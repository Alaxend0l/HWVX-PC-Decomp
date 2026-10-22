/* 13 functions from 0x00447390 to 0x00448330, found by Ghidra. */
#include "common.h"

struct State_0048D970 {
    char unk_0x00[0xd0];
    int unk_0xd0;
    int unk_0xd4;
};

struct Mat_006922E0 {
    float m[16];
};

struct Body_004482C0 {
    float unk_0x00[3];
    char unk_0x0c[4];
    Mat_006922E0 mat;
    float unk_0x50[4];
    float unk_0x60[3];
    char unk_0x6c[4];
    int unk_0x70;
    int unk_0x74;
    char unk_0x78[8];
    short unk_0x80;
    char unk_0x82;
    char unk_0x83;
    int unk_0x84;
    int unk_0x88;
    char unk_0x8c[8];
    int unk_0x94;
};

extern Mat_006922E0 D_006922E0;
int func_00458420(int);

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
        if (func_0042A680(0x198, 0) != 0)
            func_004480E0(0xb);
        return;
    case 0xf:
        if (func_00427760())
            msg->unk_0x20 = 0xb;
        return;
    case 9:
        func_004480E0(2);
        return;
    case 0x11:
        D_0048D960 = msg->unk_0x24;
        D_0048D964 = 1;
    case 6:
        msg->unk_0x20 = 4;
    default:
        return;
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

int func_004480C0(void)
{
    int v = D_0048D970->unk_0xd4;
    D_0048D970->unk_0xd4 = -1;
    return v;
}

