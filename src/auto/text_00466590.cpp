/* 13 functions from 0x00466590 to 0x00466FF5, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

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
