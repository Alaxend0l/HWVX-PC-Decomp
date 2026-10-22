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
