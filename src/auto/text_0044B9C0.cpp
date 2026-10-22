/* 3 functions from 0x0044B9C0 to 0x0044BA60, found by Ghidra. */
#include "common.h"

struct Entry_004B6300 {
    int a;
    int b;
    char pad[0x38];
};

extern "C" char D_004B62E0[];
extern "C" Entry_004B6300 D_004B6300[8];
extern "C" char D_0047B7A0[];
extern "C" void func_00454D10(void *, int);
extern "C" void func_00452F70(const char *);

extern "C" void func_0044B9C0(void)
{
    func_00454D10(D_004B62E0, 0x200);
}

extern "C" void func_0044B9E0(int a, int b)
{
    int i = 0;
    Entry_004B6300 *e;
    for (e = D_004B6300; e < D_004B6300 + 8; e++, i++) {
        if (e->a == 0) {
            D_004B6300[i].a = a;
            D_004B6300[i].b = b;
            return;
        }
    }
    func_00452F70(D_0047B7A0);
}

