
#pragma once

#include <initializer_list>

namespace Pt
{

typedef void *HANDLE;

enum class Reg : unsigned int
{
    EAX = 0,
    EBX,
    ECX,
    EDX,
    ESI,
    EDI,
    EBP,
    ESP,
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
    void asm_push(int);
    void asm_mov_exx(Reg, int);
    void asm_add_exx(Reg, int);
    void asm_mov_exx_dword_ptr(Reg, int);
    void asm_mov_exx_dword_ptr_exx_add(Reg, int);
    void asm_push_exx(Reg);
    void asm_pop_exx(Reg);
    void asm_call(int);
    void asm_ret();
    void asm_code_inject(HANDLE);

  protected:
    unsigned char *code;
    unsigned int length;
};

template <typename... Args>
void Code::asm_add_list(Args... value)
{
    asm_add_list({static_cast<unsigned char>(value)...});
}

} // namespace Pt
