/* 5 functions from 0x00454E70 to 0x00455BC9, found by Ghidra. */
#include "common.h"

extern "C" int func_00475660(const char *s1, const char *s2);
extern "C" char *func_0046B1E0(const char *str1, const char *str2);
extern "C" int func_0046B2EB(const char *nptr);
extern "C" int strcmp(const char *s1, const char *s2);
#pragma intrinsic(strcmp)

struct VideoMode_00454E70 {
    int width;
    int height;
    int depth;
};

extern VideoMode_00454E70 D_0047BF60[5];
extern char D_0047C1A4[];
extern char D_0047C1A0[];
extern char D_0047C19C[];
extern char D_0047C198[];
extern char D_0047C194[];
extern char D_0047C190[];
extern char D_0047C18C[];
extern char D_0047C188[];
extern char D_0047C184[];
extern char D_0047C048[];
extern char D_0047C044[];
extern char D_0068E0A4;
extern char D_0068DF04;
int D_0068DEE0;
int D_0068DEE4;
extern int D_0068DEE8;
extern unsigned int D_0068DEEC;
extern unsigned int D_0068DEF0;
extern unsigned int D_0068DEF4;
extern unsigned int D_0068DEF8;
extern unsigned int D_0068DEFC;

void func_004553B0(const char *key, const char *value)
{
    if (func_00475660(key, D_0047C1A4) == 0) {
        D_0068E0A4 = 1;
    } else if (func_00475660(key, D_0047C1A0) == 0) {
        int *mode;
        char *p;
        int height;
        int width;

        width = func_0046B2EB(value);
        height = 0;
        if ((p = func_0046B1E0(value, D_0047C048)) != NULL || (p = func_0046B1E0(value, D_0047C044)) != NULL)
            height = func_0046B2EB(p + 1);
        for (mode = &D_0047BF60[0].height; mode < &D_0047BF60[5].height; mode += 3) {
            if (mode[-1] == width && *mode == height) {
                D_0068DEE4 = height;
                D_0068DEE0 = width;
                break;
            }
        }
    } else if (func_00475660(key, D_0047C19C) == 0) {
        int depth = func_0046B2EB(value);
        if (depth == 16 || depth == 32)
            D_0068DEE8 = depth;
    } else if (func_00475660(key, D_0047C198) == 0) {
        D_0068DF04 = 0;
    } else if (strcmp(key, D_0047C194) == 0) {
        unsigned int n = func_0046B2EB(value);
        if (n < 5)
            D_0068DEF8 = n;
    } else if (strcmp(key, D_0047C190) == 0) {
        unsigned int n = func_0046B2EB(value);
        if (n < 5)
            D_0068DEF4 = n;
    } else if (strcmp(key, D_0047C18C) == 0) {
        unsigned int n = func_0046B2EB(value);
        if (n < 5)
            D_0068DEFC = n;
    } else if (strcmp(key, D_0047C188) == 0) {
        unsigned int n = func_0046B2EB(value);
        if (n < 5)
            D_0068DEF0 = n;
    } else if (strcmp(key, D_0047C184) == 0) {
        unsigned int n = func_0046B2EB(value);
        if (n < 5)
            D_0068DEEC = n;
    }
}
