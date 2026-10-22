/* 14 functions from 0x0046F464 to 0x00470413, found by Ghidra. */
#include "common.h"
#include <windows.h>

/* The original's import slots are named without the @N decoration. */
extern "C" LPVOID (__stdcall *_imp__HeapAlloc)(HANDLE, DWORD, SIZE_T);
extern "C" LPVOID (__stdcall *_imp__HeapReAlloc)(HANDLE, DWORD, LPVOID, SIZE_T);
extern "C" BOOL (__stdcall *_imp__HeapFree)(HANDLE, DWORD, LPVOID);
extern "C" LPVOID (__stdcall *_imp__VirtualAlloc)(LPVOID, SIZE_T, DWORD, DWORD);
extern "C" BOOL (__stdcall *_imp__VirtualFree)(LPVOID, SIZE_T, DWORD);
#define HeapAlloc (*_imp__HeapAlloc)
#define HeapReAlloc (*_imp__HeapReAlloc)
#define HeapFree (*_imp__HeapFree)
#define VirtualAlloc (*_imp__VirtualAlloc)
#define VirtualFree (*_imp__VirtualFree)

struct Entry_0046F464 {
    int unk_0x0;
    int unk_0x4;
};

struct Region_0046F464 {
    Region_0046F464 *unk_0x0;
    Region_0046F464 *unk_0x4;
    int unk_0x8;
    Entry_0046F464 *unk_0xc;
    char *unk_0x10;
    char *unk_0x14;
    Entry_0046F464 unk_0x18[0x400];
};

struct Page_0046F464 {
    unsigned char *unk_0x0;
    int unk_0x4;
    unsigned char unk_0x8[0xf0];
    unsigned char unk_0xf8[0x1000 - 0xf8];
};

struct Header_0046F464 {
    int unk_0x0;
    int unk_0x4;
    int unk_0x8;
    void *unk_0xc;
    int *unk_0x10;
};

extern "C" HANDLE D_006D59C4;
extern "C" int D_006D59A8;
extern "C" int D_006D59B8;
extern "C" Header_0046F464 *D_006D59BC;
extern "C" int D_0049D9F0;
extern "C" Region_0046F464 D_0047DA58;
extern "C" Region_0046F464 *D_0047DA5C;
extern "C" int D_0047DA68;
extern "C" Region_0046F464 *D_0047FA78;

extern "C" void func_0046FD53(Region_0046F464 *);
extern "C" void func_0046FDA9(int);

#pragma optimize("s", on)

extern "C" Header_0046F464 *func_0046F76D(void)
{
    Header_0046F464 *h;
    void *p;

    if (D_006D59B8 == D_006D59A8) {
        p = HeapReAlloc(D_006D59C4, 0, D_006D59BC, (D_006D59A8 + 0x10) * sizeof(Header_0046F464));
        if (p == NULL)
            return NULL;
        D_006D59A8 += 0x10;
        D_006D59BC = (Header_0046F464 *)p;
    }
    h = D_006D59BC + D_006D59B8;
    if ((h->unk_0x10 = (int *)HeapAlloc(D_006D59C4, HEAP_ZERO_MEMORY, 0x41c4)) == NULL)
        return NULL;
    if ((h->unk_0xc = VirtualAlloc(NULL, 0x100000, MEM_RESERVE, PAGE_READWRITE)) == NULL) {
        HeapFree(D_006D59C4, 0, h->unk_0x10);
        return NULL;
    }
    h->unk_0x8 = -1;
    h->unk_0x0 = 0;
    h->unk_0x4 = 0;
    D_006D59B8++;
    *h->unk_0x10 = -1;
    return h;
}

extern "C" void func_0046FD53(Region_0046F464 *r)
{
    VirtualFree(r->unk_0x10, 0, MEM_RELEASE);
    if (D_0047FA78 == r)
        D_0047FA78 = r->unk_0x4;
    if (r != &D_0047DA58) {
        r->unk_0x4->unk_0x0 = r->unk_0x0;
        r->unk_0x0->unk_0x4 = r->unk_0x4;
        HeapFree(D_006D59C4, 0, r);
    } else {
        D_0047DA68 = -1;
    }
}

extern "C" void func_0046FDA9(int n)
{
    Region_0046F464 *r = D_0047DA5C;
    Region_0046F464 *cur;
    Entry_0046F464 *e;
    int off;
    int freed;
    int i;

    do {
        if (r->unk_0x10 != (char *)-1) {
            freed = 0;
            e = &r->unk_0x18[0x3ff];
            off = 0x3ff000;
            do {
                if (e->unk_0x0 == 0xf0 && VirtualFree(r->unk_0x10 + off, 0x1000, MEM_DECOMMIT)) {
                    e->unk_0x0 = -1;
                    D_0049D9F0--;
                    if (r->unk_0xc == NULL || r->unk_0xc > e)
                        r->unk_0xc = e;
                    freed++;
                    if (--n == 0)
                        break;
                }
                off -= 0x1000;
                e--;
            } while (off >= 0);
            cur = r;
            r = r->unk_0x4;
            if (freed && cur->unk_0x18[0].unk_0x0 == -1) {
                for (i = 1; i < 0x400; i++)
                    if (cur->unk_0x18[i].unk_0x0 != -1)
                        break;
                if (i == 0x400)
                    func_0046FD53(cur);
            }
        }
    } while (r != D_0047DA5C && n > 0);
}

extern "C" unsigned char *func_0046FE6B(char *p, Region_0046F464 **pr, Page_0046F464 **pp)
{
    Region_0046F464 *r = &D_0047DA58;
    Page_0046F464 *pg;

    while (p <= r->unk_0x10 || p >= r->unk_0x14) {
        r = r->unk_0x0;
        if (r == &D_0047DA58)
            return NULL;
    }
    if ((unsigned int)p & 0xf)
        return NULL;
    if (((unsigned int)p & 0xfff) < 0x100)
        return NULL;
    *pr = r;
    pg = (Page_0046F464 *)((unsigned int)p & ~0xfff);
    *pp = pg;
    return (unsigned char *)pg + 8 + ((p - (char *)pg - 0x100) >> 4);
}

extern "C" void func_0046FEC2(Region_0046F464 *r, char *page, unsigned char *hdr)
{
    Entry_0046F464 *e = &r->unk_0x18[(page - r->unk_0x10) >> 12];
    e->unk_0x0 += *hdr;
    *hdr = 0;
    e->unk_0x4 = 0xf1;
    if (e->unk_0x0 == 0xf0 && ++D_0049D9F0 == 0x20)
        func_0046FDA9(0x10);
}
