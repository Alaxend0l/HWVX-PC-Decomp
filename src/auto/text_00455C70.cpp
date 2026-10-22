/* 8 functions from 0x00455C70 to 0x00455FF3, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <string.h>

extern char D_0068E020[];
extern HWND D_00496E24;
extern char D_0047C1BC[];
extern char D_0047C224[];

extern "C" char func_00455E90(int a);
extern "C" HINSTANCE D_00496E20;
extern "C" void func_00456000(HWND, int, HWND, int);
extern "C" BOOL func_00456040(HWND, WPARAM, LPARAM);
extern "C" BOOL CALLBACK func_00455FA0(HWND, UINT, WPARAM, LPARAM);

extern "C" char func_00455D60(char *name, char *value)
{
    char cls[12];
    DWORD disp;
    HKEY key = 0;

    if (RegCreateKeyExA(HKEY_CURRENT_USER, D_0068E020, 0, cls, 0, KEY_ALL_ACCESS, 0, &key, &disp) == 0 &&
        RegSetValueExA(key, name, 0, REG_SZ, (BYTE *)value, strlen(value) + 2) == 0) {
        RegCloseKey(key);
        return 1;
    }
    RegCloseKey(key);
    return 0;
}

extern "C" void func_00455DF0(const char *s)
{
    strcpy(D_0068E020, s);
}

extern "C" char func_00455E20(int a)
{
retry:
    if (func_00455E90(a))
        return 1;
    while (ShowCursor(TRUE) < 0)
        ;
    if (MessageBoxA(D_00496E24, D_0047C1BC, D_0047C224, MB_OKCANCEL) == IDCANCEL)
        return 0;
    while (ShowCursor(FALSE) >= 0)
        ;
    goto retry;
}

extern "C" char func_00455E90(int a)
{
    return 1;
}
