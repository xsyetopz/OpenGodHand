// COMPILER: ee-gcc2.95.3-136
// SN ProDG ee-gcc 2.95.3 (build 136) is the compiler whose prologues save callee-saved registers with sq.

struct HeatS { float a[3]; float b[3]; float h; float g; };
extern struct HeatS D_00755880;
extern struct { float a, b; } g_HeatSys;
extern char *Getplayer__Fv(void);
extern void func_002A9BF0(void *, float);
extern void SetHeatGage__8cHeatSysf(void *, float);

// FUNCTION: GAME 0x31C438
void func_0031C438(void)
{
    char *p = Getplayer__Fv();
    (*(float **)(p + 0xF0))[0] = D_00755880.a[0];
    (*(float **)(p + 0xF0))[1] = D_00755880.a[1];
    (*(float **)(p + 0xF0))[2] = D_00755880.a[2];
    *(float *)(p + 0x490) = D_00755880.a[0];
    *(float *)(p + 0x494) = D_00755880.a[1];
    *(float *)(p + 0x498) = D_00755880.a[2];
    *(float *)(p + 0x100) = D_00755880.b[0];
    *(float *)(p + 0x104) = D_00755880.b[1];
    *(float *)(p + 0x108) = D_00755880.b[2];
    func_002A9BF0(&g_HeatSys, D_00755880.g);
    SetHeatGage__8cHeatSysf(&g_HeatSys, D_00755880.h);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31D928 (11 words differ: structure matches, but p/q take a1/a2 where the original uses a2/a1)
extern int D_003C4030[];
extern int func_0031D778(unsigned, int *);

int func_0031D928(unsigned n)
{
    int c = 0x14;
    int a = func_0031D778(n, &c);
    if (c != 1) {
        char *p = (char *)a + n;
        char *q;
        int i;
        D_003C4030[((n + 7) >> 3) - 1] = (int)p;
        q = p;
        p = q + n;
        for (i = 1; i != c - 1; i++) {
            *(int *)q = (int)p;
            q = p;
            p = q + n;
        }
        *(int *)q = 0;
    }
    return a;
}
#endif

struct O;
extern struct O cerr;
extern char D_00450F38[];
extern void (*D_003C4070)(void);
extern struct O *__ls__7ostreamPCc(struct O *, const char *);
extern struct O *endl__FR7ostream(struct O *);
extern void func_0031DB70(int) __attribute__((noreturn));
extern void *malloc(unsigned);

// FUNCTION: GAME 0x31D6E8
void func_0031D6E8(unsigned n)
{
    do {
        void (*f)(void) = D_003C4070;
        if (f == 0) {
            struct O *(*e)(struct O *) = endl__FR7ostream;
            e(__ls__7ostreamPCc(&cerr, D_00450F38));
            func_0031DB70(1);
        }
        f();
    } while (malloc(n) == 0);
}

struct BB { char d[0x20]; };
struct Pr { int a, b; };
extern struct Pr D_007558A8[];
extern void *func_00149310(void);
extern struct BB *__12cBoundingBox(struct BB *);
extern void _$_12cBoundingBox(struct BB *, int);
extern void func_00148420(void *, int, int, int, int, struct BB *, int);
extern void func_001485A0(void *, int, int, int, int, struct BB *, int);
extern void func_0014B640(char *, void *, struct BB *);

// FUNCTION: GAME 0x31D2F8
void func_0031D2F8(char *o, int i)
{
    int a = D_007558A8[i].a;
    int b = D_007558A8[i].b;
    if (a != 0 && b != 0) {
        struct BB bb;
        void *h = func_00149310();
        __12cBoundingBox(&bb);
        func_00148420(h, a, b, 0x1001000, 1, &bb, 0);
        func_001485A0(h, a, b, 0x1001000, 1, &bb, *(int *)(o + 0x288));
        func_0014B640(o, h, &bb);
        _$_12cBoundingBox(&bb, 2);
    }
}

struct D { unsigned char flag; char p0[3]; int a4; int n8; int aC; int n10; int a14; int n18; };
struct S { int n0; int o4; int n8; int oC; int n10; int o14; };
struct E { char p[0x10]; int v; char q[0xC]; };
extern void *memcpy(void *, const void *, unsigned);

// FUNCTION: GAME 0x31C238
void func_0031C238(struct D *d, struct S *s, int base)
{
    int i;
    if (d->flag == 0) {
        d->aC = base + s->o4;
        d->a4 = base + s->oC;
        d->a14 = base + s->o14;
    } else {
        memcpy((void *)d->aC, (void *)(base + s->o4), s->n0 << 5);
        memcpy((void *)d->a4, (void *)(base + s->oC), s->n8 * 12);
        memcpy((void *)d->a14, (void *)(base + s->o14), s->n10 << 1);
    }
    d->n10 = s->n0;
    d->n8 = s->n8;
    d->n18 = s->n10;
    for (i = 0; i < d->n10; i++)
        ((struct E *)d->aC)[i].v += d->a14;
}

extern int func_0031CA58(int);
extern void Draw_Line_sc__FPA3_fUiUib(float (*)[3], unsigned, unsigned, int);

// FUNCTION: GAME 0x31CA88
void func_0031CA88(short *pts, short n, int c, unsigned z)
{
    float buf[n][4];
    int k = n;
    float (*q)[4] = buf;
    do {
        (*q)[0] = pts[0];
        (*q)[1] = pts[1];
        (*q)[2] = z;
        (*q)[3] = 1.0f;
        pts += 2;
        q++;
    } while (--k);
    Draw_Line_sc__FPA3_fUiUib((float (*)[3])buf, n - 1, func_0031CA58(c), 1);
}

// FUNCTION: GAME 0x31D0C0
float func_0031D0C0(int *s)
{
    int x = *s * 0x19660D + 0x3C6EF35F;
    int u;
    *s = x;
    u = (x & 0x7FFFFF) | 0x3F800000;
    return *(float *)&u - 1.0f;
}

// FUNCTION: GAME 0x31D108
float func_0031D108(int *s)
{
    int x = *s * 0x19660D + 0x3C6EF35F;
    int u;
    *s = x;
    u = (x & 0x7FFFFF) | 0x3F800000;
    return (*(float *)&u + *(float *)&u - 2.0f) - 1.0f;
}

extern struct { char p[0x600]; unsigned char n; } Sys;

// FUNCTION: GAME 0x31D2B8
void func_0031D2B8(int a, int b)
{
    D_007558A8[Sys.n].a = a;
    D_007558A8[Sys.n].b = b;
    Sys.n++;
}

extern void func_0030F2B0(unsigned);
extern int D_00747B10, D_00747B14;

// FUNCTION: GAME 0x31CEB8
void func_0031CEB8(void)
{
    D_00747B10 = 0x3124;
    D_00747B14 = 0x66B;
    func_0030F2B0(0xD8A9523D);
}
