#include <string.h>

#include "tinycg.h"

static void cg_emit_data(struct cg_state_t *cg, const void *data, size_t size) {
  memcpy(cg->head, data, size);
  cg->head += size;
}

static void cg_modrm(struct cg_state_t *cg, uint32_t mod, uint32_t rm,
                     uint32_t reg) {
  const uint8_t data = (mod << 6) | (rm << 3) | reg;
  cg_emit_data(cg, &data, 1);
}

uint32_t cg_size(struct cg_state_t *cg) {
  return (uint32_t)(cg->head - cg->start);
}

void cg_mov_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x89", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_mov_r32_i32(struct cg_state_t *cg, cg_r32_t r1, uint32_t imm) {
  const uint8_t inst = 0xb8 | (r1 & 0x7);
  cg_emit_data(cg, &inst, 1);
  cg_emit_data(cg, &imm, sizeof(imm));
}

void cg_ret(struct cg_state_t *cg) {
  cg_emit_data(cg, "\xc3", 1);
}

void cg_mov_r32_r64disp(struct cg_state_t *cg, cg_r32_t r1, cg_r64_t base,
                        int32_t disp) {
  if (disp >= -128 && disp < 127) {
    cg_emit_data(cg, "\x8b", 1);
    cg_modrm(cg, 1, r1, base);
    const uint8_t disp8 = disp;
    cg_emit_data(cg, &disp8, 1);
  }
  else {
    cg_emit_data(cg, "\x8b", 1);
    cg_modrm(cg, 2, r1, base);
    cg_emit_data(cg, &disp, sizeof(disp));
  }
}

void cg_mov_r64disp_r32(struct cg_state_t *cg, cg_r64_t base, int32_t disp,
                        cg_r32_t r1) {
  if (disp >= -128 && disp < 127) {
    cg_emit_data(cg, "\x89", 1);
    cg_modrm(cg, 1, r1, base);
    const uint8_t disp8 = disp;
    cg_emit_data(cg, &disp8, 1);
  }
  else {
    cg_emit_data(cg, "\x89", 1);
    cg_modrm(cg, 2, r1, base);
    cg_emit_data(cg, &disp, sizeof(disp));
  }
}

void cg_movsx_r32_r8(struct cg_state_t *cg, cg_r32_t r1, cg_r8_t r2) {
  cg_emit_data(cg, "\x0f\xbe", 2);
  cg_modrm(cg, 3, r1, r2);
}

void cg_movsx_r32_r16(struct cg_state_t *cg, cg_r32_t r1, cg_r16_t r2) {
  cg_emit_data(cg, "\x0f\xbf", 2);
  cg_modrm(cg, 3, r1, r2);
}

void cg_movzx_r32_r8(struct cg_state_t *cg, cg_r32_t r1, cg_r8_t r2) {
  cg_emit_data(cg, "\x0f\xb6", 2);
  cg_modrm(cg, 3, r1, r2);
}

void cg_movzx_r32_r16(struct cg_state_t *cg, cg_r32_t r1, cg_r16_t r2) {
  cg_emit_data(cg, "\x0f\xb7", 2);
  cg_modrm(cg, 3, r1, r2);
}

void cg_add_r64_i32(struct cg_state_t *cg, cg_r64_t r1, int32_t imm) {
  cg_emit_data(cg, "\x48", 1);
  cg_add_r32_i32(cg, r1, imm);
}

void cg_add_r32_i32(struct cg_state_t *cg, cg_r32_t r1, int32_t imm) {
  if (imm >= -128 && imm <= 127) {
    cg_emit_data(cg, "\x83", 1);
    cg_modrm(cg, 3, 0, r1);
    const int8_t imm8 = imm;
    cg_emit_data(cg, &imm8, 1);
  }
  else {
    if (r1 == cg_r32_eax) {
      cg_emit_data(cg, "\x05", 1);
    }
    else {
      cg_emit_data(cg, "\x81", 1);
      cg_modrm(cg, 3, 0, r1);
    }
    cg_emit_data(cg, &imm, sizeof(imm));
  }
}

void cg_add_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x01", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_and_r32_i32(struct cg_state_t *cg, cg_r32_t r1, uint32_t imm) {
  if (r1 == cg_r32_eax) {
    cg_emit_data(cg, "\x25", 1);
  }
  else {
    cg_emit_data(cg, "\x81", 1);
    cg_modrm(cg, 3, 4, r1);
  }
  cg_emit_data(cg, &imm, sizeof(imm));
}

void cg_and_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x21", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_sub_r32_i32(struct cg_state_t *cg, cg_r32_t r1, int32_t imm) {
  if (imm >= -128 && imm <= 127) {
    cg_emit_data(cg, "\x83", 1);
    const uint8_t op = 0xe8 | (r1 & 0x7);
    cg_emit_data(cg, &op, 1);
    const int8_t imm8 = imm;
    cg_emit_data(cg, &imm8, 1);
  }
  else {
    if (r1 == cg_r32_eax) {
      cg_emit_data(cg, "\x2d", 1);
    }
    else {
      cg_emit_data(cg, "\x81", 1);
      cg_modrm(cg, 3, 5, r1);
    }
    cg_emit_data(cg, &imm, sizeof(imm));
  }
}

void cg_sub_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x29", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_shl_r32_i8(struct cg_state_t *cg, cg_r32_t r1, uint8_t imm) {
  if (imm == 1) {
    const uint8_t op = 0xe0 | (r1 & 0x7);
    cg_emit_data(cg, "\xd1", 1);
    cg_emit_data(cg, &op, 1);
  }
  else {
    cg_emit_data(cg, "\xc1", 1);
    cg_modrm(cg, 3, 4, r1);
    cg_emit_data(cg, &imm, sizeof(imm));
  }
}

