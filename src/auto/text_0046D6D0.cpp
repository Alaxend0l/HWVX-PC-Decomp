/* 16 functions from 0x0046D6D0 to 0x0046E5D3, found by Ghidra. */
#include "common.h"

struct XcptAction_0046D6D0 {
    unsigned long XcptNum;
    int SigNum;
    void *XcptAction;
};

extern "C" void *(__stdcall *_imp__GetModuleHandleA)(const char *name);
#define GetModuleHandleA (*_imp__GetModuleHandleA)
extern int D_0047D7B4;
extern int D_006D6B08;
extern unsigned char *D_006D6B14;
extern "C" void func_00472B36(void);
extern "C" int func_0047271C(unsigned int c);

#pragma optimize("s", on)

extern "C" XcptAction_0046D6D0 *func_0046DD7B(unsigned long xcptnum, XcptAction_0046D6D0 *table)
{
    XcptAction_0046D6D0 *p = table;

    while (p->XcptNum != xcptnum && ++p < table + D_0047D7B4)
        ;
    if (p >= table + D_0047D7B4 || p->XcptNum != xcptnum)
        return NULL;
    return p;
}

extern "C" unsigned char *func_0046DDB5(void)
{
    unsigned char *p;

    if (D_006D6B08 == 0)
        func_00472B36();
    p = D_006D6B14;
    if (*p == '"') {
        while (*++p != '"' && *p != '\0') {
            if (func_0047271C(*p))
                p++;
        }
        if (*p == '"')
            p++;
    } else {
        while (*p > ' ')
            p++;
    }
    while (*p != '\0' && *p <= ' ')
        p++;
    return p;
}

extern "C" void func_0046E401(unsigned char *ver)
{
    unsigned char *base;
    int off;

    *(int *)ver = 0;
    base = (unsigned char *)GetModuleHandleA(NULL);
    if (*(unsigned short *)base == 0x5a4d && (off = *(int *)(base + 0x3c)) != 0) {
        base += off;
        ver[0] = base[0x1a];
        ver[1] = base[0x1b];
    }
}
