/* 16 functions from 0x004453E0 to 0x004460B0, found by Ghidra. */
#include "common.h"

extern float D_0053B158;
extern float D_0053B1E0;
extern float D_0053B1F8;
extern float D_0053B160;
extern float D_0053B1F4;
extern float D_0053B1FC;
extern char D_0047B3D0[];
float func_00445D30(void);
float func_00445D40(void);
void func_00445D80(void);
void func_004403D0(void *a, int b, void (*c)(void), int d, int e);
void func_00440470(void *a);
void func_00445C60(void)
{
    D_0053B158 = 0.0f;
    D_0053B1E0 = 0.0f;
    D_0053B1F8 = 0.0f;
    D_0053B160 = 0.0f;
    func_004403D0(D_0047B3D0, 0, func_00445D80, 0, 1);
}

float func_00445D30(void)
{
    return D_0053B158;
}

void func_00445CB0(void)
{
    func_00440470(D_0047B3D0);
}

float func_00445D40(void)
{
    return D_0053B1E0;
}

void func_00445C40(char *obj)
{
    *(float *)(obj + 0x24) = func_00445D30();
    *(float *)(obj + 0x28) = func_00445D40();
}
