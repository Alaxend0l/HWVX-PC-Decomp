/* 19 functions from 0x0042AFA0 to 0x0042BF60, found by Ghidra. */
#include "common.h"

unsigned char func_00440130(void);
int func_00429EA0(void);
extern char D_0064DD5E[];
extern char D_0064D39F[];
extern char D_0065E35A;
extern char D_0065E350[];
struct D_0064D148_t { char data[32]; };
extern D_0064D148_t D_0064D148[];
extern char D_0064D164;
unsigned char func_0042AFA0(void)
{
    return func_00440130();
}

unsigned char func_0042AFB0(int idx)
{
    char *p;
    unsigned int i;

    switch (func_00429EA0()) {
    case 0:
        p = D_0064D39F;
        break;
    case 1:
        p = D_0064DD5E;
        break;
    default:
        p = (char *)idx;
        break;
    }

    switch (idx) {
    case 9:
        for (i = 0; i < 11; i++) {
            if (i != 9 && p[i] != 0)
                return 1;
        }
        if (i == 11)
            return 0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        if (p[10] != 0 && D_0065E35A != 0)
            return 1;
        break;
    }

    if (p[10] == 0 && p == NULL)
        return 0;
    if (D_0065E350[idx] == 0)
        return 0;
    return 1;
}

char *func_0042B040(int i)
{
    return (char *)&D_0064D148[i];
}

char *func_0042B140(void)
{
    return &D_0064D164;
}
