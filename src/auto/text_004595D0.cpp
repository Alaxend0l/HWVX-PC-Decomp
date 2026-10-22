/* 12 functions from 0x004595D0 to 0x00459BF8, found by Ghidra. */
#include "common.h"
#include <crtdbg.h>

struct Slot_004595D0 {
    int unk_0x00;
    int unk_0x04[7];
};

struct Voice_004595D0 {
    union {
        unsigned int id;
        struct {
            char unk_0x0[0x3];
            char unk_0x3;
        };
    };
    char unk_0x4[0x11];
    char unk_0x15;
    char unk_0x16[0x34 - 0x16];
    int unk_0x34;
    int unk_0x38;
    int unk_0x3C;
    int unk_0x40;
    int unk_0x44;
    char unk_0x48[0x50 - 0x48];
};

extern int D_00497148;
extern int D_00497150;
extern Slot_004595D0 D_00497158[];
extern unsigned char D_00499118[];
extern Voice_004595D0 D_00692A00[64];
extern char D_0047C5BC[];
extern char D_0047C5F4[];
extern char D_0047C618[];

int func_00452FB0(const char *, const char *, int, int, int);
int func_0045CE10(Slot_004595D0 *);
void func_0045D110(int);
char func_0044A5A0(int);
void func_0045D630(Voice_004595D0 *, int);
void func_0045DC20(Voice_004595D0 *, int);

int func_004595D0(Slot_004595D0 *src)
{
    Slot_004595D0 *s;
    unsigned char *p;
    int i;
    int next;

    if (D_00497148 == -1)
        return 0;
    s = &D_00497158[D_00497148];
    *s = *src;
    if (!func_0045CE10(s))
        return 0;
    i = D_00497148;
    p = &D_00499118[i];
    next = *p;
    *p = 0xff;
    D_00497148 = next;
    return i + 1;
}

char func_00459630(int handle)
{
    unsigned int idx;
    int p;

    if ((!handle || !D_0047C618) && func_00452FB0(D_0047C5BC, D_0047C5F4, 0x13b, 0, 0))
        _CrtDbgBreak();
    idx = handle - 1;
    if (idx < 0xfe && (p = D_00497158[idx].unk_0x00) != 0) {
        func_0045D110(p);
        D_00499118[idx] = (unsigned char)D_00497148;
        D_00497148 = idx;
        D_00497158[idx].unk_0x00 = 0;
        return func_0044A5A0(p);
    }
    return 0;
}

void func_004596C0(int arg)
{
    Voice_004595D0 *v;
    int i;

    D_00497150 = arg;
    v = D_00692A00;
    for (i = 64; i != 0; i--, v++) {
        if (v->unk_0x3 != 1 || v->unk_0x15 != 1)
            continue;
        func_0045DC20(v, D_00497150);
    }
}

void func_00459950(unsigned int id)
{
    Voice_004595D0 *v = &D_00692A00[id & 0xff];
    unsigned int vid = v->id;

    if (vid == id)
        func_0045D630(v, 3);
}
