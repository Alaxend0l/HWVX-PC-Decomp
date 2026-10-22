/* 20 functions from 0x00406770 to 0x004076D0, found by Ghidra. */
#include "common.h"

struct List_00406770 {
    char pad_0x0[0xc];
    unsigned int count;
    int *items;
};

struct State_00407160 {
    char *p;
    unsigned char state;
};

struct Driver_00406770 {
    char unk_0x0;
    char unk_0x1;
    char pad_0x2[0x12];
    char unk_0x14;
    char pad_0x15[0x17];
    char *car;
    char pad_0x30[0x98];
    int unk_0xc8;
    char pad_0xcc;
    char unk_0xcd;
    char pad_0xce[0xa];
    List_00406770 *list;
    char pad_0xdc[4];
    int target;
    char pad_0xe4[8];
    char unk_0xec;
    char unk_0xed;
    char unk_0xee;
    char unk_0xef;
    char pad_0xf0[4];
    int unk_0xf4;
};

extern "C" int func_0046A800(void);
extern "C" float func_004535B0(void *a, void *b);
extern "C" void func_0041EC40(char *p);
float func_004532F0(float);
float func_004532D0(float y, float x);
float func_00406AB0(char *car, int target);
float func_00406A00(Driver_00406770 *d, int target);
void func_00406950(Driver_00406770 *d, int target);

struct Pair_004073A0 {
    int a;
    unsigned short b;
};

struct Mesh_004073A0 {
    unsigned count;
    int *items;
    unsigned pairCount;
    Pair_004073A0 *pairs;
    int *buf;
    unsigned *info;
};

struct Obj_004073A0 {
    Mesh_004073A0 *mesh;
    char pad_0x4[0xc];
    char *unk_0x10;
    char pad_0x14[4];
    char *unk_0x18;
    char pad_0x1c[4];
    int unk_0x20;
    float unk_0x24;
};

void func_00454CF0(void *, void *, int);
void func_0045E120(int, int, void *, int);
extern "C" void func_0044A990(char *a);
extern "C" void func_0044A910(char *a);
extern float D_0047700C;
extern float D_00477000;
extern float D_00477064;
extern float D_004770B8;
extern float D_004770BC;
extern float D_004770C0;
extern float D_004770C4;
extern float D_004770C8;
extern float D_004770CC;
extern float D_004770D0;
extern float D_004770D4;
void func_00406880(Driver_00406770 *d)
{
    if (d->unk_0xf4 == 0 && *(float *)(d->car + 0x1bc) == D_0047700C) {
        List_00406770 *list = d->list;
        int *target = &d->target;
        if (*target == 0) {
            if (list->count == 0)
                return;
            *target = list->items[func_0046A800() % list->count];
        }
        if (func_004535B0((void *)d->target, d->car + 0x40) < 25.0f) {
            func_0041EC40(d->car);
            d->unk_0xcd = 0;
        } else {
            d->unk_0xc8 = 100;
            func_00406950(d, d->target);
            d->unk_0x14 = -1;
        }
    } else {
        d->unk_0xc8 = 1000;
    }
}

void func_00406B30(Driver_00406770 *d)
{
    if (d->unk_0xec != 0) {
        d->unk_0xec--;
    } else {
        d->unk_0xed = 0x7f;
        d->unk_0xee = func_0046A800() % 256 + 0x80;
        d->unk_0xef = 1;
        d->unk_0xec = func_0046A800() % 64 + 0x40;
    }
    d->unk_0x0 = d->unk_0xee;
    d->unk_0x1 = d->unk_0xed;
    if (d->unk_0xef)
        d->unk_0x14 = -1;
}

extern int D_0053A9D4[0x12];
void func_0044A7C0(char **list, char *o);
void func_0044A790(char *list, char *o);
void func_00406FA0(Driver_00406770 *d)
{
    char *car = d->car;

    if (func_004535B0(car + 0x40, *(void **)(car + 0x90)) > 25.0f) {
        func_00406950(d, *(int *)(d->car + 0x90));
        d->unk_0x14 = -1;
        d->unk_0xc8 = 100;
    }
}

void func_00406950(Driver_00406770 *d, int target)
{
    float dist = func_004535B0(*(char **)((char *)d + 0x2c) + 0x40, (void *)target);
    float steer = func_00406A00(d, target);
    float t;

    if (dist > 10000.0f)
        dist = 10000.0f;
    if (func_004532F0(steer) > 1.5707964f)
        t = D_00477000;
    else
        t = D_0047700C - func_004532F0(steer) * 0.63661975f;
    t = dist * 0.0001f + t;
    if (t > D_0047700C)
        t = D_0047700C;
    d->unk_0x1 = (char)(t * 127.0f);
}

