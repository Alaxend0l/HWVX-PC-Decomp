/* 1 function from 0x00416A40 to 0x00418030, found by Ghidra. */
#include "common.h"

struct Vec4_00416A40 {
    float x;
    float y;
    float z;
    float w;
};

struct Mat4_00416A40 {
    Vec4_00416A40 row0;
    Vec4_00416A40 row1;
    Vec4_00416A40 row2;
    Vec4_00416A40 pos;
};

struct Surface_00416A40 {
    char unk_0x00;
    char unk_0x01;
    u16 unk_0x02;
    char unk_0x04[0x14 - 0x04];
    float unk_0x14;
    char unk_0x18[0x2c - 0x18];
    u32 *unk_0x2c;
    int unk_0x30;
    int unk_0x34;
    char unk_0x38[0x3c - 0x38];
    Surface_00416A40 *unk_0x3c;
    int unk_0x40;
};

struct Hit_00416A40 {
    Vec4_00416A40 point;
    Vec4_00416A40 normal;
    char unk_0x20[0x28 - 0x20];
    Surface_00416A40 *surface;
    Vec4_00416A40 vel;
};

struct Particle_00416A40 {
    Vec4_00416A40 pos;
    Vec4_00416A40 unk_0x10;
    Vec4_00416A40 vel;
    Vec4_00416A40 unk_0x30;
    int unk_0x40;
    int unk_0x44;
    int unk_0x48;
    float unk_0x4c;
};

struct Wheel_00416A40 {
    float radius;
    char unk_0x04[0x0c - 0x04];
    float unk_0x0c;
    float unk_0x10;
    float unk_0x14;
    float unk_0x18;
    float unk_0x1c;
    float unk_0x20;
    float unk_0x24;
    char unk_0x28[0x38 - 0x28];
    float unk_0x38;
    u8 unk_0x3c;
    u8 unk_0x3d;
    u8 unk_0x3e;
    u8 unk_0x3f;
    u16 unk_0x40;
    u8 unk_0x42;
    char unk_0x43[0x50 - 0x43];
};

struct CarParams_00416A40 {
    char unk_0x00[0x04];
    float unk_0x04;
    float unk_0x08;
    char unk_0x0c[0x14 - 0x0c];
    float unk_0x14;
    char unk_0x18[0x40 - 0x18];
    float unk_0x40;
    float unk_0x44;
    float unk_0x48;
};

struct CarPhys_00416A40 {
    char unk_0x00[0x44];
    float unk_0x44;
    char unk_0x48[0x6c - 0x48];
    float unk_0x6c;
};

struct Gear_00416A40 {
    float ratio;
    float unk_0x4;
};

struct CarDef_00416A40 {
    char unk_0x00[0x11];
    u8 type;
    char unk_0x12[0x14 - 0x12];
    u16 unk_0x14;
    char unk_0x16[0x30 - 0x16];
    float unk_0x30;
    char unk_0x34[0x50 - 0x34];
    int unk_0x50;
    char unk_0x54[0x6c - 0x54];
    u32 *unk_0x6c;
    char unk_0x70[0x80 - 0x70];
    CarPhys_00416A40 *phys;
    char unk_0x84[0x88 - 0x84];
    CarParams_00416A40 *params;
    char unk_0x8c[0xd0 - 0x8c];
    u32 numWheels;
    Wheel_00416A40 *wheels;
    char unk_0xd8[0xdc - 0xd8];
    Gear_00416A40 *gears;
};

struct Player_00416A40 {
    s8 unk_0x00;
    char unk_0x01[0x0c - 0x01];
    u8 unk_0x0c;
    char unk_0x0d[0x12 - 0x0d];
    u8 unk_0x12;
    u8 unk_0x13;
    u8 unk_0x14;
    char unk_0x15[0xc8 - 0x15];
    int unk_0xc8;
};

struct WheelState_00416A40 {
    s16 unk_0x00;
    s16 unk_0x02;
    char unk_0x04[0x08 - 0x04];
    float unk_0x08;
    float unk_0x0c;
    u32 color;
    u32 unk_0x14;
    Vec4_00416A40 slip;
    char unk_0x28[0x2c - 0x28];
};

struct Car_00416A40 {
    Vec4_00416A40 vel;
    Mat4_00416A40 mat;
    char unk_0x050[0x94 - 0x50];
    Player_00416A40 *player;
    char unk_0x098[0x1b4 - 0x98];
    WheelState_00416A40 ws[8];
    char unk_0x314[0x320 - 0x314];
    Mat4_00416A40 *bones;
    char unk_0x324[0x35c - 0x324];
    float unk_0x35c[4];
    char unk_0x36c[0x394 - 0x36c];
    int contacts;
    CarDef_00416A40 *def;
    char unk_0x39c[0x3e0 - 0x39c];
    int unk_0x3e0;
    Vec4_00416A40 unk_0x3e4;
    char unk_0x3f4[0x428 - 0x3f4];
    Surface_00416A40 *lastSurface;
    float speed;
    char unk_0x430[0x440 - 0x430];
    int unk_0x440;
    char unk_0x444[0x460 - 0x444];
    u32 flags;
    char unk_0x464[0x4b0 - 0x464];
    float unk_0x4b0;
    u8 gear;
    char unk_0x4b5[0x4c4 - 0x4b5];
    int sound;
    float unk_0x4c8;
    char unk_0x4cc[0x4ec - 0x4cc];
    Vec4_00416A40 unk_0x4ec;
    Vec4_00416A40 unk_0x4fc;
};

extern Vec4_00416A40 D_00692350;
extern u32 D_00692364;
extern s16 D_00692370;
extern float D_00692378;
extern char D_0068DF05;
extern Car_00416A40 *D_0048D97C;
extern float D_00477000;
extern float D_00477008;
extern float D_0047700C;
extern float D_00477038;
extern float D_00477064;
extern float D_00477078;
extern float D_00477120;
extern float D_0047714C;
extern float D_00477158;
extern float D_004771A4;
extern float D_004771AC;
extern float D_004771B4;
extern float D_004771D8;
extern float D_0047721C;
extern float D_00477220;
extern float D_00477234;
extern float D_00477254;
extern float D_00477258;
extern float D_0047725C;
extern float D_00477260;
extern float D_00477264;
extern float D_0047726C;
extern float D_00477270;
extern float D_00477274;
extern float D_00477278;
extern float D_0047727C;
extern float D_00477280;
extern float D_00477284;
extern float D_00477288;
extern float D_0047728C;

float func_00453360(void *, void *);
float func_004532F0(float);
float func_004534B0(void *);
void func_00453330(void *, void *, void *);
void func_00453380(void *, void *, void *);
void func_00453300(Car_00416A40 *, void *, void *);
void func_00453470(void *);
void func_004535E0(void *, void *, void *);
void func_00454300(void *, void *);
float func_00454AC0(float, float);
float func_00462040(void *);
char func_0043E9F0(Player_00416A40 *);
char func_0044D550(Vec4_00416A40 *, Vec4_00416A40 *, float *, Hit_00416A40 *);
void func_0040E070(Car_00416A40 *, Vec4_00416A40 *, Vec4_00416A40 *, float);
void func_00458220(int, int, int, int);
void func_00401090(int, int, int);
void func_00458250(int, int);
void func_00458280(int);
void func_004582A0(int);
void func_0044D0B0(int, Particle_00416A40 *);
int func_0043BDF0(int);
void func_0043BE70(void *, void *, void *, void *, int, float, int);
void func_00416080(float *, float *, float);
void func_004093E0(int, int, void *);
void func_004160C0(Car_00416A40 *);
