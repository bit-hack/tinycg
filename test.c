#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "tinycg.h"


uint8_t buffer[128];


static void test_case_01() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r32_r32(&cg, cg_r32_eax, cg_r32_edx);
  const uint8_t ref[] = { 0x89, 0xD0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov eax, edx'\n");
}

static void test_case_02() {
  struct cg_state_t cg = { buffer, buffer };
  cg_movsx_r32_r8(&cg, cg_r32_eax, cg_r8_dl);
  const uint8_t ref[] = { 0x0F, 0xBE, 0xC2 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx eax, dl'\n");
}

static void test_case_03() {
  struct cg_state_t cg = { buffer, buffer };
  cg_movsx_r32_r16(&cg, cg_r32_edx, cg_r16_cx);
  const uint8_t ref[] = { 0x0F, 0xBF, 0xD1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx edx, cx'\n");
}

static void test_case_04() {
  struct cg_state_t cg = { buffer, buffer };
  cg_movzx_r32_r8(&cg, cg_r32_edx, cg_r8_ch);
  const uint8_t ref[] = { 0x0F, 0xB6, 0xD5 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movzx edx, ch'\n");
}

static void test_case_05() {
  struct cg_state_t cg = { buffer, buffer };
  cg_movzx_r32_r16(&cg, cg_r32_edx, cg_r16_cx);
  const uint8_t ref[] = { 0x0F, 0xB7, 0xD1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movzx edx, cx'\n");
}

static void test_case_06() {
  struct cg_state_t cg = { buffer, buffer };
  cg_ret(&cg);
  const uint8_t ref[] = { 0xC3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'ret'\n");
}

static void test_case_07() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r32_i32(&cg, cg_r32_edx, 0x11223344);
  const uint8_t ref[] = { 0xBA, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, 0x11223344'\n");
}

static void test_case_08() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_i32(&cg, cg_r32_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xC1, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add ecx, 0x11223344'\n");
}

static void test_case_09() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_r32(&cg, cg_r32_ecx, cg_r32_esi);
  const uint8_t ref[] = { 0x01, 0xF1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add ecx, esi'\n");
}

static void test_case_10() {
  struct cg_state_t cg = { buffer, buffer };
  cg_and_r32_i32(&cg, cg_r32_edi, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xE7, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and edi, 0x11223344'\n");
}

static void test_case_11() {
  struct cg_state_t cg = { buffer, buffer };
  cg_and_r32_r32(&cg, cg_r32_ebx, cg_r32_edi);
  const uint8_t ref[] = { 0x21, 0xFB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and ebx, edi'\n");
}

static void test_case_12() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sub_r32_i32(&cg, cg_r32_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xE9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub ecx, 0x11223344'\n");
}

static void test_case_13() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sub_r32_r32(&cg, cg_r32_esi, cg_r32_edi);
  const uint8_t ref[] = { 0x29, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub esi, edi'\n");
}

static void test_case_14() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shl_r32_i8(&cg, cg_r32_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xE6, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl esi, 13'\n");
}

static void test_case_15() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shl_r32_i8(&cg, cg_r32_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xE3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl ebx, 1'\n");
}

static void test_case_16() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shl_r32_cl(&cg, cg_r32_ecx);
  const uint8_t ref[] = { 0xD3, 0xE1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl ecx, cl'\n");
}

static void test_case_17() {
  struct cg_state_t cg = { buffer, buffer };
  cg_xor_r32_i32(&cg, cg_r32_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xF1, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor ecx, 0x11223344'\n");
}

static void test_case_18() {
  struct cg_state_t cg = { buffer, buffer };
  cg_xor_r32_r32(&cg, cg_r32_esi, cg_r32_edi);
  const uint8_t ref[] = { 0x31, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor esi, edi'\n");
}

static void test_case_19() {
  struct cg_state_t cg = { buffer, buffer };
  cg_or_r32_i32(&cg, cg_r32_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xC9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'or ecx, 0x11223344'\n");
}

static void test_case_20() {
  struct cg_state_t cg = { buffer, buffer };
  cg_or_r32_r32(&cg, cg_r32_esi, cg_r32_edi);
  const uint8_t ref[] = { 0x09, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'or esi, edi'\n");
}

static void test_case_21() {
  struct cg_state_t cg = { buffer, buffer };
  cg_cmp_r32_i32(&cg, cg_r32_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xF9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmp ecx, 0x11223344'\n");
}

static void test_case_22() {
  struct cg_state_t cg = { buffer, buffer };
  cg_cmp_r32_r32(&cg, cg_r32_esi, cg_r32_edi);
  const uint8_t ref[] = { 0x39, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmp esi, edi'\n");
}

static void test_case_23() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mul_r32(&cg, cg_r32_edx);
  const uint8_t ref[] = { 0xF7, 0xE2 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mul edx'\n");
}

static void test_case_24() {
  struct cg_state_t cg = { buffer, buffer };
  cg_imul_r32(&cg, cg_r32_ecx);
  const uint8_t ref[] = { 0xF7, 0xE9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'imul ecx'\n");
}

static void test_case_25() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sar_r32_i8(&cg, cg_r32_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xFE, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar esi, 13'\n");
}

static void test_case_26() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sar_r32_i8(&cg, cg_r32_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xFB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar ebx, 1'\n");
}

static void test_case_27() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sar_r32_cl(&cg, cg_r32_ecx);
  const uint8_t ref[] = { 0xD3, 0xF9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar ecx, cl'\n");
}

static void test_case_28() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shr_r32_i8(&cg, cg_r32_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xEE, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr esi, 13'\n");
}

static void test_case_29() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shr_r32_i8(&cg, cg_r32_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xEB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr ebx, 1'\n");
}

static void test_case_30() {
  struct cg_state_t cg = { buffer, buffer };
  cg_shr_r32_cl(&cg, cg_r32_ecx);
  const uint8_t ref[] = { 0xD3, 0xE9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr ecx, cl'\n");
}

static void test_case_31() {
  struct cg_state_t cg = { buffer, buffer };
  cg_push_r64(&cg, cg_r64_rcx);
  const uint8_t ref[] = { 0x51 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'push rcx'\n");
}

static void test_case_32() {
  struct cg_state_t cg = { buffer, buffer };
  cg_pop_r64(&cg, cg_r64_rcx);
  const uint8_t ref[] = { 0x59 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'push rcx'\n");
}

static void test_case_33() {
  struct cg_state_t cg = { buffer, buffer };
  cg_nop(&cg);
  const uint8_t ref[] = { 0x90 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'nop'\n");
}

static void test_case_34() {
  struct cg_state_t cg = { buffer, buffer };
  cg_call_r64disp(&cg, cg_r64_rsi, 15);
  const uint8_t ref[] = { 0xFF, 0x56, 0x0F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'call [rsi + 15]'\n");
}

static void test_case_35() {
  struct cg_state_t cg = { buffer, buffer };
  cg_call_r64disp(&cg, cg_r64_rdx, 278);
  const uint8_t ref[] = { 0xFF, 0x92, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'call [rdx + 278]'\n");
}

static void test_case_36() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r32_r64disp(&cg, cg_r32_edx, cg_r64_rdx, 278);
  const uint8_t ref[] = { 0x8B, 0x92, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rdx + 278]'\n");
}

static void test_case_37() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r32_r64disp(&cg, cg_r32_edx, cg_r64_rdx, 63);
  const uint8_t ref[] = { 0x8B, 0x52, 0x3F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rdx + 63]'\n");
}

static void test_case_38() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r64disp_r32(&cg, cg_r64_rdx, 278, cg_r32_esi);
  const uint8_t ref[] = { 0x89, 0xB2, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rdx + 278], esi'\n");
}

static void test_case_39() {
  struct cg_state_t cg = { buffer, buffer };
  cg_mov_r64disp_r32(&cg, cg_r64_rbx, 57, cg_r32_edi);
  const uint8_t ref[] = { 0x89, 0x7B, 0x39 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rbx + 57], edi'\n");
}

static void test_case_40() {
  struct cg_state_t cg = { buffer, buffer };
  cg_setcc_r8(&cg, cg_cc_lt, cg_r8_bl);
  const uint8_t ref[] = { 0x0F, 0x9C, 0xC3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setl bl'\n");
}

static void test_case_41() {
  struct cg_state_t cg = { buffer, buffer };
  cg_setcc_r8(&cg, cg_cc_ae, cg_r8_ah);
  const uint8_t ref[] = { 0x0F, 0x93, 0xC4 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setae ah'\n");
}

static void test_case_42() {
  struct cg_state_t cg = { buffer, buffer };
  cg_setcc_r8(&cg, cg_cc_ns, cg_r8_dh);
  const uint8_t ref[] = { 0x0F, 0x99, 0xC6 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setns dh'\n");
}

static void test_case_43() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_i32(&cg, cg_r32_esp, 0x1f);
  const uint8_t ref[] = { 0x83, 0xC4, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add esp, 0x1f'\n");
}

static void test_case_44() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_i32(&cg, cg_r32_eax, 127);
  const uint8_t ref[] = { 0x83, 0xC0, 0x7F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add eax, 127'\n");
}

static void test_case_45() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_i32(&cg, cg_r32_edx, -16);
  const uint8_t ref[] = { 0x83, 0xC2, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add edx, -16'\n");
}

static void test_case_46() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r32_i32(&cg, cg_r32_eax, -1024);
  const uint8_t ref[] = { 0x05, 0x00, 0xFC, 0xFF, 0xFF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add eax, -1024'\n");
}

static void test_case_47() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r64_i32(&cg, cg_r64_rsp, 0x1f);
  const uint8_t ref[] = { 0x48, 0x83, 0xC4, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rsp, 0x1f'\n");
}

static void test_case_48() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r64_i32(&cg, cg_r64_rax, 127);
  const uint8_t ref[] = { 0x48, 0x83, 0xC0, 0x7F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rax, 127'\n");
}

static void test_case_49() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r64_i32(&cg, cg_r64_rdx, -16);
  const uint8_t ref[] = { 0x48, 0x83, 0xC2, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rdx, -16'\n");
}

static void test_case_50() {
  struct cg_state_t cg = { buffer, buffer };
  cg_add_r64_i32(&cg, cg_r64_rax, -1024);
  const uint8_t ref[] = { 0x48, 0x05, 0x00, 0xFC, 0xFF, 0xFF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rax, -1024'\n");
}

static void test_case_51() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sub_r32_i32(&cg, cg_r32_edx, -16);
  const uint8_t ref[] = { 0x83, 0xEA, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub edx, -16'\n");
}

static void test_case_52() {
  struct cg_state_t cg = { buffer, buffer };
  cg_sub_r32_i32(&cg, cg_r32_eax, 1024);
  const uint8_t ref[] = { 0x2D, 0x00, 0x04, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub eax, 1024'\n");
}

static void test_cast_53() {
  struct cg_state_t cg = { buffer, buffer };
  cg_cmov_r32_r32(&cg, cg_cc_p, cg_r32_eax, cg_r32_edi);
  const uint8_t ref[] = { 0x0F, 0x4A, 0xC7 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmovp eax, edi'\n");
}

static void test_cast_54() {
  struct cg_state_t cg = { buffer, buffer };
  cg_cmov_r32_r32(&cg, cg_cc_no, cg_r32_esi, cg_r32_ebx);
  const uint8_t ref[] = { 0x0F, 0x41, 0xF3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmovno esi, ebx'\n");
}

int main() {
  test_case_01();
  test_case_02();
  test_case_03();
  test_case_04();
  test_case_05();
  test_case_06();
  test_case_07();
  test_case_08();
  test_case_09();
  test_case_10();
  test_case_11();
  test_case_12();
  test_case_13();
  test_case_14();
  test_case_15();
  test_case_16();
  test_case_17();
  test_case_18();
  test_case_19();
  test_case_20();
  test_case_21();
  test_case_22();
  test_case_23();
  test_case_24();
  test_case_25();
  test_case_26();
  test_case_27();
  test_case_28();
  test_case_29();
  test_case_30();
  test_case_31();
  test_case_32();
  test_case_33();
  test_case_34();
  test_case_35();
  test_case_36();
  test_case_37();
  test_case_38();
  test_case_39();
  test_case_40();
  test_case_41();
  test_case_42();
  test_case_43();
  test_case_44();
  test_case_45();
  test_case_46();
  test_case_47();
  test_case_48();
  test_case_49();
  test_case_50();
  test_case_51();
  test_case_52();
  test_cast_53();
  test_cast_54();
  return 0;
}
