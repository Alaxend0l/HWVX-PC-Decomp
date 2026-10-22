/* 1 function from 0x00446840 to 0x00447390, found by Ghidra. */
#include "common.h"

struct Item_00446840 {
    char unk_0x0[0x1c];
    int unk_0x1c;
    char unk_0x20[0x10];
    unsigned short unk_0x30;
    char unk_0x32[4];
    unsigned char unk_0x36;
    unsigned char unk_0x37;
    char unk_0x38[8];
};

struct Group_00446840 {
    char unk_0x0[0x14];
    unsigned int count;
    Item_00446840 *items;
};

struct Node_00446840 {
    char unk_0x0[0x1c];
    int unk_0x1c;
    unsigned int count;
    int *ids;
    char unk_0x28[8];
    Group_00446840 *group;
    char unk_0x34[0x1c];
};

struct Car_00446840 {
    char unk_0x0[0x24];
    int unk_0x24;
    char unk_0x28[8];
    unsigned int unk_0x30;
    char unk_0x34;
    unsigned char unk_0x35;
    char unk_0x36;
    unsigned char unk_0x37;
    char unk_0x38[0x18];
    int unk_0x50;
    int unk_0x54;
    char unk_0x58[5];
    signed char unk_0x5d;
    signed char unk_0x5e;
    char unk_0x5f;
};

struct Names_00446840 {
    char unk_0x0[0xa0];
    int unk_0xa0;
    int unk_0xa4;
};

struct Track_00446840 {
    int unk_0x0;
    int unk_0x4;
    unsigned int ncars;
    Car_00446840 *cars;
    char unk_0x10[0x10];
    unsigned int nnodes;
    Node_00446840 *nodes;
    char unk_0x28[0x54];
    int unk_0x7c;
    int unk_0x80;
    int unk_0x84;
    int unk_0x88;
    char unk_0x8c[0x10];
    Names_00446840 *names;
};

struct Cfg_00446840 {
    char unk_0x0;
    char unk_0x1[0xf];
    int unk_0x10;
};

extern int D_0048D940;
extern int D_0047B3F0;
extern int D_00496E18;
extern char D_0047B52C[];
extern char D_0047B504[];
extern char D_0047B4DC[];
extern char D_0047B4B0[];
extern char D_0047B48C[];
extern char D_0047B468[];
extern char D_0047B440[];
extern char D_0049DBB4;
extern int D_0048D8F8;
extern int *D_0049DBA8;
extern Track_00446840 *D_0049DBA0;
extern int D_0049DBB0;
extern int **D_0049DBAC;
extern unsigned int D_0048D908;
extern unsigned int D_0048D948;
extern Car_00446840 *D_0048D944;
extern Node_00446840 *D_0048D830[];
extern unsigned int D_0048D900;
extern char D_0048D910;
extern int D_0048D8FC;
extern int D_0048D904;
extern char D_0048D93D;

extern "C" void func_004420E0(void);
extern "C" void func_00452F70(const char *fmt, ...);
extern "C" int func_004287E0(int name, int a, int b, int c);
extern "C" int func_004289E0(int name, int a, int b);
extern "C" int func_00428C10(int a, int b, int c);
extern "C" bool func_00427760(void);
extern "C" void func_00427840(void);
extern "C" unsigned int func_00427770(void);
extern "C" bool func_0040A170(int a, Car_00446840 *car);
extern "C" void func_00428360(Node_00446840 **list, unsigned int count, bool flag);
extern "C" Cfg_00446840 *func_00429EC0(void);
extern "C" void func_00421400(int a);
extern "C" int func_0042A680(int a, int b);
extern "C" int func_00454A70(int a, int b);
extern "C" int func_00429EA0(void);
extern "C" bool func_0042AFB0(int a);
extern "C" int func_004216C0(int a, int b);
extern "C" void func_00452030(void);
extern "C" void func_00452040(void);
