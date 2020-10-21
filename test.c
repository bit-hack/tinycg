// ___________.__              _________   ________
// \__    ___/|__| ____ ___.__.\_   ___ \ /  _____/
//   |    |   |  |/    <   |  |/    \  \//   \  ___
//   |    |   |  |   |  \___  |\     \___\    \_\  \
//   |____|   |__|___|  / ____| \______  /\______  /
//  Tiny Code Gen X64 \/\/             \/        \/
//
//  https://github.com/bit-hack/tinycg
//

#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "tinycg.h"


uint8_t buffer[256];
struct cg_state_t cg;


static void test_case_01() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_r32(&cg, cg_eax, cg_edx);
  const uint8_t ref[] = { 0x89, 0xD0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov eax, edx'\n");
}

static void test_case_02() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r32_r8(&cg, cg_eax, cg_dl);
  const uint8_t ref[] = { 0x0F, 0xBE, 0xC2 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx eax, dl'\n");
}

static void test_case_03() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r32_r16(&cg, cg_edx, cg_cx);
  const uint8_t ref[] = { 0x0F, 0xBF, 0xD1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx edx, cx'\n");
}

static void test_case_04() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movzx_r32_r8(&cg, cg_edx, cg_ch);
  const uint8_t ref[] = { 0x0F, 0xB6, 0xD5 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movzx edx, ch'\n");
}

static void test_case_05() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movzx_r32_r16(&cg, cg_edx, cg_cx);
  const uint8_t ref[] = { 0x0F, 0xB7, 0xD1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movzx edx, cx'\n");
}

static void test_case_06() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
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
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_i32(&cg, cg_edx, 0x11223344);
  const uint8_t ref[] = { 0xBA, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, 0x11223344'\n");
}

static void test_case_08() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_i32(&cg, cg_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xC1, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add ecx, 0x11223344'\n");
}

static void test_case_09() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_r32(&cg, cg_ecx, cg_esi);
  const uint8_t ref[] = { 0x01, 0xF1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add ecx, esi'\n");
}

static void test_case_10() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_and_r32_i32(&cg, cg_edi, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xE7, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and edi, 0x11223344'\n");
}

static void test_case_11() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_and_r32_r32(&cg, cg_ebx, cg_edi);
  const uint8_t ref[] = { 0x21, 0xFB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and ebx, edi'\n");
}

static void test_case_12() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r32_i32(&cg, cg_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xE9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub ecx, 0x11223344'\n");
}

static void test_case_13() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r32_r32(&cg, cg_esi, cg_edi);
  const uint8_t ref[] = { 0x29, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub esi, edi'\n");
}

static void test_case_14() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shl_r32_i8(&cg, cg_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xE6, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl esi, 13'\n");
}

static void test_case_15() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shl_r32_i8(&cg, cg_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xE3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl ebx, 1'\n");
}

static void test_case_16() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shl_r32_cl(&cg, cg_ecx);
  const uint8_t ref[] = { 0xD3, 0xE1 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl ecx, cl'\n");
}

static void test_case_17() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_xor_r32_i32(&cg, cg_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xF1, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor ecx, 0x11223344'\n");
}

static void test_case_18() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_xor_r32_r32(&cg, cg_esi, cg_edi);
  const uint8_t ref[] = { 0x31, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor esi, edi'\n");
}

static void test_case_19() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_or_r32_i32(&cg, cg_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xC9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'or ecx, 0x11223344'\n");
}

static void test_case_20() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_or_r32_r32(&cg, cg_esi, cg_edi);
  const uint8_t ref[] = { 0x09, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'or esi, edi'\n");
}

static void test_case_21() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cmp_r32_i32(&cg, cg_ecx, 0x11223344);
  const uint8_t ref[] = { 0x81, 0xF9, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmp ecx, 0x11223344'\n");
}

static void test_case_22() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cmp_r32_r32(&cg, cg_esi, cg_edi);
  const uint8_t ref[] = { 0x39, 0xFE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmp esi, edi'\n");
}

static void test_case_23() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mul_r32(&cg, cg_edx);
  const uint8_t ref[] = { 0xF7, 0xE2 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mul edx'\n");
}

