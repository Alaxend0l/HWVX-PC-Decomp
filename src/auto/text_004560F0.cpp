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

extern "C" DWORD D_00496E38;
extern "C" HANDLE D_00496E3C;
extern "C" char D_0047C244[];
extern float D_004772D4;
extern float D_00477388;
extern float D_00477384;
extern float D_0047700C;
extern float D_00477060;

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
