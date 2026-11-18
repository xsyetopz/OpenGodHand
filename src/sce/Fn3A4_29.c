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


extern int D_003F9840[];
extern char D_003FA1C0[];
extern int D_003F866Cn __asm__("D_003F866C");
extern volatile int D_003F866C;
extern int func_00398EB0(int);
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

extern int D_003F9C80;
extern int D_003FA1E8, D_003FA1EC, D_003FA1F0;
extern void sceSifWriteBackDCache(void *, int);

// FUNCTION: GAME 0x399BD8
int func_00399BD8(int a)
{
    int r;
    int *p = &D_003F9C80;
    if (func_00398EB0(0x22) == 0)
        return 0;
    D_003F9C80 = a;
    sceSifWriteBackDCache(p, 4);
    if (sceSifCallRpc(D_003FA1C0, D_003FA1E8, 0, p, D_003FA1EC, D_003F9840, D_003FA1F0, 0, 0) < 0) {
        SignalSema(D_003F866Cn);
        return 0;
    }
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866Cn);
    return r;
}

#define F(s, o) (*(int *)((char *)(s) + (o)))
extern char D_0045E548[], D_0045E568[];
extern void func_0039C390(void *, char *);
extern int func_0039D5B8(void *);

// FUNCTION: GAME 0x39ACD8
int func_0039ACD8(char *s)
{
    int st, r;
    int *q;
    if (F(s, 0x184) == 3 && F(s, 0x130)) {
        func_0039C390(s, D_0045E548);
        F(s, 0x130) = 0;
    }
    st = F(s, 0x184);
    switch (st) {
    case 3:
        q = (int *)F(s, 0x1D0);
        break;
    case 1:
        q = (int *)F(s, 0x1E0);
        break;
    case 2:
        q = (int *)F(s, 0x1F0);
        break;
    default:
        q = (int *)F(s, 0x1D0);
        func_0039C390(s, D_0045E568);
        break;
    }
    r = func_0039D5B8(s);
    if (r)
        q[10] = 1;
    return r;
}
