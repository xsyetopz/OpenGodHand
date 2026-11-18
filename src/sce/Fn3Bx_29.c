// COMPILER: ee-gcc2.9-991111
// SCE library units built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

extern int *func_003A4FB8(void);
extern void iSignalSema(int);
extern void func_003B0D80(int);
extern void func_003B0D48(int);
extern void func_003B0E30(int);
extern void func_003B2450(void);
extern int D_003FAE54;
extern void func_003B3E70(void);
extern int D_003FAEE4;
extern int WaitSema(int);
extern int func_003B5C48(int, int, int, int *);
extern int func_003B5E78(int, int, int, int *, int);
extern void func_003B6818(int);
extern void func_003AF8C0(int);
extern int func_003B00D0(int, int *);
extern void (*D_003D141C)(void);

// FUNCTION: GAME 0x3B0360
int func_003B0360(void)
{
    *func_003A4FB8() = 5;
    return -1;
}

// FUNCTION: GAME 0x3B0D20
int func_003B0D20(int a, int b, int c, int d)
{
    iSignalSema(d);
    __asm__ volatile("sync\n\tei");
    return 0;
}

// FUNCTION: GAME 0x3B0E30
void func_003B0E30(int c)
{
    if (c == 10) {
        func_003B0D48(13);
        func_003B0D48(10);
    } else
        func_003B0D48(c);
}

// FUNCTION: GAME 0x3B1E40
int func_003B1E40(int a, int b, int c)
{
    if (c)
        func_003B0D80(c);
    return 1;
}

// FUNCTION: GAME 0x3B1E68
int func_003B1E68(int a, int b, int c)
{
    if (c)
        func_003B0E30(c);
    return 1;
}

// FUNCTION: GAME 0x3B2AA0
void func_003B2AA0(void)
{
    func_003B2450();
    D_003FAE54 = 0;
}

// FUNCTION: GAME 0x3B3EC8
int func_003B3EC8(void)
{
    func_003B3E70();
    WaitSema(D_003FAEE4);
    return 0;
}

// FUNCTION: GAME 0x3B5E50
int func_003B5E50(int a, int b, int c)
{
    int v;
    return func_003B5C48(a, b, c, &v);
}

// FUNCTION: GAME 0x3B60A0
int func_003B60A0(int a, int b, int c)
{
    int v;
    return func_003B5E78(a, b, c, &v, 0);
}

// FUNCTION: GAME 0x3B6820
void func_003B6820(int a)
{
    func_003B6818(a);
    func_003AF8C0(a);
}

// FUNCTION: GAME 0x3B7AA8
int func_003B7AA8(int a)
{
    int v = a;
    return func_003B00D0(0x10, &v);
}

// FUNCTION: GAME 0x3B9AF8
void func_003B9AF8(void)
{
    if (D_003D141C)
        D_003D141C();
}

extern int func_003B2B90();
extern int func_003B26C8();
extern int func_003B0100();
extern int func_003B0110();
extern int func_003B7C58();

// FUNCTION: GAME 0x3B2BC0
int func_003B2BC0(int *a, int b)
{
    if (b < 0 || b >= a[8])
        return func_003B2B90();
    return a[7] + (b << 6);
}

// FUNCTION: GAME 0x3B2CD0
int func_003B2CD0(int a, int b, int c, int *d)
{
    return func_003B26C8(0x80000008, d, 0x40, d[9], d[10], d[11]) ? 0 : 0x800;
}

// FUNCTION: GAME 0x3B7C18
int func_003B7C18(void)
{
    if (func_003B0100() == 0x2000000)
        return func_003B7C58();
    return func_003B0110();
}

// FUNCTION: GAME 0x3B2E38
int func_003B2E38(int a, int b, int c, int d)
{
    return func_003B26C8(0x80000008, d, 0x40, 0, 0, 0) ? 0 : 0x800;
}

struct SifReq {
    int m_0;
    int _p4[3];
    int m_10;
    int m_14;
    int _p18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
};
struct SifRn {
    int _p0[2];
    int m_8;
};
extern void func_003B7898(int, void *, void *);
extern struct SifRn *func_003B2DE8(int, int);

// FUNCTION: GAME 0x3B2D10
void func_003B2D10(struct SifReq *a, int b)
{
    struct SifReq *s;
    int u;
    int t;
    if (a->m_10 & 4)
        s = (struct SifReq *)func_003B2BC0((int *)b, (unsigned)a->m_10 >> 16);
    else
        s = (struct SifReq *)func_003B2B90(b);
    u = a->m_14;
    t = a->m_1C;
    s->m_14 = u;
    s->m_1C = t;
    s->m_20 = 0x8000000C;
    s->m_24 = a->m_20;
    s->m_28 = a->m_24;
    s->m_2C = a->m_28;
    if (func_003B26C8(0x80000008, s, 0x40, a->m_20, a->m_24, a->m_28) == 0)
        func_003B7898(0x800, func_003B2CD0, s);
}

// FUNCTION: GAME 0x3B2E78
void func_003B2E78(struct SifReq *a, int b)
{
    struct SifReq *s = (struct SifReq *)func_003B2B90(b);
    struct SifRn *n;
    int r;
    int u = a->m_14;
    int t = a->m_1C;
    s->m_1C = t;
    s->m_14 = u;
    s->m_20 = 0x80000009;
    n = func_003B2DE8(a->m_20, b);
    if (!n) {
        s->m_24 = 0;
        s->m_28 = 0;
    } else {
        s->m_24 = (int)n;
        s->m_28 = n->m_8;
    }
    if (func_003B26C8(0x80000008, s, 0x40, 0, 0, 0) == 0)
        func_003B7898(0x800, func_003B2E38, s);
}

extern int func_003B63A0();
extern void func_003B63F0();
extern int func_003AF9F0();
extern int func_003AF9E0();
extern int func_003AFA10();
extern int func_003AFA00();

// FUNCTION: GAME 0x3B06D8
int func_003B06D8(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AF9F0(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B0740
int func_003B0740(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AF9E0(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B07A8
int func_003B07A8(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AFA10(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B0810
int func_003B0810(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AFA00(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

extern void func_003AFD50();
extern void func_003AFD40();

// FUNCTION: GAME 0x3B66D0
int func_003B66D0(void)
{
    unsigned v[2];
    func_003AFD50(&v[0]);
    v[1] = (v[0] & 0xFFFF1FFF) | 0x2000;
    func_003AFD40(&v[1]);
    func_003AFD50(&v[1]);
    func_003AFD40(&v[0]);
    return ((v[1] >> 13) & 7) == 0;
}
