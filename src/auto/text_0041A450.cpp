/* 8 functions from 0x0041A450 to 0x0041B410, found by Ghidra. */
#include "common.h"

struct Cell_0041A450 {
    char unk_0x0[0x20];
    int unk_0x20;
    char unk_0x24[0xc];
};

struct Grid_0041A450 {
    float x, y, z;
    char unk_0xc[0x1c];
    float sx, sy, sz;
    char unk_0x34[0x20];
    Cell_0041A450 *cells;
};

struct Obj_0041A450 {
    char unk_0x0[0x3c];
    int unk_0x3c;
    unsigned int count;
    unsigned short *ids;
};

extern Grid_0041A450 **D_0049DBA0;
extern int D_0049DBA4;

char func_0041DBE0(int, Cell_0041A450 *, int);
char *func_00419420(int, int, int);
char func_0041A350(char *, float *);
int func_0041A550(float *, float *, int, int, int, int, float *, float *);
char func_0041A4D0(float *, float *);
