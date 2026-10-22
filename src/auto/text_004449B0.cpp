/* 13 functions from 0x004449B0 to 0x004453E0, found by Ghidra. */
#include "common.h"
struct Ctx_00429EC0 {
    char unk_0x00[0x3c];
    unsigned int unk_0x3c;
};

struct Obj_004401B0 {
    char unk_0x00[0x60];
    int unk_0x60;
    char unk_0x64[0xc8 - 0x64];
    int unk_0xc8;
};

extern void (*D_0053B1E8)(void);
extern int D_0053B1EC;
extern char D_0048D974;
extern char D_00692374;
extern void (*D_006929A0)(void);

Ctx_00429EC0 *func_00429EC0(void);
unsigned char func_00440130(void);
Obj_004401B0 *func_004401B0(int);
unsigned char *func_0042B040(int);
void func_00457120(unsigned char *, unsigned char *);
void func_0043F4B0(Obj_004401B0 *, int);
void func_004591B0(int, int);
void func_00444F50(void);
void func_0040A810(unsigned char);
void func_00409EE0(int);
void func_00401090(void);
void func_00401090(int);
void func_0042E200(int);
void func_0044F200(char);
char func_00427760(void);
void func_00461AD0(void);
void func_00461B10(void);
void func_00461B30(void);
void func_0043B4E0(void);
void func_0040CB70(void);
void func_0044B910(void);
void func_00442500(void);
void func_0043FF10(void);
void func_004520B0(void);
void func_00450A60(void);
void func_00429FA0(int, int, int);
void func_004620A0(void);