float func_00406A00(Driver_00406770 *d, int target)
{
    float v = func_00406AB0(*(char **)((char *)d + 0x2c), target);
    float s;

    if (v > 1.5707964f)
        s = 1.0f;
    else if (v < -1.5707964f)
        s = -1.0f;
    else
        s = v * 0.63661975f;
    if (func_004532F0(v) >= 0.1f) {
        d->unk_0x0 = (char)(s * -127.0f);
        if (d->unk_0x0 < 0x30 && d->unk_0x0 >= 0)
            d->unk_0x0 = 0x30;
        else if (d->unk_0x0 > -0x30 && d->unk_0x0 < 0)
            d->unk_0x0 = -0x30;
    }
    return v;
}

float func_00406AB0(char *car, int target)
{
    float *t = (float *)target;
    float a = func_004532D0(t[2] - *(float *)(car + 0x48), t[0] - *(float *)(car + 0x40));
    float r = func_004532D0(*(float *)(car + 0x38), *(float *)(car + 0x30)) - a;

    while (r > 3.1415927f)
        r -= 6.2831855f;
    while (r < -3.1415927f)
        r += 6.2831855f;
    return r;
}

float func_00406EE0(char *a, char *b)
{
    float r;

    if (func_00406AB0(b, (int)(a + 0x40)) < D_00477000) {
        float h = func_004532D0(*(float *)(a + 0x38), *(float *)(a + 0x30));
        r = h - func_004532D0(-*(float *)(b + 0x18), -*(float *)(b + 0x10));
    } else {
        float h = func_004532D0(*(float *)(a + 0x38), *(float *)(a + 0x30));
        r = h - func_004532D0(*(float *)(b + 0x18), *(float *)(b + 0x10));
    }
    while (r > 3.1415927f)
        r -= 6.2831855f;
    while (r < -3.1415927f)
        r += 6.2831855f;
    return r;
}

void func_00407160(State_00407160 *s)
{
    for (;;) {
        switch (s->state) {
        case 0:
            if (s->p[0x1c] != 0)
                return;
            s->state = 1;
        case 1:
            if (s->p[0x1d] != 0)
                return;
            s->state = 2;
        case 2:
            if (s->p[0x1e] != 0)
                return;
            s->state = 0;
        }
    }
}

void func_00407280(char *p, unsigned char id)
{
    char **list = (char **)(p + 0x14);
    char *o = *list;

    while (o != 0) {
        char *next = *(char **)(o + 0xa4);
        if (*(unsigned char *)(o + 0x83) == id) {
            (*(void (**)(char *))(*(char **)(o + 0x8c) + 4))(o);
            func_0044A7C0(list, o);
            *(int *)(o + 0x74) = *(int *)(o + 0x74) & ~0x200000 | 0x1000;
            func_0044A790((char *)&D_0053A9D4[*(int *)(o + 0xa8)], o);
        }
        o = next;
    }
}

void func_004072F0(char *p)
{
    func_0044A990(p + 0x14);
    func_0044A910(p + 0x14);
}

void func_00407350(int **p, void *dst)
{
    int *m = *(int **)(*p + 5);
    func_00454CF0(dst, (void *)m[4], m[0] << 5);
    *(float *)&p[9] = 1.0f;
    func_0045E120(*(int *)((char *)p[6] + 0x10), (int)p[8], dst, m[0]);
}

void func_0044A9C0(int a, char *b);
void func_0043AE90(int buf);
void func_00454CF0(void *, void *, int);
void func_0045E120(int, int, void *, int);
void func_0045E160(int, int, int, int);
void func_0045E670(int, char *);
void func_00407EF0(char *p, int);
void func_0044AD00(void *, void *, void *, void *, void *, int);
extern float D_00692350[4];
void func_00407310(char *p)
{
    if (*(int *)(p + 0x10) != 0) {
        func_0044A9C0(*(int *)(p + 0x10), p + 0x14);
        func_0043AE90(*(int *)(p + 0x10));
        *(int *)(p + 0x10) = 0;
        p[7] = 0;
    }
    func_004072F0(p);
}

void func_004073A0(int **p)
{
    unsigned i;
    int *s = (int *)(*p)[5];

    for (i = 0; i < (unsigned)(*p)[0]; i++)
        func_0045E160(((int *)(*p)[1])[i], (int)p[4], s[0], 0);
    for (i = 0; i < (unsigned)(*p)[2]; i++) {
        Pair_004073A0 *e = &((Pair_004073A0 *)(*p)[3])[i];
        func_0045E670(e->a, (char *)p[4] + e->b * 0x40);
    }
    func_00407EF0((char *)p, 0);
}

void func_00407590(char *p, unsigned *list, int c)
{
    unsigned i;
    float q[4];

    func_00407280(p, c);
    for (i = 0; i < list[0]; i++) {
        char *item = (char *)list[1] + i * 0x20;
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 1.0f;
        func_0044AD00(p + 0x14, item, item, q, D_00692350, c);
    }
}

