
#include <iostream>

#include "process.h"

#include <psapi.h>
#include <winver.h>

namespace Pt
{

Process::Process()
{
    this->hwnd = nullptr;
    this->pid = 0;
    this->handle = nullptr;
    this->path = L"";
    this->name = L"";
    this->version = L"";
    this->of_name = L"";
}

Process::~Process()
{
    if (IsValid())
        CloseHandle(this->handle);
}

bool Process::OpenByWindow(const wchar_t *class_name, const wchar_t *window_name)
{
    if (IsValid())
        CloseHandle(this->handle);

    this->hwnd = nullptr;
    this->pid = 0;
    this->handle = nullptr;
    this->path = L"";
    this->name = L"";
    this->version = L"";
    this->of_name = L"";

    auto get_path = [&]() {
        wchar_t file_path[MAX_PATH]; // 游戏本体路径
        DWORD name_size = GetModuleFileNameExW(this->handle, nullptr, file_path, MAX_PATH);
        if (name_size != 0)
            this->path = std::wstring(file_path);

        // 用某个未公开接口获取父进程标识和文件路径
        NtQueryInformationProcess _NtQueryInformationProcess = //
            (NtQueryInformationProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "NtQueryInformationProcess");
        if (_NtQueryInformationProcess == nullptr)
            return;
        PROCESS_BASIC_INFORMATION pbi;
        NTSTATUS status = _NtQueryInformationProcess(this->handle,                      //
                                                     ProcessBasicInformation,           //
                                                     (void *)&pbi,                      //
                                                     sizeof(PROCESS_BASIC_INFORMATION), //
                                                     nullptr);                          //
        if (NT_SUCCESS(status))
        {
            DWORD _pid = (DWORD)(pbi.Reserved3);                           // 父进程标识
            HANDLE _handle = OpenProcess(PROCESS_ALL_ACCESS, false, _pid); // 父进程句柄
            if (_handle != nullptr)
            {
                wchar_t _file_path[MAX_PATH]; // 父进程文件路径
                DWORD _name_size = GetModuleFileNameExW(_handle, nullptr, _file_path, MAX_PATH);
                CloseHandle(_handle);
                if (_name_size != 0)
                {
                    std::wstring _path = std::wstring(_file_path);
                    PathStripPathW(_file_path);
                    std::wstring launcher = std::wstring(_file_path);
                    // std::wcout << L"父进程名: " << launcher << std::endl;
                    std::transform(launcher.begin(), launcher.end(), launcher.begin(), ::tolower);
                    // 提取游戏本体破解后双击由 explorer.exe 启动
                    // 未提取则是 PlantsVsZombies.exe 或其他修改后的文件名
                    // 游戏自动创建的 popcapgame1.exe 被独占, 改为读取启动器的版本信息
                    if (launcher != L"explorer.exe")
                        this->path = _path;
                }
            }
        }
    };

    auto get_info = [&]() {
        if (this->path == L"")
            return;
        DWORD size = GetFileVersionInfoSizeW(this->path.c_str(), nullptr);
        if (size == 0)
            return;

        wchar_t *info = new wchar_t[size];
        if (GetFileVersionInfoW(this->path.c_str(), 0, size, info) != 0)
        {
            unsigned int len = 0;
            void *data;
            int ret;

            ret = VerQueryValueW(info, L"\\StringFileInfo\\040904b0\\ProductName", (void **)&data, &len);
            if (ret != 0 && len > 0)
                this->name = std::wstring((wchar_t *)data);

            ret = VerQueryValueW(info, L"\\StringFileInfo\\040904b0\\ProductVersion", (void **)&data, &len);
            if (ret != 0 && len > 0)
                this->version = std::wstring((wchar_t *)data);

            ret = VerQueryValueW(info, L"\\StringFileInfo\\040904b0\\OriginalFilename", (void **)&data, &len);
            if (ret != 0 && len > 0)
                this->of_name = std::wstring((wchar_t *)data);
        }
        delete[] info;
    };

    this->hwnd = FindWindowW(class_name, window_name);
    if (this->hwnd != nullptr)
    {
        GetWindowThreadProcessId(this->hwnd, &(this->pid));
        if (this->pid != 0)
        {
            this->handle = OpenProcess(PROCESS_ALL_ACCESS, false, this->pid);
            if (this->handle != nullptr)
            {
                get_path();
                get_info();
            }
        }
    }

#ifdef _DEBUG
    // 在 #define _WIN32_WINNT 0x0501 的情况下
    // std::cout << "PROCESS_ALL_ACCESS: " << std::hex << PROCESS_ALL_ACCESS << std::endl;
    assert(PROCESS_ALL_ACCESS == 0x001F0FFF);
#endif

#ifdef _DEBUG
    std::wcout << L"查找窗口: " << (class_name == nullptr ? L"nullptr" : class_name)              //
               << L" " << (window_name == nullptr ? L"nullptr" : window_name) << std::endl        //
               << L" -> " << this->hwnd << L" " << this->pid << L" " << this->handle << std::endl //
               << this->path << std::endl                                                         //
               << this->name << L"  " << this->version << L"  " << this->of_name << std::endl;
#endif

    // 返回的是窗口有没有找到而不是进程有没有打开
    return this->hwnd != nullptr;
}

bool Process::IsValid()
{
    if (this->handle == nullptr)
        return false;

    DWORD exit_code;
    BOOL ret = GetExitCodeProcess(this->handle, &exit_code);
    bool valid = (ret != 0 && exit_code == STILL_ACTIVE);

#ifdef _DEBUG
    if (!valid)
        std::wcout << L"当前进程不可用." << std::endl;
#endif

    return valid;
}

} // namespace Pt
