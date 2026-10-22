/* 22 functions from 0x00452040 to 0x00452FB0, found by Ghidra. */
#include "common.h"
struct Track_00452040 {
    char unk_0x00[0x8];
    int unk_0x08;
    int unk_0x0c;
    int unk_0x10;
    float unk_0x14;
    int unk_0x18;
    char unk_0x1c[0x4];
    int unk_0x20;
    char unk_0x24[0x40 - 0x24];
    int unk_0x40;
    char unk_0x44[0x8c - 0x44];
    unsigned short unk_0x8c;
    char unk_0x8e[0x2];
    unsigned short unk_0x90;
    char unk_0x92[0xc0 - 0x92];
    int *unk_0xc0;
};

extern Track_00452040 *D_0049DBA0;
extern int D_0049DBA8;
extern int D_0049DBAC;
extern int D_0049DBB0;

extern "C" Track_00452040 *func_004525A0(void);
extern "C" void func_0045F9C0(int, int, int, int, int);
extern "C" void func_00466A40(unsigned char, int, float, int);
extern "C" void func_00409F50(void);
extern "C" void func_00461C00(int);
extern "C" void func_00427780(void);
extern "C" void func_00428A70(int, int);
extern "C" void func_00450C10(void);

extern "C" void func_00452040(void)
{
    Track_00452040 *t = func_004525A0();

    if (t) {
        func_0045F9C0(t->unk_0x8c, t->unk_0x90, t->unk_0x0c, t->unk_0x10, 1);
        func_00466A40(*(float *)t->unk_0xc0, 0, t->unk_0x14, t->unk_0x18);
        func_00409F50();
        func_00461C00(t->unk_0x20);
    } else {
        func_00461C00(0);
    }
}

extern "C" void func_004520B0(void)
{
    func_00427780();
    func_00428A70(4, 1);
    func_00428A70(5, 1);
    func_00428A70(6, 1);
    func_00428A70(0, 1);
    func_00428A70(2, 1);
    func_00428A70(8, 1);
    func_00428A70(1, 1);
    func_00428A70(9, 1);
    D_0049DBA0 = 0;
    D_0049DBA8 = 0;
    D_0049DBAC = 0;
    D_0049DBB0 = 0;
    func_00450C10();
    func_00466A40(0.0f, 0, 1.0f, 0);
}

extern "C" int func_004524B0(void)
{
    return D_0049DBA0->unk_0x08;
}

extern "C" int func_004524C0(void)
{
    return D_0049DBA0->unk_0x40;
}

