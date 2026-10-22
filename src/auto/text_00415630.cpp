/* 6 functions from 0x00415630 to 0x004160C0, found by Ghidra. */
#include "common.h"

struct Vec4_00692350 {
    float x;
    float y;
    float z;
    float w;
};

struct Sub_00415630 {
    char unk_0x00[0x20];
    float unk_0x20;
    float unk_0x24;
};

struct Info_00415630 {
    char unk_0x00[0x10];
    Sub_00415630 *unk_0x10;
};

struct Obj_00415630 {
    char unk_0x000[0xc0];
    Info_00415630 *unk_0x0c0;
    char unk_0x0c4[0xf0 - 0xc4];
    Vec4_00692350 unk_0x0f0;
    Vec4_00692350 unk_0x100;
};

extern Vec4_00692350 D_00692350;
extern float D_00477000;
extern float D_0047700C;
extern float D_0047A3FC[][10];
extern float D_0047A420[][10];

float func_00453360(float *, float *);
void func_00415630(Obj_00415630 *);

void func_00415B60(Obj_00415630 *p)
{
    Sub_00415630 *s;
    p->unk_0x100 = D_00692350;
    p->unk_0x0f0 = D_00692350;
    s = p->unk_0x0c0->unk_0x10;
    p->unk_0x0f0.y += s->unk_0x24 * s->unk_0x20;
    func_00415630(p);
}

float func_00415FA0(unsigned char a, unsigned int n)
{
    float r = D_0047700C;
    if (a > 8) {
        while (a > 8) {
            r = func_00415FA0(8, n) * r;
            a -= 8;
        }
        return func_00415FA0(a, n) * r;
    }
    while (n >= 10) {
        r *= D_0047A420[a][0];
        n -= 10;
    }
    return r * D_0047A3FC[a][n];
}

float func_00416040(char *a, char *b, float s)
{
    float r = func_00453360((float *)(a + 0x20), (float *)(b + 0x10)) * s;
    if (r < D_00477000)
        return D_0047700C;
    return D_0047700C - r;
}

void func_00416080(float *a, float *b, float t)
{
    float d = func_00453360(a, b) * (D_0047700C - t);
    a[0] -= d * b[0];
    a[1] -= d * b[1];
    a[2] -= d * b[2];
}