static void test_case_24() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_imul_r32(&cg, cg_ecx);
  const uint8_t ref[] = { 0xF7, 0xE9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'imul ecx'\n");
}

static void test_case_25() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sar_r32_i8(&cg, cg_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xFE, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar esi, 13'\n");
}

static void test_case_26() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sar_r32_i8(&cg, cg_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xFB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar ebx, 1'\n");
}

static void test_case_27() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sar_r32_cl(&cg, cg_ecx);
  const uint8_t ref[] = { 0xD3, 0xF9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sar ecx, cl'\n");
}

static void test_case_28() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shr_r32_i8(&cg, cg_esi, 13);
  const uint8_t ref[] = { 0xC1, 0xEE, 0x0D };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr esi, 13'\n");
}

static void test_case_29() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shr_r32_i8(&cg, cg_ebx, 1);
  const uint8_t ref[] = { 0xD1, 0xEB };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr ebx, 1'\n");
}

static void test_case_30() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shr_r32_cl(&cg, cg_ecx);
  const uint8_t ref[] = { 0xD3, 0xE9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shr ecx, cl'\n");
}

static void test_case_31() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_push_r64(&cg, cg_rcx);
  const uint8_t ref[] = { 0x51 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'push rcx'\n");
}

static void test_case_32() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_pop_r64(&cg, cg_rcx);
  const uint8_t ref[] = { 0x59 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'push rcx'\n");
}

static void test_case_33() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
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
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_call_r64disp(&cg, cg_rsi, 15);
  const uint8_t ref[] = { 0xFF, 0x56, 0x0F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'call [rsi + 15]'\n");
}

static void test_case_35() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_call_r64disp(&cg, cg_rdx, 278);
  const uint8_t ref[] = { 0xFF, 0x92, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'call [rdx + 278]'\n");
}

static void test_case_36() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rdx, 278);
  const uint8_t ref[] = { 0x8B, 0x92, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rdx + 278]'\n");
}

static void test_case_37() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rdx, 63);
  const uint8_t ref[] = { 0x8B, 0x52, 0x3F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rdx + 63]'\n");
}

static void test_case_38() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r32(&cg, cg_rdx, 278, cg_esi);
  const uint8_t ref[] = { 0x89, 0xB2, 0x16, 0x01, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rdx + 278], esi'\n");
}

static void test_case_39() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r32(&cg, cg_rbx, 57, cg_edi);
  const uint8_t ref[] = { 0x89, 0x7B, 0x39 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rbx + 57], edi'\n");
}

static void test_case_40() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_setcc_r8(&cg, cg_cc_lt, cg_bl);
  const uint8_t ref[] = { 0x0F, 0x9C, 0xC3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setl bl'\n");
}

static void test_case_41() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_setcc_r8(&cg, cg_cc_ae, cg_ah);
  const uint8_t ref[] = { 0x0F, 0x93, 0xC4 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setae ah'\n");
}

static void test_case_42() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_setcc_r8(&cg, cg_cc_ns, cg_dh);
  const uint8_t ref[] = { 0x0F, 0x99, 0xC6 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'setns dh'\n");
}

static void test_case_43() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_i32(&cg, cg_esp, 0x1f);
  const uint8_t ref[] = { 0x83, 0xC4, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add esp, 0x1f'\n");
}

static void test_case_44() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_i32(&cg, cg_eax, 127);
  const uint8_t ref[] = { 0x83, 0xC0, 0x7F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add eax, 127'\n");
}

static void test_case_45() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_i32(&cg, cg_edx, -16);
  const uint8_t ref[] = { 0x83, 0xC2, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add edx, -16'\n");
}

static void test_case_46() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r32_i32(&cg, cg_eax, -1024);
  const uint8_t ref[] = { 0x05, 0x00, 0xFC, 0xFF, 0xFF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add eax, -1024'\n");
}

static void test_case_47() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64_i32(&cg, cg_rsp, 0x1f);
  const uint8_t ref[] = { 0x48, 0x83, 0xC4, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rsp, 0x1f'\n");
}

static void test_case_48() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64_i32(&cg, cg_rax, 127);
  const uint8_t ref[] = { 0x48, 0x83, 0xC0, 0x7F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rax, 127'\n");
}

