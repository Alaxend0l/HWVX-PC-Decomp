/* 18 functions from 0x00459C00 to 0x0045A550, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern HANDLE D_00499218;
extern IUnknown *D_00499220;
extern IUnknown *D_00499224;
extern int D_00499228;
extern int D_0049922C;
extern int D_00692998;
extern int D_006929E8;
extern char D_006929DF;
extern char D_0047C70C[];
extern int D_00499254;
typedef void (*Fn_00692994)(void);
extern Fn_00692994 D_00692994;
extern Fn_00692994 D_0069299C;
extern Fn_00692994 D_006929A0;
extern Fn_00692994 D_006929A4;
extern Fn_00692994 D_006929A8;
extern Fn_00692994 D_006929B0;
extern int D_006929C0[8];
extern Fn_00692994 D_006929E0;
extern Fn_00692994 D_006929E4;
extern Fn_00692994 D_006929EC;
extern Fn_00692994 D_006929F0;

void func_0044A5A0(void);
void func_0045A090(void);

void func_00459BA0(void);
char func_00459B10(char);

char func_00459C00(void)
{
    if (D_00499218 == NULL)
        D_00499218 = CreateMutexA(NULL, FALSE, D_0047C70C);
    timeSetEvent(3, 5, (LPTIMECALLBACK)func_00459BA0, 0, TIME_PERIODIC);
    return 1;
}

unsigned int __fastcall func_00459CB0(unsigned int a, unsigned int b)
{
    return (unsigned int)(((unsigned __int64)a * b) >> 16);
}

char func_00459CC0(void)
{
    D_00692998 = 0x7fff;
    D_0049922C = 0x7fff;
    D_00499228 = 0x7fff;
    D_006929E8 = 0;
    D_006929DF = 0;
    return 1;
}

char func_00459EF0(void)
{
    if (D_00499254)
        func_0045A090();
    return 1;
}

void func_00459C40(void)
{
    HANDLE h;

    if ((h = D_00499218) != NULL) {
        func_00459B10(1);
        D_00499218 = NULL;
        ReleaseMutex(h);
        CloseHandle(h);
    }
    if (D_00499224) {
        D_00499224->Release();
        D_00499224 = NULL;
    }
    if (D_00499220) {
        D_00499220->Release();
        D_00499220 = NULL;
    }
}

