/* 20 functions from 0x0044D050 to 0x0044E050, found by Ghidra. */
#include "common.h"

struct Obj_0044D050;

struct Funcs_0044D050 {
    void (*unk_0x00)(Obj_0044D050 *, int);
    void (*unk_0x04)(Obj_0044D050 *);
    void (*unk_0x08)(Obj_0044D050 *);
    void (*unk_0x0c)(Obj_0044D050 *);
    void (*unk_0x10)(Obj_0044D050 *);
};

struct Obj_0044D050 {
    char unk_0x00[0x40];
    float unk_0x40[12];
    float unk_0x70;
    unsigned int unk_0x74;
    char unk_0x78[0x82 - 0x78];
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
void func_0044D860(int, int);

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

void func_0044D940(int a)
{
    func_0044D860(a, 0x20);
}
