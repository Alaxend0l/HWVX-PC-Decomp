/* 1 function from 0x00416A40 to 0x00418030, found by Ghidra. */
#include "common.h"

struct Vec4_00416A40 {
    float x;
    float y;
    float z;
    float w;
};

struct Mat4_00416A40 {
    Vec4_00416A40 row0;
    Vec4_00416A40 row1;
    Vec4_00416A40 row2;
    Vec4_00416A40 pos;
};

struct Surface_00416A40 {
    char unk_0x00;
    char unk_0x01;
    u16 unk_0x02;
    char unk_0x04[0x14 - 0x04];
    float unk_0x14;
    char unk_0x18[0x1c - 0x18];
    float unk_0x1c;
    float unk_0x20;
    char unk_0x24[0x2c - 0x24];
    u32 *unk_0x2c;
    int unk_0x30;
    int unk_0x34;
    char unk_0x38[0x3c - 0x38];
    Surface_00416A40 *unk_0x3c;
    int unk_0x40;
};

struct Hit_00416A40 {
    Vec4_00416A40 point;
    Vec4_00416A40 normal;
    char unk_0x20[0x28 - 0x20];
    Surface_00416A40 *surface;
    Vec4_00416A40 vel;
};

struct Particle_00416A40 {
    Vec4_00416A40 pos;
    Vec4_00416A40 unk_0x10;
    Vec4_00416A40 vel;
    Vec4_00416A40 unk_0x30;
    int unk_0x40;
    Vec4_00416A40 *unk_0x44;
    int unk_0x48;
    float unk_0x4c;
};

struct Wheel_00416A40 {
    float radius;
    char unk_0x04[0x0c - 0x04];
    float unk_0x0c;
    float unk_0x10;
    float unk_0x14;
    float unk_0x18;
    float unk_0x1c;
    float unk_0x20;
    float unk_0x24;
    char unk_0x28[0x38 - 0x28];
    float unk_0x38;
    u8 unk_0x3c;
    u8 unk_0x3d;
    u8 unk_0x3e;
    u8 unk_0x3f;
    u16 unk_0x40;
    u8 unk_0x42;
    char unk_0x43[0x50 - 0x43];
};

struct CarParams_00416A40 {
    char unk_0x00[0x04];
    float unk_0x04;
    float unk_0x08;
    char unk_0x0c[0x14 - 0x0c];
    float unk_0x14;
    char unk_0x18[0x40 - 0x18];
    float unk_0x40;
    float unk_0x44;
    float unk_0x48;
};

struct CarPhys_00416A40 {
    char unk_0x00[0x44];
    float unk_0x44;
    char unk_0x48[0x6c - 0x48];
    float unk_0x6c;
};

struct Gear_00416A40 {
    float ratio;
    float unk_0x4;
};

struct CarDef_00416A40 {
    char unk_0x00[0x11];
    u8 type;
    char unk_0x12[0x14 - 0x12];
    u16 unk_0x14;
    char unk_0x16[0x30 - 0x16];
    float unk_0x30;
    char unk_0x34[0x50 - 0x34];
    u32 unk_0x50;
    char unk_0x54[0x6c - 0x54];
    u32 *unk_0x6c;
    char unk_0x70[0x80 - 0x70];
    CarPhys_00416A40 *phys;
    char unk_0x84[0x88 - 0x84];
    CarParams_00416A40 *params;
    char unk_0x8c[0xd0 - 0x8c];
    u32 numWheels;
    Wheel_00416A40 *wheels;
    char unk_0xd8[0xdc - 0xd8];
    Gear_00416A40 *gears;
};

struct Player_00416A40 {
    s8 unk_0x00;
    char unk_0x01[0x0c - 0x01];
    u8 unk_0x0c;
    char unk_0x0d[0x12 - 0x0d];
    u8 unk_0x12;
    u8 unk_0x13;
    u8 unk_0x14;
    char unk_0x15[0xc8 - 0x15];
    int unk_0xc8;
};

struct WheelState_00416A40 {
    s16 unk_0x00;
    s16 unk_0x02;
    char unk_0x04[0x08 - 0x04];
    float unk_0x08;
    float unk_0x0c;
    u32 color;
    u32 unk_0x14;
    Vec4_00416A40 slip;
    char unk_0x28[0x2c - 0x28];
};

