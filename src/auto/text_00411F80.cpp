/* 9 functions from 0x00411F80 to 0x00412DB0, found by Ghidra. */
#include "common.h"

struct Vec4_00411F80 {
    float x, y, z, w;
};

struct Mtx_00411F80 {
    Vec4_00411F80 row[4];
};

extern "C" void func_0041B470(int a, int b, char *c, char *d);
extern "C" void func_0041B410(int a, char *m, char *b, char *obj);
extern "C" int func_0043B500(char *, int);
extern "C" int func_00454AF0(int, int);
extern "C" void func_004535E0(Mtx_00411F80 *m, char *b, Vec4_00411F80 *out);
extern "C" float func_0041BF80(int a, Mtx_00411F80 *m, int b, int c, float d, char *e);

extern "C" char *func_00411F80(char *p)
{
    char *e = *(char **)(*(char **)(p + 0x398) + 0xa0);
    switch (*(unsigned char *)(e + 0x10)) {
    case 0:
        if (*(unsigned *)(p + 0x74) & 0x180) {
            func_0041B410(*(int *)(e + 0x44), p + 0x10, p + 0x4ec, p + 0xc0);
            *(unsigned *)(p + 0x74) &= ~0x180;
        }
        return p + 0xc0;
    case 1:
        func_0041B470(*(int *)(p + 0x350), *(int *)(e + 0x48), p + 0x10, p + 0x4ec);
        return *(char **)(p + 0x350);
    }
    return 0;
}

extern "C" int func_004121A0(char *p)
{
    if (*(int *)(p + 0x38c) == -1) {
        *(int *)(p + 0x38c) = func_0043B500(p + 0x40, -1);
        *(int *)(p + 0x390) = func_00454AF0(300, 100);
    }
    return *(int *)(p + 0x38c);
}

extern "C" char func_004126B0(char *p, unsigned lo, unsigned hi)
{
    unsigned v = *(unsigned *)(p + 0x398);
    if (v >= lo && v < hi)
        return 1;
    return 0;
}
