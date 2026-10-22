/* 17 functions from 0x00469AF0 to 0x0046A71B, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

struct Vec4_00469AF0 {
    float x, y, z, w;
};

struct Group_00469AF0 {
    Vec4_00469AF0 unk_0x0[4];
    unsigned int unk_0x40;
    int unk_0x44[5];
};

struct Light_00469AF0 {
    Vec4_00469AF0 unk_0x0;
    Vec4_00469AF0 unk_0x10;
    unsigned char unk_0x20[4];
};

struct State_00469AF0 {
    char pad_0x0[0x24];
    unsigned int unk_0x24;
    char pad_0x28[0x1abdc0 - 0x28];
    Light_00469AF0 unk_0x1abdc0[1];
};

struct Arrays_00469B80 {
    void *unk_0x0;
    void *unk_0x4;
    void *unk_0x8;
    void *unk_0xc;
};

#define GROUPS_00469AF0(s) ((Group_00469AF0 *)((char *)(s) + 0x1c9450))

extern State_00469AF0 *D_0049D7C8;

extern "C" void func_00460820(int a);
extern "C" void func_00467E20(int a);
extern "C" void func_00467130(int a);
extern "C" void func_00466FD0(int a);
extern "C" void func_00466FF0(void);
extern "C" void func_00469990(int a, int b);
extern "C" void func_00469970(void);
extern "C" void func_00469890(Vec4_00469AF0 *a, int *b, int c);
