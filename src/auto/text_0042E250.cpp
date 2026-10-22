/* 6 functions from 0x0042E250 to 0x0042F090, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Entry_005E7660 {
    char unk_0x000[0x134];
};

struct Sub_0042EFA0 {
    char unk_0x00[0x14];
    int unk_0x14;
};

struct Info_0042EFA0 {
    char unk_0x00[4];
    Sub_0042EFA0 *unk_0x04;
    char unk_0x08[0xa];
    char unk_0x12;
};

struct Obj_0042EFA0 {
    char unk_0x000[0x2c];
    char unk_0x02c;
    char unk_0x02d[0x54 - 0x2d];
    char unk_0x054;
    char unk_0x055[0x84 - 0x55];
    char unk_0x084;
    char unk_0x085[0x15c - 0x85];
    char unk_0x15c;
    char unk_0x15d[0x18c - 0x15d];
    char unk_0x18c;
    char unk_0x18d[0x198 - 0x18d];
    char **unk_0x198;
    char *unk_0x19c;
    short unk_0x1a0;
    short unk_0x1a2;
    int unk_0x1a4;
    char unk_0x1a8;
    char unk_0x1a9;
    char unk_0x1aa[0x1b8 - 0x1aa];
    char unk_0x1b8;
    char unk_0x1b9[0x240 - 0x1b9];
    char unk_0x240;
    char unk_0x241[0x250 - 0x241];
    Info_0042EFA0 *unk_0x250;
};

extern Entry_005E7660 D_005E7660[18];

void func_0042F090(Entry_005E7660 *, int);
