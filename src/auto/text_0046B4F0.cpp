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
extern "C" long func_0046B6BE(FILE *stream);
extern "C" int func_0046D3CC(FILE *stream);
extern "C" long func_004708B5(int fh, long pos, int mthd);
extern "C" int *func_00470486(void);
extern "C" void func_00470413(unsigned long oserr);
extern "C" size_t func_0046B878(const void *buffer, size_t size, size_t count, FILE *stream);
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char *);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(void);

#pragma optimize("s", on)

extern "C" _onexit_t func_0046B524(_onexit_t func)
{
    _onexit_t retval;
    _PVFV *p;

    func_0046AEAD();
    if (func_004707C7(D_006D6B10) < (unsigned)((char *)D_006D6B0C - (char *)D_006D6B10 + sizeof(_PVFV))) {
        if ((p = (_PVFV *)func_00470498(D_006D6B10, func_004707C7(D_006D6B10) + 4 * sizeof(_PVFV))) == NULL) {
            retval = NULL;
            goto done;
        }
        D_006D6B0C = p + (D_006D6B0C - D_006D6B10);
        D_006D6B10 = p;
    }
    *(D_006D6B0C++) = (_PVFV)func;
    retval = func;
done:
    func_0046AEB6();
    return retval;
}

extern "C" int func_0046B5A2(_PVFV func)
{
    return (func_0046B524((_onexit_t)func) == NULL) ? -1 : 0;
}

extern "C" void func_0046B5B4(void)
{
    if ((D_006D6B10 = (_PVFV *)func_0046AED9(32 * sizeof(_PVFV))) == NULL)
        func_0046AD1F(0x18);
    *(D_006D6B10) = (_PVFV)NULL;
    D_006D6B0C = D_006D6B10;
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

