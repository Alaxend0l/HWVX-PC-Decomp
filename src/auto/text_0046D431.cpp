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

#pragma optimize("s", on)
extern "C" int func_0046D431(int flag)
{
    int count = 0;
    int err = 0;
    int i;

    func_0046E959(2);
    for (i = 0; i < D_006D6B00; i++) {
        if (D_006D5AE4[i] != 0 && (D_006D5AE4[i]->flag & 0x83)) {
            func_0046C845(i, D_006D5AE4[i]);
            if (D_006D5AE4[i]->flag & 0x83) {
                if (flag == 1) {
                    if (func_0046D39E(D_006D5AE4[i]) != -1)
                        count++;
                } else if (flag == 0 && (D_006D5AE4[i]->flag & 2)) {
                    if (func_0046D39E(D_006D5AE4[i]) == -1)
                        err = -1;
                }
            }
            func_0046C897(i, D_006D5AE4[i]);
        }
    }
    func_0046E9BA(2);
    if (flag == 1)
        return count;
    return err;
}
#pragma optimize("s", on)
extern "C" int func_0046D4D5(unsigned int fh, const void *buf, unsigned int cnt)
{
    int r;
    if (fh < D_006D5AE0 && (D_006D59E0[(int)fh >> 5][fh & 0x1f].osfile & 1)) {
        func_00472339(fh);
        r = func_0046D53A(fh, buf, cnt);
        func_00472398(fh);
        return r;
    }
    *func_00470486() = 9;
    *func_0047048F() = 0;
    return -1;
}
