/* 10 functions from 0x0042C540 to 0x0042D500, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Pair_0042C540 {
    int a;
    int b;
};

static inline void SetPair_0042C540(int *p, int v)
{
    p[0] = v;
    p[1] = v;
}

struct Slot_0042C540 {
    int id;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    int unk_0x14;
    char unk_0x18[0xc];
    char *unk_0x24;
    char unk_0x28[4];
    int unk_0x2c;
    int unk_0x30;
    char unk_0x34[4];
};

struct PoolEntry_0042C540 {
    int unk_0x0;
    char unk_0x4[0x40];
    short unk_0x44;
    char unk_0x46[2];
};

struct Pool_0042C540 {
    PoolEntry_0042C540 entries[0x800];
    int used;
    unsigned int count;
};

struct Car_0042C540 {
    int id;
    char unk_0x4[0xc5];
    unsigned char color[4];
};

extern Slot_0042C540 D_0064D080[4];
extern Pool_0042C540 *D_0048D5DC;
struct SlotPtr_0042C540 {
    char *ptr;
    char unk_0x4[0x34];
};
extern SlotPtr_0042C540 D_0064D0A4[4];
extern char D_0047ACC0[];

void func_0043FF50(void);
void func_0042D010(int);
void func_00454C50(void *);
void *func_00454B80(int, int, const char *);

void func_0042C540(void)
{
    Slot_0042C540 *s;

    for (s = D_0064D080; s < &D_0064D080[4]; s++) {
        memset(s, 0, sizeof(*s));
        s->id = -1;
        s->unk_0xc = -1;
        s->unk_0x4 = -1;
        s->unk_0x8 = -1;
        s->unk_0x14 = -1;
        SetPair_0042C540(&s->unk_0x2c, -1);
    }
    func_0043FF50();
}

void func_0042C580(Car_0042C540 *car)
{
    int i;
    char *p;

    i = 0;
    do {
        if (D_0064D080[i].id == car->id && D_0064D080[i].unk_0x24 != NULL)
            goto found;
        i++;
    } while (i < 4);
    return;
found:
    p = *(char **)(D_0064D080[i].unk_0x24 + 0x398);
    car->color[0] = (*(char **)(p + 0x84))[0x34];
    car->color[1] = (*(char **)(p + 0x84))[0x35];
    car->color[2] = (*(char **)(p + 0x84))[0x36];
    car->color[3] = (*(char **)(p + 0x84))[0x37];
}

char func_0042CF70(void)
{
    Pool_0042C540 *pool;
    unsigned int i;

    D_0048D5DC = pool = (Pool_0042C540 *)func_00454B80(sizeof(Pool_0042C540), 0x42, D_0047ACC0);
    if (pool == NULL)
        return 0;
    D_0048D5DC->count = 0x800;
    D_0048D5DC->used = 0;
    for (i = 0; i < D_0048D5DC->count; i++) {
        D_0048D5DC->entries[i].unk_0x0 = 0;
        D_0048D5DC->entries[i].unk_0x44 = 0;
    }
    return 1;
}

void func_0042CFF0(void)
{
    func_0042D010(1);
    func_00454C50(D_0048D5DC);
    D_0048D5DC = NULL;
}
