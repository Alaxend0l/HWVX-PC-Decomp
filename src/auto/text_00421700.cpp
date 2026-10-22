/* 9 functions from 0x00421700 to 0x00422600, found by Ghidra. */
#include "common.h"

struct Vec4_00421700 {
    float x, y, z, w;
};

struct Bounds_00421700 {
    char unk_0x0[0x20];
    float radius;
    char unk_0x24[0xc];
};

struct Shape_00421700 {
    char unk_0x0[0x10];
    Bounds_00421700 bounds;
};

struct Info_00421700 {
    char unk_0x0[0x10];
    unsigned char type;
    unsigned char unk_0x11;
    char unk_0x12[2];
    int unk_0x14;
    char unk_0x18[4];
    int unk_0x1c;
    char unk_0x20[0x24];
    Bounds_00421700 *bounds;
    int unk_0x48;
};

struct Model_00421700 {
    Shape_00421700 *shape;
    unsigned char kind;
    unsigned char unk_0x5;
    unsigned char unk_0x6;
    char unk_0x7;
    float unk_0x8;
    char unk_0xc[4];
    Info_00421700 *info;
    char unk_0x14[4];
    char unk_0x18[4];
};

struct Desc_00421700 {
    Vec4_00421700 unk_0x0;
    Vec4_00421700 unk_0x10;
    char unk_0x20[0x10];
    Vec4_00421700 unk_0x30;
    Model_00421700 *model;
    char unk_0x44[4];
    float unk_0x48;
    char unk_0x4c[4];
    int unk_0x50;
    int unk_0x54;
    char unk_0x58[4];
    int unk_0x5c;
};

struct Obj_00421700 {
    Vec4_00421700 unk_0x0;
    Vec4_00421700 unk_0x10;
    char unk_0x20[0x20];
    Vec4_00421700 unk_0x40;
    Vec4_00421700 unk_0x50;
    char unk_0x60[0x10];
    float radius;
    unsigned int flags;
    int unk_0x78;
    int unk_0x7c;
    short type;
    char unk_0x82[6];
    char unk_0x88[4];
    void *unk_0x8c;
    char unk_0x90[0x30];
    Model_00421700 *model;
    float unk_0xc4;
    int unk_0xc8;
    char *unk_0xcc;
    char *unk_0xd0;
    int unk_0xd4;
    int unk_0xd8;
    int unk_0xdc;
};

struct Box_00421700 {
    char unk_0x0[0x10];
    Vec4_00421700 pts[8];
    char unk_0x90[0x40];
    Vec4_00421700 min;
    Vec4_00421700 max;
};

struct Item_00421700 {
    char unk_0x0[0x10];
    float unk_0x10;
    char unk_0x14[0xc];
};

struct List_00421700 {
    unsigned int count;
    Item_00421700 *items;
};

struct Effect_00421700 {
    Vec4_00421700 a, b, c;
    Shape_00421700 *shape;
    char *unk_0x34;
};

extern Vec4_00421700 D_00692350;
extern char D_0047A830[];
extern char D_0047B088[];
extern char D_0047B040[];
extern char D_0047A3B0[];

void func_004482C0(Obj_00421700 *, Desc_00421700 *);
void func_00453FB0(Vec4_00421700 *, Vec4_00421700 *);
float func_00421CB0(Bounds_00421700 *, Vec4_00421700 *);
char *func_0041B630(void);
Box_00421700 *func_00422910(Obj_00421700 *);
char *func_0041B590(int);
List_00421700 *func_00448400(Obj_00421700 *);
float func_004534B0(Item_00421700 *);
char *func_0044D0F0(int, Effect_00421700 *, int);
void func_0044A790(char *, char *);
void func_00449CD0(Obj_00421700 *, char *, int);
void func_00449DE0(Obj_00421700 *, int);
