/* 1 function from 0x00428430 to 0x00428471, found by Ghidra. */
#include "common.h"

extern "C" bool D_0048D1A0;
extern "C" bool D_0048D1A1;
extern "C" bool D_0048D1A2;
extern "C" void func_00428480(int);
extern "C" void func_00428C80(void);
extern "C" void func_00428430(void)
{
    char a = D_0048D1A1;
    D_0048D1A0 = 1;
    if (a) {
        func_00428480(0);
    }
    if (D_0048D1A2) {
        func_00428C80();
    }
    D_0048D1A1 = 0;
    D_0048D1A2 = 0;
    D_0048D1A0 = 0;
}
