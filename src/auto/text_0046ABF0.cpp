/* 3 functions from 0x0046ABF0 to 0x0046AD1C, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <excpt.h>

extern "C" unsigned int D_0049D818;
extern "C" unsigned int D_0049D81C;
extern "C" unsigned int D_0049D820;
extern "C" unsigned int D_0049D824;
extern "C" char *D_006D6B14;
extern "C" char *D_0049D808;
extern "C" int func_0046E576(int);
extern "C" void func_0046AD44(int);
extern "C" int func_0046C5EC(void);
extern "C" void func_0046E245(void);
extern "C" char *func_0046E113(void);
extern "C" void func_0046DEC6(void);
extern "C" void func_0046DE0D(void);
extern "C" void func_0046ADB9(void);
extern "C" char *func_0046DDB5(void);
extern "C" void func_0046ADE6(int);
extern "C" int func_0046DC3D(unsigned long, struct _EXCEPTION_POINTERS *);
extern "C" void func_0046AD24(int);
int __stdcall func_00454E70(HINSTANCE, HINSTANCE, char *, int);

extern "C" char *func_0046ABF0(const char *s, int ch)
{
    const char *start = s;
    while (*s++)
        ;
    while (--s != start && *s != (char)ch)
        ;
    if (*s == (char)ch)
        return (char *)s;
    return 0;
}
