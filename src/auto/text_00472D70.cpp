/* 9 functions from 0x00472D70 to 0x0047353F, found by Ghidra. */
#include "common.h"
#include <windows.h>

typedef int (WINAPI *PFNMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT);
typedef HWND (WINAPI *PFNGetActiveWindow)(void);
typedef HWND (WINAPI *PFNGetLastActivePopup)(HWND);

extern "C" PFNMessageBoxA D_0049D9FC;
extern "C" PFNGetActiveWindow D_0049DA00;
extern "C" PFNGetLastActivePopup D_0049DA04;
extern "C" char D_00478EB0[];
extern "C" char D_00478EA4[];
extern "C" char D_00478E94[];
extern "C" char D_00478E80[];

extern "C" int D_0049DAC0;
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" void func_00472E62(void);

extern "C" int func_00472E31(void)
{
    return 0;
}
