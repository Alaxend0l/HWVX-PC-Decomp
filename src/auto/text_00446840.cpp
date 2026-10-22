/* 1 function from 0x00446840 to 0x00447390, found by Ghidra. */
#include "common.h"

struct Item_00446840 {
    char unk_0x0[0x1c];
    int unk_0x1c;
    char unk_0x20[0x10];
    unsigned short unk_0x30;
    char unk_0x32[4];
    unsigned char unk_0x36;
    unsigned char unk_0x37;
    char unk_0x38[8];
};

struct Group_00446840 {
    char unk_0x0[0x14];
    unsigned int count;
    Item_00446840 *items;
};

struct Node_00446840 {
    char unk_0x0[0x1c];
    int unk_0x1c;
    unsigned int count;
    int *ids;
    char unk_0x28[8];
    Group_00446840 *group;
    char unk_0x34[0x1c];
};

struct Car_00446840 {
    char unk_0x0[0x24];
    int unk_0x24;
    char unk_0x28[8];
    unsigned int unk_0x30;
    char unk_0x34;
    unsigned char unk_0x35;
    char unk_0x36;
    unsigned char unk_0x37;
    char unk_0x38[0x18];
    int unk_0x50;
    int unk_0x54;
    char unk_0x58[5];
    unsigned char unk_0x5d;
    unsigned char unk_0x5e;
    char unk_0x5f;
};

struct Names_00446840 {
    char unk_0x0[0xa0];
    int unk_0xa0;
    int unk_0xa4;
};

struct Track_00446840 {
    int unk_0x0;
    int unk_0x4;
    unsigned int ncars;
    Car_00446840 *cars;
    char unk_0x10[0x10];
    unsigned int nnodes;
    Node_00446840 *nodes;
    char unk_0x28[0x54];
    int unk_0x7c;
    int unk_0x80;
    int unk_0x84;
    int unk_0x88;
    char unk_0x8c[0x10];
    Names_00446840 *names;
};

struct Cfg_00446840 {
    char unk_0x0;
    char unk_0x1[0xf];
    int unk_0x10;
};

extern int D_0048D940;
extern int D_0047B3F0;
extern int D_00496E18;
extern char D_0047B52C[];
extern char D_0047B504[];
extern char D_0047B4DC[];
extern char D_0047B4B0[];
extern char D_0047B48C[];
extern char D_0047B468[];
extern char D_0047B440[];
extern char D_0049DBB4;
extern int D_0048D8F8;
extern int *D_0049DBA8;
extern Track_00446840 *D_0049DBA0;
extern int D_0049DBB0;
extern int **D_0049DBAC;
extern unsigned int D_0048D908;
extern unsigned int D_0048D948;
extern Car_00446840 *D_0048D944;
extern Node_00446840 *D_0048D830[];
extern unsigned int D_0048D900;
extern char D_0048D910;
extern int D_0048D8FC;
extern int D_0048D904;
extern char D_0048D93D;

extern "C" void func_004420E0(void);
extern "C" void func_00452F70(const char *fmt, ...);
extern "C" int func_004287E0(int name, int a, int b, int c);
extern "C" int func_004289E0(int name, int a, int b);
extern "C" int func_00428C10(int a, int b, int c);
extern "C" bool func_00427760(void);
extern "C" void func_00427840(void);
extern "C" unsigned int func_00427770(void);
extern "C" bool func_0040A170(int a, Car_00446840 *car);
extern "C" void func_00428360(Node_00446840 **list, unsigned int count, bool flag);
extern "C" Cfg_00446840 *func_00429EC0(void);
extern "C" void func_00421400(int a);
extern "C" int func_0042A680(int a, int b);
extern "C" int func_00454A70(int a, int b);
extern "C" int func_00429EA0(void);
extern "C" bool func_0042AFB0(int a);
extern "C" int func_004216C0(int a, int b);
extern "C" void func_00452030(void);
extern "C" void func_00452040(void);

