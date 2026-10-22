/* 7 functions from 0x0044E050 to 0x0044EB52, found by Ghidra. */
#include "common.h"

struct Node_0048D980 {
    char unk_0x00[0xc];
    float unk_0x0c;
    char unk_0x10[0x1c - 0x10];
    float unk_0x1c;
    char unk_0x20[0x40 - 0x20];
    float unk_0x40;
    char unk_0x44[4];
    Node_0048D980 *next;
};

struct Entry_0048D980 {
    Node_0048D980 nodes[15];
    Node_0048D980 *unk_0x474;
    Node_0048D980 *unk_0x478;
    char unk_0x47c[0x490 - 0x47c];
    short unk_0x490;
    short unk_0x492;
    short unk_0x494;
    char unk_0x496[0x49c - 0x496];
};

extern Entry_0048D980 D_0048D980[32];

struct Obj_0044EB30 {
    char unk_0x00[0xb0];
    unsigned int unk_0xb0;
};

int func_0044E050(void)
{
    int i = 0;
    short *p;
    for (p = &D_0048D980[0].unk_0x492; p < &D_0048D980[32].unk_0x492; p = (short *)((char *)p + sizeof(Entry_0048D980)), i++) {
        if (*p == 0)
            break;
    }
    return i;
}

void func_0044E840(int idx)
{
    int i;

    D_0048D980[idx].unk_0x474 = D_0048D980[idx].nodes;
    D_0048D980[idx].unk_0x478 = D_0048D980[idx].nodes;
    D_0048D980[idx].unk_0x490 = 0;
    D_0048D980[idx].unk_0x492 = 0;
    D_0048D980[idx].unk_0x494 = -1;
    for (i = 0; i < 14; i++) {
        D_0048D980[idx].nodes[i].next = &D_0048D980[idx].nodes[i + 1];
        D_0048D980[idx].nodes[i].unk_0x0c = 1.0f;
        D_0048D980[idx].nodes[i].unk_0x1c = 1.0f;
        D_0048D980[idx].nodes[i].unk_0x40 = 1.0f;
    }
    D_0048D980[idx].nodes[14].next = D_0048D980[idx].nodes;
}

bool func_0044EB30(Obj_0044EB30 *p, unsigned int lo, unsigned int hi)
{
    if (p->unk_0xb0 < lo || p->unk_0xb0 >= hi)
        return false;
    return true;
}

