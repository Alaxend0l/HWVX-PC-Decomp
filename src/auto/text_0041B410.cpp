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
extern "C" void func_00452F70(const char *fmt, ...);

struct OBox_00663180 {
    char unk_0x00[0x9d];
    char unk_0x9d;
    char unk_0x9e[0x52];
};

extern OBox_00663180 D_00663180[];
extern char D_0066321D[];
extern char D_0068121D[];
extern char D_0047A5B8[];
extern char D_0047A5C8[];

extern "C" void func_0041B410(int a, Mtx_0041B410 *m, int b, Obj_0041B410 *obj)
{
    Mtx_0041B410 tmp;

    tmp = *m;
    func_004535E0(m, b, &tmp.row[3]);
    func_0041B1B0(a, &tmp, obj);
    obj->unk_0xa0 = &m->row[2];
    obj->unk_0xa4 = m;
    obj->unk_0xa8 = &m->row[1];
}

extern "C" float func_0041BC60(int a, int b, int c, float d)
{
    return d;
}

extern "C" void func_0041B570(void)
{
    Slot_006614C0 *p = D_006614C0;
    do {
        p->unk_0x00 = 0;
        p++;
    } while (p < D_006633C0);
}

extern "C" Entry_006611C0 *func_0041B590(int value)
{
    int i = 0;
    Slot_006614C0 *p;

    for (p = D_006614C0; p < D_006633C0; p++, i++) {
        if (p->unk_0x00 == 0) {
            D_006614C0[i].unk_0x00 = value;
            return &D_006611C0[i];
        }
    }
    func_00452F70(D_0047A59C);
    return 0;
}

extern "C" void func_0041B5E0(Slot_006614C0 *p)
{
    if (p)
        *(int *)((char *)p + 0x300) = 0;
}

extern "C" void func_0041B600(void)
{
    char *p;

    func_00452F70(D_0047A5B8, D_00663180);
    p = D_0066321D;
    do {
        *p = 0;
        p += sizeof(OBox_00663180);
    } while (p < D_0068121D);
}

