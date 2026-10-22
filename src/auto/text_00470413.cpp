/* 17 functions from 0x00470413 to 0x00470CA7, found by Ghidra. */
#include "common.h"

extern "C" char *func_0046C653(void);
extern "C" void func_0046E9BA(int);
extern "C" unsigned long D_0047FC98[];
extern "C" int D_0047FC9C[];
extern "C" unsigned long D_0047FE00[];
extern "C" int *func_00470486(void);
extern "C" unsigned long *func_0047048F(void);
extern "C" void func_00470413(unsigned long oserr)
{
    unsigned long *p;
    int i = 0;
    *func_0047048F() = oserr;
    p = D_0047FC98;
    do {
        if (oserr == *p) {
            *func_00470486() = D_0047FC9C[i * 2];
            return;
        }
        p += 2;
        i++;
    } while (p < D_0047FE00);
    if (oserr >= 0x13 && oserr <= 0x24)
        *func_00470486() = 0xd;
    else if (oserr >= 0xbc && oserr <= 0xca)
        *func_00470486() = 8;
    else
        *func_00470486() = 0x16;
}

extern "C" unsigned long *func_0047048F(void)
{
    return (unsigned long *)(func_0046C653() + 0xc);
}

extern "C" int *func_00470486(void)
{
    return (int *)(func_0046C653() + 8);
}

extern "C" void func_0047062C(void)
{
}

extern "C" void func_00470623(void)
{
    func_0046E9BA(9);
}

