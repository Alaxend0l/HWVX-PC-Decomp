/* 2 functions from 0x004460B0 to 0x00446840, found by Ghidra. */
#include "common.h"

extern "C" int func_0042A680(int, int);
extern "C" void func_00443DA0(int);
extern "C" char D_0048D93C;
extern "C" int D_0047B3E8;
extern "C" int D_0047B3EC;
struct Pair_0047B3E8 { int a; int b; };

extern "C" bool func_004467F0(int *p)
{
    if (func_0042A680(0x198, 0)) {
        func_00443DA0(0xc);
        return true;
    }
    D_0048D93C = 0;
    D_0047B3E8 = p[0];
    D_0047B3EC = p[1];
    func_00443DA0(0xb);
    return true;
}
