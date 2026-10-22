/* 15 functions from 0x0041B410 to 0x0041C360, found by Ghidra. */
#include "common.h"

struct Vec4_0041B410 {
    float x, y, z, w;
};

struct Mtx_0041B410 {
    Vec4_0041B410 row[4];
};

struct Obj_0041B410 {
    char unk_0x00[0xa0];
    Vec4_0041B410 *unk_0xa0;
    Mtx_0041B410 *unk_0xa4;
    Vec4_0041B410 *unk_0xa8;
};

struct Slot_006614C0 {
    int unk_0x00;
    char unk_0x04[0x3dc];
};

struct Entry_006611C0 {
    char unk_0x00[0x3e0];
};

extern Slot_006614C0 D_006614C0[];
extern Slot_006614C0 D_006633C0[];
extern Entry_006611C0 D_006611C0[];
extern char D_0047A59C[];

extern "C" void func_004535E0(Mtx_0041B410 *m, int b, Vec4_0041B410 *out);
extern "C" void func_0041B1B0(int a, Mtx_0041B410 *m, Obj_0041B410 *obj);
extern "C" void func_00452F70(const char *fmt, ...);

struct OBox_00663180 {
    char unk_0x00[0x9d];
    char unk_0x9d;
    char unk_0x9e[0x52];
};

extern OBox_00663180 D_00663180[];
extern char D_0066321D[];
extern char D_0068121D[];
extern char D_0047A5B8[];
extern char D_0047A5C8[];

struct Box_0041B680 {
    Vec4_0041B410 min;
    Vec4_0041B410 max;
};

struct Hit_0041B680 {
    Vec4_0041B410 pos;
    Vec4_0041B410 normal;
    char unk_0x20[0x1c];
    char side;
};

extern float D_00477000;
extern float D_0047700C;
extern float D_00477290;
extern Vec4_0041B410 D_00692350;

extern "C" float func_004534E0(Vec4_0041B410 *v);
extern "C" float func_004534B0(Vec4_0041B410 *v);
extern "C" float func_004532E0(float f);

struct Timer_006630E0 {
    int unk_0x00;
    int unk_0x04;
    unsigned unk_0x08;
    char unk_0x0c[0x24];
};

extern Timer_006630E0 D_006630E0[];
extern Timer_006630E0 D_006631A0[];
extern unsigned D_006630E8[];
extern unsigned D_006631A8[];
extern int D_00692370;

extern "C" void func_0041B410(int a, Mtx_0041B410 *m, int b, Obj_0041B410 *obj)
{
    Mtx_0041B410 tmp;

    tmp = *m;
    func_004535E0(m, b, &tmp.row[3]);
    func_0041B1B0(a, &tmp, obj);
    obj->unk_0xa0 = &m->row[2];
    obj->unk_0xa4 = m;
    obj->unk_0xa8 = &m->row[1];
}

extern "C" float func_0041BC60(int a, int b, int c, float d)
{
    return d;
}

