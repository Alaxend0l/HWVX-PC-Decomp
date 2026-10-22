/* 2 functions from 0x0040E8D0 to 0x0040F6A0, found by Ghidra. */
#include "common.h"

extern "C" void func_0040F670(char *p)
{
    char *q;
    for (q = *(char **)(p + 0x324); q != 0; q = *(char **)(q + 0xa4))
        *(int *)(q + 0x94) = *(int *)(p + 0x94);
}
