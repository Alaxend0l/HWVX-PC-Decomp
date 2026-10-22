/* 30 functions from 0x0043B2A0 to 0x0043BF20, found by Ghidra. */
#include "common.h"

struct Bink_0048D64C {
    char unk_0x00[0x8];
    unsigned unk_0x08;
    unsigned unk_0x0c;
    char unk_0x10[0x34 - 0x10];
    char unk_0x34[4];
};

struct BinkBuf_0048D650 {
    char unk_0x00[0x4];
    int unk_0x04;
    char unk_0x08[0x10 - 0x08];
    int unk_0x10;
    int unk_0x14;
    int unk_0x18;
};

struct Elem_0043B460 {
    char unk_0x00[0x60];
};

struct List_0043B460 {
    Elem_0043B460 *items;
    unsigned count;
};

extern Bink_0048D64C *D_0048D64C;
extern BinkBuf_0048D650 *D_0048D650;
extern char D_0048D760;
extern List_0043B460 *D_0048D768;
extern void **D_0048D76C;
extern char D_0047B020[];

extern "C" __declspec(dllimport) int __stdcall binkw32_0(Bink_0048D64C *);
extern "C" __declspec(dllimport) int __stdcall binkw32_3(BinkBuf_0048D650 *);
extern "C" __declspec(dllimport) int __stdcall binkw32_4(Bink_0048D64C *, int, int, int, int, int, int);
extern "C" __declspec(dllimport) int __stdcall binkw32_5(BinkBuf_0048D650 *);
extern "C" __declspec(dllimport) int __stdcall binkw32_6(Bink_0048D64C *, int);
extern "C" __declspec(dllimport) int __stdcall binkw32_7(BinkBuf_0048D650 *, void *, int);
extern "C" __declspec(dllimport) void __stdcall binkw32_8(Bink_0048D64C *);
extern "C" __declspec(dllimport) void __stdcall binkw32_10(Bink_0048D64C *);

extern "C" void *func_00454B80(unsigned size, int tag, const char *file);
extern "C" void *func_0042D620(int type, unsigned index, void *a, void *b);
