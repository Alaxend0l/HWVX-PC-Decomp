/* 20 functions from 0x0044D050 to 0x0044E050, found by Ghidra. */
#include "common.h"

struct Obj_0044D050;

struct Funcs_0044D050 {
    void (*unk_0x00)(Obj_0044D050 *, int);
    void (*unk_0x04)(Obj_0044D050 *);
    void (*unk_0x08)(Obj_0044D050 *);
    void (*unk_0x0c)(Obj_0044D050 *);
    void (*unk_0x10)(Obj_0044D050 *);
};

struct Obj_0044D050 {
    char unk_0x00[0x40];
    char unk_0x40[0x30];
    int unk_0x70;
    unsigned int unk_0x74;
    char unk_0x78[0x82 - 0x78];
    char unk_0x82;
    char unk_0x83[0x8c - 0x83];
    Funcs_0044D050 *unk_0x8c;
    char unk_0x90[0xa4 - 0x90];
    Obj_0044D050 *unk_0xa4;
};

extern Obj_0044D050 *D_0053A9D0;
extern int D_0053A9D4[0x12];
extern Obj_0044D050 *D_0048D97C;

Obj_0044D050 *func_0044A810(int *);
void func_0044A790(Obj_0044D050 **, Obj_0044D050 *);
void func_00449AD0(Obj_0044D050 *);
int func_0045E270(char *, int);
void func_0044D860(int, int);
