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

void func_0044B900(void)
{
    func_0044B910();
    func_00401090();
}
