/* 9 functions from 0x00442C10 to 0x004439C0, found by Ghidra. */
#include "common.h"
struct Ent_00443 {
    char unk_0x0[0x4];
    char unk_0x4;
    char unk_0x5[0x6f];
    unsigned int unk_0x74;
    char unk_0x78[0x50];
    Ent_00443 *unk_0xc8;
    char unk_0xcc[0x4];
    int unk_0xd0[4];
};

struct Rect_00443 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
};

struct Spawn_00443 {
    Rect_00443 rect;
    Ent_00443 *owner;
    char unk_0x14;
};

extern Rect_00443 D_00692350;
extern char D_0048D974;

void func_004506E0(void);
char func_00409E40(int);
void func_00409DD0(int);
void func_00448330(Ent_00443 *);
unsigned char func_00440130(void);
Ent_00443 *func_0044D0B0(int, Spawn_00443 *);
unsigned int func_0044D8F0(Ent_00443 **, int);
void func_00443560(Ent_00443 *);
Ent_00443 *func_00443740(Ent_00443 *, Rect_00443 *);

void func_00443940(Ent_00443 *e)
{
    if (e != (Ent_00443 *)-1 && e != NULL)
        func_00443560(e);
}
