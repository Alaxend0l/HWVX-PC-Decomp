/* 6 functions from 0x00403F10 to 0x00404A80, found by Ghidra. */
#include "common.h"

int func_00401FD0(char *);
void func_004021D0(char *);
void func_004044E0(char *p)
{
    func_00401FD0(p + 0x648);
    if (*(int *)(p + 0x644) != 0 && func_00401FD0(p + 0x644) == 0)
        func_004021D0(p + 0x634);
}
