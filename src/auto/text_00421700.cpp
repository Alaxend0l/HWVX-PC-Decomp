/* 9 functions from 0x00421700 to 0x00422600, found by Ghidra. */
#include "common.h"

struct Vec4_00421700 {
    float x, y, z, w;
};

struct Bounds_00421700 {
    char unk_0x0[0xc];
    float unk_0xc;
    char unk_0x10[0x10];
    float radius;
    char unk_0x24[0xc];
};

struct Shape_00421700 {
    char unk_0x0[0x10];
    Bounds_00421700 bounds;
};

struct Info_00421700 {
    char unk_0x0[0x10];
    unsigned char type;
    unsigned char unk_0x11;
    char unk_0x12[2];
    int unk_0x14;
    char unk_0x18[4];
    int unk_0x1c;
    char unk_0x20[0x24];
    Bounds_00421700 *bounds;
    int unk_0x48;
};

struct Model_00421700 {
    Shape_00421700 *shape;
    unsigned char kind;
    unsigned char unk_0x5;
    unsigned char unk_0x6;
    char unk_0x7;
    float unk_0x8;
    char unk_0xc[4];
    Info_00421700 *info;
    char unk_0x14[4];
    char unk_0x18[4];
};

struct Desc_00421700 {
    Vec4_00421700 unk_0x0;
    Vec4_00421700 unk_0x10;
    char unk_0x20[0x10];
    Vec4_00421700 unk_0x30;
    Model_00421700 *model;
    char unk_0x44[4];
    float unk_0x48;
    char unk_0x4c[4];
    int unk_0x50;
    int unk_0x54;
    char unk_0x58[4];
    int unk_0x5c;
};

enum ObjFlags_00421700 { OBJFLAGS_00421700_NONE = 0 };

struct Obj_00421700 {
    Vec4_00421700 unk_0x0;
    Vec4_00421700 unk_0x10;
    char unk_0x20[0x20];
    Vec4_00421700 unk_0x40;
    Vec4_00421700 unk_0x50;
    char unk_0x60[0x10];
    float radius;
    union {
        int flags;
        ObjFlags_00421700 eflags;
        struct {
            unsigned int b0 : 1;
            unsigned int b1 : 1;
            unsigned int b2 : 1;
            unsigned int b3 : 1;
            unsigned int b4 : 3;
            unsigned int b7 : 1;
            unsigned int b8 : 1;
            unsigned int b9 : 1;
            unsigned int b10 : 7;
            unsigned int b17 : 1;
            unsigned int b18 : 1;
            unsigned int b19 : 1;
            unsigned int b20 : 1;
            unsigned int b21 : 5;
            unsigned int b26 : 1;
            unsigned int b27 : 1;
            unsigned int b28 : 1;
            unsigned int b29 : 1;
            unsigned int b30 : 1;
            unsigned int b31 : 1;
        } bits;
    };
    int unk_0x78;
    int unk_0x7c;
    short type;
    char unk_0x82[6];
    char unk_0x88[4];
    void *unk_0x8c;
    char unk_0x90[0x30];
    Model_00421700 *model;
    float unk_0xc4;
    int unk_0xc8;
    char *unk_0xcc;
    char *unk_0xd0;
    int unk_0xd4;
    int unk_0xd8;
    int unk_0xdc;
};

struct Box_00421700 {
    char unk_0x0[0x10];
    Vec4_00421700 pts[8];
    char unk_0x90[0x40];
    Vec4_00421700 min;
    Vec4_00421700 max;
};

struct Item_00421700 {
    char unk_0x0[0x10];
    float unk_0x10;
    char unk_0x14[0xc];
};

struct List_00421700 {
    unsigned int count;
    Item_00421700 *items;
};

struct Effect_00421700 {
    Vec4_00421700 a, b, c;
    Shape_00421700 *shape;
    char *unk_0x34;
};

extern Vec4_00421700 D_00692350;
extern char D_0047A830[];
extern char D_0047B088[];
extern char D_0047B040[];
extern char D_0047A3B0[];

void func_004482C0(Obj_00421700 *, Desc_00421700 *);
void func_00453FB0(Vec4_00421700 *, Vec4_00421700 *);
float func_00421CB0(Bounds_00421700 *, Vec4_00421700 *);
char *func_0041B630(void);
Box_00421700 *func_00422910(Obj_00421700 *);
char *func_0041B590(int);
List_00421700 *func_00448400(Obj_00421700 *);
float func_004534B0(Item_00421700 *);
char *func_0044D0F0(int, Effect_00421700 *, int);
void func_0044A790(char *, char *);
void func_00449CD0(Obj_00421700 *, char *, int);
void func_00449DE0(Obj_00421700 *, int);

