/* 9 functions from 0x0045BB10 to 0x0045C9A0, found by Ghidra. */
#include "common.h"

struct Node_0045C {
    char unk_0x0[2];
    unsigned char unk_0x2;
    char unk_0x3;
    Node_0045C *next;
    char unk_0x8[0x38];
    int unk_0x40;
};

struct List_0045C {
    Node_0045C *head;
    Node_0045C *unk_0x4;
    char unk_0x8[0x12];
    short unk_0x1a;
    char unk_0x1c[0x10];
    int unk_0x2c;
    char unk_0x30[0x40];
};

extern List_0045C D_00499A68[];

void func_0045D630(Node_0045C *, int);
void func_0045DC20(Node_0045C *, int);

void func_0045C640(List_0045C *list)
{
    Node_0045C *old = list->unk_0x4;
    Node_0045C *n = list->head->next;

    list->head = n;
    func_0045D630(old, 3);
    list->unk_0x4 = NULL;
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

void func_0045C5E0(List_0045C *list)
{
    Node_0045C *n;

    for (n = list->head; n != NULL; n = n->next)
        func_0045DC20(n, list->unk_0x1a);
}

void func_0045C610(List_0045C *list)
{
    Node_0045C *n;

    for (n = list->head; n != NULL; n = n->next) {
        n->unk_0x40 = list->unk_0x2c;
        func_0045DC20(n, list->unk_0x1a);
    }
}

