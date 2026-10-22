/* 8 functions from 0x00438BD0 to 0x00439680, found by Ghidra. */
#include "common.h"

struct Unk5E66E0 {
    int unk0;
    char unk4[0x78];
};
extern Unk5E66E0 D_005E66E0[];
extern Unk5E66E0 D_005E6EA0[];
extern u16 D_005E6E40;

struct Unk5DC680 {
    u32 unk0;
    char unk4[0x24];
};
struct Unk5DC6A4 {
    u8 unk0;
    char unk1[0x27];
};
extern u32 D_005DC640;
extern u32 D_0048D628;
extern Unk5DC680 D_005DC680[];
extern Unk5DC680 D_005DC684[];
extern Unk5DC680 D_005DC688[];
extern Unk5DC6A4 D_005DC6A4[];

extern "C" void func_00462E00(int, int);
extern "C" void func_00461C10(void);
extern "C" int func_00453550(int, char *, int);
extern "C" void func_00461C30(int, char *, int);
