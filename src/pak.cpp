
#include "pak.h"

namespace Pt
{

PAK::PAK()
{
}

PAK::~PAK()
{
}

std::string PAK::utf8_encode(const std::wstring &wstr)
{
    if (wstr.empty())
        return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), nullptr, 0, nullptr, nullptr);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, nullptr, nullptr);
    return str;
}

std::wstring PAK::utf8_decode(const std::string &str)
{
    if (str.empty())
        return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), nullptr, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
    return wstr;
}

bool PAK::create_path(const std::wstring &path)
{
    if (path == L"")
        return false;

    // The directory already exists and returns directly to true
    DWORD fa = GetFileAttributesW(path.c_str());
    if ((fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
        return true;

    // If it does not exist, it is created, and the creation is successful
    if (CreateDirectoryW(path.c_str(), nullptr))
        return true;

    // Creation failed, the superior directory does not exist, failed
    if (path.substr(0, path.find_last_of(L"\\")) == path)
        return false;

    // The superior directory exists, but the creation failed
    if (!create_path(path.substr(0, path.find_last_of(L"\\"))))
        return false;

    // The superior directory was created successfully, and the result of creating this directory is returned
    return CreateDirectoryW(path.c_str(), nullptr);
}

void PAK::find_files(const std::wstring find_path,
                     std::vector<std::wstring> &files_name,
                     std::vector<int> &files_size,
                     std::vector<FILETIME> &files_time)
{
    std::wstring path = find_path + L"\\*";
    WIN32_FIND_DATA ffd;
    HANDLE hf;

    hf = FindFirstFileW(path.c_str(), &ffd);
    if (hf != INVALID_HANDLE_VALUE)
    {
        do
        {
            std::wstring name = ffd.cFileName;
            if (name == L"." || name == L".." //
                || name == L"thumbs.db" || name == L"Thumbs.db")
                continue;
            if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                std::wstring sub_path = find_path + L"\\" + name;
                std::vector<std::wstring> _names;
                std::vector<int> _sizes;
                std::vector<FILETIME> _times;
                find_files(sub_path, _names, _sizes, _times);
                for (size_t i = 0; i < _names.size(); i++)
                {
                    files_name.push_back(name + L"\\" + _names[i]);
                    files_size.push_back(_sizes[i]);
                    files_time.push_back(_times[i]);
                }
            }
            else
            {
                files_name.push_back(ffd.cFileName);
                files_size.push_back(ffd.nFileSizeLow);
                files_time.push_back(ffd.ftLastWriteTime);
            }
        } while (FindNextFileW(hf, &ffd) != 0);
        FindClose(hf);
    }
}

int PAK::Unpack(std::wstring src_file, std::wstring dst_dir)
{
#ifdef _DEBUG
	std::wcout << L"Unpack source file: " << src_file << std::endl;
    std::wcout << L"Unpack target folder: " << dst_dir << std::endl;
#endif

    // Open pak file
    HANDLE hfr = CreateFileW(src_file.c_str(), GENERIC_READ, FILE_SHARE_READ, //
                             nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hfr == INVALID_HANDLE_VALUE)
        return UNPACK_SRC_NOT_EXIST;

    // Get size
    DWORD size = GetFileSize(hfr, nullptr);
    if (size == INVALID_FILE_SIZE || size < 10)
    {
        CloseHandle(hfr);
        return UNPACK_SRC_SIZE_ERROR;
    }
#ifdef _DEBUG
    std::wcout << L"Source file size: " << size << "bytes" << std::endl;
#endif

    // Load the entire file content into memory
    char *buffer = new char[size];
    DWORD read_size = 0;
    BOOL ret = ReadFile(hfr, buffer, size, &read_size, nullptr);
    CloseHandle(hfr);

    if (ret == FALSE || size != read_size)
    {
        delete[] buffer;
        return UNPACK_SRC_LOAD_ERROR;
    }

    // The entire file is XOR with 0xF7
    for (size_t i = 0; i < size; ++i)
        buffer[i] = buffer[i] ^ 0xf7;

    // File offset
    unsigned int offset = 0;

    // Check file header
    unsigned long file_header_magic = (unsigned long &)buffer[offset];
    offset += sizeof(unsigned long);
    unsigned long file_header_version = (unsigned long &)buffer[offset];
    offset += sizeof(unsigned long);
    if (file_header_magic != 0xBAC04AC0 || file_header_version > 0x00000000)
    {
        delete[] buffer;
        return UNPACK_SRC_HEADER_ERROR;
    }

    // Index area data structure
	unsigned char eof_flag; // end flag
    unsigned char name_width; // file name length
    char file_name[256]; // file name
    int file_size; // size
    FILETIME file_time; // time

    unsigned int files_count = 0; //Total number of files
    std::vector<std::string> files_name; // The path saved in pak
    std::vector<int> files_size; // size

    //Traverse the index area to obtain file information
    for (;;)
    {
        eof_flag = (unsigned char &)buffer[offset];
        offset += sizeof(unsigned char);
        // Exit the loop when encountering the end sign
        if (eof_flag != static_cast<unsigned char>(0x00) || eof_flag == static_cast<unsigned char>(0x80))
            break;

        name_width = (unsigned char &)buffer[offset];
        offset += sizeof(unsigned char);

        for (unsigned int i = 0; i < static_cast<unsigned int>(name_width); i++)
            file_name[i] = buffer[offset + i];
        file_name[static_cast<unsigned int>(name_width)] = 0;
        offset += static_cast<unsigned int>(name_width);

        file_size = (int &)buffer[offset];
        offset += sizeof(int);

        file_time = (FILETIME &)buffer[offset]; // Useless
        offset += sizeof(FILETIME);

        files_name.push_back(std::string(file_name));
        files_size.push_back(file_size);
        files_count++;

#ifdef _DEBUG
        SYSTEMTIME system_time;
        FileTimeToSystemTime(&file_time, &system_time);
        std::wcout << unsigned char(name_width) << " "
                   << file_name << " "
                   << file_size << " "
                   << system_time.wYear << "."
                   << system_time.wMonth << "."
                   << system_time.wDay << " "
                   << system_time.wHour << ":"
                   << system_time.wMinute << ":"
                   << system_time.wSecond << " "
                   << unsigned char(eof_flag) << std::endl;
#endif
    }
#ifdef _DEBUG
    std::wcout << L"Total number of files: " << files_count << std::endl;
#endif

    // Check the correctness of the data in the file index area
    unsigned int _offset = offset; // temporary storage
    for (unsigned int i = 0; i < files_count; i++)
    {
        int output_file_size = files_size.at(i);
        offset += output_file_size;
    }
    if (offset != size)
    {
        delete[] buffer;
        return UNPACK_SRC_DATA_ERROR;
    }
    offset = _offset; // reduction

    // Extract all files in the data area
    for (size_t i = 0; i < files_count; i++)
    {
        // Full path and size of each file
        std::wstring output_path = dst_dir + L"\\" + utf8_decode(files_name.at(i));
        unsigned int output_size = files_size.at(i);

        // Get directory name and create
        bool path_created = create_path(output_path.substr(0, output_path.find_last_of(L"\\")));
        if (!path_created)
        {
            // std::wcout << L"Path creation failed: " << output_path.substr(0, output_path.find_last_of(L"\\")) << std::endl;
            delete[] buffer;
            return UNPACK_PATH_CREATE_ERROR;
        }

        HANDLE hfw = CreateFileW(output_path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, //
                                 nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (hfw == INVALID_HANDLE_VALUE)
        {
            // std::wcout << L"File creation failed: " << output_path << std::endl;
            delete[] buffer;
            return UNPACK_FILE_CREATE_ERROR;
        }

        char *output_buff = new char[output_size];
        for (size_t j = 0; j < output_size; j++)
            output_buff[j] = buffer[offset + j];

        DWORD write_size = 0;
        WriteFile(hfw, output_buff, output_size, &write_size, nullptr);
        CloseHandle(hfw);

        if (output_size != write_size)
        {
            // std::wcout << L"File writing failed: " << output_path << std::endl;
            delete[] output_buff;
            delete[] buffer;
            return UNPACK_FILE_WRITE_ERROR;
        }

        delete[] output_buff;
        offset += output_size;
    }

    delete[] buffer;
    return UNPACK_SUCCESS;
}

int PAK::Unpack(std::string src_file, std::string dst_dir)
{
    return Unpack(utf8_decode(src_file), utf8_decode(dst_dir));
}

int PAK::Pack(std::wstring src_dir, std::wstring dst_file)
{
#ifdef _DEBUG
    std::wcout << L"Pack source folder: " << src_dir << std::endl;
    std::wcout << L"Pack target file: " << dst_file << std::endl;
#endif

    DWORD fa = GetFileAttributesW(src_dir.c_str());
    if ((fa == INVALID_FILE_ATTRIBUTES) || !(fa & FILE_ATTRIBUTE_DIRECTORY))
        return PACK_SRC_NOT_EXIST;

	unsigned int files_count = 0; //Total number of files
    std::vector<std::wstring> files_name; // The path saved in pak
    std::vector<int> files_size; // size
    std::vector<FILETIME> files_time; // time

    find_files(src_dir, files_name, files_size, files_time);
    files_count = files_name.size();
#ifdef _DEBUG
    std::wcout << L"Total number of files found: " << files_count << std::endl;
#endif

    if (files_count == 0)
        return PACK_SRC_EMPTY_ERROR;

#ifdef _DEBUG
    for (size_t i = 0; i < files_count; i++)
    {
        SYSTEMTIME system_time;
        FileTimeToSystemTime(&files_time[i], &system_time);
        std::wcout << files_name[i] << " "
                   << files_size[i] << " "
                   << system_time.wYear << "."
                   << system_time.wMonth << "."
                   << system_time.wDay << " "
                   << system_time.wHour << ":"
                   << system_time.wMinute << ":"
                   << system_time.wSecond << std::endl;
    }
#endif

    // Create output folder
    bool path_created = create_path(dst_file.substr(0, dst_file.find_last_of(L"\\")));
    if (!path_created)
    {
        // std::wcout << L"Path creation failed: " << dst_file.substr(0, dst_file.find_last_of(L"\\")) << std::endl;
        return PACK_PATH_CREATE_ERROR;
    }

    // Create output file
    HANDLE hfw = CreateFileW(dst_file.c_str(), GENERIC_WRITE, FILE_SHARE_READ, //
                             nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hfw == INVALID_HANDLE_VALUE)
        return PACK_FILE_CREATE_ERROR;

    // Used to check the correctness of the data size written each time
    DWORD write_size = 0;

    // Write file header
    unsigned long file_header_magic = 0xBAC04AC0;
    unsigned long file_header_version = 0x00000000;
    file_header_magic ^= 0xf7f7f7f7;
    file_header_version ^= 0xf7f7f7f7;

    WriteFile(hfw, (void *)&file_header_magic, sizeof(unsigned long), &write_size, nullptr);
    if (write_size != sizeof(unsigned long))
    {
        CloseHandle(hfw);
        return PACK_FILE_WRITE_ERROR;
    }

    WriteFile(hfw, (void *)&file_header_version, sizeof(unsigned long), &write_size, nullptr);
    if (write_size != sizeof(unsigned long))
    {
        CloseHandle(hfw);
        return PACK_FILE_WRITE_ERROR;
    }

    // Index area data structure
	unsigned char eof_flag; // end flag
    unsigned char name_width; // file name length
    char file_name[256]; // file name
    int file_size; // size
    FILETIME file_time; // time

    // Write index area
    for (size_t i = 0; i < files_count; i++)
    {
        eof_flag = (unsigned char)(0x00);

        std::string file_name_str = utf8_encode(files_name.at(i));
        unsigned int name_size = file_name_str.size();
        name_width = static_cast<unsigned char>(name_size);

        for (size_t i = 0; i < name_size; i++)
            file_name[i] = file_name_str.at(i);
        file_name[name_size] = 0;

        file_size = files_size.at(i);

        file_time = files_time.at(i);

        // Create buffer
        unsigned int struct_size = sizeof(unsigned char)   //
                                   + sizeof(unsigned char) //
                                   + name_size             //
                                   + sizeof(int)           //
                                   + sizeof(FILETIME);
        char *buff = new char[struct_size];

        // copy to buffer

        unsigned int index = 0;

        buff[index] = eof_flag;
        index += sizeof(unsigned char);

        buff[index] = name_width;
        index += sizeof(unsigned char);

        for (size_t j = 0; j < name_size; j++)
            buff[index + j] = file_name[j];
        index += name_size;

        (int &)buff[index] = file_size;
        index += sizeof(int);

        (FILETIME &)buff[index] = file_time;
        index += sizeof(FILETIME);

        assert(index == struct_size);

        // encryption
        for (size_t k = 0; k < struct_size; k++)
            buff[k] = buff[k] ^ 0xf7;

        // write buffer
        WriteFile(hfw, buff, struct_size, &write_size, nullptr);
        if (write_size != struct_size)
        {
            CloseHandle(hfw);
            delete[] buff;
            return PACK_FILE_WRITE_ERROR;
        }

        delete[] buff;
    }

    // end sign
    eof_flag = (unsigned char)(0x80);
    eof_flag ^= 0xf7;
    WriteFile(hfw, (void *)&eof_flag, sizeof(unsigned char), &write_size, nullptr);
    if (write_size != sizeof(unsigned char))
    {
        CloseHandle(hfw);
        return PACK_FILE_WRITE_ERROR;
    }

    // write data area
    for (size_t i = 0; i < files_count; i++)
    {
        // full file path
        auto file_path = src_dir + L"\\" + files_name.at(i);

        HANDLE hfr = CreateFileW(file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, //
                                 nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (hfr == INVALID_HANDLE_VALUE)
        {
            CloseHandle(hfw);
            return PACK_SRC_READ_ERROR;
        }

        // Read file into buffer
        unsigned int size = files_size.at(i);
        DWORD read_size = 0;
        char *buffer = new char[size];
        BOOL ret = ReadFile(hfr, buffer, size, &read_size, nullptr);
        if (ret == FALSE || read_size != size)
        {
            CloseHandle(hfw);
            CloseHandle(hfr);
            delete[] buffer;
            return PACK_SRC_READ_ERROR;
        }
        CloseHandle(hfr);

        // encryption
        for (size_t i = 0; i < size; ++i)
            buffer[i] = buffer[i] ^ 0xf7;

        // write
        DWORD write_size = 0;
        WriteFile(hfw, buffer, size, &write_size, nullptr);
        if (write_size != size)
        {
            CloseHandle(hfw);
            delete[] buffer;
            return PACK_FILE_WRITE_ERROR;
        }
        delete[] buffer;
    }

    CloseHandle(hfw);
    return PACK_SUCCESS;
}

int PAK::Pack(std::string src_file, std::string dst_dir)
{
    return Pack(utf8_decode(src_file), utf8_decode(dst_dir));
}

} // namespace Pt