static void test_case_49() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64_i32(&cg, cg_rdx, -16);
  const uint8_t ref[] = { 0x48, 0x83, 0xC2, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rdx, -16'\n");
}

static void test_case_50() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64_i32(&cg, cg_rax, -1024);
  const uint8_t ref[] = { 0x48, 0x05, 0x00, 0xFC, 0xFF, 0xFF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add rax, -1024'\n");
}

static void test_case_51() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r32_i32(&cg, cg_edx, -16);
  const uint8_t ref[] = { 0x83, 0xEA, 0xF0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub edx, -16'\n");
}

static void test_case_52() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r32_i32(&cg, cg_eax, 1024);
  const uint8_t ref[] = { 0x2D, 0x00, 0x04, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub eax, 1024'\n");
}

static void test_case_53() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cmov_r32_r32(&cg, cg_cc_p, cg_eax, cg_edi);
  const uint8_t ref[] = { 0x0F, 0x4A, 0xC7 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmovp eax, edi'\n");
}

static void test_case_54() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cmov_r32_r32(&cg, cg_cc_no, cg_esi, cg_ebx);
  const uint8_t ref[] = { 0x0F, 0x41, 0xF3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmovno esi, ebx'\n");
}

static void test_case_55() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_rsi, 32, cg_rbx);
  const uint8_t ref[] = { 0x48, 0x89, 0x5E, 0x20 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rsi + 32], rbx'\n");
}

static void test_case_56() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_rdx, 1234, cg_rcx);
  const uint8_t ref[] = { 0x48, 0x89, 0x8A, 0xD2, 0x04, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rdx + 1234], rcx'\n");
}

static void test_case_57() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_push_r64(&cg, cg_rbp);
  const uint8_t ref[] = { 0x55 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'push rbp'\n");
}

static void test_case_58() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_rsp, 32, cg_rsi);
  const uint8_t ref[] = { 0x48, 0x89, 0x74, 0x24, 0x20 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rsp + 32], rsi'\n");
}

static void test_case_59() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r32(&cg, cg_rsp, 32, cg_esi);
  const uint8_t ref[] = { 0x89, 0x74, 0x24, 0x20 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rsp + 32], esi'\n");
}

static void test_case_60() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rsp, 32);
  const uint8_t ref[] = { 0x8B, 0x54, 0x24, 0x20 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rsp + 32]'\n");
}

static void test_case_61() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_rsi, cg_rsp, 32);
  const uint8_t ref[] = { 0x48, 0x8B, 0x74, 0x24, 0x20 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsi, [rsp + 32]'\n");
}

static void test_case_62() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_rsi, cg_rsp, 726);
  const uint8_t ref[] = { 0x48, 0x8B, 0xB4, 0x24, 0xD6, 0x02, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsi, [rsp + 726]'\n");
}

static void test_case_63() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_rsp, cg_rbp);
  const uint8_t ref[] = { 0x48, 0x89, 0xEC };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsp, rbp'\n");
}

static void test_case_64() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_rdx, cg_rcx);
  const uint8_t ref[] = { 0x48, 0x89, 0xCA };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rdx, rcx'\n");
}

static void test_case_65() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rsp, -512);
  const uint8_t ref[] = { 0x8B, 0x94, 0x24, 0x00, 0xFE, 0xFF, 0xFF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov edx, [rsp - 512]'\n");
}

static void test_case_66() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64_i32(&cg, cg_rsp, 64);
  const uint8_t ref[] = { 0x48, 0x83, 0xEC, 0x40 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub rsp, 64'\n");
}

static void test_case_67() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64_i32(&cg, cg_rsp, 640);
  const uint8_t ref[] = { 0x48, 0x81, 0xEC, 0x80, 0x02, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub rsp, 640'\n");
}

static void test_case_68() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_rsp, cg_r10);
  const uint8_t ref[] = { 0x4C, 0x89, 0xD4 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsp, r10'\n");
}

static void test_case_69() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_r11, cg_rdx);
  const uint8_t ref[] = { 0x49, 0x89, 0xD3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r11, rdx'\n");
}

static void test_case_70() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_i32(&cg, cg_r11, 0x11223344);
  const uint8_t ref[] = { 0x49, 0xC7, 0xC3, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r11, 0x11223344'\n");
}

