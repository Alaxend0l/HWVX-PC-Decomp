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

int func_004193D0(int x, int y, int z)
{
    Grid_0049DBA0 *g = *D_0049DBA0;
    if (x >= 0 && x < g->unk_0x34 && y >= 0 && y < g->unk_0x38 && z >= 0 && z < g->unk_0x3c)
        return (g->unk_0x3c * y + z) * g->unk_0x34 + x;
    return -1;
}

char *func_00419420(int x, int y, int z)
{
    int i = func_004193D0(x, y, z);
    if (i == -1)
        return (*D_0049DBA0)->unk_0x20;
    return (*D_0049DBA0)->unk_0x20 + (*D_0049DBA0)->unk_0x40[i] * 0x50;
}

void func_00419470(int a, int b, int c, int d)
{
    char buf[16];
    func_00453330(b, a, buf);
    func_0041ACE0(a, buf, c, d);
}
