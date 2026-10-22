/* 31 functions from 0x00453FB0 to 0x00454E70, found by Ghidra. */
#include "common.h"

extern "C" void *func_0046AED9(unsigned int size);
float func_00453360(float *, float *);
float func_004534B0(float *);
void func_00453330(float *, float *, float *);
float func_00454800(float *, float *);
float func_004532E0(float);
void func_004546B0(float *);
float func_00454AC0(float, float);
void func_00454A30(float *);
void func_00453D20(float *, float, float *);

struct Vec3_00453FB0 {
    float x, y, z;
};

static inline float Length3_00453FB0(float x, float y, float z)
{
    return func_004532E0(x * x + y * y + z * z);
}

extern float D_0047700C;
extern float D_00477000;
extern float D_00477008;
float func_00454800(float *plane, float *v)
{
    return plane[2] * v[2] + plane[1] * v[1] + plane[0] * v[0] + plane[3];
}

void func_004546B0(float *p)
{
    float len = Length3_00453FB0(p[0], p[1], p[2]);

    if (len != D_0047700C && len != D_00477000) {
        float inv = D_0047700C / len;
        p[0] = inv * p[0];
        p[1] = inv * p[1];
        p[2] = inv * p[2];
        p[3] = inv * p[3];
    }
}

void func_00454730(float *out, float *n, float *pt)
{
    *(Vec3_00453FB0 *)out = *(Vec3_00453FB0 *)n;
    out[3] = (pt[1] * n[1] + pt[2] * n[2] + n[0] * pt[0]) * D_00477008;
    func_004546B0(out);
}

void *func_00454B60(void)
{
    return func_0046AED9(0x54);
}

extern "C" void func_0046B013(void *p);
float func_004532E0(float);
extern float D_0047700C;
extern float D_00477000;
extern float D_00477008;
void func_00454B70(void *p)
{
    func_0046B013(p);
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
    if (*lo > *p)
        *lo = *p;
    if (lo[1] > p[1])
        lo[1] = p[1];
    if (lo[2] > p[2])
        lo[2] = p[2];
    if (lo[3] > p[3])
        lo[3] = p[3];
    if (*hi < *p)
        *hi = *p;
    if (hi[1] < p[1])
        hi[1] = p[1];
    if (hi[2] < p[2])
        hi[2] = p[2];
    if (hi[3] < p[3])
        hi[3] = p[3];
}

void func_004545C0(float *m, float *v, float *out)
{
    out[0] = func_00454800(&m[0], v);
    out[1] = func_00454800(&m[4], v);
    out[2] = func_00454800(&m[8], v);
    out[3] = func_00454800(&m[12], v);
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

void func_00454780(float *out, const float *n, const float *pt)
{
    out[0] = n[0];
    out[1] = n[1];
    out[2] = n[2];
    out[3] = (pt[1] * n[1] + pt[2] * n[2] + n[0] * pt[0]) * D_00477008;
}

float func_00454AC0(float, float);
void func_00454A30(float *);
void func_00453D20(float *, float, float *);
void func_004547C0(float *p)
{
    p[0] = p[0] * D_00477008;
    p[1] = p[1] * D_00477008;
    p[2] = p[2] * D_00477008;
    p[3] = p[3] * D_00477008;
}

