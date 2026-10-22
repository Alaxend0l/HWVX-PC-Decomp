/* 4 functions from 0x00414110 to 0x00414820, found by Ghidra. */
#include "common.h"

extern "C" int D_00692370;
extern "C" void func_00407280(void *, unsigned char);
extern "C" void func_00407610(void *, void *, unsigned char, int);
extern "C" void func_0044A910(void *);

extern "C" void func_004147E0(char *p, int idx)
{
    *(int *)(p + 0x440 + idx * 4) = 10001;
    func_00407280(p + 0x310, (unsigned char)(idx - 0x10));
    func_0044A910(p + 0x324);
}
