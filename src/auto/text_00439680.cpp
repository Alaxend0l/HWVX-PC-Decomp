/* 3 functions from 0x00439680 to 0x0043A3C0, found by Ghidra. */
#include "common.h"
struct Unk5D5490 {
    int unk0;
    char unk4[0xE0];
};
extern Unk5D5490 D_005D5490[];
extern Unk5D5490 D_005DC690[];

void func_0043A1D0(void)
{
    Unk5D5490 *p = D_005D5490;
    do {
        p->unk0 = 0;
        p++;
    } while (p < D_005DC690);
}
