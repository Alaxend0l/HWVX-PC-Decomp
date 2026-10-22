/* 35 functions from 0x00452FB0 to 0x00453FB0, found by Ghidra. */
#include "common.h"
#include <math.h>
#include <string.h>
#include <windows.h>

extern "C" char D_0047BE10[];
extern "C" char D_0047BE0C[];
extern "C" char D_0047BDF8[];
extern "C" char *func_0046ABF0(const char *s, int ch);
extern "C" int func_0046A89F(char *string, const char *format, ...);
extern "C" int func_0046ADE6(int code);

float func_004532F0(float x)
{
    return (float)fabs(x);
}

float func_004532E0(float x)
{
    return (float)sqrt(x);
}
