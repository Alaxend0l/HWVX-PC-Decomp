/* 20 functions from 0x00437D70 to 0x00438BD0, found by Ghidra. */
#include "common.h"

struct Point_00437D70 {
    char type;
    char pad_0x1[3];
    int value;
    int unk_0x8;
};

struct Info_00437D70 {
    char pad_0x0[0xa];
    unsigned short unk_0x0a;
    char pad_0xc[0x64 - 0xc];
    unsigned int numPoints;
    Point_00437D70 *points;
};

struct Car_00437D70 {
    char pad_0x0[0x23b];
    char unk_0x23b;
    char pad_0x23c;
    char unk_0x23d;
    char pad_0x23e[0x254 - 0x23e];
    Info_00437D70 *unk_0x254;
    char pad_0x258[0x268 - 0x258];
    int unk_0x268;
    char pad_0x26c[0x2f8 - 0x26c];
};

struct Sub2_00437D70 {
    char pad_0x0[6];
    short unk_0x6;
};

struct Sub1_00437D70 {
    char pad_0x0[8];
    Sub2_00437D70 *unk_0x8;
};

struct Race_00437D70 {
    unsigned int numCars;
    int unk_0x4;
    char pad_0x8[0x18 - 0x8];
    float unk_0x18;
    Sub1_00437D70 *unk_0x1c;
    char pad_0x20[0x80 - 0x20];
    Car_00437D70 *cars;
    char pad_0x84[0x134 - 0x84];
};

struct Thing_00437D70 {
    char pad_0x0[0x24];
    int unk_0x24;
};

struct Obj_00437D70 {
    char pad_0x0[0x8c];
    void *unk_0x8c;
    Thing_00437D70 *unk_0x90;
};

extern Race_00437D70 D_005E7660[18];
extern char D_0047AED8[];

void func_0042F090(Race_00437D70 *, int);
void func_0042FA50(Race_00437D70 *, int);
void func_0042F380(Race_00437D70 *, Car_00437D70 *, int, int);
void func_00448330(Obj_00437D70 *);
