/* 9 functions from 0x0045BB10 to 0x0045C9A0, found by Ghidra. */
#include "common.h"

struct Src_0045C {
    char unk_0x0[0x11];
    unsigned char unk_0x11;
    unsigned char unk_0x12;
    char unk_0x13[0x1d];
    int unk_0x30;
    int unk_0x34;
    int unk_0x38;
    unsigned int unk_0x3c;
    char unk_0x40[0x8];
    int unk_0x48;
};

struct Node_0045C {
    char unk_0x0;
    char unk_0x1;
    unsigned char unk_0x2;
    char unk_0x3;
    Node_0045C *next;
    char unk_0x8[0x8];
    Src_0045C *unk_0x10;
    char unk_0x14[0xc];
    int unk_0x20;
    int unk_0x24;
    int unk_0x28;
    unsigned char unk_0x2c;
    char unk_0x2d[0x3];
    unsigned int unk_0x30;
    int unk_0x34;
    int unk_0x38;
    int unk_0x3c;
    int unk_0x40;
    int unk_0x44;
};

struct List_0045C {
    Node_0045C *head;
    Node_0045C *unk_0x4;
    Src_0045C *unk_0x8;
    char unk_0xc[0x4];
    unsigned char unk_0x10;
    char unk_0x11;
    unsigned char unk_0x12;
    char unk_0x13;
    unsigned char unk_0x14;
    char unk_0x15[0x4];
    unsigned char unk_0x19;
    short unk_0x1a;
    char unk_0x1c[0x10];
    int unk_0x2c;
    char unk_0x30[0x14];
    int unk_0x44;
    char unk_0x48[0x28];
};

extern float D_00477CE0[];
extern int D_0049A884;

extern List_0045C D_00499A68[];

struct Iface_0045C {
    void **vtbl;
};

struct Slot_0045C {
    Iface_0045C *unk_0x0;
    Iface_0045C *unk_0x4;
    char unk_0x8[0xc];
    int unk_0x14;
    char unk_0x18[0x8];
};

struct Entry24_0045C {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    char unk_0x10[0x14];
};

struct Entry18_0045C {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    int unk_0x14;
};

extern Slot_0045C D_0049B7E8[32];
extern Entry24_0045C D_0049AEFC[64];
extern Entry18_0045C D_0049BBE8[254];

void func_0045D630(Node_0045C *, int);
void func_0045DC20(Node_0045C *, int);
Node_0045C *func_0045D4E0(int, int);
void func_0045D620(Node_0045C *);
void func_0045C640(List_0045C *list);

static inline void ReleaseNode_0045C(Node_0045C *n)
{
    func_0045D630(n, 3);
}

void func_0045C640(List_0045C *list)
{
    list->head = list->head->next;
    ReleaseNode_0045C(list->unk_0x4);
    list->unk_0x4 = NULL;
}

char func_0045C4A0(List_0045C *list)
{
    unsigned int rate;
    Src_0045C *src;
    Node_0045C *n;

    src = list->unk_0x8;
    rate = (unsigned int)(src->unk_0x3c * D_00477CE0[list->unk_0x19]);
    if (rate > 0x2ee00 || rate < 0x60) {
        if (list->unk_0x4 != NULL)
            func_0045C640(list);
        return 0;
    }
    if (list->unk_0x4 != NULL) {
        func_0045D630(list->unk_0x4, 3);
        list->head = list->head->next;
    }
    if ((list->unk_0x4 = func_0045D4E0(0, list->unk_0x12)) == NULL)
        return 0;
    list->unk_0x4->unk_0x2 = list->unk_0x10;
    list->unk_0x4->unk_0x1 = list->unk_0x14;
    list->unk_0x4->next = list->head;
    n = list->unk_0x4;
    list->head = n;
    n->unk_0x10 = list->unk_0x8;
    src = list->unk_0x8;
    n->unk_0x20 = src->unk_0x48;
    n->unk_0x24 = (src->unk_0x12 & 0x10) ? src->unk_0x34 : -1;
    n->unk_0x28 = (src->unk_0x12 & 0x10) ? src->unk_0x38 : src->unk_0x30;
    n->unk_0x2c = (src->unk_0x12 & 2) ? 16 : 8;
    n->unk_0x30 = rate;
    n->unk_0x34 = D_0049A884;
    n->unk_0x38 = list->unk_0x44;
    n->unk_0x3c = src->unk_0x11 << 9;
    n->unk_0x40 = list->unk_0x2c;
    n->unk_0x44 = -0x7fff;
    func_0045D620(n);
    func_0045DC20(n, list->unk_0x1a);
    return 1;
}

void func_0045C670(Node_0045C *node)
{
    int idx = node->unk_0x2;
    List_0045C *list;
    Node_0045C *n;

    if ((unsigned char)idx <= 0x20) {
        list = &D_00499A68[idx & 0xff];
        if (list->unk_0x4 == node) {
            list->unk_0x4 = NULL;
            list->head = node->next;
            return;
        }
        for (n = list->head; n->next != node; n = n->next)
            ;
        n->next = node->next;
    }
}

void func_0045C920(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        D_0049B7E8[i].unk_0x14 = 0;
        if (D_0049B7E8[i].unk_0x0 != NULL)
            ((int (__stdcall *)(Iface_0045C *))D_0049B7E8[i].unk_0x0->vtbl[0x48 / 4])(D_0049B7E8[i].unk_0x0);
        if (D_0049B7E8[i].unk_0x4 != NULL)
            ((int (__stdcall *)(Iface_0045C *, int, int))D_0049B7E8[i].unk_0x4->vtbl[0xc / 4])(D_0049B7E8[i].unk_0x4, 0, 0);
    }
}

int func_0045C960(void)
{
    Entry24_0045C *a;
    Entry18_0045C *b;

    for (a = D_0049AEFC; a < D_0049AEFC + 64; a++) {
        a->unk_0x4 = 0;
        a->unk_0x0 = 0;
        a->unk_0xc = 0;
    }
    for (b = D_0049BBE8; b < D_0049BBE8 + 254; b++) {
        b->unk_0x10 = 0;
        b->unk_0x4 = 0;
        b->unk_0xc = 0;
        b->unk_0x0 = 0;
        b->unk_0x8 = 0;
    }
    return 1;
}

