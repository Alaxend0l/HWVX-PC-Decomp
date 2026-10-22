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
extern "C" void func_0046AEAD(void);
extern "C" void func_0046AEB6(void);
extern "C" void func_0046AEBF(_PVFV *, _PVFV *);

#pragma optimize("s", on)

extern "C" void func_0046AD1F(int code)
{
    if (D_0049D810 == 1)
        func_0046E7A4();
    func_0046E7DD(code);
    D_0047D430(255);
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

