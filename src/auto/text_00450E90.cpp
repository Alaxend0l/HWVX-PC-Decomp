/* 7 functions from 0x00450E90 to 0x00451C80, found by Ghidra. */
#include "common.h"
struct Slot_00450E90 {
    int unk_0x00;
    char pad_0x04[0x3c];
    short unk_0x40;
    short unk_0x42;
    int unk_0x44;
    int unk_0x48;
    int unk_0x4c;
};

struct Obj_00450E90 {
    char pad_0x00[0x40];
    int unk_0x40[4];
    char pad_0x50[0x60];
    Slot_00450E90 slots[12];
    unsigned char unk_0x470;
    char pad_0x471;
    unsigned char unk_0x472;
    char pad_0x473[5];
    int unk_0x478;
    float unk_0x47c;
};

extern "C" void func_004482C0(Obj_00450E90 *p, int a);
extern "C" void func_00448330(Obj_00450E90 *p);
extern "C" void func_00407310(Slot_00450E90 *p);
extern "C" void func_00451C20(Obj_00450E90 *p, unsigned char idx);
