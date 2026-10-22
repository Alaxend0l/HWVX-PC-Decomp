/* 26 functions from 0x0046AD1F to 0x0046B1D8, found by Ghidra. */
#include "common.h"
#include <stdio.h>
#include <stdarg.h>

extern "C" int func_0046C971(FILE *stream, const char *format, va_list argptr);
extern "C" int func_0046D17B(int ch, FILE *stream);
extern "C" int D_0049D810;
extern "C" void (__cdecl *D_0047D430)(int);
extern "C" void func_0046E7A4(void);
extern "C" void func_0046E7DD(int);
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int);
extern "C" __declspec(dllimport) void *__stdcall GetCurrentProcess(void);
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void *, unsigned int);

typedef void (__cdecl *_PVFV)(void);
extern "C" int D_0049D854;
extern "C" int D_0049D850;
extern "C" char D_0049D84C;
extern "C" _PVFV *D_006D6B10;
extern "C" _PVFV *D_006D6B0C;
extern "C" _PVFV D_0047A020[];
extern "C" _PVFV D_0047A028[];
extern "C" _PVFV D_0047A02C[];
extern "C" _PVFV D_0047A030[];
extern "C" _PVFV D_0047D408;
extern "C" _PVFV D_0047A000[];
extern "C" _PVFV D_0047A008[];
extern "C" _PVFV D_0047A00C[];
extern "C" _PVFV D_0047A01C[];
extern "C" void func_0046AEAD(void);
extern "C" void func_0046AEB6(void);
extern "C" void func_0046AEBF(_PVFV *, _PVFV *);
extern "C" void *func_0046AEEB(unsigned int, int);
extern "C" int D_0049D9E8;
extern "C" void *func_0046AF17(unsigned int);
extern "C" int func_0046F0AD(unsigned int);

#pragma optimize("s", on)

extern "C" void func_0046AD1F(int code)
{
    if (D_0049D810 == 1)
        func_0046E7A4();
    func_0046E7DD(code);
    D_0047D430(255);
}

extern "C" void func_0046AEBF(_PVFV *pfbegin, _PVFV *pfend)
{
    while (pfbegin < pfend) {
        if (*pfbegin != NULL)
            (**pfbegin)();
        ++pfbegin;
    }
}

extern "C" void *func_0046AED9(unsigned int size)
{
    return func_0046AEEB(size, D_0049D9E8);
}

extern "C" void func_0046AE08(int code, int quick, int retcaller)
{
    func_0046AEAD();
    if (D_0049D854 == 1)
        TerminateProcess(GetCurrentProcess(), code);

    D_0049D850 = 1;
    D_0049D84C = (char)retcaller;

    if (!quick) {
        if (D_006D6B10) {
            _PVFV *pfend = D_006D6B0C;
            while (--pfend >= D_006D6B10) {
                if (*pfend != NULL)
                    (**pfend)();
            }
        }
        func_0046AEBF(D_0047A020, D_0047A028);
    }
    func_0046AEBF(D_0047A02C, D_0047A030);

    if (retcaller) {
        func_0046AEB6();
        return;
    }
    D_0049D854 = 1;
    ExitProcess(code);
}

extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" void func_0046AEAD(void)
{
    func_0046E959(13);
}

extern "C" void func_0046AEB6(void)
{
    func_0046E9BA(13);
}

extern "C" void *func_0046AEEB(unsigned int size, int nhFlag)
{
    void *pvReturn;

    if (size > 0xffffffe0)
        return NULL;

    for (;;) {
        pvReturn = func_0046AF17(size);
        if (pvReturn || nhFlag == 0)
            return pvReturn;
        if (!func_0046F0AD(size))
            return NULL;
    }
}

