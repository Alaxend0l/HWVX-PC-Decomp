/* 11 functions from 0x00429170 to 0x00429FA0, found by Ghidra. */
#include "common.h"
#include <string.h>

extern char D_0047AB18;
extern char D_0047A778[];
extern int D_0048D4C4;
extern char D_0048D1C5;
extern unsigned int D_0048D358;
struct Guid_00429 {
    int unk_0x0[4];
};

struct Guid2_00429 {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

#pragma pack(push, 2)
struct Info_00429 {
    char unk_0x0[0x2];
    Guid_00429 unk_0x2;
    unsigned char unk_0x12[13];
};
#pragma pack(pop)

extern "C" Info_00429 *func_0042B040(int a);

static inline void CopyGuid_00429(Guid_00429 *d, const Guid_00429 *s)
{
    *d = *s;
}

static inline void ZeroGuid_00429(Guid_00429 *d)
{
    memset(d, 0, sizeof(Guid_00429));
}

extern int D_0065E2A0[4];
extern int D_0065E2B0[4];
extern int D_0065E2C0;
extern int D_0065E2C4;
extern int D_0065E2C8;
extern int D_0065E2CC;
extern int D_0065E2D0;
extern int D_0065E2D4[];
extern int D_0065E2E4[];
extern int D_0065E2F4[];
extern char D_0065E304[];
extern char D_0065E30C;
struct Arrays_0065E2D4 {
    int a[4];
    int b[4];
    int c[4];
    char d[4];
};
extern int D_0065E310;
extern int D_0065E314;
extern int D_0065E318;
extern int D_0065E31C;
extern int D_0065E320;
extern char D_0065E324;
extern int D_0065E328;
extern int D_0065E32C;
extern char D_0065E330;
extern char D_0065E339;
extern char D_0048D4C0;
extern int D_0065E33C;
extern int D_0064D160[0x62];
extern char D_0064D400[];
extern char D_0064FA20[];
extern char D_0064D164;
extern unsigned char D_0064D165;
extern unsigned char D_0064D166;
struct D_0064D148_t { char data[32]; };
extern D_0064D148_t D_0064D148[];
extern char *D_0064DD34;
extern char *D_0064DD38;
extern char D_0064D300[];
extern char D_0064DD40[];
extern int D_0047AAF4;
extern int D_0047AAF8;
extern int D_0047AB10;
extern int D_0047AB14;
extern "C" void func_00429FA0(int a, int b, int c);
extern "C" void func_00429E60(void);
extern "C" void func_00429E80(void);
extern "C" void func_00429DD0(void);
extern "C" void func_00429F10(int a);
extern "C" int func_00429EA0(void);
extern "C" int func_004287E0(void *name, int a, int b, int c);
extern "C" int func_00428C10(int a, int b, int c);
extern "C" int func_004216C0(int a, int b);
extern "C" unsigned char func_00440160(void);
extern "C" char *func_00440180(unsigned int i);
extern "C" int func_00429EC0(void);

extern "C" void func_00429E60(void)
{
    D_0065E2C0 = 1;
    D_0065E2C4 = 1;
    D_0065E2C8 = 1;
    D_0065E2CC = 1;
}

extern "C" void func_00429E80(void)
{
    int *p;

    p = D_0065E2B0;
    do {
        p[-4] = -1;
        *p = -1;
        p++;
    } while (p < &D_0065E2C0);
}

extern "C" void func_00429DD0(void)
{
    int i;
    Arrays_0065E2D4 *s = (Arrays_0065E2D4 *)D_0065E2D4;
    int (*x)[4] = (int (*)[4])D_0065E2D4;

    D_0065E2D0 = 1;
    for (i = 0; i < 4; i++) {
        x[0][i] = 0;
        x[1][i] = 0;
        x[2][i] = 0;
        s->d[i] = 0;
    }
    D_0065E32C = 1;
    D_0065E330 = 1;
    D_0065E339 = 1;
    D_0065E30C = 0;
    D_0065E310 = 0;
    D_0065E314 = 300000;
    D_0065E318 = 10;
    D_0065E31C = 1000;
    D_0065E320 = 3;
    D_0065E324 = 0;
    D_0065E328 = 3;
}

extern "C" void func_00429F10(int a)
{
    char *dev = (char *)func_00429EC0();
    Info_00429 *info = func_0042B040(a);

    if (dev != NULL && *(int *)(dev + 0x3c) != 0) {
        int *g = (int *)((int *)**(int **)*(int *)(dev + 0x40))[1];
        int *d = (int *)&info->unk_0x2;
        d[0] = g[0];
        d[1] = g[1];
        d[2] = g[2];
        d[3] = g[3];
        info->unk_0x12[0] = 10;
        info->unk_0x12[1] = 11;
        info->unk_0x12[2] = 9;
        info->unk_0x12[3] = 7;
        info->unk_0x12[4] = 8;
        info->unk_0x12[5] = 6;
        info->unk_0x12[6] = 4;
        info->unk_0x12[7] = 5;
        info->unk_0x12[8] = 3;
        info->unk_0x12[9] = 2;
        info->unk_0x12[10] = 12;
        info->unk_0x12[11] = 13;
        info->unk_0x12[12] = 1;
        return;
    }
    memset(info->unk_0x2.unk_0x0, 0, 16);
}

extern "C" int func_00429EA0(void)
{
    unsigned char *p = (unsigned char *)func_00429EC0();
    if (p)
        return p[1];
    return 0;
}

extern "C" int func_00429EC0(void)
{
    if (D_0047AB18) {
        int t, h;
        D_0047AB18 = 0;
        t = func_004287E0(D_0047A778, 3, 0, 0);
        h = func_00428C10(t, 3, 1);
        if (h == 0)
            return 0;
        D_0048D4C4 = func_004216C0(h, 0);
    }
    return D_0048D4C4;
}

extern "C" void func_00429830(unsigned int mode)
{
    *(unsigned char *)&D_0048D1C5 = 1;
    D_0048D358 = mode;
    if (mode < 1 && mode > 4)
        D_0048D358 = 0xffffffff;
}

extern "C" void func_00429860(int *ids, unsigned int count)
{
    unsigned int i;
    unsigned int n;

    i = 0;
    n = func_00440160();
    if (i < n) {
        do {
            char *p = func_00440180(i);
            unsigned int j;
            for (j = 0; j < count; j++) {
                if (*(int *)(p + 0xa8) == ids[j]) {
                    *(unsigned int *)(p + 0x60) = j + 1;
                    break;
                }
            }
            i++;
        } while (i < n);
    }
}

extern "C" void func_00429C30(void)
{
    int i;
    char *p;

    memset(D_0065E2A0, 0, 0xbc);
    D_0048D4C0 = 1;
    D_0065E33C = 1;
    func_00429E60();
    func_00429E80();
    func_00429DD0();
    memset(D_0064D160, 0, sizeof(D_0064D160));
    D_0064D160[0] = 0;
    D_0064D166 = 1;
    D_0064D165 = 100;
    D_0064D164 = 100;
    i = 1;
    p = D_0064D148[1].data;
    do {
        func_00429F10(i);
        *p = 1;
        p += 0x20;
        i++;
    } while (p <= D_0064D148[4].data);
    switch (func_00429EA0()) {
    case 0:
        D_0064DD34 = D_0064D300;
        memset(D_0064D300, 0, 0xf4);
        D_0047AAF4 = 0x928;
        D_0047AAF8 = 0xf4;
        D_0064DD38 = D_0064D400;
        D_0064D300[0x0] = 1;
        D_0064D300[0x1] = 1;
        D_0064D300[0x2] = 1;
        D_0064D300[0x3] = 1;
        D_0064D300[0x4] = 1;
        D_0064D300[0x5] = 1;
        D_0064D300[0x93] = 1;
        D_0064D300[0x94] = 1;
        D_0064D300[0x95] = 1;
        D_0064D300[0x21] = 1;
        D_0064D300[0x26] = 1;
        D_0064D300[0x34] = 1;
        D_0064D300[0x35] = 1;
        D_0064D300[0x36] = 1;
        D_0064D300[0x37] = 1;
        D_0064D300[0x3e] = 1;
        D_0064D300[0x3f] = 1;
        D_0064D300[0x40] = 1;
        D_0064D300[0x41] = 1;
        D_0064D300[0x48] = 1;
        D_0064D300[0xaa] = 1;
        D_0064D300[0xab] = 1;
        D_0064D300[0xae] = 1;
        break;
    case 1:
        D_0064DD34 = D_0064DD40;
        memset(D_0064DD40, 0, 0x1cdc);
        D_0047AB10 = 0xe868;
        D_0047AB14 = 0x1cdc;
        D_0064DD38 = D_0064FA20;
        D_0064DD40[0x0] = 1;
        D_0064DD40[0x14] = 1;
        func_00429FA0(0x6a, 10, 1);
        func_00429FA0(0x6b, 10, 1);
        break;
    }
}

