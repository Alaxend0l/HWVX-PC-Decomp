/* 16 functions from 0x0041DBE0 to 0x0041EB80, found by Ghidra. */
#include "common.h"

struct Vec4_0041DBE0 {
    float x, y, z, w;
};

/* 0x30-byte records at 0x00661100; each field's address has its own symbol */
struct RecA_00661100 {
    Vec4_0041DBE0 unk_0x00;
    char unk_0x10[0x20];
};

struct RecB_00661110 {
    Vec4_0041DBE0 unk_0x00;
    char unk_0x10[0x20];
};

struct Timer_00661120 {
    int unk_0x00;
    int unk_0x04;
    unsigned unk_0x08;
    char unk_0x0c[0x24];
};

struct RecD_00661128 {
    unsigned unk_0x00;
    char unk_0x04[0x2c];
};

struct Obj_0041E7B0 {
    char unk_0x00[0x1b4];
    float unk_0x1b4;
};

extern RecA_00661100 D_00661100[];
extern RecB_00661110 D_00661110[];
extern Timer_00661120 D_00661120[];
extern Timer_00661120 D_006611E0[];
extern RecD_00661128 D_00661128[];
extern unsigned D_006611E8[];
extern int D_00692370;

extern "C" void func_0041E120(void)
{
    Timer_00661120 *p = D_00661120;
    do {
        p->unk_0x04 = 0;
        p->unk_0x00 = 0;
        p->unk_0x08 = 99999;
        p++;
    } while (p < D_006611E0);
}

extern "C" float func_0041E7B0(Obj_0041E7B0 *o)
{
    return o->unk_0x1b4;
}
