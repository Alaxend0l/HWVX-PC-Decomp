/* 13 functions from 0x00447390 to 0x00448330, found by Ghidra. */
#include "common.h"

struct State_0048D970 {
    char unk_0x00[0xd0];
    int unk_0xd0;
};

struct Msg_00447C60 {
    int unk_0x00;
    unsigned short type;
    char unk_0x06[0x20 - 0x06];
    int unk_0x20;
    int unk_0x24;
};

extern int D_0048D95C;
extern int D_0048D960;
extern char D_0048D964;
extern State_0048D970 *D_0048D970;
extern int D_0053AA24;

extern "C" void func_00454C50(void *p);
int func_0042A680(int, int);
char func_00427760(void);
void func_004480E0(int);

void func_00447910(int a, int b)
{
    D_0048D95C = a;
    D_0053AA24 = b;
}

int func_004480B0(void)
{
    return D_0048D970->unk_0xd0;
}
