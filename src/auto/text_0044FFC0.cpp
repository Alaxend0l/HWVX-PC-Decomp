/* 38 functions from 0x0044FFC0 to 0x00450E90, found by Ghidra. */
#include "common.h"
struct Obj_0044FFC0 {
    char pad0[0x74];
    unsigned char flags_74;
};

struct Item_0044FFC0 {
    char pad0[0x28];
    Obj_0044FFC0 *obj_28;
    char pad2C[0x4];
    int type_30;
};

struct List_0044FFC0 {
    unsigned int count;
    Item_0044FFC0 *items[1];
};

struct Entry_004505A0 {
    char pad0[0xc];
    int unk_c;
    int unk_10;
    char *unk_14;
    char pad18[0x4];
    unsigned int unk_1c;
    char pad20[0x4];
    int state_24;
    char unk_28;
};

extern "C" char func_0044F4D0(char a, int b, int c);
extern "C" int func_00401140(void *p);

extern "C" char D_00496DC8;
extern "C" unsigned int D_0047B978;
extern "C" Entry_004505A0 **D_00496DAC;
