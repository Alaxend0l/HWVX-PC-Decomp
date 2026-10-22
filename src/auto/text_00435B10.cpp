/* 1 function from 0x00435B10 to 0x00436D70, found by Ghidra. */
#include "common.h"
#include <string.h>
struct Vec4_00435B10 {
    float x, y, z, w;
};

struct Mtx_00435B10 {
    Vec4_00435B10 r[4];
};

struct Col_00435B10 {
    u8 r, g, b, a;
};

struct Font_00435B10 {
    char unk_0x00[0x12];
    u8 unk_0x12;
    char unk_0x13;
    u16 w;
    u16 h;
};

struct TextFont_00435B10 {
    char unk_0x00[0xe];
    u8 unk_0xe;
    u8 unk_0xf;
    u8 unk_0x10;
    u8 unk_0x11;
    char unk_0x12[2];
    u16 w;
    u16 h;
    int unk_0x18;
};

struct PathPt_00435B10 {
    float x, y;
    char unk_0x08[8];
    Col_00435B10 col;
    char unk_0x14[0xc];
};

struct Path_00435B10 {
    unsigned int count;
    PathPt_00435B10 *pts;
    u8 mode;
};

struct Desc_00435B10 {
    char unk_0x00[0xc];
    s16 unk_0xc;
    char unk_0xe[2];
    int unk_0x10;
    void *unk_0x14;
    char unk_0x18[0x18];
    float ax;
    float ay;
};

struct Link_00435B10 {
    char unk_0x00[8];
    int unk_0x8;
    char unk_0xc[0x1c];
    int unk_0x28;
};

struct Spr_00435B10 {
    char unk_0x00[0x40];
    Vec4_00435B10 pos;
};

struct Model_00435B10;

struct ModelVt_00435B10 {
    char unk_0x00[0x10];
    void (*draw)(Model_00435B10 *);
};

struct Model_00435B10 {
    char unk_0x00[0x10];
    Mtx_00435B10 mtx;
    char unk_0x50[0x24];
    unsigned int flags;
    char unk_0x78[0x14];
    ModelVt_00435B10 *vt;
    char unk_0x90[0x398 - 0x90];
    float *unk_0x398;
};

struct Ent_00435B10 {
    char unk_0x00[0x24];
    Col_00435B10 color;
    char unk_0x28[4];
    u8 unk_0x2c;
    char unk_0x2d[3];
    Vec4_00435B10 scale;
    char unk_0x40[0x14];
    u8 unk_0x54;
    char unk_0x55[0xb];
    Vec4_00435B10 pos;
    char unk_0x70[0x14];
    u8 unk_0x84;
    char unk_0x85[0xb];
    Vec4_00435B10 rot;
    char unk_0xa0[0x14];
    u8 unk_0xb4;
    char unk_0xb5[0xb];
    Vec4_00435B10 unk_0xc0;
    char unk_0xd0[8];
    Vec4_00435B10 unk_0xd8;
    char unk_0xe8[0x30];
    u8 unk_0x118;
    char unk_0x119[0xb];
    u8 unk_0x124;
    u8 unk_0x125;
    char unk_0x126[0xa];
    u8 unk_0x130;
    char unk_0x131[7];
    int unk_0x138;
    char unk_0x13c[0x60];
    char *text;
    u16 maxLen;
    u16 len;
    char unk_0x1a4[4];
    u8 unk_0x1a8;
    u8 unk_0x1a9;
    char unk_0x1aa[0xe];
    char textBuf[0x80];
    u8 unk_0x238;
    char unk_0x239[2];
    u8 type;
    u8 unk_0x23c;
    u8 unk_0x23d;
    char unk_0x23e[0xe];
    Link_00435B10 *link;
    Font_00435B10 *font;
    Desc_00435B10 *desc;
    Ent_00435B10 *parent;
    Ent_00435B10 *rel;
    char unk_0x260[4];
    Spr_00435B10 *spr;
    int unk_0x268;
    char unk_0x26c[0x14];
    Model_00435B10 *model;
    char unk_0x284[0x74];
};

struct Sub_00435B10 {
    char unk_0x00[0x2c];
    int unk_0x2c;
};

struct Owner_00435B10 {
    unsigned int count;
    char unk_0x4[4];
    Sub_00435B10 *unk_0x8;
    char unk_0xc[0x69];
    u8 unk_0x75;
    char unk_0x76[7];
    u8 unk_0x7d;
    char unk_0x7e[2];
    Ent_00435B10 *ents;
};

