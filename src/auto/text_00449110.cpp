/* 11 functions from 0x00449110 to 0x0044A0D0, found by Ghidra. */
#include "common.h"

void func_0044B310(int a, void *list, int c);
struct Vec4_00449110 {
    float x, y, z, w;
};

/* particle spawn record passed to func_0044D0B0 */
struct Spawn_00449110 {
    Vec4_00449110 a;
    Vec4_00449110 b;
    Vec4_00449110 c;
    int d[4];
    int src;
    int owner;
    float unk_0x48;
    float unk_0x4c;
};

struct Mtx_00449110 {
    float m[16];
};

extern int D_00692350;
extern int D_00692354;
extern int D_00692358;
extern int D_0069235C;

void func_004540C0(void *m, void *out);
char *func_0044D0B0(int, void *);
void func_00453750(void *, void *, void *);
void func_004536E0(void *, void *, void *);
char func_0043E9F0(void *);

extern "C" void func_00449E20(void *obj, void *a, void *b, int arg);
void *func_0042D620(int x, void *y, void *from, void *to);

char func_00449860(unsigned int *p)
{
    unsigned int n = p[0];
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        unsigned int m = p[n + 1];
        for (j = 0; j < m; j++) {
            if (*((unsigned char *)p[n + 2 + j] + 0x75) & 8)
                return 1;
        }
    }
    return 0;
}

void func_00449AA0(char *p)
{
    char *q;
    for (q = *(char **)(p + 0x88); q != 0; q = *(char **)(q + 0xa4))
        *(int *)(q + 0x94) = *(int *)(p + 0x94);
}

void func_00449CD0(int p, void *list, int c)
{
    int q = p + 0x88;
    func_0044B310(q, list, c);
}

void func_00449DE0(char *obj, int x)
{
    float box[8];

    func_00449E20(obj, &box[4], &box[0], 0);
    *(void **)(obj + 0x84) = func_0042D620(x, obj, &box[4], &box[0]);
}

