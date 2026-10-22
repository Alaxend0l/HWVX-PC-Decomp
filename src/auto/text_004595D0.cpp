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
    char unk_0x16[0x50 - 0x16];
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
