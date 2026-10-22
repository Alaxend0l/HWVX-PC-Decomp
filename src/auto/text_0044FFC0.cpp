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

extern "C" char func_0044F4D0(char a, int b, int c);
extern "C" int func_00401140(void *p);

extern "C" char D_00496DC8;
extern "C" unsigned int D_0047B978;
extern "C" Entry_004505A0 **D_00496DAC;

extern "C" bool func_0044FFC0(List_0044FFC0 *list)
{
    for (int i = 0; i < list->count; i++) {
        if (list->items[i]->obj_28 && (list->items[i]->obj_28->flags_74 & 2))
            return true;
    }
    return false;
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

extern "C" int D_00496DE8;
int func_00450A50(void)
{
    return D_00496DE8;
}

