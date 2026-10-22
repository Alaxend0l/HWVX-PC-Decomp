/* 12 functions from 0x00465590 to 0x00466590, found by Ghidra. */
#include "common.h"
#include <windows.h>
#include <string.h>
#include <GL/gl.h>

struct DisplayMode {
    int id;
    int unk_4[5];
};

extern "C" char D_006C9AC0;
extern "C" DEVMODEA D_006C9AE0;
extern "C" char D_0047D11C[];
extern "C" int D_006C99FC;
extern "C" DisplayMode D_006C9A00[];
extern "C" int D_006C9A78;

extern "C" char *func_0046B970(const char *str, int ch);
extern "C" char *func_0046B1E0(const char *str1, const char *str2);

extern "C" int func_00466390(char *word, char *list)
{
    char *p;
    char *end;
    int len;

    if (func_0046B970(word, ' ') == NULL && *word != '\0') {
        for (p = func_0046B1E0(list, word); p != NULL; p = func_0046B1E0(list, word)) {
            len = strlen(word);
            end = p + len;
            if ((p == list || p[-1] == ' ') && (*end == ' ' || *end == '\0'))
                return 1;
            list = end;
        }
    }
    return 0;
}

extern "C" void func_00466410(int id)
{
    int i;

    for (i = 0; i < D_006C99FC; i++) {
        if (D_006C9A00[i].id == id)
            break;
    }
    if (i != D_006C99FC)
        D_006C9A78 = i;
}

extern "C" short func_004664C0(void)
{
    return 0;
}

extern "C" void func_00465CB0(int enable)
{
    LONG result;

    if (!D_006C9AC0)
        return;
    if (!enable) {
        ChangeDisplaySettingsA(NULL, CDS_FULLSCREEN);
        return;
    }
    result = ChangeDisplaySettingsA(&D_006C9AE0, CDS_FULLSCREEN);
    if (result != DISP_CHANGE_SUCCESSFUL)
        MessageBoxA(NULL, D_0047D11C, NULL, MB_ICONHAND);
}
