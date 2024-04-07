
#include "code.h"

namespace Pt
{

Code::Code()
{
    unsigned int page = 256; // 1MB
    code = new unsigned char[4096 * page];
    length = 0;
    calls_pos.clear();
}

Code::~Code()
{
    delete[] code;
}

void Code::asm_init()
{
    length = 0;
    calls_pos.clear();
}

void Code::asm_add_byte(unsigned char value)
{
    code[length] = value;
    length += 1;
}

void Code::asm_add_word(unsigned short value)
{
    (unsigned short &)code[length] = value;
    length += 2;
}

void Code::asm_add_dword(unsigned int value)
{
    (unsigned int &)code[length] = value;
    length += 4;
}

void Code::asm_add_list(std::initializer_list<unsigned char> value)
{
    for (auto it = value.begin(); it != value.end(); it++)
        asm_add_byte(*it);
}

void Code::asm_push_byte(unsigned char value)
{
    asm_add_byte(0x6a);
    asm_add_byte(value);
}

void Code::asm_push_dword(unsigned int value)
{
    asm_add_byte(0x68);
    asm_add_dword(value);
}

void Code::asm_mov_exx(Reg reg, unsigned int value)
{
    asm_add_byte(0xb8 + static_cast<unsigned int>(reg));
    asm_add_dword(value);
}

void Code::asm_mov_exx_dword_ptr(Reg reg, unsigned int value)
{
    asm_add_byte(0x8b);
    asm_add_byte(0x05 + static_cast<unsigned int>(reg) * 8);
    asm_add_dword(value);
}

void Code::asm_mov_exx_dword_ptr_exx_add(Reg reg, unsigned int value)
{
    asm_add_byte(0x8b);
    asm_add_byte(0x80 + static_cast<unsigned int>(reg) * (8 + 1));
    if (reg == Reg::ESP)
        asm_add_byte(0x24);
    asm_add_dword(value);
}

void Code::asm_push_exx(Reg reg)
{
    asm_add_byte(0x50 + static_cast<unsigned int>(reg));
}

void Code::asm_pop_exx(Reg reg)
{
    asm_add_byte(0x58 + static_cast<unsigned int>(reg));
}

void Code::asm_mov_exx_exx(Reg reg_to, Reg reg_from)
{
    asm_add_byte(0x8b);
    asm_add_byte(0xc0 + static_cast<unsigned int>(reg_to) * 8 + static_cast<unsigned int>(reg_from));
}

void Code::asm_call(unsigned int addr)
{
    asm_add_byte(0xe8);
    calls_pos.push_back(length);
    asm_add_dword(addr);
}

void Code::asm_ret()
{
    asm_add_byte(0xc3);
}

void Code::asm_code_inject(HANDLE handle)
{
    LPVOID addr = VirtualAllocEx(handle, nullptr, this->length, //
                                 MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (addr == nullptr)
        return;

    for (size_t i = 0; i < this->calls_pos.size(); i++)
    {
        unsigned int pos = this->calls_pos[i];
        int &call_addr = (int &)(this->code[pos]);
        call_addr = call_addr - ((int)addr + pos + 4);
    }

    DWORD write_size = 0;
    BOOL ret = WriteProcessMemory(handle, addr, this->code, this->length, &write_size);
    if (ret == 0 || write_size != this->length)
    {
        VirtualFreeEx(handle, addr, 0, MEM_RELEASE);
        return;
    }

    HANDLE thread = CreateRemoteThread //
        (handle, nullptr, 0, LPTHREAD_START_ROUTINE(addr), nullptr, 0, nullptr);
    if (thread == nullptr)
    {
        VirtualFreeEx(handle, addr, 0, MEM_RELEASE);
        return;
    }

    DWORD wait_status = WaitForSingleObject(thread, INFINITE); // INFINITE?
    CloseHandle(thread);
    VirtualFreeEx(handle, addr, 0, MEM_RELEASE);

#ifdef _DEBUG
    std::wcout << L"waiting state: " << wait_status << std::endl;
    assert(this->length > 0);
    assert(this->length < 4096 * 16);
    std::wcout << L"Inject assembly code: ";
    for (size_t i = 0; i < this->length; i++)
        std::cout << std::hex << int(this->code[i]) << " ";
    std::cout << std::endl;
#endif
}

} // namespace Pt
