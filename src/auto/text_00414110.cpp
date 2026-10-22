/* 4 functions from 0x00414110 to 0x00414820, found by Ghidra. */
#include "common.h"

extern "C" int D_00692370;
extern "C" void func_00407280(void *, unsigned char);
extern "C" void func_00407610(void *, void *, int, int);
extern "C" void func_0044A910(void *);

extern "C" void func_00414750(char *p)
{
    unsigned int i;
    for (i = 0; i < *(unsigned int *)(*(char **)(p + 0x398) + 0xe8); i++) {
        int *t = (int *)(p + 0x440) + i;
        if (*t < 10000) {
            func_00407610(p + 0x310, *(char **)(*(char **)(p + 0x398) + 0xec) + i * 0xc + 4,
                          (unsigned char)(i - 0x10), *t);
            func_0044A910(p + 0x324);
            *t += D_00692370;
        }
    }
}

extern "C" void func_004147E0(char *p, int idx)
{
    *(int *)(p + 0x440 + idx * 4) = 10001;
    func_00407280(p + 0x310, (unsigned char)(idx - 0x10));
    func_0044A910(p + 0x324);
}
