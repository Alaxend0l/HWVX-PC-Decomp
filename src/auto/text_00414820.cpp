/* 5 functions from 0x00414820 to 0x00415630, found by Ghidra. */
#include "common.h"

struct Mat_00414820 {
    float m[12];
};

struct Body_00414820 {
    float unk_0x00;
    float unk_0x04;
    float unk_0x08;
    char unk_0x0c[4];
    char unk_0x10;
    char unk_0x11[0xf];
    float unk_0x20;
    char unk_0x24[0x20];
    Mat_00414820 *unk_0x44;
};

extern float D_0047700C;

void func_00453750(void *, void *, void *);
void func_004536E0(void *, void *, void *);

void func_00415360(char *p)
{
    Body_00414820 *b = *(Body_00414820 **)(*(char **)(p + 0xc0) + 0x10);
    Mat_00414820 m;
    float xx, yy, zz;
    if (!b->unk_0x10)
        m = *b->unk_0x44;
    zz = m.m[6] * m.m[6];
    yy = m.m[5] * m.m[5];
    *(float *)(p + 0x120) = D_0047700C / ((yy + zz) * b->unk_0x20 * b->unk_0x00);
    xx = m.m[4] * m.m[4];
    b = *(Body_00414820 **)(*(char **)(p + 0xc0) + 0x10);
    *(float *)(p + 0x124) = D_0047700C / ((xx + zz) * b->unk_0x20 * b->unk_0x04);
    b = *(Body_00414820 **)(*(char **)(p + 0xc0) + 0x10);
    *(float *)(p + 0x128) = D_0047700C / ((xx + yy) * b->unk_0x20 * b->unk_0x08);
}

void func_004152C0(char *p, int unused, char *q)
{
    *(char **)(q + 0x7c) = p + 0x154;
    *(int *)(q + 0x80) = 1;
    *(float *)(q + 0x84) = 1.0f;
    *(float *)(q + 0x28) = 0.0f;
    *(float *)(q + 0x2c) = 1.0f;
    *(float *)(q + 0x30) = 0.0f;
}

void func_00415300(char *p)
{
    float v[4];
    float w[4];
    func_00453750(p + 0x10, p + 0x110, v);
    w[0] = v[0] * *(float *)(p + 0x120);
    w[1] = v[1] * *(float *)(p + 0x124);
    w[2] = v[2] * *(float *)(p + 0x128);
    func_004536E0(p + 0x10, w, p + 0x130);
}

