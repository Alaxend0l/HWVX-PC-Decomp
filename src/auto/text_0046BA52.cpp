/* 20 functions from 0x0046BA52 to 0x0046C229, found by Ghidra. */
#include "common.h"

struct StrFlt_0046BA52 {
    int sign;
    int decpt;
    int flag;
    char *mantissa;
};

extern "C" StrFlt_0046BA52 *func_004717AB(double value, StrFlt_0046BA52 *flt, char *buf);
extern "C" int func_00471734(char *buf, int digits, StrFlt_0046BA52 *flt);
extern "C" void func_0046C079(char *buf, int ndec, StrFlt_0046BA52 *flt, int g_fmt);
extern "C" void func_0046BF62(char *buf, int ndec, int caps, StrFlt_0046BA52 *flt, int g_fmt);
extern "C" void func_0046E9BA(int lock);

extern "C" void func_0046BCE6(void)
{
    func_0046E9BA(9);
}

extern "C" void func_004710DD(unsigned int, unsigned int);
extern "C" void func_0046BD6F(void)
{
    func_0046E9BA(9);
}

#pragma optimize("s", on)
extern "C" void func_0046BD8A(void)
{
    func_004710DD(0x10000, 0x30000);
}
extern "C" void func_0046C120(double *value, char *buf, int ndec, int caps)
{
    StrFlt_0046BA52 flt;
    char digits[24];
    char *p;
    int exp;
    char grew;

    func_004717AB(*value, &flt, digits);
    exp = flt.decpt - 1;
    p = buf + (flt.sign == '-');
    func_00471734(p, ndec, &flt);
    grew = exp < flt.decpt - 1;
    exp = flt.decpt - 1;
    if (exp < -4 || exp >= ndec) {
        func_0046BF62(buf, ndec, caps, &flt, 1);
    } else {
        if (grew) {
            while (*p++)
                ;
            *(p - 2) = '\0';
        }
        func_0046C079(buf, ndec, &flt, 1);
    }
}

#pragma optimize("sy", off)
#pragma optimize("s", on)
extern "C" void func_0046E959(int lock);
extern "C" void *func_0046F464(unsigned int size);
extern "C" void *func_0046FF07(unsigned int paras);
extern "C" void *func_00471050(void *dst, int c, unsigned int n);
extern "C" int func_0046F0AD(unsigned int size);
extern int D_006D59C8;
extern unsigned int D_006D59C0;
extern unsigned int D_0047FA7C;
extern void *D_006D59C4;
extern int D_0049D9E8;
extern "C" __declspec(dllimport) void *__stdcall HeapAlloc(void *heap, unsigned long flags, unsigned long size);
extern "C" void *func_0046BC4D(unsigned int num, unsigned int size)
{
    unsigned int total = num * size;
    void *p;

    size = total;
    if (size <= 0xffffffe0) {
        if (size == 0)
            size = 1;
        size = (size + 15) & ~15;
    }
    for (;;) {
        p = NULL;
        if (size <= 0xffffffe0) {
            if (D_006D59C8 == 3) {
                if (total <= D_006D59C0) {
                    func_0046E959(9);
                    __try {
                        p = func_0046F464(total);
                    } __finally {
                        func_0046E9BA(9);
                    }
                    if (p != NULL)
                        func_00471050(p, 0, total);
                }
            } else if (D_006D59C8 == 2 && size <= D_0047FA7C) {
                func_0046E959(9);
                __try {
                    p = func_0046FF07(size >> 4);
                } __finally {
                    func_0046E9BA(9);
                }
                if (p != NULL)
                    func_00471050(p, 0, size);
            }
            if (p != NULL)
                return p;
            p = HeapAlloc(D_006D59C4, 8, size);
        }
        if (p != NULL || D_0049D9E8 == 0)
            return p;
        if (!func_0046F0AD(size))
            return NULL;
    }
}

