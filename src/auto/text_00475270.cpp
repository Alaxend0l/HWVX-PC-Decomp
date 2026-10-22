/* 6 functions from 0x00475270 to 0x00475654, found by Ghidra. */
#include "common.h"

extern "C" int D_006D578C;
extern "C" int D_006D59A4;
extern "C" char *D_006D59E0[];

extern "C" int func_00475831(int, int, const char *, int, const char *, int, int);
extern "C" int *func_00470486(void);

/* C runtime code: built for size */
#pragma optimize("s", on)

struct LDBL12_00475270 {
    unsigned char ld12[12];
};

extern "C" LDBL12_00475270 D_00480420[];
extern "C" LDBL12_00475270 D_00480580[];

extern "C" void func_004752AA(LDBL12_00475270 *, LDBL12_00475270 *);

#pragma optimize("y", off)
extern "C" void func_004754CA(LDBL12_00475270 *pld12, int pow, int mult12)
{
    LDBL12_00475270 *pow_10p = D_00480420 - 8;
    if (pow == 0)
        return;
    if (pow < 0) {
        pow = -pow;
        pow_10p = D_00480580 - 8;
    }
    if (!mult12)
        *(unsigned short *)pld12 = 0;
    while (pow) {
        int last3;
        LDBL12_00475270 unround;
        LDBL12_00475270 *py;
        pow_10p += 7;
        last3 = pow & 7;
        pow >>= 3;
        if (last3 == 0)
            continue;
        py = &pow_10p[last3];
        if (*(unsigned short *)py >= 0x8000) {
            unround = *py;
            (*(unsigned long *)&unround.ld12[2])--;
            py = &unround;
        }
        func_004752AA(pld12, py);
    }
}
#pragma optimize("y", on)

extern "C" int func_00475546(int fh, int mode)
{
    int oldmode = *(unsigned char *)(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4) & 0x80;
    if (mode == 0x8000)
        *(unsigned char *)(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4) &= ~0x80;
    else if (mode == 0x4000)
        *(unsigned char *)(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4) |= 0x80;
    else {
        *func_00470486() = 0x16;
        return -1;
    }
    return oldmode ? 0x4000 : 0x8000;
}

#pragma optimize("y", off)
#pragma optimize("s", on)
extern "C" int func_004755A7(const char *a, const char *b, int n)
{
    int r;
    if (n == 0)
        return 0;
    r = func_00475831(D_006D59A4, 1, a, n, b, n, D_006D578C);
    if (r == 0)
        return 0x7fffffff;
    return r - 2;
}
#pragma optimize("", on)
