/* 1 function from 0x00424FA0 to 0x00426600, found by Ghidra. */
#include "common.h"
struct Vec4_00424FA0 {
    float x, y, z, w;
};

struct Mtx_00424FA0 {
    Vec4_00424FA0 r[4];
};

struct Range_00424FA0 {
    float lo, hi;
};

struct Emit_00424FA0 {
    int count_lo, count_hi;
    Range_00424FA0 speed;
    Range_00424FA0 unk_0x10;
    Range_00424FA0 unk_0x18;
    char unk_0x20;
    char unk_0x21[3];
    float unk_0x24;
};

struct Place_00424FA0 {
    char unk_0x0[0x18];
    char reset;
    char hasOffset;
    char unk_0x1a[2];
    Range_00424FA0 *offset;
};

struct Cmd_00424FA0 {
    int op;
    int a;
    int b;
};

struct Script_00424FA0 {
    unsigned int count;
    Cmd_00424FA0 *cmds;
};

struct Point_00424FA0 {
    Vec4_00424FA0 pos;
    int unk_0x10;
    Range_00424FA0 unk_0x14;
    int unk_0x1c;
    int unk_0x20;
    char unk_0x24[0xc];
};

struct Burst_00424FA0 {
    int count_lo, count_hi;
    unsigned int numPoints;
    Point_00424FA0 *points;
};

struct Obj_00424FA0 {
    Vec4_00424FA0 unk_0x0;
    Vec4_00424FA0 mtx[3];
    Vec4_00424FA0 pos;
    Vec4_00424FA0 quat;
    char unk_0x60[0x14];
    unsigned int flags;
    char unk_0x78[8];
    short unk_0x80;
    char unk_0x82[0x12];
    char *owner;
    char unk_0x98[0xc];
    Obj_00424FA0 *next;
    char unk_0xa8[0x18];
    Vec4_00424FA0 unk_0xc0;
    Script_00424FA0 *script;
    unsigned int pc;
    unsigned int loopStart;
    unsigned int loopCount;
    unsigned int wait;
    unsigned int repeat;
    int repStart;
    int repLen;
    char repState;
    char active;
    char unk_0xf2[6];
    float unk_0xf8;
};

extern float D_00477000;
extern float D_0047700C;
extern float D_0069236C;
extern float D_00477260;
extern float D_004772D0;
extern float D_004771A0;
extern float D_004770AC;
extern Vec4_00424FA0 D_00692350;
extern Vec4_00424FA0 D_006922E0[4];
extern Obj_00424FA0 *D_0053A9D0;

