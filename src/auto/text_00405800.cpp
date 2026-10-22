/* 7 functions from 0x00405800 to 0x00406770, found by Ghidra. */
#include "common.h"

struct Obj_00405800 {
    char pad_0x00[0xb8];
    Obj_00405800 *unk_0xb8;
    void (*unk_0xbc)(void);
    char pad_0xc0[4];
    char unk_0xc4;
    char pad_0xc5[3];
    int unk_0xc8;
    char pad_0xcc;
    char unk_0xcd;
    char pad_0xce[2];
    int unk_0xd0;
    char pad_0xd4[4];
    int unk_0xd8;
    int unk_0xdc;
    int unk_0xe0;
    int unk_0xe4;
    char pad_0xe8[4];
    char unk_0xec;
    char pad_0xed[3];
    int unk_0xf0;
    int unk_0xf4;
};

struct Cmd_00405800 {
    char *desc;
    char pad_0x4[0xc];
    char *target;
};

struct Req_00405800 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    int unk_0xc;
    char unk_0x10;
    char unk_0x11;
};

struct Slot_00405800 {
    char *unk_0x0;
    short unk_0x4;
    short unk_0x6;
    short unk_0x8;
    short unk_0xa;
    char pad_0xc[8];
};

extern float D_00477000;
extern float D_00477040;
extern "C" float func_004535B0(void *a, void *b);
extern "C" float func_00401FF0(char *a, void *b);
extern "C" char func_004020C0(float a, float b, float c);

static inline char InRange_00405800(char *p, char *pos, float maxDist, float minDist, float dir, float range)
{
    float d = func_004535B0(pos, *(char **)(p + 0x2c) + 0x40);
    if (minDist != D_00477000 || maxDist != D_00477000) {
        if (d > maxDist || d < minDist)
            return 0;
    }
    return func_004020C0(func_00401FF0(*(char **)(p + 0x2c), pos) * D_00477040, dir, range);
}

