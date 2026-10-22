/* 11 functions from 0x00449110 to 0x0044A0D0, found by Ghidra. */
#include "common.h"

void func_0044B310(int a, void *list, int c);
struct Vec4_00449110 {
    float x, y, z, w;
};

extern "C" void func_00449E20(void *obj, void *a, void *b, int arg);
void *func_0042D620(int x, void *y, void *from, void *to);

char func_00449860(unsigned int *p)
{
    unsigned int n = p[0];
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < p[n + 1]; j++) {
            if (*((unsigned char *)p[n + 2 + j] + 0x75) & 8)
                return 1;
        }
    }
    return 0;
}

void func_00449AA0(char *p)
{
    char *q;
    for (q = *(char **)(p + 0x88); q != 0; q = *(char **)(q + 0xa4))
        *(int *)(q + 0x94) = *(int *)(p + 0x94);
}

void func_00449CD0(char *p, void *list, int c)
{
    func_0044B310((int)(p + 0x88), list, c);
}

void func_00449DE0(char *obj, int x)
{
    float a[4];
    float b[4];

    func_00449E20(obj, b, a, 0);
    *(void **)(obj + 0x84) = func_0042D620(x, obj, b, a);
}

