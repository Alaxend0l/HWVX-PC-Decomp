/* 11 functions from 0x00427470 to 0x00428430, found by Ghidra. */
#include "common.h"
#include <string.h>

extern "C" bool D_0048D1A0;
extern "C" int D_0048D1A4;
struct Obj_00427470 {
    int unk_0x0;
    char pad_0x4[0x8];
    int unk_0xC;
    int unk_0x10;
    char pad_0x14[0x8];
    int unk_0x1C;
    unsigned int unk_0x20;
    int *unk_0x24;
    char pad_0x28[0xC];
    bool unk_0x34;
    char pad_0x35[0x1B];
};

struct Track_00427470 {
    char pad_0x0[0x20];
    unsigned int count;
    Obj_00427470 *nodes;
};

extern "C" unsigned int D_0048D1AC;
extern "C" bool D_0048D1A1;
extern "C" int D_0048D1B4;
extern "C" int D_0047A938;
extern "C" int D_0049DBB0;
extern "C" int D_0065F380;
extern "C" Obj_00427470 *D_0048D1A8;
extern "C" Obj_00427470 *D_0065F420[];
extern "C" Obj_00427470 *D_0065F4A0[];
extern "C" Track_00427470 *D_0049DBA0;
extern "C" void func_00421650(Obj_00427470 *);
extern "C" void func_00421210(int, Obj_00427470 *);
extern "C" void func_00428BA0(void);
extern "C" void func_00427B50(int, int);
extern "C" void func_004585A0(int);
extern "C" int func_00455C40(void (*)(void), int);
extern "C" void func_00428430(void);
extern "C" void func_00428480(int);
extern "C" bool func_00427760(void);
extern "C" int D_0048D1B0;
extern "C" int D_0047A934;
extern "C" unsigned int D_0047A908[11];
extern "C" char D_0047A93C[];
extern "C" void *D_0065F460[11];
extern "C" void *D_0065F48C[];
extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);
extern "C" void func_00428A70(int, int);

extern "C" bool func_00427760(void)
{
    return D_0048D1A0;
}

extern "C" int func_00427770(void)
{
    return 11;
}

extern "C" void func_00427780(void)
{
    unsigned int i;
    Obj_00427470 *last;

    while (func_00427760())
        ;
    for (i = 0; i < D_0048D1AC; i++) {
        if (D_0065F420[i] != 0 && D_0065F420[i]->unk_0x34)
            func_00421650(D_0065F420[i]);
    }
    last = D_0048D1A8;
    if (last && last->unk_0x34)
        func_00421650(last);
    D_0048D1AC = 0;
    D_0048D1B0 = 0;
    func_00428BA0();
    func_00428BA0();
    func_00427B50(0, 0);
    D_0047A934 = 0;
    if (D_0047A938 != -1) {
        func_004585A0(D_0047A938);
        D_0047A938 = -1;
    }
}

extern "C" void func_00427840(void)
{
    int i;
    int j;
    int k;
    Obj_00427470 *n;

    if (D_0049DBA0 != 0) {
        for (i = 0; (unsigned)i < D_0049DBA0->count; i++) {
            if (D_0049DBA0->nodes[i].unk_0x1C == 0) {
                D_0048D1A8 = &D_0049DBA0->nodes[i];
                continue;
            }
            n = &D_0049DBA0->nodes[i];
            for (j = 0; (unsigned)j < n->unk_0x20; j++) {
                for (k = 0; (unsigned)k < D_0049DBA0->count; k++) {
                    if (k != i && D_0049DBA0->nodes[k].unk_0x0 == n->unk_0x24[j]) {
                        n->unk_0x24[j] = k;
                        break;
                    }
                }
            }
        }
    }
}

extern "C" void func_00428360(Obj_00427470 **list, unsigned int count, bool flag)
{
    unsigned int i;

    if (func_00427760() || D_0048D1B4 != 0)
        return;
    for (i = 0; i < count; i++) {
        if (list[i]->unk_0x10 != 0 && list[i]->unk_0x34 == false) {
            func_00421210(D_0049DBB0, list[i]);
            list[i]->unk_0x34 = 1;
        } else if (list[i]->unk_0xC == 0) {
            list[i]->unk_0x34 = 1;
        } else if (list[i]->unk_0x34 == false) {
            D_0065F4A0[D_0048D1B0] = list[i];
            D_0048D1B0++;
        }
    }
    if (D_0048D1B0 != 0) {
        if (flag) {
            D_0048D1A1 = 1;
            D_0048D1A0 = 1;
            D_0065F380 = func_00455C40(func_00428430, 99);
            return;
        }
        func_00428480(1);
    }
}

extern "C" void func_004276B0(void)
{
    unsigned int i;
    unsigned int n;
    unsigned int size;
    void *p;

    D_0048D1AC = 0;
    D_0048D1B0 = 0;
    D_0047A934 = 0;
    i = 0;
    do {
        if (i != 7 && (n = D_0047A908[i]) > 0) {
            size = n * 168;
            p = func_00454B80(size, 0x76, D_0047A93C);
            D_0065F460[i] = p;
            memset(p, 0, size);
        } else {
            D_0065F460[i] = 0;
        }
        i++;
    } while (i < 11);
    D_0048D1A4 = 0;
}

extern "C" void func_00427730(void)
{
    int i;
    void **p;

    i = 0;
    for (p = D_0065F460; p < D_0065F48C; p++) {
        func_00428A70(i, 1);
        func_00454C50(*p);
        i++;
    }
}

