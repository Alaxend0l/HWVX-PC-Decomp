/* 2 functions from 0x00475120 to 0x00475221, found by Ghidra. */
#include "common.h"

extern "C" unsigned int func_00471CF0(const char *);
extern "C" int func_004755A7(const char *, const char *, unsigned int);
extern "C" int func_004755E6(void);
extern "C" int D_006D6B04;
extern "C" char **D_0049D834;
extern "C" void *D_0049D83C;

#pragma optimize("s", on)
extern "C" char *func_004751A4(const char *option)
{
    char **search = D_0049D834;
    unsigned int length;

    if (!D_006D6B04)
        return 0;

    if (search == 0 && D_0049D83C != 0) {
        if (func_004755E6() != 0)
            return 0;
        search = D_0049D834;
    }

    if (search == 0 || option == 0)
        return 0;

    length = func_00471CF0(option);

    while (*search) {
        if (func_00471CF0(*search) > length && *(*search + length) == '='
            && func_004755A7(*search, option, length) == 0)
            return *search + length + 1;
        search++;
    }

    return 0;
}
#pragma optimize("", on)
