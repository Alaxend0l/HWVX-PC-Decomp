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
