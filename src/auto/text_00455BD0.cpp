/* 4 functions from 0x00455BD0 to 0x00455C64, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <objbase.h>

extern "C" int func_0046B2F6(int, int, int);

extern "C" void func_00455BD0(void)
{
    CoUninitialize();
    ShowCursor(TRUE);
}

extern "C" void func_00455BE0(int *year, int *month, int *day, int *hour, int *minute)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    *year = st.wYear;
    *month = st.wMonth;
    *day = st.wDay;
    *hour = st.wHour;
    *minute = st.wMinute;
}

