/* 16 functions from 0x0046D6D0 to 0x0046E5D3, found by Ghidra. */
#include "common.h"

struct XcptAction_0046D6D0 {
    unsigned long XcptNum;
    int SigNum;
    void *XcptAction;
};

extern "C" void *(__stdcall *_imp__GetModuleHandleA)(const char *name);
#define GetModuleHandleA (*_imp__GetModuleHandleA)
extern int D_0047D7B4;
extern int D_006D6B08;
extern unsigned char *D_006D6B14;
extern "C" void func_00472B36(void);
extern "C" int func_0047271C(unsigned int c);
extern "C" unsigned long (__stdcall *_imp__GetModuleFileNameA)(void *module, char *name, unsigned long size);
#define GetModuleFileNameA (*_imp__GetModuleFileNameA)
extern char *D_0049D808;
extern char **D_0049D834;
extern int D_006D6B04;
extern char D_0049D87C[];
extern char *D_0049D844;
extern char **D_0049D82C;
extern int D_0049D828;
extern "C" unsigned int func_00471CF0(const char *s);
extern "C" void *func_0046AED9(unsigned int size);
extern "C" void func_0046AD1F(int code);
extern "C" char *func_004718C0(char *dst, const char *src);
extern "C" void func_0046B013(void *p);
extern "C" void func_0046DF5F(char *cmdstart, char **argv, char *args, int *numargs, int *numchars);

#pragma optimize("s", on)

extern "C" XcptAction_0046D6D0 *func_0046DD7B(unsigned long xcptnum, XcptAction_0046D6D0 *table)
{
    XcptAction_0046D6D0 *p = table;

    while (p->XcptNum != xcptnum && ++p < table + D_0047D7B4)
        ;
    if (p >= table + D_0047D7B4 || p->XcptNum != xcptnum)
        return NULL;
    return p;
}

extern "C" unsigned char *func_0046DDB5(void)
{
    unsigned char *p;

    if (D_006D6B08 == 0)
        func_00472B36();
    p = D_006D6B14;
    if (*p == '"') {
        while (*++p != '"' && *p != '\0') {
            if (func_0047271C(*p))
                p++;
        }
        if (*p == '"')
            p++;
    } else {
        while (*p > ' ')
            p++;
    }
    while (*p != '\0' && *p <= ' ')
        p++;
    return p;
}

extern "C" void func_0046DE0D(void)
{
    char *p;
    char **env;
    int numstrings;
    int cchars;

    if (D_006D6B08 == 0)
        func_00472B36();
    numstrings = 0;
    for (p = D_0049D808; *p != '\0'; p += func_00471CF0(p) + 1) {
        if (*p != '=')
            numstrings++;
    }
    D_0049D834 = env = (char **)func_0046AED9((numstrings + 1) * sizeof(char *));
    if (env == NULL)
        func_0046AD1F(9);
    for (p = D_0049D808; *p != '\0'; p += cchars) {
        cchars = func_00471CF0(p) + 1;
        if (*p != '=') {
            if ((*env = (char *)func_0046AED9(cchars)) == NULL)
                func_0046AD1F(9);
            func_004718C0(*env, p);
            env++;
        }
    }
    func_0046B013(D_0049D808);
    D_0049D808 = NULL;
    *env = NULL;
    D_006D6B04 = 1;
}

extern "C" void func_0046DEC6(void)
{
    char *p;
    char *cmdstart;
    int numargs, numchars;

    if (D_006D6B08 == 0)
        func_00472B36();
    GetModuleFileNameA(NULL, D_0049D87C, 260);
    D_0049D844 = D_0049D87C;
    cmdstart = (*D_006D6B14 == '\0') ? D_0049D87C : (char *)D_006D6B14;
    func_0046DF5F(cmdstart, NULL, NULL, &numargs, &numchars);
    p = (char *)func_0046AED9(numargs * sizeof(char *) + numchars);
    if (p == NULL)
        func_0046AD1F(8);
    func_0046DF5F(cmdstart, (char **)p, p + numargs * sizeof(char *), &numargs, &numchars);
    D_0049D828 = numargs - 1;
    D_0049D82C = (char **)p;
}

extern "C" void func_0046E401(unsigned char *ver)
{
    unsigned char *base;
    int off;

    *(int *)ver = 0;
    base = (unsigned char *)GetModuleHandleA(NULL);
    if (*(unsigned short *)base == 0x5a4d && (off = *(int *)(base + 0x3c)) != 0) {
        base += off;
        ver[0] = base[0x1a];
        ver[1] = base[0x1b];
    }
}

extern "C" void *(__stdcall *_imp__HeapCreate)(unsigned long options, unsigned long initial, unsigned long maximum);
extern "C" int (__stdcall *_imp__HeapDestroy)(void *heap);
extern void *D_006D59C4;
extern int D_006D59C8;
extern "C" int func_0046E42E(void);
extern "C" int func_0046F0C8(int threshold);
extern "C" int func_0046FC0F(void);
extern "C" int func_0046E576(int mtflag)
{
    if ((D_006D59C4 = (*_imp__HeapCreate)(mtflag == 0, 0x1000, 0)) == NULL)
        return 0;
    if ((D_006D59C8 = func_0046E42E()) == 3) {
        if (!func_0046F0C8(0x3f8)) {
            (*_imp__HeapDestroy)(D_006D59C4);
            return 0;
        }
    } else if (D_006D59C8 == 2) {
        if (func_0046FC0F() == 0) {
            (*_imp__HeapDestroy)(D_006D59C4);
            return 0;
        }
    }
    return 1;
}

