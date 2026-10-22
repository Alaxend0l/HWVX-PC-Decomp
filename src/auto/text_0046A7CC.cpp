/* 4 functions from 0x0046A7CC to 0x0046A863, found by Ghidra. */
#include "common.h"
#include <stdarg.h>

typedef struct {
    unsigned long tid;
    unsigned long thandle;
    int terrno;
    unsigned long tdoserrno;
    unsigned int fpds;
    unsigned long holdrand;
} tiddata;

extern "C" char D_0047D4C8[];
extern "C" tiddata *func_0046C653(void);
extern "C" void func_0046C845(int, void *);
extern "C" void func_0046C897(int, void *);
extern "C" int func_0046C8BA(void *);
extern "C" void func_0046C947(int, void *);
extern "C" int func_0046C971(void *, const char *, va_list);

extern "C" void func_0046A7F3(unsigned int seed)
{
    func_0046C653()->holdrand = seed;
}

#pragma optimize("s", on)
extern "C" int func_0046A800(void)
{
    tiddata *ptd = func_0046C653();
    return ((ptd->holdrand = ptd->holdrand * 214013L + 2531011L) >> 16) & 0x7fff;
}
extern "C" int func_0046A822(const char *format, ...)
{
    va_list arglist;
    int buffing;
    int retval;

    va_start(arglist, format);
    func_0046C845(1, D_0047D4C8);
    buffing = func_0046C8BA(D_0047D4C8);
    retval = func_0046C971(D_0047D4C8, format, arglist);
    func_0046C947(buffing, D_0047D4C8);
    func_0046C897(1, D_0047D4C8);
    return retval;
}

