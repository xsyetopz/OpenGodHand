// COMPILER: ee-gcc2.9-991111
// SCE small leaf helpers in 0x3951F8-0x3A4AF0.

extern char D_0045E630[];
extern void scePrintf(const char *, ...);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A19D8
// diff: 6 words; ours adds a daddu a0->v1 after mfc1 (5 variants tried)
float func_003A19D8(float x)
{
    union { float f; unsigned int i; } u;
    u.f = x;
    u.i &= 0x7FFFFFFF;
    return u.f;
}
#endif

struct Ctx {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
};

// FUNCTION: GAME 0x39ADA8
void func_0039ADA8(struct Ctx *c, int a, int b)
{
    c->m_4 = b;
    c->m_0 = a;
    c->m_8 = a;
    c->m_C = a;
}

struct Hd {
    char _pad[0x40];
    char *m_40;
};

// FUNCTION: GAME 0x39AA38
void func_0039AA38(struct Hd *h)
{
    *(int *)(h->m_40 + 0x878) = 1;
}

// FUNCTION: GAME 0x39C218
void func_0039C218(const char *a)
{
    scePrintf(D_0045E630, a);
}

// FUNCTION: GAME 0x3970C8
void func_003970C8(char *p, int n)
{
    while (n--)
        *p++ = 0;
}

struct Cx {
    char _pad[0xC];
    int m_C;
    char _pad2[0x868 - 0x10];
    void *m_868;
};
struct Msg {
    int m_0;
    const char *m_4;
};
extern void func_0039AB20(void *, struct Msg *);
extern void func_003B1EE0(char *, int, const char *, int);
void func_0039C390(struct Cx *, const char *);
extern char D_0045E8B0[];
extern char D_0045E8E0[];
extern char D_0045E8F8[];
extern char D_0045E930[];
extern void func_0039E7C0(void);

// FUNCTION: GAME 0x39C390
void func_0039C390(struct Cx *c, const char *s)
{
    struct Msg m;
    if (c->m_868 && c && c->m_C) {
        m.m_0 = 0;
        m.m_4 = s;
        func_0039AB20(c->m_868, &m);
    } else
        func_0039C218(s);
}

// FUNCTION: GAME 0x39C3E8
void func_0039C3E8(struct Cx *c, const char *fmt, int arg)
{
    char buf[256];
    func_003B1EE0(buf, 256, fmt, arg);
    func_0039C390(c, buf);
}

// FUNCTION: GAME 0x3A09F0
void func_003A09F0(struct Cx *a)
{
    func_0039C390(a, D_0045E8B0);
}

// FUNCTION: GAME 0x3A0A00
void func_003A0A00(struct Cx *a)
{
    func_0039C390(a, D_0045E8E0);
}

// FUNCTION: GAME 0x3A0BF8
void func_003A0BF8(struct Cx *a)
{
    func_0039C390(a, D_0045E8F8);
}

// FUNCTION: GAME 0x3A0C08
void func_003A0C08(struct Cx *a)
{
    func_0039C390(a, D_0045E930);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3A0DE8
// diff: 8 words, register numbering only (v0/v1/a0/a1 order; 4 variants tried)
void func_003A0DE8(void)
{
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000)
        func_0039E7C0();
}
#endif

struct Sx {
    char _pad[0x108];
    int m_108;
    char _pad1[0x160 - 0x10C];
    int m_160;
    char _pad2[0x184 - 0x164];
    int m_184;
    char _pad3[0x1C8 - 0x188];
    int m_1C8;
    char _pad4[0x1D4 - 0x1CC];
    int m_1D4;
    int m_1D8;
    char _pad5[0x1E4 - 0x1DC];
    int m_1E4;
    int m_1E8;
    char _pad6[0x1F4 - 0x1EC];
    int m_1F4;
};
extern void func_0039B130(struct Sx *, int, int);
extern void func_0039B3F0(struct Sx *, int, int, int);

// FUNCTION: GAME 0x39B8D0
void func_0039B8D0(struct Sx *s, int n, int flag)
{
    int a1, a2;
    if (flag) {
        if (s->m_184 == 3) {
            func_0039B130(s, s->m_160 == 3 ? s->m_1D4 : s->m_1C8, n - 1);
        } else {
            if (s->m_160 == 3) {
                a1 = s->m_1E4;
                a2 = s->m_1F4;
            } else {
                a1 = s->m_1D8;
                a2 = s->m_1E8;
            }
            func_0039B3F0(s, a1, a2, n - 1);
        }
    }
    if (s->m_108 == 1)
        s->m_108 = 2;
}

extern int func_003B63A0(void);
extern void func_003B63F0(void);
#define REG(a) (*(volatile unsigned int *)(a))

