/* 6 functions from 0x004439C0 to 0x004449B0, found by Ghidra. */
#include "common.h"

struct Obj_0048D7C0 {
    char pad_0x00[0x24];
    int *unk_0x24;
    char pad_0x28[0x34 - 0x28];
    unsigned int unk_0x34;
    int *unk_0x38;
};

struct Msg_00443D70 {
    int unk_0x00;
    short unk_0x04;
};

extern "C" Obj_0048D7C0 *D_0048D7C0;
extern "C" char D_0048D7C8;
extern "C" int D_0053B15C;
extern "C" char D_0053B1F0;

extern "C" void func_00428A70(int, int);
extern "C" int func_0042A680(int, int);
extern "C" void func_004480E0(int);

extern "C" void func_00443D20(void)
{
    func_00428A70(3, 1);
}

extern "C" int func_00443D30(unsigned int i)
{
    if (func_0042A680(0x198, 0)) {
        if (D_0048D7C0)
            return D_0048D7C0->unk_0x24[2];
    } else {
        if (D_0048D7C0 && i < D_0048D7C0->unk_0x34)
            return D_0048D7C0->unk_0x38[i];
    }
    return 0;
}

extern "C" void func_00443D70(Msg_00443D70 *msg)
{
    if (msg->unk_0x04 == 5) {
        if (func_0042A680(0x198, 0))
            func_004480E0(0xb);
        D_0048D7C8 = 0;
    }
}

