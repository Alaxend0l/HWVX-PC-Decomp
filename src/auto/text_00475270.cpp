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
extern "C" int func_004745AC(unsigned long, unsigned long, unsigned long *);
extern "C" void func_0047462B(LDBL12_00475270 *);
extern "C" void func_00474659(LDBL12_00475270 *);

#define UL_LO_12(p) ((unsigned long *)&(p)->ld12[0])
#define UL_MED_12(p) ((unsigned long *)&(p)->ld12[4])
#define UL_HI_12(p) ((unsigned long *)&(p)->ld12[8])
#define UL_MANLO_12(p) ((unsigned long *)&(p)->ld12[2])
#define UL_MANHI_12(p) ((unsigned long *)&(p)->ld12[6])
#define U_XT_12(p) ((unsigned short *)&(p)->ld12[0])
#define U_EXP_12(p) ((unsigned short *)&(p)->ld12[10])
#define USHORT_12(p, i) ((unsigned short *)((unsigned char *)(p) + (i)))
#define ULONG_12(p, i) ((unsigned long *)((unsigned char *)(p) + (i)))

#pragma optimize("y", off)
extern "C" void func_004752AA(LDBL12_00475270 *px, LDBL12_00475270 *py)
{
    unsigned short sign;
    unsigned short expx, expy, expsum;
    LDBL12_00475270 tempman;
    int sticky = 0;
    int roffs, poffs, qoffs;
    int i, j;

    *UL_LO_12(&tempman) = 0;
    *UL_MED_12(&tempman) = 0;
    *UL_HI_12(&tempman) = 0;

    expx = *U_EXP_12(px);
    expy = *U_EXP_12(py);
    sign = (expx ^ expy) & 0x8000;
    expx &= 0x7fff;
    expy &= 0x7fff;
    expsum = expx + expy;

    if (expx >= 0x7fff || expy >= 0x7fff || expsum > 0xbffd) {
        *UL_HI_12(px) = sign ? 0xffff8000 : 0x7fff8000;
        *UL_MED_12(px) = 0;
        *UL_LO_12(px) = 0;
        return;
    }
    if (expsum <= 0x3fbf) {
        *UL_HI_12(px) = 0;
        *UL_MED_12(px) = 0;
        *UL_LO_12(px) = 0;
        return;
    }
    if (expx == 0) {
        expsum++;
        if ((*UL_HI_12(px) & 0x7fffffff) == 0 && *UL_MED_12(px) == 0 && *UL_LO_12(px) == 0) {
            *U_EXP_12(px) = 0;
            return;
        }
    }
    if (expy == 0) {
        expsum++;
        if ((*UL_HI_12(py) & 0x7fffffff) == 0 && *UL_MED_12(py) == 0 && *UL_LO_12(py) == 0) {
            *UL_HI_12(px) = 0;
            *UL_MED_12(px) = 0;
            *UL_LO_12(px) = 0;
            return;
        }
    }

    roffs = 0;
    for (i = 0; i < 5; i++) {
        poffs = i << 1;
        qoffs = 8;
        for (j = 5 - i; j > 0; j--) {
            unsigned long prod;
            unsigned short *p, *q;
            unsigned long *r;
            p = USHORT_12(px, poffs);
            q = USHORT_12(py, qoffs);
            r = ULONG_12(&tempman, roffs);
            prod = (unsigned long)*p * (unsigned long)*q;
            if (func_004745AC(*r, prod, r))
                (*USHORT_12(&tempman, roffs + 4))++;
            poffs += 2;
            qoffs -= 2;
        }
        roffs += 2;
    }

    expsum += 0xc002;
    while ((short)expsum > 0 && (*UL_HI_12(&tempman) & 0x80000000) == 0) {
        func_0047462B(&tempman);
        expsum--;
    }
    if ((short)expsum <= 0) {
        expsum--;
        if ((short)expsum < 0) {
            int shift = -(short)expsum;
            expsum += shift;
            i = shift;
            do {
                if (*U_XT_12(&tempman) & 1)
                    sticky++;
                func_00474659(&tempman);
            } while (--i);
            if (sticky)
                *U_XT_12(&tempman) |= 1;
        }
    }

    if (*U_XT_12(&tempman) > 0x8000 || (*UL_LO_12(&tempman) & 0x1ffff) == 0x18000) {
        if (*UL_MANLO_12(&tempman) == 0xffffffff) {
            *UL_MANLO_12(&tempman) = 0;
            if (*UL_MANHI_12(&tempman) == 0xffffffff) {
                *UL_MANHI_12(&tempman) = 0;
                if (*U_EXP_12(&tempman) == 0xffff) {
                    *U_EXP_12(&tempman) = 0x8000;
                    expsum++;
                } else {
                    (*U_EXP_12(&tempman))++;
                }
            } else {
                (*UL_MANHI_12(&tempman))++;
            }
        } else {
            (*UL_MANLO_12(&tempman))++;
        }
    }

    if (expsum >= 0x7fff) {
        *UL_HI_12(px) = sign ? 0xffff8000 : 0x7fff8000;
        *UL_MED_12(px) = 0;
        *UL_LO_12(px) = 0;
    } else {
        *U_XT_12(px) = *USHORT_12(&tempman, 2);
        *ULONG_12(px, 2) = *ULONG_12(&tempman, 4);
        *ULONG_12(px, 6) = *ULONG_12(&tempman, 8);
        *U_EXP_12(px) = expsum | sign;
    }
}

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
