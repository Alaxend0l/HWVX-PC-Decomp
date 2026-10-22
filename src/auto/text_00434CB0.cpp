/* 6 functions from 0x00434CB0 to 0x00435B10, found by Ghidra. */
#include "common.h"

struct Entry_00435840 {
    int unk_0x00;
    int unk_0x04;
    char unk_0x08[0x10 - 0x08];
    int unk_0x10;
    char unk_0x14[0x77 - 0x14];
    char unk_0x77;
    char unk_0x78[0x134 - 0x78];
};

extern unsigned int D_005E7648;
extern int D_005E7600[];
extern Entry_00435840 D_005E7660[];

void func_004358A0(Entry_00435840 *);
