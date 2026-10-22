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

extern "C" void func_0046C120(double *value, char *buf, int ndec, int caps)
{
    StrFlt_0046BA52 flt;
    char digits[24];
    char *p;
    int exp;
    int grew;

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
