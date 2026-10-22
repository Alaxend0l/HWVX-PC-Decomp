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
    char unk_0x08[0x0c - 0x08];
    int unk_0x0c;
    int unk_0x10;
    int delay;
};

extern Task_00401090 *D_004806E0[80];
extern int D_00480820;
extern int D_00480824;
extern int D_0068DD20;
extern int D_0068DD24;
extern char D_0047A0F0[];

struct Group_004018C0 {
    char value;
    char unk_0x01[3];
    unsigned int count;
    char *items[1];
};

struct Item_004018C0 {
    char unk_0x00[0x50];
    char unk_0x50;
};

static inline unsigned int FindFreeTask_00401090(void)
{
    unsigned int i = 0;
    Task_00401090 **p;
    for (p = D_004806E0; p < (Task_00401090 **)&D_00480820; p++, i++) {
        if (*p == NULL)
            return i;
    }
    return 80;
}

extern "C" void func_00452F70(const char *fmt, ...);
extern "C" unsigned int func_0042A680(int, int);
void func_0043EA50(int, int);
extern void (*D_0047A040[])(TaskArg_00401090 *);
extern u32 D_00692370;

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
        if (*p != NULL && (*p)->delay <= 0) {
            D_0047A040[(*p)->type]((*p)->arg);
            if (!((*p)->type == 0x14 && (*p)->arg->unk_0x4 != 0))
                *p = NULL;
        } else if (*p != NULL) {
            (*p)->delay = (*p)->delay - D_00692370;
        }
    }
}

void func_00401120(void)
{
    memset(D_004806E0, 0, sizeof(D_004806E0));
}

int func_00401140(Task_00401090 *task)
{
    unsigned int i = FindFreeTask_00401090();
    if (i >= 80) {
        func_00452F70(D_0047A0F0, 80);
        return 1;
    }
    if (task->unk_0x10 != -1)
        task->unk_0x10--;
    D_004806E0[i] = task;
    task->delay = task->unk_0x0c;
    return task->unk_0x10 != 0;
}

char func_004018C0(Group_004018C0 *g)
{
    unsigned int i;
    for (i = 0; i < g->count; i++)
        g->items[i][0x50] = g->value;
    return 1;
}

void func_00401F40(void)
{
    D_00480820 = 0;
    D_0068DD20 = -1;
    D_00480824 = 0;
    if (func_0042A680(0x12d, 0) >= 3)
        D_0068DD24 = 8000;
}

void func_00401FA0(int a, int b)
{
    func_0043EA50(a, b);
}

void func_00401FC0(void)
{
    func_00402290();
    func_00405CC0();
}
