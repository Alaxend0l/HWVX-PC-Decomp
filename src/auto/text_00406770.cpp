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
    char pad_0xe4[0x10];
    int unk_0xf4;
};

extern "C" int func_0046A800(void);
extern "C" float func_004535B0(void *a, void *b);
extern "C" void func_0041EC40(char *p);
float func_004532F0(float);
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
void func_004072F0(char *p)
{
    func_0044A990(p + 0x14);
    func_0044A910(p + 0x14);
}
