#pragma once
#include <cstdint>


namespace tinycg {

enum r8_t {
  al, cl, dl, bl, ah, ch, dh, bh,
};

enum r16_t {
  ax, cx, dx, bx, sp, bp, si, di,
};

enum r32_t {
  eax, ecx, edx, ebx, esp, ebp, esi, edi,
};

enum r64_t {
  rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi,
  r8, r9, r10, r11, r12, r13, r14, r15,
};

enum rxmm_t {
  xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7,
};

struct deref_t {

  deref_t(r64_t base)
    : base(base)
    , disp(0)
  {}

  deref_t(r64_t base, int32_t disp)
    : base(base)
    , disp(disp)
  {}
  
  const r64_t base;
  const int32_t disp;
};

struct asm_x64_t {

  asm_x64_t(uint8_t *ptr, size_t size);

  void mov(r64_t dst, r64_t src);
  void mov(r32_t dst, r32_t src);
  void mov(r64_t dst, const deref_t &src);
  void mov(const deref_t &dst, r64_t src);
  void mov(r32_t dst, const deref_t &src);
  void mov(const deref_t &dst, r32_t src);
  void mov(r64_t dst, int32_t imm);
  void mov(r32_t dst, int32_t imm);

  void add(r32_t dst, r32_t src);
  void add(r32_t dst, int32_t imm);
  void add(r32_t dst, const deref_t &src);
  void add(const deref_t &dst, r32_t src);
  void add(const deref_t &dst, int32_t imm);

  // sub

  void ret();
  void nop();

  void clear();
  size_t size() const;

protected:

  void emit(const void *data, size_t size);
  void modrm(uint8_t mod, uint8_t reg, uint8_t rm);
  void rex(uint8_t w, uint8_t r, uint8_t x, uint8_t b);

  uint8_t *start;
  uint8_t *head;
  const uint8_t *const end;
};

}  // namespace tinycg