void cg_shl_r32_cl(struct cg_state_t *cg, cg_r32_t r1) {
  cg_emit_data(cg, "\xd3", 1);
  cg_modrm(cg, 3, 4, r1);
}

void cg_sar_r32_i8(struct cg_state_t *cg, cg_r32_t r1, uint8_t imm) {
  if (imm == 1) {
    const uint8_t op = 0xf8 | (r1 & 0x7);
    cg_emit_data(cg, "\xd1", 1);
    cg_emit_data(cg, &op, 1);
  }
  else {
    cg_emit_data(cg, "\xc1", 1);
    cg_modrm(cg, 3, 7, r1);
    cg_emit_data(cg, &imm, 1);
  }
}

void cg_sar_r32_cl(struct cg_state_t *cg, cg_r32_t r1) {
  cg_emit_data(cg, "\xd3", 1);
  cg_modrm(cg, 3, 7, r1);
}

void cg_shr_r32_i8(struct cg_state_t *cg, cg_r32_t r1, uint8_t imm) {
  if (imm == 1) {
    const uint8_t op = 0xe8 | (r1 & 0x7);
    cg_emit_data(cg, "\xd1", 1);
    cg_emit_data(cg, &op, 1);
  }
  else {
    cg_emit_data(cg, "\xc1", 1);
    cg_modrm(cg, 3, 5, r1);
    cg_emit_data(cg, &imm, sizeof(imm));
  }
}

void cg_shr_r32_cl(struct cg_state_t *cg, cg_r32_t r1) {
  cg_emit_data(cg, "\xd3", 1);
  cg_modrm(cg, 3, 5, r1);
}

void cg_xor_r32_i32(struct cg_state_t *cg, cg_r32_t r1, uint32_t imm) {
  if (r1 == cg_r32_eax) {
    cg_emit_data(cg, "\x35", 1);
  }
  else {
    cg_emit_data(cg, "\x81", 1);
    cg_modrm(cg, 3, 6, r1);
  }
  cg_emit_data(cg, &imm, sizeof(imm));
}

void cg_xor_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x31", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_or_r32_i32(struct cg_state_t *cg, cg_r32_t r1, uint32_t imm) {
  if (r1 == cg_r32_eax) {
    cg_emit_data(cg, "\x0d", 1);
  }
  else {
    cg_emit_data(cg, "\x81", 1);
    cg_modrm(cg, 3, 1, r1);
  }
  cg_emit_data(cg, &imm, sizeof(imm));
}

void cg_or_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x09", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_cmp_r32_r32(struct cg_state_t *cg, cg_r32_t r1, cg_r32_t r2) {
  cg_emit_data(cg, "\x39", 1);
  cg_modrm(cg, 3, r2, r1);
}

void cg_cmp_r32_i32(struct cg_state_t *cg, cg_r32_t r1, uint32_t imm) {
  if (r1 == cg_r32_eax) {
    cg_emit_data(cg, "\x3d", 1);
  }
  else {
    cg_emit_data(cg, "\x81", 1);
    cg_modrm(cg, 3, 7, r1);
  }
  cg_emit_data(cg, &imm, sizeof(imm));
}

void cg_call_r64disp(struct cg_state_t *cg, cg_r64_t base, int32_t disp) {
  if (disp >= -128 && disp <= 127) {
    cg_emit_data(cg, "\xff", 1);
    const uint8_t op = 0x50 | (base & 0x7);
    cg_emit_data(cg, &op, 1);
    const int8_t disp8 = disp;
    cg_emit_data(cg, &disp8, 1);
  }
  else {
    cg_emit_data(cg, "\xff", 1);
    const uint8_t op = 0x90 | (base & 0x7);
    cg_emit_data(cg, &op, 1);
    cg_emit_data(cg, &disp, sizeof(disp));
  }
}

void cg_mul_r32(struct cg_state_t *cg, cg_r32_t r1) {
  cg_emit_data(cg, "\xF7", 1);
  cg_modrm(cg, 3, 4, r1);
}

void cg_imul_r32(struct cg_state_t *cg, cg_r32_t r1) {
  cg_emit_data(cg, "\xF7", 1);
  cg_modrm(cg, 3, 5, r1);
}

void cg_push_r64(struct cg_state_t *cg, cg_r64_t r1) {
  const uint8_t inst = 0x50 | (r1 & 0x7);
  cg_emit_data(cg, &inst, 1);
}

void cg_pop_r64(struct cg_state_t *cg, cg_r64_t r1) {
  const uint8_t inst = 0x58 | (r1 & 0x7);
  cg_emit_data(cg, &inst, 1);
}

void cg_nop(struct cg_state_t *cg) {
  cg_emit_data(cg, "\x90", 1);
}

void cg_setcc_r8(struct cg_state_t *cg, cg_cc_t cc, cg_r8_t r1) {
  cg_emit_data(cg, "\x0f", 1);
  const uint8_t op = 0x90 | (cc & 0xf);
  cg_emit_data(cg, &op, 1);
  cg_modrm(cg, 3, 0, r1);
}

void cg_cmov_r32_r32(struct cg_state_t *cg, cg_cc_t cc, cg_r32_t r1,
                     cg_r32_t r2) {
  cg_emit_data(cg, "\x0f", 1);
  const uint8_t op = 0x40 | (cc & 0xf);
  cg_emit_data(cg, &op, 1);
  cg_modrm(cg, 3, r1, r2);
}
