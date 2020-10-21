#include <cassert>
#include <cstring>

#include "tinycg.hpp"


namespace {

inline bool is_imm8(int32_t imm) {
  return (imm >= -128 && imm <= 127);
}

}  // namespace {}


namespace tinycg {

asm_x64_t::asm_x64_t(uint8_t *ptr, size_t size)
  : start(ptr)
  , head(ptr)
  , end(ptr + size)
{
}

void asm_x64_t::modrm(uint8_t mod, uint8_t reg, uint8_t rm) {
  const uint8_t data = ((mod & 3) << 6) | ((reg & 7) << 3) | (rm & 7);
  emit(&data, 1);
  // if we need a sib byte
  if (mod < 3 && rm == 4) {
    // scale = 0, index = none, base = esp
    const uint8_t sib = (0 << 6) | (4 << 3) | 4;
    emit(&sib, 1);
  }
}

void asm_x64_t::rex(uint8_t w, uint8_t r, uint8_t x, uint8_t b) {
  const uint8_t rex = 0x40 | (w << 3) | (r << 2) | (x << 1) | b;
  emit(&rex, 1);
}

void asm_x64_t::mov(r64_t dst, r64_t src) {
  rex(1, src >= r8, 0, dst >= r8);
  emit("\x89", 1);
  modrm(3, src, dst);
}

void asm_x64_t::mov(r32_t dst, r32_t src) {
  emit("\x89", 1);
  modrm(3, src, dst);
}

void asm_x64_t::mov(r64_t dst, const deref_t &src) {
  rex(1, src.base >= r8, 0, dst >= r8);
  if (is_imm8(src.disp)) {
    emit("\x8b", 1);
    modrm(1, src.base, dst);
    const int8_t disp8 = src.disp;
    emit(&disp8, 1);
  }
  else {
    emit("\x8b", 1);
    modrm(2, src.base, dst);
    emit(&src.disp, sizeof(src.disp));
  }
}

void asm_x64_t::mov(const deref_t &dst, r64_t src) {
  rex(1, src >= r8, 0, dst.base >= r8);
  if (is_imm8(dst.disp)) {
    emit("\x89", 1);
    modrm(1, src, dst.base);
    const int8_t disp8 = dst.disp;
    emit(&disp8, 1);
  }
  else {
    emit("\x89", 1);
    modrm(2, src, dst.base);
    emit(&dst.disp, sizeof(dst.disp));
  }
}

void asm_x64_t::mov(r32_t dst, const deref_t &src) {
  if (is_imm8(src.disp)) {
    emit("\x8b", 1);
    modrm(1, dst, src.base);
    const uint8_t disp8 = src.disp;
    emit(&disp8, 1);
  }
  else {
    emit("\x8b", 1);
    modrm(2, dst, src.base);
    emit(&src.disp, sizeof(src.disp));
  }
}

void asm_x64_t::mov(const deref_t &dst, r32_t src) {
  if (is_imm8(dst.disp)) {
    emit("\x89", 1);
    modrm(1, src, dst.base);
    const uint8_t disp8 = dst.disp;
    emit(&disp8, 1);
  }
  else {
    emit("\x89", 1);
    modrm(2, src, dst.base);
    emit(&dst.disp, sizeof(dst.disp));
  }
}

void asm_x64_t::mov(r64_t dst, int32_t imm) {
  rex(1, 0, 0, dst >= r8);
  emit("\xc7", 1);
  modrm(3, 0, dst);
  emit(&imm, sizeof(imm));
}

void asm_x64_t::mov(r32_t dst, int32_t imm) {
  const uint8_t inst = 0xb8 | (dst & 0x7);
  emit(&inst, 1);
  emit(&imm, sizeof(imm));
}

void asm_x64_t::add(r32_t dst, r32_t src) {
  emit("\x01", 1);
  modrm(3, src, dst);
}

void asm_x64_t::add(r32_t dst, int32_t src) {
  if (is_imm8(src)) {
    emit("\x83", 1);
    modrm(3, 0, dst);
    const int8_t imm8 = src;
    emit(&imm8, 1);
  }
  else {
    if (dst == eax) {
      emit("\x05", 1);
    }
    else {
      emit("\x81", 1);
      modrm(3, 0, dst);
    }
    emit(&src, sizeof(src));
  }
}

void asm_x64_t::nop() {
  emit("\x90", 1);
}

void asm_x64_t::ret() {
  emit("\xc3", 1);
}

void asm_x64_t::emit(const void *data, size_t size) {
  memcpy(head, data, size);
  head += size;
}

void asm_x64_t::clear() {
  head = start;
}

size_t asm_x64_t::size() const {
  return head - start;
}

} // namespace tinycg
