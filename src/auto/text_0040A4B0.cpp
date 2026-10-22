/* 12 functions from 0x0040A4B0 to 0x0040B090, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Slot_0040A4B0 {
    char unk_0x000[0x16c];
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

static inline void ClearLists_0040A4B0(int *a, int *b, int *count)
{
    memset(a, 0, 8 * sizeof(int));
    memset(b, 0, 8 * sizeof(int));
    *count = 0;
}

void func_00409DA0(int);
void func_0040A4F0(void);

int func_0040A4B0(void)
{
    return *(int *)&D_00681AB0 & 0xff;
}

void func_0040A4F0(void)
{
    memset(D_00681380, 0, sizeof(D_00681380));
    D_006814E0 = 0;
    memset(D_00681360, 0, sizeof(D_00681360));
    memset(D_00681460, 0, sizeof(D_00681460));
    D_006814E4 = 0;
    memset(D_006813E0, 0, sizeof(D_006813E0));
}

void func_0040A540(void)
{
    D_00681AB4 = 0;
    D_00681AB0 = 0;
    func_00409DA0(0);
    func_0040A4F0();
}

Slot_0040A4B0 *func_0040A4C0(u32 i)
{
    if (i < (*(u32 *)&D_00681AB0 & 0xff) && i < 4)
        return &D_00681500[i];
    return NULL;
}

