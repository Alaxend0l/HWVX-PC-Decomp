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