extern "C" int func_00446840(int name, int arg)
{
    Track_00446840 *t;
    Cfg_00446840 *cfg;
    unsigned int i, j;
    int r;

    switch (D_0048D940) {
    case 0:
        if (D_0047B3F0 != 0) {
            func_004420E0();
            D_0049DBB4 = 1;
            func_00452F70(D_0047B52C, D_00496E18);
            D_0048D8F8 = func_004287E0(name, 4, 0, arg);
            D_0047B3F0 = D_0048D940;
        }
        if (!func_00427760()) {
            if ((D_0049DBA8 = (int *)func_00428C10(D_0048D8F8, 4, 0)) == NULL)
                return 8;
            if ((D_0049DBA0 = (Track_00446840 *)*D_0049DBA8) == NULL)
                return 8;
            D_0048D940 = 1;
        }
        break;

    case 1:
        if (D_0047B3F0 != 1) {
            func_00452F70(D_0047B504, D_00496E18);
            D_0048D8F8 = func_004287E0(D_0049DBA0->unk_0x84, 6, D_0049DBA0->unk_0x88, arg);
            D_0047B3F0 = D_0048D940;
        }
        if (!func_00427760()) {
            if ((D_0049DBB0 = func_00428C10(D_0048D8F8, 6, 0)) == 0)
                return 8;
            D_0048D940 = 2;
        }
        break;

    case 2:
        if (D_0047B3F0 != 2) {
            func_00452F70(D_0047B4DC, D_00496E18);
            D_0048D8F8 = func_004287E0(D_0049DBA0->unk_0x7c, 5, D_0049DBA0->unk_0x80, arg);
            D_0047B3F0 = D_0048D940;
        }
        if (!func_00427760()) {
            if ((D_0049DBAC = (int **)func_00428C10(D_0048D8F8, 5, 0)) == NULL)
                return 8;
            if ((*D_0049DBAC)[0x24 / 4] != 0xd)
                return 8;
            func_00427840();
            D_0048D940 = 4;
        }
        break;

    case 3:
        if (D_0047B3F0 != 3) {
            unsigned int n;

            D_0047B3F0 = 3;
            func_00427840();
            D_0048D908 = 0;
            D_0048D948 = 0;
            func_00452F70(D_0047B4B0, D_00496E18);
            t = D_0049DBA0;
            D_0048D944 = NULL;
            for (i = 0; i < t->ncars; i++) {
                if (t->cars[i].unk_0x35 == 1) {
                    D_0048D944 = &t->cars[i];
                    break;
                }
            }
            n = t->nnodes;
            if (func_00427770() >= n) {
                for (i = 0; i < t->nnodes; i++)
                    D_0048D830[D_0048D948++] = &D_0049DBA0->nodes[i];
            } else {
                for (i = 0; i < n; i++) {
                    Node_00446840 *node = &D_0049DBA0->nodes[i];
                    if (node->unk_0x1c == 0) {
                        D_0048D830[D_0048D948++] = node;
                    } else if (D_0048D944 != NULL && func_0040A170(node->unk_0x1c, D_0048D944)) {
                        t = D_0049DBA0;
                        node = &t->nodes[i];
                        D_0048D830[D_0048D948++] = node;
                        for (j = 0; j < node->count; j++)
                            D_0048D830[D_0048D948++] = &t->nodes[node->ids[j]];
                        break;
                    }
                    n = D_0049DBA0->nnodes;
                }
            }
        }
        if (!func_00427760()) {
            if (D_0048D908 < D_0048D948) {
                func_00428360(&D_0048D830[D_0048D908++], 1, 1);
            } else {
                func_00427840();
                D_0048D940 = 4;
            }
        }
        break;

    case 4:
        if (D_0047B3F0 != 4) {
            D_0047B3F0 = 4;
            D_0048D908 = 0;
            D_0048D948 = 0;
            D_0048D8F8 = -1;
            if (D_0049DBA0->ncars == 0 || D_0049DBA0->cars[0].unk_0x24 != 0)
                return D_0048D940 = 5;
            func_00452F70(D_0047B48C, D_00496E18);
        }
        if (!func_00427760()) {
            switch (D_0048D908) {
            case 0:
                cfg = func_00429EC0();
                if (cfg == NULL || cfg->unk_0x10 == 0) {
                    D_0048D908++;
                    break;
                }
                if (D_0048D8F8 == -1) {
                    D_0048D8F8 = func_004287E0(cfg->unk_0x10, 8, 1, arg);
                    break;
                }
                func_00428C10(D_0048D8F8, 8, 1);
                D_0048D908++;
                D_0048D8F8 = -1;
                break;
            case 1:
                return D_0048D940 = 5;
            default:
                D_0048D908++;
                break;
            }
        }
        break;

    case 5:
        if (D_0047B3F0 != 5) {
            cfg = func_00429EC0();
            D_0048D900 = 0;
            D_0048D908 = 0;
            D_0048D910 = 1;
            D_0047B3F0 = D_0048D940;
            func_00421400((int)D_0049DBA8);
            func_00421400(D_0049DBB0);
            func_00421400((int)D_0049DBAC);
            func_00452F70(D_0047B468, D_00496E18);
            if (cfg != NULL && D_0049DBA0->names->unk_0xa4 != 0 && cfg->unk_0x0 == 0)
                D_0048D8F8 = func_004287E0(D_0049DBA0->names->unk_0xa4, 8, 3, 0);
        }
        if (func_00427760())
            break;
        t = D_0049DBA0;
        if (D_0048D900 < t->nnodes) {
            Group_00446840 *g = t->nodes[D_0048D900].group;
            Item_00446840 *it;

            if (D_0048D908 < g->count) {
                if (D_0048D910) {
                    int nm;
                    unsigned int v;

                    it = &g->items[D_0048D908++];
                    if (it->unk_0x1c != 0)
                        break;
                    nm = t->names->unk_0xa4;
                    v = it->unk_0x30;
                    switch (func_0042A680(0x134, 0)) {
                    case 0:
                        it->unk_0x30 = 0xffff;
                        return D_0048D940;
                    case 1:
                        if (v == 0xffff)
                            v = func_00454A70(it->unk_0x36, it->unk_0x37 + 1);
                        if (func_00429EA0() == 0 && v == 3 && func_0042AFB0(8))
                            v = 0x4d;
                        break;
                    case 2:
                        v = func_00454A70(it->unk_0x36, it->unk_0x37 + 1);
                        if (func_00429EA0() == 0 && v == 3 && func_0042AFB0(8))
                            v = 0x4d;
                        break;
                    default:
                        return D_0048D940;
                    }
                    it->unk_0x30 = v;
                    func_004287E0(nm, 2, v, arg);
                } else {
                    unsigned int v;

                    it = &g->items[D_0048D908++];
                    if (it->unk_0x1c != 0)
                        break;
                    if (it->unk_0x30 == 0xffff)
                        break;
                    v = it->unk_0x30;
                    r = func_004289E0(t->names->unk_0xa4, 2, v);
                    r = func_00428C10(r, 2, 1);
                    if (r == 0)
                        return 8;
                    it->unk_0x1c = func_004216C0(r, v);
                }
            } else {
                D_0048D900++;
                D_0048D908 = 0;
            }
            break;
        }
        if (D_0048D910) {
            D_0048D900 = 0;
            D_0048D908 = 0;
            D_0048D910 = 0;
            break;
        }
        for (i = 0; i < D_0049DBA0->ncars; i++) {
            Car_00446840 *c = &D_0049DBA0->cars[i];
            if (c->unk_0x5d != 0xff && c->unk_0x50 == 0) {
                D_0048D8F8 = func_004287E0(D_0049DBA0->names->unk_0xa4, 2, c->unk_0x5d, 0);
                r = func_00428C10(D_0048D8F8, 2, 1);
                if (r == 0)
                    return 8;
                c->unk_0x50 = func_004216C0(r, c->unk_0x5d);
            }
            if (c->unk_0x5e != 0xff && c->unk_0x54 == 0) {
                D_0048D8F8 = func_004287E0(D_0049DBA0->names->unk_0xa4, 2, c->unk_0x5e, 0);
                r = func_00428C10(D_0048D8F8, 2, 1);
                if (r == 0)
                    return 8;
                c->unk_0x54 = func_004216C0(r, c->unk_0x5e);
            }
            if (c->unk_0x35 <= 4) {
                int id = func_0042A680(0xcc, c->unk_0x35);
                if (id != -1) {
                    r = func_004287E0(D_0049DBA0->names->unk_0xa4, 2, id, 0);
                    func_00428C10(r, 2, 1);
                }
            }
        }
        D_0048D940 = 6;
        break;

    case 6:
        if (D_0047B3F0 != 6) {
            unsigned int k;

            cfg = func_00429EC0();
            k = 0;
            D_0048D908 = 0;
            D_0047B3F0 = D_0048D940;
            func_00452F70(D_0047B440, D_00496E18);
            if (func_0042A680(0x12d, 0) != 0) {
                unsigned int cnt = 0;
                unsigned int m;

                if (func_0042A680(0x198, 0) != 0) {
                    for (i = 0; i < D_0049DBA0->ncars; i++)
                        ;
                    cnt = 1;
                    for (i = 0; i < D_0049DBA0->ncars; i++) {
                        if (D_0049DBA0->cars[i].unk_0x35 <= 4 && ++k > 1)
                            D_0049DBA0->cars[i].unk_0x35 = 6;
                    }
                } else {
                    for (i = 1; i <= 4; i++) {
                        if (func_0042A680(0xcb, i) != -1)
                            cnt++;
                    }
                }
                m = func_0042A680(0x133, 0) + 1;
                if (m > cnt)
                    D_0048D8FC = m - cnt;
                else
                    D_0048D8FC = 0;
            } else {
                D_0048D8FC = 100000;
            }
            D_0048D904 = func_00454A70(0, 0x24);
            if (cfg != NULL && D_0049DBA0->names->unk_0xa0 != 0 && cfg->unk_0x0 == 0)
                D_0048D8F8 = func_004287E0(D_0049DBA0->names->unk_0xa0, 8, 2, 0);
        }
        if (!func_00427760()) {
            if (D_0048D908 < D_0049DBA0->ncars) {
                Car_00446840 *c = &D_0049DBA0->cars[D_0048D908++];
                if (c->unk_0x24 == 0) {
                    int nm = D_0049DBA0->names->unk_0xa0;
                    unsigned int v = c->unk_0x30;

                    if (c->unk_0x35 <= 4 && func_0042A680(0x198, 0) == 0) {
                        if (!D_0048D93D) {
                            v = func_0042A680(0xcb, c->unk_0x35);
                            if (v == (unsigned int)-1)
                                return D_0047B3F0;
                        }
                    } else if (v == (unsigned int)-1 || func_0042A680(0x198, 0) != 0) {
                        unsigned int a = func_0042A680(0xcb, 1);
                        unsigned int m = c->unk_0x37 + 1;
                        v = (D_0048D904 + a + D_0048D908) % m;
                        if (v == a)
                            v = (a + D_0048D908) % m;
                    }
                    if (c->unk_0x35 > 4) {
                        if (--D_0048D8FC < 0)
                            return D_0047B3F0;
                    }
                    r = func_004287E0(nm, 0, v, 0);
                    r = func_00428C10(r, 0, 1);
                    c->unk_0x30 = v;
                    if (r == 0)
                        return 8;
                    c->unk_0x24 = func_004216C0(r, v);
                }
            } else {
                D_0048D940 = 7;
            }
        }
        if (D_0048D940 == 7) {
            D_0049DBA0->unk_0x0 = (int)*D_0049DBAC;
            D_0048D940 = 0;
            D_0047B3F0 = 7;
            func_00452030();
            func_00452040();
        }
        return D_0047B3F0;

    default:
        return D_0048D940;
    }
    return D_0048D940;
}