static void test_case_71() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_i32(&cg, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0x48, 0xC7, 0xC6, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsi, 0x11223344'\n");
}

static void test_case_72() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_r11, cg_r8);
  const uint8_t ref[] = { 0x4D, 0x89, 0xC3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r11, r8'\n");
}

static void test_case_73() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64(&cg, cg_rsp, cg_rbp);
  const uint8_t ref[] = { 0x48, 0x89, 0xEC };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r11, r8'\n");
}

static void test_case_74() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_i32(&cg, cg_rsi, 0x11);
  const uint8_t ref[] = { 0x48, 0xC7, 0xC6, 0x11, 0x00, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rsi, 0x11'\n");
}

static void test_case_75() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_i32(&cg, cg_r8, 0x11);
  const uint8_t ref[] = { 0x49, 0xC7, 0xC0, 0x11, 0x00, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r8, 0x11'\n");
}

static void test_case_76() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64_i32(&cg, cg_r10, 0x11);
  const uint8_t ref[] = { 0x49, 0x83, 0xC2, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add r10, 0x11'\n");
}

static void test_case_77() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64_i32(&cg, cg_r10, 0x11);
  const uint8_t ref[] = { 0x49, 0x83, 0xEA, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub r10, 0x11'\n");
}

static void test_case_78() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_r8, 1, cg_r10);
  const uint8_t ref[] = { 0x4D, 0x89, 0x50, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [r8 + 1], r10'\n");
}

static void test_case_79() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_rax, 1, cg_r10);
  const uint8_t ref[] = { 0x4C, 0x89, 0x50, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [rax + 1], r10'\n");
}

static void test_case_80() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_r8, 1, cg_rax);
  const uint8_t ref[] = { 0x49, 0x89, 0x40, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [r8 + 1], rax'\n");
}

static void test_case_81() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_r10, cg_r8, 1);
  const uint8_t ref[] = { 0x4D, 0x8B, 0x50, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r10, [r8 + 1]'\n");
}

static void test_case_82() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_rax, cg_r8, 1);
  const uint8_t ref[] = { 0x49, 0x8B, 0x40, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov rax, [r8 + 1]'\n");
}

static void test_case_83() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_r10, cg_rax, 1);
  const uint8_t ref[] = { 0x4C, 0x8B, 0x50, 0x01 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r10, [rax + 1]'\n");
}

static void test_case_84() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64_r64disp(&cg, cg_r10, cg_rax, 1234);
  const uint8_t ref[] = { 0x4C, 0x8B, 0x90, 0xD2, 0x04, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov r10, [rax + 1234]'\n");
}

static void test_case_85() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_r64(&cg, cg_r8, 1234, cg_rax);
  const uint8_t ref[] = { 0x49, 0x89, 0x80, 0xD2, 0x04, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov [r8 + 1234], rax'\n");
}

static void test_case_86() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_xor_r64_r64(&cg, cg_r8, cg_rax);
  const uint8_t ref[] = { 0x49, 0x31, 0xC0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor r8, rax'\n");
}

static void test_case_87() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cmp_r64_r64(&cg, cg_rsi, cg_rdx);
  const uint8_t ref[] = { 0x48, 0x39, 0xD6 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cmp rsi, rdx'\n");
}

static void test_case_88() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_and_r8_i8(&cg, cg_al, 0x1f);
  const uint8_t ref[] = { 0x24, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and al, 0x1f'\n");
}

static void test_case_89() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_and_r8_i8(&cg, cg_dl, 0x1f);
  const uint8_t ref[] = { 0x80, 0xE2, 0x1F };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and dl, 0x1f'\n");
}

static void test_case_90() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x10, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_91() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movss_r64disp_xmm(&cg, cg_rsi, 0x11223344, cg_xmm0);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x11, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movss [rsi + 0x11223344], xmm0'\n");
}

static void test_case_92() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_addss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x58, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'addss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_93() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_subss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x5C, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'subss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_94() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mulss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x59, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mulss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_95() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_divss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x5E, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'divss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_96() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sqrtss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x51, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sqrtss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_97() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cvttss2si_r32_r64disp(&cg, cg_eax, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x2C, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cvttss2si eax, [rsi + 0x11223344]'\n");
}

