/* 16 functions from 0x00428480 to 0x00429170, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Entry_0065F460 {
    char active;
    char unk_0x1;
    char unk_0x2;
    char unk_0x3;
    const char *name;
    int id;
    int refs;
    char unk_0x10[0x14 - 0x10];
    int unk_0x14;
    char unk_0x18[0x3c - 0x18];
    int unk_0x3c;
    int unk_0x40;
    char unk_0x44[0x78 - 0x44];
    char unk_0x78;
    char unk_0x79[0xa8 - 0x79];
};

struct Unk_0065EC5C {
    int unk0;
    char unk_0x4[0x78 - 0x4];
};

extern unsigned int D_0047A908[11];
extern Entry_0065F460 *D_0065F460[11];
extern Entry_0065F460 *D_0065F3E0[];
extern int D_0048D1B8;
extern void (*D_006929A0)(void);
extern Unk_0065EC5C D_0065EC5C[];
extern Unk_0065EC5C D_0065F3DC[];

void func_0044DB90(int, int);
void func_00428BA0(void);
char func_00428AE0(unsigned int idx, int type);
