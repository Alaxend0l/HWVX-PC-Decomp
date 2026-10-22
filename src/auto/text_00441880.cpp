/* 12 functions from 0x00441880 to 0x00442472, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Info_00441880 {
    char unk_0x00[0x2c];
    float unk_0x2c;
};

struct Obj_00441880 {
    float x, y, z;
    char unk_0x0c[0x78 - 0x0c];
    int unk_0x78;
    char unk_0x7c[0x120 - 0x7c];
    Info_00441880 *info;
};

struct Dir_00441880 {
    char unk_0x00[0x10];
    float x, y, z;
};

extern void *D_0053B244;
extern const char D_0047B1BC[];

extern "C" void func_00441880(Obj_00441880 *, Dir_00441880 *);
extern "C" void func_004420E0(void);
extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);
