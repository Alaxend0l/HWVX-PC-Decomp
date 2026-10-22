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

extern "C" u32 func_004639D0(char *s, int a, float b, int c);
extern "C" float func_004532E0(float x);

extern "C" void func_00464F10(void)
{
    float total = 0.0f;
    Name_006D4D40 *p;
    struct {
        Name_006D4D40 n;
        char end;
    } buf;

    for (p = D_006D4D40; p < D_006D5740; p++) {
        buf.n = *p;
        buf.end = 0;
        if (buf.n.name[0] != 0)
            total += (float)func_004639D0(buf.n.name, 0, total, D_006D4D14 & 0xffff);
    }
}

extern "C" void func_00464F90(u8 a, u8 b, u8 c, u8 d)
{
    D_006C99E4 = a;
    D_006C99E5 = b;
    D_006C99E6 = c;
    D_006C99E7 = d;
}

