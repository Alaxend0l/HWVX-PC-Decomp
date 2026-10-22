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

extern "C" Name_0047C470 D_0047C470[];
extern "C" unsigned int D_0047C528;
extern "C" int D_00693E04;

extern "C" void func_004585A0(int);
extern "C" int func_00475660(const char *, const char *);
extern "C" void func_0045CD20(void);

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
#pragma optimize("", on)
extern "C" void func_00459590(char v)
{
    D_00693E00 = v;
}
