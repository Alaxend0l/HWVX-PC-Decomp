/* 8 functions from 0x0041EB80 to 0x0041FAD0, found by Ghidra. */
#include "common.h"

extern float D_0047700C;
extern float D_00477000;
extern float D_00692378;

struct Flags_0041EB80 {
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 bit2 : 1;
    u32 bit3 : 1;
    u32 bit4 : 1;
    u32 rest : 27;
};

struct Obj_0041EB80 {
    char unk0[0x74];
    u32 unk_0x74;
};

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
    char *s;
    float t;
    float a;
    float b;

    s = p + 0xd0;
    if (*(float *)(p + 0x1bc) >= D_0047700C) {
        *(float *)(s + 0x24) += *(float *)(p + 0xcc) * D_00692378;
        if (*(float *)(s + 0x24) > D_0047700C)
            *(float *)(s + 0x24) = 1.0f;
        a = 0.0f;
        t = *(float *)(s + 0x24) / (*(float *)(s + 0x44) + *(float *)(s + 0x24));
        b = D_00477000;
        if (*(char **)(s + 0x18) != 0)
            a = *(float *)(*(char **)(s + 0x18) + 0x18);
        if (*(char **)(s + 0x38) != 0)
            b = *(float *)(*(char **)(s + 0x38) + 0x18);
        func_004077E0(s + 0x18, 2, ((a - b) * t + b) * *(float *)(p + 0x1b8));
        if (*(int *)(s + 0x30) != 0)
            ((Flags_0041EB80 *)(p + 0x74))->bit4 = 0;
        *(float *)(s + 0x24) = 0.0f;
        func_00408290(s, p);
    }
}

extern "C" int func_0041EC60(List_0041EC60 *list, u32 id)
{
    u32 n = list->count;
    u32 i;

    for (i = 0; i < n; i++) {
        if (list->entries[i].unk4 == id)
            return i;
    }
    return -1;
}

extern "C" void func_0041F9C0(char *p)
{
    ((Flags_0041EB80 *)(p + 0x74))->bit4 = 0;
    func_0041E850(p, 10, 1, 0);
}

extern "C" void func_0041EC40(char *p)
{
    func_00407310(p + 0xd0);
    func_00448330(p);
}

