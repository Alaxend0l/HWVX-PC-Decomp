/* 21 functions from 0x0045E910 to 0x0045F8E0, found by Ghidra. */
#include "common.h"

extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);
extern "C" void func_00469C20(void);

struct Vec4_0045E910 {
    float x, y, z, w;
};

struct Elem_0045E910 {
    float unk_0x0;
    char pad_0x4[0x1c];
    float unk_0x20;
    char pad_0x24[0x1c];
    float unk_0x40;
    char pad_0x44[0x20];
};

struct Light_0045E910 {
    Vec4_0045E910 unk_0x0;
    Vec4_0045E910 unk_0x10;
    int unk_0x20;
};

struct Item_0045E910 {
    char unk_0x0[0x2c];
};

struct State_0045E910 {
    char pad_0x0[0x24];
    int unk_0x24;
    char pad_0x28[0xc];
    unsigned int unk_0x34;
    char pad_0x38[0x38ccc - 0x38];
    Elem_0045E910 unk_0x38ccc[12000];
    char pad_0x15dc4c[0x1abdc0 - 0x15dc4c];
    Light_0045E910 unk_0x1abdc0[2588];
    char pad_0x1c29b0[0x20];
    Item_0045E910 unk_0x1c29d0[256];
};

extern State_0045E910 *D_0049D7C8;
extern void *D_0049D7C4;
extern char D_0047CC44[];
