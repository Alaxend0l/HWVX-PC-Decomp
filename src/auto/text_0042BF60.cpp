/* 7 functions from 0x0042BF60 to 0x0042C532, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Info_0042B050 {
    char unk_0x00[0x18];
    unsigned int unk_0x18;
};

extern char *D_0064DD38;
extern char *D_0064DD34;
extern int D_0064D160[0x62];
extern int D_0064D1E8[0x40];
extern int D_0065E33C;
extern int D_0065E340;
extern char D_0065E344;
extern char D_0065E345;
extern char D_0065E346;
extern int D_0065E350;
extern int D_0065E354;
extern short D_0065E358;
extern char D_0065E35A;
extern char D_0048D4C8;
extern char D_0048D4C9;
extern char D_0048D4CA;

int func_0042B980(int *, int);
void func_0042B050(Info_0042B050 *);
char func_0042B800(int, Info_0042B050 *, ...);
char func_0042B880(int, Info_0042B050 *, ...);
char func_004584E0(int);

char func_0042C1A0(void)
{
    int n;
    Info_0042B050 info;
    int r;
    char *p;

    r = func_0042B980(&n, 1);
    if (r != 1 && r != 0)
        return 0;
    n--;
    func_0042B050(&info);
    p = D_0064DD38;
    if (!func_0042B800(n + 11, &info, p))
        memset(p + 0x94, 0, 0x100);
    memcpy(D_0064D1E8, p + 0x94, 0x100);
    memcpy(p + 0xc, D_0064D160, 0x188);
    return D_0065E344 = func_0042B880(n + 11, &info, D_0064DD38) ? 1 : 0;
}

void func_0042C3F0(void)
{
    int a = D_0065E33C - 1;
    int b = D_0065E340 - 1;
    Info_0042B050 info;
    char *p;

    func_0042B050(&info);
    if (!func_0042B800(a + 11, &info, D_0064DD38)) {
        D_0065E345 = 0;
        return;
    }
    p = D_0064DD38;
    memcpy(D_0064DD34, p + 0x194 + b * info.unk_0x18, info.unk_0x18);
    memcpy(D_0064D160, p + 0xc, 0x188);
    D_0065E350 = 0;
    D_0065E354 = 0;
    D_0065E358 = 0;
    D_0048D4C8 = 1;
    D_0048D4C9 = 1;
    D_0048D4CA = 1;
    D_0065E345 = 1;
    D_0065E35A = 0;
}

void func_0042C4B0(void)
{
    char r = func_004584E0(D_0065E33C + 10);
    D_0048D4C8 = 1;
    D_0048D4C9 = 1;
    D_0048D4CA = 1;
    D_0065E346 = r;
}

