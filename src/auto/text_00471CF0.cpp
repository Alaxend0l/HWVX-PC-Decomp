/* 8 functions from 0x00471CF0 to 0x00472018, found by Ghidra. */
#include "common.h"
#include <windows.h>

typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[0x24 - 6];
} ioinfo;

typedef struct {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    char pad[0x20 - 0x10];
    CRITICAL_SECTION lock;
} CRTFILE;

extern "C" unsigned int D_006D5AE0;
extern "C" ioinfo *D_006D59E0[];
extern "C" int D_006D6B00;
extern "C" CRTFILE **D_006D5AE4;
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" int func_0046A8F1(CRTFILE *);
extern "C" void func_0046B013(void *);
extern "C" void func_0046AD1F(int);

#pragma optimize("s", on)
extern "C" void func_00471D6B(void)
{
    func_0046AD1F(2);
}
