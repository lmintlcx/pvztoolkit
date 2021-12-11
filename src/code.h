
#pragma once

#include <iostream>
#include <cassert>
#include <initializer_list>
#include <vector>

#include <Windows.h>

namespace Pt
{

typedef void *HANDLE;

enum class Reg : unsigned int
{
    EAX = 0,
    EBX = 3,
    ECX = 1,
    EDX = 2,
    ESI = 6,
    EDI = 7,
    EBP = 5,
    ESP = 4,
};

class Code
{
  public:
    Code();
    ~Code();

    void asm_init();

    void asm_add_byte(unsigned char);
    void asm_add_word(unsigned short);
    void asm_add_dword(unsigned int);

    void asm_add_list(std::initializer_list<unsigned char>);
    template <typename... Args>
    void asm_add_list(Args...);

    void asm_push_byte(unsigned char);
    void asm_push_dword(unsigned int);

    void asm_mov_exx(Reg, unsigned int);
    void asm_mov_exx_dword_ptr(Reg, unsigned int);
    void asm_mov_exx_dword_ptr_exx_add(Reg, unsigned int);

    void asm_push_exx(Reg);
    void asm_pop_exx(Reg);
    void asm_mov_exx_exx(Reg, Reg);

    void asm_call(unsigned int);

    void asm_ret();

    void asm_code_inject(HANDLE);

  protected:
    unsigned char *code;
    unsigned int length;
    std::vector<unsigned int> calls_pos;
};

template <typename... Args>
void Code::asm_add_list(Args... value)
{
    asm_add_list({static_cast<unsigned char>(value)...});
}

} // namespace Pt