struct Car_00416A40 {
    Vec4_00416A40 vel;
    Mat4_00416A40 mat;
    char unk_0x050[0x94 - 0x50];
    Player_00416A40 *player;
    char unk_0x098[0x1b4 - 0x98];
    WheelState_00416A40 ws[8];
    char unk_0x314[0x320 - 0x314];
    Mat4_00416A40 *bones;
    char unk_0x324[0x35c - 0x324];
    float unk_0x35c[4];
    char unk_0x36c[0x394 - 0x36c];
    int contacts;
    CarDef_00416A40 *def;
    char unk_0x39c[0x3e0 - 0x39c];
    int unk_0x3e0;
    Vec4_00416A40 unk_0x3e4;
    char unk_0x3f4[0x428 - 0x3f4];
    Surface_00416A40 *lastSurface;
    float speed;
    char unk_0x430[0x440 - 0x430];
    int unk_0x440;
    char unk_0x444[0x460 - 0x444];
    int flags;
    char unk_0x464[0x4b0 - 0x464];
    float unk_0x4b0;
    u8 gear;
    char unk_0x4b5[0x4c4 - 0x4b5];
    int sound;
    float unk_0x4c8;
    char unk_0x4cc[0x4ec - 0x4cc];
    Vec4_00416A40 unk_0x4ec;
    Vec4_00416A40 unk_0x4fc;
};

extern Vec4_00416A40 D_00692350;
extern u32 D_00692364;
extern s16 D_00692370;
extern float D_00692378;
extern char D_0068DF05;
extern Car_00416A40 *D_0048D97C;
extern float D_00477000;
extern float D_00477008;
extern float D_0047700C;
extern float D_00477038;
extern float D_00477064;
extern float D_00477078;
extern float D_00477120;
extern float D_0047714C;
extern float D_00477158;
extern float D_004771A4;
extern float D_004771AC;
extern float D_004771B4;
extern float D_004771D8;
extern float D_0047721C;
extern float D_00477220;
extern float D_00477234;
extern float D_00477254;
extern float D_00477258;
extern float D_0047725C;
extern float D_00477260;
extern float D_00477264;
extern float D_0047726C;
extern float D_00477270;
extern float D_00477274;
extern float D_00477278;
extern float D_0047727C;
extern float D_00477280;
extern float D_00477284;
extern float D_00477288;
extern float D_0047728C;

float func_00453360(void *, void *);
float func_004532F0(float);
float func_004534B0(void *);
void func_00453330(void *, void *, void *);
void func_00453380(void *, void *, void *);
void func_00453300(Car_00416A40 *, void *, void *);
void func_00453470(void *);
void func_004535E0(void *, void *, void *);
void func_00454300(void *, void *);
float func_00454AC0(float, float);
float func_00462040(void *);
char func_0043E9F0(Player_00416A40 *);
char func_0044D550(Vec4_00416A40 *, Vec4_00416A40 *, float *, Hit_00416A40 *);
void func_0040E070(Car_00416A40 *, Vec4_00416A40 *, Vec4_00416A40 *, float);
void func_00458220(int, int, int, int);
void func_00401090(int, int, int);
void func_00458250(int, int, int = 0);
void func_00458280(int);
void func_004582A0(int);
void func_0044D0B0(int, Particle_00416A40 *);
int func_0043BDF0(int);
void func_0043BE70(void *, void *, void *, void *, int, float, int);
void func_00416080(float *, float *, float);
void func_004093E0(int, int, void *);
void func_004160C0(Car_00416A40 *);

