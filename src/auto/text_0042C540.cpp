/* 10 functions from 0x0042C540 to 0x0042D500, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Slot_0042C540 {
    int id;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    int unk_0x14;
    char unk_0x18[0xc];
    char *unk_0x24;
    char unk_0x28[4];
    int unk_0x2c;
    int unk_0x30;
    char unk_0x34[4];
};

struct PoolEntry_0042C540 {
    int unk_0x0;
    char unk_0x4[0x40];
    short unk_0x44;
    char unk_0x46[2];
};

struct Pool_0042C540 {
    PoolEntry_0042C540 entries[0x800];
    int used;
    unsigned int count;
};

struct Car_0042C540 {
    int id;
    char unk_0x4[0xc5];
    unsigned char color[4];
};

extern Slot_0042C540 D_0064D080[4];
extern Pool_0042C540 *D_0048D5DC;
extern char D_0047ACC0[];

void func_0043FF50(void);
void func_0042D010(int);
void func_00454C50(void *);
void *func_00454B80(int, int, const char *);
