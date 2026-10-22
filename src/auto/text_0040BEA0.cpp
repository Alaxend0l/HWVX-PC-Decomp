/* 14 functions from 0x0040BEA0 to 0x0040CE70, found by Ghidra. */
#include "common.h"

struct Vec4_0040BEA0 {
    float x, y, z, w;
};

struct Model_0040BEA0;

struct Ops_0040BEA0 {
    char unk_0x00[0x3c];
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
    char unk_0x004[0x16c - 0x4];
};

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
