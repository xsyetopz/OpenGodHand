extern int D_00747B14;
extern unsigned *D_00747A4C;
extern char D_00450ED8[];
extern char D_00450E88[];
unsigned *SearchData(unsigned *, const char *, unsigned);
extern "C" int memcmp(const void *, const void *, unsigned);
extern "C" void func_0031C238(int, char *, char *);
extern "C" void func_0031D3D0(int, int, int, int);
extern "C" float func_0031CF78(void);

// FUNCTION: GAME 0x31C1D0
extern "C" void func_0031C1D0(int a, char *b)
{
    if (b && !memcmp(b, D_00450E88, 4))
        func_0031C238(a, b + 4, b + 0x20);
}

// FUNCTION: GAME 0x31CE38
unsigned *SearchCameraData(const char *n)
{
    unsigned *p = SearchData(D_00747A4C, D_00450ED8, 0);
    if (!p)
        return 0;
    return SearchData(p, n, 0);
}

// FUNCTION: GAME 0x31CF30
extern "C" float func_0031CF30(void)
{
    float r = func_0031CF78();
    if (r <= 0.0f)
        r += 1.0f;
    return r;
}

// FUNCTION: GAME 0x31CF78
extern "C" float func_0031CF78(void)
{
    unsigned r = D_00747B14 * 0x10DCD;
    D_00747B14 = r;
    float f = (float)r * 2.3283064e-10f;
    return f + f;
}

// FUNCTION: GAME 0x31D658
extern "C" unsigned short func_0031D658(char *s, unsigned char b)
{
    for (int i = 0; i < *(unsigned short *)(s + 8); i++) {
        int p = ((int *)(s + 0x10))[i] + (int)s;
        func_0031D3D0(p, *(int *)p + p, i, b);
    }
    return *(unsigned short *)(s + 8);
}

extern char Sys[];
extern char Dvd[];
extern char RoomHeap[];
extern char D_00450EC0[];
extern int D_007558A0[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int func_00200DF8(char *, char *, char *, char *, int, int *, int, int);
extern "C" void func_00201108(char *, int);

// FUNCTION: GAME 0x31CC48
extern "C" void func_0031CC48(void)
{
    char buf[0x40];
    int v;
    sprintf(buf, D_00450EC0, (unsigned char)Sys[0x5B1], (unsigned char)Sys[0x5B1], (unsigned char)Sys[0x5B0]);
    func_00201108(Dvd, func_00200DF8(Dvd, buf, Sys + 0x5AC, RoomHeap, 0, &v, 0, 0));
    D_007558A0[0] = *(int *)(Sys + 0x5AC);
    D_007558A0[1] = v;
}

#include "game/cVec.h"
extern "C" char *Getplayer__Fv();
struct HeatS { cVec a; cVec b; float h; float g; };
extern HeatS D_00755880;
extern struct { float a, b; } g_HeatSys;
// FUNCTION: GAME 0x31C350
extern "C" void func_0031C350(const cVec *a, const cVec *b)
{
    char *p = Getplayer__Fv();
    if (!a) {
        D_00755880.a.x = (*(cVec **)(p + 0xF0))->x;
        D_00755880.a.y = (*(cVec **)(p + 0xF0))->y;
        D_00755880.a.z = (*(cVec **)(p + 0xF0))->z;
    } else {
        D_00755880.a.x = a->x;
        D_00755880.a.y = a->y;
        D_00755880.a.z = a->z;
    }
    if (!b) {
        D_00755880.b.x = *(float *)(p + 0x100);
        D_00755880.b.y = *(float *)(p + 0x104);
        D_00755880.b.z = *(float *)(p + 0x108);
    } else {
        D_00755880.b.x = b->x;
        D_00755880.b.y = b->y;
        D_00755880.b.z = b->z;
    }
    D_00755880.g = g_HeatSys.a;
    D_00755880.h = g_HeatSys.b;
}

extern "C" int strcmp(const char *, const char *);
// FUNCTION: GAME 0x31CCF0
unsigned *SearchData(unsigned *tbl, const char *name, unsigned n)
{
    unsigned cnt, k, i;
    char *s;
    if (!tbl)
        return 0;
    cnt = tbl[0];
    k = 0;
    s = (char *)tbl + cnt * 4;
    for (i = 1; i <= cnt; i++) {
        s += 4;
        if (!strcmp(s, name)) {
            if (k++ == n)
                return (unsigned *)(tbl[i] + (unsigned)tbl);
        }
    }
    return 0;
}

void Draw_Poly_sc(const float (*)[3], unsigned);
extern "C" unsigned func_0031CA58(int);
// FUNCTION: GAME 0x31CB80
extern "C" void func_0031CB80(short *pts, int c, unsigned z)
{
    float v[16];
    float *q;
    int i; for (i = 4, q = v; i != 0; i--) {
        q[0] = pts[0];
        q[1] = pts[1];
        q[2] = (float)z + 65528.0f;
        q[3] = 1.0f;
        pts += 2;
        q += 4;
    }
    Draw_Poly_sc((const float(*)[3])v, func_0031CA58(c));
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31C7E0 (12 words differ: scheduling of a2/v1 loads before the V4 stores)
struct V4 { float x, y, z, w; };
struct VE { short d; short i; void (*f)(char *, const void *); };
void setPlayerPos(const cVec &pos, float f)
{
    char *p = Getplayer__Fv();
    VE *vt = *(VE **)(p + 0x214);
    vt[14].f(p + vt[14].d, &pos);
    vt = *(VE **)(p + 0x214);
    V4 v;
    v.x = 0.0f;
    v.y = f;
    v.z = 0.0f;
    v.w = 1.0f;
    vt[15].f(p + vt[15].d, &v);
    *(float *)(p + 0x30) = pos.x;
    *(float *)(p + 0x34) = pos.y;
    *(float *)(p + 0x38) = pos.z;
    char *q = *(char **)(p + 0x68C);
    if (q)
        *(unsigned *)(q + 0x2F0) |= 1;
}
#endif
