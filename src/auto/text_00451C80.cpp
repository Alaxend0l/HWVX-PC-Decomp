/* 6 functions from 0x00451C80 to 0x00452033, found by Ghidra. */
#include "common.h"

extern "C" int D_0049DB90;
extern "C" int D_0049DBA0;
extern "C" int D_0049DBB8;

extern "C" void func_004520B0(void);

extern "C" bool func_00451FC0(int p, unsigned int lo, unsigned int hi)
{
    unsigned int i;
    unsigned int *e = (unsigned int *)(p + 0xfc);
    for (i = 0; i < 12; i++, e += 0x14) {
        if (*e >= lo && *e < hi)
            return true;
    }
    return false;
}

extern "C" bool func_00452000(void)
{
    D_0049DB90 = 0;
    D_0049DBA0 = 0;
    D_0049DBB8 = 1;
    return true;
}

extern "C" void func_00452020(void)
{
    if (D_0049DBA0 != 0)
        func_004520B0();
}

