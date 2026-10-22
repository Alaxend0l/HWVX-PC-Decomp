/* 7 functions from 0x00467F10 to 0x00468B10, found by Ghidra. */
#include "common.h"

extern "C" void func_004684C0(int *p, int a, int b);
extern "C" void func_00468130(int *p, int a, int b);
extern "C" void func_004686B0(int *p, int a, int b);
extern "C" void func_00467F10(int *p, int a, int b);
extern "C" void func_004688D0(int *p, int a, int b)
{
    if (p[1] & 2) {
        if (p[1] & 8)
            func_004684C0(p, a, b);
        else
            func_00468130(p, a, b);
    } else {
        if (p[1] & 8)
            func_004686B0(p, a, b);
        else
            func_00467F10(p, a, b);
    }
}
