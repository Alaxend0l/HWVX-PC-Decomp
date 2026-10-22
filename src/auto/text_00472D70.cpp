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

#pragma optimize("s", on)
extern "C" int func_00472DA8(LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    HWND hWndParent = NULL;

    if (NULL == D_0049D9FC) {
        HINSTANCE hlib = LoadLibraryA(D_00478EB0);
        if (NULL == hlib || NULL == (D_0049D9FC = (PFNMessageBoxA)GetProcAddress(hlib, D_00478EA4)))
            return 0;
        D_0049DA00 = (PFNGetActiveWindow)GetProcAddress(hlib, D_00478E94);
        D_0049DA04 = (PFNGetLastActivePopup)GetProcAddress(hlib, D_00478E80);
    }

    if (D_0049DA00 != NULL) {
        hWndParent = (*D_0049DA00)();
        if (hWndParent != NULL && D_0049DA04 != NULL)
            hWndParent = (*D_0049DA04)(hWndParent);
    }

    return (*D_0049D9FC)(hWndParent, lpText, lpCaption, uType);
}
extern "C" int func_00472E31(void)
{
    return 0;
}

extern "C" void func_00472E34(void)
{
    if (D_0049DAC0 == 0) {
        func_0046E959(0xb);
        if (D_0049DAC0 == 0) {
            func_00472E62();
            D_0049DAC0++;
        }
        func_0046E9BA(0xb);
    }
}

extern "C" int func_0047310A(int);
extern "C" int func_004730E9(int arg)
{
    int retval;

    func_0046E959(0xb);
    retval = func_0047310A(arg);
    func_0046E9BA(0xb);
    return retval;
}

