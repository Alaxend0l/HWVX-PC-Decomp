/* 8 functions from 0x00475660 to 0x00475DB6, found by Ghidra. */
#include "common.h"
#include <windows.h>

extern "C" unsigned int func_00471CF0(const char *);
extern "C" void *func_0046AED9(unsigned int);
extern "C" char *func_004718C0(char *, const char *);
extern "C" int func_004755A7(const char *, const char *, unsigned int);
extern "C" char *func_0046B970(const char *, int);
extern "C" void func_0046E959(int);
extern "C" void func_0046E9BA(int);
extern "C" void func_0046AD1F(int);
extern "C" char *func_00475D8B(const char *);
extern "C" char **D_0049D834;
extern "C" int D_006D579C;
extern "C" unsigned char D_006D58A1[];
extern "C" char **D_0049D838;
extern "C" int D_0049DB84;
extern "C" int D_0049DB00;
extern "C" int func_00474581(const char *, int);
extern "C" wchar_t **D_0049D83C;
extern "C" int func_004755E6(void);
extern "C" void func_0046B013(void *);
extern "C" void *func_00470498(void *, unsigned int);
extern "C" int func_00475C35(const char *, unsigned int);
extern "C" char **func_00475C8D(char **);
extern "C" unsigned char *func_00475CF4(const unsigned char *, unsigned int);

#pragma optimize("s", on)

#pragma optimize("y", off)
extern "C" unsigned char *func_00475CF4(const unsigned char *string, unsigned int c)
{
    unsigned short cc;

    if (D_006D579C == 0)
        return (unsigned char *)func_0046B970((const char *)string, c);

    func_0046E959(0x19);
    for (; (cc = *string); string++) {
        if (D_006D58A1[(unsigned char)cc] & 4) {
            if (*++string == '\0') {
                func_0046E9BA(0x19);
                return NULL;
            }
            if (c == (unsigned int)((cc << 8) | *string)) {
                func_0046E9BA(0x19);
                return (unsigned char *)(string - 1);
            }
        }
        else if (c == (unsigned int)cc)
            break;
    }
    func_0046E9BA(0x19);
    return (c == (unsigned int)cc) ? (unsigned char *)string : NULL;
}
#pragma optimize("", on)
#pragma optimize("s", on)

extern "C" char **func_00475C8D(char **oldenv)
{
    char **oldenvptr = oldenv;
    char **newenv, **newenvptr;
    int cvars = 0;

    if (oldenv == NULL)
        return NULL;

    while (*oldenvptr++)
        cvars++;

    if (!(newenv = newenvptr = (char **)func_0046AED9((cvars + 1) * sizeof(char *))))
        func_0046AD1F(9);

    for (oldenvptr = oldenv; *oldenvptr; )
        *newenvptr++ = func_00475D8B(*oldenvptr++);

    *newenvptr = NULL;
    return newenv;
}

extern "C" int func_00475C35(const char *option, unsigned int length)
{
    char **env;

    for (env = D_0049D834; *env != NULL; env++) {
        if (func_004755A7(option, *env, length) == 0
            && (*(*env + length) == '=' || *(*env + length) == '\0'))
            return env - D_0049D834;
    }
    return -(env - D_0049D834);
}

extern "C" char *func_00475D8B(const char *str)
{
    char *copy;

    if (str == NULL)
        return NULL;
    if ((copy = (char *)func_0046AED9(func_00471CF0(str) + 1)) != NULL)
        return func_004718C0(copy, str);
    return NULL;
}

#pragma optimize("y", off)
extern "C" int func_00475AAE(const char *option, const int primary)
{
    int ix;
    int remove;
    char **env;
    char *name, *value;
    const char *equal;

    if (option == NULL || (equal = (const char *)func_00475CF4((const unsigned char *)option, '=')) == NULL
        || option == equal)
        return -1;

    remove = (*(equal + 1) == '\0');

    if (D_0049D834 == D_0049D838)
        D_0049D834 = func_00475C8D(D_0049D834);

    if (D_0049D834 == NULL) {
        if (primary && D_0049D83C) {
            if (func_004755E6() != 0)
                return -1;
        }
        else {
            if (remove)
                return 0;
            else {
                if ((D_0049D834 = (char **)func_0046AED9(sizeof(char *))) == NULL)
                    return -1;
                *D_0049D834 = NULL;
                if (D_0049D83C == NULL) {
                    if ((D_0049D83C = (wchar_t **)func_0046AED9(sizeof(wchar_t *))) == NULL)
                        return -1;
                    *D_0049D83C = NULL;
                }
            }
        }
    }

    env = D_0049D834;
    ix = func_00475C35(option, equal - option);

    if (ix >= 0 && *env != NULL) {
        if (remove) {
            func_0046B013(env[ix]);
            for (; env[ix] != NULL; ++ix)
                env[ix] = env[ix + 1];
            if ((env = (char **)func_00470498(env, ix * sizeof(char *))) != NULL)
                D_0049D834 = env;
        }
        else {
            env[ix] = (char *)option;
        }
    }
    else {
        if (!remove) {
            if (ix < 0)
                ix = -ix;
            if ((env = (char **)func_00470498(env, sizeof(char *) * (ix + 2))) == NULL)
                return -1;
            env[ix] = (char *)option;
            env[ix + 1] = NULL;
            D_0049D834 = env;
        }
        else
            return 0;
    }

    if (primary) {
        if ((name = (char *)func_0046AED9(func_00471CF0(option) + 2)) != NULL) {
            func_004718C0(name, option);
            value = name + (equal - option);
            *value++ = '\0';
            SetEnvironmentVariableA(name, remove ? NULL : value);
            func_0046B013(name);
        }
    }
    return 0;
}
#pragma optimize("", on)
#pragma optimize("s", on)

