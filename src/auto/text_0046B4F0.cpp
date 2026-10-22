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
