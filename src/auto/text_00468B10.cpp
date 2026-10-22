/* 9 functions from 0x00468B10 to 0x00469AF0, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

extern "C" void func_00469970(void)
{
    int i;
    GLenum light = GL_LIGHT1;
    for (i = 0; i < 6; i++, light++)
        glDisable(light);
}
