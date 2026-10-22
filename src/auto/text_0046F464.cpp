/* 14 functions from 0x0046F464 to 0x00470413, found by Ghidra. */
#include "common.h"
#include <windows.h>

struct Entry_0046F464 {
    int unk_0x0;
    int unk_0x4;
};

struct Region_0046F464 {
    Region_0046F464 *unk_0x0;
    Region_0046F464 *unk_0x4;
    int unk_0x8;
    Entry_0046F464 *unk_0xc;
    char *unk_0x10;
    int unk_0x14;
    Entry_0046F464 unk_0x18[0x400];
};

struct Header_0046F464 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    void *unk_0xc;
    int *unk_0x10;
};

extern "C" HANDLE D_006D59C4;
extern "C" int D_006D59A8;
extern "C" int D_006D59B8;
extern "C" Header_0046F464 *D_006D59BC;
extern "C" int D_0049D9F0;
extern "C" Region_0046F464 D_0047DA58;
extern "C" Region_0046F464 *D_0047DA5C;
extern "C" int D_0047DA68;
extern "C" Region_0046F464 *D_0047FA78;

extern "C" void func_0046FD53(Region_0046F464 *);
extern "C" void func_0046FDA9(int);

#pragma optimize("s", on)
