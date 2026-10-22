/* 6 functions from 0x00415630 to 0x004160C0, found by Ghidra. */
#include "common.h"

struct Vec4_00692350 {
    float x;
    float y;
    float z;
    float w;
};

struct Sub_00415630 {
    char unk_0x00[0x20];
    float unk_0x20;
    float unk_0x24;
};

struct Info_00415630 {
    char unk_0x00[0x10];
    Sub_00415630 *unk_0x10;
};

struct Obj_00415630 {
    char unk_0x000[0xc0];
    Info_00415630 *unk_0x0c0;
    char unk_0x0c4[0xf0 - 0xc4];
    Vec4_00692350 unk_0x0f0;
    Vec4_00692350 unk_0x100;
};

extern Vec4_00692350 D_00692350;
extern float D_00477000;
extern float D_0047700C;
extern float D_0047A3FC[][10];
extern float D_0047A420[][10];

float func_00453360(float *, float *);
void func_00415630(Obj_00415630 *);
