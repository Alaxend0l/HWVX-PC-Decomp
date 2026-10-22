/* 12 functions from 0x0040A4B0 to 0x0040B090, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Slot_0040A4B0 {
    char unk_0x000[0x54];
    float unk_0x054[3];
    char unk_0x060[0x74 - 0x60];
    float unk_0x074[4];
    float unk_0x084[4];
    float unk_0x094[4];
    char unk_0x0a4[0x16c - 0xa4];
};

extern u8 D_00681AB0;
extern u8 D_00681AB4;
extern Slot_0040A4B0 D_00681500[4];
extern int D_00681360[8];
extern int D_00681380[8];
extern int D_006813E0[8];
extern int D_00681460[8];
extern int D_006814E0;
extern int D_006814E4;

void func_00409DA0(int);
void func_0040A4F0(void);

int func_0040A4B0(void)
{
    return *(int *)&D_00681AB0 & 0xff;
}

void func_0040A4F0(void)
{
    int i;
    for (i = 0; i < 8; i++)
        D_00681380[i] = 0;
    for (i = 0; i < 8; i++)
        D_00681360[i] = 0;
    D_006814E0 = 0;
    for (i = 0; i < 8; i++)
        D_00681460[i] = 0;
    for (i = 0; i < 8; i++)
        D_006813E0[i] = 0;
    D_006814E4 = 0;
}

void func_0040A540(void)
{
    D_00681AB4 = 0;
    D_00681AB0 = 0;
    func_00409DA0(0);
    func_0040A4F0();
}

void func_0040A7D0(void)
{
    Slot_0040A4B0 *s;
    for (s = D_00681500; s < D_00681500 + 4; s++) {
        s->unk_0x054[0] = 0.0f;
        s->unk_0x054[1] = 0.0f;
        s->unk_0x054[2] = 0.0f;
        s->unk_0x074[0] = 0.0f;
        s->unk_0x074[1] = 0.0f;
        s->unk_0x074[2] = 1.0f;
        s->unk_0x084[0] = 0.0f;
        s->unk_0x084[1] = 1.0f;
        s->unk_0x084[2] = 0.0f;
        s->unk_0x094[0] = 1.0f;
        s->unk_0x094[1] = 0.0f;
        s->unk_0x094[2] = 0.0f;
    }
}

void func_0040A810(u8 n)
{
    D_00681AB4 = n;
}

Slot_0040A4B0 *func_0040A4C0(u32 i)
{
    if (i < (*(u32 *)&D_00681AB0 & 0xff) && i < 4)
        return &D_00681500[i];
    return NULL;
}

