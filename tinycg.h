#pragma once
#include <stdint.h>

typedef int cg_r8_t;
typedef int cg_r16_t;
typedef int cg_r32_t;
typedef int cg_r64_t;

enum {
  cg_r8_al,
  cg_r8_cl,
  cg_r8_dl,
  cg_r8_bl,
  cg_r8_ah,
  cg_r8_ch,
  cg_r8_dh,
  cg_r8_bh,
};

enum {
  cg_r16_ax,
  cg_r16_cx,
  cg_r16_dx,
  cg_r16_bx,
  cg_r16_sp,
  cg_r16_bp,
  cg_r16_si,
  cg_r16_di,
};

enum {
  cg_r32_eax,
  cg_r32_ecx,
  cg_r32_edx,
  cg_r32_ebx,
  cg_r32_esp,
  cg_r32_ebp,
  cg_r32_esi,
  cg_r32_edi,
};

enum {
  cg_r64_rax,
  cg_r64_rcx,
  cg_r64_rdx,
  cg_r64_rbx,
  cg_r64_rsp,
  cg_r64_rbp,
  cg_r64_rsi,
  cg_r64_rdi,
};

struct cg_state_t {
  uint8_t *start;
  uint8_t *head;
};

//tested
void cg_mov_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);
//tested
void cg_mov_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);

//tested
void cg_ret            (struct cg_state_t *);

void cg_mov_r32_r64disp(struct cg_state_t *, uint32_t r1, uint32_t base, int32_t disp);
void cg_mov_r64disp_r32(struct cg_state_t *, uint32_t base, int32_t disp, uint32_t r1);

//tested
void cg_movsx_r32_r8   (struct cg_state_t *, uint32_t r1, uint32_t r2);
//tested
void cg_movsx_r32_r16  (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_movzx_r32_r8   (struct cg_state_t *, uint32_t r1, uint32_t r2);
//tested
void cg_movzx_r32_r16  (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_add_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);
//tested
void cg_add_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_and_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);
//tested
void cg_and_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_sub_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);
//tested
void cg_sub_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_shl_r32_i8     (struct cg_state_t *, uint32_t r1, uint8_t imm);
//tested
void cg_shl_r32_cl     (struct cg_state_t *, uint32_t r1);

//tested
void cg_sar_r32_i8     (struct cg_state_t *, uint32_t r1, uint8_t imm);
//tested
void cg_sar_r32_cl     (struct cg_state_t *, uint32_t r1);

//tested
void cg_shr_r32_i8     (struct cg_state_t *, uint32_t r1, uint8_t imm);
//tested
void cg_shr_r32_cl     (struct cg_state_t *, uint32_t r1);

//tested
void cg_xor_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);
//tested
void cg_xor_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);

//tested
void cg_or_r32_i32     (struct cg_state_t *, uint32_t r1, uint32_t imm);
//tested
void cg_or_r32_r32     (struct cg_state_t *, uint32_t r1, uint32_t r2);

void cg_setl_r8        (struct cg_state_t *, uint32_t r1);
void cg_setb_r8        (struct cg_state_t *, uint32_t r1);

//tested
void cg_cmp_r32_r32    (struct cg_state_t *, uint32_t r1, uint32_t r2);
//tested
void cg_cmp_r32_i32    (struct cg_state_t *, uint32_t r1, uint32_t imm);

void cg_call_r64disp   (struct cg_state_t *, uint32_t base, int32_t disp32);

//tested
void cg_mul_r32        (struct cg_state_t *, uint32_t r1);
//tested
void cg_imul_r32       (struct cg_state_t *, uint32_t r1);

//tested
void cg_push_r64       (struct cg_state_t *, uint32_t r1);
//tested
void cg_pop_r64        (struct cg_state_t *, uint32_t r1);

//tested
void cg_nop            (struct cg_state_t *);

//tested
uint32_t cg_size       (struct cg_state_t *);
