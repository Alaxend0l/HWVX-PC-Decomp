/* 3 functions from 0x0046D431 to 0x0046D6C5, found by Ghidra. */
#include "common.h"
typedef struct {
    int osfhnd;
    char osfile;
    char pipech;
    char pad[0x24 - 6];
} ioinfo;

typedef struct {
    char *ptr;
    int cnt;
    char *base;
    int flag;
} CRTFILE;

extern "C" unsigned int D_006D5AE0;
extern "C" ioinfo *D_006D59E0[];
extern "C" int D_006D6B00;
extern "C" CRTFILE **D_006D5AE4;
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" void func_0046C845(int, CRTFILE *);
extern "C" void func_0046C897(int, CRTFILE *);
extern "C" int func_0046D39E(CRTFILE *);
extern "C" void func_00472339(int);
extern "C" void func_00472398(int);
extern "C" int func_0046D53A(int, const void *, unsigned int);
extern "C" int *func_00470486(void);
extern "C" unsigned long *func_0047048F(void);
