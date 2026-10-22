/* 30 functions from 0x004617F0 to 0x00462460, found by Ghidra. */
#include "common.h"
#include <string.h>

extern int D_006D4D04;
extern int D_0049D7D4;
extern float D_006D4D08;
extern int D_006D4D10;
extern unsigned char D_006D4D16;
extern unsigned char D_006D4D17;
extern unsigned char D_006D4D18;
extern unsigned char D_006D4D19;
extern unsigned char D_006D4D1A;
extern unsigned char D_006D4D1C;
extern int D_006D4D20;
extern int D_006D4D00;
extern int D_006D4CFC;
extern int D_006D4CF8;

struct Vec4_004617F0 {
    float x, y, z, w;
};

struct Light_006D4CA0 {
    Vec4_004617F0 unk_0x0;
    float unk_0x10;
    int unk_0x14;
};

extern Light_006D4CA0 D_006D4CA0[3];

struct LightSet_006D4CA0 {
    Light_006D4CA0 l[3];
    char unk_0x48[0x2e];
    unsigned char unk_0x76;
    unsigned char unk_0x77;
    unsigned char count;
};
extern Vec4_004617F0 D_006D4CE8;
void func_00453470(void *);

struct Slot_006D3E80 {
    char unk_0x0[0x2d0];
};

extern Slot_006D3E80 D_006D3E80[];
extern Slot_006D3E80 *D_006D3E60;

void func_00401090(void);
void func_00453100(void);
void func_00461B50(void);
void func_004665B0(void);
void func_004564B0(void);
void func_00462ED0(void);
int func_004620B0(void);
int func_0045E910(void);
void func_0045E970(void);
void func_00462100(void);
void func_00465490(void);
void func_00465590(int a, int b, int c, int d, int e, int f);
extern unsigned char D_006C99E4;
extern unsigned char D_006C99E5;
extern unsigned char D_006C99E6;
extern unsigned char D_006C99E7;
extern unsigned char D_0049D7D0;
extern unsigned char D_0049D7D1;
extern unsigned char D_006D3D4C;
extern int D_006D4D40[0x280];
extern "C" float func_004535B0(void *a, void *b);
extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern char D_006D4000[];
extern char D_006D4E10[];
extern char D_006D42D0[];
extern char D_006D45A0[];
extern char D_0047CC70[];
extern int D_006D3D48;
extern void *D_006D3D44;
void func_00461B50(void)
{
    D_006D4D18 = 0;
    D_006D4D04 = 1;
    D_006D4D08 = 64.0f;
    D_006D4D19 = 0xff;
    D_006D4D16 = 1;
    D_006D4D17 = 1;
    D_006D4D1A = 0xff;
    D_006D4D1C = 0;
    D_006D4D10 = 0;
    D_006D4D20 = 0;
}

extern "C" float func_004535B0(void *a, void *b);
extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern char D_006D4000[];
extern char D_006D4E10[];
extern char D_006D42D0[];
extern char D_006D45A0[];
extern char D_0047CC70[];
extern int D_006D3D48;
extern void *D_006D3D44;
char *func_00461D50(void)
{
    return (char *)&D_006D3E80[D_0049D7D4];
}

int func_00461FE0(int *out)
{
    int n = 0;
    int i = 0;
    char *p = D_006D4000;
    do {
        if (D_006D3D4C & (unsigned char)(1 << i)) {
            int *s = (int *)p;
            out[0] = s[0];
            out[1] = s[1];
            out[2] = s[2];
            out[3] = s[3];
            n++;
            out += 4;
        }
        p += 0x2d0;
        i++;
    } while (p < D_006D4E10);
    return n;
}

float func_00462040(void *a)
{
    float f;
    float g;
    if (D_006D3D4C == 1)
        return func_004535B0(a, D_006D4000);
    f = func_004535B0(a, D_006D42D0);
    g = func_004535B0(a, D_006D45A0);
    if (f < g)
        return f;
    return g;
}

