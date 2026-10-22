/* 17 functions from 0x00467000 to 0x00467F10, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

/* opengl32 import slots are named without @N (__imp__glEnable): call them through the slots */
extern "C" void (__stdcall *_imp__glBlendFunc)(GLenum, GLenum);
extern "C" void (__stdcall *_imp__glTexEnvf)(GLenum, GLenum, GLfloat);
extern "C" void (__stdcall *_imp__glEnable)(GLenum);
extern "C" void (__stdcall *_imp__glDisable)(GLenum);
extern "C" void (__stdcall *_imp__glDepthMask)(GLboolean);
extern "C" void (__stdcall *_imp__glCullFace)(GLenum);
extern "C" void (__stdcall *_imp__glFogi)(GLenum, GLint);
extern "C" void (__stdcall *_imp__glDeleteTextures)(GLsizei, const GLuint *);
#define glBlendFunc (*_imp__glBlendFunc)
#define glTexEnvf (*_imp__glTexEnvf)
#define glEnable (*_imp__glEnable)
#define glDisable (*_imp__glDisable)
#define glDepthMask (*_imp__glDepthMask)
#define glCullFace (*_imp__glCullFace)
#define glFogi (*_imp__glFogi)
#define glDeleteTextures (*_imp__glDeleteTextures)

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

void func_00467150(int mode)
{
    switch (mode) {
    case 0:
        glDisable(GL_CULL_FACE);
        break;
    case 1:
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
        break;
    case 2:
        glCullFace(GL_FRONT);
        glEnable(GL_CULL_FACE);
        break;
    }
    D_006C99F0 = mode;
}

extern "C" void (__stdcall *_imp__glEnable)(GLenum);
extern "C" void (__stdcall *_imp__glDisable)(GLenum);
extern "C" void (__stdcall *_imp__glFogi)(GLenum, GLint);
void func_004671A0(int on)
{
    GLenum cap = GL_DEPTH_TEST;
    if (on == 1)
        (*_imp__glEnable)(cap);
    else
        (*_imp__glDisable)(cap);
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

void func_004671D0(int on)
{
    (*_imp__glFogi)(GL_FOG_MODE, GL_LINEAR);
    if (on == 1)
        (*_imp__glEnable)(GL_FOG);
    else
        (*_imp__glDisable)(GL_FOG);
    D_006C99E8 = on;
}

void func_00467E10(GLuint tex)
{
    glDeleteTextures(1, &tex);
}

