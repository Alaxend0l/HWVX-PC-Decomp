/* 5 functions from 0x0044EB60 to 0x0044EFB2, found by Ghidra. */
#include "common.h"

struct Entry_0049E9E0 {
    char unk_0x00[0x0c];
    unsigned int unk_0x0c;
    char unk_0x10[0x1c];
    unsigned int unk_0x2c;
    char unk_0x30[0x20];
    int unk_0x50;
    char unk_0x54[8];
    u16 unk_0x5c;
    u16 unk_0x5e;
};

extern Entry_0049E9E0 D_0049E9E0[1000];
extern float D_0049E9C0;
extern int D_0049E9C4;
extern int D_00692370;
extern float D_00692378;
extern float D_0047736C;

int func_004438E0(void);
void func_0045F0A0(int);
char *func_0045EE10(int, int, int);
void func_00454CF0(void *, void *, int);

void func_0044EB60(void)
{
    int i;
    for (i = 0; i < 1000; i++)
        D_0049E9E0[i].unk_0x50 = 0;
    D_0049E9C0 = 0;
    D_0049E9C4 = 0;
}

void func_0044EB90(void)
{
    int i;
    int dt = D_00692370;
    for (i = 0; i < 1000; i++) {
        Entry_0049E9E0 *e = &D_0049E9E0[i];
        if (e->unk_0x50 > 0) {
            e->unk_0x50 -= dt;
            if (e->unk_0x50 <= 0) {
                e->unk_0x50 = 0;
            } else if (e->unk_0x50 < 2000) {
                int v = (e->unk_0x50 * 128) / 2000;
                if ((unsigned int)v < e->unk_0x0c)
                    e->unk_0x0c = v;
            }
        }
    }
    if (D_0049E9C0 > D_0047736C)
        D_0049E9C0 -= D_0047736C;
    D_0049E9C0 += D_00692378;
}

void func_0044EC10(void)
{
    int n = 0;
    u16 last = 0xffff;
    char *dst = 0;
    Entry_0049E9E0 *e;
    for (e = D_0049E9E0; e < D_0049E9E0 + 1000; e++) {
        if (e->unk_0x50 > 0 && e->unk_0x5e != 0) {
            if (last != e->unk_0x5c) {
                if (n != 0) {
                    func_0045F0A0(n);
                    n = 0;
                }
                dst = func_0045EE10(e->unk_0x5c, 7, 0);
                last = e->unk_0x5c;
            }
            func_00454CF0(dst, e, 0x50);
            dst += 0x50;
            n++;
        }
    }
    if (n != 0)
        func_0045F0A0(n);
}

BOOL func_0044EFA0(void)
{
    return func_004438E0() == 0;
}
