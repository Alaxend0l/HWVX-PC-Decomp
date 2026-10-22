/* 19 functions from 0x0042AFA0 to 0x0042BF60, found by Ghidra. */
#include "common.h"
#include <string.h>

unsigned char func_00440130(void);
int func_00429EA0(void);
extern char D_0064DD5E[];
extern char D_0064D39F[];
extern char D_0065E35A;
extern char D_0065E350[];
struct D_0064D148_t { char data[32]; };
extern D_0064D148_t D_0064D148[];
extern char D_0064D164;
extern unsigned char D_0064D165;
extern unsigned char D_0064D166;
extern char D_0048D4A4[];
extern char D_0048D4AE;
extern int D_0064DDAC;
extern int D_0064DDB0;
extern int D_0064FA14;
extern char D_0064DDB4;
struct D_0064DDB8_t { int data[14]; };
extern D_0064DDB8_t D_0064DDB8;
void func_004449B0(void);
void func_00459D70(int);
void func_004596C0(int);
void func_00459590(int);
void func_00429FA0(int, int, int);
struct Obj_004401B0 { char pad[0x70]; D_0064DDB8_t data; };
Obj_004401B0 *func_004401B0(int);
extern int D_0065E340;
extern char D_0048D4CF[];
extern char D_0065E347;
struct D_0064D160_t { int data[0x62]; };
extern D_0064D160_t D_0064D160;
extern int *D_0064DD38;
int func_004584F0(int, int, int, int);
void func_004585D0(int, int, int *);
char func_00458610(int, int, int *);
void func_004585A0(int);
int func_00459360(int, int *);
int func_0042B980(int *, int);
void func_0042B050(int *);
char func_0042B800(int, int *, int *);
void func_0042B150(void);
struct SaveHdr_0042B800 {
    int type;
    int id;
    int sum;
    int data[4];
};
struct SaveInfo_0042B800 {
    char pad[0xc];
    int unk_0x0c;
    int unk_0x10;
    int unk_0x14;
    int unk_0x18;
};

static inline int func_0042AFB0_check(char *p, int idx)
{
    if (p[10] == 0 && p == NULL)
        return 0;
    if (D_0065E350[idx] != 0)
        return 1;
    return 0;
}
int func_0042AFA0(void)
{
    return func_00440130();
}

char func_0042B800(int a, int *o, int *buf)
{
    char ok = 0;
    int h = func_004584F0(a, o[3], 0, 0);

    if (h != -1) {
        func_004585D0(h, o[6] * 8 + 0x194, buf);
        if (buf[0] == 4) {
            int id = o[5];
            if (buf[1] == id && buf[2] == func_00459360(id, buf + 3))
                ok = 1;
        }
        func_004585A0(h);
        return ok;
    }
    return ok;
}

char func_0042B880(int a, int *o, int *buf)
{
    char ok = 0;
    int h = func_004584F0(a, o[3], 5, 0);

    if (h != -1) {
        buf[0] = 4;
        buf[1] = o[5];
        buf[2] = func_00459360(o[5], buf + 3);
        if (func_00458610(h, o[6] * 8 + 0x194, buf))
            ok = 1;
        func_004585A0(h);
    }
    return ok;
}

char func_0042B900(void)
{
    int n;
    int buf[7];
    int r;

    r = func_0042B980(&n, 1);
    if (r != 1 && r != 0)
        return 0;
    n = n - 1;
    func_0042B050(buf);
    if (func_0042B800(n + 0xb, buf, D_0064DD38) == 0)
        return 0;
    memcpy(&D_0064D160, D_0064DD38 + 3, sizeof(D_0064D160));
    func_0042B150();
    return 1;
}

void func_0042B150(void)
{
    func_004449B0();
    func_00459D70((int)((D_0064D165 * 0x7fff) * 0.01f));
    func_004596C0((int)((*(int *)&D_0064D164 & 0xff) * 0x7fff * 0.01f));
    func_00459590(D_0064D166);
}

void func_0042B1C0(int *a, int *b)
{
    switch (func_00429EA0()) {
    case 0:
        *a = 0;
        *b = 0;
        break;
    case 1:
        *a = D_0064DDAC;
        *b = D_0064DDB0;
        func_00429FA0(0xcb, 1, D_0064FA14);
        break;
    }
}

void func_0042B210(void)
{
    switch (func_00429EA0()) {
    case 1:
        if (D_0064DDB4 && func_00440130() == 1)
            memcpy((char *)func_004401B0(0) + 0x70, &D_0064DDB8, sizeof(D_0064DDB8));
        break;
    }
}

void func_0042BCA0(void)
{
    D_0065E347 = D_0048D4CF[D_0065E340] != 0;
}

unsigned char func_0042AFB0(int idx)
{
    char *p;
    unsigned int i;

    switch (func_00429EA0()) {
    case 0:
        p = D_0064D39F;
        break;
    case 1:
        p = D_0064DD5E;
        break;
    default:
        p = (char *)idx;
        break;
    }

    if (idx == 9) {
        for (i = 0; i < 11; i++) {
            if (i != 9 && p[i] != 0)
                return 1;
        }
        if (i == 11)
            return 0;
    } else if (idx == 1 || idx == 2 || idx == 3 || idx == 4) {
        if (p[10] != 0 && D_0065E35A != 0)
            return 1;
    }

    if (p[10] == 0) {
        if (p == NULL)
            return 0;
    }
    if (D_0065E350[idx] != 0)
        return 1;
    return 0;
}

char *func_0042B040(int i)
{
    return D_0064D148[i].data;
}

char *func_0042B140(void)
{
    return &D_0064D164;
}

void func_0042BD80(unsigned int *p)
{
    unsigned int i;

    for (i = 0; i < 10; i++, p++) {
        if (*p < 26)
            D_0048D4A4[i] = *p + 'A';
        else if (*p < 36)
            D_0048D4A4[i] = *p + 0x16;
        else
            D_0048D4A4[i] = ' ';
    }
    D_0048D4AE = 0;
}

