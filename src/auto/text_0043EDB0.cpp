/* 4 functions from 0x0043EDB0 to 0x0043FDB0, found by Ghidra. */
#include "common.h"
#include <string.h>

extern int D_0048D780;
extern u8 D_0047B0D0[][16];

char func_0043E920(void);
void func_0043E9A0(int);

char func_0043FD40(char *p)
{
    if (p[0x6c] & 1)
        return 0;
    if (D_0048D780 == 2) {
        p[0] = func_0043E920();
        p[2] = 0;
        p[1] = func_0043E920();
        p[3] = 0;
    } else if (D_0048D780 == 1) {
        func_0043E9A0((p[2] << 16) + p[0]);
        func_0043E9A0((p[3] << 16) + p[1]);
    }
    return 1;
}
