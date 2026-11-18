// COMPILER: ee-gcc2.96

extern int func_0036C5F8();
extern int func_00369F20();
extern int func_00368FC0();
extern int func_00368E90();
extern int func_0036D688();
extern int func_0036D8E8();
extern int func_003691D8();
extern int func_0036DFF0();
extern int func_0036DE80();
struct V7 { char pad[0x18]; int (*f18)(); int (*f1C)(); };
struct O7 { struct V7 *vt; };

// FUNCTION: GAME 0x368AB0
int func_00368AB0(long *a, long *b)
{
    int r = func_00368FC0(a);
    if (r) {
        return func_00368E90(0, 0xFF020201);
    }
    b[0] = a[3];
    b[1] = a[4];
    return r;
}

// FUNCTION: GAME 0x368C60
int func_00368C60(long *a, long *b)
{
    int r = func_00368FC0(a);
    if (r) {
        return func_00368E90(0, 0xFF020203);
    }
    b[0] = a[21];
    b[1] = a[22];
    b[2] = a[23];
    b[3] = a[24];
    b[4] = a[25];
    return r;
}

// FUNCTION: GAME 0x36A300
int func_0036A300(char *a, int *b, int *c)
{
    int r = func_0036C5F8();
    if (r) return func_00369F20(0, 0xFF03020E);
    *b = *(int *)(a + 0x2B4);
    *c = *(int *)(a + 0x2B8);
    return r;
}

// FUNCTION: GAME 0x36DE00
int func_0036DE00(int a, int b)
{
    int r;
    if (func_0036D688(a)) return func_0036D8E8(0, 0xFF03020C);
    r = func_0036DFF0(a, b);
    if (!r) func_0036DE80(a);
    return r;
}

// FUNCTION: GAME 0x36A5F8
int func_0036A5F8(struct O7 *o)
{
    int buf[2];
    o->vt->f18(o, 1, 0x7FFFFFFF, buf);
    o->vt->f1C(o, 1, buf);
    if (buf[1] < 4) return 0;
    return func_003691D8(buf[0]);
}

extern int func_0036BB78();
extern int func_0036BDA0();
struct X8 { int x[8]; };
struct E5b { int f; char pad[0xFC]; };
struct T5b { char pad[0xC]; int n; struct E5b e[1]; };
extern struct T5b *D_003F1A98;
extern void func_00369188();
extern void func_00366D20();
extern int func_00368AA8();

// FUNCTION: GAME 0x369FB8
int func_00369FB8(int a, int b)
{
    int r;
    if (func_0036C5F8()) return func_00369F20(0, 0xFF03020A);
    r = 0xFF030305;
    do {
        int v = func_0036BB78(b);
        if (v == 0) break;
        if (v & 0xCC) { r = 0; break; }
    } while (func_0036BDA0(b, 1, 4) == 4);
    return func_00369F20(a, r);
}

// FUNCTION: GAME 0x36D970
int func_0036D970(int a, int b)
{
    int r;
    if (func_0036D688()) return func_0036D8E8(0, 0xFF03020A);
    r = 0xFF030305;
    do {
        int v = func_0036BB78(b);
        if (v == 0) break;
        if (v & 0xCC) { r = 0; break; }
    } while (func_0036BDA0(b, 1, 4) == 4);
    return func_0036D8E8(a, r);
}

// FUNCTION: GAME 0x368B18
int func_00368B18(char *a, struct X8 *b, int c)
{
    int r = func_00368FC0(a);
    if (r) return func_00368E90(0, 0xFF020202);
    *b = ((struct X8 *)(a + 0x48))[c];
    return r;
}

// FUNCTION: GAME 0x36E208
void func_0036E208(int *a)
{
    int x = (a[0x50 / 4] << 12) | a[1];
    int y = (a[0x54 / 4] << 12) | a[2];
    a[0x2CC / 4] = (unsigned)(x + 0xF) >> 4;
    a[0x2C4 / 4] = x;
    a[0x2C8 / 4] = y;
    if (a[0x48 / 4] == 1)
        a[0x2D0 / 4] = (unsigned)(y + 0xF) >> 4;
    else if (a[0x118 / 4] == 3)
        a[0x2D0 / 4] = ((unsigned)(y + 0x1F) >> 5) << 1;
    else
        a[0x2D0 / 4] = (unsigned)(y + 0x1F) >> 5;
    {
        int p = a[0x2CC / 4] << 4;
        int q = a[0x2D0 / 4] << 4;
        a[0x3B4 / 4] = p;
        a[0x3B8 / 4] = q;
        a[0x3BC / 4] = p >> 1;
        a[0x3C0 / 4] = q >> 1;
    }
}

// FUNCTION: GAME 0x368DF0
int func_00368DF0(void)
{
    struct T5b *t = D_003F1A98;
    int n = t->n;
    struct E5b *a = t->e;
    if (n > 0) {
        struct E5b *e = a;
        int m = n;
        do {
            if (e->f != 1) func_00369188(e);
            e++;
            m--;
        } while (m);
    }
    func_00366D20();
    return func_00368AA8();
}

#ifdef NONMATCHING
extern int func_0036C688();
extern int func_0036C440();
struct S7 { char pad[0x188]; int f; };
// DRAFT: GAME 0x36C3D0
// diff: 2 words, v1 vs v0 for the constant 1 stored at 0x188
int func_0036C3D0(struct S7 *a)
{
    if (func_0036C5F8()) return func_00369F20(0, 0xFF030201);
    func_0036C688(a);
    func_0036C440(a, 0x40C);
    a->f = 1;
    return 0;
}

extern int func_0036CD70();
extern int D_0076A590[];
extern int func_0036D630();
// DRAFT: GAME 0x36D580
// diff: 7 words, v0/v1 register choice for the table address and ld ordering
int func_0036D580(char *a, int i, int fn)
{
    int *t;
    if (i == 8 && fn == 0) fn = (int)func_0036CD70;
    if (a == 0) {
        func_0036D630(i, fn);
        t = D_0076A590;
    } else {
        if (func_0036D688(a)) return func_0036D8E8(0, 0xFF030202);
        t = (int *)(a + 0x18);
    }
    t[i] = fn;
}

struct W7 { int x[5]; };
// DRAFT: GAME 0x36D868
// diff: 3 words, epilogue ld order (ra restored first in the original)
int func_0036D868(char *a, struct W7 *b)
{
    if (func_0036D688(a))
        return func_0036D8E8(0, 0xFF030204);
    *b = *(struct W7 *)(a + 4);
}

extern char *func_00369370();
// DRAFT: GAME 0x36D0F8
// diff: 1 word, a0 for the second func_00369370 call is s2 in the original and s0 here
int func_0036D0F8(char *a, int n)
{
    char *p = func_00369370(a, n, 0x40);
    if (p == 0) return 0;
    p += 4;
    n -= p - a;
    a = p;
    if (n <= 0) return 0;
    p = func_00369370(a, n, -1);
    if (p == 0) return 0;
    if ((func_003691D8(p) & 0x10) == 0) return 0;
    p += 4;
    n -= p - a;
    if (n <= 0) return 0;
    return (*(unsigned char *)p >> 4) == 1;
}

extern long func_003B7FE0();
// DRAFT: GAME 0x36C920
// diff: 14 words, register choice for b copy (v0) and product (v1 then a0) before the call
int func_0036C920(int a, int b, int c)
{
    long p = (long)a * b;
    if (c == 0) return ((a ^ b) < 0) ? 0x80000000 : 0x7FFFFFFF;
    return (int)func_003B7FE0(p, c);
}
#endif