struct Slot_00435B10 {
    char unk_0x00[0x134];
};

struct Emit1_00435B10 {
    Vec4_00435B10 a;
    Vec4_00435B10 b;
    Vec4_00435B10 c;
    Vec4_00435B10 d;
    Font_00435B10 *src;
    int owner;
    int unk_0x48;
    int unk_0x4c;
};

struct Emit2_00435B10 {
    Vec4_00435B10 a;
    Vec4_00435B10 b;
    Vec4_00435B10 c;
    Font_00435B10 *src;
    int owner;
    int unk_0x38;
};

extern char D_0048D5FC;
extern char D_0048D5FD;
extern float D_00477000;
extern float D_00477040;
extern float D_00477060;
extern float D_004770AC;
extern Vec4_00435B10 D_00692350;
extern Mtx_00435B10 D_006922E0;
extern ModelVt_00435B10 D_0047A2E8;
extern Slot_00435B10 D_005E7660[];

void func_00434D90(Vec4_00435B10 *, float, float);
void func_00434CB0(Vec4_00435B10 *);
extern "C" void func_00448330(Spr_00435B10 *);
void func_0042F090(Slot_00435B10 *, int);
void func_0045FE00(Vec4_00435B10 *);
void func_00453B20(Mtx_00435B10 *, float, float, float);
void func_004537C0(Mtx_00435B10 *, Mtx_00435B10 *, Mtx_00435B10 *);
void func_004540C0(Mtx_00435B10 *, void *);
void func_0040F6A0(Model_00435B10 *);
void func_00437620(Vec4_00435B10 *, Owner_00435B10 *);
void func_00437920(Ent_00435B10 *, Owner_00435B10 *);
void func_004358A0(Slot_00435B10 *);
void func_00437450(Ent_00435B10 *);
void func_00436D70(Ent_00435B10 *, Owner_00435B10 *);
void func_004351A0(Ent_00435B10 *);
void func_00434EA0(Ent_00435B10 *);
Spr_00435B10 *func_0044D0B0(int, void *);
void func_00453330(Vec4_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_004535E0(Mtx_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_0046AAF0(char *, char *, unsigned int);
void func_00464F90(int, int, int, int);
void func_00463900(char *, int, float *, float *, int);
void func_004632A0(char *, float, float, int, int, int);
void func_00463440(char *, int, float, float, int, int, int, int, float, float, int, Vec4_00435B10 *);
void func_00463760(char *, float, float, int, int, Vec4_00435B10 *, int);
void func_00453300(Vec4_00435B10 *, Vec4_00435B10 *, Vec4_00435B10 *);
void func_0045EBA0(Vec4_00435B10 *, Vec4_00435B10 *, Col_00435B10 *, Col_00435B10 *, int);
float func_004532D0(float, float);
float func_004532E0(float);
void func_00453240(float, float *, float *);

void func_00435B10(Owner_00435B10 *o, int idx)
{
    Ent_00435B10 *ent;
    Ent_00435B10 *cam;
    unsigned int i;
    char restore;
    Vec4_00435B10 savedPos;
    Vec4_00435B10 savedRot;
    Vec4_00435B10 savedScale;
    Vec4_00435B10 off;
    Mtx_00435B10 m;
    Mtx_00435B10 s;

    ent = &o->ents[idx];
    cam = NULL;
    if (ent->unk_0x238)
        return;
    if (o->unk_0x7d)
        return;
    if (D_0048D5FC) {
        Desc_00435B10 *desc = ent->desc;

        if (desc->unk_0xc == 0) {
            Font_00435B10 *font;

            if (ent->type == 5 && (font = ent->font)->unk_0x12) {
                Vec4_00435B10 v;
                float w;
                float h;
                float hw;
                float hh;

                v.x = 0.0f;
                v.y = 0.0f;
                v.z = 0.0f;
                v.w = 1.0f;
                w = font->w;
                h = font->h;
                hw = w * D_00477060;
                hh = h * D_00477060;
                v.x = ent->pos.x - hw - hw * desc->ax;
                v.y = ent->pos.y - hh - hh * desc->ay;
                func_00434D90(&v, w, h);
            }
            func_00434CB0(&ent->pos);
        }
    }
    if (ent->unk_0x125)
        return;
    if (!ent->unk_0x124) {
        switch (ent->type) {
        case 3:
            ent->unk_0x23c = 0;
            ent->spr = NULL;
            break;
        case 4:
            ent->unk_0x23c = 0;
            if (ent->spr != NULL) {
                func_00448330(ent->spr);
                ent->spr = NULL;
            }
            break;
        }
        ent->unk_0x84 = 1;
        ent->unk_0xb4 = 1;
        ent->unk_0x54 = 1;
        ent->unk_0x2c = 1;
        ent->unk_0x118 = 1;
        if (ent->type == 1)
            ent->unk_0x130 = 1;
        if (ent->type == 6)
            func_0042F090(&D_005E7660[ent->unk_0x268], 0);
        return;
    }

    restore = 0;
    if (ent->parent != NULL) {
        if (ent->link->unk_0x8 == 0)
            ent->pos = ent->parent->pos;
        if (ent->link->unk_0x28 == 0)
            ent->rot = ent->parent->rot;
    }
    if (ent->rel != NULL) {
        Ent_00435B10 *rel = ent->rel;

        savedPos = ent->pos;
        ent->pos.x = rel->pos.x + ent->pos.x;
        ent->pos.y = rel->pos.y + ent->pos.y;
        ent->pos.z = rel->pos.z + ent->pos.z;
        savedRot = ent->rot;
        ent->rot.x = rel->rot.x + ent->rot.x;
        restore = 1;
        ent->rot.y = rel->rot.y + ent->rot.y;
        savedScale = ent->scale;
        ent->rot.z = rel->rot.z + ent->rot.z;
        ent->scale.x = rel->scale.x + ent->scale.x;
        ent->scale.y = rel->scale.y + ent->scale.y;
        ent->scale.z = rel->scale.z + ent->scale.z;
    }

    if (ent->model != NULL) {
        for (i = 0; i < o->count; i++) {
            if (o->ents[i].unk_0x23d == 4) {
                cam = &o->ents[i];
                break;
            }
        }
        func_0045FE00(&off);
        if (cam != NULL) {
            off.x -= cam->pos.x;
            off.y -= cam->pos.y;
            off.z -= cam->pos.z;
            func_00453B20(&m, (cam->rot.y + ent->rot.y) * D_004770AC, (cam->rot.x + ent->rot.x) * D_004770AC,
                          (cam->rot.z + ent->rot.z) * D_004770AC);
        } else {
            func_00453B20(&m, D_004770AC * ent->rot.y, D_004770AC * ent->rot.x, D_004770AC * ent->rot.z);
        }
        if (ent->model->vt == &D_0047A2E8) {
            float *d = ent->model->unk_0x398;
            if (*(int *)&ent->rot.z == 0x43340000 || *(int *)&ent->rot.z == 0xc3340000) {
                off.x -= d[0];
                off.y -= d[1];
                off.z -= d[2];
            } else {
                off.x += d[0];
                off.y += d[1];
                off.z += d[2];
            }
        }
        if (ent->rel != NULL) {
            m.r[3].x = savedPos.x + ent->rel->desc->ax + off.x;
            m.r[3].y = savedPos.y + ent->rel->desc->ay + off.y;
            m.r[3].z = savedPos.z + off.z;
        } else {
            m.r[3].x = off.x + ent->pos.x;
            m.r[3].y = off.y + ent->pos.y;
            m.r[3].z = off.z + ent->pos.z;
        }
        s = D_006922E0;
        s.r[0].x = ent->scale.x;
        s.r[1].y = ent->scale.y;
        s.r[2].z = ent->scale.z;
        func_004537C0(&s, &m, &ent->model->mtx);
        func_004540C0(&ent->model->mtx, ent->model->unk_0x50);
        ent->model->flags |= 0x80;
        if (ent->model->vt == &D_0047A2E8)
            func_0040F6A0(ent->model);
        else
            ent->model->vt->draw(ent->model);
    }

    if (ent->unk_0x23d == 7) {
        if (o->unk_0x8 != NULL && o->unk_0x8->unk_0x2c != 0)
            func_00437620(&ent->pos, o);
    } else if (ent->unk_0x23d == 0x1e) {
        func_00437920(ent, o);
    } else if (ent->unk_0x23d != 4) {
        switch (ent->type) {
        case 6:
            if (ent->unk_0x268 != o->unk_0x75)
                func_004358A0(&D_005E7660[ent->unk_0x268]);
            break;
        case 0:
        case 1:
            func_00437450(ent);
            break;
        case 2:
            func_00436D70(ent, o);
            break;
        case 8:
            if (!D_0048D5FD)
                break;
        case 5: {
            unsigned int len = ent->len;
            TextFont_00435B10 *font;
            char buf[512];
            float w;
            float h;

            if (!ent->unk_0x1a9 && len < ent->maxLen) {
                if (ent->text != NULL)
                    func_0046AAF0(buf, ent->text, len);
                else
                    func_0046AAF0(buf, ent->textBuf, len);
                buf[len] = 0;
                if (len == 0)
                    break;
            } else if (ent->text != NULL) {
                strcpy(buf, ent->text);
            } else {
                strcpy(buf, ent->textBuf);
            }
            font = (TextFont_00435B10 *)ent->desc->unk_0x14;
            func_00464F90(ent->color.r, ent->color.g, ent->color.b, ent->color.a);
            func_00463900(buf, ent->unk_0x1a8, &w, &h, ent->unk_0x138);
            if (font->unk_0xf) {
                if (ent->unk_0x1a9) {
                    w = font->w * D_00477060;
                    h = font->h * D_00477060;
                    func_00463440(buf, ent->len, ent->pos.x - w - w * ent->desc->ax, ent->pos.y - h - h * ent->desc->ay,
                                  ent->unk_0x1a8, ent->unk_0x138, font->unk_0xe, font->unk_0x11, font->w, font->h,
                                  font->unk_0x18, &ent->scale);
                } else {
                    w = D_00477060 * ent->scale.x * w;
                    h = D_00477060 * ent->scale.y * h;
                    func_00463760(buf, ent->pos.x - w - w * ent->desc->ax, ent->pos.y - h - h * ent->desc->ay,
                                  ent->unk_0x1a8, ent->unk_0x138, &ent->scale, font->unk_0xe);
                }
            } else {
                if (ent->unk_0x1a9) {
                    w = font->w * D_00477060;
                    h = font->h * D_00477060;
                    func_00463440(buf, ent->len, ent->pos.x - w - w * ent->desc->ax, ent->pos.y - h - h * ent->desc->ay,
                                  ent->unk_0x1a8, ent->unk_0x138, font->unk_0xe, font->unk_0x11, font->w, font->h,
                                  font->unk_0x18, NULL);
                } else {
                    w = D_00477060 * w;
                    h = D_00477060 * h;
                    func_004632A0(buf, ent->pos.x - w - w * ent->desc->ax, ent->pos.y - h - h * ent->desc->ay,
                                  ent->unk_0x1a8, ent->unk_0x138, font->unk_0xe);
                }
            }
            break;
        }
        case 4:
            if (!ent->unk_0x23c) {
                Emit2_00435B10 e;

                e.src = ent->font;
                e.unk_0x38 = 0;
                e.a.z = 0.0f;
                e.a.y = 0.0f;
                e.a.x = 0.0f;
                e.c.z = 0.0f;
                e.c.y = 0.0f;
                e.c.x = 0.0f;
                e.b.z = 0.0f;
                e.b.y = 0.0f;
                e.b.x = 0.0f;
                e.b.w = 1.0f;
                e.owner = 0;
                ent->spr = func_0044D0B0(2, &e);
                ent->unk_0x23c = 1;
            }
            if (ent->spr != NULL) {
                Vec4_00435B10 a;
                Mtx_00435B10 m2;

                cam = NULL;
                for (i = 0; i < o->count; i++) {
                    if (o->ents[i].unk_0x23d == 4) {
                        cam = &o->ents[i];
                        break;
                    }
                }
                func_0045FE00(&a);
                if (cam != NULL) {
                    func_00453330(&a, &cam->pos, &a);
                    func_00453B20(&m2, (cam->rot.y + ent->rot.y) * D_004770AC,
                                  (cam->rot.x + ent->rot.x) * D_004770AC, (cam->rot.z + ent->rot.z) * D_004770AC);
                } else {
                    func_00453B20(&m2, D_004770AC * ent->rot.y, D_004770AC * ent->rot.x, D_004770AC * ent->rot.z);
                }
                m2.r[3].x = a.x;
                m2.r[3].y = a.y;
                m2.r[3].z = a.z;
                func_004535E0(&m2, &ent->pos, &a);
                ent->spr->pos = a;
            }
            break;
        case 3:
            if (!ent->unk_0x23c) {
                Emit1_00435B10 e;

                e.src = ent->font;
                e.d = D_00692350;
                e.a.z = 0.0f;
                e.a.y = 0.0f;
                e.a.x = 0.0f;
                e.c.z = 0.0f;
                e.c.y = 0.0f;
                e.c.x = 0.0f;
                e.b.z = 0.0f;
                e.b.y = 0.0f;
                e.b.x = 0.0f;
                e.b.w = 1.0f;
                e.owner = 0;
                e.unk_0x48 = 0;
                e.unk_0x4c = 0;
                ent->spr = func_0044D0B0(1, &e);
                ent->unk_0x23c = 1;
            }
            if (ent->spr != NULL)
                ent->spr->pos = ent->pos;
            break;
        case 9:
            if (D_0048D5FD)
                func_004351A0(ent);
            break;
        case 10:
            if (D_0048D5FD)
                func_00434EA0(ent);
            break;
        case 11: {
            Vec4_00435B10 a;
            Vec4_00435B10 b;
            Vec4_00435B10 v1;
            Vec4_00435B10 v2;

            v1.y = ent->unk_0xc0.y;
            v1.x = ent->unk_0xc0.x;
            v2.x = ent->unk_0xd8.x;
            v2.y = ent->unk_0xd8.y;
            b = ent->pos;
            v1.z = 0.0f;
            v1.w = 1.0f;
            v2.z = 0.0f;
            v2.w = 1.0f;
            func_00453300(&b, &ent->rot, &a);
            func_0045EBA0(&b, &a, &ent->color, &ent->color, 5);
            if (ent->desc->unk_0x10)
                b = a;
            func_00453300(&b, &ent->scale, &a);
            func_0045EBA0(&b, &a, &ent->color, &ent->color, 5);
            if (ent->desc->unk_0x10)
                b = a;
            func_00453300(&b, &v1, &a);
            func_0045EBA0(&b, &a, &ent->color, &ent->color, 5);
            if (ent->desc->unk_0x10)
                b = a;
            func_00453300(&b, &v2, &a);
            func_0045EBA0(&b, &a, &ent->color, &ent->color, 5);
            break;
        }
        case 12: {
            Path_00435B10 *path = (Path_00435B10 *)ent->desc->unk_0x14;
            Vec4_00435B10 a;
            Vec4_00435B10 b;
            Col_00435B10 c0;
            Col_00435B10 c1;

            a.z = 0.0f;
            a.w = 1.0f;
            b.x = 0.0f;
            b.y = 0.0f;
            b.z = 0.0f;
            b.w = 1.0f;
            if (path->count != 0) {
                c0.r = (path->pts[0].col.r + ent->color.r) / 2;
                c0.g = (path->pts[0].col.g + ent->color.g) / 2;
                c0.b = (path->pts[0].col.b + ent->color.b) / 2;
                c0.a = (path->pts[0].col.a + ent->color.a) / 2;
                a.x = path->pts[0].x * ent->scale.x;
                a.y = path->pts[0].y * ent->scale.y;
                func_00453300(&ent->pos, &a, &a);
                for (i = 1; i < path->count; i++) {
                    c1.r = (path->pts[i].col.r + ent->color.r) / 2;
                    c1.g = (path->pts[i].col.g + ent->color.g) / 2;
                    c1.b = (path->pts[i].col.b + ent->color.b) / 2;
                    c1.a = (path->pts[i].col.a + ent->color.a) / 2;
                    b.x = path->pts[i].x * ent->scale.x;
                    b.y = path->pts[i].y * ent->scale.y;
                    if (ent->rot.x != D_00477000) {
                        float ang;
                        float len;
                        float sn;
                        float cs;

                        ang = ent->rot.x;
                        ang = func_004532D0(b.x, b.y) * D_00477040 + ang;
                        len = func_004532E0(b.x * b.x + b.y * b.y);
                        func_00453240(ang, &sn, &cs);
                        b.x = sn * len;
                        b.y = cs * len;
                    }
                    func_00453300(&ent->pos, &b, &b);
                    func_0045EBA0(&a, &b, &c0, &c1, (u8)path->mode);
                    a = b;
                    c0 = c1;
                }
            }
            break;
        }
        }
    }

    if (restore) {
        ent->pos = savedPos;
        ent->rot = savedRot;
        ent->scale = savedScale;
    }
}
