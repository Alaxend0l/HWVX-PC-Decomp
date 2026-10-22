/* 38 functions from 0x0044FFC0 to 0x00450E90, found by Ghidra. */
#include "common.h"
struct Obj_0044FFC0 {
    char pad0[0x74];
    unsigned char flags_74;
};

struct Item_0044FFC0 {
    char pad0[0x28];
    Obj_0044FFC0 *obj_28;
    char pad2C[0x4];
    int type_30;
};

struct List_0044FFC0 {
    unsigned int count;
    Item_0044FFC0 *items[1];
};

struct Entry_004505A0 {
    char pad0[0xc];
    int unk_c;
    int unk_10;
    char *unk_14;
    char pad18[0x4];
    unsigned int unk_1c;
    char pad20[0x4];
    int state_24;
    char unk_28;
};

struct Target_00450780 {
    char pad0[0x8];
    int state_8;
};

struct Cmd_00450780 {
    int op;
    unsigned int count;
    Target_00450780 *targets[1];
};

struct Trigger_004507E0 {
    char pad0[0x14];
    void *unk_14;
    char pad18[0x4];
    int unk_1c;
    char pad20[0x30];
};

struct Level_004507E0 {
    char pad0[0x20];
    unsigned int numTriggers;
    Trigger_004507E0 *triggers;
    char pad28[0x38];
    unsigned int numPaths;
    char (*paths)[0x10];
};

struct Slot_0049DCC0 {
    char *path;
    char data[0x2c];
    char active;
    char pad31[3];
};

extern "C" Level_004507E0 *D_0049DBA0;
extern "C" int D_00496DD0;
extern "C" unsigned int D_00496DCC;
extern "C" Slot_0049DCC0 D_0049DCC0[];
extern "C" void *D_0049DBC0[];
extern "C" int D_0069236C;
extern "C" void func_004268B0(int, char *, int);
extern "C" void func_00401090(void);
extern "C" void func_004508C0(void *p);

extern "C" char func_0044F4D0(char a, int b, int c);
extern "C" int func_00401140(void *p);

extern "C" char D_00496DC8;
extern "C" unsigned int D_0047B978;
extern "C" Entry_004505A0 **D_00496DAC;
extern "C" unsigned int D_0047B984;
extern "C" Entry_004505A0 **D_00496DB0;
extern "C" unsigned int D_0047B9A8;
extern "C" Entry_004505A0 **D_00496DBC;

extern "C" bool func_0044FFC0(List_0044FFC0 *list)
{
    for (int i = 0; i < list->count; i++) {
        if (list->items[i]->obj_28 && (list->items[i]->obj_28->flags_74 & 2))
            return true;
    }
    return false;
}

extern "C" void func_004508C0(void *p)
{
    if (p != NULL)
        D_0049DBC0[D_00496DD0++] = p;
}

extern "C" bool func_004500E0(List_0044FFC0 *list)
{
    for (int i = 0; i < list->count; i++) {
        if (list->items[i]->type_30 == 3)
            return true;
    }
    return false;
}

extern "C" char func_00450220(void)
{
    return 0;
}

extern "C" void func_004505A0(void)
{
    if (!D_00496DC8) {
        for (unsigned int i = 0; i < D_0047B978; i++) {
            if (D_00496DAC[i]->state_24 != 2
                && func_0044F4D0(D_00496DAC[i]->unk_28, D_00496DAC[i]->unk_10, D_00496DAC[i]->unk_c)) {
                int sum = 0;
                unsigned int n = D_00496DAC[i]->unk_1c;
                for (unsigned int j = 0; j < n; j++) {
                    sum += func_00401140(&D_00496DAC[i]->unk_14[j * 0x18]);
                    n = D_00496DAC[i]->unk_1c;
                }
                if (sum == 0)
                    D_00496DAC[i]->state_24 = 2;
            }
        }
    }
}

extern "C" void func_00450640(void)
{
    unsigned int i;
    unsigned int j;
    int sum;

    if (D_00496DC8)
        return;
    for (i = 0; i < D_0047B984; i++) {
        if (D_00496DB0[i]->state_24 == 2)
            continue;
        if (!func_0044F4D0(D_00496DB0[i]->unk_28, D_00496DB0[i]->unk_10, D_00496DB0[i]->unk_c))
            continue;
        sum = 0;
        for (j = 0; j < D_00496DB0[i]->unk_1c; j++)
            sum += func_00401140(D_00496DB0[i]->unk_14 + j * 0x18);
        if (sum == 0)
            D_00496DB0[i]->state_24 = 2;
    }
}

extern "C" void func_004506E0(void)
{
    if (!D_00496DC8) {
        for (unsigned int i = 0; i < D_0047B9A8; i++) {
            if (D_00496DBC[i]->state_24 != 2
                && func_0044F4D0(D_00496DBC[i]->unk_28, D_00496DBC[i]->unk_10, D_00496DBC[i]->unk_c)) {
                int sum = 0;
                unsigned int n = D_00496DBC[i]->unk_1c;
                for (unsigned int j = 0; j < n; j++) {
                    sum += func_00401140(&D_00496DBC[i]->unk_14[j * 0x18]);
                    n = D_00496DBC[i]->unk_1c;
                }
                if (sum == 0)
                    D_00496DBC[i]->state_24 = 2;
            }
        }
    }
}

extern "C" char func_00450780(Cmd_00450780 *cmd)
{
    unsigned int n = cmd->count;
    for (unsigned int i = 0; i < n; i++) {
        Target_00450780 *t = cmd->targets[i];
        switch (cmd->op) {
        case 0:
            t->state_8 = 0;
            break;
        case 1:
            t->state_8 = 1;
            break;
        case 2:
            t->state_8 = !t->state_8;
            break;
        }
    }
    return 1;
}

extern "C" void func_004507D0(void)
{
    D_00496DD0 = 0;
    D_00496DCC = 0;
}

extern "C" void func_004507E0(void)
{
    Level_004507E0 *lv = D_0049DBA0;
    unsigned int i;

    D_00496DD0 = 0;
    D_00496DCC = 0;
    if (lv != NULL) {
        for (i = 0; i < lv->numPaths; i++) {
            D_0049DCC0[D_00496DCC].path = lv->paths[i];
            D_0049DCC0[D_00496DCC].active = 1;
            D_00496DCC++;
        }
        for (i = 0; i < lv->numTriggers; i++) {
            if (lv->triggers[i].unk_1c == 0) {
                if (lv->triggers[i].unk_14 != NULL)
                    func_004508C0(lv->triggers[i].unk_14);
                return;
            }
        }
    }
}

extern "C" void func_00450870(void)
{
    int dt = D_0069236C;
    unsigned int i;

    for (i = 0; i < D_00496DCC; i++)
        func_004268B0(*(int *)(D_0049DCC0[i].path + 4), D_0049DCC0[i].data, dt);
    func_00401090();
}

extern "C" int D_00496DE8;
int func_00450A50(void)
{
    return D_00496DE8;
}

extern "C" unsigned int D_0047B984;
extern "C" Entry_004505A0 **D_00496DB0;
extern "C" unsigned int D_0047B9A8;
extern "C" Entry_004505A0 **D_00496DBC;
extern "C" int D_00496DF4;
extern "C" void func_00450C00(void)
{
    D_00496DF4 = 0;
}

