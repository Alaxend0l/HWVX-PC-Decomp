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
    int type;
    int *unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    PoolItem *items;
    int unk_0x18;
    unsigned int numItems;
    int unk_0x20;
    int state;
    char unk_0x28;
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
extern char *D_0047B800[28];
extern char D_0047BD44[];
extern unsigned int D_0047B8C4;
extern PoolObj **D_00496D70;

extern "C" int func_0046A89F(char *string, const char *format, ...);
extern "C" char func_0044F4D0(char a, int b, int c);
extern "C" int func_00401140(void *p);

void func_0044EFC0(void)
{
    func_00454C50(D_00496DC4);
    D_00496DC4 = NULL;
}

void func_0044EFE0(void)
{
    int i;
    int total;
    int offset;
    PoolObj **base;

    total = 0;
    offset = 0;
    if (D_00496DC4 != NULL) {
        func_00454C50(D_00496DC4);
        D_00496DC4 = NULL;
    }
    for (i = 0; i < 28; i++) {
        D_0047B870[i].count = 0;
        total += D_0047B870[i].size;
    }
    base = (PoolObj **)func_00454B80(total * 4, 0xde, D_0047BD28);
    D_00496DC4 = base;
    for (i = 0; i < 28; i++) {
        D_00496D54[i] = &base[offset];
        offset += D_0047B870[i].size;
    }
    for (i = 0; i < 10; i++)
        D_00496D00[i].unk_0x0 = 0;
    D_00496DC8 = 0;
}

void func_0044F080(int *out, unsigned int max)
{
    unsigned int n = 0;
    int k;
    unsigned int i;
    unsigned int j;
    int id;

    for (k = 0; k < 28; k++) {
        for (i = 0; i < D_0047B870[k].count; i++) {
            for (j = 0; j < D_00496D54[k][i]->numItems; j++) {
                if (n >= max)
                    return;
                id = D_00496D54[k][i]->items[j].id;
                if (id != -1)
                    out[n++] = id;
            }
        }
    }
}

void func_0044F200(char value)
{
    D_00496DC8 = value;
}

char func_0044F210(void)
{
    return D_00496DC8;
}
