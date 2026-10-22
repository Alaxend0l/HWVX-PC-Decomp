/* 14 functions from 0x004076D0 to 0x00408690, found by Ghidra. */
#include "common.h"

struct Vec4_004076D0 {
    float x;
    float y;
    float z;
    float w;
};

struct Item_004076D0 {
    char unk_0x00[0x14];
    float unk_0x14;
    char unk_0x18[0x20 - 0x18];
};

struct List_004076D0 {
    unsigned int count;
    Item_004076D0 *items;
};

struct Info_004076D0 {
    char unk_0x00[0x2c];
    unsigned int unk_0x2c;
};

struct Obj_004076D0 {
    char unk_0x00[0x14];
    char unk_0x14[0x18 - 0x14];
    Info_004076D0 *unk_0x18;
    char unk_0x1c[0x1e - 0x1c];
    char unk_0x1e;
    char unk_0x1f[0x28 - 0x1f];
    float unk_0x28;
    float unk_0x2c;
};

void func_0044AD00(void *, void *, void *, void *, void *, int);
