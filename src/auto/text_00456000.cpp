/* 4 functions from 0x00456000 to 0x004560E3, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern "C" HINSTANCE D_00496E20;
extern "C" void func_004563C0(HWND, HWND);
extern "C" void func_004560F0(HWND, int, HWND, UINT);
extern "C" BOOL func_00456220(HWND, HWND, LPARAM);
extern "C" BOOL CALLBACK func_00456090(HWND, UINT, WPARAM, LPARAM);

extern "C" void func_00456000(HWND hwnd, int id)
{
    switch (id) {
    case 1:
        EndDialog(hwnd, id);
        break;
    case 2:
        EndDialog(hwnd, id);
        break;
    case 0x3f6:
        EndDialog(hwnd, id);
        break;
    }
}

extern "C" BOOL func_00456040(HWND hwnd)
{
    func_004563C0(hwnd, GetDesktopWindow());
    return TRUE;
}

extern "C" int func_00456060(void)
{
    int ret = DialogBoxParamA(D_00496E20, MAKEINTRESOURCE(0x6c), NULL, func_00456090, 0);
    if (ret < 0) {
        GetLastError();
        ret = 2;
    }
    return ret;
}

