/* 10 functions from 0x0046B4F0 to 0x0046B96F, found by Ghidra. */
#include "common.h"
#include <stdio.h>

typedef void (__cdecl *_PVFV)(void);
typedef int (__cdecl *_onexit_t)(void);
extern "C" _PVFV *D_006D6B10;
extern "C" _PVFV *D_006D6B0C;
extern "C" void func_0046AEAD(void);
extern "C" void func_0046AEB6(void);
extern "C" size_t func_004707C7(void *);
extern "C" void *func_00470498(void *, size_t);
extern "C" void *func_0046AED9(size_t);
extern "C" void func_0046AD1F(int);
extern "C" void func_0046C816(FILE *stream);
extern "C" void func_0046C868(FILE *stream);
extern "C" int func_0046B60F(FILE *stream, long offset, int whence);

#pragma optimize("s", on)

extern "C" _onexit_t func_0046B524(_onexit_t func)
{
    _PVFV *p;

    func_0046AEAD();
    if (func_004707C7(D_006D6B10) < (unsigned)((char *)D_006D6B0C - (char *)D_006D6B10 + sizeof(_PVFV))) {
        if ((p = (_PVFV *)func_00470498(D_006D6B10, func_004707C7(D_006D6B10) + 4 * sizeof(_PVFV))) == NULL) {
            func = NULL;
            goto done;
        }
        D_006D6B0C = p + (D_006D6B0C - D_006D6B10);
        D_006D6B10 = p;
    }
    *(D_006D6B0C++) = (_PVFV)func;
done:
    func_0046AEB6();
    return func;
}

extern "C" int func_0046B5E3(FILE *stream, long offset, int whence)
{
    int retval;

    func_0046C816(stream);
    retval = func_0046B60F(stream, offset, whence);
    func_0046C868(stream);
    return retval;
}
#pragma optimize("y", on)