extern float D_00477268;
extern float D_0047724C;
extern float D_00477248;
extern float D_00477018;
void func_00416A40(Car_00416A40 *car)
{
    int slipCount = 0;
    float steer = 0.0f;
    float drive = 0.0f;
    float rideHeight;
    float load = 0.0f;
    float grip;
    Vec4_00416A40 sum;
    float gripScale;
    Surface_00416A40 *bestSurf;
    float bestLoad;
    float frontSlip;
    float limit;
    float sndVal;
    float tmp[4];
    CarDef_00416A40 *def;
    Player_00416A40 *pl;
    WheelState_00416A40 *ws;
    u32 i;

    func_00453360(&car->mat.row2, car);
    rideHeight = car->def->params->unk_0x14;
    grip = car->def->wheels->unk_0x18 * 0.083333f;
    sum = D_00692350;
    gripScale = 1.0f;
    bestSurf = NULL;
    bestLoad = 0.0f;
    frontSlip = 0.0f;
    car->contacts = 0;
    if (car->player != NULL && func_0043E9F0(car->player)) {
        float speed, f, a, b, fwd, side;
        pl = car->player;
        speed = func_004534B0(car);
        f = speed * 0.014285714f;
        if (1.0f <= f)
            a = 1.0f;
        else
            a = f;
        f = 1.0f - f;
        if (0.0f >= f)
            b = 0.0f;
        else
            b = f;
        fwd = func_004532F0(func_00453360(car, &car->mat.row2));
        side = func_004532F0(func_00453360(car, &car->mat.row0));
        func_00458220(pl->unk_0xc8, 0, (int)(a * 40.0f), (unsigned int)(a * 40.0f));
        func_00401090(pl->unk_0xc8, (int)(b * 130.0f), 0xff);
        if (!car->player->unk_0x12 && !(car->flags & 0x8020)) {
            if (side < 2.0f || side * 1.7f < fwd) {
                if (speed < 70.0f && car->speed < 70.0f)
                    grip += car->def->wheels->unk_0x18 * speed * 0.0167f;
                if (grip > 1.8f)
                    grip = 1.8f;
            }
        }
    }
    if (func_004532F0(func_00453360(&car->unk_0x3e4, &car->mat.row1)) < grip)
        car->flags |= 0x100;
    else
        car->flags &= ~0x100;
    if (car->def->type == 2) {
        CarParams_00416A40 *p = car->def->params;
        float a = p->unk_0x40;
        float b = p->unk_0x44;
        float c = p->unk_0x48;
        float spd = func_004534B0(car);
        if (spd < a) {
            float y = car->mat.row1.y;
            rideHeight = y - (y - car->def->params->unk_0x14) * (spd / a);
        }
        if (spd < b)
            gripScale = spd / b * (1.0f - c) + c;
    }
    func_004535E0(&car->mat.row0, &car->unk_0x4ec, tmp);
    def = car->def;
    if (def->type > 1) {
        if (def->type != 2 || car->player == NULL || car->player->unk_0x12)
            goto noSteer;
        steer = def->params->unk_0x08;
    } else {
        steer = def->params->unk_0x04;
    }
    steer = -steer;
noSteer:
    ws = car->ws;
    for (i = 0; i < def->numWheels; i++, ws++) {
        Wheel_00416A40 *w = &def->wheels[i];
        Vec4_00416A40 up, fwd, side, dir, origin;
        Hit_00416A40 hit;
        float dist, compress;
        char hitOk;
        int parent = w->unk_0x40 - w->unk_0x3f;
        if (w->unk_0x3f) {
            Mat4_00416A40 *m = &car->bones[parent];
            up = m->row1;
            fwd = m->row2;
            side = m->row0;
        } else {
            up = car->mat.row1;
            fwd = car->mat.row2;
            side = car->mat.row0;
        }
        dir.x = -up.x;
        dir.y = -up.y;
        dir.z = -up.z;
        hit.vel = D_00692350;
        origin.x = car->bones[w->unk_0x40].pos.x - dir.x * w->radius;
        origin.y = car->bones[w->unk_0x40].pos.y - dir.y * w->radius;
        origin.z = car->bones[w->unk_0x40].pos.z - dir.z * w->radius;
        D_0048D97C = car;
        dist = w->radius + w->radius + w->unk_0x0c;
        hitOk = func_0044D550(&origin, &dir, &dist, &hit);
        D_0048D97C = NULL;
        ((u8 *)&ws->color)[3] = 0;
        compress = w->radius + w->radius - dist;
        if (hitOk) {
            float pen;
            car->contacts++;
            pen = compress + w->unk_0x0c;
            if (w->unk_0x3c) {
                float wload, reach, slip;
                Vec4_00416A40 contact, rel, rel2, pv, slipV;
                reach = pen + w->radius;
                wload = pen * w->unk_0x10;
                grip = (compress - ws->unk_0x0c) / ((float)D_00692364 * 0.001f) * w->unk_0x1c * gripScale;
                sum.x += hit.normal.x;
                sum.y += hit.normal.y;
                sum.z += hit.normal.z;
                if (car->def->phys->unk_0x6c != 1.0f)
                    reach = pen;
                if (wload > bestLoad && hit.surface->unk_0x3c != NULL) {
                    bestSurf = hit.surface->unk_0x3c;
                    bestLoad = wload;
                }
                contact.x = reach * dir.x + car->bones[w->unk_0x40].pos.x;
                contact.y = reach * dir.y + car->bones[w->unk_0x40].pos.y;
                contact.z = reach * dir.z + car->bones[w->unk_0x40].pos.z;
                contact.w = 1.0f;
                if (w->unk_0x38 != 0.0f && wload > 0.0f && grip > w->unk_0x38)
                    grip = w->unk_0x38;
                func_0040E070(car, &contact, &up, (grip + wload) * func_00453360(&up, &hit.normal));
                limit = 110.0f;
                func_00453330(&contact, &car->mat.pos, &rel);
                func_00453380(&car->unk_0x3e4, &rel, &rel2);
                func_00453300(car, &rel2, &pv);
                slipV.x = pv.x - fwd.x * car->speed - hit.vel.x;
                slipV.y = pv.y - fwd.y * car->speed - hit.vel.y;
                slipV.z = pv.z - fwd.z * car->speed - hit.vel.z;
                func_00454300(&hit.normal, &slipV);
                ws->slip = slipV;
                slip = func_004534B0(&slipV);
                if (slip > 0.0f) {
                    float maxF, k, f, d, throttle, lat, h, off, ny;
                    Vec4_00416A40 n2, force, p, t40;
                    func_00453360(&up, &hit.normal);
                    maxF = wload * w->unk_0x18;
                    if (maxF > w->unk_0x20)
                        maxF = w->unk_0x20;
                    func_00453380(&fwd, &hit.normal, &n2);
                    func_00453470(&n2);
                    k = (1.0f - func_00453360(&n2, &up) * 1.8f) * 1.1f;
                    if (k < 0.1f)
                        k = 0.1f;
                    else if (k > 1.0f)
                        k = 1.0f;
                    if (car->unk_0x440 < 10000)
                        k = 0.0f;
                    if (car->flags & 0x8000)
                        maxF = (1.0f - w->unk_0x24) * maxF;
                    if (car->def->type == 2)
                        f = func_004532F0(hit.normal.y * hit.normal.y * hit.normal.y) * hit.surface->unk_0x14 * maxF;
                    else
                        f = maxF * hit.surface->unk_0x14;
                    if ((car->flags & 0x100) && f * k * D_00692378 > slip) {
                        slipCount++;
                        f = 1.0f / D_00692378;
                    } else {
                        f = f * k / slip;
                    }
                    pl = car->player;
                    throttle = 0.0f;
                    force.x = -(f * slipV.x);
                    force.y = -(f * slipV.y);
                    force.z = -(f * slipV.z);
                    if (pl != NULL)
                        throttle = pl->unk_0x00;
                    if (pl == NULL || !pl->unk_0x13 || pl->unk_0x12) {
                        d = func_00453360(&fwd, &force);
                        lat = -((1.0f - car->unk_0x4c8) * w->unk_0x14 * throttle);
                        d = (1.0f - w->unk_0x14 * car->unk_0x4c8) * d;
                        force.x -= d * fwd.x;
                        force.y -= d * fwd.y;
                        force.z -= d * fwd.z;
                        force.x -= side.x * lat;
                        force.y -= side.y * lat;
                        force.z -= side.z * lat;
                    } else {
                        d = 0.0f;
                    }
                    drive += d;
                    ny = hit.normal.y;
                    func_00453330(&contact, &car->mat.pos, &t40);
                    h = func_00453360(&up, &t40);
                    off = -((1.0f - rideHeight) * h);
                    if (car->unk_0x3e0 < 500)
                        off = h * ny * -1.0f;
                    p.x = off * up.x + contact.x;
                    p.y = off * up.y + contact.y;
                    p.z = off * up.z + contact.z;
                    func_0040E070(car, &p, &force, 1.0f);
                    if (i == 2 || i == 3)
                        frontSlip += func_00453360(&side, &slipV);
                }
                if (D_0068DF05) {
                    if (w->unk_0x42 && hit.surface->unk_0x40 && w->unk_0x14 != 0.0f && slip > 20.0f) {
                        float sz = 450.0f - (slip - 20.0f) * w->unk_0x14 * 3.0f;
                        if (sz < 50.0f)
                            sz = 50.0f;
                        else if (sz > 1000.0f)
                            sz = 1000.0f;
                        ws->unk_0x02 += D_00692370;
                        if (ws->unk_0x02 > 50) {
                            sz *= 0.01f;
                            do {
                                Particle_00416A40 pa;
                                pa.unk_0x40 = hit.surface->unk_0x40;
                                pa.pos = contact;
                                pa.vel = car->vel;
                                pa.unk_0x30 = D_00692350;
                                pa.unk_0x10.x = 0.0f;
                                pa.unk_0x10.y = 0.0f;
                                pa.unk_0x10.z = 0.0f;
                                pa.unk_0x10.w = 1.0f;
                                pa.unk_0x44 = &car->mat.pos;
                                pa.unk_0x48 = 0;
                                pa.unk_0x4c = sz;
                                func_0044D0B0(1, &pa);
                                ws->unk_0x02 -= 50;
                            } while (ws->unk_0x02 > 50);
                        }
                    }
                    if (hit.surface->unk_0x30 && func_004532F0(car->speed) > 50.0f) {
                        u32 n = (int)(50.0f / func_004532F0(car->speed) * hit.surface->unk_0x1c + slip);
                        if (n > 200)
                            n = 200;
                        ws->unk_0x02 += D_00692370;
                        while (ws->unk_0x02 > (int)n) {
                            Particle_00416A40 pb;
                            pb.unk_0x40 = hit.surface->unk_0x30;
                            pb.pos = contact;
                            pb.vel = car->vel;
                            pb.unk_0x30 = D_00692350;
                            pb.unk_0x10.x = 0.0f;
                            pb.unk_0x10.y = 0.0f;
                            pb.unk_0x10.z = 0.0f;
                            pb.unk_0x10.w = 1.0f;
                            pb.unk_0x44 = NULL;
                            pb.unk_0x48 = 0;
                            pb.unk_0x4c = 0;
                            func_0044D0B0(1, &pb);
                            ws->unk_0x02 -= n;
                        }
                    }
                    if (hit.surface->unk_0x34 && slip > 60.0f && wload > 60.0f &&
                        func_00462040(&car->mat.pos) < 40000.0f) {
                        int n = (int)(62500.0f / wload * hit.surface->unk_0x20);
                        ws->unk_0x00 += D_00692370;
                        while (ws->unk_0x00 > n && func_0043BDF0(hit.surface->unk_0x34)) {
                            Vec4_00416A40 acc, grav, v;
                            float s, r;
                            acc.x = 0.0f;
                            acc.y = 0.0f;
                            s = w->unk_0x14 * car->speed * 0.3f;
                            acc.z = 0.0f;
                            acc.w = 1.0f;
                            r = func_00454AC0(5.0f, 30.0f) * w->unk_0x14;
                            grav.x = 0.0f;
                            grav.y = -0.0001f;
                            grav.z = 0.0f;
                            grav.w = 0.0f;
                            v.x = (r * up.x + (car->vel.x * 1.02f - s * fwd.x)) * 0.001f;
                            v.y = (r * up.y + (car->vel.y * 1.02f - s * fwd.y)) * 0.001f;
                            v.z = (r * up.z + (car->vel.z * 1.02f - s * fwd.z)) * 0.001f;
                            func_0043BE70(&contact, &v, &grav, &acc, hit.surface->unk_0x34, 1.0f, 0);
                            ws->unk_0x00 -= n;
                        }
                    }
                }
                def = car->def;
                if (slip > (car->player != NULL && def->type == 2 && ((car->flags & 0x8000) || (car->flags & 0x20)) ? 3.0f : limit) &&
                    car->def->unk_0x50 > 0 && w->unk_0x3e && hit.surface->unk_0x00 != 1) {
                    float s = wload * 0.025f;
                    int tex = car->def->unk_0x14;
                    u32 color = *car->def->unk_0x6c;
                    u8 alpha = ((u8 *)&color)[3];
                    u8 a;
                    if (s < 0.03f)
                        s = 0.03f;
                    else if (s > 1.0f)
                        s = 1.0f;
                    if (hit.surface->unk_0x00 == 2) {
                        color = *hit.surface->unk_0x2c;
                        tex = hit.surface->unk_0x02;
                    }
                    load += s * 0.23f;
                    a = (int)(s * 255.0f);
                    ((u8 *)&color)[3] = a;
                    if (a > alpha)
                        ((u8 *)&color)[3] = alpha;
                    if (s > 0.01f) {
                        ws->color = color;
                        ws->unk_0x14 = tex;
                    }
                }
            }
        } else {
            ws->slip = D_00692350;
        }
        ws->unk_0x0c = compress;
        if (car->def->type != 1 || compress < 0.3f)
            ws->unk_0x08 = compress;
        def = car->def;
    }
    pl = car->player;
    if (pl != NULL) {
        if (!(pl->unk_0x0c & 4)) {
            float v;
            def = car->def;
            car->unk_0x4b0 = D_00692378 * car->unk_0x4c8 * drive * steer + car->unk_0x4b0;
            v = car->unk_0x4b0 * def->gears[car->gear].ratio;
            car->speed = v;
            if (car->flags & 0x1000) {
                float m = def->phys->unk_0x44 * def->unk_0x30;
                if (v > m)
                    car->speed = m;
            } else if (v > def->phys->unk_0x44) {
                car->speed = def->phys->unk_0x44;
            }
        }
        if (car->player != NULL && func_0043E9F0(car->player)) {
            float a;
            pl = car->player;
            if (frontSlip > 0.0f) {
                a = frontSlip * 0.033333335f * 180.0f;
                if (180.0f <= a)
                    a = 180.0f;
                func_00458250(pl->unk_0xc8, (int)a, 270);
            } else {
                a = frontSlip * -0.033333335f * 180.0f;
                if (180.0f <= a)
                    a = 180.0f;
                func_00458250(pl->unk_0xc8, (int)a, 90);
            }
            if (frontSlip == 0.0f) {
                if (!(car->flags & 0x10000))
                    func_00458280(pl->unk_0xc8);
            } else {
                func_004582A0(pl->unk_0xc8);
            }
        }
    }
    pl = car->player;
    if (pl != NULL && !pl->unk_0x12 && !pl->unk_0x13 && !pl->unk_0x14 &&
        func_004532F0(car->speed) < 1.0f && slipCount == car->def->numWheels) {
        if (func_00453360(&car->unk_0x3e4, &car->mat.row1) < 0.05f) {
            func_00454300(&car->mat.row0, car);
            func_00416080(car->unk_0x35c, &car->mat.row1.x, 0.5f);
        }
    }
    if (car->sound != -1) {
        if (bestSurf != NULL) {
            sndVal = bestSurf->unk_0x14;
            if (load > 1.0f)
                load = 1.0f;
            if (bestSurf != car->lastSurface) {
                limit = 0.0f;
                func_004093E0(car->sound, 0, &limit);
                func_004093E0(car->sound, 8, &sndVal);
                car->lastSurface = bestSurf;
            } else {
                func_004093E0(car->sound, 0, &load);
                func_004093E0(car->sound, 5, &car->mat.pos);
                func_004093E0(car->sound, 6, car);
            }
        } else {
            limit = 0.0f;
            func_004093E0(car->sound, 0, &limit);
        }
    }
    if (car->contacts == car->def->numWheels) {
        car->unk_0x4fc = sum;
        func_00453470(&car->unk_0x4fc);
    }
    func_004160C0(car);
}
