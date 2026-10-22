/* 12 functions from 0x00448330 to 0x00449110, found by Ghidra. */
#include "common.h"

extern char D_0047A2E8[];
extern char D_0047A830[];
extern char D_0047B088[];
extern char D_0047B040[];
extern char D_0047AED8[];
extern char D_0047A3B0[];
extern "C" void func_0042D770(int a);
extern "C" void func_0044A9C0(char *a, char *b);
extern "C" void func_0044A990(char *a);
extern "C" void func_0044A910(char *a);
extern "C" void func_0043ED30(char *a);
extern "C" char *func_004483A0(char *p);

extern float D_0047700C;
float func_00448B60(void)
{
    return D_0047700C;
}

extern "C" int func_00448B70(char *p)
{
    char *q = *(char **)(p + 0x94);

    if (q != NULL)
        return *(int *)(q + 0x2c);
    return 0;
}

