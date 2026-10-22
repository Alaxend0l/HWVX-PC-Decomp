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
    unsigned flags;
    char unk_0x78[0xc0 - 0x78];
    char *unk_0xc0;
    char unk_0xc4[0xce - 0xc4];
    short unk_0xce;
    Mesh_0041FAD0 *mesh;
    char unk_0xd4[0xe0 - 0xd4];
    Node_0041FAD0 *nodes;
    char unk_0xe4[0x198 - 0xe4];
    Vec4_0041FAD0 vel;
    char unk_0x1a8[0x1bc - 0x1a8];
    float unk_0x1bc;
};

extern float D_00477000;

extern "C" void func_004533F0(float, Vec4_0041FAD0 *, Vec4_0041FAD0 *, Vec4_0041FAD0 *);
extern "C" void func_004073A0(Mesh_0041FAD0 **);
extern "C" void *func_0044A840(void *, int);
extern "C" void func_00451C80(void *, char *, int);
extern "C" void func_00438770(Obj_0041FAD0 *);

extern "C" int func_00420600(Obj_0041FAD0 *o)
{
    return o->unk_0x08;
}
