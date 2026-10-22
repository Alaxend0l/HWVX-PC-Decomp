/* 34 functions from 0x0046C460 to 0x0046D431, found by Ghidra. */
#include "common.h"

extern "C" void func_0046D431(int);
extern "C" void func_0046C460(void)
{
}

extern "C" void func_0046D428(void)
{
    func_0046D431(1);
}

#pragma optimize("s", on)
extern "C" int func_0046D150(char **ap)
{
    return *(int *)((*ap += 4) - 4);
}
extern "C" int func_0046C48C(unsigned int sw)
{
    if (sw & 0x80000)
        return 7;
    return 1;
}

extern "C" unsigned int func_0046C4A5(void)
{
    return 0;
}

extern "C" unsigned int func_0046C4E8(unsigned int lo, unsigned int hi)
{
    if ((hi & 0x7ff00000) != 0x7ff00000)
        return hi & 0x7ff00000;
    return hi;
}

extern "C" void func_0046C4FE(void)
{
}

