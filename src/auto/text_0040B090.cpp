/* 4 functions from 0x0040B090 to 0x0040BEA0, found by Ghidra. */
#include "common.h"

struct Vec4_0040B090 {
    float x, y, z, w;
};

extern float D_00692378;

void func_004532A0(float, float *, float *);
void func_00453330(void *, void *, void *);
void func_00453380(void *, void *, void *);
void func_00453470(void *);
void func_00460B30(void *);
void func_0040BD20(char *, char *, void *, void *);

void func_0040BC80(char *p, void *a, float *q, void *m)
{
    float r[4];
    *(float *)(p + 0x54) = q[0];
    *(float *)(p + 0x58) = q[1];
    *(float *)(p + 0x5c) = q[2];
    *(float *)(p + 0x60) = q[3];
    r[0] = 0.0f;
    r[1] = 1.0f;
    r[2] = 0.0f;
    r[3] = 0.0f;
    func_00453330(m, p + 0x54, p + 0x74);
    func_00453470(p + 0x74);
    func_00453380(r, p + 0x74, p + 0x94);
    func_00453380(p + 0x74, p + 0x94, p + 0x84);
    func_00453470(p + 0x94);
    func_00453470(p + 0x84);
    func_00460B30(a);
}

void func_0040BE10(char *p, char *e)
{
    float s, c;
    float m[4];
    char *obj;
    float a = D_00692378 * *(float *)(e + 0x1c) + *(float *)(p + 0xac);
    *(float *)(p + 0xac) = a;
    func_004532A0(a, &c, &s);
    obj = *(char **)(*(char **)p + 0x2c);
    if (obj != 0) {
        (*(void (**)(char *, float *))(*(char **)(obj + 0x8c) + 0x3c))(obj, m);
        func_0040BD20(p, e, m, m);
        return;
    }
    func_0040BD20(p, e, p + 0x34, p + 0x34);
}