int func_00461A10(void)
{
    func_00453100();
    func_00461B50();
    func_004665B0();
    func_004564B0();
    func_00462ED0();
    D_006C99E7 = 0xff;
    D_006C99E6 = 0xff;
    D_006C99E5 = 0xff;
    D_006C99E4 = 0xff;
    D_0049D7D1 = 0;
    D_0049D7D0 = 0;
    D_006D3D4C = 1;
    memset(&D_006D4D40, 0, 0xa00);
    if (func_004620B0() == 0)
        return 0;
    return func_0045E910() != 0;
}

void func_00461A80(void)
{
    func_00401090();
    func_0045E970();
    func_00462100();
    func_00465490();
}

void func_00461AA0(int a, int b, int c, int d, int e, int f)
{
    func_00465590(a, b, c, d, e, f);
}

extern int D_006D4D04;
extern int D_006D3D60[0x40];
extern int D_0049D7D4;
void func_00466CA0(void);
void func_0045E990(void);
char *func_00461D50(void);
void func_00460B30(int a);
void func_00460820(int a);
void func_00466D60(void);
void func_004664A0(void);
void func_00461AD0(void)
{
    int *p;
    int i;

    D_006D4D04 = 0;
    func_00466CA0();
    func_0045E990();
    p = D_006D3D60;
    for (i = 0x40; i != 0; i--)
        *p++ = 0;
    func_00460B30(*(int *)(func_00461D50() + 0x270));
    func_00460820(0);
}

void func_00461B10(void)
{
    func_00466D60();
    D_0049D7D1 = 0;
    D_0049D7D0 = 0;
}

void func_00461B30(void)
{
    func_004664A0();
    memset(D_006D4D40, 0, sizeof(D_006D4D40));
}

void func_00461BA0(int flags)
{
    int *p = &D_006D4D04;
    *p |= flags;
}

void func_00461BC0(int flags)
{
    D_006D4D04 &= ~flags;
}

extern "C" void func_00461BE0(unsigned char v)
{
    D_006D4D1C = v;
}

extern "C" void func_00461BF0(int v)
{
    D_006D4D10 = v;
}

extern "C" void func_00461C00(int v)
{
    D_006D4D20 = v;
}

extern "C" void func_00461C10(void)
{
    if (D_006D4D18) {
        D_006D4D18 = 0;
        D_006D4D16 = 1;
    }
}

extern LightSet_006D4CA0 D_006D4CA0_set;
extern "C" void func_00461C30(int a, Vec4_004617F0 *v, float f)
{
    if (D_006D4CA0_set.count < 3) {
        D_006D4CA0_set.l[D_006D4CA0_set.count].unk_0x14 = a;
        D_006D4CA0_set.l[D_006D4CA0_set.count].unk_0x0 = *v;
        D_006D4CA0_set.l[D_006D4CA0_set.count].unk_0x10 = f;
        D_006D4CA0_set.unk_0x76 = 1;
        D_006D4CA0_set.count++;
    }
}

extern int D_006D4CEC;
extern int D_006D4CF0;
extern int D_006D4CF4;
extern "C" void func_00461CB0(int a, Vec4_004617F0 *v)
{
    D_006D4CF8 = a;
    if (v) {
        Vec4_004617F0 *d = (Vec4_004617F0 *)&D_006D4CE8;
        d->x = v->x;
        d->y = v->y;
        d->z = v->z;
        d->w = v->w;
        func_00453470(d);
    }
    D_006D4D16 = 1;
}

extern "C" void func_00461D00(int v)
{
    D_006D4D00 = v;
}

extern "C" void func_00461D10(int v)
{
    D_006D4CFC = v;
}

void func_00461D20(int id)
{
    D_0049D7D4 = id;
    D_006D3E60 = &D_006D3E80[id];
}

int func_00461D40(void)
{
    return D_0049D7D4;
}

void func_004620A0(void)
{
    func_00401090();
}
