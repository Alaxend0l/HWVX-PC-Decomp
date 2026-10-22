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
extern int *D_0049D7C8;
extern int D_006C9AC4;
extern int D_006D3D60;
extern int D_006D3D64;
extern int D_006C9A6C;
extern float D_00477000;

struct Blk_00467210 {
    int unk[64];
};

struct Elem_004675B0 {
    float unk_0x0[4];
    float unk_0x10[3];
    int unk_0x1c;
};

float func_00453360(void *, void *);

struct Tex_00467E80 {
    char unk_0x0[0x3e];
    short unk_0x3e;
};

extern int D_006D4D0C;
extern int D_006D3E30;
extern Tex_00467E80 *D_006D3D44;

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

void func_00467E20(unsigned short tex)
{
    if (tex == D_006D4D0C)
        return;
    D_006D3E30++;
    if (tex >= 0xfffe) {
        glDisable(GL_TEXTURE_2D);
        D_006D4D0C = 0xffff;
        return;
    }
    D_006D4D0C = tex;
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);
}

void func_00467E80(unsigned short tex)
{
    short wrap;

    glBindTexture(GL_TEXTURE_2D, tex);
    wrap = D_006D3D44[tex].unk_0x3e;
    if (wrap == 0) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    } else if (wrap == 1) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    }
}

void func_004675B0(Elem_004675B0 *elems, unsigned int count, void *v)
{
    unsigned int i;

    for (i = 0; i < count; i++) {
        float a = func_00453360(elems[i].unk_0x0, v);
        float b = func_00453360(elems[i].unk_0x10, v);
        if (a < D_00477000 && b > D_00477000)
            elems[i].unk_0x1c = 2;
        else if (a > D_00477000 && b < D_00477000)
            elems[i].unk_0x1c = 1;
        else
            elems[i].unk_0x1c = 0;
    }
}

void func_00467810(int mode)
{
    int filter;

    switch (mode) {
    case 0:
        filter = GL_NEAREST;
        break;
    case 1:
        filter = GL_LINEAR_MIPMAP_NEAREST;
        break;
    case 3:
        filter = GL_NEAREST_MIPMAP_NEAREST;
        break;
    case 4:
        filter = GL_NEAREST_MIPMAP_LINEAR;
        break;
    case 2:
        filter = GL_LINEAR_MIPMAP_LINEAR;
        break;
    default:
        filter = mode;
        break;
    }
    D_006C9A6C = filter;
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

int func_00467880(int width, int height, int format)
{
    int size = ((width + 3) & ~3) * ((height + 3) & ~3);

    if (format == 0x83f0 || format == 0x83f1)
        size >>= 1;
    return size;
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
    glFogi(GL_FOG_MODE, GL_LINEAR);
    if (on == 1)
        glEnable(GL_FOG);
    else
        glDisable(GL_FOG);
    D_006C99E8 = on;
}

void func_00467210(Blk_00467210 *dst)
{
    D_006D3D60 = D_0049D7C8[5];
    D_006D3D64 = D_006C9AC4;
    *dst = *(Blk_00467210 *)&D_006D3D60;
}

void func_00467E10(GLuint tex)
{
    glDeleteTextures(1, &tex);
}