extern "C" float func_0041B680(Vec4_0041B410 *pos, Vec4_0041B410 *dir, Box_0041B680 *box, float t, Hit_0041B680 *hit)
{
    float frac;
    Vec4_0041B410 s;
    Vec4_0041B410 e;
    char side;
    float f;
    float len;

    side = 0;
    frac = 0.0f;
    s = *pos;
    e.x = t * dir->x + pos->x;
    e.y = t * dir->y + pos->y;
    e.z = t * dir->z + pos->z;

    if (s.x > box->max.x && e.x < box->max.x) {
        f = (s.x - box->max.x) / (s.x - e.x);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 1;
        frac = f;
    } else if (s.x < box->min.x && e.x > box->min.x) {
        f = (s.x - box->min.x) / (s.x - e.x);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 2;
        frac = f;
    }

    if (s.y > box->max.y && e.y < box->max.y) {
        f = (s.y - box->max.y) / (s.y - e.y);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 3;
        frac += f;
    } else if (s.y < box->min.y && e.y > box->min.y) {
        f = (s.y - box->min.y) / (s.y - e.y);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 4;
        frac += f;
    }

    if (s.z > box->max.z && e.z < box->max.z) {
        f = (s.z - box->max.z) / (s.z - e.z);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 5;
        frac += f;
    } else if (s.z < box->min.z && e.z > box->min.z) {
        f = (s.z - box->min.z) / (s.z - e.z);
        s.x += (e.x - s.x) * f;
        s.y += (e.y - s.y) * f;
        s.z += (e.z - s.z) * f;
        side = 6;
        frac += f;
    }

    if (frac <= D_0047700C
        && (s.x <= box->max.x || e.x <= box->max.x)
        && (s.y <= box->max.y || e.y <= box->max.y)
        && (s.z <= box->max.z || e.z <= box->max.z)
        && (box->min.x <= s.x || box->min.x <= e.x)
        && (box->min.y <= s.y || box->min.y <= e.y)
        && (box->min.z <= s.z || box->min.z <= e.z)) {
        if (s.x < box->max.x && s.x > box->min.x &&
            s.y < box->max.y && s.y > box->min.y &&
            s.z < box->max.z && s.z > box->min.z) {
            func_004534E0(&s);
            func_004534E0(&e);
            len = func_004534E0(&s);
            if (func_004534E0(&e) - D_00477290 <= len) {
                if (hit) {
                    len = func_004532E0(func_004534B0(dir));
                    if (len < D_00477290)
                        return t;
                    hit->pos = s;
                    hit->normal.x = -(dir->x / len);
                    hit->normal.y = -(dir->y / len);
                    hit->normal.z = -(dir->z / len);
                }
                return D_00477000;
            }
        }
        if (side) {
            if (hit) {
                hit->pos = s;
                hit->normal = D_00692350;
                hit->side = side;
                switch (side) {
                case 1:
                    hit->normal.x = 1.0f;
                    break;
                case 2:
                    hit->normal.x = -1.0f;
                    break;
                case 3:
                    hit->normal.y = 1.0f;
                    break;
                case 4:
                    hit->normal.y = -1.0f;
                    break;
                case 5:
                    hit->normal.z = 1.0f;
                    break;
                case 6:
                    hit->normal.z = -1.0f;
                    break;
                }
            }
            return frac * t;
        }
    }
    return t;
}

extern "C" void func_0041C180(void)
{
    Timer_006630E0 *p = D_006630E0;
    do {
        p->unk_0x04 = 0;
        p->unk_0x00 = 0;
        p->unk_0x08 = 99999;
        p++;
    } while (p < D_006631A0);
}

extern "C" void func_0041C1A0(void)
{
    int dt = D_00692370;
    unsigned *p = D_006630E8;
    do {
        if (p[-2] != 0)
            *p += dt;
        if (*p > 1000) {
            p[-1] = 0;
            p[-2] = 0;
            *p = 99999;
        }
        p += sizeof(Timer_006630E0) / sizeof(unsigned);
    } while (p < D_006631A8);
}

extern "C" void func_0041B570(void)
{
    Slot_006614C0 *p = D_006614C0;
    do {
        p->unk_0x00 = 0;
        p++;
    } while (p < D_006633C0);
}

extern "C" Entry_006611C0 *func_0041B590(int value)
{
    int i = 0;
    Slot_006614C0 *p;

    for (p = D_006614C0; p < D_006633C0; p++, i++) {
        if (p->unk_0x00 == 0) {
            D_006614C0[i].unk_0x00 = value;
            return &D_006611C0[i];
        }
    }
    func_00452F70(D_0047A59C);
    return 0;
}

extern "C" void func_0041B5E0(Slot_006614C0 *p)
{
    if (p)
        *(int *)((char *)p + 0x300) = 0;
}

extern "C" void func_0041B600(void)
{
    char *p;

    func_00452F70(D_0047A5B8, D_00663180);
    p = D_0066321D;
    do {
        *p = 0;
        p += sizeof(OBox_00663180);
    } while (p < D_0068121D);
}

extern "C" OBox_00663180 *func_0041B630(void)
{
    int i = 0;
    char *p;

    for (p = D_0066321D; p < D_0068121D; p += sizeof(OBox_00663180), i++) {
        if (*p == 0) {
            D_0066321D[i * sizeof(OBox_00663180)] = 1;
            return &D_00663180[i];
        }
    }
    func_00452F70(D_0047A5C8);
    return 0;
}

extern "C" void func_0041B670(OBox_00663180 *p)
{
    if (p)
        p->unk_0x9d = 0;
}

