/* 11 functions from 0x0043BF20 to 0x0043CF10, found by Ghidra. */
#include "common.h"

struct Vec4_0043BF20 {
    float x, y, z, w;
};

struct Part_0043C4F0 {
    char unk_0x00[0xb4];
    unsigned char flags;
    char unk_0xb5[0x100 - 0xb5];
};

struct Group_0043C4F0 {
    Part_0043C4F0 parts[0x280];
    char unk_0x28000[0x10];
};

struct Elem_0043C520 {
    Vec4_0043BF20 unk_0x00;
    Vec4_0043BF20 unk_0x10;
    Vec4_0043BF20 unk_0x20;
    char unk_0x30[0x94 - 0x30];
    unsigned char flags;
    char unk_0x95[0xb0 - 0x95];
};

struct Body_0043C6C0 {
    Vec4_0043BF20 pos;
    char unk_0x10[0x30 - 0x10];
    Vec4_0043BF20 rot;
    Vec4_0043BF20 spin;
    char unk_0x50[0xb8 - 0x50];
    float unk_0xb8;
    char unk_0xbc[0xc8 - 0xbc];
    float unk_0xc8;
    char unk_0xcc[0xf0 - 0xcc];
    Vec4_0043BF20 vel;
};

extern float D_0069236C;
extern float D_00477000;
extern float D_00477158;
extern char D_0048D974;
extern Group_0043C4F0 D_005463E0[3];
extern Elem_0043C520 D_005BE410[0x200];

void func_0043C5E0(Part_0043C4F0 *);
void func_0043CCB0(Elem_0043C520 *, Elem_0043C520 *);
void func_004533F0(float, Vec4_0043BF20 *, Vec4_0043BF20 *, Vec4_0043BF20 *);
void func_00453D20(Vec4_0043BF20 *, float, Vec4_0043BF20 *);
void func_00453E00(Vec4_0043BF20 *, Vec4_0043BF20 *, Vec4_0043BF20 *);

void func_0043CF50(Part_0043C4F0 *);
void func_0043D010(Elem_0043C520 *);
void func_0043C4F0(Part_0043C4F0 *p)
{
    int i;
    for (i = 0; i < 0x280; i++, p++) {
        if (!(p->flags & 8))
            func_0043C5E0(p);
    }
}

void func_0043C520(Elem_0043C520 *elems)
{
    Elem_0043C520 *e;
    int i;
    float dt;

    dt = D_0069236C;
    e = elems;
    for (i = 0x200; i != 0; i--, e++) {
        if (!(e->flags & 8))
            func_0043CCB0(e, elems);
    }
    e = elems;
    for (i = 0x200; i != 0; i--, e++) {
        if (!(e->flags & 8)) {
            func_004533F0(dt, &e->unk_0x20, &e->unk_0x10, &e->unk_0x10);
            func_004533F0(dt, &e->unk_0x10, &e->unk_0x00, &e->unk_0x00);
        }
    }
}

void func_0043C6C0(Body_0043C6C0 *b)
{
    Vec4_0043BF20 t;
    Vec4_0043BF20 r;
    Vec4_0043BF20 q;

    func_004533F0(D_0069236C, &b->vel, &b->pos, &t);
    b->pos.x = t.x;
    b->pos.y = t.y;
    b->pos.z = t.z;
    b->pos.w = t.w;
    if (b->unk_0xc8 != D_00477000) {
        func_00453D20(&b->spin, b->unk_0xb8 * b->unk_0xc8 * D_0069236C * D_00477158, &q);
        func_00453E00(&b->rot, &q, &r);
        b->rot = r;
    }
}

void func_0043CEB0(Part_0043C4F0 *p)
{
    int i;
    for (i = 0; i < 0x280; i++, p++) {
        if (!(p->flags & 8))
            func_0043CF50(p);
    }
}

void func_0043C5A0(void)
{
    Group_0043C4F0 *g;
    if (D_0048D974)
        return;
    for (g = D_005463E0; g < (Group_0043C4F0 *)D_005BE410; g++)
        func_0043C4F0(g->parts);
    func_0043C520(D_005BE410);
}

