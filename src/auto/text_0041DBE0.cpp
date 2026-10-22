/* 16 functions from 0x0041DBE0 to 0x0041EB80, found by Ghidra. */
#include "common.h"
#include <string.h>

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

/* 0x50-byte records at 0x0065FD00; each field's address has its own symbol */
template <class T> struct Rec50_0065FD00 {
    T v;
    char pad[0x50 - sizeof(T)];
};

struct Obj_0041E470 {
    char unk_0x00[0x20];
    void *unk_0x20;
};

struct Obj_0041E780 {
    char unk_0x00[0x40];
    float unk_0x40;
    float unk_0x44;
    float unk_0x48;
};

extern int D_0065FCE0;
extern unsigned D_0048956C;
extern Rec50_0065FD00<Obj_0041E470 *> D_0065FD00[64];
extern Rec50_0065FD00<Vec4_0041DBE0> D_0065FD04[64];
extern Rec50_0065FD00<char> D_0065FD40[64];
extern Rec50_0065FD00<int> D_0065FD44[64];
extern Rec50_0065FD00<int> D_0065FD48[64];
extern Rec50_0065FD00<char> D_0065FD4C[64];
extern float D_00477108;

int func_00438AF0(void *, int, Vec4_0041DBE0 *);

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

extern "C" void func_0041E140(void)
{
    int dt = D_00692370;
    unsigned *p = (unsigned *)D_00661128;
    do {
        if (p[-1] != 0)
            *p += dt;
        if (*p > 1000) {
            p[-1] = 0;
            p[-2] = 0;
            *p = 99999;
        }
        p += sizeof(Timer_00661120) / sizeof(unsigned);
    } while (p < D_006611E8);
}

extern "C" bool func_0041E180(int a, int b, Vec4_0041DBE0 *out1, Vec4_0041DBE0 *out2)
{
    Timer_00661120 *p;
    int i = 0;
    for (p = D_00661120; p < D_006611E0; p++, i++) {
        if (a == p->unk_0x04 && b == p->unk_0x00) {
            *out1 = D_00661100[i].unk_0x00;
            *out2 = D_00661110[i].unk_0x00;
            D_00661128[i].unk_0x00 = 0;
            return true;
        }
    }
    return false;
}

extern "C" void func_0041E460(void)
{
    D_0065FCE0 = 0;
    D_0048956C = 0;
}

extern "C" float func_0041E7B0(Obj_0041E7B0 *o)
{
    return o->unk_0x1b4;
}
