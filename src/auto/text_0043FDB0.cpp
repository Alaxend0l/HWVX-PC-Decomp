/* 22 functions from 0x0043FDB0 to 0x00440DB0, found by Ghidra. */
#include "common.h"
struct Player_0043FDB0 {
    char unk_0x00[0x60];
    int unk_0x60;
    char unk_0x64[0x6c - 0x64];
    unsigned unk_0x6c;
    char unk_0x70[0xb0 - 0x70];
    Player_0043FDB0 *next;
    Player_0043FDB0 *prev;
    char unk_0xb8[0xc8 - 0xb8];
    int unk_0xc8;
};

struct Car_0043FDB0 {
    char unk_0x00[0x94];
    Player_0043FDB0 *player;
};

struct Item_0043FDB0 {
    char unk_0x00[0x28];
    Car_0043FDB0 *car;
};

struct Msg_0043FDB0 {
    int type;
    int unk_0x04;
    unsigned count;
    Item_0043FDB0 *items[1];
};

extern int D_0053B260;

extern "C" char func_0043E9F0(Player_0043FDB0 *p);
extern "C" void func_004591B0(int index, char value);
extern "C" char *func_0042B040(int i);

extern "C" void func_004403C0(void)
{
    D_0053B260 = 0;
}
