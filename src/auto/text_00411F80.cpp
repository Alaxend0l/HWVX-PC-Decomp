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
