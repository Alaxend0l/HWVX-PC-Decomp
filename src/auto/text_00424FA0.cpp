/* 1 function from 0x00424FA0 to 0x00426600, found by Ghidra. */
#include "common.h"
struct Vec4_00424FA0 {
    float x, y, z, w;
};

struct Range_00424FA0 {
    float lo, hi;
};

struct Emit_00424FA0 {
    int count_lo, count_hi;
    Range_00424FA0 speed;
    Range_00424FA0 unk_0x10;
    Range_00424FA0 unk_0x18;
    char unk_0x20;
    char unk_0x21[3];
    float unk_0x24;
};

struct Place_00424FA0 {
    char unk_0x0[0x18];
    char reset;
    char hasOffset;
    char unk_0x1a[2];
    Range_00424FA0 *offset;
};

struct Cmd_00424FA0 {
    int op;
    int a;
    int b;
};

struct Script_00424FA0 {
    unsigned int count;
    Cmd_00424FA0 *cmds;
};

struct Point_00424FA0 {
    Vec4_00424FA0 pos;
    int unk_0x10;
    Range_00424FA0 unk_0x14;
    int unk_0x1c;
    int unk_0x20;
    char unk_0x24[0xc];
};

struct Burst_00424FA0 {
    int count_lo, count_hi;
    unsigned int numPoints;
    Point_00424FA0 *points;
};

struct Obj_00424FA0 {
    Vec4_00424FA0 unk_0x0;
    Vec4_00424FA0 mtx[3];
    Vec4_00424FA0 pos;
    Vec4_00424FA0 quat;
    char unk_0x60[0x14];
    unsigned int flags;
    char unk_0x78[8];
    short unk_0x80;
    char unk_0x82[0x12];
    char *owner;
    char unk_0x98[0xc];
    Obj_00424FA0 *next;
    char unk_0xa8[0x18];
    Vec4_00424FA0 unk_0xc0;
    Script_00424FA0 *script;
    unsigned int pc;
    unsigned int loopStart;
    unsigned int loopCount;
    unsigned int wait;
    unsigned int repeat;
    int repStart;
    int repLen;
    char repState;
    char active;
    char unk_0xf2[6];
    float unk_0xf8;
};

extern float D_00477000;
extern float D_0047700C;
extern float D_0069236C;
extern float D_00477260;
extern float D_004772D0;
extern float D_004771A0;
extern float D_004770AC;
extern Vec4_00424FA0 D_00692350;
extern Vec4_00424FA0 D_006922E0[4];
extern Obj_00424FA0 *D_0053A9D0;

float func_004534B0(Obj_00424FA0 *);
int func_0043BDF0(char *);
int func_00426600(Obj_00424FA0 *, int);
extern "C" int func_0042AFA0(void);
extern "C" int func_00454AF0(int, int);
float func_00454AC0(float, float);
void func_00453FB0(Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00424040(Emit_00424FA0 *, Obj_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00424860(Emit_00424FA0 *, Obj_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_0043BE70(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, char *, float, int);
char *func_0044D0B0(int, void *);
char *func_0044D0F0(int, void *, int);
void func_0044A790(char *, char *);
void func_004536E0(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00453300(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00423550(char *, Vec4_00424FA0 *, Obj_00424FA0 *);
int func_0042A680(int, int);
void func_00428F20(char *, Vec4_00424FA0 *);
float func_004535B0(Vec4_00424FA0 *, Vec4_00424FA0 *);
float func_004532E0(float);
void func_00428CE0(char *, Vec4_00424FA0 *, Obj_00424FA0 *, float);
void func_00439230(int, Vec4_00424FA0 *, int);
int func_00409E60(int);
void func_00409E90(int, int, int);
int func_00409500(int);
void func_004093E0(int, int, void *);
void func_00409DB0(int);
void func_00443740(int, Vec4_00424FA0 *);
float func_004534E0(Vec4_00424FA0 *);
void func_00454A30(Vec4_00424FA0 *);
extern "C" void func_00448330(Obj_00424FA0 *);
