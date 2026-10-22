/* 31 functions from 0x00453FB0 to 0x00454E70, found by Ghidra. */
#include "common.h"

extern "C" void *func_0046AED9(unsigned int size);
float func_00453360(float *, float *);
float func_004534B0(float *);
void func_00453330(float *, float *, float *);
void *func_00454B60(void)
{
    return func_0046AED9(0x54);
}

void func_004542D0(float *a, float *b)
{
    float d = func_00453360(a, b);
    b[0] = d * a[0];
    b[1] = d * a[1];
    b[2] = d * a[2];
}