static void test_case_98() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cvtsi2ss_xmm_r64disp(&cg, cg_xmm0, cg_rsi, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x2A, 0x86, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cvtsi2ss xmm0, [rsi + 0x11223344]'\n");
}

static void test_case_99() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_xmm(&cg, cg_eax, cg_xmm0);
  const uint8_t ref[] = { 0x66, 0x0F, 0x7E, 0xC0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movd eax, xmm0'\n");
}

static void test_case_100() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_xmm_r32(&cg, cg_xmm0, cg_eax);
  const uint8_t ref[] = { 0x66, 0x0F, 0x6E, 0xC0 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movd xmm0, eax'\n");
}

static void test_case_101() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r32_xmm(&cg, cg_esi, cg_xmm5);
  const uint8_t ref[] = { 0x66, 0x0F, 0x7E, 0xEE };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movd esi, xmm5'\n");
}

static void test_case_102() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_xmm_r32(&cg, cg_xmm4, cg_ebx);
  const uint8_t ref[] = { 0x66, 0x0F, 0x6E, 0xE3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movd xmm4, ebx'\n");
}

static void test_case_103() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cvtsi2ss_xmm_r64disp(&cg, cg_xmm3, cg_rbx, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x2A, 0x9B, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cvtsi2ss xmm3, dword ptr [rbx + 0x11223344]'\n");
}

static void test_case_104() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_cvttss2si_r32_r64disp(&cg, cg_ebx, cg_rcx, 0x11223344);
  const uint8_t ref[] = { 0xF3, 0x0F, 0x2C, 0x99, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'cvttss2si ebx, dword ptr [rcx + 0x11223344]'\n");
}

static void test_case_105() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_i32(&cg, cg_rsi, 0x58, 0x11223344);
  const uint8_t ref[] = { 0xC7, 0x46, 0x58, 0x44, 0x33, 0x22, 0x11 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov dword ptr [rsi + 0x58], 0x11223344'\n");
}

static void test_case_106() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mov_r64disp_i32(&cg, cg_rcx, 0xcafe, 0xbabe);
  const uint8_t ref[] = { 0xC7, 0x81, 0xFE, 0xCA, 0x00, 0x00, 0xBE, 0xBA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mov dword ptr [rcx + 0xcafe], 0xbabe'\n");
}

static void test_case_107() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r32(&cg, cg_r8, cg_ebx);
  const uint8_t ref[] = { 0x4C, 0x63, 0xC3 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx r8, ebx'\n");
}

static void test_case_108() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r32(&cg, cg_rdi, cg_ecx);
  const uint8_t ref[] = { 0x48, 0x63, 0xF9 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx rdi, ecx'\n");
}

static void test_case_109() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r32(&cg, cg_r11, cg_edi);
  const uint8_t ref[] = { 0x4C, 0x63, 0xDF };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx r11, edi'\n");
}

static void test_case_110() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r64disp(&cg, cg_r8, cg_rsi, 0xcafe);
  const uint8_t ref[] = { 0x4C, 0x63, 0x86, 0xFE, 0xCA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx r8, dword ptr [rsi + 0xcafe]'\n");
}

static void test_case_111() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r64disp(&cg, cg_rdi, cg_rcx, 0xcafe);
  const uint8_t ref[] = { 0x48, 0x63, 0xB9, 0xFE, 0xCA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx rdi, dword ptr [rcx + 0xcafe]'\n");
}

static void test_case_112() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_movsx_r64_r64disp(&cg, cg_rdi, cg_rcx, 12);
  const uint8_t ref[] = { 0x48, 0x63, 0x79, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'movsx rdi, dword ptr [rcx + 12]'\n");
}

static void test_case_113() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64disp_i32(&cg, cg_rsi, 0xcafe, 0xbabe);
  const uint8_t ref[] = { 0x81, 0x86, 0xFE, 0xCA, 0x00, 0x00, 0xBE, 0xBA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add dword ptr [rsi + 0xcafe], 0xbabe'\n");
}

static void test_case_114() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_add_r64disp_i32(&cg, cg_rbx, 12, 0xbabe);
  const uint8_t ref[] = { 0x81, 0x43, 0x0C, 0xBE, 0xBA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'add dword ptr [rbx + 12], 0xbabe'\n");
}

