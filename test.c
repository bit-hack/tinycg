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
  return 0;
}
