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

void func_004449B0(void)
{
    Ctx_00429EC0 *ctx;
    unsigned int n;
    unsigned int i;
    Obj_004401B0 *obj;
    unsigned char *info;

    ctx = func_00429EC0();
    n = func_00440130();
    for (i = 0; i < n; i++) {
        obj = func_004401B0(i);
        info = func_0042B040(obj->unk_0x60);
        if (ctx != NULL && ctx->unk_0x3c != 0) {
            if (info[1] >= ctx->unk_0x3c)
                info[1] = 0;
            func_00457120(info + 4, info + 0x12);
        } else {
            func_0043F4B0(obj, info[1]);
            func_004591B0(obj->unk_0xc8, info[0]);
        }
    }
}

void func_00444E00(unsigned char id)
{
    func_0040A810(id);
    func_00409EE0(id);
    func_00401090(id);
    func_0042E200(id);
    D_0048D974 = 1;
}

void func_00444F30(void)
{
    D_0053B1E8 = func_00444F50;
    D_0053B1EC = 0;
}

char func_00444E30(void)
{
    func_0044F200(1);
    while (func_00427760())
        ;
    D_00692374 = 0;
    func_00461AD0();
    func_00461B10();
    func_00461B30();
    func_00461AD0();
    func_00461B10();
    func_00461B30();
    func_0043B4E0();
    func_0040CB70();
    func_0044B910();
    func_00401090();
    func_00401090();
    D_006929A0();
    func_00401090();
    func_00401090();
    func_00442500();
    func_0043FF10();
    func_0044F200(0);
    func_004520B0();
    func_00450A60();
    func_00429FA0(0x19b, 0, 1);
    D_0048D974 = 0;
    func_004620A0();
    return 1;
}

