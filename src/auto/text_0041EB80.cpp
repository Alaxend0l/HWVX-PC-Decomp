/* 8 functions from 0x0041EB80 to 0x0041FAD0, found by Ghidra. */
#include "common.h"

extern float D_0047700C;
extern float D_00477000;
extern float D_00692378;

struct Entry_0041EC60 {
    u32 unk0;
    u16 unk4;
    char unk6[0x16];
};
struct List_0041EC60 {
    u32 count;
    Entry_0041EC60 *entries;
};

extern "C" void func_00407310(char *p);
extern "C" void func_00448330(char *p);
extern "C" void func_004077E0(char *p, int a, float b);
extern "C" void func_00408290(char *p, char *q);
extern "C" void func_0041E850(char *p, int a, int b, int c);
