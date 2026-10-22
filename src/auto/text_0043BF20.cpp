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

struct Src20_0043BF20 {
    unsigned char b00;
    unsigned char b01;
    char unk_0x02[0x4 - 0x2];
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

struct Elem_0043C520 {
    Vec4_0043BF20 unk_0x00;
    Vec4_0043BF20 unk_0x10;
    Vec4_0043BF20 unk_0x20;
    char unk_0x30[0x5c - 0x30];
    unsigned char b5c;
    char unk_0x5d[0x60 - 0x5d];
    float f60;
    char unk_0x64[0x80 - 0x64];
    float f80;
    float f84;
    int f88;
    float f8c;
    int f90;
    unsigned char flags;
    unsigned char b95;
    unsigned char b96;
    unsigned char b97;
    float f98;
    float f9c;
    float fa0;
    char unk_0xa4[0xb0 - 0xa4];
};

struct Body_0043C6C0 {
    unsigned char b00;
    unsigned char b01;
    char unk_0x02[0x4 - 0x2];
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char unk_0x24[0x28 - 0x24];
    float f28;
    char unk_0x2c[0x30 - 0x2c];
    Vec4_0043BF20 pos;
    Vec4_0043BF20 rot;
    Vec4_0043BF20 spin;
    char unk_0x50[0x80 - 0x50];
    float f80;
    float f84;
    char unk_0x88[0x8c - 0x88];
    float f8c;
    char unk_0x90[0xb8 - 0x90];
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

int func_00454AF0(int, int);
int func_0046A7CC(void);
void func_004268B0(int, float *, float);
void func_004266F0(char *, float *, float);
float func_00454AC0(float, float);
float func_00454B20(float, float);
extern int D_005D4410;
extern float D_0047700C;
void func_0043C2D0(Vec4_0043BF20 *s0, int a1, Src20_0043BF20 *src, int a3, int a4, float scale)
{
    Elem_0043C520 *e;
    float fl;
    float fv;
    Body_0043C6C0 *b;
    int c;

    fl = (float)func_00454AF0(src->f08, src->f0c);
    fv = (float)(int)func_0046A7CC();
    b = (Body_0043C6C0 *)src->f04;
    if (b == NULL)
        return;
    e = &D_005BE410[D_005D4410];
    D_005D4410 = D_005D4410 + 1;
    if (D_005D4410 >= 0x200)
        D_005D4410 = 0;
    e->unk_0x00 = *s0;
    e->unk_0x10 = *(Vec4_0043BF20 *)a1;
    e->unk_0x20 = *(Vec4_0043BF20 *)src;
    e->f90 = (int)b;
    e->flags &= 0xf3;
    if (src->b01 == 0) {
        e->b97 = 0;
        e->fa0 = *(float *)&src->f20;
    } else {
        e->fa0 = *(float *)&src->f1c;
    }
    e->f88 = func_0046A7CC();
    e->f98 = fl;
    e->f9c = 1.0f;
    if (src->f0c != 0 && src->f08 != 0)
        e->f9c = D_0047700C / (fl / (float)src->f08);
    e->b95 = src->b00;
    func_004268B0(src->f04 + 0x14, (float *)&b->pos, fv);
    e->b96 = 1;
    func_004266F0((char *)src + 0x28, &e->f9c, fv);
    e->fa0 = func_00454B20(*(float *)&src->f04, *(float *)&src->f08);
    e->f8c = func_00454AC0(*(float *)&src->f0c, *(float *)&src->f10);
    if (b->f14 != 0) {
        if (b->f14 != 1)
            return;
        c = **(int **)&b->f18;
        if ((char)c == -1 && (char)(c >> 8) == -1 && (char)(c >> 16) == -1)
            e->b96 = 0;
        return;
    }
    e->b96 = 0;
}

void func_0043CEB0(Part_0043C4F0 *p)
{
    int i;
    for (i = 0; i < 0x280; i++, p++) {
        if (!(p->flags & 8))
            func_0043CF50(p);
    }
}

void func_0043CEE0(Elem_0043C520 *e)
{
    int i;
    for (i = 0; i < 0x200; i++, e++) {
        if (!(e->flags & 8))
            func_0043D010(e);
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

