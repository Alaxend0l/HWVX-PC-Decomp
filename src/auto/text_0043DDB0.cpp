/* 17 functions from 0x0043DDB0 to 0x0043EDB0, found by Ghidra. */
#include "common.h"
#include <string.h>

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

struct Obj_0043EA50 {
    char unk_0x0[0x31];
    char unk_0x31;
    char unk_0x32[2];
    int unk_0x34;
    char unk_0x38[4];
    int unk_0x3c;
    char unk_0x40[0x20];
    int unk_0x60;
    char unk_0x64[4];
    int unk_0x68;
    int unk_0x6c;
    char unk_0x70[0x38];
    char unk_0xa8[4];
    short unk_0xac;
    short unk_0xae;
    char unk_0xb0[0x18];
    int unk_0xc8;
};

struct Obj_0043ECA0;
void func_0043E8F0(void)
{
    func_004585A0(D_0047B0CC);
    D_0047B0CC = -1;
    D_0048D780 = 0;
}

void func_0041E450(char *);
int func_00458EF0(int);
int func_0043E9F0(char *);
void func_0043EA50(char *p, int)
{
    int i;

    func_0041E450(p);
    *(char *)(p + 0x40) = 0;
    *(char *)(p + 0x31) = 0;
    *(int *)(p + 0x3c) = 0;
    *(int *)(p + 0x68) = -1;
    for (i = 0; i < 14; i++)
        ((int *)(p + 0x70))[i] = 0;
    *(char *)(p + 0x71) = 1;
    *(int *)(p + 0x34) = 0;
    ((short *)(p + 0x94))[0] = 0x1e;
    ((short *)(p + 0x94))[1] = 0x1e;
    ((short *)(p + 0x94))[2] = 0x1e;
    ((short *)(p + 0x94))[3] = 0x1e;
    ((short *)(p + 0x94))[4] = 0x1e;
    ((short *)(p + 0x94))[5] = 0x1e;
    ((short *)(p + 0x94))[6] = 0x1e;
    ((short *)(p + 0x94))[7] = 0x1e;
    *(short *)(p + 0xa2) = 0;
    *(int *)(p + 0x6c) = 0;
    *(short *)(p + 0xac) = -1;
    *(short *)(p + 0xae) = -1;
}

void func_0043EAC0(char *p, int a, const char *s)
{
    strcpy(p + 0x40, s);
    *(int *)(p + 0x60) = a;
    if (((char (*)(char *))func_0043E9F0)(p))
        *(int *)(p + 0xc8) = func_00458EF0(*(int *)(p + 0x60));
}

int func_0043E9F0(char *p)
{
    if (p != NULL && *(char **)(p + 0x20) == &D_0043F9E0)
        return 1;
    return 0;
}

void func_0043EA10(Obj_0043EA10 *o)
{
    func_0043EA50((char *)o, 0);
    o->unk_0xc8 = 0;
    func_0043F4B0((char *)o, 0);
    o->unk_0x6c = 0;
    o->unk_0x114 = &o->unk_0x118[0];
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

