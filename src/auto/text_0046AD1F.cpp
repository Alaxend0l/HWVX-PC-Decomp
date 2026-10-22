/* 26 functions from 0x0046AD1F to 0x0046B1D8, found by Ghidra. */
#include "common.h"
extern "C" int D_0049D810;
extern "C" void (__cdecl *D_0047D430)(int);
extern "C" void func_0046E7A4(void);
extern "C" void func_0046E7DD(int);
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int);

#pragma optimize("s", on)

extern "C" void func_0046AD1F(int code)
{
    if (D_0049D810 == 1)
        func_0046E7A4();
    func_0046E7DD(code);
    D_0047D430(255);
}

extern "C" void func_0046AD44(int code)
{
    if (D_0049D810 == 1)
        func_0046E7A4();
    func_0046E7DD(code);
    ExitProcess(255);
}

