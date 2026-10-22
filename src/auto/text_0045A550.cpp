/* 11 functions from 0x0045A550 to 0x0045B480, found by Ghidra. */
#include "common.h"

struct Sound_0045A550 {
    char unk_0x00[0x1e];
    unsigned short unk_0x1e;
};

struct Voice_0045A550 {
    char unk_0x00[4];
    Voice_0045A550 *next;
    char unk_0x08[0x10 - 0x08];
    Sound_0045A550 *sound;
    char unk_0x14;
    char unk_0x15;
    unsigned char unk_0x16;
    char unk_0x17;
    int unk_0x18;
    int unk_0x1c;
};

struct VoiceList_0045A550 {
    Voice_0045A550 *head;
};

struct Format_0045A550 {
    char unk_0x00[0xa];
    unsigned char unk_0x0a;
    unsigned char unk_0x0b;
    char unk_0x0c[0x14 - 0x0c];
    int unk_0x14;
};

extern int D_00692998;

int __fastcall func_00459CB0(unsigned int, int);
void func_00401090(Voice_0045A550 *);
unsigned int func_0045AF20(unsigned int rate);

static inline void StartVoice_0045A550(Voice_0045A550 *v, unsigned char state)
{
    int step;
    if (v->unk_0x16 == state)
        return;
    v->unk_0x16 = state;
    v->unk_0x17 = 0;
    step = func_0045AF20(v->sound->unk_0x1e);
    if (step == -1) {
        v->unk_0x1c = 0x10000;
        step = 0;
    }
    v->unk_0x18 = step;
    v->unk_0x14 -= 15;
    func_00401090(v);
}

unsigned int func_0045AF20(unsigned int rate)
{
    return (unsigned short)rate ? 0xffffffff / ((unsigned short)rate * 1000) : 0xffffffff;
}

void func_0045AF90(Voice_0045A550 *v)
{
    int step;
    unsigned char state = 4;
    if (v->unk_0x16 != state) {
        v->unk_0x16 = state;
        v->unk_0x17 = 0;
        step = func_0045AF20(v->sound->unk_0x1e);
        if (step == -1) {
            v->unk_0x1c = 0x10000;
            step = 0;
        }
        v->unk_0x18 = step;
        v->unk_0x14 -= 15;
        func_00401090(v);
    }
}

void func_0045AF50(Format_0045A550 *fmt)
{
    int n = fmt->unk_0x0a * fmt->unk_0x0b;
    fmt->unk_0x14 = func_00459CB0((unsigned int)(n * n) / 3970, D_00692998);
}

void func_0045AF90(Voice_0045A550 *v);
void func_0045AFE0(VoiceList_0045A550 *list)
{
    Voice_0045A550 *v;
    for (v = list->head; v != NULL; v = v->next)
        func_0045AF90(v);
}

