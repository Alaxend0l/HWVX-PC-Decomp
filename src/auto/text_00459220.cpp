/* 16 functions from 0x00459220 to 0x004595C3, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Pad_00692500 {
    int unk_0x00;
    char unk_0x04[0x18 - 0x4];
    char unk_0x18;
    char unk_0x19[0x1c - 0x19];
};

extern "C" Pad_00692500 D_00692500[4];

struct Slot_00692518 {
    char unk_0x0;
    char unk_0x1[0x1c - 0x1];
};

extern "C" Slot_00692518 D_00692518[4];
extern "C" Slot_00692518 D_00692588[];
extern "C" char D_00693E00;
extern "C" char D_00496FD8[];
extern "C" char D_00692380[];
extern "C" char D_006923C0[];
extern "C" char D_00692400[];
extern "C" char D_00692440[];
extern "C" char D_00692480[];

struct Name_0047C470 {
    const char *unk_0x0;
    int unk_0x4;
};

struct Value_0047C474 {
    int unk_0x0;
    const char *unk_0x4;
};

extern "C" Name_0047C470 D_0047C470[];
extern "C" Value_0047C474 D_0047C474[];
extern "C" unsigned int D_0047C528;
extern "C" int D_00693E04;

extern "C" void func_004585A0(int);
extern "C" int func_00475660(const char *, const char *);
extern "C" void func_0045CD20(void);
extern "C" void func_00401090(...);
extern "C" void func_00459580(void);
extern "C" void func_00459C40(void);
extern "C" char func_00459CC0(void);
extern "C" char func_0045B400(void);
extern "C" char func_00459EC0(void);
extern "C" char func_00459500(void);
extern "C" char func_00459C00(void);
extern "C" char func_00459CF0(void);
extern "C" char func_0045B440(void);
extern "C" char func_00459EF0(void);
extern "C" char func_00459530(void);
extern "C" char func_00401070(void);
extern "C" char D_00497140;
extern "C" int D_00693E08;

extern "C" void func_00459220(void)
{
    int i = 0;
    int n = 4;
    Pad_00692500 *p = D_00692500;
    do {
        if (p->unk_0x18 != -1) {
            int v = p->unk_0x00 << 8;
            v |= p->unk_0x18;
            func_004585A0((v << 8) | i);
        }
        i++;
        p++;
    } while (--n);
}

extern "C" void func_00459580(void)
{
    D_00693E04 = 0;
    func_0045CD20();
}

extern "C" void func_00459260(const char *s)
{
    if (s != NULL)
        strcpy(D_00496FD8, s);
    else
        D_00496FD8[0] = 0;
}

#pragma optimize("t", on)
extern "C" void func_004592A0(const char *a, const char *b, const char *c, const char *d, const char *e)
{
    strcpy(&D_00692380[0], a);
    strcpy(&D_006923C0[0], b);
    strcpy(&D_00692400[0], c);
    strcpy(&D_00692440[0], d);
    strcpy(&D_00692480[0], e);
}

extern "C" int func_00459360(unsigned int n, const unsigned char *p)
{
    int sum = 0;
    unsigned int i;
    for (i = 0; i < n; i++)
        sum += p[i] + 1;
    return sum;
}

extern "C" int func_00459390(void)
{
    int i = 0;
    Slot_00692518 *p;
    for (p = D_00692518; p < D_00692588; p++, i++) {
        if (p->unk_0x0 == -1)
            break;
    }
    if (i == 4)
        return -1;
    return i;
}

extern "C" int func_004593C0(const char *name)
{
    unsigned int i;
    for (i = 0; i < D_0047C528; i++) {
        if (func_00475660(name, D_0047C470[i].unk_0x0) == 0)
            return D_0047C474[i].unk_0x0;
    }
    return 0;
}

extern "C" char func_00459410(void)
{
    if (D_00497140 == 0) {
        D_00693E04 = 0;
        D_00693E08 = 0;
        if (func_00459CC0() && func_0045B400() && func_00459EC0() && func_00459500() && func_00459C00()) {
            D_00497140 = 1;
            return 1;
        }
    }
    return D_00497140;
}

extern "C" char func_00459470(void)
{
    D_00693E04 = 0;
    D_00693E08 = 0;
    if (func_00459CF0() && func_0045B440() && func_00459EF0() && func_00459530() && func_00401070())
        return 1;
    return 0;
}

extern "C" void func_004594B0(void)
{
    D_00693E04 = 0;
    D_00693E08 = 0;
    func_00401090();
    func_00401090();
    func_00459580();
    func_00459C40();
    D_00497140 = 0;
}

#pragma optimize("", on)
extern "C" void func_00459590(char v)
{
    D_00693E00 = v;
}

extern "C" void func_004595A0(int a, int b)
{
    func_00401090(a, b, 0x666, 0x28);
}

