// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x390000-0x3A0000.

register int gp __asm__("$28");

#define SYSCALL_STUB(name, n) \
    void name(void) \
    { \
        __asm__ volatile("li $3,%0\n\tsyscall" ::"i"(n)); \
    }

// FUNCTION: GAME 0x396560
SYSCALL_STUB(func_00396560, 0x80)

struct Ev {
    char _pad[0x40];
    char *m_40;
};

struct Ent {
    int a;
    int b;
    int g;
};
struct Ent2 {
    int _p[4];
    int b;
    int g;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x39AAD8
// diff: 9 words, original copies gp via v1/t0 and keeps t0 base
int func_0039AAD8(struct Ev *s, int i, int a, int b)
{
    struct Ent *e = (struct Ent *)(s->m_40 + 0xC) + i;
    struct Ent2 *f = (struct Ent2 *)(s->m_40 + i * 12);
    int old = e->a;
    e->a = a;
    f->b = b;
    f->g = gp;
    return old;
}
#endif

struct Cb {
    char _pad[0xC];
    int m_C;
};
extern void (*D_003F85D0)(int);
extern int D_0077C380;

#ifdef NONMATCHING
// DRAFT: GAME 0x397780
// diff: 2 words, lui and daddu s0 order swapped (6 variants tried)
void func_00397780(struct Cb *s)
{
    if (D_003F85D0) {
        int save = gp;
        gp = D_0077C380;
        __asm__ volatile("");
        D_003F85D0(s->m_C);
        gp = save;
    }
    __asm__ volatile("sync\n\tei");
}
#endif

extern void (*D_0077C3C8)(int);
extern int D_003F8664;
extern int D_0077C3CC;
extern int D_0077C3D0;

#ifdef NONMATCHING
// DRAFT: GAME 0x3987C0
// diff: 4 words, lui/daddu s0 order and a0 load placement
void func_003987C0(void)
{
    if (D_0077C3C8 && !D_003F8664) {
        int save = gp;
        gp = D_0077C3CC;
        __asm__ volatile("");
        D_0077C3C8(D_0077C3D0);
        gp = save;
    }
}
#endif

// FUNCTION: GAME 0x393F80
int func_00393F80(unsigned int *p)
{
    unsigned int t = p[0] & 0xFFFFFF;
    if (t != 0x524E53)
        return 1;
    if ((unsigned int)(((unsigned char *)p)[3] - 0x31) < 2)
        return ((p[10] - 1) & (unsigned int)p) ? 4 : 0;
    return 2;
}

struct Ac {
    int m_0;
    int m_4;
    int m_8;
    char _pad[0x98 - 0xC];
    int m_98;
    char _pad1[0xC0 - 0x9C];
    int m_C0;
    char _pad2[0x128 - 0xC4];
    int m_128;
    char _pad3[0x858 - 0x12C];
    int m_858;
    char _pad4[0x878 - 0x85C];
    int m_878;
};
struct Ad {
    char _pad[8];
    int m_8;
    char _pad1[0x40 - 0xC];
    struct Ac *m_40;
};
extern void func_0039A078(struct Ac *);

// FUNCTION: GAME 0x39AA48
int func_0039AA48(struct Ad *d)
{
    struct Ac *s = d->m_40;
    s->m_878 = 0;
    s->m_0 = 0;
    s->m_4 = 0;
    s->m_8 = 0;
    d->m_8 = 0;
    s->m_C0 = 0;
    s->m_98 = -1;
    func_0039A078(s);
    s->m_128 = 0;
    s->m_858 = 0;
    *(volatile unsigned int *)0x10002010 = (*(volatile unsigned int *)0x10002010 & 0xFF7FFFFF) | 0x800000;
    return 1;
}

struct Tb {
    char _pad[0x10];
    int m_10;
    char _pad1[0x70 - 0x14];
};
extern struct Tb D_0077C110[];
extern void func_00397BC8(int, int, void *);
extern void *memcpy(void *, const void *, unsigned int);

#define TBE(a, b) (*(struct Tb *)((char *)D_0077C110 + (a) * 0x70 + (b) * 0x1C))

#ifdef NONMATCHING
// DRAFT: GAME 0x397D20
// diff: 9 words, mult/mult1 pipe assignment and address-add order (2 variants tried)
int func_00397D20(int a, int b, void *dst)
{
    char buf[0x80];
    if (TBE(a, b).m_10 == 0)
        return 0;
    func_00397BC8(a, b, buf);
    memcpy(dst, buf, *(int *)(buf + 0x60));
    return *(int *)(buf + 0x60);
}

// DRAFT: GAME 0x397D98
// diff: 9 words, mult/mult1 pipe assignment and address-add order (2 variants tried)
int func_00397D98(int a, int b)
{
    unsigned char buf[0x80];
    if (TBE(a, b).m_10 == 0)
        return 0x63;
    func_00397BC8(a, b, buf);
    if (buf[0x70] == 6 && buf[0x71] == 2)
        return 5;
    return buf[0x70];
}
#endif

extern int D_0077C300[];
extern char D_0077C0C0[];
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);

// FUNCTION: GAME 0x398468
int func_00398468(void)
{
    D_0077C300[0] = 0x12;
    if (sceSifCallRpc(D_0077C0C0, 1, 0, D_0077C300, 0x80, D_0077C300, 0x80, 0, 0) < 0)
        return 0;
    return D_0077C300[3];
}

extern int D_003F8650;
extern char D_0045E2B0[];
extern char D_003FA1C0[];
extern int scePrintf(const char *, ...);
extern int func_003B3328(void *);
extern int DelayThread(int);

// FUNCTION: GAME 0x398E40
int func_00398E40(int a)
{
    if (a == 0) {
        if (D_003F8650 > 0)
            scePrintf(D_0045E2B0);
        while (func_003B3328(D_003FA1C0))
            DelayThread(4000);
        return 0;
    }
    return func_003B3328(D_003FA1C0);
}

extern int D_003F8664;
extern int D_003F8688;
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern void func_003B2488(unsigned int, void (*)(void), int);
extern void func_003987C0(void);

// FUNCTION: GAME 0x398818
int func_00398818(void)
{
    int s;
    D_003F8664 = 1;
    s = func_003B63A0();
    func_003B2488(0x80000012, func_003987C0, 0);
    if (s)
        func_003B63F0();
    D_003F8664 = 0;
    D_003F8688 = 1;
    return 1;
}

struct Vt {
    char _pad[0x44];
    int (*m_44)(void *, int, int, int);
};
struct Fl {
    int m_0;
    char _pad[0x38 - 4];
    int m_38;
    char _pad1[0x40 - 0x3C];
    long m_40;
    char _pad2[0x50 - 0x48];
    struct Vt *m_50;
};
extern int *func_003A4FB8(void);

// FUNCTION: GAME 0x392998
struct Fl *func_00392998(struct Fl *f, int fd)
{
    if (f->m_38 >= 0)
        return 0;
    {
        long k = -1;
        f->m_38 = fd;
        f->m_0 = (f->m_0 & ~0xC) | 0x40;
        f->m_40 = k;
        if (f->m_50->m_44(f, 0, 1, 3) == k) {
            if (*func_003A4FB8() != 0x1D)
                return 0;
        }
    }
    return f;
}
