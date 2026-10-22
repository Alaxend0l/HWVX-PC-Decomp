/* 12 functions from 0x00448330 to 0x00449110, found by Ghidra. */
#include "common.h"

extern float D_0047700C;
float func_00448B60(void)
{
    return D_0047700C;
}

extern "C" int func_00448B70(char *p)
{
    char *q = *(char **)(p + 0x94);

    if (q != NULL)
        return *(int *)(q + 0x2c);
    return 0;
}

