/* 15 functions from 0x0041B410 to 0x0041C360, found by Ghidra. */
#include "common.h"

struct Vec4_0041B410 {
    float x, y, z, w;
};

struct Mtx_0041B410 {
    Vec4_0041B410 row[4];
};

struct Obj_0041B410 {
    char unk_0x00[0xa0];
    Vec4_0041B410 *unk_0xa0;
    Mtx_0041B410 *unk_0xa4;
    Vec4_0041B410 *unk_0xa8;
};

struct Slot_006614C0 {
    int unk_0x00;
    char unk_0x04[0x3dc];
};

struct Entry_006611C0 {
    char unk_0x00[0x3e0];
};

extern Slot_006614C0 D_006614C0[];
extern Slot_006614C0 D_006633C0[];
extern Entry_006611C0 D_006611C0[];
extern char D_0047A59C[];

extern "C" void func_004535E0(Mtx_0041B410 *m, int b, Vec4_0041B410 *out);
extern "C" void func_0041B1B0(int a, Mtx_0041B410 *m, Obj_0041B410 *obj);
extern "C" void func_00452F70(const char *msg);

extern "C" float func_0041BC60(int a, int b, int c, float d)
{
    return d;
}
