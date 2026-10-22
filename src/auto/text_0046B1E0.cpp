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

#pragma optimize("s", on)
extern "C" unsigned long func_0046B2F6(void (*initialcode)(void*), unsigned stacksize, void* argument)
{
    _tiddata* ptd;
    unsigned long thdl;
    unsigned long errcode = 0L;

    if ((ptd = (_tiddata*)func_0046BC4D(1, sizeof(_tiddata))) == NULL)
        goto error_return;

    func_0046C640(ptd);

    ptd->_initaddr = (void*)initialcode;
    ptd->_initarg = argument;

    if ((ptd->_thandle = thdl = (unsigned long)CreateThread(NULL, stacksize, func_0046B36D, (LPVOID)ptd, CREATE_SUSPENDED, (LPDWORD)&(ptd->_tid))) == 0L) {
        errcode = GetLastError();
        goto error_return;
    }

    if (ResumeThread((HANDLE)thdl) == (DWORD)(-1L)) {
        errcode = GetLastError();
        goto error_return;
    }

    return thdl;

error_return:
    func_0046B013(ptd);
    if (errcode != 0L)
        func_00470413(errcode);
    return (unsigned long)-1L;
}

extern "C" void func_0046B43D(void)
{
}

