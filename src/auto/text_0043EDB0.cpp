/* 4 functions from 0x0043EDB0 to 0x0043FDB0, found by Ghidra. */
#include "common.h"
#include <string.h>

extern int D_0048D780;
extern u8 D_0047B0D0[][16];

struct Map_0047B0D0 {
    u8 unk_0x0;
    u8 unk_0x1;
    u8 map[14];
};

char func_0043E920(void);
void func_0043E9A0(int);

void func_0043F4B0(char *p, int n)
{
    u8 *src;
    u8 *idx;
    int i;
    memset(p + 0xb8, 0, 16);
    memset(p + 0xb8, 0xff, 14);
    src = &D_0047B0D0[n + 1][2];
    idx = &D_0047B0D0[0][2];
    for (i = 14; i != 0; i--)
        p[0xb8 + *idx++] = *src++;
    p[0xc6] = D_0047B0D0[n + 1][0];
    p[0xc7] = D_0047B0D0[n + 1][1];
}

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
