/* 8 functions from 0x0046A870 to 0x0046AAEB, found by Ghidra. */
#include "common.h"
#include <stdio.h>
#include <stdarg.h>

extern "C" int func_0046C971(FILE *stream, const char *format, va_list argptr);
extern "C" int func_0046D17B(int ch, FILE *stream);
extern "C" void func_0046C816(FILE *stream);
extern "C" void func_0046C868(FILE *stream);
extern "C" int func_0046A922(FILE *stream);
extern "C" FILE *func_0046AAA7(const char *filename, const char *mode, int shflag);

#pragma optimize("s", on)
#pragma optimize("y", off)
extern "C" int func_0046A89F(char *string, const char *format, ...)
{
    FILE str;
    FILE *outfile = &str;
    va_list arglist;
    int retval;

    va_start(arglist, format);
    outfile->_flag = _IOWRT | _IOSTRG;
    outfile->_ptr = outfile->_base = string;
    outfile->_cnt = 0x7fffffff;
    retval = func_0046C971(outfile, format, arglist);
    if (--outfile->_cnt >= 0)
        *outfile->_ptr = '\0';
    else
        func_0046D17B('\0', outfile);
    return retval;
}
#pragma optimize("y", on)
extern "C" int func_0046A8F1(FILE *stream)
{
    int result = EOF;

    if (stream->_flag & _IOSTRG) {
        stream->_flag = 0;
    } else {
        func_0046C816(stream);
        result = func_0046A922(stream);
        func_0046C868(stream);
    }
    return result;
}

extern "C" FILE *func_0046AAD8(const char *filename, const char *mode)
{
    return func_0046AAA7(filename, mode, 0x40);
}

