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
extern "C" __declspec(noreturn) void func_0046ADE6(int code);

struct Vec4_004530C0 {
    float x, y, z, w;
};

struct Mat4_004530E0 {
    float m[16];
};

extern float D_00477000;
extern float D_00477014;
extern float D_004770AC;
extern float D_00477040;

int func_00452FB0(const char *expr, const char *file, int line, const char *msg)
{
    char buf[256];
    const char *p;
    int r;

    p = func_0046ABF0(file, '\\');
    if (p != NULL)
        file = p + 1;
    func_0046A89F(buf, D_0047BE10, file, line);
    if (msg != NULL) {
        strcat(buf, msg);
        strcat(buf, D_0047BE0C);
    }
    if (expr != NULL)
        strcat(buf, expr);
    r = MessageBoxA(NULL, buf, D_0047BDF8, MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
    if (r == IDABORT)
        func_0046ADE6(-1);
    return r != IDIGNORE;
}

void func_00453240(float angle, float *s, float *c)
{
    while (angle < D_00477000)
        angle += D_00477014;
    while (angle >= D_00477014)
        angle -= D_00477014;
    angle *= D_004770AC;
    *s = (float)sin(angle);
    *c = (float)cos(angle);
}

void func_004532A0(float angle, float *s, float *c)
{
    func_00453240(angle * D_00477040, s, c);
}

float func_004532D0(float y, float x)
{
    return (float)atan2(y, x);
}

float func_004532F0(float x)
{
    return (float)fabs(x);
}

void func_004530C0(Vec4_004530C0 *dst, Vec4_004530C0 *src)
{
    *dst = *src;
}

void func_004530E0(Mat4_004530E0 *dst, Mat4_004530E0 *src)
{
    *dst = *src;
}

float func_004532E0(float x)
{
    return (float)sqrt(x);
}
