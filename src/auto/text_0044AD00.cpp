/* 8 functions from 0x0044AD00 to 0x0044B9B0, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Obj_0053A9D0;

struct Funcs_0053A9D0 {
    void (*unk_0x00)(Obj_0053A9D0 *);
    void (*unk_0x04)(Obj_0053A9D0 *);
};

struct Obj_0053A9D0 {
    char unk_0x00[0x8c];
    Funcs_0053A9D0 *unk_0x8c;
    char unk_0x90[0xa4 - 0x90];
    Obj_0053A9D0 *unk_0xa4;
};

struct List_0044B310 {
    unsigned int count;
    char *items;
};

extern float D_00692350[4];
extern Obj_0053A9D0 *D_0053A9D0;
extern int D_0053A9D4[0x12];

void func_00401090(void);
void func_0044B910(void);
void func_0041B600(void);
void func_0041B570(void);
void func_0044B390(void);
void func_0041C180(void);
void func_0041E120(void);
void func_0044AA50(void);
void func_0044A8A0(int, int);
void func_0044AD00(int, char *, char *, float *, float *, int);

void func_0044B310(int a, List_0044B310 *list, int c)
{
    unsigned int i;
    float q[4];

    func_0044A8A0(a, c);
    for (i = 0; i < list->count; i++) {
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 1.0f;
        func_0044AD00(a, list->items + i * 0x20, list->items + i * 0x20, q, D_00692350, c);
    }
}

void func_0044B8A0(void)
{
    func_0041B600();
    func_0041B570();
    func_0044B390();
    func_0041C180();
    func_0041E120();
    func_0044AA50();
}

void func_0044B900(void)
{
    func_0044B910();
    func_00401090();
}
