/* 8 functions from 0x0046B1E0 to 0x0046B43F, found by Ghidra. */
#include "common.h"
#include <windows.h>

struct _tiddata {
    unsigned long _tid;
    unsigned long _thandle;
    char unk_08[0x40];
    void* _initaddr;
    void* _initarg;
    char unk_50[0x24];
};

extern "C" DWORD D_0047D4A0;
extern "C" void (*D_0047D40C)(void);
extern "C" void (*D_0047D410)(void);
extern "C" void* func_0046BC4D(unsigned num, unsigned size);
extern "C" void func_0046C640(_tiddata* ptd);
extern "C" void func_0046B013(void* p);
extern "C" void func_00470413(unsigned long err);
extern "C" void func_0046AD1F(int code);
extern "C" void func_0046ADF7(int code);
extern "C" int func_0046DC3D(unsigned long code, struct _EXCEPTION_POINTERS* ep);
extern "C" _tiddata* func_0046C653(void);
extern "C" void func_0046C6BA(_tiddata* ptd);
extern "C" void func_0046B400(void);
extern "C" unsigned long WINAPI func_0046B36D(void* ptd);

extern "C" int D_0047FC8C;
extern "C" unsigned short* D_0047FA80;
extern "C" int func_0047039E(int c, int mask);
extern "C" long func_0046B260(const char* nptr);

#pragma optimize("s", on)
extern "C" char* func_0046B1E0(const char* str1, const char* str2)
{
    char* cp = (char*)str1;
    char *s1, *s2;
    if (!*str2)
        return (char*)str1;
    while (*cp) {
        s1 = cp;
        s2 = (char*)str2;
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
        if (!*s2)
            return cp;
        cp++;
    }
    return 0;
}

extern "C" long func_0046B260(const char* nptr)
{
    int c;
    int sign;
    long total;

    while ((D_0047FC8C > 1 ? func_0047039E((unsigned char)*nptr, 8) : D_0047FA80[(unsigned char)*nptr] & 8))
        ++nptr;

    c = (int)(unsigned char)*nptr++;
    sign = c;
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++;

    total = 0;

    while ((D_0047FC8C > 1 ? func_0047039E(c, 4) : D_0047FA80[c] & 4)) {
        total = 10 * total + (c - '0');
        c = (int)(unsigned char)*nptr++;
    }

    if (sign == '-')
        return -total;
    else
        return total;
}
extern "C" int func_0046B2EB(const char* nptr)
{
    return (int)func_0046B260(nptr);
}

extern "C" void func_0046B43D(void)
{
}

