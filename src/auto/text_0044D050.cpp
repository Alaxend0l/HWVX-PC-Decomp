/* 20 functions from 0x0044D050 to 0x0044E050, found by Ghidra. */
#include "common.h"

struct Obj_0044D050;

struct Funcs_0044D050 {
    void (*unk_0x00)(Obj_0044D050 *, int);
    void (*unk_0x04)(Obj_0044D050 *);
    void (*unk_0x08)(Obj_0044D050 *);
    void (*unk_0x0c)(Obj_0044D050 *);
    void (*unk_0x10)(Obj_0044D050 *);
    void (*unk_0x14[11])(Obj_0044D050 *);
    int (*unk_0x40)(Obj_0044D050 *);
};

struct Obj_0044D050 {
    char unk_0x00[0x40];
    float unk_0x40[12];
    float unk_0x70;
    unsigned int unk_0x74;
    char unk_0x78[0x80 - 0x78];
    short unk_0x80;
    char unk_0x82;
    char unk_0x83[0x8c - 0x83];
    Funcs_0044D050 *unk_0x8c;
    char unk_0x90[0xa4 - 0x90];
    Obj_0044D050 *unk_0xa4;
};

extern Obj_0044D050 *D_0053A9D0;
extern int D_0053A9D4[0x12];
extern Obj_0044D050 *D_0048D97C;

Obj_0044D050 *func_0044A810(int *);
void func_0044A790(Obj_0044D050 **, Obj_0044D050 *);
void func_00449AD0(Obj_0044D050 *);
int func_0045E270(char *, int);
int func_0044D860(void **, int);

struct Ent560_0044D050 {
    char unk_0x00[0x74];
    unsigned int unk_0x74;
    char unk_0x78[0x560 - 0x78];
};

struct EntF0_0044D050 {
    char unk_0x00[0x74];
    unsigned int unk_0x74;
    char unk_0x78[0xf0 - 0x78];
};

struct Ent1D0_0044D050 {
    char unk_0x00[0x74];
    unsigned int unk_0x74;
    char unk_0x78[0x1d0 - 0x78];
};

struct EntE0_0044D050 {
    char unk_0x00[0x74];
    unsigned int unk_0x74;
    char unk_0x78[0xe0 - 0x78];
};

extern EntE0_0044D050 D_005305D0[128];
extern EntE0_0044D050 D_005375D0[];

struct Info_0044DF30 {
    char unk_0x00[0x14];
    int unk_0x14;
};

struct Sub_0044DF30 {
    char unk_0x00[0xa0];
    Info_0044DF30 *unk_0xa0;
};

struct Car_0044DF30 {
    char unk_0x00[0x78];
    int unk_0x78;
    char unk_0x7c[0x398 - 0x7c];
    Sub_0044DF30 *unk_0x398;
};

struct Racer_0044DF30 {
    char unk_0x00[0x28];
    Car_0044DF30 *unk_0x28;
};

struct Player_0044DFC0 {
    char unk_0x00[0x434];
    int unk_0x434;
    char unk_0x438[0x4b4 - 0x438];
    unsigned char unk_0x4b4;
};

struct Game_0044DFC0 {
    char unk_0x00[0x2c];
    Player_0044DFC0 *unk_0x2c;
};

struct Cond_0044DFC0 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
};

extern Game_0044DFC0 *D_00681500;

extern Ent560_0044D050 D_0051F720[8];
extern Ent560_0044D050 D_00522220[];
extern EntF0_0044D050 D_004F3C20[96];
extern EntF0_0044D050 D_004F9620[];
extern Ent1D0_0044D050 D_00511E20[80];
extern Ent1D0_0044D050 D_0051AF20[];
char func_0041ACE0(int, int, int, int);
char func_0044D370(int, int, int, int);
char func_004194B0(int, float *, float *, int);
char func_0044D250(int, Obj_0044D050 *, int);
char func_00419CA0(int, int);
char func_0044D140(int, Obj_0044D050 *, int);

struct Pair_0044D050 {
    int unk_0x0;
    Obj_0044D050 *obj;
};

static inline float Sq_0044D050(float x)
{
    return x * x;
}

void func_0044A0D0(Obj_0044D050 *, float *, float *);
int func_0042D7A0(float *, float *, int, Pair_0044D050 *, int);
float func_004535B0(float *, float *);
char func_0041CE70(int, int, int);

static inline char Touch_0044D050(Obj_0044D050 *obj, Obj_0044D050 *o, int c)
{
    if (Sq_0044D050(o->unk_0x70 + obj->unk_0x70) > func_004535B0(obj->unk_0x40, o->unk_0x40) &&
        o->unk_0x80 == 1 && func_0041CE70((int)obj, o->unk_0x8c->unk_0x40(o), c)) {
        if (c != 0) {
            *(Obj_0044D050 **)(c + 0x20) = obj;
            *(Obj_0044D050 **)(c + 0x24) = o;
        }
        return 1;
    }
    return 0;
}

extern int *D_0049DBA0;
extern float D_00692350[4];
extern unsigned int D_0052E664;
extern char D_0052E5F0[];

int func_0045E270(float *, float);
void func_0044D050(void)
{
    Obj_0044D050 *p;

    for (p = D_0053A9D0; p != NULL; p = p->unk_0xa4) {
        if ((p->unk_0x74 & 0x200200) == 0 && func_0045E270(p->unk_0x40, p->unk_0x70) != 0) {
            p->unk_0x8c->unk_0x10(p);
            D_0048D97C = p;
            func_00449AD0(p);
        }
    }
    D_0048D97C = NULL;
}

