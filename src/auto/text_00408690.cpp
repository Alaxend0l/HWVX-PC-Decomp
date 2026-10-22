/* 15 functions from 0x00408690 to 0x00409690, found by Ghidra. */
#include "common.h"

struct Node_00408690 {
    char unk_0x00[0x1c];
    u8 unk_0x1c;
    char unk_0x1d;
    u8 unk_0x1e;
    u8 unk_0x1f;
};

struct Info_00408690 {
    u8 unk_0x00;
    u8 unk_0x01;
    char unk_0x02[6];
    u16 unk_0x08;
    char unk_0x0a[2];
    char unk_0x0c[8];
    char unk_0x14[8];
    char unk_0x1c[4];
};

struct Obj_00408690 {
    char unk_0x00[0x40];
    int unk_0x40;
    int unk_0x44;
    int unk_0x48;
    int unk_0x4c;
    char unk_0x50[0x74 - 0x50];
    unsigned int unk_0x74;
    char unk_0x78[0xb0 - 0x78];
    char *unk_0xb0;
    Info_00408690 *unk_0xb4;
    float unk_0xb8;
    char unk_0xbc[0xd0 - 0xbc];
    int unk_0xd0;
    char unk_0xd4[0xdc - 0xd4];
    float unk_0xdc;
    char unk_0xe0[0x100 - 0xe0];
    int unk_0x100;
    char unk_0x104[0x130 - 0x104];
    int unk_0x130;
    char unk_0x134[0x154 - 0x134];
    int unk_0x154;
};

struct Out_0045EC70 {
    int unk_0x00;
    int unk_0x04;
    int unk_0x08;
    int unk_0x0c;
    char unk_0x10[0x1c - 0x10];
    int unk_0x1c;
    char unk_0x20[4];
    int unk_0x24;
    char unk_0x28[2];
    char unk_0x2a;
};

extern int D_0069236C;

struct Vec4i_00408690 {
    int x, y, z, w;
};

struct Spawn_00408D10 {
    char *unk_0x00;
    Vec4i_00408690 unk_0x04;
};

extern char D_0047A2CC[];
extern char D_0047A2A4[];
extern char D_0047A28C[];
extern char D_0047A26C[];
extern char D_00489554;
extern void *D_0048955C;
extern void *D_00489564;

void func_004594B0(void);
void func_00454C50(void *);
void func_00452F70(char *);
char func_00459410(void);
void func_0046A822(char *);
void *func_00454B80(int, int, char *);
void func_004482C0(Obj_00408690 *, int);
void func_00461D10(int);
void func_00461BA0(int);
void func_00461BC0(int);
void func_0045E730(int, void *, void *, void *);

void func_004268B0(void *, void *, int);
void func_00426BE0(void *, void *, int);
void func_00460820(int);
Out_0045EC70 *func_0045EC70(u16);
void func_004088B0(Obj_00408690 *);

int func_00408690(Node_00408690 *node)
{
    int n = 1;
    Node_00408690 *child = node + 1;
    unsigned int i;

    if (node->unk_0x1f & 3)
        return 0;
    node->unk_0x1f |= 2;
    for (i = 0; i < node->unk_0x1c; i++) {
        n += func_00408690(child);
        child += child->unk_0x1e;
    }
    return n;
}

char func_00408840(Obj_00408690 *o)
{
    if (!(o->unk_0x74 & 0x4000)) {
        int t = D_0069236C;
        func_004268B0(o->unk_0xb4->unk_0x1c, &o->unk_0x130, t);
        t = D_0069236C;
        func_00426BE0(o->unk_0xb4->unk_0x14, &o->unk_0xd0, t);
        t = D_0069236C;
        func_00426BE0(o->unk_0xb4->unk_0x0c, &o->unk_0x100, t);
    }
    return 1;
}

void func_00408A70(Obj_00408690 *o)
{
    if (!(o->unk_0x74 & 0x10)) {
        func_00460820(0);
        switch (o->unk_0xb4->unk_0x00) {
        case 0: {
            Out_0045EC70 *out = func_0045EC70(o->unk_0xb4->unk_0x08);
            out->unk_0x2a = o->unk_0xb4->unk_0x01;
            out->unk_0x24 = o->unk_0x154;
            out->unk_0x1c = o->unk_0x100;
            out->unk_0x0c = o->unk_0xd0;
            out->unk_0x00 = o->unk_0x40;
            out->unk_0x04 = o->unk_0x44;
            out->unk_0x08 = o->unk_0x48;
            return;
        }
        case 1:
            func_004088B0(o);
            return;
        }
    }
}

char func_00408CF0(Obj_00408690 *o, unsigned int lo, unsigned int hi)
{
    unsigned int v = (unsigned int)o->unk_0xb4;

    if (v < lo || v >= hi)
        return 0;
    return 1;
}

void func_004093C0(void)
{
    func_004594B0();
    func_00454C50(D_0048955C);
    func_00454C50(D_00489564);
}

