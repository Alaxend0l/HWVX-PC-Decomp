/* 22 functions from 0x00471050 to 0x004718BD, found by Ghidra. */
#include "common.h"
#include <string.h>

extern "C" unsigned int func_004710A8(unsigned int, unsigned int);
#pragma optimize("s", on)
extern "C" unsigned int func_004710F3(unsigned short cw)
{
    unsigned int abstr = 0;

    if (cw & 0x1)
        abstr |= 0x10;
    if (cw & 0x4)
        abstr |= 0x8;
    if (cw & 0x8)
        abstr |= 0x4;
    if (cw & 0x10)
        abstr |= 0x2;
    if (cw & 0x20)
        abstr |= 0x1;
    if (cw & 0x2)
        abstr |= 0x80000;

    switch (cw & 0xc00) {
    case 0x000:
        abstr |= 0x000;
        break;
    case 0x400:
        abstr |= 0x100;
        break;
    case 0x800:
        abstr |= 0x200;
        break;
    case 0xc00:
        abstr |= 0x300;
        break;
    }

    switch (cw & 0x300) {
    case 0x000:
        abstr |= 0x20000;
        break;
    case 0x200:
        abstr |= 0x10000;
        break;
    case 0x300:
        abstr |= 0x00000;
        break;
    }

    if (cw & 0x1000)
        abstr |= 0x40000;

    return abstr;
}

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

