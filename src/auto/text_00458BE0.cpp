/* 10 functions from 0x00458BE0 to 0x00459212, found by Ghidra. */
#include "common.h"
#include <string.h>

struct Unk006924C8 {
    unsigned int flags;
    char pad4[0x2C];
};

extern "C" char D_00692400[];
extern "C" char D_0047C468[];
extern "C" char D_006924C1[];
extern "C" char D_006924C2[];
extern "C" Unk006924C8 D_006924C8[];
extern "C" Unk006924C8 D_006924F8[];
extern "C" Unk006924C8 D_006924C4[];
extern "C" Unk006924C8 D_006924F4[];
extern "C" char D_006924A0[];
extern "C" char D_006924C3[];
extern "C" char D_006924D0[];
extern "C" char D_00692518[];
extern "C" char D_00692380[];
extern "C" char D_006923C0[];
extern "C" char D_00692440[];
extern "C" char D_00692480[];
extern "C" void func_00458910(char *);
extern "C" int func_00458EB0(void);

static inline void ActivateSlot(int slot)
{
    D_006924C1[slot * 0x30] = 1;
    D_006924C2[slot * 0x30] = 1;
}

extern "C" void func_00458BE0(const char *name)
{
    char path[256];

    strcat(strcat(strcpy(path, D_00692400), D_0047C468), name);
    func_00458910(path);
}

extern "C" int func_00458EB0(void)
{
    short i;

    for (i = 0; i < 1; i++) {
        if (D_006924C1[i * 0x30] == 0) {
            D_006924C1[i * 0x30] = 1;
            D_006924C2[i * 0x30] = 1;
            return i;
        }
    }
    return -2;
}

extern "C" void func_00458EF0(int id)
{
    unsigned int slot = id - 1;

    if (slot > 1) {
        func_00458EB0();
        return;
    }
    ActivateSlot(slot);
}

extern "C" unsigned char func_004590E0(int index, unsigned char bit)
{
    Unk006924C8 *p;

    if (bit > 20)
        return 0;
    if (index == -1) {
        for (p = D_006924C8; p < D_006924F8; p++) {
            if ((p->flags >> bit) & 1)
                return 1;
        }
        return 0;
    }
    return (D_006924C8[index].flags >> bit) & 1;
}

extern "C" char func_00459140(int index, unsigned char bit)
{
    Unk006924C8 *p;

    if (bit == 0xff)
        return 0;
    if (index == -1) {
        for (p = D_006924C4; p < D_006924F4; p++) {
            if ((p->flags >> bit) & 1)
                return D_006924A0[bit];
        }
        return 0;
    }
    if ((D_006924C4[index].flags >> bit) & 1)
        return D_006924D0[index * 0x30 + bit];
    return 0;
}

extern "C" void func_004591B0(int index, char value)
{
    D_006924C3[index * 0x30] = value;
}

extern "C" char func_004591D0(void)
{
    char *p;
    int i;

    p = D_00692518;
    for (i = 4; i != 0; i--) {
        *p = 0xff;
        p += 0x1c;
    }
    D_00692380[0] = 0;
    D_006923C0[0] = 0;
    D_00692400[0] = 0;
    D_00692440[0] = 0;
    D_00692480[0] = 0;
    return 1;
}

