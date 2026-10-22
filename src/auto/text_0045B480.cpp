/* 8 functions from 0x0045B480 to 0x0045BB10, found by Ghidra. */
#include "common.h"
struct Node_0045B {
    char unk_0x0[0x4];
    Node_0045B *next;
};

struct Chan_0045B {
    Node_0045B *head;
    char unk_0x4[0xd];
    unsigned char unk_0x11;
    char unk_0x12[0x8];
    unsigned short unk_0x1a;
    char unk_0x1c[0x54];
};

struct Voice_0045B {
    char unk_0x0[0x3];
    char unk_0x3;
    char unk_0x4[0x11];
    char unk_0x15;
    char unk_0x16[0x1e];
    int unk_0x34;
    char unk_0x38[0x18];
};

extern Chan_0045B D_00499A68[32];
extern char D_0049A868[];
extern unsigned int D_006929AC;
extern int D_0049A898;
extern int D_0049A884;
extern int D_006929C0[8];
extern char D_0047CA0C[];
extern char D_0047C984[];
extern char D_0047C9D4[];
extern Voice_0045B D_00692A00[64];

int func_00452FB0(const char *, const char *, int, int, int);
void func_0045B680(int);
void func_0045E0C0(int);
void func_0045DC20(Node_0045B *, int);
int __fastcall func_0045E100(void *, Chan_0045B *);
void func_0045DD10(Voice_0045B *);

void func_0045B8F0(void)
{
    Chan_0045B *c;
    Node_0045B *n;
    int i;
    int v;

    c = D_00499A68;
    for (i = 32; i != 0; i--) {
        n = c->head;
        v = (unsigned short)func_0045E100(D_0049A868, c);
        c->unk_0x1a = v;
        for (; n != NULL; n = n->next)
            func_0045DC20(n, v);
        c++;
    }
}

void func_0045B940(int arg)
{
    Voice_0045B *v;
    int i;

    D_0049A884 = arg;
    v = D_00692A00;
    for (i = 64; i != 0; i--) {
        if (v->unk_0x15 != 0 && v->unk_0x3 == 0) {
            v->unk_0x34 = arg;
            func_0045DD10(v);
        }
        v++;
    }
}

void func_0045BA60(unsigned int mask, char global)
{
    unsigned char *p;

    if (global) {
        D_006929AC |= mask;
    } else {
        p = &D_00499A68[0].unk_0x11;
        while (mask != 0) {
            *p |= mask & 1;
            mask >>= 1;
            p += sizeof(Chan_0045B);
        }
    }
}
