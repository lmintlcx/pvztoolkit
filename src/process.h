
#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <functional>
#include <initializer_list>
#include <array>
#include <cassert>
#include <algorithm>

#include <Windows.h>
#include <winternl.h>
#include <shlwapi.h>

namespace Pt
{

typedef NTSTATUS(NTAPI *NtQueryInformationProcess) //
    (HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG);

class Process
{
public:
    Process();
    ~Process();

    // 根据窗口类名和标题打开进程
    bool OpenByWindow(const wchar_t *, const wchar_t *);

    // 进程可用性
    bool IsValid();

    // 读内存
    template <typename T>
    T ReadMemory(std::initializer_list<uintptr_t>);

    // 写内存
    template <typename T>
    void WriteMemory(T, std::initializer_list<uintptr_t>);

    // 读内存数组
    template <typename T, size_t size>
    std::array<T, size> ReadMemory(std::initializer_list<uintptr_t>);

    // 写内存数组
    template <typename T, size_t size>
    void WriteMemory(std::array<T, size>, std::initializer_list<uintptr_t>);

    // template <typename T, typename... Args>
    // T ReadMemory(Args...);
    // template <typename T, typename... Args>
    // void WriteMemory(T, Args...);

    // template <typename T, size_t size, typename... Args>
    // std::array<T, size> ReadMemory(Args...);
    // template <typename T, size_t size, typename... Args>
    // void WriteMemory(std::array<T, size>, Args...);

protected:
    HWND hwnd;     // 窗口句柄
    DWORD pid;     // 进程标识
    HANDLE handle; // 进程句柄

public:
    std::wstring path;    // 文件路径
    std::wstring name;    // 产品名称
    std::wstring version; // 产品版本
    std::wstring of_name; // 原始文件名

#ifdef _DEBUG
private:
    std::string int_to_hex_string(unsigned int num)
    {
        std::stringstream sstream;
        sstream << "0x" << std::hex << num;
        return sstream.str();
    }

    // [[[0x6a9ec0] +0x768] +0x5560]
    std::string addr_list_to_string(std::initializer_list<uintptr_t> addr_list)
    {
        std::string str;
        for (auto it = addr_list.begin(); it != addr_list.end(); it++)
            if (it == addr_list.begin())
                str = "[" + int_to_hex_string(*it) + "]";
            else
                str = "[" + str + " +" + int_to_hex_string(*it) + "]";
        return str;
    }
#endif
};

template <typename T>
T Process::ReadMemory(std::initializer_list<uintptr_t> addr)
{
    T result = T();

    if (IsValid())
    {
        uintptr_t offset = 0;
        for (auto it = addr.begin(); it != addr.end(); it++)
        {
            if (it != addr.end() - 1)
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
                if (ret == 0 || sizeof(offset) != read_size)
                    return T();
            }
            else
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &result, sizeof(result), &read_size);
                if (ret == 0 || sizeof(result) != read_size)
                    return T();
            }
        }

#ifdef _DEBUG
        std::cout << addr_list_to_string(addr) << " --> " << std::dec << result << " / " << std::hex << result << std::endl;
#endif
    }

    return result;
}

template <typename T>
void Process::WriteMemory(T value, std::initializer_list<uintptr_t> addr)
{
    if (IsValid())
    {
        uintptr_t offset = 0;
        for (auto it = addr.begin(); it != addr.end(); it++)
        {
            if (it != addr.end() - 1)
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
                if (ret == 0 || sizeof(offset) != read_size)
                    return;
            }
            else
            {
                unsigned long write_size = 0;
                int ret = WriteProcessMemory(this->handle, (void *)(offset + *it), &value, sizeof(value), &write_size);
                if (ret == 0 || sizeof(value) != write_size)
                    return;
            }
        }

#ifdef _DEBUG
        std::cout << addr_list_to_string(addr) << " <-- " << std::dec << value << " / " << std::hex << value << std::endl;
        // if (ReadMemory<T>(addr) != value)
        //     std::wcout << L"写内存出错!" << std::endl;
#endif
    }
}

template <typename T, size_t size>
std::array<T, size> Process::ReadMemory(std::initializer_list<uintptr_t> addr)
{
    std::array<T, size> result = {T()};

    if (IsValid())
    {
        T buff[size] = {0};
        uintptr_t offset = 0;
        for (auto it = addr.begin(); it != addr.end(); it++)
        {
            if (it != addr.end() - 1)
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
                if (ret == 0 || sizeof(offset) != read_size)
                    return std::array<T, size>{T()};
            }
            else
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &buff, sizeof(buff), &read_size);
                if (ret == 0 || sizeof(buff) != read_size)
                    return std::array<T, size>{T()};
            }
        }
        for (size_t i = 0; i < size; i++)
            result[i] = buff[i];

#ifdef _DEBUG
        std::cout << addr_list_to_string(addr) << " --> ";
        for (size_t i = 0; i < size; i++)
            std::cout << std::hex << int(result[i]) << " ";
        std::cout << std::endl;
#endif
    }

    return result;
}

template <typename T, size_t size>
void Process::WriteMemory(std::array<T, size> value, std::initializer_list<uintptr_t> addr)
{
    if (IsValid())
    {
        T buff[size] = {0};
        for (size_t i = 0; i < size; i++)
            buff[i] = value[i];
        uintptr_t offset = 0;
        for (auto it = addr.begin(); it != addr.end(); it++)
        {
            if (it != addr.end() - 1)
            {
                unsigned long read_size = 0;
                int ret = ReadProcessMemory(this->handle, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
                if (ret == 0 || sizeof(offset) != read_size)
                    return;
            }
            else
            {
                unsigned long write_size = 0;
                int ret = WriteProcessMemory(this->handle, (void *)(offset + *it), &buff, sizeof(buff), &write_size);
                if (ret == 0 || sizeof(buff) != write_size)
                    return;
            }
        }

#ifdef _DEBUG
        std::cout << addr_list_to_string(addr) << " <-- ";
        for (size_t i = 0; i < size; i++)
            std::cout << std::hex << int(value[i]) << " ";
        std::cout << std::endl;
        // if (ReadMemory<T, size>(addr) != value)
        //     std::wcout << L"写内存出错!" << std::endl;
#endif
    }
}

// template <typename T, typename... Args>
// T Process::ReadMemory(Args... address)
// {
//     return ReadMemory<T>({static_cast<uintptr_t>(address)...});
// }

// template <typename T, typename... Args>
// void Process::WriteMemory(T value, Args... address)
// {
//     WriteMemory<T>(value, {static_cast<uintptr_t>(address)...});
// }

// template <typename T, size_t size, typename... Args>
// std::array<T, size> Process::ReadMemory(Args... address)
// {
//     return ReadMemory<T, size>({static_cast<uintptr_t>(address)...});
// }

// template <typename T, size_t size, typename... Args>
// void Process::WriteMemory(std::array<T, size> value, Args... address)
// {
//     WriteMemory<T, size>(value, {static_cast<uintptr_t>(address)...});
// }

} // namespace Pt
