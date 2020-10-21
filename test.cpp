#include <cstring>
#include <cstdio>

#include "tinycg.hpp"


uint8_t buffer[1024];
tinycg::asm_x64_t cg{ buffer, sizeof(buffer) };


#define CHECK() { printf("test % 3d : %s\n", (test++), check(ref) ? "pass" : "fail"); }


namespace {
template <size_t SIZE>
bool check(const uint8_t(&ref)[SIZE]) {
  if (cg.size() == SIZE) {
    if (memcmp(buffer, ref, SIZE) == 0) {
      return true;
    }
  }
  // failure

  printf("expected: ");
  for (int i = 0; i < SIZE; ++i) {
    printf("%02x ", ref[i]);
  }
  printf("\n");
  printf("     got: ");
  for (int i = 0; i < cg.size(); ++i) {
    printf("%02x ", buffer[i]);
  }
  printf("\n");
  return false;
}
}  // namespace {}

static void test_mov() {
  using namespace tinycg;
  printf("---- ---- ---- ---- MOV\n");
  int test = 0;
  {
    cg.clear();
    cg.mov(rsi, rbx);
    const uint8_t ref[] = { 0x48, 0x89, 0xDE };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(rsp, rbp);
    const uint8_t ref[] = { 0x48, 0x89, 0xEC };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(rsp, r10);
    const uint8_t ref[] = { 0x4C, 0x89, 0xD4 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(r8, r10);
    const uint8_t ref[] = { 0x4D, 0x89, 0xD0 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(r8, rdi);
    const uint8_t ref[] = { 0x49, 0x89, 0xF8 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(ebx, deref_t{ rsi });
    const uint8_t ref[] = { 0x8B, 0x1E }; // todo
    CHECK();
  }
  {
    cg.clear();
    cg.mov(ebx, deref_t{ rsi, 123 });
    const uint8_t ref[] = { 0x8B, 0x5E, 0x7B };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(ebx, deref_t{ rsi, 1234 });
    const uint8_t ref[] = { 0x8B, 0x9E, 0xD2, 0x04, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(deref_t{ rsi, 128 }, edx);
    const uint8_t ref[] = { 0x89, 0x96, 0x80, 0x00, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(ebx, edx);
    const uint8_t ref[] = { 0x89, 0xD3 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(ebp, esp);
    const uint8_t ref[] = { 0x89, 0xE5 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(edx, 0);
    const uint8_t ref[] = { 0xBA, 0x00, 0x00, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(edx, 12);
    const uint8_t ref[] = { 0xBA, 0x0C, 0x00, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(edi, 0xcafebabe);
    const uint8_t ref[] = { 0xBF, 0xBE, 0xBA, 0xFE, 0xCA };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(rdx, 0);
    const uint8_t ref[] = { 0x48, 0xC7, 0xC2, 0x00, 0x00, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(r9, 12);
    const uint8_t ref[] = { 0x49, 0xC7, 0xC1, 0x0C, 0x00, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.mov(r11, 0xcafebabe);
    const uint8_t ref[] = { 0x49, 0xC7, 0xC3, 0xBE, 0xBA, 0xFE, 0xCA };
    CHECK();
  }
}

void test_misc() {
  using namespace tinycg;
  printf("---- ---- ---- ---- MISC\n");
  int test = 0;
  {
    cg.clear();
    cg.ret();
    const uint8_t ref[] = { 0xC3 };
    CHECK();
  }
  {
    cg.clear();
    cg.nop();
    const uint8_t ref[] = { 0x90 };
    CHECK();
  }
}

void test_add() {
  using namespace tinycg;
  printf("---- ---- ---- ---- ADD\n");
  int test = 0;
  {
    cg.clear();
    cg.add(eax, edx);
    const uint8_t ref[] = { 0x01, 0xD0 };
    CHECK();
  }
  {
    cg.clear();
    cg.add(esp, eax);
    const uint8_t ref[] = { 0x01, 0xC4 };
    CHECK();
  }
  {
    cg.clear();
    cg.add(esp, 12);
    const uint8_t ref[] = { 0x83, 0xC4, 0x0C };
    CHECK();
  }
  {
    cg.clear();
    cg.add(esp, 1234);
    const uint8_t ref[] = { 0x81, 0xC4, 0xD2, 0x04, 0x00, 0x00 };
    CHECK();
  }
  {
    cg.clear();
    cg.add(eax, 1);
    const uint8_t ref[] = { 0x83, 0xC0, 0x01 };
    CHECK();
  }
  {
    cg.clear();
    cg.add(eax, 12);
    const uint8_t ref[] = { 0x83, 0xC0, 0x0C };
    CHECK();
  }
  {
    cg.clear();
    cg.add(eax, 0xcafebabe);
    const uint8_t ref[] = { 0x05, 0xBE, 0xBA, 0xFE, 0xCA };
    CHECK();
  }
  {
    cg.clear();
    cg.add(eax, -1);
    const uint8_t ref[] = { 0x83, 0xC0, 0xFF };
    CHECK();
  }
  {
    cg.clear();
    cg.add(eax, 0);
    const uint8_t ref[] = { 0x83, 0xC0, 0x00 };
    CHECK();
  }
}

int main(int argc, char **args) {
  using namespace tinycg;

  test_mov();
  test_add();
  test_misc();

  return 0;
}
