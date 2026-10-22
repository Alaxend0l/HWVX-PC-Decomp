/* 12 functions from 0x00462EE0 to 0x00463DC0, found by Ghidra. */
#include "common.h"

struct Sub_006C9C04 {
    float unk_0x00;
    char unk_0x04[4];
    float unk_0x08;
    char unk_0x0c[4];
    u8 unk_0x10;
    u8 unk_0x11;
    char unk_0x12[2];
};

struct Chan_006C9C04 {
    char unk_0x00[0xc];
    u16 unk_0x0c;
    char unk_0x0e[2];
    char active;
    char unk_0x11;
    s16 refs;
    Sub_006C9C04 sub[128];
};

struct Entry_006D3D44 {
    char unk_0x00[0x32];
    u16 unk_0x32;
    char unk_0x34[0x40 - 0x34];
};

extern Chan_006C9C04 D_006C9C04[16];
extern int D_006C9C00;
extern u16 D_006D4D14;
extern Entry_006D3D44 *D_006D3D44;

void func_00462F10(u16 v)
{
    D_006D4D14 = v;
}
