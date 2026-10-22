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
    return (unsigned int)((unsigned __int64)a * b >> 16);
}
