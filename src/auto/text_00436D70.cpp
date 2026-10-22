/* 9 functions from 0x00436D70 to 0x00437D70, found by Ghidra. */
#include "common.h"
struct Obj_00437 {
    char unk_0x0[0x68];
    int unk_0x68;
};

struct Slot_00437 {
    Obj_00437 *unk_0x0;
    char unk_0x4[0x168];
};

struct Msg_00437 {
    int unk_0x0;
    int unk_0x4;
};

struct Target_00437 {
    char unk_0x0[0x10];
    char *unk_0x10;
    char unk_0x14[0x10];
    char *unk_0x24;
    char *unk_0x28;
    char *unk_0x2c;
};

struct Event_00437 {
    int type;
    Target_00437 *target;
};

extern unsigned char D_00681AB0;
extern Slot_00437 D_00681500[];
extern char *D_0048D614;
extern char *D_0048D608;
extern int D_0048D618;
extern int D_0048D610;
extern int D_0048D61C;
extern char D_00692350[];

void func_0042E250(int, int, int);
void func_0043EB20(Obj_00437 *);
void func_0042DE60(int);
int func_0043B500(char *, int);
