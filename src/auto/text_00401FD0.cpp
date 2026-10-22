/* 15 functions from 0x00401FD0 to 0x00402FB0, found by Ghidra. */
#include "common.h"

struct Task_00480820 {
    int unk_0x0;
    void (*unk_0x4)(...);
    Task_00480820 *unk_0x8;
    char unk_0xc;
};

extern "C" unsigned int D_00692370;
extern "C" short D_00480828;
extern "C" unsigned int D_0068DD5C;
extern "C" Task_00480820 *D_00480820;
extern "C" Task_00480820 *D_00480824;
extern float D_00477000;
extern float D_00477010;
extern float D_00477014;
extern float D_00477018;

extern "C" unsigned int func_00401FD0(unsigned int *p)
{
    if (*p > D_00692370)
        return *p -= D_00692370;
    *p = 0;
    return *p;
}

extern "C" void func_00402280(int p)
{
    *(int *)(p + 0xc8) = 500;
}

extern "C" char func_004020C0(float a, float b, float c)
{
    float d;
    if (b == D_00477000 && c == D_00477000)
        return 1;
    if (c == D_00477018)
        return 1;
    if (b > D_00477018)
        b -= D_00477014;
    d = a - b;
    if (d > D_00477018)
        d -= D_00477014;
    else if (d < D_00477010)
        d += D_00477014;
    if (d <= c && d >= -c)
        return 1;
    return 0;
}

extern "C" char func_00402170(void)
{
    Task_00480820 *t;
    if (D_00480828 > 5 || D_0068DD5C < 0xfa) {
        D_00480828 = 0;
        t = D_00480820;
        if (t != NULL) {
            D_00480820 = t->unk_0x8;
            if (D_00480820 == NULL)
                D_00480824 = NULL;
            t->unk_0xc = 0;
            if (t->unk_0x0 != 0)
                t->unk_0x4(t->unk_0x0);
            else
                t->unk_0x4();
            return 1;
        }
    }
    return 0;
}