static void test_case_115() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64disp_i32(&cg, cg_rsi, 0xcafe, 0xbabe);
  const uint8_t ref[] = { 0x81, 0xAE, 0xFE, 0xCA, 0x00, 0x00, 0xBE, 0xBA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub dword ptr [rsi + 0xcafe], 0xbabe'\n");
}

static void test_case_116() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64disp_i32(&cg, cg_rbx, 12, 0xbabe);
  const uint8_t ref[] = { 0x81, 0x6B, 0x0C, 0xBE, 0xBA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub dword ptr [rbx + 12], 0xbabe'\n");
}

static void test_case_117() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64disp_i32(&cg, cg_rbx, 0xcafe, 12);
  const uint8_t ref[] = { 0x83, 0xAB, 0xFE, 0xCA, 0x00, 0x00, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub dword ptr [rbx + 0xcafe], 12'\n");
}

static void test_case_118() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_sub_r64disp_i32(&cg, cg_rbx, 19, 12);
  const uint8_t ref[] = { 0x83, 0x6B, 0x13, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'sub dword ptr [rbx + 19], 12'\n");
}

static void test_case_119() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_and_r64disp_i32(&cg, cg_rbx, 19, 12);
  const uint8_t ref[] = { 0x83, 0x63, 0x13, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'and dword ptr [rbx + 19], 12'\n");
}

static void test_case_120() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_or_r64disp_i32(&cg, cg_rbx, 19, 12);
  const uint8_t ref[] = { 0x83, 0x4B, 0x13, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'or dword ptr [rbx + 19], 12'\n");
}

static void test_case_121() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_xor_r64disp_i32(&cg, cg_rbx, 19, 12);
  const uint8_t ref[] = { 0x83, 0x73, 0x13, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'xor dword ptr [rbx + 19], 12'\n");
}

static void test_case_122() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shl_r64disp_i8(&cg, cg_rbx, 19, 12);
  const uint8_t ref[] = { 0xC1, 0x63, 0x13, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl dword ptr [rbx + 19], 12'\n");
}

static void test_case_123() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_shl_r64disp_i8(&cg, cg_rdx, 0xcafe, 12);
  const uint8_t ref[] = { 0xC1, 0xA2, 0xFE, 0xCA, 0x00, 0x00, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'shl dword ptr [rdx + 0xcafe], 12'\n");
}

static void test_case_124() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_imul_r64disp(&cg, cg_rsi, 0xcafe);
  const uint8_t ref[] = { 0xF7, 0xAE, 0xFE, 0xCA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'imul dword ptr [rsi + 0xcafe]'\n");
}

static void test_case_125() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_imul_r64disp(&cg, cg_rsi, 12);
  const uint8_t ref[] = { 0xF7, 0x6E, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'imul dword ptr [rsi + 0xcafe]'\n");
}

static void test_case_126() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mul_r64disp(&cg, cg_rsi, 0xcafe);
  const uint8_t ref[] = { 0xF7, 0xA6, 0xFE, 0xCA, 0x00, 0x00 };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mul dword ptr [rsi + 0xcafe]'\n");
}

static void test_case_127() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));
  cg_mul_r64disp(&cg, cg_rsi, 12);
  const uint8_t ref[] = { 0xF7, 0x66, 0x0C };
  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'mul dword ptr [rsi + 0xcafe]'\n");
}


static void test_case_bb1() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));

  // push rbp
  // mov rbp, rsp
  // add rsp, -64
  // mov [rsp + 32], rsi
  // mov rsi, rcx
  // mov eax, 414220
  // mov [rsi + 200], eax
  // mov rsi, [rsp + 32]
  // mov rsp, rbp
  // pop rbp
  // ret

  cg_push_r64(&cg, cg_rbp);
  cg_mov_r64_r64(&cg, cg_rbp, cg_rsp);
  cg_add_r64_i32(&cg, cg_rsp, -64);
  cg_mov_r64disp_r64(&cg, cg_rsp, 32, cg_rsi);
  cg_mov_r64_r64(&cg, cg_rsi, cg_rcx);
  cg_mov_r32_i32(&cg, cg_eax, 414220);
  cg_mov_r64disp_r32(&cg, cg_rsi, 200, cg_eax);
  cg_mov_r64_r64disp(&cg, cg_rsi, cg_rsp, 32);
  cg_mov_r64_r64(&cg, cg_rsp, cg_rbp);
  cg_pop_r64(&cg, cg_rbp);
  cg_ret(&cg);

  const uint8_t ref[] = {
    0x55,
    0x48, 0x89, 0xE5,
    0x48, 0x83, 0xC4, 0xC0,
    0x48, 0x89, 0x74, 0x24, 0x20,
    0x48, 0x89, 0xCE,
    0xB8, 0x0C, 0x52, 0x06, 0x00,
    0x89, 0x86, 0xC8, 0x00, 0x00, 0x00,
    0x48, 0x8B, 0x74, 0x24, 0x20,
    0x48, 0x89, 0xEC,
    0x5D,
    0xC3
  };

  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'basic block 1'\n");
}

