/* 8 functions from 0x0041EB80 to 0x0041FAD0, found by Ghidra. */
#include "common.h"

extern float D_0047700C;
extern float D_00477000;
extern float D_00692378;

struct Entry_0041EC60 {
    u32 unk0;
    u16 unk4;
    char unk6[0x16];
};
struct List_0041EC60 {
    u32 count;
    Entry_0041EC60 *entries;
};

extern "C" void func_00407310(char *p);
extern "C" void func_00448330(char *p);
extern "C" void func_004077E0(char *p, int a, float b);
extern "C" void func_00408290(char *p, char *q);
extern "C" void func_0041E850(char *p, int a, int b, int c);

extern "C" void func_0041EB80(char *p)
{
    char *s = p + 0xd0;
    float t;
    float a;
    float b;

    if (*(float *)(p + 0x1bc) >= D_0047700C) {
        *(float *)(s + 0x24) += *(float *)(p + 0xcc) * D_00692378;
        if (*(float *)(s + 0x24) > D_0047700C)
            *(float *)(s + 0x24) = 1.0f;
        t = *(float *)(s + 0x24) / (*(float *)(s + 0x44) + *(float *)(s + 0x24));
        a = 0.0f;
        b = D_00477000;
        if (*(char **)(s + 0x18) != 0)
            a = *(float *)(*(char **)(s + 0x18) + 0x18);
        if (*(char **)(s + 0x38) != 0)
            b = *(float *)(*(char **)(s + 0x38) + 0x18);
        func_004077E0(s + 0x18, 2, ((a - b) * t + b) * *(float *)(p + 0x1b8));
        if (*(int *)(s + 0x30) != 0)
            *(u32 *)(p + 0x74) &= ~0x10;
        *(float *)(s + 0x24) = 0.0f;
        func_00408290(s, p);
    }
}

extern "C" void func_0041EC40(char *p)
{
    func_00407310(p + 0xd0);
    func_00448330(p);
}

