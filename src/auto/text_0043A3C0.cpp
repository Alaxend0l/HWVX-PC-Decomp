/* 14 functions from 0x0043A3C0 to 0x0043B062, found by Ghidra. */
#include "common.h"

struct Sub_0043A3C0 {
    char unk_0x0[0x32];
    char unk_0x32;
};

struct Obj_0043A3C0 {
    char unk_0x0[0x10];
    char unk_0x10[0x20];
    char unk_0x30[0x10];
    char unk_0x40[0x54];
    Sub_0043A3C0 *unk_0x94;
    char unk_0x98[0x18];
    char unk_0xb0[0xc];
    Obj_0043A3C0 *unk_0xbc;
    int unk_0xc0;
};

extern char D_005D4440[];
extern char (*D_0048D634)(void);

struct Slot_0048D638 {
    int used;
    char *buf;
};

struct Pool_0048D638 {
    Slot_0048D638 small[0x60];
    Slot_0048D638 medium[0x80];
    Slot_0048D638 large[0x80];
};

extern Pool_0048D638 *D_0048D638;
extern const char D_0047AF74[];

extern "C" void *func_00454B80(unsigned int size, int line, const char *file);
extern "C" void func_00454C50(void *p);

void func_004073A0(char *);
void func_00407420(char *, char *, char *);
Obj_0043A3C0 *func_0044D950(char *, char *);
int func_004480C0(void);
int func_00447FC0(int);
void func_00401090(void);
void func_0044B8C0(void);
void func_004420C0(void);
void func_004507D0(void);
void func_0043ADC0(void);
void func_00452020(void);
void func_0042CFF0(void);
void func_00447FA0(void);
void func_0040A4A0(void);
void func_0044EFC0(void);
void func_00459210(void);
void func_00461A80(void);
void func_00443D20(void);
void func_00427730(void);
void func_004093C0(void);
void func_00454D30(void);

void func_0043A760(Obj_0043A3C0 *obj)
{
    if (obj->unk_0x94->unk_0x32 == 7) {
        if (obj->unk_0xbc != NULL) {
            obj->unk_0xbc = NULL;
        } else {
            obj->unk_0xbc = func_0044D950(obj->unk_0x40, obj->unk_0x30);
            if (obj->unk_0xbc == obj)
                obj->unk_0xbc = NULL;
        }
    }
    obj->unk_0x94->unk_0x32 = 0;
}

void func_0043AD10(void)
{
    char *p;
    unsigned int i;

    D_0048D638 = (Pool_0048D638 *)func_00454B80(0xa6b00, 0x20, D_0047AF74);
    p = (char *)(D_0048D638 + 1);
    for (i = 0; i < 0x60; i++) {
        D_0048D638->small[i].buf = p;
        D_0048D638->small[i].used = 0;
        p += 0x100;
    }
    for (i = 0; i < 0x80; i++) {
        D_0048D638->medium[i].buf = p;
        D_0048D638->medium[i].used = 0;
        p += 0x400;
    }
    for (i = 0; i < 0x80; i++) {
        D_0048D638->large[i].buf = p;
        D_0048D638->large[i].used = 0;
        p += 0x1000;
    }
}

void func_0043ADC0(void)
{
    func_00454C50(D_0048D638);
    D_0048D638 = NULL;
}

char *func_0043ADE0(unsigned int size, int tag)
{
    unsigned int i;

    if (size > 0x10) {
        for (i = 0; i < 0x80; i++) {
            if (D_0048D638->large[i].used == 0) {
                D_0048D638->large[i].used = tag;
                return D_0048D638->large[i].buf;
            }
        }
        return NULL;
    }
    if (size > 4) {
        for (i = 0; i < 0x80; i++) {
            if (D_0048D638->medium[i].used == 0) {
                D_0048D638->medium[i].used = tag;
                return D_0048D638->medium[i].buf;
            }
        }
        return NULL;
    }
    for (i = 0; i < 0x60; i++) {
        if (D_0048D638->small[i].used == 0) {
            D_0048D638->small[i].used = tag;
            return D_0048D638->small[i].buf;
        }
    }
    return NULL;
}

void func_0043AE90(char *buf)
{
    unsigned int i;

    for (i = 0; i < 0x80; i++) {
        if (D_0048D638->large[i].buf == buf) {
            D_0048D638->large[i].used = 0;
            return;
        }
    }
    for (i = 0; i < 0x80; i++) {
        if (D_0048D638->medium[i].buf == buf) {
            D_0048D638->medium[i].used = 0;
            return;
        }
    }
    for (i = 0; i < 0x60; i++) {
        if (D_0048D638->small[i].buf == buf) {
            D_0048D638->small[i].used = 0;
            return;
        }
    }
}

char func_0043AC70(void)
{
    int id = func_004480C0();

    if (id != -1 && func_00447FC0(id) != id)
        return 0;
    return D_0048D634();
}

char func_0043ACA0(void)
{
    func_00401090();
    func_0044B8C0();
    func_00401090();
    func_004420C0();
    func_004507D0();
    func_0043ADC0();
    func_00452020();
    func_0042CFF0();
    func_00447FA0();
    func_0040A4A0();
    func_0044EFC0();
    func_00401090();
    func_00401090();
    func_00459210();
    func_00461A80();
    func_00443D20();
    func_00427730();
    func_004093C0();
    func_00454D30();
    return 1;
}

void func_0043B020(Obj_0043A3C0 *obj)
{
    if (obj->unk_0xc0 != 0) {
        func_004073A0(obj->unk_0xb0);
        return;
    }
    func_00407420(obj->unk_0xb0, obj->unk_0x10, D_005D4440);
}
