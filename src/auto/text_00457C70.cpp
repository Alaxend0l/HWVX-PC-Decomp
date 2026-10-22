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
    unsigned char state;
    Device *dev;

    if (D_00496E40[index].unk0 == 0)
        return 0;
    if (device == 9)
        return D_00496E40[index].unk13D;
    dev = D_00496E40[index].unk104[device];
    if (dev == NULL)
        return 0;
    dev->unk24(&state);
    return state & 1;
}

extern "C" void func_00458220(int unused, char a, char b, short c)
{
    Unk00458220 tmp;

    tmp.a = a;
    tmp.b = b;
    tmp.c = c;
    func_00458000(1, 0, 0, &tmp);
}

extern "C" int func_00458460(void)
{
    return D_00496FD0;
}

extern "C" void func_00457FA0(char enable, DeviceSlot *slot)
{
    int i;

    if (enable) {
        if (!slot->unk13D) {
            for (i = 0; i < 8; i++) {
                if (slot->unk104[i])
                    slot->unk104[i]->unk20();
            }
            slot->unk13D = 1;
        }
    }
    else if (slot->unk13D) {
        slot->unk13D = 0;
    }
}
