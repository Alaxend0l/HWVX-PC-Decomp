/* 9 functions from 0x0040CE70 to 0x0040DCD0, found by Ghidra. */
#include "common.h"

struct Vec4_0040CE70 {
    float x, y, z, w;
};

struct Item_0040CE70 {
    char unk_0x00[0x14];
    float unk_0x14;
    char unk_0x18[0x8];
};

struct ItemList_0040CE70 {
    unsigned count;
    Item_0040CE70 *items;
};

extern float D_00692350[4];

extern "C" void func_00453750(void *, void *, void *);
extern "C" void func_004536E0(void *, void *, void *);
extern "C" void func_00407280(void *, int);
extern "C" void func_0044AD00(void *, void *, void *, void *, void *, int);
