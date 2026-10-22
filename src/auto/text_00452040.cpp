/* 22 functions from 0x00452040 to 0x00452FB0, found by Ghidra. */
#include "common.h"
struct ElemA_00452040 {
    char unk_0x00[0x18];
    int unk_0x18;
    char unk_0x1c[0x20 - 0x1c];
};

struct ElemB_00452040 {
    char unk_0x00[0x20];
    int unk_0x20;
    char unk_0x24[0x30 - 0x24];
};

struct Sub_00452040 {
    char unk_0x00[0x48];
    unsigned int unk_0x48;
    ElemA_00452040 *unk_0x4c;
    unsigned int unk_0x50;
    ElemB_00452040 *unk_0x54;
    int unk_0x58;
};

struct Vec4_00452040 {
    float x, y, z, w;
};

struct Obj_00452040 {
    char unk_0x00[0x30];
    Vec4_00452040 unk_0x30;
    char unk_0x40[0x48 - 0x40];
    int unk_0x48;
    char unk_0x4c[0x60 - 0x4c];
    int unk_0x60;
    char unk_0x64[0x70 - 0x64];
};

struct Desc_00452660 {
    Vec4_00452040 unk_0x00;
    char unk_0x10[0x10];
    int unk_0x20;
    int unk_0x24;
    int unk_0x28;
    int unk_0x2c;
    int unk_0x30;
    int unk_0x34;
    int unk_0x38;
};

struct Track_00452040 {
    Sub_00452040 *unk_0x00;
    char unk_0x04[0x8 - 0x4];
    int unk_0x08;
    int unk_0x0c;
    int unk_0x10;
    float unk_0x14;
    int unk_0x18;
    char unk_0x1c[0x4];
    int unk_0x20;
    char unk_0x24[0x28 - 0x24];
    int unk_0x28;
    int unk_0x2c;
    unsigned int unk_0x30;
    Obj_00452040 *unk_0x34;
    int unk_0x38;
    int unk_0x3c;
    int unk_0x40;
    int unk_0x44;
    char unk_0x48[0x68 - 0x48];
    int unk_0x68;
    int unk_0x6c;
    char unk_0x70[0x78 - 0x70];
    int unk_0x78;
    char unk_0x7c[0x8c - 0x7c];
    unsigned short unk_0x8c;
    char unk_0x8e[0x2];
    unsigned short unk_0x90;
    char unk_0x92[0x9c - 0x92];
    Track_00452040 *unk_0x9c;
    char unk_0xa0[0xc0 - 0xa0];
    int *unk_0xc0;
};

extern Track_00452040 *D_0049DBA0;
extern int D_0049DBA4;
extern int D_0049DBA8;
extern int D_0049DBAC;
extern int D_0049DBB0;

extern "C" Track_00452040 *func_004525A0(void);
extern "C" void func_0045F9C0(int, int, int, int, int);
extern "C" void func_00466A40(int, int, float, int);
extern "C" void func_00409F50(void);
extern "C" void func_00461C00(int);
extern "C" void func_00427780(void);
extern "C" void func_00428A70(int, int);
extern "C" void func_00450C10(void);
extern "C" void func_004525C0(void);

extern "C" void func_00452040(void)
{
    Track_00452040 *t = func_004525A0();

    if (t) {
        func_0045F9C0(t->unk_0x8c, t->unk_0x90, t->unk_0x0c, t->unk_0x10, 1);
        func_00466A40(*t->unk_0xc0, 0, t->unk_0x14, t->unk_0x18);
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
    func_00466A40(0, 0, 1.0f, 0);
}

extern "C" int func_004524B0(void)
{
    return D_0049DBA0->unk_0x08;
}

extern "C" int func_004524C0(void)
{
    return D_0049DBA0->unk_0x40;
}

extern "C" int func_004524D0(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x08)
        return D_0049DBA0->unk_0x0c + i * 0x60;
    return 0;
}

extern "C" int func_004524F0(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x40)
        return D_0049DBA0->unk_0x44 + i * 0x40;
    return 0;
}

extern "C" int func_00452510(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x10)
        return *(int *)&D_0049DBA0->unk_0x14 + i * 0x20;
    return 0;
}

extern "C" int func_00452530(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x28)
        return D_0049DBA0->unk_0x2c + i * 0x40;
    return 0;
}

extern "C" int func_00452550(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x38)
        return D_0049DBA0->unk_0x3c + i * 0x20;
    return 0;
}

extern "C" int func_00452570(unsigned int i)
{
    if (i < (unsigned int)D_0049DBA0->unk_0x68)
        return D_0049DBA0->unk_0x6c + i * 0x30;
    return 0;
}

extern "C" int func_00452590(void)
{
    return D_0049DBA0->unk_0x78;
}

extern "C" void func_00452650(void)
{
    if (++*(unsigned int *)&D_0049DBA4 == 0)
        func_004525C0();
}

