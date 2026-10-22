/* 8 functions from 0x0046B1E0 to 0x0046B43F, found by Ghidra. */
#include "common.h"

extern "C" int D_0047FC8C;
extern "C" unsigned short* D_0047FA80;
extern "C" int func_0047039E(int c, int mask);
extern "C" long func_0046B260(const char* nptr);

extern "C" long func_0046B260(const char* nptr)
{
    int c;
    int sign;
    long total;

    while ((D_0047FC8C > 1 ? func_0047039E((unsigned char)*nptr, 8) : D_0047FA80[(unsigned char)*nptr] & 8))
        ++nptr;

    c = (int)(unsigned char)*nptr++;
    sign = c;
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++;

    total = 0;

    while ((D_0047FC8C > 1 ? func_0047039E(c, 4) : D_0047FA80[c] & 4)) {
        total = 10 * total + (c - '0');
        c = (int)(unsigned char)*nptr++;
    }

    if (sign == '-')
        return -total;
    else
        return total;
}

#pragma optimize("s", on)
extern "C" int func_0046B2EB(const char* nptr)
{
    return (int)func_0046B260(nptr);
}
