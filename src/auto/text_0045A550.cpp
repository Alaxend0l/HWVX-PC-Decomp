/* 11 functions from 0x0045A550 to 0x0045B480, found by Ghidra. */
#include "common.h"
#include <string.h>
#include <crtdbg.h>

struct Sound_0045A550 {
    char unk_0x00[0x1e];
    unsigned short unk_0x1e;
};

struct Voice_0045A550 {
    char unk_0x00[2];
    unsigned char chan;
    char unk_0x03;
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

struct Chan_00499260 {
    Voice_0045A550 *head;
    char flags;
    char unk_0x05[0x18 - 0x05];
    int unk_0x18;
    char unk_0x1c;
    unsigned char unk_0x1d;
    char unk_0x1e;
    unsigned char unk_0x1f;
};

struct Mode_00499660 {
    int unk_0x0;
    char unk_0x4;
    char unk_0x5;
    char unk_0x6[2];
};

struct Chan_00499A68 {
    int unk_0x00;
    int unk_0x04;
    char unk_0x08[0x10 - 0x08];
    unsigned char index;
    char unk_0x11[0x70 - 0x11];
};

extern Chan_00499260 D_00499260[16];
extern Mode_00499660 D_00499660[];
extern Chan_00499A68 D_00499A68[32];
extern char D_0049A868[0x30];
extern int D_0049A898;
extern unsigned int D_006929AC;
extern unsigned int D_00692990;
extern int D_00499230;
extern int D_00499238;
extern int D_00499244;
extern int D_00499248;
extern char D_0049924C;
extern char D_0049924D;
extern unsigned char D_0049924E;
extern char D_0047C730[];
extern char D_0047C83C[];
extern char D_0047C818[];

int func_00452FB0(const char *, const char *, int, int, int);
void func_0045A4A0(unsigned int, int);
int func_0045DF40(int *);

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

void func_0045AFE0(VoiceList_0045A550 *list);
void func_0045B330(void)
{
    int i;
    Chan_00499260 *c;
    func_0045A4A0(D_006929AC, 0);
    if (D_00692990 != 0) {
        for (i = 0; ; i++)
            D_00499260[i].flags &= ~(D_00692990 & 1);
    }
    D_006929AC = 0;
    D_00692990 = 0;
    D_00499230 = 0;
    D_00499238 = 0;
    D_00499244 = D_00499660[D_0049924E].unk_0x0;
    D_00499248 = func_0045DF40(&D_00499244);
    D_0049924C = D_00499660[D_0049924E].unk_0x4;
    D_0049924D = D_00499660[D_0049924E].unk_0x5;
    c = D_00499260;
    for (i = 0; i < 16; i++, c++) {
        func_0045AFE0((VoiceList_0045A550 *)c);
        c->unk_0x1f = 0;
        c->unk_0x1d = 0x40;
        c->unk_0x18 = 0x10000;
    }
    D_0049924E = 0;
}

unsigned int func_0045AF20(unsigned int rate)
{
    if ((unsigned short)rate != 0)
        return 0xffffffff / ((unsigned short)rate * 1000U);
    return 0xffffffff;
}

void func_0045AF90(Voice_0045A550 *v)
{
    StartVoice_0045A550(v, 4);
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

void func_0045B000(Voice_0045A550 *v)
{
    Voice_0045A550 *prev = D_00499260[v->chan].head;
    if (prev == v) {
        if (prev == v->next && func_00452FB0(D_0047C83C, D_0047C730, 0x4dd, 0, 0))
            _CrtDbgBreak();
        D_00499260[v->chan].head = v->next;
    } else {
        while (prev->next != v)
            prev = prev->next;
        if ((prev == NULL || prev == v->next) && func_00452FB0(D_0047C818, D_0047C730, 0x4e7, 0, 0))
            _CrtDbgBreak();
        prev->next = v->next;
    }
    v->unk_0x15 = 0;
    v->chan = 0xff;
}

char func_0045B400(void)
{
    unsigned char i;
    memset(D_0049A868, 0, sizeof(D_0049A868));
    memset(D_00499A68, 0, sizeof(D_00499A68));
    i = 0;
    do {
        D_00499A68[i].index = i;
    } while (++i < 32);
    D_0049A898 = 0;
    return 1;
}

