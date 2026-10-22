/* 12 functions from 0x0047435D to 0x00475111, found by Ghidra. */
#include "common.h"

#pragma optimize("s", on)
extern "C" int func_00474581(const char *string, int cnt)
{
    int n = cnt;
    const char *cp = string;

    while (n-- && *cp)
        cp++;

    if (!*cp)
        return cp - string;
    return cnt;
}
extern "C" int func_004745AC(unsigned int x, unsigned int y, unsigned int *sum)
{
    unsigned int r;
    int carry = 0;

    r = x + y;
    if (r < x || r < y)
        carry = 1;
    *sum = r;
    return carry;
}

extern "C" void func_0047462B(unsigned int *p)
{
    unsigned int c0 = p[0] >> 31;
    unsigned int c1 = p[1] >> 31;

    p[0] <<= 1;
    p[1] = (p[1] << 1) | c0;
    p[2] = (p[2] << 1) | c1;
}

extern "C" void func_004745CD(unsigned int *x, unsigned int *y)
{
    if (func_004745AC(x[0], y[0], &x[0])) {
        if (func_004745AC(x[1], 1, &x[1])) {
            x[2]++;
        }
    }
    if (func_004745AC(x[1], y[1], &x[1])) {
        x[2]++;
    }
    func_004745AC(x[2], y[2], &x[2]);
}

