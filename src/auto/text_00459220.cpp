/* 16 functions from 0x00459220 to 0x004595C3, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Pad_00692500 {
    int unk_0x00;
    char unk_0x04[0x18 - 0x4];
    char unk_0x18;
    char unk_0x19[0x1c - 0x19];
};

extern "C" Pad_00692500 D_00692500[4];
extern "C" char D_00693E00;
extern "C" char D_00496FD8[];
extern "C" char D_00692380[];
extern "C" char D_006923C0[];
extern "C" char D_00692400[];
extern "C" char D_00692440[];
extern "C" char D_00692480[];

extern "C" void func_004585A0(int);
