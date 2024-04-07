
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include <Windows.h>

namespace Pt
{

#define UNPACK_SUCCESS 0           // Successful unpacking
#define UNPACK_SRC_NOT_EXIST 1     // Failed to open the source file
#define UNPACK_SRC_SIZE_ERROR 2    // Failed to obtain the source file size
#define UNPACK_SRC_LOAD_ERROR 3    // Failed to read the contents of the source file
#define UNPACK_SRC_HEADER_ERROR 4  // Incorrect file header format
#define UNPACK_SRC_DATA_ERROR 5    // File data is corrupted
#define UNPACK_PATH_CREATE_ERROR 6 // Unpacking path creation failed
#define UNPACK_FILE_CREATE_ERROR 7 // Unpacking file creation failed
#define UNPACK_FILE_WRITE_ERROR 8  // Unpacking file failed to write

#define PACK_SUCCESS 0           // Packaged successfully
#define PACK_SRC_NOT_EXIST 1     // Failed to open the source folder
#define PACK_SRC_EMPTY_ERROR 2   // The source folder is empty
#define PACK_PATH_CREATE_ERROR 3 // Package path creation failed
#define PACK_FILE_CREATE_ERROR 4 // Package file creation failed
#define PACK_FILE_WRITE_ERROR 5  // Package file failed to write
#define PACK_SRC_READ_ERROR 6    // Failed to read the packaged source file

class PAK
{
  public:
    PAK();
    ~PAK();

  private:
    std::string utf8_encode(const std::wstring &);
    std::wstring utf8_decode(const std::string &);

    // Create folders recursively
    bool create_path(const std::wstring &);

    // Find all files recursively
    void find_files(const std::wstring,
                    std::vector<std::wstring> &, //
                    std::vector<int> &,          //
                    std::vector<FILETIME> &);

  public:
    // Unpack, the parameters are the source file name and unpack folder respectively
    int Unpack(std::wstring, std::wstring);
    int Unpack(std::string, std::string);

    // Package, the parameters are the source folder and the package file name respectively
    int Pack(std::wstring, std::wstring);
    int Pack(std::string, std::string);
};

} // namespace Pt
