/* 16 functions from 0x00428480 to 0x00429170, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Entry_0065F460 {
    char active;
    char unk_0x1;
    char unk_0x2;
    char unk_0x3;
    const char *name;
    int id;
    int refs;
    char unk_0x10[0x14 - 0x10];
    int unk_0x14;
    char unk_0x18[0x3c - 0x18];
    int unk_0x3c;
    int unk_0x40;
    char unk_0x44[0x78 - 0x44];
    char unk_0x78;
    char unk_0x79[0xa8 - 0x79];
};

struct Unk_0065EC5C {
    int unk0;
    char unk_0x4[0x78 - 0x4];
};

extern unsigned int D_0047A908[11];
extern Entry_0065F460 *D_0065F460[11];
extern Entry_0065F460 *D_0065F3E0[];
extern unsigned int D_0048D1B8;
extern void (*D_006929A0)(void);
extern Unk_0065EC5C D_0065EC5C[];
extern Unk_0065EC5C D_0065F3DC[];

struct Unk_0065E360 {
    int unk0;
    char unk_0x4[0x5c - 0x4];
};

extern Unk_0065E360 D_0065E360[24];
extern unsigned int D_0048D1B4;
extern int D_0065F3A0[];
extern Entry_0065F460 *D_0048D1A4;
extern int D_0047A904;

void func_00421530(int *);
void func_00421650(int);
void func_00421400(int *);
void func_00420710(const char *, int *, int, int, int *);

void func_0044DB90(int, int);
void func_00428BA0(void);
char func_00428AE0(unsigned int idx, int type);

char func_00428AE0(unsigned int idx, int type)
{
    int base;

    if (type >= 11 || idx >= D_0047A908[type])
        return 0;
    if (!D_0065F460[type][idx].active)
        return 1;
    if (!D_0065F460[type][idx].unk_0x1) {
        D_0065F460[type][idx].active = 0;
        return 1;
    }
    D_0065F460[type][idx].refs--;
    if (D_0065F460[type][idx].refs != 0)
        return 1;
    if (!D_0065F460[type][idx].unk_0x2)
        D_0065F460[type][idx].unk_0x40 = 0;
    base = D_0065F460[type][idx].unk_0x14;
    func_0044DB90(base, D_0065F460[type][idx].unk_0x3c + base);
    if (D_0065F460[type][idx].unk_0x78)
        D_006929A0();
    D_0065F3E0[D_0048D1B8++] = &D_0065F460[type][idx];
    return 1;
}

int func_004289E0(const char *name, int type, int id)
{
    unsigned int i, n;
    Entry_0065F460 *e;

    if (type < 11) {
        n = D_0047A908[type];
        for (i = 0; i < n; i++) {
            e = &D_0065F460[type][i];
            if (e->active && e->id == id) {
                if (name == e->name || strcmp(name, e->name) == 0)
                    return i;
            }
        }
    }
    return -1;
}

char func_00428A70(int type, char flag)
{
    unsigned int i;

    if (type >= 11)
        return 0;
    for (i = 0; i < D_0047A908[type]; i++) {
        if (D_0065F460[type] != NULL && D_0065F460[type][i].unk_0x1 != 0) {
            D_0065F460[type][i].refs = 1;
            func_00428AE0(i, type);
        }
    }
    if (flag != 0) {
        func_00428BA0();
        func_00428BA0();
    }
    return 1;
}

void func_00428CC0(void)
{
    Unk_0065EC5C *p = D_0065EC5C;
    do {
        p->unk0 = 0;
        p++;
    } while (p < D_0065F3DC);
}

void func_00428F00(void)
{
    int i;

    for (i = 0; i < 24; i++)
        D_0065E360[i].unk0 = 0;
}

