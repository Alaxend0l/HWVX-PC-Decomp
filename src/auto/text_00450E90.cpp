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

extern "C" char func_004512B0(Obj_00450E90 *p, int *src)
{
    int i;
    Slot_00450E90 *s;
    func_004482C0(p, 0);
    p->unk_0x40[0] = src[0];
    p->unk_0x40[1] = src[1];
    p->unk_0x40[2] = src[2];
    p->unk_0x40[3] = src[3];
    p->unk_0x470 = 0;
    p->unk_0x472 = 0;
    s = p->slots;
    for (i = 12; i != 0; i--, s++) {
        s->unk_0x40 = 0;
        s->unk_0x00 = 0;
        s->unk_0x42 = 0;
        s->unk_0x48 = 0;
        s->unk_0x4c = 0;
    }
    p->unk_0x478 = 0;
    p->unk_0x47c = -1.0f;
    return 0;
}

extern "C" void func_00451330(Obj_00450E90 *p)
{
    int i;
    for (i = 0; i < 12; i++)
        func_00407310(&p->slots[i]);
    func_00448330(p);
}

extern "C" void func_00451C00(Obj_00450E90 *p)
{
    unsigned int i;
    if (p != 0) {
        for (i = 0; i < 12; i++)
            func_00451C20(p, i);
    }
}
