/* 11 functions from 0x0045C9A0 to 0x0045D930, found by Ghidra. */
#include "common.h"
struct Iface_0045D {
    void **vtbl;
};

struct Entry18_0045D {
    Iface_0045D *unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    int unk_0x14;
};

struct Entry24_0045D {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    Entry18_0045D *unk_0xc;
    char unk_0x10[0x14];
};

struct Voice_0045D {
    char unk_0x0[0x2];
    unsigned char unk_0x2;
    char unk_0x3[0x12];
    char unk_0x15;
    char unk_0x16[0x3a];
};

extern Entry18_0045D D_0049BBE8[254];
extern Entry24_0045D D_0049AEFC[64];
extern Voice_0045D D_00692A00[64];
extern void (*D_006929F4)(Voice_0045D *);

void func_0045D1C0(Voice_0045D *, int);
void func_0045D630(void *, int);
