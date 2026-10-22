/* 21 functions from 0x0045E910 to 0x0045F8E0, found by Ghidra. */
#include "common.h"

extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);
extern "C" void func_00469C20(void);

struct Vec4_0045E910 {
    float x, y, z, w;

    Vec4_0045E910 &operator=(const Vec4_0045E910 &o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
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

int func_0045E910(void)
{
    unsigned int i;

    D_0049D7C8 = (State_0045E910 *)func_00454B80(0x34f384, 0x37, D_0047CC44);
    if (D_0049D7C8 == NULL)
        return 0;
    for (i = 0; i < sizeof(D_0049D7C8->unk_0x38ccc); i += sizeof(Elem_0045E910)) {
        ((Elem_0045E910 *)((char *)D_0049D7C8->unk_0x38ccc + i))->unk_0x0 = 1.0f;
        ((Elem_0045E910 *)((char *)D_0049D7C8->unk_0x38ccc + i))->unk_0x20 = 1.0f;
        ((Elem_0045E910 *)((char *)D_0049D7C8->unk_0x38ccc + i))->unk_0x40 = 1.0f;
    }
    return 1;
}

void func_0045E970(void)
{
    func_00454C50(D_0049D7C8);
    func_00454C50(D_0049D7C4);
}

void func_0045EAD0(Vec4_0045E910 *a, Vec4_0045E910 *b, int *c)
{
    Light_0045E910 *l;

    l = &D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24];
    l->unk_0x0 = *a;
    l = &D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24];
    l->unk_0x10 = *b;
    D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24].unk_0x20 = *c;
    D_0049D7C8->unk_0x24++;
    func_00469C20();
    D_0049D7C8->unk_0x24 = 0;
}

Item_0045E910 *func_0045EB60(void)
{
    State_0045E910 *s;

    if (D_0049D7C8->unk_0x34 >= 0x100)
        D_0049D7C8->unk_0x34 = 0;
    s = D_0049D7C8;
    return &s->unk_0x1c29d0[s->unk_0x34++];
}

