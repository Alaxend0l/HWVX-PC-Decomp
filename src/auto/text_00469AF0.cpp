/* 17 functions from 0x00469AF0 to 0x0046A71B, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <GL/gl.h>

struct Vec4_00469AF0 {
    float x, y, z, w;
};

struct Group_00469AF0 {
    Vec4_00469AF0 unk_0x0[4];
    unsigned int unk_0x40;
    int unk_0x44[5];
};

struct Light_00469AF0 {
    Vec4_00469AF0 unk_0x0;
    Vec4_00469AF0 unk_0x10;
    unsigned char unk_0x20[4];
};

struct State_00469AF0 {
    char pad_0x0[0x24];
    unsigned int unk_0x24;
    char pad_0x28[0x1abdc0 - 0x28];
    Light_00469AF0 unk_0x1abdc0[1];
};

struct Arrays_00469B80 {
    void *unk_0x0;
    void *unk_0x4;
    void *unk_0x8;
    void *unk_0xc;
};

#define GROUPS_00469AF0(s) ((Group_00469AF0 *)((char *)(s) + 0x1c9450))

extern State_00469AF0 *D_0049D7C8;

extern "C" void func_00460820(int a);
extern "C" void func_00467E20(int a);
extern "C" void func_00467130(int a);
extern "C" void func_00466FD0(int a);
extern "C" void func_00466FF0(void);
extern "C" void func_00469990(int a, int b);
extern "C" void func_00469970(void);
extern "C" void func_00469890(Vec4_00469AF0 *a, int *b, int c);

struct Image_00469F10 {
    int unk_0x0;
    void *unk_0x4;
    int unk_0x8;
    int unk_0xc;
};

extern "C" void func_0046B013(void *p);
extern "C" void *func_0046BC4D(unsigned int n, unsigned int size);

extern "C" void func_0046C1B3(void);
extern "C" void func_0046BE5D(void);
extern "C" void func_0046BEC3(void);
extern "C" void func_0046BE03(void);
extern "C" void func_0046BEAB(void);
extern void (*D_0047D44C)(void);
extern void (*D_0047D450)(void);
extern void (*D_0047D454)(void);
extern void (*D_0047D458)(void);
extern void (*D_0047D45C)(void);
extern void (*D_0047D460)(void);

extern "C" void func_00469AF0(int id, int b)
{
    unsigned char j;

    if (id == -1)
        return;
    func_00469990(id, b);
    func_00469970();
    for (j = 0; j < GROUPS_00469AF0(D_0049D7C8)[id].unk_0x40; j++)
        func_00469890(&GROUPS_00469AF0(D_0049D7C8)[id].unk_0x0[j],
                      &GROUPS_00469AF0(D_0049D7C8)[id].unk_0x44[j], j + 1);
}

extern "C" void func_0046A6C8(void)
{
    D_0047D44C = func_0046C1B3;
    D_0047D450 = func_0046BE5D;
    D_0047D454 = func_0046BEC3;
    D_0047D458 = func_0046BE03;
    D_0047D45C = func_0046BEAB;
    D_0047D460 = func_0046C1B3;
}

extern "C" void func_00469B80(Arrays_00469B80 *a)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 16, a->unk_0x0);
    glTexCoordPointer(2, GL_FLOAT, 8, a->unk_0x8);
    if (a->unk_0x4 != NULL) {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_UNSIGNED_BYTE, 4, a->unk_0x4);
    } else {
        glDisableClientState(GL_COLOR_ARRAY);
    }
    if (a->unk_0xc != NULL) {
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, 16, a->unk_0xc);
        return;
    }
    glDisableClientState(GL_NORMAL_ARRAY);
}

extern "C" void func_00469C20(void)
{
    unsigned int i;
    unsigned int n;

    func_00460820(0);
    func_00467E20(0xffff);
    func_00467130(0);
    func_00466FD0(1);
    n = D_0049D7C8->unk_0x24;
    for (i = 0; i < n; i++) {
        glColor3ubv(D_0049D7C8->unk_0x1abdc0[i].unk_0x20);
        glVertex3fv(&D_0049D7C8->unk_0x1abdc0[i].unk_0x0.x);
        glVertex3fv(&D_0049D7C8->unk_0x1abdc0[i].unk_0x10.x);
        n = D_0049D7C8->unk_0x24;
    }
    func_00466FF0();
}

extern "C" void func_00469DD0(Light_00469AF0 *l)
{
    l->unk_0x10.z = -1.0f;
    l->unk_0x0.z = -1.0f;
    glColor3ub(l->unk_0x20[0], l->unk_0x20[1], l->unk_0x20[2]);
    glVertex3fv(&l->unk_0x0.x);
    glVertex3fv(&l->unk_0x10.x);
}

extern "C" int func_00469F10(Image_00469F10 *img)
{
    if (img->unk_0x4 != NULL) {
        func_0046B013(img->unk_0x4);
        img->unk_0x4 = NULL;
    }
    img->unk_0x4 = func_0046BC4D(img->unk_0x8 * img->unk_0xc * 4, 1);
    return img->unk_0x4 != NULL;
}

extern "C" void func_0046A714(void)
{
}

