/* 17 functions from 0x00470413 to 0x00470CA7, found by Ghidra. */
#include "common.h"

/* C runtime code, built size-optimized */
#pragma optimize("s", on)

typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[0x24 - 6];
} ioinfo;

extern "C" unsigned int D_006D5AE0;
extern "C" ioinfo *D_006D59E0[];
extern "C" void func_00472339(int);
extern "C" void func_00472398(int);
extern "C" int D_006D59C8;
extern "C" void *D_006D59C4;
extern "C" void func_0046E959(int);
extern "C" void *func_0046F110(void *);
extern "C" unsigned char *func_0046FE6B(void *, void **, void **);
extern "C" __declspec(dllimport) unsigned long __stdcall HeapSize(void *, unsigned long, const void *);
extern "C" int func_004722F7(int);
extern "C" long func_0047091A(int, long, int);
extern "C" long func_00470ACE(int, int, int);
extern "C" unsigned long (__stdcall *_imp__SetFilePointer)(void *, long, long *, unsigned long);
extern "C" unsigned long (__stdcall *_imp__GetLastError)(void);
#define SetFilePointer (*_imp__SetFilePointer)
#define GetLastError (*_imp__GetLastError)

extern "C" char *func_0046C653(void);
extern "C" void func_0046E9BA(int);
extern "C" unsigned long D_0047FC98[];
extern "C" int D_0047FC9C[];
extern "C" unsigned long D_0047FE00[];
extern "C" int *func_00470486(void);
extern "C" unsigned long *func_0047048F(void);
extern "C" void func_00470413(unsigned long oserr)
{
    int i;
    *func_0047048F() = oserr;
    for (i = 0; i < 45; i++) {
        if (oserr == D_0047FC98[i * 2]) {
            *func_00470486() = D_0047FC9C[i * 2];
            return;
        }
    }
    if (oserr >= 0x13 && oserr <= 0x24)
        *func_00470486() = 0xd;
    else if (oserr >= 0xbc && oserr <= 0xca)
        *func_00470486() = 8;
    else
        *func_00470486() = 0x16;
}

extern "C" int *func_00470486(void)
{
    return (int *)(func_0046C653() + 8);
}

extern "C" unsigned long *func_0047048F(void)
{
    return (unsigned long *)(func_0046C653() + 0xc);
}

extern "C" void func_00470623(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0047062C(void)
{
}

extern "C" void func_00470771(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0047077C(void)
{
}

#pragma optimize("s", on)
extern "C" unsigned int func_004707C7(void *pblock)
{
    void *pHeader;
    unsigned int retval;

    if (D_006D59C8 == 3) {
        func_0046E959(9);
        __try {
            if ((pHeader = func_0046F110(pblock)) != NULL)
                retval = ((int *)pblock)[-1] - 9;
        }
        __finally {
            func_0046E9BA(9);
        }
        if (pHeader != NULL)
            return retval;
    } else if (D_006D59C8 == 2) {
        void *pRegion;
        void *pPage;
        unsigned char *pMap;

        func_0046E959(9);
        __try {
            if ((pMap = func_0046FE6B(pblock, &pRegion, &pPage)) != NULL)
                retval = (unsigned int)*pMap << 4;
        }
        __finally {
            func_0046E9BA(9);
        }
        if (pMap != NULL)
            return retval;
    }
    return HeapSize(D_006D59C4, 0, pblock);
}

extern "C" void func_00470831(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0047083A(void)
{
}

extern "C" void func_004708AC(void)
{
    func_0046E9BA(9);
}

extern "C" long func_0047091A(int fh, long pos, int mthd)
{
    int osHandle;
    long newpos;
    unsigned long dosretval;

    if ((osHandle = func_004722F7(fh)) == -1) {
        *func_00470486() = 9;
        return -1;
    }
    if ((newpos = SetFilePointer((void *)osHandle, pos, NULL, mthd)) == -1)
        dosretval = GetLastError();
    else
        dosretval = 0;
    if (dosretval) {
        func_00470413(dosretval);
        return -1;
    }
    D_006D59E0[fh >> 5][fh & 0x1f].osfile &= ~2;
    return newpos;
}

#pragma optimize("s", on)
extern "C" long func_004708B5(unsigned int fh, long pos, int mthd)
{
    long r;
    if (fh < D_006D5AE0 && (D_006D59E0[(int)fh >> 5][fh & 0x1f].osfile & 1)) {
        func_00472339(fh);
        r = func_0047091A(fh, pos, mthd);
        func_00472398(fh);
        return r;
    }
    *func_00470486() = 9;
    *func_0047048F() = 0;
    return -1;
}

