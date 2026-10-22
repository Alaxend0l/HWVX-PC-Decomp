/* 22 functions from 0x00409690 to 0x0040A4A2, found by Ghidra. */
#include "common.h"

struct Vec4_00409690 {
    float x, y, z, w;
};

struct Mtx_00409690 {
    float m[16];
};

struct VecSlot_00409690 {
    Vec4_00409690 v;
    char unk_0x10[0x80];
};

struct MtxSlot_00409690 {
    Mtx_00409690 m;
    char unk_0x40[0x50];
};

extern char D_00681500[];
extern int D_0068DAC0;
extern VecSlot_00409690 D_0068DAE0[];
extern VecSlot_00409690 D_0068DAF0[];
extern MtxSlot_00409690 D_0068DB30[];

extern "C" char func_00459B10(int);
extern "C" void func_004096C0(unsigned int);
extern "C" void func_00409A40(void);
extern "C" void func_00409A60(void);
