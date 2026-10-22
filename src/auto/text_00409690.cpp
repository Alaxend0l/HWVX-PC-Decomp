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

struct Entry_0048955C {
    char unk_0x00[0x24];
    int unk_0x24;
    char unk_0x28[0x2c - 0x28];
    int unk_0x2c;
    int unk_0x30;
    char unk_0x34[0x48 - 0x34];
    char unk_0x48;
    char unk_0x49;
    char unk_0x4a[2];
};

struct Node_0040A170 {
    char unk_0x00[0x10];
    unsigned char flags;
    char unk_0x11;
    unsigned short skip;
    char unk_0x14[0xc];
};

extern int D_0068DAC4;
extern Entry_0048955C *D_0048955C;
extern char D_00489554;
extern float D_00489530;
extern double D_00477140;
extern void (*D_00692994)(int);

extern char D_00489560;

extern "C" void func_00459A70(int, int, int);
extern "C" void func_00459AC0(int, int);
extern "C" void func_00459A30(int, int);
extern "C" void func_00459700(int);
extern "C" void func_00459D40(int);
extern "C" char func_00459B10(int);
extern "C" void func_004096C0(unsigned int);
extern "C" void func_00409A40(void);
extern "C" void func_00409A60(void);
extern "C" void func_00459950(int);
extern "C" int func_00459880(int, int);
extern "C" void func_00459980(int, int);

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
    switch (type) {
    case 5:
        D_0068DAE0[index].v = *(Vec4_00409690 *)data;
        break;
    case 6:
        D_0068DAF0[index].v = *(Vec4_00409690 *)data;
        break;
    case 7:
        D_0068DB30[index].m = *(Mtx_00409690 *)data;
        break;
    }
}

extern "C" void func_00409DA0(int n)
{
    if (n)
        D_0068DAC4 = n - 1;
}

extern "C" void func_00409DB0(int index)
{
    D_0048955C[index].unk_0x49 = 1;
}

extern "C" void func_00409DD0(int index)
{
    if (D_0048955C[index].unk_0x2c > 0)
        func_00459950(D_0048955C[index].unk_0x2c);
    D_0048955C[index].unk_0x2c = -1;
    D_0048955C[index].unk_0x24 = 0;
    D_0048955C[index].unk_0x30 = 0;
}

extern "C" int func_00409E20(int index)
{
    return D_0048955C[index].unk_0x2c != -1 ? 1 : 0;
}

extern "C" char func_00409E40(int index)
{
    return (char)D_0048955C[index].unk_0x30;
}

extern "C" int func_00409E60(int a)
{
    int h = 0;
    if (a) {
        h = func_00459880(a, 5);
        if (h) {
            func_00459980(h, 1);
            return h;
        }
    }
    return 0;
}

extern "C" void func_00459DA0(int, int);
extern "C" void func_00459A70(int, int, int);
extern "C" void func_00459AC0(int, int);
extern "C" void func_00459A30(int, int);
extern "C" void func_00459700(int);
extern char D_00489560;
extern "C" float func_00454800(Node_0040A170 *, int);
extern float D_00477000;
extern "C" void func_00409F30(int a, int b)
{
    func_00459DA0(a, b);
    D_00489554 = 1;
}

extern "C" void func_00409F50(void)
{
    if (D_00489554) {
        D_00692994(1);
        func_00459D40((int)(D_00489530 * D_00477140));
    }
}

extern "C" char func_0040A170(Node_0040A170 *p, int b)
{
    for (;;) {
        if (func_00454800(p, b) > D_00477000) {
            if (!(p->flags & 1))
                return 0;
            p++;
        } else {
            if (!(p->flags & 2))
                return 1;
            p += p->skip;
        }
    }
}

extern "C" char *func_0040A490(void)
{
    return D_00681500;
}