extern "C" void func_00401F80(char *p);
extern "C" void func_00401FA0(char *p, int *a);
extern "C" void func_00406770(void);
extern "C" void func_004061D0(char *p);
extern float D_00477000;
extern float D_00477040;
extern char D_0047AED8[];
extern "C" float func_004535B0(void *a, void *b);
extern "C" float func_00401FF0(char *a, void *b);
extern "C" char func_004020C0(float a, float b, float c);
extern "C" char func_004057E0(char *p, char *desc, char *target);
extern "C" unsigned int func_0043BD10(void);
extern "C" char *func_0043BD20(unsigned int id);
extern "C" char func_0043E9F0(char *p);
extern "C" char func_00405800(char *p, Cmd_00405800 *cmd, float maxDist, float minDist, float dir, float range)
{
    char *desc = cmd->desc;
    char type = desc[0];

    if (type == 6 || type == 7 || type == 8 || type == 9 || type == 0xb || type == 0xd) {
        char *t = cmd->target;
        char *pos;
        float d;
        if (t == NULL || *(char **)(t + 0x8c) != D_0047AED8 || (*(unsigned int *)(t + 0x74) & 0x1000))
            return 0;
        if (**(char **)(t + 0xc0) == 7 && *(char **)(t + 0x94) != NULL
            && *(int *)(*(char **)(t + 0x94) + 0x2c) != 0) {
            if (!func_0043E9F0(*(char **)(t + 0x94)))
                return 0;
            pos = *(char **)(*(char **)(cmd->target + 0x94) + 0x2c) + 0x40;
        } else {
            pos = t + 0x40;
        }
        if (pos == NULL)
            return 0;
        d = func_004535B0(pos, *(char **)(p + 0x2c) + 0x40);
        if (minDist != D_00477000 || maxDist != D_00477000) {
            if (d > maxDist || d < minDist)
                return 0;
        }
        d = func_00401FF0(*(char **)(p + 0x2c), pos) * D_00477040;
        if (func_004020C0(d, dir, range))
            return 1;
    } else if (type == 1 || type == 2 || type == 3) {
        float d;
        if (*(unsigned int *)(cmd->target + 0x74) & 0x1000)
            return 0;
        if (!func_004057E0(p, desc, cmd->target))
            return 0;
        if (cmd->desc[1] == 3) {
            char *req = *(char **)(cmd->desc + 0x58);
            char kind = req[0x10];
            char ok = kind != 1;
            short i;
            for (i = 0; i < 16; i++) {
                if (*(char **)(p + 0x4a4 + i * 0x14) == NULL)
                    break;
                if (*(char **)(p + 0x4a4 + i * 0x14) == cmd->target) {
                    if (req[0x11] == 1) {
                        if ((*(int *)(req + 0x8) > 0 && *(short *)(p + 0x4ac + i * 0x14) > *(int *)(req + 0x8))
                            || (*(int *)(req + 0xc) > 0 && *(short *)(p + 0x4ae + i * 0x14) > *(int *)(req + 0xc))
                            || (*(int *)(req + 0x0) > 0 && *(short *)(p + 0x4a8 + i * 0x14) > *(int *)(req + 0x0))
                            || (*(int *)(req + 0x4) > 0 && *(short *)(p + 0x4aa + i * 0x14) > *(int *)(req + 0x4)))
                            ok = kind == 1;
                    } else {
                        if ((*(int *)(req + 0x8) == 0 || *(short *)(p + 0x4ac + i * 0x14) > *(int *)(req + 0x8))
                            && (*(int *)(req + 0xc) == 0 || *(short *)(p + 0x4ae + i * 0x14) > *(int *)(req + 0xc))
                            && (*(int *)(req + 0x0) == 0 || *(short *)(p + 0x4a8 + i * 0x14) > *(int *)(req + 0x0))
                            && (*(int *)(req + 0x4) == 0 || *(short *)(p + 0x4aa + i * 0x14) > *(int *)(req + 0x4)))
                            ok = kind == 1;
                    }
                    break;
                }
            }
            if (!ok)
                return 0;
        }
        d = func_004535B0(cmd->target + 0x40, *(char **)(p + 0x2c) + 0x40);
        if (minDist != D_00477000 || maxDist != D_00477000) {
            if (d > maxDist || d < minDist)
                return 0;
        }
        d = func_00401FF0(*(char **)(p + 0x2c), cmd->target + 0x40) * D_00477040;
        if (func_004020C0(d, dir, range))
            return 1;
    } else if (type == 0xa) {
        char *t = cmd->target;
        if (t != NULL && t[0x50] != 0) {
            float r;
            if (desc[5] == 0) {
                r = *(float *)(t + 0x24);
                if (!(func_004535B0(t, *(char **)(p + 0x2c) + 0x40) > r * r))
                    return 0;
            }
            return 1;
        }
    } else if (type == 0xe) {
        if (cmd->target != NULL) {
            unsigned int id = *(unsigned int *)(p + 0x494);
            if (id < func_0043BD10()) {
                cmd->target = func_0043BD20(id);
                return 1;
            }
        }
    }
    return 0;
}

extern "C" void func_004061D0(char *q)
{
    func_00401F80(q);
    ((Obj_00405800 *)q)->unk_0xe4 = 0;
    ((Obj_00405800 *)q)->unk_0xec = 0;
    ((Obj_00405800 *)q)->unk_0xf4 = 0;
    ((Obj_00405800 *)q)->unk_0xf0 = 0;
    ((Obj_00405800 *)q)->unk_0xcd = 0;
    ((Obj_00405800 *)q)->unk_0xc8 = 0;
    ((Obj_00405800 *)q)->unk_0xd8 = 0;
    ((Obj_00405800 *)q)->unk_0xdc = -1;
    ((Obj_00405800 *)q)->unk_0xe0 = 0;
}

extern "C" float func_004065F0(float *a, float *b)
{
    float dz = a[2] - b[2];
    float dx = a[0] - b[0];
    return dx * dx + dz * dz;
}

extern "C" void func_00406720(char *p, int *a)
{
    func_00401FA0(p, a);
    *(int *)(p + 0xd0) = *a;
    *(char **)(p + 0xb8) = p;
    *(void (**)(void))(p + 0xbc) = func_00406770;
    *(char *)(p + 0xc4) = 0;
    func_004061D0(p);
    *(char *)(p + 0xcd) = 3;
}
