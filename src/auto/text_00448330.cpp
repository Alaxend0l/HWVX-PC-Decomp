/* 12 functions from 0x00448330 to 0x00449110, found by Ghidra. */
#include "common.h"

extern char D_0047A2E8[];
extern char D_0047A830[];
extern char D_0047B088[];
extern char D_0047B040[];
extern char D_0047AED8[];
extern char D_0047A3B0[];
extern char D_0047A5E0[];
extern "C" bool func_0044A870(char *a, int b);
extern "C" void func_0042D770(int a);
extern "C" void func_0044A9C0(char *a, char *b);
extern "C" void func_0044A990(char *a);
extern "C" void func_0044A910(char *a);
extern "C" void func_0043ED30(char *a);
extern "C" char *func_004483A0(char *p);
extern "C" void func_004543B0(float *a, int b, float *c, float *d);

static inline void Max4_00448(float *d, const float *s)
{
    if (d[0] < s[0])
        d[0] = s[0];
    if (d[1] < s[1])
        d[1] = s[1];
    if (d[2] < s[2])
        d[2] = s[2];
    if (d[3] < s[3])
        d[3] = s[3];
}

static inline void Min4_00448(float *d, const float *s)
{
    if (d[0] > s[0])
        d[0] = s[0];
    if (d[1] > s[1])
        d[1] = s[1];
    if (d[2] > s[2])
        d[2] = s[2];
    if (d[3] > s[3])
        d[3] = s[3];
}

extern float D_0047700C;
extern "C" void func_00448330(char *p)
{
    char *q;

    *(unsigned int *)(p + 0x74) |= 0x200202;
    if (*(int *)(p + 0x84) != 0)
        func_0042D770(*(int *)(p + 0x84));
    *(int *)(p + 0x84) = 0;
    func_0044A9C0(p + 0x10, p + 0x88);
    func_0044A990(p + 0x88);
    func_0044A910(p + 0x88);
    q = *(char **)(p + 0x94);
    if (q != NULL && *(char **)(q + 0x2c) == p)
        func_0043ED30(q);
}

extern "C" char *func_004483A0(char *p)
{
    char *t = *(char **)(p + 0x8c);

    if (t == D_0047A2E8)
        return *(char **)(*(char **)(p + 0x398) + 0xa0);
    if (t == D_0047A830 || t == D_0047B088 || t == D_0047B040)
        return *(char **)(*(char **)(p + 0xc0) + 0x10);
    if (t == D_0047AED8)
        return 0;
    if (t == D_0047A3B0)
        return *(char **)(*(char **)(p + 0xc0) + 0x10);
    return 0;
}

extern "C" int func_00448400(char *p)
{
    char *d = func_004483A0(p);
    int k = *(unsigned char *)(d + 0x10);

    switch (k) {
    case 0:
        return *(int *)(d + 0x44);
    case 1:
        return *(int *)(d + 0x48);
    case 7:
        return *(int *)(d + 0x44);
    }
    return 0;
}

extern "C" void func_004484A0(float *a, float *b, float *c)
{
    if (c[0] < a[0])
        c[0] = a[0];
    if (c[1] < a[1])
        c[1] = a[1];
    if (c[2] < a[2])
        c[2] = a[2];
    if (c[3] < a[3])
        c[3] = a[3];
    if (c[0] > b[0])
        c[0] = b[0];
    if (c[1] > b[1])
        c[1] = b[1];
    if (c[2] > b[2])
        c[2] = b[2];
    if (c[3] > b[3])
        c[3] = b[3];
}

extern "C" void func_00448430(float *a, float *b, float t)
{
    float d[4];
    float v[4];
    float r;

    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    v[0] = d[0] * t + a[0x10];
    v[1] = d[1] * t + a[0x11];
    v[2] = d[2] * t + a[0x12];
    r = a[0x1c] + b[0x1c];
    func_004543B0(b + 0x10, *(int *)&r, a + 0x10, v);
}

float func_00448B60(void)
{
    return D_0047700C;
}

extern "C" int func_00448B70(char *p)
{
    char *q = *(char **)(p + 0x94);

    if (q != NULL)
        return *(int *)(q + 0x2c);
    return 0;
}

extern "C" void func_00448B90(char *p, int a)
{
    if (*(char **)(p + 0x8c) == D_0047A2E8) {
        if (!func_0044A870(p + 0x324, a))
            goto fallback;
        return;
    }
    if (*(char **)(p + 0x8c) == D_0047A5E0 && func_0044A870(p + 0xe4, a))
        return;
fallback:
    func_0044A870(p + 0x88, a);
}

extern "C" bool func_004490C0(int *p)
{
    unsigned int i;
    int mode = p[0];
    unsigned int n = p[1];

    for (i = 0; i < n; i++) {
        int *e = (int *)p[i + 2];
        switch (mode) {
        case 0:
            e[1] = 0;
            break;
        case 2:
            e[1] = e[1] != 1;
            break;
        default:
            e[1] = 1;
            break;
        }
    }
    return true;
}

