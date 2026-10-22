/* 12 functions from 0x0041FAD0 to 0x00420710, found by Ghidra. */
#include "common.h"

struct Vec4_0041FAD0 {
    float x, y, z, w;
};

struct Node_0041FAD0 {
    char unk_0x00[0x30];
    Vec4_0041FAD0 pos;
};

struct Mesh_0041FAD0 {
    char unk_0x00[0x14];
    unsigned *unk_0x14;
    unsigned *unk_0x18;
};

struct Obj_0041FAD0 {
    char unk_0x00[0x8];
    int unk_0x08;
    char unk_0x0c[0x40 - 0x0c];
    Vec4_0041FAD0 pos;
    char unk_0x50[0x74 - 0x50];
    union {
        int flags;
        struct {
            unsigned unk_0x74_0 : 14;
            unsigned unk_0x74_14 : 1;
        };
    };
    char unk_0x78[0xc0 - 0x78];
    char *unk_0xc0;
    char unk_0xc4[0xce - 0xc4];
    short unk_0xce;
    Mesh_0041FAD0 *mesh;
    char unk_0xd4[0xe0 - 0xd4];
    Node_0041FAD0 *nodes;
    char unk_0xe4[0x198 - 0xe4]; /* list passed to func_0044A840 */
    Vec4_0041FAD0 vel;
    char unk_0x1a8[0x1bc - 0x1a8];
    float unk_0x1bc;
};

extern float D_00477000;
extern char D_0047A658;
extern int D_0047A65C;
extern int D_0047A660;
extern "C" void func_004585A0(int);

struct Slot_00489A9C {
    char unk_0x00;
    char unk_0x01[0x4ff];
};

extern Slot_00489A9C D_00489A9C[];
extern Slot_00489A9C D_0048D19C[];

extern "C" void func_004533F0(float, Vec4_0041FAD0 *, Vec4_0041FAD0 *, Vec4_0041FAD0 *);
extern "C" void func_004073A0(Mesh_0041FAD0 **);
extern "C" void *func_0044A840(void *, int);
extern "C" void func_00451C80(void *, char *, int);
extern "C" void func_00438770(Obj_0041FAD0 *);

extern "C" void func_0041FC50(Obj_0041FAD0 *o, float dt)
{
    Vec4_0041FAD0 t;
    Vec4_0041FAD0 *vel = &o->vel;
    unsigned *count;
    unsigned i;

    func_004533F0(dt, vel, &o->pos, &t);
    o->pos = t;
    count = o->mesh->unk_0x14;
    for (i = 0; i < *count; i++) {
        o->nodes[i].pos.x += dt * vel->x;
        o->nodes[i].pos.y += dt * o->vel.y;
        o->nodes[i].pos.z += dt * o->vel.z;
    }
    o->flags &= ~0x4000;
}

extern "C" void func_004202B0(Obj_0041FAD0 *o)
{
    if (o->unk_0x1bc > D_00477000)
        func_004073A0(&o->mesh);
    o->flags = o->flags | 0x4000;
}

extern "C" char func_004202E0(int a, Obj_0041FAD0 *b)
{
    void *r;

    if (*b->unk_0xc0 == 3) {
        r = func_0044A840((void *)(a + 0xe4), 8);
        if (r != 0) {
            func_00451C80(r, b->unk_0xc0, b->unk_0xce);
            func_00438770(b);
            if (b->mesh != 0)
                b->mesh->unk_0x18 = b->mesh->unk_0x14;
            return 1;
        }
    }
    return 0;
}

extern "C" char func_00420340(Obj_0041FAD0 *o, unsigned lo, unsigned hi)
{
    unsigned v = *(unsigned *)((char *)o + 0xb8);
    if (v < lo || v >= hi)
        return 0;
    return 1;
}

extern "C" int func_00420600(Obj_0041FAD0 *o)
{
    return o->unk_0x08;
}

extern "C" int func_00420610(Mesh_0041FAD0 *m)
{
    return *(int *)((char *)m + 0x14);
}

extern "C" void func_004206B0(char c)
{
    D_0047A658 = c;
}

extern "C" void func_004206C0(void)
{
    Slot_00489A9C *p = D_00489A9C;
    do {
        p->unk_0x00 = 0;
        p++;
    } while (p < D_0048D19C);
}

