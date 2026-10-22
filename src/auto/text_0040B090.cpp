/* 4 functions from 0x0040B090 to 0x0040BEA0, found by Ghidra. */
#include "common.h"

struct Vec4_0040B090 {
    float x, y, z, w;
};

struct Obj_0040B090 {
    char *unk_0x00;
    char unk_0x04[0x30];
    Vec4_0040B090 unk_0x34;
    char unk_0x44[0x10];
    Vec4_0040B090 unk_0x54;
    char unk_0x64[0x10];
    Vec4_0040B090 unk_0x74;
    Vec4_0040B090 unk_0x84;
    Vec4_0040B090 unk_0x94;
    char unk_0xa4[8];
    float unk_0xac;
};

extern float D_00692378;

void func_004532A0(float, float *, float *);
void func_00453330(void *, void *, void *);
void func_00453380(void *, void *, void *);
void func_00453470(void *);
void func_00460B30(void *);
void func_0040BD20(char *, char *, void *, void *);

void func_0040BC80(char *p, void *a, Vec4_0040B090 *q, void *m)
{
    *(Vec4_0040B090 *)(p + 0x54) = *q;
    Vec4_0040B090 r = { 0.0f, 1.0f, 0.0f, 0.0f };
    func_00453330(m, p + 0x54, p + 0x74);
    func_00453470(p + 0x74);
    func_00453380(&r, p + 0x74, p + 0x94);
    func_00453380(p + 0x74, p + 0x94, p + 0x84);
    func_00453470(p + 0x94);
    func_00453470(p + 0x84);
    func_00460B30(a);
}

void func_0040BE10(char *p, char *e)
{
    float s, c;
    Vec4_0040B090 m;
    Vec4_0040B090 *v;
    char *obj;
    func_004532A0(*(float *)(p + 0xac) += D_00692378 * *(float *)(e + 0x1c), &c, &s);
    obj = *(char **)(*(char **)p + 0x2c);
    if (obj != 0) {
        (*(void (**)(char *, Vec4_0040B090 *))(*(char **)(obj + 0x8c) + 0x3c))(obj, &m);
        v = &m;
    } else {
        v = (Vec4_0040B090 *)(p + 0x34);
    }
    func_0040BD20(p, e, v, v);
}
