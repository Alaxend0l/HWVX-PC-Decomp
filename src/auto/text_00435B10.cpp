/* 1 function from 0x00435B10 to 0x00436D70, found by Ghidra. */
#include "common.h"
#include <string.h>
struct Vec4_00435B10 {
    float x, y, z, w;
};

struct Mtx_00435B10 {
    Vec4_00435B10 r[4];
};

struct Col_00435B10 {
    u8 r, g, b, a;
};

struct Font_00435B10 {
    char unk_0x00[0x12];
    u8 unk_0x12;
    char unk_0x13;
    u16 w;
    u16 h;
};

struct TextFont_00435B10 {
    char unk_0x00[0xe];
    u8 unk_0xe;
    u8 unk_0xf;
    u8 unk_0x10;
    u8 unk_0x11;
    char unk_0x12[2];
    u16 w;
    u16 h;
    int unk_0x18;
};

struct PathPt_00435B10 {
    float x, y;
    char unk_0x08[8];
    Col_00435B10 col;
    char unk_0x14[0xc];
};

struct Path_00435B10 {
    unsigned int count;
    PathPt_00435B10 *pts;
    char mode;
};

struct Desc_00435B10 {
    char unk_0x00[0xc];
    s16 unk_0xc;
    char unk_0xe[2];
    int unk_0x10;
    void *unk_0x14;
    char unk_0x18[0x18];
    float ax;
    float ay;
};

struct Link_00435B10 {
    char unk_0x00[8];
    int unk_0x8;
    char unk_0xc[0x1c];
    int unk_0x28;
};

struct Spr_00435B10 {
    char unk_0x00[0x40];
    Vec4_00435B10 pos;
};

struct Model_00435B10;

struct ModelVt_00435B10 {
    char unk_0x00[0x10];
    void (*draw)(Model_00435B10 *);
};

struct Model_00435B10 {
    char unk_0x00[0x10];
    Mtx_00435B10 mtx;
    char unk_0x50[0x24];
    unsigned int flags;
    char unk_0x78[0x14];
    ModelVt_00435B10 *vt;
    char unk_0x90[0x398 - 0x90];
    float *unk_0x398;
};

struct Ent_00435B10 {
    char unk_0x00[0x24];
    Col_00435B10 color;
    char unk_0x28[4];
    u8 unk_0x2c;
    char unk_0x2d[3];
    Vec4_00435B10 scale;
    char unk_0x40[0x14];
    u8 unk_0x54;
    char unk_0x55[0xb];
    Vec4_00435B10 pos;
    char unk_0x70[0x14];
    u8 unk_0x84;
    char unk_0x85[0xb];
    Vec4_00435B10 rot;
    char unk_0xa0[0x14];
    u8 unk_0xb4;
    char unk_0xb5[0xb];
    Vec4_00435B10 unk_0xc0;
    char unk_0xd0[8];
    Vec4_00435B10 unk_0xd8;
    char unk_0xe8[0x30];
    u8 unk_0x118;
    char unk_0x119[0xb];
    u8 unk_0x124;
    u8 unk_0x125;
    char unk_0x126[0xa];
    u8 unk_0x130;
    char unk_0x131[7];
    int unk_0x138;
    char unk_0x13c[0x60];
    char *text;
    u16 maxLen;
    u16 len;
    char unk_0x1a4[4];
    u8 unk_0x1a8;
    u8 unk_0x1a9;
    char unk_0x1aa[0xe];
    char textBuf[0x80];
    u8 unk_0x238;
    char unk_0x239[2];
    u8 type;
    u8 unk_0x23c;
    u8 unk_0x23d;
    char unk_0x23e[0xe];
    Link_00435B10 *link;
    Font_00435B10 *font;
    Desc_00435B10 *desc;
    Ent_00435B10 *parent;
    Ent_00435B10 *rel;
    char unk_0x260[4];
    Spr_00435B10 *spr;
    int unk_0x268;
    char unk_0x26c[0x14];
    Model_00435B10 *model;
    char unk_0x284[0x74];
};

struct Sub_00435B10 {
    char unk_0x00[0x2c];
    int unk_0x2c;
};

struct Owner_00435B10 {
    unsigned int count;
    char unk_0x4[4];
    Sub_00435B10 *unk_0x8;
    char unk_0xc[0x69];
    u8 unk_0x75;
    char unk_0x76[7];
    u8 unk_0x7d;
    char unk_0x7e[2];
    Ent_00435B10 *ents;
};

struct Slot_00435B10 {
    char unk_0x00[0x134];
};

struct Emit1_00435B10 {
    Vec4_00435B10 a;
    Vec4_00435B10 b;
    Vec4_00435B10 c;
    Vec4_00435B10 d;
    Font_00435B10 *src;
    int owner;
    int unk_0x48;
    int unk_0x4c;
};

struct Emit2_00435B10 {
    Vec4_00435B10 a;
    Vec4_00435B10 b;
    Vec4_00435B10 c;
    Font_00435B10 *src;
    int owner;
    int unk_0x38;
};

extern char D_0048D5FC;
extern char D_0048D5FD;
extern float D_00477000;
extern float D_00477040;
extern float D_00477060;
extern float D_004770AC;
extern Vec4_00435B10 D_00692350;
extern Mtx_00435B10 D_006922E0;
extern ModelVt_00435B10 D_0047A2E8;
extern Slot_00435B10 D_005E7660[];

void func_00434D90(Vec4_00435B10 *, float, float);
void func_00434CB0(Vec4_00435B10 *);
extern "C" void func_00448330(Spr_00435B10 *);
void func_0042F090(Slot_00435B10 *, int);
void func_0045FE00(Vec4_00435B10 *);
void func_00453B20(Mtx_00435B10 *, float, float, float);
void func_004537C0(Mtx_00435B10 *, Mtx_00435B10 *, Mtx_00435B10 *);
void func_004540C0(Mtx_00435B10 *, void *);
void func_0040F6A0(Model_00435B10 *);
void func_00437620(Vec4_00435B10 *, Owner_00435B10 *);
void func_00437920(Ent_00435B10 *, Owner_00435B10 *);
void func_004358A0(Slot_00435B10 *);
void func_00437450(Ent_00435B10 *);
void func_00436D70(Ent_00435B10 *, Owner_00435B10 *);
void func_004351A0(Ent_00435B10 *);
void func_00434EA0(Ent_00435B10 *);
Spr_00435B10 *func_0044D0B0(int, void *);
void func_00453330(Vec4_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_004535E0(Mtx_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_0046AAF0(char *, char *, unsigned int);
void func_00464F90(int, int, int, int);
void func_00463900(char *, int, float *, float *, int);
void func_004632A0(char *, float, float, int, int, int);
void func_00463440(char *, int, float, float, int, int, int, int, float, float, int, Vec4_00435B10 *);
void func_00463760(char *, float, float, int, int, Vec4_00435B10 *, int);
void func_00453300(Vec4_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_0045EBA0(Vec4_00435B10 *, Vec4_00435B10 *, Col_00435B10 *, Col_00435B10 *, int);
float func_004532D0(float, float);
float func_004532E0(float);
void func_00453240(float, float *, float *);
