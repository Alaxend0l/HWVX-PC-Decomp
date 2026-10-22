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
extern volatile char D_0048D964;
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

void func_00447C60(Msg_00447C60 *msg)
{
    switch (msg->type) {
    case 5:
        if (func_0042A680(0x198, 0))
            func_004480E0(0xb);
        break;
    case 0xf:
        if (func_00427760())
            msg->unk_0x20 = 0xb;
        break;
    case 9:
        func_004480E0(2);
        break;
    case 0x11:
        D_0048D960 = msg->unk_0x24;
        D_0048D964 = 1;
    case 6:
        msg->unk_0x20 = 4;
        break;
    }
}

void func_00447FA0(void)
{
    if (D_0048D970 != NULL) {
        func_00454C50(D_0048D970);
        D_0048D970 = NULL;
    }
}

int func_004480B0(void)
{
    return D_0048D970->unk_0xd0;
}
