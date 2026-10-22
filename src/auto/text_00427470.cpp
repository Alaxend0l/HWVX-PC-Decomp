/* 11 functions from 0x00427470 to 0x00428430, found by Ghidra. */
#include "common.h"
#include <string.h>

extern "C" bool D_0048D1A0;
extern "C" int D_0048D1A4;
extern "C" int D_0048D1AC;
extern "C" int D_0048D1B0;
extern "C" int D_0047A934;
extern "C" unsigned int D_0047A908[11];
extern "C" char D_0047A93C[];
extern "C" void *D_0065F460[11];
extern "C" void *D_0065F48C[];
extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);
extern "C" void func_00428A70(int, int);

extern "C" bool func_00427760(void)
{
    return D_0048D1A0;
}

extern "C" int func_00427770(void)
{
    return 11;
}

extern "C" void func_004276B0(void)
{
    unsigned int i;
    unsigned int n;

    D_0048D1AC = 0;
    D_0048D1B0 = 0;
    D_0047A934 = 0;
    for (i = 0; i < 11; i++) {
        if (i != 7 && (n = D_0047A908[i]) > 0) {
            D_0065F460[i] = func_00454B80(n * 168, 0x76, D_0047A93C);
            memset(D_0065F460[i], 0, n * 168);
        } else {
            D_0065F460[i] = 0;
        }
    }
    D_0048D1A4 = 0;
}

extern "C" void func_00427730(void)
{
    int i;

    for (i = 0; i < 11; i++) {
        func_00428A70(i, 1);
        func_00454C50(D_0065F460[i]);
    }
}

