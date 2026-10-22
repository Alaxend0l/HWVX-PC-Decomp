/* 7 functions from 0x00442480 to 0x00442C10, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Rec_00442480 {
    short unk_0x00;
    char unk_0x02[7];
    unsigned char unk_0x09;
    unsigned char unk_0x0a;
    unsigned char unk_0x0b;
    char unk_0x0c[0x28 - 0x0c];
    int unk_0x28;
};

struct Obj_004525A0 {
    char unk_0x000[0xc8];
    Rec_00442480 *unk_0xc8;
};

struct Slot_0053B220 {
    int unk_0x00;
    int unk_0x04[3];
};

extern int D_0053B200;
extern int D_0053B204;
extern int D_0053B208;
extern Slot_0053B220 D_0053B220[2];
extern Slot_0053B220 *D_0053B240;

Obj_004525A0 *func_004525A0(void);
int func_00462F60(short, float, float, int, int);
void func_00462F10(int);
void func_00462F20(int);
void func_00456630(void *);
void func_00456680(void *);
void func_00401090(void);
void func_00461AD0(void);

void func_00442480(void)
{
    Rec_00442480 *r;

    if (func_004525A0() != 0) {
        r = func_004525A0()->unk_0xc8;
        memset(D_0053B220, 0, sizeof(D_0053B220));
        D_0053B200 = 1;
        D_0053B204 = 0;
        if (r != 0) {
            D_0053B208 = func_00462F60(r->unk_0x00, (float)(int)r->unk_0x09, (float)(int)r->unk_0x0a, r->unk_0x0b, r->unk_0x28);
            func_00462F10(D_0053B208);
        }
    }
}

void func_00442500(void)
{
    func_00462F20(D_0053B208);
}

void func_00442510(void)
{
    D_0053B204 = D_0053B204 == 0;
    D_0053B240 = &D_0053B220[D_0053B204];
    func_00401090();
    func_00456630(D_0053B240);
}

void func_00442550(void)
{
    func_00456680(D_0053B240);
    func_00456630(D_0053B240->unk_0x04);
    func_00461AD0();
}

extern int D_0048D7B8;
void func_00442600(Slot_0053B220 *);
void func_00461B10(void);
void func_00461B30(void);
void func_00442580(void)
{
    if (D_0053B200 != 0 && D_0048D7B8 != 0)
        func_00442600(&D_0053B220[D_0053B204 == 0]);
    func_00456680(&D_0053B240->unk_0x04[0]);
    func_00456630(&D_0053B240->unk_0x04[1]);
    func_00461B10();
    func_00456680(&D_0053B240->unk_0x04[1]);
    func_00461B30();
    func_00401090();
    func_00401090();
}

