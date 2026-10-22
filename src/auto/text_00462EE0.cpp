/* 12 functions from 0x00462EE0 to 0x00463DC0, found by Ghidra. */
#include "common.h"

struct Sub_006C9C04 {
    float unk_0x00;
    char unk_0x04[4];
    float unk_0x08;
    char unk_0x0c[4];
    u8 unk_0x10;
    u8 unk_0x11;
    char unk_0x12[2];
};

struct Chan_006C9C04 {
    char unk_0x00[0xc];
    u16 unk_0x0c;
    char unk_0x0e[2];
    char active;
    char unk_0x11;
    s16 refs;
    Sub_006C9C04 sub[128];
};

struct Entry_006D3D44 {
    char unk_0x00[0x32];
    u16 unk_0x32;
    char unk_0x34[0x40 - 0x34];
};

/* The same table seen from the labels the original's code addresses fields through. */
struct ChanIdx_006C9C10 {
    u16 unk_0x0c;
    char unk_0x0e[0xa14 - 0x2];
};

struct ChanActive_006C9C14 {
    char active;
    char unk_0x11[0xa14 - 0x1];
};

extern Chan_006C9C04 D_006C9C04[16];
extern ChanIdx_006C9C10 D_006C9C10[16];
extern ChanActive_006C9C14 D_006C9C14[16];
extern ChanActive_006C9C14 D_006D3D54[];
extern int D_006C9C00;
extern u16 D_006D4D14;
extern Entry_006D3D44 *D_006D3D44;

void func_00462EE0(void)
{
    Chan_006C9C04 *p;

    D_006D4D14 = 0;
    D_006C9C00 = 0;
    p = D_006C9C04;
    do {
        p->active = 0;
        p++;
    } while (p < &D_006C9C04[16]);
}

void func_00462F10(u16 v)
{
    D_006D4D14 = v;
}

int func_00462F20(int i)
{
    Chan_006C9C04 *c = &D_006C9C04[i];

    if (c->active != 0) {
        if (--c->refs != 0)
            return 0;
        c->active = 0;
        D_006C9C00--;
    }
    return 1;
}

void func_00463220(int i, u8 n, float a, float b)
{
    Chan_006C9C04 *c = &D_006C9C04[i];
    Sub_006C9C04 *s = &c->sub[n];
    float t = a / (float)D_006D3D44[c->unk_0x0c].unk_0x32;

    s->unk_0x10 = (u8)a;
    s->unk_0x11 = (u8)b;
    s->unk_0x08 = t + c->sub[n].unk_0x00;
}

