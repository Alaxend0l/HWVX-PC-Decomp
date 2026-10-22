/* 22 functions from 0x00471050 to 0x004718BD, found by Ghidra. */
#include "common.h"
#include <string.h>

extern "C" unsigned int func_004710A8(unsigned int, unsigned int);
#pragma optimize("s", on)
extern "C" void func_0047148E(void *p)
{
    memset(p, 0, 12);
}
extern "C" unsigned int func_004710DD(unsigned int newval, unsigned int mask)
{
    return func_004710A8(newval, mask & 0xfff7ffff);
}

