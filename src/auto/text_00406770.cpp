/* 20 functions from 0x00406770 to 0x004076D0, found by Ghidra. */
#include "common.h"

struct List_00406770 {
    char pad_0x0[0xc];
    unsigned int count;
    int *items;
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

void func_004072F0(char *p)
{
    func_0044A990(p + 0x14);
    func_0044A910(p + 0x14);
}
