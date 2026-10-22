/* 7 functions from 0x00405800 to 0x00406770, found by Ghidra. */
#include "common.h"

struct Obj_00405800 {
    char pad_0x00[0xb8];
    Obj_00405800 *unk_0xb8;
    void (*unk_0xbc)(void);
    char pad_0xc0[4];
    char unk_0xc4;
    char pad_0xc5[3];
    int unk_0xc8;
    char pad_0xcc;
    char unk_0xcd;
    char pad_0xce[2];
    int unk_0xd0;
    char pad_0xd4[4];
    int unk_0xd8;
    int unk_0xdc;
    int unk_0xe0;
    int unk_0xe4;
    char pad_0xe8[4];
    char unk_0xec;
    char pad_0xed[3];
    int unk_0xf0;
    int unk_0xf4;
};

extern "C" void func_00401F80(char *p);
extern "C" void func_00401FA0(char *p, int *a);
extern "C" void func_00406770(void);
extern "C" void func_004061D0(char *p);
extern "C" void func_004061D0(char *p)
{
    func_00401F80(p);
    *(int *)(p + 0xe4) = 0;
    *(char *)(p + 0xec) = 0;
    *(int *)(p + 0xf4) = 0;
    *(int *)(p + 0xf0) = 0;
    *(char *)(p + 0xcd) = 0;
    *(int *)(p + 0xc8) = 0;
    *(int *)(p + 0xd8) = 0;
    *(int *)(p + 0xdc) = -1;
    *(int *)(p + 0xe0) = 0;
}

extern "C" float func_004065F0(float *a, float *b)
{
    float dz = a[2] - b[2];
    float dx = a[0] - b[0];
    return dx * dx + dz * dz;
}

extern "C" void func_00406720(char *p, int *a)
{
    func_00401FA0(p, a);
    *(int *)(p + 0xd0) = *a;
    *(char **)(p + 0xb8) = p;
    *(void (**)(void))(p + 0xbc) = func_00406770;
    *(char *)(p + 0xc4) = 0;
    func_004061D0(p);
    *(char *)(p + 0xcd) = 3;
}
