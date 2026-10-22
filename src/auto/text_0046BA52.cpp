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
extern "C" char *func_0046C079(char *buf, int ndec, StrFlt_0046BA52 *flt, int g_fmt);
extern "C" char *func_0046C024(double *value, char *buf, int ndec);
extern "C" char *func_0046BF01(double *value, char *buf, int ndec, int caps);
extern "C" void func_0046C120(double *value, char *buf, int ndec, int caps);
extern "C" void *func_00471050(void *dst, int c, unsigned int n);
extern "C" char *func_0046BF62(char *buf, int ndec, int caps, StrFlt_0046BA52 *flt, int g_fmt);
extern "C" void func_0046E9BA(int lock);
extern "C" void func_0046C204(char *s, int dist);
extern "C" char *func_004718C0(char *dst, const char *src);
extern char D_004789B0[];

extern "C" void func_0046BCE6(void)
{
    func_0046E9BA(9);
}

extern "C" void func_0046BCEF(void)
{
}

extern "C" void func_004710DD(unsigned int, unsigned int);
extern "C" int func_0047120E(int c);
extern "C" int func_0047039E(int c, int mask);
extern "C" unsigned int func_00471CF0(const char *s);
extern "C" void *func_004719B0(void *dst, const void *src, unsigned int n);
extern int D_0047FC8C;
extern unsigned short *D_0047FA80;
extern char D_0047FC90[];
extern char D_0047899C[];
extern char D_00478980[];
extern "C" void *(__stdcall *_imp__GetModuleHandleA)(const char *name);
extern "C" void *(__stdcall *_imp__GetProcAddress)(void *module, const char *name);
#define GetModuleHandleA (*_imp__GetModuleHandleA)
#define GetProcAddress (*_imp__GetProcAddress)
extern "C" void func_0046BD6F(void)
{
    func_0046E9BA(9);
}

#pragma optimize("y", off)
#pragma optimize("sp", on)
#pragma optimize("g", off)
extern "C" int func_0046BD9C(void)
{
    double divisor = 3145727.0;
    double dividend = 4195835.0;
    double result;

    result = dividend - (dividend / divisor) * divisor;
    if (result > 1.0)
        return 1;
    return 0;
}

#pragma optimize("", on)
extern "C" int func_0046BDDA(void)
{
    void *kernel;
    int (__stdcall *present)(int);

    kernel = GetModuleHandleA(D_0047899C);
    if (kernel != NULL) {
        present = (int (__stdcall *)(int))GetProcAddress(kernel, D_00478980);
        if (present != NULL)
            return present(0);
    }
    return func_0046BD9C();
}

#pragma optimize("", on)
#pragma optimize("s", on)
extern "C" void func_0046BE03(char *buf)
{
    char hold, next;

    if (func_0047120E(*buf) != 'e') {
        do {
            buf++;
        } while (D_0047FC8C > 1 ? func_0047039E(*buf, 4) : D_0047FA80[*buf] & 4);
    }
    hold = *buf;
    *buf++ = *D_0047FC90;
    do {
        next = *buf;
        *buf = hold;
        hold = next;
    } while (*buf++);
}

extern "C" void func_0046BE5D(char *buf)
{
    char *stop;

    while (*buf && *buf != *D_0047FC90)
        buf++;
    if (*buf++) {
        while (*buf && *buf != 'e' && *buf != 'E')
            buf++;
        stop = buf--;
        while (*buf == '0')
            buf--;
        if (*buf == *D_0047FC90)
            buf--;
        while ((*++buf = *stop++) != '\0')
            ;
    }
}

extern "C" void func_004716DA(int *dbl, char *str);
extern "C" void func_00471707(int *flt, char *str);
extern "C" char *func_004718C0(char *dst, const char *src);
extern "C" void func_0046C204(char *s, int dist);
extern char D_004789B0[];
extern double D_004789A8;
extern "C" void func_0046BEC3(int flag, char *arg, char *number)
{
    int dbl[2];
    int flt;

    if (flag) {
        func_004716DA(dbl, number);
        ((int *)arg)[0] = dbl[0];
        ((int *)arg)[1] = dbl[1];
    } else {
        func_00471707(&flt, number);
        *(int *)arg = flt;
    }
}

extern "C" char *func_0046BF62(char *buf, int ndec, int caps, StrFlt_0046BA52 *flt, int g_fmt)
{
    char *p;
    int exp;

    if ((char)g_fmt)
        func_0046C204(buf + (flt->sign == '-'), ndec > 0);
    p = buf;
    if (flt->sign == '-')
        *p++ = '-';
    if (ndec > 0) {
        *p = *(p + 1);
        *++p = *D_0047FC90;
    }
    p = func_004718C0(p + ndec + ((char)g_fmt == 0), D_004789B0);
    if (caps)
        *p = 'E';
    p++;
    if (*flt->mantissa != '0') {
        exp = flt->decpt - 1;
        if (exp < 0) {
            exp = -exp;
            *p = '-';
        }
        p++;
        if (exp >= 100) {
            *p += (char)(exp / 100);
            exp %= 100;
        }
        p++;
        if (exp >= 10) {
            *p += (char)(exp / 10);
            exp %= 10;
        }
        *(p + 1) += (char)exp;
    }
    return buf;
}

extern "C" void func_0046C204(char *s, int dist)
{
    if (dist)
        func_004719B0(s + dist, s, func_00471CF0(s) + 1);
}

extern "C" char *func_0046C024(double *value, char *buf, int ndec)
{
    StrFlt_0046BA52 flt;
    char digits[24];

    func_004717AB(*value, &flt, digits);
    func_00471734(buf + (flt.sign == '-'), flt.decpt + ndec, &flt);
    func_0046C079(buf, ndec, &flt, 0);
    return buf;
}

extern "C" void func_0046BD78(void)
{
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

extern "C" void func_0046C1B3(double *value, char *buf, int format, int ndec, int caps)
{
    if (format == 'e' || format == 'E')
        func_0046BF01(value, buf, ndec, caps);
    else if (format == 'f')
        func_0046C024(value, buf, ndec);
    else
        func_0046C120(value, buf, ndec, caps);
}

extern "C" char *func_0046BF01(double *value, char *buf, int ndec, int caps)
{
    StrFlt_0046BA52 flt;
    char digits[24];

    func_004717AB(*value, &flt, digits);
    func_00471734(buf + (ndec > 0) + (flt.sign == '-'), ndec + 1, &flt);
    func_0046BF62(buf, ndec, caps, &flt, 0);
    return buf;
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

