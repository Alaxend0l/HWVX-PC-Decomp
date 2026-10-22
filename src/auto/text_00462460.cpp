/* 7 functions from 0x00462460 to 0x00462ED2, found by Ghidra. */
#include "common.h"

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
