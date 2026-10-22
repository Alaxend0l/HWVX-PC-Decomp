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
void func_0042DE60(int);
void func_0043EA50(char *, int);
void func_0043F4B0(char *, int);
extern char D_0043F9E0;

struct Obj_0043EA10 {
    char unk_0x0[0x6c];
    int unk_0x6c;
    char unk_0x70[0xc8 - 0x70];
    int unk_0xc8;
    char unk_0xcc[0x114 - 0xcc];
    char *unk_0x114;
    char unk_0x118[1];
};

struct Obj_0043ECA0;
void func_0043E8F0(void)
{
    func_004585A0(D_0047B0CC);
    D_0047B0CC = -1;
    D_0048D780 = 0;
}

int func_0043E9F0(char *p)
{
    if (p != NULL && *(char **)(p + 0x20) == &D_0043F9E0)
        return 1;
    return 0;
}

void func_0043EA10(char *p)
{
    func_0043EA50(p, 0);
    *(int *)(p + 0xc8) = 0;
    func_0043F4B0(p, 0);
    *(int *)(p + 0x6c) = 0;
    *(char **)(p + 0x114) = p + 0x118;
}

int func_0043E920(void)
{
    int v;
    int n;

    if (D_005463C0 == D_005463C4) {
        func_0043E8F0();
        v = D_005423C0[D_005463C0];
        D_0048D77C = 1;
    } else {
        v = D_005423C0[D_005463C0++];
        if (D_005463C0 == 0x1000) {
            n = func_004585D0(D_0047B0CC, 0x4000, D_005423C0);
            D_005463C0 = 0;
            if (n != 0x4000)
                D_005463C4 = n - 1;
        }
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

void func_0043EBF0(char *p)
{
    if (*(int *)(p + 0x68) != -1)
        func_0042DE60(*(int *)(p + 0x68));
}

bool func_0043ECA0(Obj_0043ECA0 *o)
{
    return ((char (*)(Obj_0043ECA0 *))((void **)o)[8])(o) != 0;
}

