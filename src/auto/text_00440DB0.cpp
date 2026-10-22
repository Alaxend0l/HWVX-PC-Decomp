/* 9 functions from 0x00440DB0 to 0x00441880, found by Ghidra. */
#include "common.h"

extern "C" char D_0047B178[];
extern "C" void func_00438B80(int);
extern "C" void func_00448330(int);
extern "C" void func_00439310(int);
extern "C" void func_00440FD0(int);
extern "C" void func_00449110(int);

extern "C" void func_00440DB0(int arg)
{
    func_00438B80(*(int *)(arg + 0x130));
    func_00448330(arg);
    func_00439310(*(int *)(arg + 0x134));
    *(char **)(arg + 0x8c) = D_0047B178;
}

extern "C" char func_00441640(int arg)
{
    func_00440FD0(arg);
    func_00449110(arg);
    return 1;
}
