/* 5 functions from 0x00414820 to 0x00415630, found by Ghidra. */
#include "common.h"

struct Mat_00414820 {
    float m[12];
};

struct Body_00414820 {
    float unk_0x00;
    float unk_0x04;
    float unk_0x08;
    char unk_0x0c[4];
    char unk_0x10;
    char unk_0x11[0xf];
    float unk_0x20;
    char unk_0x24[0x20];
    Mat_00414820 *unk_0x44;
};

extern float D_0047700C;

void func_00453750(void *, void *, void *);
void func_004536E0(void *, void *, void *);
