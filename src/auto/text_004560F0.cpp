/* 18 functions from 0x004560F0 to 0x00456D7A, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern "C" LARGE_INTEGER D_0068DDB0;
extern "C" LARGE_INTEGER D_0068DDB8;
extern "C" unsigned int D_00692370;
extern "C" float D_00692378;
extern "C" float D_00692360;
extern "C" int D_0069237C;
extern "C" float D_00692368;

void func_004564B0(void)
{
    QueryPerformanceFrequency(&D_0068DDB8);
    QueryPerformanceCounter(&D_0068DDB0);
    D_00692370 = 1;
}

int func_00456C80(void)
{
    return 3;
}
