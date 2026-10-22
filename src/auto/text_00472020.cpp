/* 20 functions from 0x00472020 to 0x00472D6E, found by Ghidra. */
#include "common.h"

/* C runtime code, built size-optimized */
#pragma optimize("s", on)

typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[0x24 - 6];
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

extern "C" int func_0047271C(int c)
{
    return func_0047272D(c, 0, 4);
}
