/* 18 functions from 0x00459C00 to 0x0045A550, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <string.h>
#include <crtdbg.h>

extern HANDLE D_00499218;
extern IUnknown *D_00499220;
extern IUnknown *D_00499224;
extern int D_00499228;
extern int D_0049922C;
extern int D_00692998;
extern int D_006929E8;
extern char D_006929DF;
extern char D_0047C70C[];
extern int D_00499254;
typedef void (*Fn_00692994)(void);
extern Fn_00692994 D_00692994;
extern Fn_00692994 D_0069299C;
extern Fn_00692994 D_006929A0;
extern Fn_00692994 D_006929A4;
extern Fn_00692994 D_006929A8;
extern Fn_00692994 D_006929B0;
extern int D_006929C0[8];
extern Fn_00692994 D_006929E0;
extern Fn_00692994 D_006929E4;
extern Fn_00692994 D_006929EC;
extern Fn_00692994 D_006929F0;

void func_0044A5A0(void);
void func_0045A090(void);

struct Voice_00459C00 {
    char unk_0x00[4];
    Voice_00459C00 *next;
    char unk_0x08[0x34 - 0x08];
    int unk_0x34;
};

struct Chan_00499260 {
    Voice_00459C00 *head;
    char flags;
    char unk_0x05[0x14 - 0x05];
    int unk_0x14;
    int unk_0x18;
    unsigned char unk_0x1c;
    unsigned char unk_0x1d;
    char unk_0x1e[2];
};

extern int D_00499230[9];
extern int D_00499250;
extern Chan_00499260 D_00499260[16];
extern char D_00499A60;
extern unsigned int D_00499234;
extern int D_0049923C;
extern unsigned int D_00499240;
extern unsigned char D_0049924E;
extern char D_0049924F;
extern unsigned int D_00692990;
extern unsigned int D_006929AC;

struct Mode_00499660 {
    int unk_0x0;
    char unk_0x4;
    char unk_0x5;
    char unk_0x6[2];
};

extern Mode_00499660 D_00499660[];

void func_0045AFE0(Chan_00499260 *);
extern char D_0047C02C[];
extern char D_0047C730[];
extern char D_0047C750[];

int func_00452FB0(const char *, const char *, int, int, int);
void func_0045A130(int);
void func_0045DF10(int);
void func_0045AF50(Chan_00499260 *);
void func_0045DC20(Voice_00459C00 *, int);
void func_0045DD10(Voice_00459C00 *);
int func_0045DF60(int, int);

void func_00459BA0(void);
char func_00459B10(char);

char func_00459C00(void)
{
    if (D_00499218 == NULL)
        D_00499218 = CreateMutexA(NULL, FALSE, D_0047C70C);
    timeSetEvent(3, 5, (LPTIMECALLBACK)func_00459BA0, 0, TIME_PERIODIC);
    return 1;
}

unsigned int __fastcall func_00459CB0(unsigned int a, unsigned int b)
{
    return (unsigned int)(((unsigned __int64)a * b) >> 16);
}

char func_00459CC0(void)
{
    D_00692998 = 0x7fff;
    D_0049922C = 0x7fff;
    D_00499228 = 0x7fff;
    D_006929E8 = 0;
    D_006929DF = 0;
    return 1;
}

char func_00459CF0(void)
{
    int i;

    D_006929A0 = func_0044A5A0;
    D_00692994 = func_0044A5A0;
    D_0069299C = func_0044A5A0;
    D_006929EC = func_0044A5A0;
    D_006929A8 = func_0044A5A0;
    D_006929E4 = func_0044A5A0;
    D_006929B0 = func_0044A5A0;
    D_006929A4 = func_0044A5A0;
    D_006929E0 = func_0044A5A0;
    D_006929F0 = func_0044A5A0;
    for (i = 0; i < 8; i++)
        D_006929C0[i] = 0;
    return 1;
}

void func_00459D40(int a)
{
    D_0049922C = a;
    D_00692998 = (unsigned int)(D_00499228 * a) >> 15;
    D_0069299C();
}

void func_00459D70(int a)
{
    D_00499228 = a;
    D_00692998 = (unsigned int)(D_0049922C * a) >> 15;
    D_0069299C();
}

char func_00459EC0(void)
{
    int *p;
    int n;

    for (p = D_00499230, n = 9; n != 0; n--)
        *p++ = 0;
    for (p = (int *)D_00499260, n = 0x80; n != 0; n--)
        *p++ = 0;
    D_00499254 = 0;
    return 1;
}

char func_00459EF0(void)
{
    if (D_00499254)
        func_0045A090();
    return 1;
}

void func_0045A090(void)
{
    if (D_00499254 == 0)
        return;
    if (!func_00459B10(1)) {
        if (func_00452FB0(D_0047C02C, D_0047C730, 0x155, 0, 0))
            _CrtDbgBreak();
        return;
    }
    if (D_00499A60 != 1 && func_00452FB0(D_0047C750, D_0047C730, 0x158, 0, 0))
        _CrtDbgBreak();
    func_0045A130(3);
    func_0045DF10(D_00499254);
    D_00499254 = 0;
    memset(D_006929C0, 0, sizeof(D_006929C0));
    D_00499A60 = 0;
    func_00459B10(0);
}

void func_0045A370(void)
{
    int i;
    Chan_00499260 *c;
    Voice_00459C00 *v;

    c = D_00499260;
    for (i = 0; i < 16; i++, c++) {
        func_0045AF50(c);
        for (v = c->head; v != NULL; v = v->next)
            func_0045DC20(v, c->unk_0x14);
    }
}

void func_0045A3B0(int vol)
{
    int i;
    Chan_00499260 *c;
    Voice_00459C00 *v;

    D_00499250 = vol;
    c = D_00499260;
    for (i = 0; i < 16; i++, c++) {
        c->unk_0x18 = func_00459CB0(func_0045DF60(c->unk_0x1d, c->unk_0x1c), vol);
        for (v = c->head; v != NULL; v = v->next) {
            v->unk_0x34 = c->unk_0x18;
            func_0045DD10(v);
        }
    }
}

void func_00459C40(void)
{
    HANDLE h;

    if ((h = D_00499218) != NULL) {
        func_00459B10(1);
        D_00499218 = NULL;
        ReleaseMutex(h);
        CloseHandle(h);
    }
    if (D_00499224) {
        D_00499224->Release();
        D_00499224 = NULL;
    }
    if (D_00499220) {
        D_00499220->Release();
        D_00499220 = NULL;
    }
}

