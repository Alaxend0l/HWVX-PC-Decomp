/* 6 functions from 0x00475270 to 0x00475654, found by Ghidra. */
#include "common.h"

extern "C" int D_006D578C;
extern "C" int D_006D59A4;
extern "C" char *D_006D59E0[];

extern "C" int func_00475831(int, int, const char *, int, const char *, int, int);
extern "C" int *func_00470486(void);

extern "C" int func_00475546(int fh, int mode)
{
    char old = *(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4);
    if (mode == 0x8000)
        *(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4) &= ~0x80;
    else if (mode == 0x4000)
        *(D_006D59E0[fh >> 5] + (fh & 0x1f) * 0x24 + 4) |= 0x80;
    else {
        *func_00470486() = 0x16;
        return -1;
    }
    return (old & 0x80) ? 0x4000 : 0x8000;
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
