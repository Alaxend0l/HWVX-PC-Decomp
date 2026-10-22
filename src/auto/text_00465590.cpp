/* 12 functions from 0x00465590 to 0x00466590, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <string.h>

struct DisplayMode {
    int id;
    int unk_4[5];
};

extern "C" char D_006C9AC0;
extern "C" DEVMODEA D_006C9AE0;
extern "C" char D_0047D11C[];
extern "C" int D_006C99FC;
extern "C" DisplayMode D_006C9A00[];
extern "C" int D_006C9A78;

extern "C" char *func_0046B970(const char *str, int ch);
extern "C" char *func_0046B1E0(const char *str1, const char *str2);
