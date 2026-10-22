/* 15 functions from 0x00401FD0 to 0x00402FB0, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Task_00480820 {
    int unk_0x0;
    void (*unk_0x4)(...);
    Task_00480820 *unk_0x8;
    char unk_0xc;
};

extern "C" unsigned int D_00692370;
extern "C" short D_00480828;
extern "C" unsigned int D_0068DD5C;
extern "C" Task_00480820 *D_00480820;
extern "C" Task_00480820 *D_00480824;
extern float D_00477000;
extern float D_00477010;
extern float D_00477014;
extern float D_00477018;

struct Node_00402680 {
    char unk_0x0[0x24];
    float unk_0x24;
};

struct Obj_00402210 {
    char unk_0x0[0x1c];
    char unk_0x1c;
    char unk_0x1d[0x2c - 0x1d];
    char *unk_0x2c;
    char unk_0x30[0xb8 - 0x30];
    Task_00480820 unk_0xb8;
    unsigned int unk_0xc8;
    char unk_0xcc;
    char unk_0xcd;
    char unk_0xce[0x3e8 - 0xce];
    int unk_0x3e8;
    char *unk_0x3ec;
    char unk_0x3f0[0x414 - 0x3f0];
    Node_00402680 *unk_0x414[0x20];
    int unk_0x494;
    unsigned int unk_0x498;
    int unk_0x49c;
    char unk_0x4a0[0x5fc - 0x4a0];
    int unk_0x5fc;
};

extern "C" int func_0044D630(char *, void *, float *, char, char);
extern "C" int func_00454AF0(int, int);

extern "C" char func_0043FD40(Obj_00402210 *);
extern "C" int func_0043B980(int, int);
extern "C" void func_0043B8B0(int, Node_00402680 **, int);
extern "C" void func_00402680(Obj_00402210 *, int);
extern "C" float func_00454340(char *, Node_00402680 *, Node_00402680 *);
extern "C" float func_004535B0(Node_00402680 *, char *);
extern "C" unsigned int func_00401FD0(unsigned int *p);
extern "C" void func_004021D0(Task_00480820 *t);

extern "C" unsigned int func_00401FD0(unsigned int *p)
{
    if (*p > D_00692370)
        *p -= D_00692370;
    else
        *p = 0;
    return *p;
}

extern "C" void func_004021D0(Task_00480820 *t)
{
    if (t->unk_0xc == 0) {
        t->unk_0x8 = NULL;
        if (D_00480824 != NULL) {
            D_00480824->unk_0x8 = t;
            D_00480824 = t;
        } else {
            D_00480820 = t;
            D_00480824 = t;
        }
        t->unk_0xc = 1;
    }
}

extern "C" char func_004025C0(Obj_00402210 *o, int a, int b)
{
    char r;
    int h;
    Node_00402680 **list = o->unk_0x414;
    memset(list, 0, sizeof(o->unk_0x414));
    o->unk_0x498 = 0;
    r = 1;
    h = func_0043B980(a, b);
    if (h != 0) {
        func_0043B8B0(h, list, 0x20);
        o->unk_0x49c = b;
        func_00402680(o, 1);
        while (o->unk_0x498 < 0x1f) {
            Node_00402680 *p0 = o->unk_0x414[o->unk_0x498];
            Node_00402680 *p1 = o->unk_0x414[o->unk_0x498 + 1];
            if (p0 == NULL || p1 == NULL)
                break;
            if (func_00454340(o->unk_0x2c + 0x40, p0, p1) < D_00477000)
                break;
            func_00402680(o, 0);
        }
    } else {
        o->unk_0x49c = -1;
        r = 0;
    }
    return r;
}

extern "C" char func_00402210(Obj_00402210 *o)
{
    char cd;
    unsigned int *t;
    if (!func_0043FD40(o))
        return 0;
    cd = o->unk_0xcd;
    o->unk_0x1c = 0;
    if (cd && o->unk_0x2c == NULL)
        o->unk_0xcc = 1;
    t = &o->unk_0xc8;
    if (*t != 0 && func_00401FD0(t) == 0)
        func_004021D0(&o->unk_0xb8);
    if (o->unk_0xcc || o->unk_0xcd)
        return 1;
    return 1;
}

extern "C" void func_00402280(int p)
{
    *(int *)(p + 0xc8) = 500;
}

extern "C" void func_004027C0(Obj_00402210 *o)
{
    char *v = o->unk_0x2c;
    Node_00402680 *n;
    while (o->unk_0x498 < 0x20 && (n = o->unk_0x414[o->unk_0x498]) != NULL) {
        float r;
        float d = func_004535B0(n, v + 0x40);
        r = n->unk_0x24;
        if (!(d < r * r))
            break;
        func_00402680(o, 0);
    }
}

extern "C" void func_00402E10(Obj_00402210 *o)
{
    float f;
    if (o->unk_0x2c != NULL) {
        void *t = NULL;
        if (o->unk_0x498 < 0x20 && o->unk_0x414[o->unk_0x498] != NULL)
            t = o->unk_0x414[o->unk_0x498];
        else if (o->unk_0x3ec != NULL)
            t = o->unk_0x3ec + 0x40;
        o->unk_0x3e8 = 0;
        if (t != NULL) {
            f = 1.0f;
            o->unk_0x3e8 = func_0044D630(o->unk_0x2c + 0x40, t, &f, 1, 0);
        }
    }
    o->unk_0x5fc = func_00454AF0(400, 400);
}

extern "C" char func_004020C0(float a, float b, float c)
{
    float d;
    if (b == D_00477000 && c == D_00477000)
        return 1;
    if (c == D_00477018)
        return 1;
    if (b > D_00477018)
        b -= D_00477014;
    d = a - b;
    if (d > D_00477018)
        d -= D_00477014;
    else if (d < D_00477010)
        d += D_00477014;
    if (d <= c && d >= -c)
        return 1;
    return 0;
}

extern "C" char func_00402170(void)
{
    Task_00480820 *t;
    if (D_00480828 > 5 || D_0068DD5C < 0xfa) {
        D_00480828 = 0;
        t = D_00480820;
        if (t != NULL) {
            D_00480820 = t->unk_0x8;
            if (D_00480820 == NULL)
                D_00480824 = NULL;
            if (t->unk_0x0 != 0) {
                t->unk_0xc = 0;
                t->unk_0x4(t->unk_0x0);
            } else {
                t->unk_0xc = 0;
                t->unk_0x4();
            }
            return 1;
        }
    }
    return 0;
}

