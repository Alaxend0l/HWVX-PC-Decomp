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

char func_0043AC70(void)
{
    int id = func_004480C0();

    if (id != -1 && func_00447FC0(id) != id)
        return 0;
    return D_0048D634();
}

void func_0043B020(Obj_0043A3C0 *obj)
{
    if (obj->unk_0xc0 != 0)
        func_004073A0(obj->unk_0xb0);
    else
        func_00407420(obj->unk_0xb0, obj->unk_0x10, D_005D4440);
}
