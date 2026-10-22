/* 13 functions from 0x0043CF10 to 0x0043DDB0, found by Ghidra. */
#include "common.h"
struct Vec4_0043CF10 {
    float x, y, z, w;
};

struct Table_0043CF10 {
    char unk_0x00[0x24];
    int *entries;
};

struct Model_0043CF10 {
    int unk_0x00;
    Table_0043CF10 *table;
};

struct Part_0043CF50 {
    char unk_0x00[0xc];
    float unk_0x0c;
    char unk_0x10[0x30 - 0x10];
    Vec4_0043CF10 unk_0x30;
    char unk_0x40[0x74 - 0x40];
    int unk_0x74;
    char unk_0x78[0x80 - 0x78];
    float unk_0x80;
    float unk_0x84;
    float unk_0x88;
    char unk_0x8c[0xb6 - 0x8c];
    char unk_0xb6;
    unsigned char unk_0xb7;
    char unk_0xb8[4];
    Model_0043CF10 *model;
    int unk_0xc0;
    float unk_0xc4;
    char unk_0xc8[0xd8 - 0xc8];
    float unk_0xd8;
    char unk_0xdc[0x100 - 0xdc];
};

struct Group_0043CF10 {
    Part_0043CF50 parts[0x280];
    char unk_0x28000[0x10];
};

struct Elem_0043D010 {
    int unk_0x00;
    int unk_0x04;
    int unk_0x08;
    char unk_0x0c[0x54 - 0x0c];
    int unk_0x54;
    char unk_0x58[0x60 - 0x58];
    float unk_0x60;
    char unk_0x64[0x80 - 0x64];
    int unk_0x80;
    char unk_0x84[0x8c - 0x84];
    float unk_0x8c;
    Model_0043CF10 *model;
    char unk_0x94;
    char unk_0x95;
    char unk_0x96;
    unsigned char unk_0x97;
    char unk_0x98[0xb0 - 0x98];
};

struct Obj_0045EC70 {
    int unk_0x00;
    int unk_0x04;
    int unk_0x08;
    float unk_0x0c;
    char unk_0x10[0x1c - 0x10];
    int unk_0x1c;
    char unk_0x20[4];
    int unk_0x24;
    char unk_0x28[2];
    char unk_0x2a;
};

extern Group_0043CF10 D_005463E0[3];
extern Elem_0043D010 D_005BE410[0x200];
extern int D_0048D774;

void func_0043CEB0(Part_0043CF50 *);
void func_0043CEE0(Elem_0043D010 *);
void func_0043D280(int, int);
void func_00461D10(int);
void func_00461BA0(int);
void func_00461BC0(int);
void func_0045E730(int, Vec4_0043CF10 *, Vec4_0043CF10 *, Part_0043CF50 *);
Obj_0045EC70 *func_0045EC70(int);

void func_0043CF10(void)
{
    Group_0043CF10 *g;
    for (g = D_005463E0; g < (Group_0043CF10 *)D_005BE410; g++)
        func_0043CEB0(g->parts);
    func_0043CEE0(D_005BE410);
    D_0048D774 = 0;
}

void func_0043CF50(Part_0043CF50 *p)
{
    Vec4_0043CF10 v;
    float s;
    unsigned char i = p->unk_0xb7;

    p->unk_0xc0 = p->model->table->entries[i];
    if (p->unk_0xb6) {
        func_00461D10(p->unk_0x74);
        func_00461BA0(0x10);
    }
    s = p->unk_0xd8 * p->unk_0xc4;
    v.x = s * p->unk_0x80;
    v.y = s * p->unk_0x84;
    v.z = s * p->unk_0x88;
    v.w = 1.0f;
    p->unk_0x0c = 1.0f;
    func_0045E730(p->unk_0xc0, &p->unk_0x30, &v, p);
    if (p->unk_0xb6)
        func_00461BC0(0x10);
}

void func_0043D010(Elem_0043D010 *e)
{
    Obj_0045EC70 *o;

    o = func_0045EC70(((unsigned short *)e->model->table->entries)[e->unk_0x97 * 2]);
    o->unk_0x2a = e->unk_0x95;
    o->unk_0x24 = e->unk_0x54;
    o->unk_0x1c = e->unk_0x80;
    o->unk_0x0c = e->unk_0x8c * e->unk_0x60;
    o->unk_0x00 = e->unk_0x00;
    o->unk_0x04 = e->unk_0x04;
    o->unk_0x08 = e->unk_0x08;
}

void func_0043D530(int a, int b)
{
    func_0043D280(a, b);
}

