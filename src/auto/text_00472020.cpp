/* 20 functions from 0x00472020 to 0x00472D6E, found by Ghidra. */
#include "common.h"
#include <string.h>

/* C runtime code, built size-optimized */
#pragma optimize("s", on)

typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[2];
    int lockinitflag;
    char lock[0x18];
} ioinfo;

typedef struct {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
} FILE_;

extern "C" unsigned int D_006D5AE0;
extern "C" ioinfo *D_006D59E0[];
extern "C" int D_0047D434;
extern "C" int D_0049D870;
extern "C" unsigned char D_006D58A0[];
extern "C" int D_006D578C;
extern "C" int D_006D579C;
extern "C" int D_006D59A4;
extern "C" unsigned int D_006D5790[];
extern "C" unsigned char D_006D58A1[];
extern "C" unsigned short D_0047FA8A[];
extern "C" int D_0049D9F8;
extern "C" int D_0049DB00;
extern "C" unsigned int (__stdcall *_imp__GetOEMCP)(void);
extern "C" unsigned int (__stdcall *_imp__GetACP)(void);
#define GetOEMCP (*_imp__GetOEMCP)
#define GetACP (*_imp__GetACP)
extern "C" void *func_0046AED9(unsigned int size);
extern "C" int *func_00470486(void);
extern "C" unsigned long *func_0047048F(void);
extern "C" int func_0047272D(int, int, int);
extern "C" int (__stdcall *_imp__SetStdHandle)(unsigned long, void *);
#define SetStdHandle (*_imp__SetStdHandle)
extern "C" void (__stdcall *_imp__InitializeCriticalSection)(void *);
extern "C" void (__stdcall *_imp__EnterCriticalSection)(void *);
extern "C" void (__stdcall *_imp__LeaveCriticalSection)(void *);
#define LeaveCriticalSection (*_imp__LeaveCriticalSection)
#define InitializeCriticalSection (*_imp__InitializeCriticalSection)
#define EnterCriticalSection (*_imp__EnterCriticalSection)
extern "C" int (__stdcall *_imp__FlushFileBuffers)(void *);
extern "C" unsigned long (__stdcall *_imp__GetLastError)(void);
#define FlushFileBuffers (*_imp__FlushFileBuffers)
#define GetLastError (*_imp__GetLastError)
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" int func_00472B69(int, int, int, int);

extern "C" unsigned __int64 __stdcall func_00472020(unsigned __int64 a, unsigned __int64 b)
{
    return a % b;
}

extern "C" void func_00472339(int fh)
{
    ioinfo *pio = &D_006D59E0[fh >> 5][fh & 0x1f];

    if (pio->lockinitflag == 0) {
        func_0046E959(0x11);
        if (pio->lockinitflag == 0) {
            InitializeCriticalSection(&pio->lock);
            pio->lockinitflag++;
        }
        func_0046E9BA(0x11);
    }
    EnterCriticalSection(&D_006D59E0[fh >> 5][fh & 0x1f].lock);
}

extern "C" int func_004722F7(int fh)
{
    if ((unsigned)fh < D_006D5AE0 && (D_006D59E0[fh >> 5][fh & 0x1f].osfile & 1))
        return D_006D59E0[fh >> 5][fh & 0x1f].osfhnd;
    *func_00470486() = 9;
    *func_0047048F() = 0;
    return -1;
}

extern "C" void func_00472398(int fh)
{
    LeaveCriticalSection(&D_006D59E0[fh >> 5][fh & 0x1f].lock);
}

extern "C" int func_004723BA(int fh)
{
    int retval;

    if ((unsigned)fh < D_006D5AE0 && (D_006D59E0[fh >> 5][fh & 0x1f].osfile & 1)) {
        func_00472339(fh);
        if (D_006D59E0[fh >> 5][fh & 0x1f].osfile & 1) {
            if (!FlushFileBuffers((void *)func_004722F7(fh)))
                retval = GetLastError();
            else
                retval = 0;
            if (retval == 0)
                goto good;
            *func_0047048F() = retval;
        }
        *func_00470486() = 9;
        retval = -1;
good:
        func_00472398(fh);
        return retval;
    }
    *func_00470486() = 9;
    return -1;
}

