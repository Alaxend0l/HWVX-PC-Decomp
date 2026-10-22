/* 27 functions from 0x0044A0D0 to 0x0044AD00, found by Ghidra. */
#include "common.h"

struct Vec4_0044A0D0 {
    float x, y, z, w;
};

struct Obj_0044A0D0 {
    char unk_0x00[0x40];
    Vec4_0044A0D0 pos;
    char unk_0x50[0x20];
    float radius;
    char unk_0x74[0x10];
    void *unk_0x84;
};

extern "C" void func_00449E20(Obj_0044A0D0 *obj, Vec4_0044A0D0 *a, Vec4_0044A0D0 *b, int arg);
extern "C" void func_0042D6E0(void *p, Vec4_0044A0D0 *a, Vec4_0044A0D0 *b);
