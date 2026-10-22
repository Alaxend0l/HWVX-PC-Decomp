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
