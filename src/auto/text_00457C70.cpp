/* 32 functions from 0x00457C70 to 0x00458BE0, found by Ghidra. */
#include "common.h"
class Device {
public:
    virtual void __stdcall unk00();
    virtual void __stdcall unk04();
    virtual void __stdcall unk08();
    virtual void __stdcall unk0C();
    virtual void __stdcall unk10();
    virtual void __stdcall unk14();
    virtual void __stdcall unk18();
    virtual void __stdcall unk1C();
    virtual void __stdcall unk20();
    virtual void __stdcall unk24(unsigned char *out);
};

struct DeviceSlot {
    int unk0;
    char pad4[0x100];
    Device *unk104[14];
    char unk13C;
    char unk13D;
    char pad13E[6];
};

struct Unk00458220 {
    char a;
    char b;
    short c;
};

extern "C" DeviceSlot D_00496E40[];
extern "C" int D_00496FD0;
extern "C" void func_00458000(int, int, int, void *);

extern "C" unsigned char func_004581C0(int index, int device)
{
    unsigned char result;
    unsigned char state;
    Device *dev;

    result = 0;
    if (D_00496E40[index].unk0) {
        if (device == 9)
            return D_00496E40[index].unk13D;
        if ((dev = D_00496E40[index].unk104[device]) != NULL) {
            dev->unk24(&state);
            result = state & 1;
        }
    }
    return result;
}

extern "C" void func_00458220(int unused, char a, char b, short c)
{
    Unk00458220 tmp = { a, b, c };

    func_00458000(1, 0, 0, &tmp);
}

extern "C" void func_00458250(int unused, short a, short b)
{
    short tmp[2];

    tmp[0] = a;
    tmp[1] = b;
    func_00458000(1, 0, 1, tmp);
}

extern "C" int func_00458460(void)
{
    return D_00496FD0;
}

extern "C" void func_00457FA0(char enable, DeviceSlot *slot)
{
    int i;

    if (enable) {
        if (slot->unk13D)
            return;
        for (i = 0; i < 8; i++) {
            if (slot->unk104[i])
                slot->unk104[i]->unk20();
        }
        slot->unk13D = 1;
        return;
    }
    if (slot->unk13D)
        slot->unk13D = 0;
}

extern "C" bool func_004582E0(int index)
{
    return D_00496E40[index].unk0 != 0;
}

extern "C" void func_00458280(void)
{
    func_00458000(1, 0, 9, 0);
}

extern "C" void func_004582A0(void)
{
    func_00458000(0, 0, 9, 0);
}

