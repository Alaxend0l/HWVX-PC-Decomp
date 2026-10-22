/* 8 functions from 0x00422600 to 0x00423550, found by Ghidra. */
#include "common.h"

extern char D_00692350[];

extern "C" void func_0041B1B0(int a, char *b, int c);
extern "C" void func_0041B470(int a, int b, char *c, char *d);

struct Item_00423120 {
    char unk0[0x30];
    char *unk_0x30;
    int unk_0x34;
};
struct List_00423120 {
    int mode;
    u32 count;
    Item_00423120 *items[1];
};
