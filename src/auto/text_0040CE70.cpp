/* 9 functions from 0x0040CE70 to 0x0040DCD0, found by Ghidra. */
#include "common.h"

struct Vec4_0040CE70 {
    float x, y, z, w;
};

struct Item_0040CE70 {
    char unk_0x00[0x14];
    float unk_0x14;
    char unk_0x18[0x8];
};

struct ItemList_0040CE70 {
    unsigned count;
    Item_0040CE70 *items;
};

extern float D_00692350[4];

extern "C" void func_00453750(void *, void *, void *);
extern "C" void func_004536E0(void *, void *, void *);
extern "C" void func_00407280(void *, int);
extern "C" void func_0044AD00(void *, void *, void *, void *, void *, int);

extern "C" void func_0040D080(char *p)
{
    Vec4_0040CE70 v;
    Vec4_0040CE70 w;

    func_00453750(p + 0x10, p + 0x35c, &v);
    w.x = v.x * *(float *)(p + 0x39c);
    w.y = v.y * *(float *)(p + 0x3b0);
    w.z = v.z * *(float *)(p + 0x3c4);
    func_004536E0(p + 0x10, &w, p + 0x3e4);
}

extern "C" void func_0040D0E0(char *p, Vec4_0040CE70 *out)
{
    *out = *(Vec4_0040CE70 *)(p + 0x3e4);
}

extern "C" void func_0040DBD0(char *p, float *out)
{
    out[0] = *(float *)(p + 0x39c);
    out[1] = *(float *)(p + 0x3b0);
    out[2] = *(float *)(p + 0x3c4);
}
