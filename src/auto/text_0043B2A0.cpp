/* 30 functions from 0x0043B2A0 to 0x0043BF20, found by Ghidra. */
#include "common.h"

struct Bink_0048D64C {
    char unk_0x00[0x8];
    unsigned unk_0x08;
    unsigned unk_0x0c;
    char unk_0x10[0x34 - 0x10];
    char unk_0x34[4];
};

struct BinkBuf_0048D650 {
    char unk_0x00[0x4];
    int unk_0x04;
    char unk_0x08[0x10 - 0x08];
    int unk_0x10;
    int unk_0x14;
    int unk_0x18;
};

struct Elem_0043B460 {
    char unk_0x00[0x60];
};

struct List_0043B460 {
    Elem_0043B460 *items;
    unsigned count;
};

extern Bink_0048D64C *D_0048D64C;
extern BinkBuf_0048D650 *D_0048D650;
extern char D_0048D760;
extern List_0043B460 *D_0048D768;
extern void **D_0048D76C;
extern char D_0047B020[];

/* binkw32.dll imports by ordinal: the import table slots are named __imp__binkw32_N */
extern "C" int (__stdcall *_imp__binkw32_0)(Bink_0048D64C *);
extern "C" int (__stdcall *_imp__binkw32_3)(BinkBuf_0048D650 *);
extern "C" int (__stdcall *_imp__binkw32_4)(Bink_0048D64C *, int, int, int, int, int, int);
extern "C" int (__stdcall *_imp__binkw32_5)(BinkBuf_0048D650 *);
extern "C" int (__stdcall *_imp__binkw32_6)(Bink_0048D64C *, int);
extern "C" int (__stdcall *_imp__binkw32_7)(BinkBuf_0048D650 *, void *, int);
extern "C" void (__stdcall *_imp__binkw32_8)(Bink_0048D64C *);
extern "C" void (__stdcall *_imp__binkw32_10)(Bink_0048D64C *);
#define binkw32_0 (*_imp__binkw32_0)
#define binkw32_3 (*_imp__binkw32_3)
#define binkw32_4 (*_imp__binkw32_4)
#define binkw32_5 (*_imp__binkw32_5)
#define binkw32_6 (*_imp__binkw32_6)
#define binkw32_7 (*_imp__binkw32_7)
#define binkw32_8 (*_imp__binkw32_8)
#define binkw32_10 (*_imp__binkw32_10)

extern "C" void *func_00454B80(unsigned size, int tag, const char *file);
extern "C" void *func_0042D620(int type, unsigned index, void *a, void *b);

extern "C" char func_0043B2A0(void)
{
    if (D_0048D64C && D_0048D64C->unk_0x0c != D_0048D64C->unk_0x08 - 1) {
        binkw32_8(D_0048D64C);
        if (!binkw32_0(D_0048D64C))
            binkw32_10(D_0048D64C);
        return 1;
    }
    return 0;
}

extern "C" void func_0043B2E0(void)
{
    if (D_0048D64C && D_0048D650) {
        if (binkw32_3(D_0048D650)) {
            binkw32_4(D_0048D64C, D_0048D650->unk_0x14, D_0048D650->unk_0x18, D_0048D650->unk_0x04, 0, 0, D_0048D650->unk_0x10);
            binkw32_5(D_0048D650);
        }
        binkw32_7(D_0048D650, D_0048D64C->unk_0x34, binkw32_6(D_0048D64C, D_0048D650->unk_0x10));
    }
}

extern "C" void func_0043B460(List_0043B460 *list)
{
    unsigned i;

    D_0048D768 = list;
    D_0048D76C = 0;
    if (list->count)
        D_0048D76C = (void **)func_00454B80(list->count * 4, 0x57, D_0047B020);
    for (i = 0; i < D_0048D768->count; i++)
        D_0048D76C[i] = func_0042D620(5, i, &D_0048D768->items[i], &D_0048D768->items[i]);
}

extern "C" void func_0043B8F0(void)
{
    D_0048D760 = 1;
}
