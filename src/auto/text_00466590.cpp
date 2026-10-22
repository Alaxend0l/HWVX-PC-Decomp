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

char *func_00461D50(void);
void func_00460B30(int a);
void func_00466410(int id);
void func_004668B0(int x, int y, int w, int h);
void func_004669A0(char *name, void *pixels, int w, int h);
extern "C" void *func_0046AED9(unsigned int size);
extern "C" void func_0046B013(void *p);
extern "C" int func_0046A89F(char *string, const char *format, ...);

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
