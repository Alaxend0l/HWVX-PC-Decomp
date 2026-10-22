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

extern "C" int func_0046C48C(unsigned int sw)
{
    if (sw & 0x80000)
        return 7;
    return 1;
}

