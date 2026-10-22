/* 3 functions from 0x0044B9C0 to 0x0044BA60, found by Ghidra. */
#include "common.h"

struct Entry_004B6300 {
    int a;
    int b;
    char pad[0x38];
};

extern "C" char D_004B62E0[];
extern "C" Entry_004B6300 D_004B6300[8];
extern "C" char D_0047B7A0[];
extern "C" void func_00454D10(void *, int);
extern "C" void func_00452F70(const char *);
