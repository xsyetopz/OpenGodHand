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
// DRAFT: GAME 0x31D928 (12 words differ: p/q register roles are swapped against the original loop, which also leaves one more nop-free delay slot)
extern int D_003C4030[];
extern int func_0031D778(unsigned, int *);

int func_0031D928(unsigned n)
{
    int c = 0x14;
    int a = func_0031D778(n, &c);
    if (c != 1) {
        char *p, *q;
        int i;
        p = (char *)a + n;
        D_003C4030[((n + 7) >> 3) - 1] = (int)p;
        q = p;
        for (i = 1; c - 1 != i; i++) {
            p = q + n;
            *(int *)q = (int)p;
            q = p;
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
