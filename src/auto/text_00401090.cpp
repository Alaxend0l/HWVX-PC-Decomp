/* 13 functions from 0x00401090 to 0x00401FC8, found by Ghidra. */
#include "common.h"
#include <string.h>

struct TaskArg_00401090 {
    int unk_0x0;
    int unk_0x4;
};

struct Task_00401090 {
    int type;
    TaskArg_00401090 *arg;
    char unk_0x08[0x14 - 0x08];
    int delay;
};

extern Task_00401090 *D_004806E0[80];
extern void (*D_0047A040[])(TaskArg_00401090 *);
extern int D_00692370;

void func_00402290(void);
void func_00405CC0(void);

void func_004010A0(void)
{
    memset(D_004806E0, 0, sizeof(D_004806E0));
}

void func_004010C0(void)
{
    Task_00401090 **p;
    for (p = D_004806E0; p < D_004806E0 + 80; p++) {
        Task_00401090 *t = *p;
        if (t != NULL) {
            if (t->delay <= 0) {
                D_0047A040[t->type](t->arg);
                if ((*p)->type != 0x14 || (*p)->arg->unk_0x4 == 0)
                    *p = NULL;
            } else if (t != NULL) {
                t->delay -= D_00692370;
            }
        }
    }
}

void func_00401120(void)
{
    memset(D_004806E0, 0, sizeof(D_004806E0));
}

void func_00401FC0(void)
{
    func_00402290();
}
