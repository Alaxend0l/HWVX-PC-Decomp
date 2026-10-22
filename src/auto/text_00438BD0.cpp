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

extern "C" void func_00439310(int i)
{
    if (i >= 0)
        D_005E66E0[i].unk0 = 0;
}

extern "C" void func_00439440(int a)
{
    int *p;
    char *s;

    func_00461C10();
    p = (int *)D_005E66E0;
    do {
        if (p[0] != 0 && ((char *)p[0])[1] != 0) {
            s = (char *)(p - 0x18);
            if (p[1] != 0)
                s = (char *)p[1] + 0x40;
            if (func_00453550(a, s, p[-8]) != 1)
                func_00461C30(p[-0xb], s, p[-8]);
        }
        p += 0x1f;
    } while (p < (int *)D_005E6EA0);
}

extern "C" bool func_004395D0(u32 *obj, u32 n)
{
    u32 i = D_005DC640;

    if (i >= 0x400) {
        obj[0x26] = 0xffffffff;
        return false;
    }
    if (obj[0x26] < i && D_005DC688[obj[0x26]].unk0 == (u32)obj) {
        *(bool *)&D_005DC6A4[obj[0x26]].unk0 = true;
        return true;
    }
    D_005DC688[i].unk0 = (u32)obj;
    D_005DC680[i].unk0 = n;
    D_005DC684[i].unk0 = D_0048D628 % n;
    *(bool *)&D_005DC6A4[i].unk0 = true;
    obj[0x26] = i;
    D_005DC640++;
    D_0048D628 += 5;
    if (D_0048D628 == 0xffffffff)
        D_0048D628 = 0;
    return true;
}

extern "C" void func_00439210(int a)
{
    D_005E6E40 = a;
    func_00462E00(a, 1);
}
