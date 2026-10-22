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
