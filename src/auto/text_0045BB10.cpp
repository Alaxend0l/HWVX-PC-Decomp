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
