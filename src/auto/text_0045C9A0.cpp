/* 11 functions from 0x0045C9A0 to 0x0045D930, found by Ghidra. */
#include "common.h"
struct Iface_0045D {
    void **vtbl;
};

/* IDirectSoundBuffer-like COM interface */
struct Snd_0045D {
    virtual long __stdcall QueryInterface(void *, void **) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void *) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long *, unsigned long *) = 0;
    virtual long __stdcall GetFormat(void *, unsigned long, unsigned long *) = 0;
    virtual long __stdcall GetVolume(long *) = 0;
    virtual long __stdcall GetPan(long *) = 0;
    virtual long __stdcall GetFrequency(unsigned long *) = 0;
    virtual long __stdcall GetStatus(unsigned long *) = 0;
    virtual long __stdcall Initialize(void *, void *) = 0;
    virtual long __stdcall Lock(unsigned long, unsigned long, void **, unsigned long *, void **, unsigned long *, unsigned long) = 0;
    virtual long __stdcall Play(unsigned long, unsigned long, unsigned long) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long) = 0;
    virtual long __stdcall SetFormat(void *) = 0;
    virtual long __stdcall SetVolume(long) = 0;
    virtual long __stdcall SetPan(long) = 0;
    virtual long __stdcall SetFrequency(unsigned long) = 0;
    virtual long __stdcall Stop() = 0;
};

struct Entry18_0045D {
    Iface_0045D *unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    int unk_0x10;
    int unk_0x14;
};

struct Entry24_0045D {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    Entry18_0045D *unk_0xc;
    char unk_0x10[0x14];
};

struct Voice_0045D {
    char unk_0x0[0x2];
    unsigned char unk_0x2;
    char unk_0x3[0x12];
    char unk_0x15;
    char unk_0x16[0x3a];
};

extern Entry18_0045D D_0049BBE8[254];
extern Entry24_0045D D_0049AEFC[64];
extern Voice_0045D D_00692A00[64];
extern void (*D_006929F4)(Voice_0045D *);

void func_0045D1C0(Voice_0045D *, int);
void func_0045D630(void *, int);

void func_0045D110(int id)
{
    Entry18_0045D *b;
    Voice_0045D *v;
    int i;

    for (i = 0; i < 254; i++) {
        if (D_0049BBE8[i].unk_0x4 == id)
            break;
    }
    if (i == 254)
        return;
    b = &D_0049BBE8[i];
    if (b != NULL && (b->unk_0x8 & 1)) {
        if (b->unk_0x0 != NULL) {
            for (i = 0; i < 64; i++) {
                if (D_0049AEFC[i].unk_0xc == b) {
                    v = &D_00692A00[i];
                    if (i >= 32 && v->unk_0x15 && v->unk_0x2 != 0xff)
                        D_006929F4(v);
                    func_0045D1C0(v, 1);
                }
            }
            ((int (__stdcall *)(Iface_0045D *))b->unk_0x0->vtbl[0x48 / 4])(b->unk_0x0);
            ((int (__stdcall *)(Iface_0045D *))b->unk_0x0->vtbl[0x8 / 4])(b->unk_0x0);
            b->unk_0x0 = NULL;
        }
        b->unk_0x8 = 0;
    }
}

int func_0045D5D0(int x)
{
    float a = 9000.0f;
    float b = 600.0f;
    if (x == 0)
        return -10000;
    return (int)(b * (double)x - a);
}

int func_0045D610(int x)
{
    return x / 4;
}

void func_0045D620(void *n)
{
    func_0045D630(n, 1);
}

