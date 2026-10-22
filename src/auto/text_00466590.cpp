/* 13 functions from 0x00466590 to 0x00466FF5, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>
#include <string.h>

struct Mode_006C9A0C {
    short unk_0x00;
    short unk_0x02;
    short unk_0x04;
    short unk_0x06;
    char unk_0x08[0x18 - 0x08];
};

extern Mode_006C9A0C D_006C9A0C[];
extern int D_006C9A78;
extern char D_006C9AC0;
extern int *D_0049D7C4;
extern int D_0049D7EC;
extern char D_0049D7F0;
extern char D_0047D380[];
extern char D_0047C198[];
extern unsigned char D_0047D394[];
extern int D_006C9A7C;
extern int D_006C99E8;

char *func_00461D50(void);
void func_00460B30(int a);
void func_00466410(int id);
void func_004668B0(int x, int y, int w, int h);
void func_004669A0(char *name, void *pixels, int w, int h);
extern "C" void *func_0046AED9(unsigned int size);
extern "C" void func_0046B013(void *p);
extern "C" int func_0046A89F(char *string, const char *format, ...);

void func_00466590(void)
{
    memset(D_0049D7C4, 0, 0x18);
}

void func_004668B0(int x, int y, int w, int h)
{
    glViewport(x, y, w, h);
}

void func_00466FD0(int mode)
{
    switch (mode) {
    case 0:
        glBegin(GL_TRIANGLES);
        break;
    case 1:
        glBegin(GL_LINES);
        break;
    }
}

extern short D_006C9A0E[];
void func_004668D0(void)
{
    char name[256];
    int w = D_006C9A0C[D_006C9A78].unk_0x00;
    int h = D_006C9A0C[D_006C9A78].unk_0x02;
    void *pixels = func_0046AED9(w * h * 3);

    glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    func_0046A89F(name, D_0047D380, D_0049D7EC++);
    func_004669A0(name, pixels, w, h);
    func_0046B013(pixels);
    D_0049D7F0 = 0;
}

void func_004667F0(int id, int w, int h)
{
    func_00466410(id);
    if (!D_006C9AC0) {
        Mode_006C9A0C *m = &D_006C9A0C[D_006C9A78];
        short sw = w;
        short sh = h;
        D_006C9A0C[D_006C9A78].unk_0x00 = sw;
        D_006C9A0C[D_006C9A78].unk_0x02 = sh;
        D_006C9A0C[D_006C9A78].unk_0x04 = sw / 2;
        D_006C9A0C[D_006C9A78].unk_0x06 = sh / 2;
        func_004668B0(0, 0, w, h);
        func_00460B30(*(int *)(func_00461D50() + 0x270));
        *(int *)(func_00461D50() + 0x2b0) = 0;
        *(int *)(func_00461D50() + 0x2b8) = 0;
        *(int *)(func_00461D50() + 0x280) = w;
        *(int *)(func_00461D50() + 0x284) = h;
    }
}

