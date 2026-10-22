/* 1 function from 0x0044BA60 to 0x0044D050, found by Ghidra. */
#include "common.h"
struct Obj_0044BA60;

struct Funcs_0044BA60 {
    void (*unk_0x00)(Obj_0044BA60 *);
    void (*unk_0x04)(Obj_0044BA60 *);
    void (*unk_0x08)(Obj_0044BA60 *);
    void (*unk_0x0c)(Obj_0044BA60 *);
    void (*unk_0x10)(Obj_0044BA60 *);
    void (*unk_0x14)(Obj_0044BA60 *, float *);
    void (*unk_0x18)(Obj_0044BA60 *);
    void (*unk_0x1c)(Obj_0044BA60 *);
    void (*unk_0x20)(Obj_0044BA60 *);
    void (*unk_0x24)(Obj_0044BA60 *);
    float *(*unk_0x28)(Obj_0044BA60 *);
    void (*unk_0x2c)(Obj_0044BA60 *);
    void (*unk_0x30)(Obj_0044BA60 *, float *);
    void (*unk_0x34)(Obj_0044BA60 *);
};

struct Obj_0044BA60 {
    float unk_0x00[3];
    float unk_0x0c;
    float unk_0x10[16];
    float unk_0x50[4];
    float unk_0x60[3];
    float unk_0x6c;
    int unk_0x70;
    unsigned int unk_0x74;
    int unk_0x78;
    int unk_0x7c;
    short unk_0x80;
    short unk_0x82;
    int unk_0x84;
    int unk_0x88;
    Funcs_0044BA60 *unk_0x8c;
    int unk_0x90;
    int unk_0x94;
    char unk_0x98[0xa4 - 0x98];
    Obj_0044BA60 *unk_0xa4;
    int unk_0xa8;
    char unk_0xac[0x398 - 0xac];
    char *unk_0x398;
    char unk_0x39c[0x4d8 - 0x39c];
    float unk_0x4d8;
};

struct Pair_0044BA60 {
    Obj_0044BA60 *obj;
    int unk_0x4;
};

extern Obj_0044BA60 *D_0053A9D0;
extern float D_00692378;
extern float D_00477000;
extern float D_00477360;
extern float D_0047726C;
extern float D_0047B6DC;
extern float D_0047B6E0;
extern float D_00477168;
extern Funcs_0044BA60 D_0047A2E8;
extern float D_00477060;
extern float D_00477180;
extern float D_0047700C;
extern float D_00477290;
extern int D_0048D978;
