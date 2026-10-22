/* 7 functions from 0x00405800 to 0x00406770, found by Ghidra. */
#include "common.h"

extern "C" void func_00401F80(char *p);
extern "C" void func_00401FA0(char *p, int *a);
extern "C" void func_00406770(void);
extern "C" void func_004061D0(char *p);
extern "C" float func_004065F0(float *a, float *b)
{
    float dz = a[2] - b[2];
    float dx = a[0] - b[0];
    return dx * dx + dz * dz;
}
