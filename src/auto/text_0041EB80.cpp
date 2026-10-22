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

struct Vec4_0041EB80 {
    float x, y, z, w;
};

/* particle spawn records passed to func_0044D0B0 / func_0044D0F0 */
struct Spawn1_0041EB80 {
    Vec4_0041EB80 a;
    Vec4_0041EB80 b;
    Vec4_0041EB80 c;
    Vec4_0041EB80 d;
    int src;
    int owner;
    int unk_0x48;
    int unk_0x4c;
};

struct Spawn2_0041EB80 {
    Vec4_0041EB80 a;
    Vec4_0041EB80 b;
    Vec4_0041EB80 c;
    int src;
    int owner;
    int unk_0x38;
};

extern char *D_0049DBA0;
extern Vec4_0041EB80 D_00692350;
extern float D_0047702C;

extern "C" float func_0041E7B0(char *p);
extern "C" void func_0041E7C0(char *p);
extern "C" void func_0041EC90(char *p, int a, int b);
extern "C" void func_0041F1C0(char *p);
extern "C" void func_00450230(char *p);
extern "C" int func_00454AF0(int, int);
float func_00454AC0(float, float);
void func_00454960(Vec4_0041EB80 *);
char *func_0044D0B0(int, void *);
char *func_0044D0F0(int, void *, int);
void func_0044A790(char *, char *);

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

extern "C" int func_0041EC60(List_0041EC60 *list, int id)
{
    u32 i;

    for (i = 0; i < list->count; i++) {
        if (list->entries[i].unk4 == id)
            return i;
    }
    return -1;
}

extern "C" void func_0041F9C0(Obj_0041EB80 *p)
{
    p->unk_0x74 &= ~0x10;
    func_0041E850((char *)p, 10, 1, 0);
}

extern "C" void func_0041EC40(char *p)
{
    func_00407310(p + 0xd0);
    func_00448330(p);
}