char func_00421DD0(Obj_00421700 *obj, Desc_00421700 *desc)
{
    Model_00421700 *model;
    Info_00421700 *info;

    obj->flags = 0;
    func_004482C0(obj, desc);
    obj->unk_0x50 = desc->unk_0x30;
    obj->unk_0x0 = desc->unk_0x10;
    func_00453FB0(&obj->unk_0x50, &obj->unk_0x10);
    obj->unk_0x40 = desc->unk_0x0;
    obj->model = desc->model;
    obj->unk_0xd0 = NULL;
    obj->unk_0xcc = NULL;
    obj->unk_0xd4 = 0;

    if (desc->model->info->type == 3) {
        Bounds_00421700 *b = desc->model->info->bounds;
        *b = desc->model->shape->bounds;
        b->radius = func_00421CB0(b, &D_00692350);
        obj->model->info->type = 0;
    }

    obj->bits.b2 = 1;
    switch (obj->model->info->type) {
    case 0: {
        Box_00421700 *box;
        int i;

        obj->type = 1;
        obj->bits.b7 = 1;
        obj->unk_0xd0 = func_0041B630();
        *(int *)(obj->unk_0xd0 + 0xcc) = 0;
        box = func_00422910(obj);
        box->min.x = 99999.9f;
        box->min.y = 99999.9f;
        box->min.z = 99999.9f;
        box->max.x = -99999.9f;
        box->max.y = -99999.9f;
        box->max.z = -99999.9f;
        for (i = 0; i < 8; i++) {
            Vec4_00421700 v = box->pts[i];
            if (v.x < box->min.x)
                box->min.x = v.x;
            if (v.y < box->min.y)
                box->min.y = v.y;
            if (v.z < box->min.z)
                box->min.z = v.z;
            if (v.x > box->max.x)
                box->max.x = v.x;
            if (v.y > box->max.y)
                box->max.y = v.y;
            if (v.z > box->max.z)
                box->max.z = v.z;
        }
        {
            Bounds_00421700 *b = obj->model->info->bounds;
            obj->radius = b->radius = func_00421CB0(b, &D_00692350);
        }
        break;
    }
    case 1:
        obj->type = 4;
        obj->unk_0xcc = func_0041B590(obj->model->info->unk_0x48);
        obj->unk_0xcc[0x3cc] = 0;
        obj->radius = 30.0f;
        break;
    case 4:
        obj->bits.b1 = 1;
        obj->bits.b17 = 1;
        obj->type = 0;
        break;
    case 6:
        obj->type = 5;
        obj->unk_0xcc = func_0041B590(obj->model->info->unk_0x48);
        obj->unk_0xcc[0x3cc] = 1;
        obj->radius = 30.0f;
        break;
    case 7: {
        List_00421700 *list;
        unsigned int i;

        obj->type = 6;
        list = func_00448400(obj);
        obj->radius = 0.0f;
        for (i = 0; i < list->count; i++) {
            float r = func_004534B0(&list->items[i]) + list->items[i].unk_0x10;
            if (r > obj->radius)
                obj->radius = r;
        }
        break;
    }
    default:
        obj->bits.b2 = 0;
        obj->bits.b1 = 1;
        obj->bits.b17 = 1;
        obj->bits.b18 = 1;
        obj->type = 0;
        obj->radius = 0.0f;
        break;
    }

    obj->bits.b18 = 1;
    switch (desc->unk_0x50) {
    case 0:
        obj->bits.b2 = 0;
        obj->bits.b3 = 1;
        obj->bits.b30 = 1;
        obj->unk_0xd4 = 0;
        obj->unk_0x8c = D_0047A830;
        break;
    case 1:
        obj->bits.b3 = 0;
        obj->bits.b26 = 1;
        obj->unk_0xd4 = desc->unk_0x5c;
        obj->unk_0xdc = 0;
        obj->unk_0xd8 = desc->unk_0x54;
        obj->unk_0x8c = D_0047B088;
        break;
    case 2:
        obj->bits.b2 = 0;
        obj->bits.b3 = 0;
        obj->bits.b18 = 0;
        obj->bits.b17 = 1;
        obj->bits.b20 = 1;
        obj->unk_0xd4 = 0;
        obj->unk_0x8c = D_0047B040;
        break;
    case 3:
        obj->bits.b2 = 0;
        obj->bits.b3 = 0;
        obj->bits.b18 = 0;
        obj->bits.b17 = 1;
        obj->unk_0xd4 = 0;
        obj->unk_0x8c = D_0047A3B0;
        break;
    }

    model = obj->model;
    info = model->info;
    if (info->unk_0x1c < 0)
        obj->bits.b28 = 1;
    else
        obj->unk_0xc8 = info->unk_0x1c;
    if (model->info->unk_0x11)
        obj->unk_0x78 = model->info->unk_0x14;
    else
        obj->unk_0x78 = 1;

    obj->unk_0xc4 = desc->unk_0x48;
    if (desc->unk_0x48 == 0.0f && desc->model->unk_0x6)
        obj->unk_0xc4 = desc->model->unk_0x8;
    if (!desc->model->unk_0x5)
        obj->bits.b9 = 1;

    switch (model->kind) {
    case 1: {
        Effect_00421700 e;
        char *r;

        e.a = D_00692350;
        e.b = D_00692350;
        e.c = D_00692350;
        e.shape = model->shape;
        e.unk_0x34 = model->unk_0x18;
        r = func_0044D0F0(0xf, &e, 0xff);
        if (r != NULL) {
            r[0x83] = 0;
            func_0044A790(obj->unk_0x88, r);
        }
        break;
    }
    case 0:
        func_00449CD0(obj, model->unk_0x18, 0xff);
        if (obj->model->shape->bounds.unk_0xc > obj->radius)
            obj->radius = obj->model->shape->bounds.unk_0xc;
        break;
    }

    obj->unk_0x7c = 0;
    if (!(obj->flags & 0x20002))
        func_00449DE0(obj, 2);
    if (obj->bits.b1)
        obj->bits.b2 = 0;
    return 1;
}
