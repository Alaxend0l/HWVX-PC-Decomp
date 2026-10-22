/* 4 functions from 0x0042F090 to 0x0042FA50, found by Ghidra. */
#include "common.h"

struct Elem_0042F090 {
    char unk_0x000[0x254];
    char *unk_0x254;
    char unk_0x258[0x28];
    int unk_0x280;
    char unk_0x284[0x74];
};

struct Entry_0042F090 {
    unsigned int unk_0x00;
    char unk_0x04[0x1c];
    short *unk_0x20;
    char unk_0x24[0x51];
    unsigned char unk_0x75;
    char unk_0x76[5];
    char unk_0x7b;
    char unk_0x7c;
    char unk_0x7d;
    char unk_0x7e[2];
    Elem_0042F090 *unk_0x80;
    char unk_0x84[4];
    void (*unk_0x88)(void *);
    char unk_0x8c[0xa8];
};

struct Msg_0042F090 {
    int unk_0x0;
    short unk_0x4;
    short unk_0x6;
};

extern Entry_0042F090 D_005E7660[18];
extern int D_0069236C;
extern int D_00692370;
extern int D_0048D61C;
extern char *D_0048D614;
extern char *D_0048D608;

void func_0042FA50(Entry_0042F090 *, int);
