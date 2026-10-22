/* 9 functions from 0x004194B0 to 0x0041A450, found by Ghidra. */
#include "common.h"

struct Tri_004194B0 {
    char unk_0x0[0x18];
    int stamp;
    int unk_0x1c;
};

struct Grid_004194B0 {
    char unk_0x0[0x4c];
    Tri_004194B0 *tris;
    char unk_0x50[8];
    int mode;
};

struct Mesh_004194B0 {
    char unk_0x0[0x38];
    int *ids;
    unsigned int count;
};

struct Node_004194B0 {
    char unk_0x0[0x14];
    unsigned short front;
    unsigned short back;
    char unk_0x18[8];
};

struct Body_004194B0 {
    char unk_0x0[0x30];
    Node_004194B0 *nodes;
};

struct Obj_004194B0 {
    char unk_0x0[0xb0];
    float unk_0xb0[3];
    char unk_0xbc[4];
    float unk_0xc0[3];
};

extern Grid_004194B0 **D_0049DBA0;
extern int D_0049DBA4;

extern "C" char func_00418BE0(Obj_004194B0 *, Tri_004194B0 *, int);
extern "C" char func_0041A3B0(Obj_004194B0 *, Mesh_004194B0 *, int);
extern "C" char func_0041A450(Obj_004194B0 *, Mesh_004194B0 *, int);
extern "C" float func_00454800(Node_004194B0 *, float *);
