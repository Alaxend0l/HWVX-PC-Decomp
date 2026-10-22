/* 7 functions from 0x004608C0 to 0x004617F0, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

struct Vec4_00460E60 {
    float x, y, z, w;
};

struct Obj_00461D50 {
    char unk_0x000[0x180];
    Vec4_00460E60 unk_0x180;
    Vec4_00460E60 unk_0x190;
    Vec4_00460E60 unk_0x1a0;
    Vec4_00460E60 unk_0x1b0;
    char unk_0x1c0[0x270 - 0x1c0];
    float unk_0x270;
};

struct Mode_006C9A0C {
    short unk_0x00;
    short unk_0x02;
    char unk_0x04[0x18 - 0x04];
};

extern Mode_006C9A0C D_006C9A0C[];
extern int D_006C9A78;
extern Vec4_00460E60 D_006D5740;
extern Vec4_00460E60 D_006D5750;
extern Vec4_00460E60 D_006D5760;
extern Vec4_00460E60 D_006D5770;

Obj_00461D50 *func_00461D50(void);
void func_004608C0(int, int, int, int);

float func_00460DB0(void)
{
    return func_00461D50()->unk_0x270;
}

void func_00460DC0(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, D_006C9A0C[D_006C9A78].unk_0x00, D_006C9A0C[D_006C9A78].unk_0x02, 0.0, 1.0, 30000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    func_004608C0(0, 0, 0, 0);
}

void func_00460E60(void)
{
    D_006D5740 = func_00461D50()->unk_0x180;
    D_006D5770 = func_00461D50()->unk_0x190;
    D_006D5750 = func_00461D50()->unk_0x1a0;
    D_006D5760 = func_00461D50()->unk_0x1b0;
}

