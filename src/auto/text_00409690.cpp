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

struct Entry_0068DAE0 {
    Vec4_00409690 unk_0x00;
    Vec4_00409690 unk_0x10;
    char unk_0x20[0x30];
    Mtx_00409690 unk_0x50;
};

extern "C" char func_00459B10(int);
extern "C" void func_004096C0(unsigned int);
extern "C" void func_00409A40(void);
extern "C" void func_00409A60(void);

extern "C" void func_00409690(void)
{
    if (func_00459B10(1)) {
        func_00409A40();
        func_00409A60();
        func_00459B10(0);
    }
}

extern "C" void func_00409A40(void)
{
    unsigned int i;

    D_0068DAC0 = 0;
    for (i = 0; i < 100; i++)
        func_004096C0(i);
}

extern "C" void func_00409D10(int index, int type, void *data)
{
    Vec4_00409690 *v;
    Mtx_00409690 *m;

    switch (type) {
    case 5:
        v = &D_0068DAE0[index].v;
        *v = *(Vec4_00409690 *)data;
        break;
    case 6:
        v = &D_0068DAF0[index].v;
        *v = *(Vec4_00409690 *)data;
        break;
    case 7:
        m = &D_0068DB30[index].m;
        *m = *(Mtx_00409690 *)data;
        break;
    }
}

extern "C" char *func_0040A490(void)
{
    return D_00681500;
}