extern "C" int func_004721FC(int fh, long value)
{
    if ((unsigned)fh < D_006D5AE0 && D_006D59E0[fh >> 5][fh & 0x1f].osfhnd == -1) {
        if (D_0047D434 == 1) {
            switch (fh) {
            case 0:
                SetStdHandle((unsigned long)-10, (void *)value);
                break;
            case 1:
                SetStdHandle((unsigned long)-11, (void *)value);
                break;
            case 2:
                SetStdHandle((unsigned long)-12, (void *)value);
                break;
            }
        }
        D_006D59E0[fh >> 5][fh & 0x1f].osfhnd = value;
        return 0;
    }
    *func_00470486() = 9;
    *func_0047048F() = 0;
    return -1;
}

extern "C" int func_0047272D(int c, int cmask, int kmask)
{
    c = (unsigned char)c;
    return (D_006D58A1[c] & kmask) || (cmask ? (D_0047FA8A[c] & cmask) : 0);
}

extern "C" int func_0047290B(int codepage)
{
    D_0049D9F8 = 0;
    if (codepage == -2) {
        D_0049D9F8 = 1;
        return GetOEMCP();
    } else if (codepage == -3) {
        D_0049D9F8 = 1;
        return GetACP();
    } else if (codepage == -4) {
        D_0049D9F8 = 1;
        return D_0049DB00;
    }
    return codepage;
}

extern "C" int func_00472955(int codepage)
{
    switch (codepage) {
    case 932:
        return 0x411;
    case 936:
        return 0x804;
    case 949:
        return 0x412;
    case 950:
        return 0x404;
    }
    return 0;
}

extern "C" void func_00472988(void)
{
    int i;

    memset(D_006D58A0, 0, 257);
    D_006D578C = 0;
    D_006D579C = 0;
    D_006D59A4 = 0;
    for (i = 0; i < 3; i++)
        D_006D5790[i] = 0;
}

extern "C" int func_00472278(int fh)
{
    if ((unsigned)fh < D_006D5AE0 && (D_006D59E0[fh >> 5][fh & 0x1f].osfile & 1)
        && D_006D59E0[fh >> 5][fh & 0x1f].osfhnd != -1) {
        if (D_0047D434 == 1) {
            switch (fh) {
            case 0:
                SetStdHandle((unsigned long)-10, NULL);
                break;
            case 1:
                SetStdHandle((unsigned long)-11, NULL);
                break;
            case 2:
                SetStdHandle((unsigned long)-12, NULL);
                break;
            }
        }
        D_006D59E0[fh >> 5][fh & 0x1f].osfhnd = -1;
        return 0;
    }
    *func_00470486() = 9;
    *func_0047048F() = 0;
    return -1;
}

extern "C" void func_00472095(FILE_ *stream)
{
    D_0049D870++;
    if ((stream->_base = (char *)func_0046AED9(0x1000)) != NULL) {
        stream->_flag |= 8;
        stream->_bufsiz = 0x1000;
    } else {
        stream->_flag |= 4;
        stream->_base = (char *)&stream->_charbuf;
        stream->_bufsiz = 2;
    }
    stream->_ptr = stream->_base;
    stream->_cnt = 0;
}

extern "C" int func_0047271C(int c)
{
    return func_0047272D(c, 0, 4);
}

extern "C" int D_006D6B08;
extern "C" int func_0047275E(int);
extern "C" void (__stdcall *_imp__LeaveCriticalSection)(void *);
extern "C" void func_00472B36(void)
{
    if (D_006D6B08 == 0) {
        func_0047275E(-3);
        D_006D6B08 = 1;
    }
}

extern "C" int func_00472B52(int a, int b, int c)
{
    return func_00472B69(a, b, c, 0);
}

