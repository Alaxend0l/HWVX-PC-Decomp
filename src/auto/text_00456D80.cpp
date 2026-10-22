/* 14 functions from 0x00456D80 to 0x00457C70, found by Ghidra. */
#include "common.h"
extern "C" unsigned char D_00496FCD;
extern "C" unsigned int D_0047C264;
extern "C" unsigned char D_0047C2F0[];
extern "C" unsigned char D_0047C300[];

extern "C" unsigned char func_00456FB0(unsigned char i)
{
    if (i < 0x10)
        return D_0047C300[i];
    return 0;
}

extern "C" unsigned char func_00456F80(void)
{
    return D_00496FCD;
}

extern "C" unsigned char func_00456F90(void)
{
    unsigned int i = D_0047C264 & 0xff;

    if (i < 0x10)
        return D_0047C2F0[i];
    return (unsigned char)i;
}

