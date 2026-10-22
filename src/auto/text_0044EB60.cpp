/* 5 functions from 0x0044EB60 to 0x0044EFB2, found by Ghidra. */
#include "common.h"

struct Entry_0049E9E0 {
    char unk_0x00[0x2c];
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

BOOL func_0044EFA0(void)
{
    return func_004438E0() == 0;
}
