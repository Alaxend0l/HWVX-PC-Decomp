/* 23 functions from 0x0042D500 to 0x0042E250, found by Ghidra. */
#include "common.h"

struct Pos_0042D500 {
    int x;
    int y;
};

struct Cell_0042D500;

struct Node_0042D500 {
    Pos_0042D500 pos;
    Node_0042D500 *next;
    Node_0042D500 *prev;
    Node_0042D500 *link;
    Cell_0042D500 *cell;
};

struct Cell_0042D500 {
    Node_0042D500 *head;
    int count;
};

struct Region_0042D500 {
    Pos_0042D500 pos;
    Node_0042D500 *nodes;
    unsigned int minA;
    unsigned int maxA;
    unsigned int minB;
    unsigned int maxB;
    Region_0042D500 *next;
};

struct Race_0042D500 {
    int numCars;
    char pad_0x4[0x75 - 0x4];
    char unk_0x75;
    char pad_0x76[0x134 - 0x76];
};

extern Node_0042D500 *D_00645074;
extern int D_0062D4C4;
extern Cell_0042D500 D_00629CC0[];
extern Region_0042D500 *D_0064D078;
extern int D_0064D07C;
extern Race_0042D500 D_005E7660[18];
extern int D_0048D5E0;
extern int D_0048D5E4;
extern int D_0048D5E8;
extern int D_0048D608;
extern int D_0048D60C;
extern int D_0048D614;
extern int D_0048D618;
extern int D_0048D61C;
extern int D_005E7648;
extern int D_005E8C10;
extern int D_005E8C14;
extern int D_005E8C18;

void func_0042D430(int value, unsigned int *a, unsigned int *b);

Node_0042D500 *func_0042D500(const Pos_0042D500 *pos, unsigned int a, unsigned int b, Node_0042D500 *link)
{
    Node_0042D500 *node = D_00645074;
    Node_0042D500 *result = NULL;
    Node_0042D500 **pnext;

    if (node != NULL) {
        pnext = &node->next;
        D_00645074 = node->next;
        node->pos = *pos;
        node->link = link;
        node->cell = &D_00629CC0[D_0062D4C4 * a + node->pos.x * 256 + b];
        node->prev = NULL;
        *pnext = D_00629CC0[D_0062D4C4 * a + node->pos.x * 256 + b].head;
        if (*pnext != NULL)
            (*pnext)->prev = node;
        D_00629CC0[node->pos.x * 256 + b + D_0062D4C4 * a].head = node;
        D_00629CC0[node->pos.x * 256 + b + D_0062D4C4 * a].count++;
        result = node;
    }
    return result;
}

void func_0042D5C0(Region_0042D500 *r)
{
    unsigned int a;
    unsigned int b;
    Node_0042D500 *node = NULL;

    for (a = r->minA; a <= r->maxA; a++)
        for (b = r->minB; b <= r->maxB; b++)
            node = func_0042D500((Pos_0042D500 *)r, a, b, node);
    r->nodes = node;
    r->next = NULL;
}

Region_0042D500 *func_0042D620(int x, int y, int from, int to)
{
    Region_0042D500 *r = D_0064D078;
    Region_0042D500 *result = NULL;

    if (r != NULL) {
        D_0064D078 = r->next;
        D_0064D07C--;
        func_0042D430(from, &r->minA, &r->minB);
        func_0042D430(to, &r->maxA, &r->maxB);
        r->pos.x = x;
        r->pos.y = y;
        func_0042D5C0(r);
        result = r;
    }
    return result;
}

void func_0042DD60(void)
{
    char *p;
    int i;

    D_0048D5E0 = 0;
    D_0048D5E4 = 0;
    D_005E7648 = 0;
    D_0048D5E8 = 0;
    for (i = 0, p = &D_005E7660[0].unk_0x75; p < &D_005E7660[18].unk_0x75; p += sizeof(Race_0042D500), i++) {
        ((Race_0042D500 *)(p - 0x75))->numCars = 0;
        *p = i;
    }
    D_0048D608 = 0;
    D_0048D60C = 0;
    D_0048D614 = 0;
    D_0048D618 = -1;
    D_0048D61C = 0;
    D_005E8C10 = 0;
    D_005E8C18 = 0;
    D_005E8C14 = 0;
}

extern int D_0048D5F4;
void func_0042DDD0(int x)
{
    D_0048D5F4 = x & 0xffff;
}

