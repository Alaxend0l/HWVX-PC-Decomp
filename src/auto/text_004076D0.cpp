/* 14 functions from 0x004076D0 to 0x00408690, found by Ghidra. */
#include "common.h"

struct Vec4_004076D0 {
    float x;
    float y;
    float z;
    float w;
};

struct Item_004076D0 {
    char unk_0x00[0x14];
    float unk_0x14;
    char unk_0x18[0x20 - 0x18];
};

struct List_004076D0 {
    unsigned int count;
    Item_004076D0 *items;
};

struct Info_004076D0 {
    char unk_0x00[0x2c];
    unsigned int unk_0x2c;
};

struct Obj_004076D0 {
    char unk_0x00[0x14];
    char unk_0x14[0x18 - 0x14];
    Info_004076D0 *unk_0x18;
    char unk_0x1c[0x1e - 0x1c];
    char unk_0x1e;
    char unk_0x1f[0x28 - 0x1f];
    float unk_0x28;
    float unk_0x2c;
};

void func_0044AD00(void *, void *, void *, void *, void *, int);
extern float D_00692378;
extern float D_0047700C;
void func_00407BC0(int **obj, int arg);
void func_00407BE0(int *, int, Vec4_004076D0 *);

void func_004076D0(Obj_004076D0 *obj, List_004076D0 *list, Vec4_004076D0 *color)
{
    Vec4_004076D0 q;
    Vec4_004076D0 c;
    float hi;
    float lo;
    unsigned int i;
    int off;

    off = 0;
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    c.w = 0.0f;
    if (color != 0)
        c = *color;
    lo = obj->unk_0x28;
    hi = obj->unk_0x2c;
    for (i = 0; i < obj->unk_0x18->unk_0x2c; i++, off += sizeof(Item_004076D0)) {
        Item_004076D0 *item = (Item_004076D0 *)((char *)list->items + off);
        float f = item->unk_0x14;
        if (obj->unk_0x1e ? (lo > f && hi <= f) : (lo <= f && hi > f)) {
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            q.w = 1.0f;
            func_0044AD00(obj->unk_0x14, item, item, &q, &c, 0xff);
        }
    }
}

void func_004081C0(Obj_004076D0 *obj, int b, Vec4_004076D0 *color)
{
    float *t = (float *)((char *)obj + 0x24);

    *t = D_00692378 + *t;
    if (*t > D_0047700C)
        *t = 1.0f;
    func_00407BC0((int **)((char *)obj + 0x18), 2);
}

void func_00408260(Obj_004076D0 *obj, int b, Vec4_004076D0 *color)
{
    if (!b)
        return;
    func_004076D0(obj, (List_004076D0 *)&(*(Info_004076D0 **)obj)->unk_0x2c, color);
    func_00407BE0((int *)obj, b, color);
}

void func_004082C0(Obj_004076D0 *obj, int b, Vec4_004076D0 *color)
{
    func_004081C0(obj, b, color);
    func_00408260(obj, b, color);
}

extern float D_00692378;
extern float D_0047700C;
void func_004077E0(int **, int, int);
void func_00407350(int *, char *);
void func_00408440(int, int, char *, int, int, int);
void func_00407BE0(int *, int, Vec4_004076D0 *);
void func_00407DA0(Obj_004076D0 *, Vec4_004076D0 *);
void func_00408260(Obj_004076D0 *obj, int b, Vec4_004076D0 *color);
void func_00407BC0(int **obj, int arg)
{
    func_004077E0(obj, arg, (*obj)[6]);
}

void func_00408200(int a, int b, int *obj, int d)
{
    int *q;
    char buf[0x800];

    if (obj[4] == 0)
        return;
    q = *(int **)(*obj + 0x14);
    func_00407350(obj, buf);
    func_00408440(a, b, buf, *q, d, obj[4]);
}