float func_004534B0(Obj_00424FA0 *);
int func_0043BDF0(char *);
int func_00426600(Obj_00424FA0 *, int);
extern "C" int func_0042AFA0(void);
extern "C" int func_00454AF0(int, int);
float func_00454AC0(float, float);
void func_00453FB0(Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00424040(Emit_00424FA0 *, Obj_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00424860(Emit_00424FA0 *, Obj_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_0043BE70(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *, char *, float, int);
char *func_0044D0B0(int, void *);
char *func_0044D0F0(int, void *, int);
void func_0044A790(char *, char *);
void func_004536E0(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00453300(Vec4_00424FA0 *, Vec4_00424FA0 *, Vec4_00424FA0 *);
void func_00423550(char *, Vec4_00424FA0 *, Obj_00424FA0 *);
int func_0042A680(int, int);
void func_00428F20(char *, Vec4_00424FA0 *);
float func_004535B0(Vec4_00424FA0 *, Vec4_00424FA0 *);
float func_004532E0(float);
void func_00428CE0(char *, Vec4_00424FA0 *, Obj_00424FA0 *, float);
void func_00439230(int, Vec4_00424FA0 *, int);
int func_00409E60(int);
void func_00409E90(int, int, int);
int func_00409500(int);
void func_004093E0(int, int, void *);
void func_00409DB0(int);
void func_00443740(int, Vec4_00424FA0 *);
float func_004534E0(Vec4_00424FA0 *);
void func_00454A30(Vec4_00424FA0 *);
extern "C" void func_00448330(Obj_00424FA0 *);

char func_00424FA0(Obj_00424FA0 *obj)
{
    float scale;
    unsigned int ticks;

    scale = 1.0f;
    if (obj->unk_0xf8 != D_00477000) {
        scale = func_004534B0(obj) * obj->unk_0xf8 + D_0047700C;
        ticks = (int)(D_0069236C * scale);
    } else {
        ticks = (int)D_0069236C;
    }
    if (obj->script == NULL)
        return 0;
    obj->active = 1;

    for (;;) {
        Cmd_00424FA0 *cmd;

        if (obj->wait != 0) {
            if (ticks <= obj->wait) {
                obj->wait -= ticks;
                return 1;
            }
            ticks -= obj->wait;
            obj->wait = 0;
        }
        if (obj->pc >= obj->script->count) {
            func_00448330(obj);
            return 1;
        }
        cmd = &obj->script->cmds[obj->pc];
        switch (cmd->op) {
        case 0:
        case 0x1e:
            break;
        case 1: {
            char *p = (char *)cmd->a;
            if (p != NULL && func_0043BDF0(p)) {
                Vec4_00424FA0 pos;
                Vec4_00424FA0 out;
                Vec4_00424FA0 quat;
                Vec4_00424FA0 vel;
                Emit_00424FA0 *em;
                unsigned int n;
                unsigned int i;

                pos.x = 0.0f;
                pos.y = 0.0f;
                pos.z = 0.0f;
                pos.w = 0.0f;
                quat.x = 0.0f;
                quat.y = 0.0f;
                quat.z = 0.0f;
                quat.w = 1.0f;
                em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                n = func_00454AF0(em->count_lo, em->count_hi);
                if (func_00426600(obj, *(int *)(p + 0x10)) || func_0042AFA0() == 1) {
                    func_00453FB0(&obj->quat, obj->mtx);
                    if (n == 0)
                        n = 1;
                    for (i = 0; i < n; i++) {
                        if (*p == 0)
                            func_00424040(em, obj, &pos, &out, &quat, &vel);
                        else
                            func_00424860(em, obj, &pos, &out, &quat, &vel);
                        pos.x *= D_00477260;
                        pos.y *= D_00477260;
                        pos.z *= D_00477260;
                        vel.x *= D_00477260;
                        vel.y *= D_00477260;
                        vel.z *= D_00477260;
                        vel.y = func_00454AC0(em->unk_0x18.lo, em->unk_0x18.hi) * D_004772D0 + vel.y;
                        func_0043BE70(&out, &pos, &vel, &quat, p, scale, 0);
                    }
                }
            }
            break;
        }
        case 2: {
            int src = cmd->a;
            if (src != 0) {
                struct {
                    Vec4_00424FA0 a;
                    Vec4_00424FA0 b;
                    float f;
                    Vec4_00424FA0 c;
                    int src;
                    char *owner;
                } s;
                Vec4_00424FA0 tmp;
                Emit_00424FA0 *em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                unsigned int n = func_00454AF0(em->count_lo, em->count_hi);
                unsigned int i;

                s.src = src;
                s.owner = obj->owner;
                func_00453FB0(&obj->quat, obj->mtx);
                if (n == 0)
                    n = 1;
                for (i = 0; i < n; i++) {
                    func_00424040(em, obj, &s.b, &s.a, &s.c, &tmp);
                    s.f = func_00454AC0(em->unk_0x18.lo, em->unk_0x18.hi);
                    func_0044D0B0(0, &s);
                }
            }
            break;
        }
        case 3: {
            int src = cmd->a;
            if (src != 0) {
                struct {
                    Vec4_00424FA0 a;
                    Vec4_00424FA0 b;
                    Vec4_00424FA0 c;
                    Vec4_00424FA0 d;
                    int src;
                    char *owner;
                    int unk_0x48;
                    int unk_0x4c;
                } s;
                Vec4_00424FA0 tmp;
                Emit_00424FA0 *em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                unsigned int n = func_00454AF0(em->count_lo, em->count_hi);
                unsigned int i;

                func_00453FB0(&obj->quat, obj->mtx);
                s.owner = obj->owner;
                s.d = D_00692350;
                s.unk_0x48 = 0;
                s.unk_0x4c = 0;
                s.src = src;
                if (n == 0)
                    n = 1;
                for (i = 0; i < n; i++) {
                    func_00424040(em, obj, &s.c, &s.a, &s.b, &tmp);
                    func_0044D0B0(1, &s);
                }
            }
            break;
        }
        case 4: {
            int src = cmd->a;
            if (src != 0) {
                struct {
                    Vec4_00424FA0 a;
                    Vec4_00424FA0 b;
                    Vec4_00424FA0 c;
                    int src;
                    char *owner;
                    int unk_0x38;
                } s;
                Vec4_00424FA0 tmp;
                Emit_00424FA0 *em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                unsigned int n = func_00454AF0(em->count_lo, em->count_hi);
                unsigned int i;

                func_00453FB0(&obj->quat, obj->mtx);
                if (n == 0)
                    n = 1;
                for (i = 0; i < n; i++) {
                    s.src = src;
                    s.unk_0x38 = 0;
                    func_00424040(em, obj, &s.c, &s.a, &s.b, &tmp);
                    s.owner = obj->owner;
                    func_0044D0B0(2, &s);
                }
            }
            break;
        }
        case 5: {
            char *p = (char *)cmd->a;
            if (p != NULL) {
                Place_00424FA0 *pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                Vec4_00424FA0 m[4];
                Vec4_00424FA0 off;
                Vec4_00424FA0 pos;
                Vec4_00424FA0 tmp;

                off.x = 0.0f;
                off.y = 0.0f;
                off.z = 0.0f;
                off.w = 0.0f;
                if (pl->reset == 1) {
                    m[0] = D_006922E0[0];
                    m[1] = D_006922E0[1];
                    m[2] = D_006922E0[2];
                    m[3] = D_006922E0[3];
                }
                func_00453FB0(&obj->quat, m);
                pos = obj->pos;
                if (pl->hasOffset) {
                    Range_00424FA0 *r = pl->offset;
                    off.x = func_00454AC0(r[0].lo, r[0].hi);
                    off.y = func_00454AC0(r[1].lo, r[1].hi);
                    off.z = func_00454AC0(r[2].lo, r[2].hi);
                }
                func_004536E0(m, &off, &tmp);
                func_00453300(&pos, &tmp, &pos);
                if (*p)
                    func_00423550(p, &pos, obj);
                if (func_0042A680(0x198, 0) == 0 && (p[2] || p[3] || p[4]))
                    func_00428F20(p, &pos);
                if (p[1]) {
                    Range_00424FA0 *r = *(Range_00424FA0 **)(p + 0x30);
                    float nearDist = r->lo;
                    float farDist = r->hi;
                    float nearSq = nearDist * nearDist;
                    int skip = 0;
                    float farSq = farDist * farDist;
                    Obj_00424FA0 *e;

                    for (e = D_0053A9D0; e != NULL; e = e->next) {
                        if (e->owner == obj->owner) {
                            if (p[5] == 0)
                                skip = 1;
                        } else if (p[5] == 2) {
                            skip = 1;
                        }
                        if (!skip && !(e->flags & 0x200000) && e->unk_0x80 != 0) {
                            float d = func_004535B0(&pos, &e->pos);
                            if (d < farSq) {
                                float f = 1.0f;
                                if (d > nearSq)
                                    f = (farDist - func_004532E0(d)) / (farDist - nearDist);
                                func_00428CE0(p, &pos, e, f);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 6: {
            char *src = (char *)cmd->a;
            if (src != NULL) {
                struct {
                    Vec4_00424FA0 pos;
                    Vec4_00424FA0 b;
                    Vec4_00424FA0 c;
                    Vec4_00424FA0 quat;
                    char *src;
                    int unk_0x44;
                    int unk_0x48;
                    int unk_0x4c;
                    int unk_0x50;
                    int unk_0x54;
                    int unk_0x58;
                    int unk_0x5c;
                } s;
                Place_00424FA0 *pl;
                Vec4_00424FA0 m[4];
                Vec4_00424FA0 off;
                Vec4_00424FA0 pos;
                Vec4_00424FA0 tmp;

                off.x = 0.0f;
                off.y = 0.0f;
                off.z = 0.0f;
                off.w = 0.0f;
                pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                if (pl->reset == 1) {
                    m[0] = D_006922E0[0];
                    m[1] = D_006922E0[1];
                    m[2] = D_006922E0[2];
                    m[3] = D_006922E0[3];
                    obj->quat.x = 0.0f;
                    obj->quat.y = 0.0f;
                    obj->quat.z = 0.0f;
                    obj->quat.w = 1.0f;
                } else {
                    func_00453FB0(&obj->quat, m);
                }
                pos = obj->pos;
                if (pl->hasOffset) {
                    Range_00424FA0 *r = pl->offset;
                    off.x = func_00454AC0(r[0].lo, r[0].hi);
                    off.y = func_00454AC0(r[1].lo, r[1].hi);
                    off.z = func_00454AC0(r[2].lo, r[2].hi);
                }
                func_004536E0(m, &off, &tmp);
                func_00453300(&pos, &tmp, &pos);
                s.pos = pos;
                s.quat = obj->quat;
                s.c = D_00692350;
                s.b = D_00692350;
                s.unk_0x4c = 0;
                s.unk_0x50 = 0;
                s.unk_0x58 = 0;
                s.unk_0x5c = 0;
                s.src = src;
                if (src[6])
                    s.unk_0x48 = *(int *)(src + 8);
                else
                    s.unk_0x48 = 0;
                func_0044D0B0(3, &s);
            }
            break;
        }
        case 7: {
            int src = cmd->a;
            if (src != 0) {
                struct {
                    Vec4_00424FA0 a;
                    Vec4_00424FA0 b;
                    Vec4_00424FA0 c;
                    Vec4_00424FA0 d;
                    int src;
                    int unk_0x44;
                    int unk_0x48;
                    int unk_0x4c;
                    int unk_0x50;
                    int unk_0x54;
                    int unk_0x58;
                    int unk_0x5c;
                } s;
                Vec4_00424FA0 tmp;
                Emit_00424FA0 *em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                unsigned int n = func_00454AF0(em->count_lo, em->count_hi);
                unsigned int i;

                func_00453FB0(&obj->quat, obj->mtx);
                s.c = obj->unk_0xc0;
                s.unk_0x4c = 0;
                s.unk_0x50 = 2;
                s.unk_0x5c = 0;
                if (n == 0)
                    n = 1;
                for (i = 0; i < n; i++) {
                    s.src = src;
                    s.unk_0x48 = 0;
                    func_00424040(em, obj, &s.b, &s.a, &s.d, &tmp);
                    func_0044D0B0(10, &s);
                }
            }
            break;
        }
        case 8: {
            int src = cmd->a;
            if (src != 0) {
                Place_00424FA0 *pl;
                Vec4_00424FA0 m[4];
                Vec4_00424FA0 off;
                Vec4_00424FA0 pos;
                Vec4_00424FA0 tmp;

                off.x = 0.0f;
                off.y = 0.0f;
                off.z = 0.0f;
                off.w = 0.0f;
                pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                if (pl->reset == 1) {
                    m[0] = D_006922E0[0];
                    m[1] = D_006922E0[1];
                    m[2] = D_006922E0[2];
                    m[3] = D_006922E0[3];
                }
                func_00453FB0(&obj->quat, m);
                pos = obj->pos;
                if (pl->hasOffset) {
                    Range_00424FA0 *r = pl->offset;
                    off.x = func_00454AC0(r[0].lo, r[0].hi);
                    off.y = func_00454AC0(r[1].lo, r[1].hi);
                    off.z = func_00454AC0(r[2].lo, r[2].hi);
                }
                func_004536E0(m, &off, &tmp);
                func_00453300(&pos, &tmp, &pos);
                func_00439230(src, &pos, 0);
            }
            break;
        }
        case 10: {
            char *p = (char *)cmd->a;
            if (p != NULL) {
                if (*p == 1) {
                    float f = func_00454AC0(*(float *)(p + 0xc), *(float *)(p + 0x10));
                    int h = func_00409E60(*(int *)(p + 0x14));
                    func_00409E90(h, 0, (int)f);
                    func_00409E90(h, 1, (int)f);
                } else {
                    Place_00424FA0 *pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                    int h = func_00409500(0);
                    int id;
                    float f;
                    Vec4_00424FA0 vel;
                    Vec4_00424FA0 m[4];
                    Vec4_00424FA0 off;
                    Vec4_00424FA0 pos;
                    Vec4_00424FA0 tmp;

                    id = *(int *)(p + 0x14);
                    f = func_00454AC0(*(float *)(p + 0xc), *(float *)(p + 0x10));
                    vel = obj->unk_0x0;
                    off.x = 0.0f;
                    off.y = 0.0f;
                    off.z = 0.0f;
                    off.w = 0.0f;
                    if (pl->reset == 1) {
                        m[0] = D_006922E0[0];
                        m[1] = D_006922E0[1];
                        m[2] = D_006922E0[2];
                        m[3] = D_006922E0[3];
                        vel.z = 0.0f;
                        vel.y = 0.0f;
                        vel.x = 0.0f;
                    }
                    func_00453FB0(&obj->quat, m);
                    pos = obj->pos;
                    if (pl->hasOffset) {
                        Range_00424FA0 *r = pl->offset;
                        off.x = func_00454AC0(r[0].lo, r[0].hi);
                        off.y = func_00454AC0(r[1].lo, r[1].hi);
                        off.z = func_00454AC0(r[2].lo, r[2].hi);
                    }
                    func_004536E0(m, &off, &tmp);
                    func_00453300(&pos, &tmp, &pos);
                    func_004093E0(h, 8, &id);
                    func_004093E0(h, 5, &pos);
                    func_004093E0(h, 6, &vel);
                    func_004093E0(h, 0, p + 8);
                    func_004093E0(h, 1, &f);
                    if (*p == 0) {
                        func_004093E0(h, 2, *(void **)(p + 0x18));
                        func_004093E0(h, 3, *(char **)(p + 0x18) + 4);
                    }
                    func_00409DB0(h);
                }
            }
            break;
        }
        case 0xb:
            obj->loopStart = obj->pc;
            obj->loopCount = cmd->a;
            break;
        case 0xc:
            if (obj->loopCount != 0) {
                obj->loopCount--;
                obj->pc = obj->loopStart;
            }
            break;
        case 0xd: {
            unsigned int i = obj->pc + 1;
            obj->repStart = i;
            obj->repeat = cmd->a;
            obj->repLen = 0;
            for (; i < obj->script->count; i++) {
                if (obj->script->cmds[i].op == 0xe)
                    break;
                obj->repLen++;
            }
            obj->repState = 1;
            break;
        }
        case 0xe:
            if (obj->repeat > 1) {
                obj->repeat--;
                obj->repState = 1;
            }
            break;
        case 0xf:
            obj->wait = cmd->a;
            break;
        case 0x19: {
            int src = cmd->a;
            if (src != 0) {
                struct {
                    Vec4_00424FA0 a;
                    Vec4_00424FA0 pos;
                    int unk_0x20;
                    int unk_0x24;
                    int unk_0x28;
                    int unk_0x2c;
                    int src;
                    int unk_0x34;
                } s;
                Place_00424FA0 *pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                Vec4_00424FA0 pos;

                pos = obj->pos;
                if (pl->hasOffset) {
                    Range_00424FA0 *r = pl->offset;
                    pos.x += func_00454AC0(r[0].lo, r[0].hi);
                    pos.y += func_00454AC0(r[1].lo, r[1].hi);
                    pos.z += func_00454AC0(r[2].lo, r[2].hi);
                }
                s.pos = pos;
                s.unk_0x34 = 0;
                s.a.w = 1.0f;
                s.a.x = 0.0f;
                s.a.y = 0.0f;
                s.a.z = 0.0f;
                s.unk_0x20 = 0;
                s.unk_0x24 = 0;
                s.unk_0x28 = 0;
                s.src = src;
                func_0044D0B0(4, &s);
            }
            break;
        }
        case 0x1a: {
            int src = cmd->a;
            if (src != 0 && (obj->owner == NULL || (obj->owner[0x6c] & 0x40) || *(char *)(src + 4))) {
                Place_00424FA0 *pl = (Place_00424FA0 *)obj->script->cmds[obj->pc].b;
                Vec4_00424FA0 m[4];
                Vec4_00424FA0 off;
                Vec4_00424FA0 pos;
                Vec4_00424FA0 tmp;

                off.x = 0.0f;
                off.y = 0.0f;
                off.z = 0.0f;
                off.w = 0.0f;
                if (pl->reset == 1) {
                    m[0] = D_006922E0[0];
                    m[1] = D_006922E0[1];
                    m[2] = D_006922E0[2];
                    m[3] = D_006922E0[3];
                }
                func_00453FB0(&obj->quat, m);
                pos = obj->pos;
                if (pl->hasOffset) {
                    Range_00424FA0 *r = pl->offset;
                    off.x = func_00454AC0(r[0].lo, r[0].hi);
                    off.y = func_00454AC0(r[1].lo, r[1].hi);
                    off.z = func_00454AC0(r[2].lo, r[2].hi);
                }
                func_004536E0(m, &off, &tmp);
                func_00453300(&pos, &tmp, &pos);
                func_00443740(src, &pos);
            }
            break;
        }
        case 0x1d: {
            Burst_00424FA0 *b = (Burst_00424FA0 *)cmd->a;
            if (b != NULL) {
                struct {
                    Vec4_00424FA0 pos;
                    Vec4_00424FA0 quat;
                    Vec4_00424FA0 r;
                    Vec4_00424FA0 vel;
                    float unk_0x40;
                    int unk_0x44;
                    int unk_0x48;
                    int unk_0x4c;
                    unsigned int unk_0x50;
                } s;
                Emit_00424FA0 *em = (Emit_00424FA0 *)obj->script->cmds[obj->pc].b;
                int n = func_00454AF0(em->count_lo, em->count_hi);
                Vec4_00424FA0 off;
                Vec4_00424FA0 tmp;
                Vec4_00424FA0 rnd;

                off.x = 0.0f;
                off.y = 0.0f;
                off.z = 0.0f;
                off.w = 0.0f;
                func_00453FB0(&obj->quat, obj->mtx);
                if (n == 0)
                    n = 1;
                do {
                    unsigned int i;

                    func_00424040(em, obj, &s.vel, &off, &s.quat, &tmp);
                    for (i = 0; i < b->numPoints; i++) {
                        Point_00424FA0 *pt = &b->points[i];
                        float len = func_004534E0(&pt->pos);
                        float sp;

                        if (len > D_004771A0) {
                            func_004536E0(obj->mtx, &pt->pos, &s.vel);
                        } else {
                            len = 1.0f;
                            s.vel.x = 0.0f;
                            s.vel.y = 1.0f;
                            s.vel.z = 0.0f;
                        }
                        sp = func_00454AC0(em->speed.lo, em->speed.hi) / len;
                        s.vel.x *= sp;
                        s.vel.y *= sp;
                        s.vel.z *= sp;
                        func_00454A30(&rnd);
                        s.unk_0x44 = pt->unk_0x1c;
                        if (s.unk_0x44 != 0) {
                            char *e;

                            s.unk_0x40 = func_00454AC0(em->unk_0x18.lo, em->unk_0x18.hi);
                            func_004536E0(obj->mtx, &pt->pos, &s.pos);
                            s.pos.x += off.x;
                            s.quat = obj->quat;
                            s.pos.y += off.y;
                            s.pos.z += off.z;
                            s.vel.x = rnd.x * em->speed.lo + s.vel.x;
                            s.vel.y = rnd.y * em->speed.lo + s.vel.y;
                            s.vel.z = rnd.z * em->speed.lo + s.vel.z;
                            if (em->unk_0x20) {
                                s.vel.x = em->unk_0x24 * obj->unk_0x0.x + s.vel.x;
                                s.vel.y = obj->unk_0x0.y * em->unk_0x24 + s.vel.y;
                                s.vel.z = obj->unk_0x0.z * em->unk_0x24 + s.vel.z;
                            }
                            s.unk_0x48 = func_00454AF0(b->count_lo, b->count_hi);
                            s.unk_0x4c = pt->unk_0x10;
                            s.unk_0x50 = (int)D_0069236C <= s.unk_0x48;
                            func_00454A30(&s.r);
                            s.r.w = func_00454AC0(pt->unk_0x14.lo, pt->unk_0x14.hi) * D_004770AC;
                            e = func_0044D0B0(6, &s);
                            if (e != NULL && pt->unk_0x20 != 0) {
                                struct {
                                    Vec4_00424FA0 a;
                                    Vec4_00424FA0 b;
                                    Vec4_00424FA0 c;
                                    int src;
                                    char *owner;
                                    int unk_0x38;
                                } s2;
                                char *f;

                                s2.a = D_00692350;
                                s2.unk_0x38 = 0;
                                s2.b.w = 1.0f;
                                s2.b.x = 0.0f;
                                s2.b.y = 0.0f;
                                s2.b.z = 0.0f;
                                s2.src = pt->unk_0x20;
                                s2.owner = obj->owner;
                                s2.c = D_00692350;
                                f = func_0044D0F0(2, &s2, 0xff);
                                if (f != NULL) {
                                    f[0x83] = (char)0xff;
                                    func_0044A790(e + 0x88, f);
                                }
                            }
                        }
                    }
                } while (--n != 0);
            }
            break;
        }
        default:
            return 0;
        }

        switch (obj->repState) {
        case 0:
            obj->pc++;
            break;
        case 1:
            obj->pc = func_00454AF0(obj->repStart, obj->repLen);
            obj->repState = 2;
            break;
        case 2:
            obj->pc = obj->repLen + obj->repStart;
            obj->repState = 0;
            break;
        }
    }
}
