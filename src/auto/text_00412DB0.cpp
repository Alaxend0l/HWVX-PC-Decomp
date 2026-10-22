/* 4 functions from 0x00412DB0 to 0x00413540, found by Ghidra. */
#include "common.h"

struct Flags_00412DB0 {
    int b0_6 : 7;
    int b7 : 1;
    int rest : 24;
};

extern "C" void func_00412FD0(char *p)
{
    char *q;
    for (q = *(char **)(p + 0x324); q != 0; q = *(char **)(q + 0xa4)) {
        if (*(int *)(q + 0xa8) == 0xd)
            *(int *)(q + 0x74) &= ~0x10;
    }
    *(volatile int *)(p + 0x460) &= ~0x80;
}

extern "C" int func_00413010(char *p, char **out)
{
    char *q = *(char **)(p + 0x324);
    unsigned int f = *(unsigned int *)(p + 0x460);
    int n = 0;
    if (f & 0x200)
        return 0;
    for (; q != 0; q = *(char **)(q + 0xa4)) {
        if (*(int *)(q + 0xa8) == 0xd && (*(unsigned int *)(q + 0x74) & 0x10) && !(*(unsigned int *)(q + 0x74) & 0x4020)) {
            *out = q;
            n++;
            out++;
        }
    }
    return n;
}

