/* 11 functions from 0x00429170 to 0x00429FA0, found by Ghidra. */
#include "common.h"

extern char D_0047AB18;
extern char D_0047A778[];
extern int D_0048D4C4;
extern char D_0048D1C5;
extern unsigned int D_0048D358;
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
extern "C" int func_004287E0(void *name, int a, int b, int c);
extern "C" int func_00428C10(int a, int b, int c);
extern "C" int func_004216C0(int a, int b);
extern "C" unsigned char func_00440160(void);
extern "C" char *func_00440180(unsigned int i);
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

extern "C" void func_00429E60(void)
{
    D_0065E2C0 = 1;
    D_0065E2C4 = 1;
    D_0065E2C8 = 1;
    D_0065E2CC = 1;
}

extern "C" void func_00429DD0(void)
{
    int i;
    int *p;

    D_0065E2D0 = 1;
    i = 0;
    p = D_0065E2E4;
    do {
        p[-4] = 0;
        *p = 0;
        p[4] = 0;
        D_0065E304[i] = 0;
        i++;
        p++;
    } while (p < D_0065E2F4);
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

extern "C" void func_00429830(unsigned int mode)
{
    D_0048D1C5 = 1;
    D_0048D358 = mode;
    if (D_0048D358 < 1 && D_0048D358 > 4)
        D_0048D358 = -1;
}

extern "C" void func_00429860(int *ids, unsigned int count)
{
    unsigned int i = 0;
    unsigned int n = func_00440160();

    for (; i < n; i++) {
        char *p = func_00440180(i);
        unsigned int j;
        for (j = 0; j < count; j++) {
            if (*(int *)(p + 0xa8) == ids[j]) {
                *(unsigned int *)(p + 0x60) = j + 1;
                break;
            }
        }
    }
}