static void test_case_bb2() {
  cg_init(&cg, buffer, buffer + sizeof(buffer));

  //  mov[rsi + 76], eax
  //  mov r8, 0x145fd0
  //  mov edx, [rsi + 80]
  //  add edx, 0x08
  //  call[rsi + 8]
  //  mov[rsi + 104], eax
  //  mov r8, 0x145fd0
  //  mov edx, [rsi + 80]
  //  add edx, 04

  cg_mov_r64disp_r32(&cg, cg_rsi, 76, cg_eax);
  cg_mov_r64_i32(&cg, cg_r8, 0x145fd0);
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rsi, 80);
  cg_add_r32_i32(&cg, cg_edx, 8);
  cg_call_r64disp(&cg, cg_rsi, 8);
  cg_mov_r64disp_r32(&cg, cg_rsi, 104, cg_eax);
  cg_mov_r64_i32(&cg, cg_r8, 0x145fd0);
  cg_mov_r32_r64disp(&cg, cg_edx, cg_rsi, 80);
  cg_add_r32_i32(&cg, cg_edx, 4);

  const uint8_t ref[] = {
    0x89, 0x46, 0x4C,
    0x49, 0xC7, 0xC0, 0xD0, 0x5F, 0x14, 0x00,
    0x8B, 0x56, 0x50,
    0x83, 0xC2, 0x08,
    0xFF, 0x56, 0x08,
    0x89, 0x46, 0x68,
    0x49, 0xC7, 0xC0, 0xD0, 0x5F, 0x14, 0x00,
    0x8B, 0x56, 0x50,
    0x83, 0xC2, 0x04
  };

  if (cg_size(&cg) == sizeof(ref)) {
    if (0 == memcmp(ref, buffer, cg_size(&cg))) {
      return;
    }
  }
  fprintf(stderr, "fail 'basic block 2'\n");
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
  test_case_53();
  test_case_54();
  test_case_55();
  test_case_56();
  test_case_57();
  test_case_58();
  test_case_59();
  test_case_60();
  test_case_61();
  test_case_62();
  test_case_63();
  test_case_64();
  test_case_65();
  test_case_66();
  test_case_67();
  test_case_68();
  test_case_69();
  test_case_70();
  test_case_71();
  test_case_72();
  test_case_73();
  test_case_74();
  test_case_75();
  test_case_76();
  test_case_77();
  test_case_78();
  test_case_79();
  test_case_80();
  test_case_81();
  test_case_82();
  test_case_83();
  test_case_84();
  test_case_85();
  test_case_86();
  test_case_87();
  test_case_88();
  test_case_89();
  test_case_90();
  test_case_91();
  test_case_92();
  test_case_93();
  test_case_94();
  test_case_95();
  test_case_96();
  test_case_97();
  test_case_98();
  test_case_99();
  test_case_100();
  test_case_101();
  test_case_102();
  test_case_103();
  test_case_104();
  test_case_105();
  test_case_106();
  test_case_107();
  test_case_108();
  test_case_109();
  test_case_110();
  test_case_111();
  test_case_112();
  test_case_113();
  test_case_114();
  test_case_115();
  test_case_116();
  test_case_117();
  test_case_118();
  test_case_119();
  test_case_120();
  test_case_121();
  test_case_122();
  test_case_123();
  test_case_124();
  test_case_125();
  test_case_126();
  test_case_127();

  test_case_bb1();
  test_case_bb2();

  return 0;
}
