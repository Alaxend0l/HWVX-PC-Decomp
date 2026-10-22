/* 20 functions from 0x00472020 to 0x00472D6E, found by Ghidra. */
#include "common.h"

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

