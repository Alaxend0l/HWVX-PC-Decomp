/* 8 functions from 0x00464CA0 to 0x00465590, found by Ghidra. */
#include "common.h"

struct Name_006D4D40 {
    char name[0x50];
};
extern Name_006D4D40 D_006D4D40[];
extern Name_006D4D40 D_006D5740[];
extern u32 D_006D4D14;
extern u8 D_006C99E4;
extern u8 D_006C99E5;
extern u8 D_006C99E6;
extern u8 D_006C99E7;
extern float D_00477000;
extern float D_0047700C;
extern float D_004770BC;

static inline u8 FloatToByte(float x)
{
    return (u8)(x * D_004770BC + D_004770BC);
}

extern "C" u32 func_004639D0(char *s, int a, float b, int c);
extern "C" float func_004532E0(float x);

extern "C" void func_00464FC0(float *v)
{
    float len = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    float inv;

    if (len == D_00477000) {
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        return;
    }
    inv = D_0047700C / func_004532E0(len);
    v[0] = inv * v[0];
    v[1] = inv * v[1];
    v[2] = inv * v[2];
}

extern "C" void func_00465030(float *v, u8 *out)
{
    float f;

    f = v[0];
    f *= D_004770BC;
    f += D_004770BC;
    out[0] = (u8)f;
    f = v[1];
    f *= D_004770BC;
    f += D_004770BC;
    out[1] = (u8)f;
    f = v[2];
    f *= D_004770BC;
    f += D_004770BC;
    out[2] = (u8)f;
}

extern "C" void func_00464F10(void)
{
    float total = 0.0f;
    Name_006D4D40 *p = D_006D4D40;
    char buf[0x51];

    do {
        *(Name_006D4D40 *)buf = *p;
        buf[0x50] = 0;
        if (buf[0] != 0)
            total += (float)func_004639D0(buf, 0, total, D_006D4D14 & 0xffff);
        p++;
    } while ((int)p < (int)D_006D5740);
}

extern "C" void func_00464F90(u8 a, u8 b, u8 c, u8 d)
{
    D_006C99E4 = a;
    D_006C99E5 = b;
    D_006C99E6 = c;
    D_006C99E7 = d;
}

