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
    char unk_0x16;
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