// FUNCTION: GAME 0x39C228
void func_0039C228(void)
{
    int r = func_003B63A0();
    REG(0x1000F590) = REG(0x1000F520) | 0x10000;
    REG(0x1000B000) = 0;
    REG(0x1000B400) = 0;
    REG(0x1000F590) = REG(0x1000F520) & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
    REG(0x1000B020) = 0;
    REG(0x1000B420) = 0;
    REG(0x10002010) = 0x40000000;
}

extern int func_003AFFC0(void);
extern void func_003AFFE0(int);

// FUNCTION: GAME 0x396008
int func_00396008(int a)
{
    int r = func_003AFFC0();
    func_003AFFE0(a);
    return r;
}

extern void func_00397028(unsigned int *, int);

// FUNCTION: GAME 0x397550
int func_00397550(unsigned int *p, int n)
{
    if (n == 1)
        return (*p >> 8) & 1;
    func_00397028(p, n);
    return 0;
}

struct Ent {
    char _pad[0x10];
    int m_10;
    char _pad2[0x1C - 0x14];
};
struct Grp {
    struct Ent e[4];
};
extern struct Grp D_0077C110[];
extern unsigned char *func_00397BC8(int, int, int);
extern int func_003982C8(int, int, int);

// FUNCTION: GAME 0x397ED0
unsigned char func_00397ED0(int a, int b)
{
    if (D_0077C110[a].e[b].m_10 == 0)
        return 0;
    return func_00397BC8(a, b, 0)[0x71];
}

// FUNCTION: GAME 0x3983F8
int func_003983F8(int a, int b)
{
    if (D_0077C110[a].e[b].m_10 == 0)
        return 0;
    return func_003982C8(a, b, 0xFFF);
}

struct Dv {
    char _pad[0x40];
    char *m_40;
};
extern void func_0039A140(struct Dv *);

// FUNCTION: GAME 0x39A9A8
void func_0039A9A8(struct Dv *d, unsigned int a, int b)
{
    char *p = d->m_40;
    *(int *)(p + 0xC4) = 1;
    *(unsigned int *)(p + 0xEC) = (a & 0xFFFFFFF) | 0x20000000;
    *(int *)(p + 0xF8) = b;
    *(int *)(p + 0xF4) = 0;
    *(int *)(p + 0xF0) = 0;
    func_0039A140(d);
    __asm__ volatile("");
}

// FUNCTION: GAME 0x39A9F0
void func_0039A9F0(struct Dv *d, unsigned int a, int b)
{
    char *p = d->m_40;
    *(int *)(p + 0xF8) = b;
    *(unsigned int *)(p + 0xEC) = (a & 0xFFFFFFF) | 0x20000000;
    *(int *)(p + 0xC4) = 0;
    *(int *)(p + 0xF4) = 0;
    *(int *)(p + 0xF0) = 0;
    func_0039A140(d);
    __asm__ volatile("");
}

extern void func_0039A720(struct Dv *);
extern void func_0039A5B0(struct Dv *);

#ifdef NONMATCHING
// DRAFT: GAME 0x39AC10
// diff: 7 words, register numbering only (a3/v1 vs a1/v1/a0; 8 variants tried)
void func_0039AC10(struct Dv *d)
{
    struct Q { char _p[0x184]; int m_184; } *q = (struct Q *)d->m_40;
    if (q->m_184 != 3) {
        func_0039A720(d);
        __asm__ volatile("");
    } else {
        func_0039A5B0(d);
        __asm__ volatile("");
    }
}
#endif

struct Bs {
    char _pad[0x828];
    int m_828;
    int m_82C;
    char _pad2[0x848 - 0x830];
    unsigned int m_848;
    int m_84C;
};
extern void func_0039ECB8(struct Bs *);
extern int func_0039E928(struct Bs *);

// FUNCTION: GAME 0x39EB90
unsigned int func_0039EB90(struct Bs *s, int n)
{
    if (s->m_828 || s->m_84C < n) {
        func_0039ECB8(s);
        *(volatile unsigned int *)0x10002000 = 0x40000000;
        s->m_828 = 0;
        s->m_82C = 0x40000000;
        s->m_848 = func_0039E928(s);
        s->m_84C = 0x20;
    }
    return s->m_848 >> -n;
}

extern void func_003A0DE8(void);
extern void func_003A0E20(int, int);

// FUNCTION: GAME 0x3A0F88
void func_003A0F88(int d)
{
    int r;
    func_003A0DE8();
    r = -(*(volatile unsigned int *)0x10002020 & 7) & 7;
    if (r)
        func_003A0E20(d, r);
}
