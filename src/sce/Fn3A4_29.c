// COMPILER: ee-gcc2.9-991111

extern int D_003F86A0, D_003F8674, D_003F8650;
extern int D_0077C3C0;
extern void SignalSema(int);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
struct Gs {
    short m_0;
    char _pad[4];
    short m_6;
    int m_8;
    int m_C;
};
extern struct Gs *func_00395388(void);
#define R32(a) (*(volatile unsigned int *)(a))

extern int D_0077C300[];
extern char D_0077C0C0[];
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_00397E18(int, int, int);

// FUNCTION: GAME 0x3982C8
int func_003982C8(int a, int b, int c)
{
    D_0077C300[0] = 10;
    D_0077C300[1] = a;
    D_0077C300[2] = b;
    D_0077C300[3] = c;
    if (sceSifCallRpc(D_0077C0C0, 1, 0, D_0077C300, 0x80, D_0077C300, 0x80, 0, 0) < 0)
        return 0;
    {
        int r = D_0077C300[4];
        if (r == 1) {
            func_00397E18(a, b, 2);
            r = D_0077C300[4];
        }
        return r;
    }
}

struct Ob {
    char _pad[0x38];
    int m_38;
    char _pad2[4];
    long m_40;
};
extern long func_003B0268(int, int, int);

// FUNCTION: GAME 0x3932B8
long func_003932B8(struct Ob *o, char *buf, long n)
{
    long k = -1;
    long left = n;
    long r;
    while (left > 0) {
        r = func_003B0268(o->m_38, (int)buf, left);
        if (r == k) {
            *(int *)o |= 0x20;
            break;
        }
        left -= r;
        buf += r;
    }
    n -= left;
    if (o->m_40 >= 0)
        o->m_40 += n;
    return n;
}

extern void func_003BAD80(void);
#define R32(a) (*(volatile unsigned int *)(a))

#ifdef NONMATCHING
// DRAFT: GAME 0x39A8E8
// diff: 5 words (store/hi-lo form of last two writes)
int func_0039A8E8(void)
{
    int en = func_003B63A0();
    R32(0x1000F590) = R32(0x1000F520) | 0x10000;
    R32(0x1000B000) &= 0xFFFFFEFF;
    R32(0x1000B400) &= 0xFFFFFEFF;
    R32(0x1000F590) = R32(0x1000F520) & 0xFFFEFFFF;
    if (en)
        func_003B63F0();
    {
        volatile unsigned int *a = (volatile unsigned int *)0x1000B020;
        unsigned int *b = (unsigned int *)0x1000B420;
        *a = 0;
        *b = 0;
    }
    func_003BAD80();
    return 1;
}
#endif

