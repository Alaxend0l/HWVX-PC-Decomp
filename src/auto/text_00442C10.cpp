/* 9 functions from 0x00442C10 to 0x004439C0, found by Ghidra. */
#include "common.h"
struct Ent_00443 {
    char unk_0x0[0x4];
    char unk_0x4;
    char unk_0x5[0x6f];
    int unk_0x74;
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
            e->unk_0xc8->unk_0x74 &= 0x7fffffff;
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

    if (owner->unk_0x4 == 0 && func_00440130() > 1)
        return (Ent_00443 *)-1;
    if (rect != NULL)
        s.rect = *rect;
    else
        s.rect = D_00692350;
    s.owner = owner;
    s.unk_0x14 = 0;
    e = func_0044D0B0(0x10, &s);
    if (e == NULL)
        return (Ent_00443 *)-1;
    if (D_0048D974)
        e->unk_0x74 |= 0x100000;
    return e;
}

Ent_00443 *func_004437E0(Ent_00443 *owner, Rect_00443 *rect)
{
    Ent_00443 *list[128];
    Ent_00443 *e;
    unsigned int n;

    e = func_00443740(owner, rect);
    if (e == (Ent_00443 *)-1)
        return e;
    n = func_0044D8F0(list, 0x80);
    while (n > 0) {
        n--;
        if ((list[n]->unk_0x74 & 0x40000000) && list[n]->unk_0xc8 == NULL) {
            list[n]->unk_0xc8 = e;
            e->unk_0x74 |= 0x80000000;
            break;
        }
    }
    e->unk_0x74 |= 0x40000000;
    e->unk_0xc8 = NULL;
    return e;
}

void func_00443940(Ent_00443 *e)
{
    if (e != (Ent_00443 *)-1 && e != NULL)
        func_00443560(e);
}
