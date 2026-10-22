/* 8 functions from 0x00471CF0 to 0x00472018, found by Ghidra. */
#include "common.h"
#include <windows.h>

typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[0x24 - 6];
} ioinfo;

typedef struct {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    char pad[0x20 - 0x10];
    CRITICAL_SECTION lock;
} CRTFILE;

extern "C" unsigned int D_006D5AE0;
extern "C" ioinfo *D_006D59E0[];
extern "C" int D_006D6B00;
extern "C" CRTFILE **D_006D5AE4;
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" int func_0046A8F1(CRTFILE *);
extern "C" void func_0046B013(void *);
extern "C" void func_0046AD1F(int);

#pragma optimize("s", on)
#pragma optimize("s", on)
extern "C" unsigned int func_00471CF0(const char* str)
{
    const char* eos = str;
    while (*eos++)
        ;
    return (int)(eos - str - 1);
}

extern "C" void func_00471D6B(void)
{
    func_0046AD1F(2);
}

extern "C" int func_00471E44(void)
{
    int count = 0;
    int i;

    func_0046E959(2);
    for (i = 3; i < D_006D6B00; i++) {
        if (D_006D5AE4[i] != NULL) {
            if ((D_006D5AE4[i]->flag & 0x83) && func_0046A8F1(D_006D5AE4[i]) != -1)
                count++;
            if (i >= 20) {
                DeleteCriticalSection(&D_006D5AE4[i]->lock);
                func_0046B013(D_006D5AE4[i]);
                D_006D5AE4[i] = NULL;
            }
        }
    }
    func_0046E9BA(2);
    return count;
}

extern "C" int func_00471EC5(int fh)
{
    if ((unsigned)fh >= D_006D5AE0)
        return 0;
    return (int)(D_006D59E0[fh >> 5][fh & 0x1f].osfile & 0x40);
}

extern "C" long D_006D5788;
extern "C" int D_006D5784;
extern "C" int D_0049DAF0;
extern "C" int D_0047FC8C;
extern "C" UINT D_0049DB00;
extern "C" int *func_00470486(void);
extern "C" int func_00471F47(char *s, wchar_t wchar);
extern "C" int func_00471EEE(char *s, wchar_t wchar)
{
    int retval;
    int local_lock_flag;

    InterlockedIncrement(&D_006D5788);
    if (D_006D5784) {
        InterlockedDecrement(&D_006D5788);
        func_0046E959(0x13);
        local_lock_flag = 1;
    } else
        local_lock_flag = 0;
    retval = func_00471F47(s, wchar);
    if (local_lock_flag)
        func_0046E9BA(0x13);
    else
        InterlockedDecrement(&D_006D5788);
    return retval;
}

