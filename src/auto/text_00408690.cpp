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
    char unk_0x4c[0x74 - 0x4c];
    unsigned int unk_0x74;
    char unk_0x78[0xb4 - 0x78];
    Info_00408690 *unk_0xb4;
    char unk_0xb8[0xd0 - 0xb8];
    int unk_0xd0;
    char unk_0xd4[0x100 - 0xd4];
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

void func_004268B0(void *, void *, int);
void func_00426BE0(void *, void *, int);
void func_00460820(int);
Out_0045EC70 *func_0045EC70(u16);
void func_004088B0(Obj_00408690 *);
