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
extern "C" void func_00448330(char *p)
{
    char *q;

    *(unsigned int *)(p + 0x74) |= 0x200202;
    if (*(int *)(p + 0x84) != 0)
        func_0042D770(*(int *)(p + 0x84));
    *(int *)(p + 0x84) = 0;
    func_0044A9C0(p + 0x10, p + 0x88);
    func_0044A990(p + 0x88);
    func_0044A910(p + 0x88);
    q = *(char **)(p + 0x94);
    if (q != NULL && *(char **)(q + 0x2c) == p)
        func_0043ED30(q);
}

extern "C" char *func_004483A0(char *p)
{
    char *t = *(char **)(p + 0x8c);

    if (t == D_0047A2E8)
        return *(char **)(*(char **)(p + 0x398) + 0xa0);
    if (t == D_0047A830 || t == D_0047B088 || t == D_0047B040)
        return *(char **)(*(char **)(p + 0xc0) + 0x10);
    if (t == D_0047AED8)
        return 0;
    if (t == D_0047A3B0)
        return *(char **)(*(char **)(p + 0xc0) + 0x10);
    return 0;
}

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

