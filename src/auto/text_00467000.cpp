/* 17 functions from 0x00467000 to 0x00467F10, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

extern int D_006C9A68;
extern int D_006C99F8;
extern int D_006C9A70;
extern int D_006C9A74;
extern int D_006C99F0;
extern int D_006C99E8;

void func_00467000(int mode)
{
    switch (mode) {
    case 1:
        D_006C9A68 = GL_ONE;
        D_006C99F8 = GL_ZERO;
        break;
    case 2:
        D_006C9A68 = GL_ONE;
        D_006C99F8 = GL_ONE;
        break;
    case 3:
    case 8:
    case 10:
        D_006C9A68 = GL_ZERO;
        D_006C99F8 = GL_ONE_MINUS_SRC_COLOR;
        break;
    case 5:
    case 6:
    case 7:
        D_006C9A68 = GL_SRC_ALPHA;
        D_006C99F8 = GL_ONE_MINUS_SRC_ALPHA;
        break;
    }
    D_006C9A70 = mode;
    glBlendFunc(D_006C9A68, D_006C99F8);
}

void func_004670B0(int mode)
{
    D_006C9A74 = mode;
    switch (mode) {
    case 1:
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        break;
    case 2:
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        break;
    case 3:
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        break;
    case 4:
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
        break;
    }
}

void func_00467130(int on)
{
    if (on == 1)
        glEnable(GL_BLEND);
    else
        glDisable(GL_BLEND);
}

void func_004671C0(GLboolean flag)
{
    glDepthMask(flag);
}

