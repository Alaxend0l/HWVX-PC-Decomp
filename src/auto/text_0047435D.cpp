/* 12 functions from 0x0047435D to 0x00475111, found by Ghidra. */
#include "common.h"

typedef struct {
    unsigned char ld12[12];
} LDBL12_0047435D;

#define UL_LO_12(p) ((unsigned int *)(p))
#define UL_MED_12(p) ((unsigned int *)((unsigned char *)(p) + 4))
#define UL_HI_12(p) ((unsigned int *)((unsigned char *)(p) + 8))
#define U_EXP_12(p) ((unsigned short *)((unsigned char *)(p) + 10))

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

extern "C" void func_0047462B(unsigned int *p);
extern "C" void func_00474686(char *manptr, unsigned int manlen, unsigned int *ld)
{
    unsigned int tmp[3];
    unsigned short expn = 0x404e;

    ld[0] = 0;
    ld[1] = 0;
    ld[2] = 0;

    for (; manlen > 0; manlen--, manptr++) {
        tmp[0] = ld[0];
        tmp[1] = ld[1];
        tmp[2] = ld[2];
        func_0047462B(ld);
        func_0047462B(ld);
        func_004745CD(ld, tmp);
        func_0047462B(ld);
        tmp[0] = (unsigned int)*manptr;
        tmp[1] = 0;
        tmp[2] = 0;
        func_004745CD(ld, tmp);
    }

    while (ld[2] == 0) {
        ld[2] = ld[1] >> 16;
        ld[1] = (ld[1] << 16) | (ld[0] >> 16);
        ld[0] <<= 16;
        expn -= 16;
    }
    while ((ld[2] & 0x8000) == 0) {
        func_0047462B(ld);
        expn--;
    }
    *(unsigned short *)((char *)ld + 10) = expn;
}

extern "C" void func_0047462B(unsigned int *p)
{
    unsigned int c0 = p[0] >> 31;
    unsigned int c1 = p[1] >> 31;

    p[0] <<= 1;
    p[1] = (p[1] << 1) | c0;
    p[2] = (p[2] << 1) | c1;
}

extern "C" void func_00474659(unsigned int *p)
{
    unsigned int c2 = p[2] << 31;
    unsigned int c1 = p[1] << 31;

    p[2] >>= 1;
    p[1] = (p[1] >> 1) | c2;
    p[0] = (p[0] >> 1) | c1;
}