extern int D_003F8650;
extern char D_0045E2A0[];
extern char D_003F9810[];
extern int scePrintf(const char *, ...);
extern void DelayThread(int);
extern int func_003B3328(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x398DA0
// diff: 10 words (tail select form)
int func_00398DA0(int a)
{
    if (a == 0) {
        if (D_003F8650 > 0)
            scePrintf(D_0045E2A0);
        while (D_003F8674 || func_003B3328(D_003F9810))
            DelayThread(4000);
        return 0;
    }
    if (D_003F8674)
        return 1;
    if (func_003B3328(D_003F9810) == 0)
        return 0;
    return 1;
}
#endif

// FUNCTION: GAME 0x398070
int func_00398070(int a, int b, int c, int d)
{
    D_0077C300[0] = 6;
    D_0077C300[1] = a;
    D_0077C300[2] = b;
    D_0077C300[3] = c;
    D_0077C300[4] = d;
    if (sceSifCallRpc(D_0077C0C0, 1, 0, D_0077C300, 0x80, D_0077C300, 0x80, 0, 0) < 0)
        return 0;
    {
        int r = D_0077C300[5];
        if (r == 1) {
            func_00397E18(a, b, 2);
            r = D_0077C300[5];
        }
        return r;
    }
}

// FUNCTION: GAME 0x3968E8
void func_003968E8(unsigned long *p)
{
    if (func_00395388()->m_6 == 1) {
        *(volatile unsigned long *)0x12000000 = p[0];
        *(volatile unsigned long *)0x12000070 = p[2];
        *(volatile unsigned long *)0x12000080 = p[3];
        *(volatile unsigned long *)0x120000C0 = p[4];
    } else {
        *(volatile unsigned long *)0x12000000 = p[0];
        *(volatile unsigned long *)0x12000020 = p[1];
        *(volatile unsigned long *)0x12000090 = p[2];
        *(volatile unsigned long *)0x120000A0 = p[3];
        *(volatile unsigned long *)0x120000E0 = p[4];
    }
}

// FUNCTION: GAME 0x3981F0
int func_003981F0(int a, int b, char *c)
{
    int *p = D_0077C300;
    char *q;
    int i;
    D_0077C300[0] = 8;
    p[1] = a;
    p[2] = b;
    q = (char *)(p + 3);
    for (i = 0; i < 6; i++)
        q[i] = c[i];
    if (sceSifCallRpc(D_0077C0C0, 1, 0, p, 0x80, p, 0x80, 0, 0) < 0)
        return 0;
    {
        int r = p[5];
        if (r == 1) {
            func_00397E18(a, b, 2);
            r = p[5];
        }
        return r;
    }
}

// FUNCTION: GAME 0x39C140
int func_0039C140(int unused, unsigned int *p)
{
    unsigned int n;
    R32(0x1000E010) = 0x10;
    n = p[0];
    if (n == 0) {
        __asm__ volatile("sync\n\tei");
        return 1;
    }
    if (n > 0xFFFF) {
        R32(0x1000B410) = p[1];
        R32(0x1000B420) = 0xFFFF;
        R32(0x1000B400) = 0x101;
        p[1] = (p[1] + 0xFFFF0) & 0xFFFFFFF;
        p[0] = p[0] - 0xFFFF;
    } else {
        R32(0x1000B410) = p[1];
        R32(0x1000B420) = p[0];
        R32(0x1000B400) = 0x101;
        p[0] = 0;
    }
    __asm__ volatile("sync\n\tei");
    return 0;
}

extern char D_0045E400[];
extern void func_0039C390(void *, char *);
#define F(s, o) (*(int *)((char *)(s) + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x399D70
// diff: 2 words (lui/ori constant scheduling)
void func_00399D70(char *s)
{
    R32(0x10002010) = (R32(0x10002010) & 0xFF7FFFFF) | 0x800000;
    if (F(s, 0x87C) == 0) {
        F(s, 0x830) = 0x70003600;
        F(s, 0x5A0) = 0x70000000;
        F(s, 0x5A4) = 0x70001800;
        F(s, 0x6E0) = 0x70001B00;
        F(s, 0x6E4) = 0x70003300;
        F(s, 0x820) = 0;
    } else if (F(s, 0x87C) == 1) {
        F(s, 0x830) = (int)(s + 0xE80);
        F(s, 0x5A4) = ((int)(s + 0x880) & 0xFFFFFFF) | 0x30000000;
        F(s, 0x6E4) = ((int)(s + 0xB80) & 0xFFFFFFF) | 0x30000000;
        F(s, 0x5A0) = 0;
        F(s, 0x6E0) = 0;
        F(s, 0x820) = 0;
    } else
        func_0039C390(s, D_0045E400);
}
#endif

extern int D_003F9840[];
extern volatile int D_003F86A0v __asm__("D_003F86A0");
extern char D_003FA1C0[];
extern volatile int D_003F866C;
extern int D_003F866Cn __asm__("D_003F866C");
extern int func_00398EB0(int);

#ifdef NONMATCHING
// DRAFT: GAME 0x399B20
// diff: 2 words (or/lw order before SignalSema)
int func_00399B20(void)
{
    int r;
    if (func_00398EB0(0x1E) == 0)
        return 0;
    D_003F86A0v = 8;
    if (sceSifCallRpc(D_003FA1C0, 0x16, 0, 0, 0, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        D_003F86A0v = 0;
        return 0;
    }
    D_003F86A0v = 0;
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866Cn);
    return r;
}
#endif

extern int D_0045E3C0[];
extern int scePrintf(const char *, ...);

// FUNCTION: GAME 0x399A68
int func_00399A68(void)
{
    int r;
    if (func_00398EB0(2) == 0)
        return -1;
    if (sceSifCallRpc(D_003FA1C0, 0xC, 0, 0, 0, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866Cn);
        return -1;
    }
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866Cn);
    if (D_003F8650 < 2)
        return r;
    scePrintf((char *)D_0045E3C0);
    return r;
}

extern char D_0045E610[];
extern void func_0039AB20(int, int *);

#ifdef NONMATCHING
// DRAFT: GAME 0x39C2C8
// diff: 7 words (arg load vs MMIO store order)
void func_0039C2C8(char *s)
{
    int t[8], en, h;
    func_0039C390(s, D_0045E610);
    t[0] = 2;
    func_0039AB20(F(s, 0x868), t);
    h = F(s, 0x868);
    R32(0x10002010) = 0x40000000;
    t[0] = 3;
    func_0039AB20(h, t);
    en = func_003B63A0();
    R32(0x1000F590) = R32(0x1000F520) | 0x10000;
    R32(0x1000B000) = 0;
    R32(0x1000F590) = R32(0x1000F520) & 0xFFFEFFFF;
    if (en)
        func_003B63F0();
    R32(0x1000B020) = 0;
}
#endif
