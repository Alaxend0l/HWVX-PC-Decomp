/* 18 functions from 0x004560F0 to 0x00456D7A, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern "C" LARGE_INTEGER D_0068DDB0;
extern "C" LARGE_INTEGER D_0068DDB8;
extern "C" unsigned int D_00692370;
extern "C" float D_00692378;
extern "C" float D_00692360;
extern "C" int D_0069237C;
extern "C" float D_00692368;
extern "C" DWORD D_00496E38;
extern "C" HANDLE D_00496E3C;
extern "C" char D_0047C244[];
extern float D_004772D4;
extern float D_00477388;
extern float D_00477384;
extern float D_0047700C;
extern float D_00477060;
extern float D_0047738C;
extern "C" int D_00496FC0;
extern "C" int D_00496E40[0x51];
extern "C" unsigned char D_00496E44[][0x144];
extern "C" int D_0068DF20[0x40];
extern "C" int D_006924C0[0xc];
extern "C" char D_006924C2;
extern "C" char D_00496FCC;
void func_00456FE0(void);
char func_00456D80(void);
void func_00456E50(void);
void func_00456830(void);
float func_00456750(int a, int b, float c, float d);

float func_00456750(int a, int b, float c, float d)
{
    float s = b * D_004772D4;
    float t = (a - D_00477388) * D_00477384;
    float t3 = t * t * t;
    return (t3 * s + (D_0047700C - s) * t) * ((d - c) * D_00477060) + (c + d) * D_00477060;
}

void func_00456830(void)
{
    memset(D_0068DF20, 0, sizeof(D_0068DF20));
    memset(D_006924C0, 0, sizeof(D_006924C0));
    D_00496FCC = 0;
    if (D_00496FC0)
        D_006924C2 = 1;
    if (D_00496E40[0])
        D_006924C2 = 1;
}

void func_004567B0(int n, unsigned char b)
{
    int i;
    for (i = 0; i < 0x100; i++)
        D_00496E44[n][i] = (unsigned char)func_00456750(i, b, 0.0f, 255.0f);
}

char func_00456800(void)
{
    char c;
    func_00456FE0();
    c = func_00456D80();
    D_00496FC0 = c;
    memset(D_00496E40, 0, sizeof(D_00496E40));
    func_00456E50();
    func_00456830();
    return 1;
}

void func_004564B0(void)
{
    QueryPerformanceFrequency(&D_0068DDB8);
    QueryPerformanceCounter(&D_0068DDB0);
    D_00692370 = 1;
}

void func_004565D0(float rate)
{
    unsigned int ms = (unsigned int)(rate * 1000.0f);
    float frames = (float)ms * 0.06f;

    D_00692370 = ms;
    D_00692378 = rate;
    D_00692360 = frames;
    D_0069237C = (int)frames;
    D_00692368 = 1.0f / rate;
}

void func_00456630(unsigned int *out)
{
    LARGE_INTEGER now;

    QueryPerformanceCounter(&now);
    now.QuadPart = now.QuadPart * 1000000 / D_0068DDB8.QuadPart;
    *out = now.LowPart;
}

void func_00456680(unsigned int *io)
{
    LARGE_INTEGER now;

    QueryPerformanceCounter(&now);
    now.QuadPart = now.QuadPart * 1000000 / D_0068DDB8.QuadPart;
    *io = now.LowPart - *io;
}

void func_004566E0(void);
void func_00456700(void);
void func_004566D0(void)
{
    func_004566E0();
    func_00456700();
}

int func_00456730(void)
{
    return D_00496E38 == ERROR_ALREADY_EXISTS;
}

struct EngineMutex {
    EngineMutex()
    {
        D_00496E3C = CreateMutexA(NULL, FALSE, D_0047C244);
        D_00496E38 = GetLastError();
    }
    ~EngineMutex()
    {
        if (D_00496E3C != NULL) {
            CloseHandle(D_00496E3C);
            D_00496E3C = NULL;
        }
    }
};

static EngineMutex s_engineMutex;

int func_00456C80(void)
{
    return 3;
}
