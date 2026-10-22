/* 9 functions from 0x00442C10 to 0x004439C0, found by Ghidra. */
#include "common.h"
struct Ent_00443 {
    char unk_0x0[0x4];
    char unk_0x4;
    char unk_0x5[0x6f];
    union {
        int unk_0x74;
        struct {
            unsigned int b0 : 20;
            unsigned int b20 : 1;
            unsigned int b21 : 9;
            unsigned int b30 : 1;
            unsigned int b31 : 1;
        } bits;
    };
    char unk_0x78[0x50];
    Ent_00443 *unk_0xc8;
    char unk_0xcc[0x4];
    int unk_0xd0[4];
};

struct Rect_00443 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
};

struct Spawn_00443 {
    Rect_00443 rect;
    Ent_00443 *owner;
    char unk_0x14;
};

struct Res_00443 {
    char unk_0x0[0x2c];
    unsigned int unk_0x2c;
    unsigned short *unk_0x30;
};

extern char D_0047A778[];
void *func_004287E0(char *, int, int, int);
Res_00443 *func_00428C10(void *, int, int);
void func_00462E30(int);
void func_00421320(Res_00443 *);

extern Rect_00443 D_00692350;
extern char D_0048D974;

void func_004506E0(void);
char func_00409E40(int);
void func_00409DD0(int);
void func_00448330(Ent_00443 *);
unsigned char func_00440130(void);
Ent_00443 *func_0044D0B0(int, Spawn_00443 *);
unsigned int func_0044D8F0(Ent_00443 **, int);
void func_00443560(Ent_00443 *);
Ent_00443 *func_00443740(Ent_00443 *, Rect_00443 *);

void func_00443560(Ent_00443 *e)
{
    int i;

    if (e->unk_0x74 & 0x40000000) {
        if (e->unk_0xc8 != NULL) {
            e->unk_0xc8->unk_0x74 &= 0x7fffffffu;
            e->unk_0xc8 = NULL;
        } else {
            func_004506E0();
        }
    }
    for (i = 0; i < 4; i++) {
        if (e->unk_0xd0[i] >= 0 && func_00409E40(e->unk_0xd0[i]))
            func_00409DD0(e->unk_0xd0[i]);
        e->unk_0xd0[i] = -1;
    }
    func_00448330(e);
}

Ent_00443 *func_00443740(Ent_00443 *owner, Rect_00443 *rect)
{
    Spawn_00443 s;
    Ent_00443 *e;

    if (owner->unk_0x4 != 0 || func_00440130() <= 1) {
        if (rect != NULL)
            s.rect = *rect;
        else
            s.rect = D_00692350;
        s.owner = owner;
        s.unk_0x14 = 0;
        e = func_0044D0B0(0x10, &s);
        if (e != NULL) {
            if (D_0048D974)
                e->unk_0x74 |= 0x100000;
            return e;
        }
    }
    return (Ent_00443 *)-1;
}

Ent_00443 *func_004437E0(Ent_00443 *owner, Rect_00443 *rect)
{
    Ent_00443 *list[128];
    Ent_00443 *e;
    Ent_00443 *p;
    unsigned int n;

    e = func_00443740(owner, rect);
    if (e != (Ent_00443 *)-1) {
        n = func_0044D8F0(list, 0x80);
        while (n > 0) {
            p = list[--n];
            if (p->bits.b30 && p->unk_0xc8 == NULL) {
                list[n]->unk_0xc8 = e;
                e->unk_0x74 |= 0x80000000;
                break;
            }
        }
        e->unk_0x74 |= 0x40000000;
        e->unk_0xc8 = NULL;
    }
    return e;
}

void func_00443880(void)
{
    Ent_00443 *list[128];
    unsigned int n;

    n = func_0044D8F0(list, 0x80);
    while (n > 0) {
        n--;
        if (list[n]->unk_0x74 & 0x40000000) {
            list[n]->unk_0x74 &= ~0x40000000;
            list[n]->unk_0xc8 = NULL;
            func_00443560(list[n]);
        }
    }
}

int func_004438E0(void)
{
    Ent_00443 *list[128];
    unsigned int n;
    int count = 0;

    n = func_0044D8F0(list, 0x80);
    while (n > 0) {
        n--;
        if (list[n]->unk_0x74 & 0x40000000)
            count++;
    }
    return count;
}

void func_00443940(Ent_00443 *e)
{
    if (e != (Ent_00443 *)-1 && e != NULL)
        func_00443560(e);
}

void func_00443960(void)
{
    Res_00443 *res;
    unsigned int i;

    res = func_00428C10(func_004287E0(D_0047A778, 3, 0, 0), 3, 1);
    if (res != NULL) {
        for (i = 0; i < res->unk_0x2c; i++)
            func_00462E30(res->unk_0x30[i]);
        func_00421320(res);
    }
}

