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

struct Rec30_0045E910 {
    char pad_0x0[0x20];
    int unk_0x20;
    char pad_0x24[0xc];
};

struct Rec84_0045E910 {
    char pad_0x0[0x83];
    char unk_0x83;
};

struct Rec20_0045E910 {
    unsigned char unk_0x0;
    char pad_0x1[0xb];
    int unk_0xc;
    char pad_0x10[0x10];
};

struct State_0045E910 {
    char pad_0x0[0x8];
    int unk_0x8;
    char pad_0xc[0xc];
    unsigned int unk_0x18;
    char pad_0x1c[0x4];
    unsigned int unk_0x20;
    int unk_0x24;
    char pad_0x28[0xc];
    unsigned int unk_0x34;
    int unk_0x38;
    int unk_0x3c;
    int unk_0x40;
    int unk_0x44;
    char pad_0x48[0x215c0 - 0x48];
    Rec30_0045E910 unk_0x215c0[2000];
    char pad_0x38cc0[0xc];
    Elem_0045E910 unk_0x38ccc[12000];
    char pad_0x15dc4c[0x1a8c40 - 0x15dc4c];
    Rec84_0045E910 unk_0x1a8c40[32];
    char pad_0x1a9cc0[0x1abdc0 - 0x1a9cc0];
    Light_0045E910 unk_0x1abdc0[2588];
    char pad_0x1c29b0[0x20];
    Item_0045E910 unk_0x1c29d0[256];
    char pad_0x1c55d0[0x34ef74 - 0x1c55d0];
    Rec20_0045E910 *unk_0x34ef74;
    char pad_0x34ef78[0xc];
    unsigned short unk_0x34ef84[0x200];
};

extern State_0045E910 *D_0049D7C8;
extern int D_0049D7D4;
extern "C" void func_00464DE0(int a);

static inline Rec20_0045E910 *CurRec20_0045E910(void)
{
    return &D_0049D7C8->unk_0x34ef74[D_0049D7C8->unk_0x44];
}

static inline Rec30_0045E910 *Rec30At_0045E910(int i)
{
    return &D_0049D7C8->unk_0x215c0[i];
}
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

void func_0045EAD0(const Vec4_0045E910 &a, const Vec4_0045E910 &b, const int &c)
{
    D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24].unk_0x0 = a;
    D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24].unk_0x10 = b;
    D_0049D7C8->unk_0x1abdc0[D_0049D7C8->unk_0x24].unk_0x20 = c;
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

void func_0045EC70(unsigned short id)
{
    unsigned short *p;

    if (D_0049D7C8->unk_0x8 == 1999)
        D_0049D7C8->unk_0x8 = 0;
    p = &D_0049D7C8->unk_0x34ef84[id];
    D_0049D7C8->unk_0x215c0[D_0049D7C8->unk_0x8].unk_0x20 = *p;
    *p = D_0049D7C8->unk_0x8;
    D_0049D7C8->unk_0x8++;
}

void func_0045F0A0(int n)
{
    D_0049D7C8->unk_0x34ef74[D_0049D7C8->unk_0x44].unk_0xc += n;
    if (D_0049D7C8->unk_0x34ef74[D_0049D7C8->unk_0x44].unk_0xc != 0) {
        switch (D_0049D7C8->unk_0x34ef74[D_0049D7C8->unk_0x44].unk_0x0) {
        case 0:
            D_0049D7C8->unk_0x38 += n;
            break;
        case 1:
            D_0049D7C8->unk_0x3c += n;
            break;
        case 4:
            D_0049D7C8->unk_0x40 += n;
            break;
        }
        D_0049D7C8->unk_0x44++;
    }
}

Rec84_0045E910 *func_0045F340(void)
{
    Rec84_0045E910 *r;

    if (D_0049D7C8->unk_0x20 >= 0x20)
        D_0049D7C8->unk_0x20 = 0;
    D_0049D7C8->unk_0x1a8c40[D_0049D7C8->unk_0x20].unk_0x83 = D_0049D7D4;
    r = D_0049D7C8->unk_0x1a8c40;
    return &r[D_0049D7C8->unk_0x20++];
}

void func_0045F3D0(int a)
{
    func_00464DE0(a);
}

