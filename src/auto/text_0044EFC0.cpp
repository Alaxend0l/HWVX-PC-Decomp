/* 15 functions from 0x0044EFC0 to 0x0044FFC0, found by Ghidra. */
#include "common.h"

extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);

struct PoolInfo {
    unsigned int count;
    int size;
    int unk_0x8;
};

struct PoolItem {
    char unk_0x0[0x10];
    int id;
    int unk_0x14;
};

struct PoolObj {
    char unk_0x0[0x14];
    PoolItem *items;
    int unk_0x18;
    unsigned int numItems;
};

struct PoolSlot {
    int unk_0x0;
    int unk_0x4;
};

extern PoolInfo D_0047B870[28];
extern char D_0047BD28[];
extern PoolSlot D_00496D00[10];
extern PoolObj **D_00496D54[28];
extern void *D_00496DC4;
extern char D_00496DC8;
