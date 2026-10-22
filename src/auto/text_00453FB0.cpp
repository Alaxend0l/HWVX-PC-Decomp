/* 31 functions from 0x00453FB0 to 0x00454E70, found by Ghidra. */
#include "common.h"

extern "C" void *func_0046AED9(unsigned int size);
float func_00453360(float *, float *);
float func_004534B0(float *);
void func_00453330(float *, float *, float *);
float func_00454800(float *, float *);
void *func_00454B60(void)
{
    return func_0046AED9(0x54);
}

void func_004542D0(float *a, float *b)
{
    float d = func_00453360(a, b);
    b[0] = d * a[0];
    b[1] = d * a[1];
    b[2] = d * a[2];
}

void func_00454300(float *a, float *b)
{
    float d;

    d = -func_00453360(a, b);
    b[0] = b[0] + a[0] * d;
    b[1] = b[1] + a[1] * d;
    b[2] = b[2] + a[2] * d;
}

float func_00454340(float *a, float *b, float *c)
{
    float u[4];
    float v[4];
    float dot;
    float lv;

    func_00453330(a, b, u);
    func_00453330(c, b, v);
    dot = func_00453360(u, v);
    lv = func_004534B0(v);
    return 1.0f * dot / (func_004534B0(u) * lv);
}

void func_00454520(float *lo, float *hi, float *p)
{
    if (lo[0] > p[0])
        lo[0] = p[0];
    if (lo[1] > p[1])
        lo[1] = p[1];
    if (lo[2] > p[2])
        lo[2] = p[2];
    if (lo[3] > p[3])
        lo[3] = p[3];
    if (hi[0] < p[0])
        hi[0] = p[0];
    if (hi[1] < p[1])
        hi[1] = p[1];
    if (hi[2] < p[2])
        hi[2] = p[2];
    if (hi[3] < p[3])
        hi[3] = p[3];
}

void func_004545C0(float *m, float *v, float *out)
{
    out[0] = func_00454800(m, v);
    out[1] = func_00454800(m + 4, v);
    out[2] = func_00454800(m + 8, v);
    out[3] = func_00454800(m + 12, v);
}

void func_00454610(float *m, float *s)
{
    m[0] *= s[0];
    m[1] *= s[0];
    m[2] *= s[0];
    m[3] *= s[0];
    m[4] = s[1] * m[4];
    m[5] = s[1] * m[5];
    m[6] = s[1] * m[6];
    m[7] = s[1] * m[7];
    m[8] = s[2] * m[8];
    m[9] *= s[2];
    m[10] *= s[2];
    m[11] *= s[2];
    m[12] *= s[3];
    m[13] *= s[3];
    m[14] *= s[3];
    m[15] *= s[3];
}

