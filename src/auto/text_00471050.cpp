/* 22 functions from 0x00471050 to 0x004718BD, found by Ghidra. */
#include "common.h"
#include <string.h>

extern "C" unsigned int func_004710A8(unsigned int, unsigned int);
#pragma optimize("s", on)
extern "C" void func_0047148E(void *p)
{
    memset(p, 0, 12);
}

extern "C" int D_0047FE60;
extern "C" int func_00471542(int, int, void *);
extern "C" int D_0049DAF0;
extern "C" long D_006D5788;
extern "C" int D_006D5784;
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" int func_0047127D(int);
extern "C" int func_004716AE(int a, int b)
{
    return func_00471542(a, b, &D_0047FE60);
}

extern "C" unsigned int func_004710DD(unsigned int newval, unsigned int mask)
{
    return func_004710A8(newval, mask & 0xfff7ffff);
}