extern "C" int D_006D59C8;
extern "C" unsigned int D_006D59C0;
extern "C" unsigned int D_0047FA7C;
extern "C" void *D_006D59C4;
extern "C" void *func_0046F464(unsigned int);
extern "C" void *func_0046FF07(unsigned int);
extern "C" __declspec(dllimport) void *__stdcall HeapAlloc(void *, unsigned long, unsigned long);
extern "C" void *func_0046AF17(unsigned int size)
{
    void *pvReturn;

    if (D_006D59C8 == 3) {
        if (size <= D_006D59C0) {
            func_0046E959(9);
            __try {
                pvReturn = func_0046F464(size);
            }
            __finally {
                func_0046E9BA(9);
            }
            if (pvReturn)
                return pvReturn;
        }
    } else if (D_006D59C8 == 2) {
        size = size ? (size + 15) & ~15 : 16;
        if (size <= D_0047FA7C) {
            func_0046E959(9);
            __try {
                pvReturn = func_0046FF07(size >> 4);
            }
            __finally {
                func_0046E9BA(9);
            }
            if (pvReturn)
                return pvReturn;
        }
        return HeapAlloc(D_006D59C4, 0, size);
    }
    if (size == 0)
        size = 1;
    size = (size + 15) & ~15;
    return HeapAlloc(D_006D59C4, 0, size);
}

extern "C" void func_0046AFE6(void)
{
}

extern "C" void *func_0046F110(void *);
extern "C" void func_0046F13B(void *, void *);
extern "C" void *func_0046FE6B(void *, void **, void **);
extern "C" void func_0046FEC2(void *, void *, void *);
extern "C" __declspec(dllimport) int __stdcall HeapFree(void *, unsigned long, void *);
extern "C" void func_0046B013(void *pBlock)
{
    if (pBlock == NULL)
        return;

    if (D_006D59C8 == 3) {
        void *pHeader;

        func_0046E959(9);
        __try {
            if ((pHeader = func_0046F110(pBlock)) != NULL)
                func_0046F13B(pHeader, pBlock);
        }
        __finally {
            func_0046E9BA(9);
        }
        if (pHeader != NULL)
            return;
    } else if (D_006D59C8 == 2) {
        void *pRegion;
        void *pPage;
        void *pHeader;

        func_0046E959(9);
        __try {
            if ((pHeader = func_0046FE6B(pBlock, &pRegion, &pPage)) != NULL)
                func_0046FEC2(pRegion, pPage, pHeader);
        }
        __finally {
            func_0046E9BA(9);
        }
        if (pHeader != NULL)
            return;
    }
    HeapFree(D_006D59C4, 0, pBlock);
}

extern "C" void *func_0046AEEB(unsigned int, int);
extern "C" int D_0049D9E8;
extern "C" void func_0046AF7E(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0046AF87(void)
{
}

extern "C" void *func_0046AF17(unsigned int);
extern "C" int func_0046F0AD(unsigned int);
extern "C" void func_0046AFDD(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0046B07D(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0046B0D5(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0046AD41(void)
{
}

extern "C" void func_0046AEAB(void)
{
}

extern "C" void func_0046AD44(int code)
{
    if (D_0049D810 == 1)
        func_0046E7A4();
    func_0046E7DD(code);
    ExitProcess(255);
}

extern "C" void func_0046AD67(void)
{
}

#pragma optimize("y", off)
extern "C" int func_0046AD68(char *string, const char *format, va_list ap)
{
    FILE str;
    FILE *outfile = &str;
    int retval;

    outfile->_flag = _IOWRT | _IOSTRG;
    outfile->_ptr = outfile->_base = string;
    outfile->_cnt = 0x7fffffff;
    retval = func_0046C971(outfile, format, ap);
    if (--outfile->_cnt >= 0)
        *outfile->_ptr = '\0';
    else
        func_0046D17B('\0', outfile);
    return retval;
}
#pragma optimize("y", on)

extern "C" void func_0046ADB9(void)
{
    if (D_0047D408)
        (*D_0047D408)();
    func_0046AEBF(D_0047A00C, D_0047A01C);
    func_0046AEBF(D_0047A000, D_0047A008);
}

extern "C" void func_0046AE08(int code, int quick, int retcaller);
extern "C" void func_0046ADE6(int code)
{
    func_0046AE08(code, 0, 0);
}

extern "C" void func_0046ADF7(int code)
{
    func_0046AE08(code, 1, 0);
}

#pragma optimize("y", on)

