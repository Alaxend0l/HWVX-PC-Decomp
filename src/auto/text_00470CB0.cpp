/* 3 functions from 0x00470CB0 to 0x0047104C, found by Ghidra. */
#include "common.h"
extern "C" double D_00478E78;
extern "C" unsigned int func_004742CB(double);
extern "C" double func_0046EEC1(double);

#pragma optimize("s", on)
#pragma optimize("y", off)
#pragma optimize("p", on)
extern "C" int func_00470FE7(double x)
{
    double y;
    if (!(func_004742CB(x) & 0x90)) {
        y = func_0046EEC1(x);
        if (y == x) {
            x = x / D_00478E78;
            if (func_0046EEC1(x) == x)
                return 2;
            return 1;
        }
    }
    return 0;
}
