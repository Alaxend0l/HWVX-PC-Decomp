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

extern int D_00681AB0;
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

char func_00437890(int *arg)
{
    func_0042E250(*arg, 0, 0);
    return 1;
}

char func_004378B0(Msg_00437 *msg)
{
    int i;

    for (i = 0; i < D_00681AB0; i++) {
        if (msg->unk_0x4 == 1) {
            func_0043EB20(D_00681500[i].unk_0x0);
        } else {
            func_0042DE60(D_00681500[i].unk_0x0->unk_0x68);
            D_00681500[i].unk_0x0->unk_0x68 = -1;
        }
    }
    return 1;
}

char func_00437C00(Event_00437 *ev)
{
    char *p;

    D_0048D614 = NULL;
    switch (ev->type) {
    case 1:
        p = (char *)ev->target;
        if (ev->target->unk_0x28 != NULL)
            p = ev->target->unk_0x28 + 0x40;
        break;
    case 2:
        p = (char *)ev->target;
        if (ev->target->unk_0x2c != NULL)
            p = ev->target->unk_0x2c + 0x40;
        break;
    case 3:
        p = (char *)ev->target;
        if (ev->target->unk_0x24 != NULL) {
            D_0048D614 = ev->target->unk_0x24;
            p = ev->target->unk_0x24 + 0x40;
        }
        break;
    case 4:
        if (ev->target->unk_0x10 != NULL)
            p = ev->target->unk_0x10 + 0x40;
        else
            p = D_00692350;
        break;
    case 6:
        p = (char *)ev->target;
        break;
    default:
        p = NULL;
        break;
    }
    if (D_0048D608 != p) {
        D_0048D608 = p;
        D_0048D618 = -1;
        D_0048D610 = 0;
    }
    return 1;
}

void func_00437CB0(void)
{
    if (D_0048D618 == -1 || D_0048D61C <= 0) {
        D_0048D618 = func_0043B500(D_0048D608, D_0048D618);
        D_0048D61C = 300;
    }
}

