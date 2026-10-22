/* 14 functions from 0x0040BEA0 to 0x0040CE70, found by Ghidra. */
#include "common.h"

struct Vec4_0040BEA0 {
    float x, y, z, w;
};

struct Model_0040BEA0;

struct Ops_0040BEA0 {
    char unk_0x00[0x4];
    void (*unk_0x04)(Model_0040BEA0 *);
    char unk_0x08[0x3c - 0x8];
    void (*unk_0x3c)(Model_0040BEA0 *, void *);
};

struct Model_0040BEA0 {
    float unk_0x00[3];
    char unk_0x0c[0x70 - 0x0c];
    int unk_0x70;
    char unk_0x74[0x8c - 0x74];
    Ops_0040BEA0 *unk_0x8c;
};

struct Ent_0040BEA0 {
    char unk_0x00[0x2c];
    Model_0040BEA0 *unk_0x2c;
};

struct Node_0040BEA0 {
    char unk_0x00[0x40];
    float unk_0x40[3];
};

struct Obj_0040BEA0 {
    Ent_0040BEA0 *unk_0x0;
    char unk_0x004[0x54 - 0x04];
    Vec4_0040BEA0 unk_0x054;
    char unk_0x064[0x168 - 0x64];
    Node_0040BEA0 *unk_0x168;
};

struct Slot_0040BEA0 {
    char *unk_0x000;
    char unk_0x004[0xa8 - 0x4];
    void *unk_0x0a8;
    int unk_0x0ac;
    char unk_0x0b0[0x168 - 0xb0];
    Model_0040BEA0 *unk_0x168;
};

struct SlotField_0040BEA0 {
    void *unk_0x0;
    char unk_0x4[0x16c - 0x4];
};

struct SlotSub_0040BEA0 {
    void *unk_0x0;
    int unk_0x4;
    char unk_0x8[0x16c - 0x8];
};

extern SlotField_0040BEA0 D_0068143C[];
extern SlotField_0040BEA0 D_00681440[];
extern SlotSub_0040BEA0 D_006815A8[];
extern SlotField_0040BEA0 D_006815AC[];
extern SlotField_0040BEA0 D_00681668[];

extern char D_0047A2E4[];
extern char D_0053A9D0[];
void func_0044A910(void *);

struct Inner_0049DBA0 {
    char unk_0x00[0x3c];
    float unk_0x3c;
};

struct Track_0040BEA0 {
    char unk_0x00[0x9c];
    Inner_0049DBA0 *unk_0x9c;
};

extern u8 D_00681AB0;
extern Slot_0040BEA0 D_00681500[];
extern Track_0040BEA0 *D_0049DBA0;

void func_00453330(void *, void *, void *);
char func_0044D550(Vec4_0040BEA0 *, Vec4_0040BEA0 *, float *, void *);
void *func_0043B500(void *, int);
Vec4_0040BEA0 *func_0043BD20(void *);
void func_0040C0A0(Obj_0040BEA0 *, int, Vec4_0040BEA0 *, void *, int, int);
void func_00440330(void);
void func_0043EB20(int);
void func_0040CA20(void);

void func_0040C4B0(Obj_0040BEA0 *obj)
{
    if (obj->unk_0x168 != 0 && obj->unk_0x0 != 0 && obj->unk_0x0->unk_0x2c != 0) {
        Inner_0049DBA0 *in = D_0049DBA0->unk_0x9c;
        float s = in->unk_0x3c;
        obj->unk_0x168->unk_0x40[0] = s * obj->unk_0x0->unk_0x2c->unk_0x00[0] + obj->unk_0x054.x;
        obj->unk_0x168->unk_0x40[1] = s * obj->unk_0x0->unk_0x2c->unk_0x00[1] + obj->unk_0x054.y;
        obj->unk_0x168->unk_0x40[2] = s * obj->unk_0x0->unk_0x2c->unk_0x00[2] + obj->unk_0x054.z;
    }
}

void func_0040C2A0(Obj_0040BEA0 *obj, int arg)
{
    char mtx[16];
    Vec4_0040BEA0 dir;
    float dist;
    Vec4_0040BEA0 *hit;
    Vec4_0040BEA0 *pos;
    Model_0040BEA0 *m;

    m = obj->unk_0x0->unk_0x2c;
    m->unk_0x8c->unk_0x3c(m, mtx);
    pos = &obj->unk_0x054;
    func_00453330(mtx, pos, &dir);
    dist = 1.0f;
    if (func_0044D550(pos, &dir, &dist, 0) &&
        (hit = func_0043BD20(func_0043B500(mtx, -1))) != 0)
        *pos = *hit;
    m = obj->unk_0x0->unk_0x2c;
    func_0040C0A0(obj, arg, pos, mtx, m->unk_0x70, 0);
}

void func_0040CA20(void)
{
    unsigned int i = 0;
    if (D_00681AB0 > 0) {
        do {
            if (D_00681500[i].unk_0x000 != 0)
                *(int *)(D_00681500[i].unk_0x000 + 0x6c) |= 0x10;
            i++;
        } while (i < (*(u32 *)&D_00681AB0 & 0xff));
    }
}

void func_0040CA50(int *p, int v)
{
    *p = v;
    func_00440330();
    func_0040CA20();
    func_0043EB20(v);
}

void func_0040CA70(void)
{
    unsigned int i = 0;
    if (D_00681AB0 > 0) {
        do {
            D_00681500[i].unk_0x0a8 = D_0047A2E4;
            i++;
        } while (i < (*(u32 *)&D_00681AB0 & 0xff));
    }
}

void func_0040CAA0(unsigned int *p)
{
    unsigned int i;
    if (*p >= 1 && *p <= 4) {
        D_00681500[*p - 1].unk_0x0a8 = p + 1;
        D_00681500[*p - 1].unk_0x0ac = 0;
        return;
    }
    i = 0;
    if (D_00681AB0 > 0) {
        do {
            D_00681500[i].unk_0x0a8 = p + (*p == 0);
            D_00681500[i].unk_0x0ac = 0;
            i++;
        } while (i < (*(u32 *)&D_00681AB0 & 0xff));
    }
}

Slot_0040BEA0 *func_0040CB30(char *key)
{
    unsigned int i;
    unsigned int n = *(u32 *)&D_00681AB0 & 0xff;
    for (i = 0; i < n; i++) {
        if (D_00681500[i].unk_0x000 == key)
            return &D_00681500[i];
    }
    return 0;
}

void func_0040CB70(void)
{
    unsigned int i = 0;
    if (D_00681AB0 > 0) {
        do {
            Model_0040BEA0 *m = (Model_0040BEA0 *)D_00681668[i].unk_0x0;
            if (m != 0) {
                m->unk_0x8c->unk_0x04(m);
                D_00681668[i].unk_0x0 = 0;
            }
            i++;
        } while (i < (*(u32 *)&D_00681AB0 & 0xff));
    }
    func_0044A910(D_0053A9D0);
}

