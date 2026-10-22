/* 8 functions from 0x0041A450 to 0x0041B410, found by Ghidra. */
#include "common.h"

struct Cell_0041A450 {
    char unk_0x0[0x20];
    int unk_0x20;
    char unk_0x24[0xc];
};

struct Grid_0041A450 {
    float x, y, z;
    char unk_0xc[0x1c];
    float sx, sy, sz;
    char unk_0x34[0x20];
    Cell_0041A450 *cells;
};

struct Obj_0041A450 {
    char unk_0x0[0x3c];
    int unk_0x3c;
    unsigned int count;
    unsigned short *ids;
};

extern Grid_0041A450 **D_0049DBA0;
extern int D_0049DBA4;

char func_0041DBE0(int, Cell_0041A450 *, int);
char *func_00419420(int, int, int);
char func_0041A350(char *, float *);
int func_0041A550(float *, float *, int, int, int, int, float *, float *);
char func_0041A4D0(float *, float *);

static inline int func_0041A450_cell(float p, float o, float s)
{
    return (int)((p - o) / s);
}

char func_0041A450(int a, Obj_0041A450 *obj, int c)
{
    unsigned int i;
    Cell_0041A450 *cell;

    if (obj->unk_0x3c == 0 && obj->count == 0)
        return 0;
    for (i = 0; i < obj->count; i++) {
        cell = &(*D_0049DBA0)->cells[obj->ids[i]];
        if (cell->unk_0x20 != D_0049DBA4) {
            cell->unk_0x20 = D_0049DBA4;
            if (func_0041DBE0(a, cell, c))
                return 1;
        }
    }
    return 0;
}

char func_0041A4D0(float *box, float *pt)
{
    if (pt[0] >= box[0] - 0.1f && pt[0] <= box[4] + 0.1f
        && pt[1] >= box[1] - 0.1f && pt[1] <= box[5] + 0.1f
        && pt[2] >= box[2] - 0.1f && pt[2] <= box[6] + 0.1f)
        return 1;
    return 0;
}

int func_0041A9F0(float *from, float *dir, int c, float *t, int e)
{
    float scale;
    float to[4];
    float hit[4];
    int r;

    to[0] = dir[0] * *t + from[0];
    scale = 1.0f;
    to[1] = dir[1] * *t + from[1];
    to[2] = dir[2] * *t + from[2];
    r = func_0041A550(from, to, c, 0, 0, e, &scale, hit);
    if (r == 0 || !func_0041A4D0((float *)c, hit))
        return 0;
    *t = scale * *t;
    return r;
}

char func_0041AC80(float *pos)
{
    Grid_0041A450 *g;
    int x, y, z;
    char *cell;

    if (D_0049DBA0 != NULL && (g = *D_0049DBA0) != NULL) {
        x = (int)((-g->x + pos[0]) / g->sx);
        y = (int)((-g->y + pos[1]) / g->sy);
        z = (int)((-g->z + pos[2]) / g->sz);
        cell = func_00419420(x, y, z);
        return func_0041A350(cell, pos);
    }
    return 0;
}

