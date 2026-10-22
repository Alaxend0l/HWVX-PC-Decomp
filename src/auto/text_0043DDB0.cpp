/* 17 functions from 0x0043DDB0 to 0x0043EDB0, found by Ghidra. */
#include "common.h"

extern int D_0047B0CC;
extern int D_0048D780;
extern int D_0048D77C;
extern int D_005423C0[0x1000];
extern int D_005463C0;
extern int D_005463C4;

void func_004585A0(int);
int func_004585D0(int, int, int *);
char func_00458610(int, int, int *);

struct Obj_0043ECA0;
void func_0043E8F0(void)
{
    func_004585A0(D_0047B0CC);
    D_0047B0CC = -1;
    D_0048D780 = 0;
}

int func_0043E920(void)
{
    int v;
    int n;

    if (D_005463C0 == D_005463C4) {
        func_0043E8F0();
        D_0048D77C = 1;
        return D_005423C0[D_005463C0];
    }
    v = D_005423C0[D_005463C0++];
    if (D_005463C0 == 0x1000) {
        n = func_004585D0(D_0047B0CC, 0x4000, D_005423C0);
        D_005463C0 = 0;
        if (n != 0x4000)
            D_005463C4 = n - 1;
    }
    return v;
}

void func_0043E9A0(int v)
{
    D_005423C0[D_005463C0++] = v;
    if (D_005463C0 == 0x1000) {
        func_00458610(D_0047B0CC, 0x4000, D_005423C0);
        D_005463C0 = 0;
    }
}

bool func_0043ECA0(Obj_0043ECA0 *o)
{
    return ((char (*)(Obj_0043ECA0 *))((void **)o)[8])(o) != 0;
}

