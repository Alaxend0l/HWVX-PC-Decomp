/* 4 functions from 0x00418BE0 to 0x004194B0, found by Ghidra. */
#include "common.h"

struct Grid_0049DBA0 {
    char unk_0x00[0x20];
    char *unk_0x20; /* 0x50-byte cells */
    char unk_0x24[0x10];
    int unk_0x34;
    int unk_0x38;
    int unk_0x3c;
    int *unk_0x40;
};

extern Grid_0049DBA0 **D_0049DBA0;

int func_00453330(int, int, void *);
int func_0041ACE0(int, void *, int, int);
int func_004193D0(int, int, int);
