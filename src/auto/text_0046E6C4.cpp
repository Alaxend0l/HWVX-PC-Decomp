/* 22 functions from 0x0046E6C4 to 0x0046F464, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern int D_0049D810;
extern int D_0047D434;
extern void (*D_0049D984)(void);
extern LPCRITICAL_SECTION D_0047D8C4;
extern LPCRITICAL_SECTION D_0047D8B4;
extern LPCRITICAL_SECTION D_0047D8A4;
extern LPCRITICAL_SECTION D_0047D884;

extern "C" void func_0046E7DD(int code);
extern LPCRITICAL_SECTION D_0047D880[];
extern "C" void *func_0046AED9(unsigned int size);
extern "C" void func_0046AD1F(int code);
extern "C" void func_0046B013(void *p);
extern "C" int *func_00470486(void);
extern "C" void func_0046E9BA(int n);
extern "C" double func_0046EED3(double x, int exp);

#pragma optimize("s", on)
extern "C" void func_0046E616(int a, int b);
extern int (*D_0049D9EC)(unsigned int);
#pragma optimize("y", off)
extern "C" void func_0046E9BA(int n)
{
    LeaveCriticalSection(D_0047D880[n]);
}
extern "C" int func_0046F017(void)
{
    short sw;
    sw = 0;
    return sw;
}

extern "C" int func_0046F025(void)
{
    short sw;
    sw = 0;
    return sw;
}

extern double D_004789A8;
#pragma optimize("y", off)
#pragma optimize("p", on)
extern "C" double func_0046EF56(double x, int *pexp)
{
    int exp;
    double man;

    if (x == D_004789A8) {
        man = 0.0;
        exp = 0;
    } else if ((*((unsigned short *)&x + 3) & 0x7ff0) == 0
               && ((*((unsigned int *)&x + 1) & 0xfffff) || *(unsigned int *)&x)) {
        int neg;
        exp = -0x3fd;
        neg = x < D_004789A8;
        while ((*((unsigned short *)&x + 3) & 0x10) == 0) {
            *((unsigned int *)&x + 1) <<= 1;
            if (*(unsigned int *)&x & 0x80000000)
                *((unsigned int *)&x + 1) |= 1;
            *(unsigned int *)&x <<= 1;
            exp--;
        }
        *((unsigned short *)&x + 3) &= 0xffef;
        if (neg)
            *((unsigned short *)&x + 3) |= 0x8000;
        man = func_0046EED3(x, 0);
    } else {
        man = func_0046EED3(x, 0);
        exp = (short)((*((unsigned short *)&x + 3) & 0x7ff0) >> 4) - 0x3fe;
    }
    *pexp = exp;
    return man;
}
#pragma optimize("p", off)
#pragma optimize("y", on)

#pragma optimize("y", on)

extern "C" double func_0046EED3(double x, int exp)
{
    double retval;
    int biased_exp;

    retval = x;
    biased_exp = exp + 0x3fe;
    *((unsigned short *)&retval + 3) = (unsigned short)(*((unsigned short *)&x + 3) & 0x800f | (biased_exp << 4));
    return retval;
}

#pragma optimize("y", on)

extern "C" void func_0046EE99(int code)
{
    switch (code) {
    case 1:
        *func_00470486() = 0x21;
        break;
    case 2:
    case 3:
        *func_00470486() = 0x22;
        break;
    }
}

#pragma optimize("y", off)
extern "C" double func_0046EEC1(double x)
{
    double r;
    r = x;
    return r;
}

#pragma optimize("y", on)

extern "C" void __stdcall func_0046E789(int *p)
{
    func_0046E616(p[6], p[7]);
}

extern "C" void func_0046E7A4(void)
{
    if (D_0049D810 == 1 || (D_0049D810 == 0 && D_0047D434 == 1)) {
        func_0046E7DD(0xfc);
        if (D_0049D984 != NULL)
            (*D_0049D984)();
        func_0046E7DD(0xff);
    }
}
extern "C" void func_0046E930(void)
{
    InitializeCriticalSection(D_0047D8C4);
    InitializeCriticalSection(D_0047D8B4);
    InitializeCriticalSection(D_0047D8A4);
    InitializeCriticalSection(D_0047D884);
}

#pragma optimize("y", off)
extern "C" void func_0046E959(int n)
{
    LPCRITICAL_SECTION *pcs = &D_0047D880[n];
    LPCRITICAL_SECTION cs;

    if (*pcs == NULL) {
        if ((cs = (LPCRITICAL_SECTION)func_0046AED9(sizeof(CRITICAL_SECTION))) == NULL)
            func_0046AD1F(0x11);
        func_0046E959(0x11);
        if (*pcs == NULL) {
            InitializeCriticalSection(cs);
            *pcs = cs;
        } else {
            func_0046B013(cs);
        }
        func_0046E9BA(0x11);
    }
    EnterCriticalSection(*pcs);
}

#pragma optimize("s", on)
#pragma optimize("y", off)
extern "C" int func_0046EEFC(double x)
{
    if (*((unsigned int *)&x + 1) == 0x7ff00000) {
        if (*(unsigned int *)&x == 0)
            return 1;
    } else if (*((unsigned int *)&x + 1) == 0xfff00000 && *(unsigned int *)&x == 0)
        return 2;
    if ((*((unsigned short *)&x + 3) & 0x7ff8) == 0x7ff8)
        return 3;
    if ((*((unsigned short *)&x + 3) & 0x7ff8) == 0x7ff0
        && ((*((unsigned int *)&x + 1) & 0x7ffff) || *(unsigned int *)&x))
        return 4;
    return 0;
}
#pragma optimize("y", on)
