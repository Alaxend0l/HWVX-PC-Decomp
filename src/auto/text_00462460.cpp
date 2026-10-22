/* 7 functions from 0x00462460 to 0x00462ED2, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Name_006D3D44 {
    char s[0x20];
};

struct Entry_006D3D44 {
    Name_006D3D44 name;
    char unk_0x20[4];
    int unk_0x24;
    int unk_0x28;
    float unk_0x2c;
    short unk_0x30;
    short unk_0x32;
    short unk_0x34;
    short unk_0x36;
    short unk_0x38;
    short unk_0x3a;
    short unk_0x3c;
    short unk_0x3e;
};

struct Rec_00462D80 {
    short unk_0x00;
    short unk_0x02;
    short unk_0x04;
    short unk_0x06;
    int unk_0x08;
    int unk_0x0c;
};

extern Entry_006D3D44 *D_006D3D44;
extern char D_006C9A78;
extern char D_0047CCD0[];

unsigned short func_00462210(void);
int func_0046A89F(char *, const char *, ...);
void func_004678B0(int, int);
void func_00467E80(unsigned short);
Rec_00462D80 *func_00462D80(Rec_00462D80 *, int);

Rec_00462D80 *func_00462D80(Rec_00462D80 *r, int n)
{
    Entry_006D3D44 *e;
    e = &D_006D3D44[n];
    D_006D3D44[n].unk_0x32 = r->unk_0x04;
    D_006D3D44[n].unk_0x30 = r->unk_0x02;
    D_006D3D44[n].unk_0x34 = r->unk_0x06;
    D_006D3D44[n].unk_0x24 = r->unk_0x08;
    D_006D3D44[n].unk_0x28 = r->unk_0x0c;
    D_006D3D44[n].unk_0x38 = r->unk_0x00;
    func_004678B0(n, 1);
    r++;
    return r;
}

void func_00462E00(int n, short v)
{
    D_006D3D44[(unsigned short)n].unk_0x3e = v;
    func_00467E80(n);
}

unsigned short func_00462CE0(Rec_00462D80 **pp)
{
    Name_006D3D44 name;
    unsigned short n;
    int i;

    n = func_00462210();
    i = n;
    *pp = func_00462D80(*pp, i);
    func_0046A89F(name.s, D_0047CCD0, i);
    D_006D3D44[i].name = name;
    D_006D3D44[i].unk_0x36++;
    D_006D3D44[i].unk_0x3c = D_006C9A78;
    D_006D3D44[i].unk_0x2c = 0.25f;
    D_006D3D44[i].unk_0x3a = 1;
    D_006D3D44[i].unk_0x3e = 0;
    return n;
}