char func_0044D140(int a, Obj_0044D050 *obj, register int c)
{
    unsigned int n;
    float mn[4];
    float mx[4];
    Pair_0044D050 hits[0x100];
    register unsigned int i;
    Obj_0044D050 *o;

    func_0044A0D0(obj, mx, mn);
    n = func_0042D7A0(mx, mn, 5, hits, 0x100);
    for (i = 0; i < n; i++) {
        o = hits[i].obj;
        if (!(o->unk_0x74 & 2) && o->unk_0x80 != 0 && o != obj) {
            if (Sq_0044D050(o->unk_0x70 + obj->unk_0x70) > func_004535B0(obj->unk_0x40, o->unk_0x40) &&
                o->unk_0x80 == 1 && func_0041CE70((int)obj, o->unk_0x8c->unk_0x40(o), c)) {
                if (c != 0) {
                    *(Obj_0044D050 **)(c + 0x20) = obj;
                    *(Obj_0044D050 **)(c + 0x24) = o;
                }
                return 1;
            }
        }
    }
    return 0;
}

int func_0044D860(void **out, int n);
int func_0044D860(void **out, int n)
{
    int count = 0;
    Ent560_0044D050 *p = D_0051F720;

    do {
        if ((p->unk_0x74 & 0x201000) == 0) {
            *out = p;
            count++;
            out++;
        }
        p++;
    } while (p < D_00522220);
    return count;
}

int func_0044D890(void **out)
{
    int count = 0;
    EntF0_0044D050 *p = D_004F3C20;

    do {
        if ((p->unk_0x74 & 0x201000) == 0) {
            *out = p;
            count++;
            out++;
        }
        p++;
    } while (p < D_004F9620);
    return count;
}

int func_0044D8C0(void **out)
{
    int count = 0;
    Ent1D0_0044D050 *p = D_00511E20;

    do {
        if ((p->unk_0x74 & 0x201000) == 0) {
            *out = p;
            count++;
            out++;
        }
        p++;
    } while (p < D_0051AF20);
    return count;
}

int func_0044D8F0(void **out)
{
    int count = 0;
    EntE0_0044D050 *p = D_005305D0;

    do {
        if ((p->unk_0x74 & 0x201000) == 0) {
            *out = p;
            count++;
            out++;
        }
        p++;
    } while (p < D_005375D0);
    return count;
}

int func_0044D920(char **out)
{
    int r = 0;

    if (!(D_0052E664 & 0x201000)) {
        *out = D_0052E5F0;
        r = 1;
    }
    return r;
}

Obj_0044D050 *func_0044D0B0(int id, int arg)
{
    Obj_0044D050 *p;

    p = func_0044A810(&D_0053A9D4[id]);
    if (p != NULL) {
        func_0044A790(&D_0053A9D0, p);
        p->unk_0x8c->unk_0x00(p, arg);
        return p;
    }
    return NULL;
}

Obj_0044D050 *func_0044D0F0(unsigned int id, int arg, char c)
{
    Obj_0044D050 *p;

    p = func_0044A810(D_0053A9D4 + id);
    if (p != NULL) {
        p->unk_0x8c->unk_0x00(p, arg);
        p->unk_0x74 |= 0x20000000;
        p->unk_0x82 = c;
        return p;
    }
    return NULL;
}

char func_0044D550(int a, int b, int c, int d)
{
    char r;

    if (D_0049DBA0 != NULL && *D_0049DBA0 != 0) {
        r = func_0041ACE0(a, b, c, d);
        if (func_0044D370(a, b, c, d))
            return 1;
        return r;
    }
    return 0;
}

char func_0044D5A0(int a, Obj_0044D050 *p, int c)
{
    float f = 1.0f;

    if (!(p->unk_0x74 & 0x40000) && func_004194B0(a, D_00692350, &f, c))
        return 1;
    return func_0044D250(a, p, c);
}

char func_0044D5F0(int a, Obj_0044D050 *p, int c)
{
    char r;

    if (!(p->unk_0x74 & 0x40000)) {
        r = func_00419CA0(a, c);
        if (r)
            return 1;
    }
    return func_0044D140(a, p, c);
}

void func_0044D940(void **out)
{
    func_0044D860(out, 0x20);
}

char func_0044DF30(unsigned int *a)
{
    unsigned int n = a[0];
    int mode = a[n + 1];
    Racer_0044DF30 **racers = (Racer_0044DF30 **)(a + 1);
    int *vals = (int *)(a + n + 3);
    int d = a[n + 2];
    int r = 0;
    unsigned int i;
    Car_0044DF30 *car;

    for (i = 0; i < n; i++) {
        car = racers[i]->unk_0x28;
        if (mode == 0x2a) {
            if (car->unk_0x78 < vals[i] - d)
                r = 1;
            vals[i] = car->unk_0x78;
        } else if (mode == 0x2b) {
            if (car->unk_0x78 < car->unk_0x398->unk_0xa0->unk_0x14 / d)
                r = 1;
        }
    }
    return r;
}

char func_0044DFC0(Cond_0044DFC0 *c)
{
    Player_0044DFC0 *p = D_00681500->unk_0x2c;

    if (p != NULL && p->unk_0x4b4 == c->unk_0x4)
        return 1;
    return 0;
}
char func_0044DFF0(Cond_0044DFC0 *c)
{
    Player_0044DFC0 *p = D_00681500 != NULL ? D_00681500->unk_0x2c : NULL;

    if (c->unk_0x8 == 0) {
        if (p != NULL && p->unk_0x434 >= c->unk_0x4)
            return c->unk_0x8 = 1;
    } else if (p != NULL && p->unk_0x434 == 0) {
        c->unk_0x8 = 0;
        return 1;
    }
    return 0;
}
