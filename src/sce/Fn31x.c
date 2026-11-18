// COMPILER: ee-gcc2.9-991111
// SCE libgcc/libstdc++ units in 0x31C000-0x322978 built by SCE ee-gcc 2.9x, -O2 -G0.

// FUNCTION: GAME 0x31FAE8
struct V { short adj; short p; int (*fn)(char *, int, int, int, int, int); };
int func_0031FAE8(char *(*f0)(void), int (*f1)(void), int a, int b, int (*f3)(void), int c)
{
    char *o = f0();
    struct V *v = (struct V *)(*(char **)(o + 4) + 0x10);
    char *o2 = o + v->adj;
    int x = f1();
    int y = f3();
    return v->fn(o2, x, a, b, y, c);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31EC48 (13 words differ: 2.9 schedules the srl/and of x before the sign store)
struct U { int cls, sign, exp, frac; };

void func_0031EC48(unsigned *p, struct U *u)
{
    unsigned x = *p;
    int e = (x >> 23) & 0xFF;
    unsigned fr = x & 0x7FFFFF;
    u->sign = x >> 31;
    if (e == 0) {
        u->cls = 2;
        return;
    }
    if (e == 0xFF) {
        if (fr == 0) {
            u->cls = 4;
            return;
        }
        if (fr & 0x100000)
            u->cls = 1;
        else
            u->cls = 0;
        u->frac = fr;
        return;
    }
    u->frac = (fr << 7) | 0x40000000;
    u->exp = e - 0x7F;
    u->cls = 3;
}

// DRAFT: GAME 0x31DFA8 (27 words differ, all from one missing nop: the original aligns the e == 0x7FF block)
struct UD { unsigned cls; int sign, exp, pad; unsigned long long frac; };
void func_0031DFA8(unsigned long long *p, struct UD *u)
{
    unsigned long long x = *p;
    unsigned long long fr = x & 0xFFFFFFFFFFFFFULL;
    int e = (int)(x >> 52) & 0x7FF;
    u->sign = x >> 63;
    if (e == 0) {
        u->cls = 2;
        return;
    }
    if (e == 0x7FF) {
        if (fr == 0) {
            u->cls = 4;
            return;
        }
        if (fr & 0x8000000000000ULL)
            u->cls = 1;
        else
            u->cls = 0;
        u->frac = fr;
        return;
    }
    u->frac = (fr << 8) | 0x1000000000000000ULL;
    u->exp = e - 0x3FF;
    u->cls = 3;
}

// DRAFT: GAME 0x31EA10 (23 words differ: original tests cls with xori/beqz and jumps from cls == 4 past the range checks)
unsigned func_0031EA10(double d)
{
    struct UD u;
    func_0031DFA8(&d, &u);
    if (u.cls == 2)
        return 0;
    if (u.cls < 2)
        return 0;
    if (u.sign)
        return 0;
    if (u.cls != 4) {
        if (u.exp < 0)
            return 0;
        if (u.exp >= 0x20)
            return ~0;
    }
    if (u.exp >= 0x3D)
        return u.frac << (u.exp - 0x3C);
    return u.frac >> (0x3C - u.exp);
}

// DRAFT: GAME 0x31EF18 (15 words differ: original numbers a1/a3 as s1/s2, this gives s2/s1)
struct W { char pad[0x10]; short adj; short p; int (*fn)(char *, int, int, int, int, int); };
extern int func_0031EE40(char *);
int func_0031EF18(char *o, int a, int b, int c, int d, int e)
{
    char *t;
    struct W *v;
    int (*fn)(char *, int, int, int, int, int);
    if (func_0031EE40(o))
        return c;
    t = *(char **)(o + 8);
    v = *(struct W **)(t + 4);
    fn = v->fn;
    return fn(t + v->adj, a, b, c, d, e);
}

// DRAFT: GAME 0x321378 (20 words differ: s1/s2 swapped for b/c, and the sh 4 store is not hoisted into the a0 argument register)
struct N { void *vt; short s4; short s6; int f8, fc, f10, f14, f18; long long f20; int f28; };
extern void *func_003212C0(int);
extern struct N **func_00320360(int);
extern void func_00321308(void);

void func_00321378(int a, int b, int c)
{
    struct N *n = func_003212C0(0x30);
    struct N **q;
    n->fc = b;
    n->f10 = c;
    n->f8 = a;
    n->f28 = a;
    n->f20 = 0;
    n->f14 = 0;
    n->vt = (void *)func_00321308;
    q = func_00320360(n->s4 = 4);
    n->s6 = 1;
    n->f18 = (int)*q;
    *q = n;
}
#endif

extern void func_0031DA48(void);
extern void _cleanup(void);
extern void _exit(int);

// FUNCTION: GAME 0x31DB70
void func_0031DB70(int code)
{
    func_0031DA48();
    _cleanup();
    _exit(code);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31DA48 (5 words differ: original loads the target from p[-1] in v1 and stores the advanced pointer in the jalr delay slot)
extern void (**D_003C4080)(void);
void func_0031DA48(void)
{
    while (*D_003C4080) {
        void (*f)(void) = *D_003C4080;
        D_003C4080++;
        f();
    }
}

// DRAFT: GAME 0x31CEB8 (14 words differ: 2.9 turns the final call into a tail jump; the original keeps jal plus sd/ld $ra)
extern void func_0030F2B0(unsigned);
extern int D_00747B10, D_00747B14;
void func_0031CEB8(void)
{
    D_00747B10 = 0x3124;
    D_00747B14 = 0x66B;
    func_0030F2B0(0xD8A9523D);
}
#endif
