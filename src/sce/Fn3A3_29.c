// COMPILER: ee-gcc2.9-991111

struct Gs {
    short m_0;
    char _pad[6];
    int m_8;
    int m_C;
};
extern struct Gs *func_00395388(void);
extern void func_003B0130(void);
extern long func_003B01C0(void);

#ifdef NONMATCHING
// DRAFT: GAME 0x395398
// diff: 14 words (compare/shift order on b path)
int func_00395398(void)
{
    struct Gs *p = func_00395388();
    if (p->m_8 == 0) {
        func_003B0130();
        if (p->m_0 == 1)
            return (*(volatile unsigned long *)0x12001000 >> 13) & 1;
    } else {
        int b = (func_003B01C0() >> 13) & 1;
        return p->m_0 == 1 ? b : 1;
    }
    return 1;
}
#endif

extern int sceOpen(const char *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(const char *);
extern char D_0045DF50[];

// FUNCTION: GAME 0x3964C0
int func_003964C0(void)
{
    char buf[0x100];
    int fd = sceOpen(D_0045DF50, 1);
    unsigned i;
    char *p;
    if (fd < 0)
        return -1;
    i = 0;
    p = buf;
    while (i < 0x100) {
        sceRead(fd, p, 1);
        if (*p++ == 0)
            break;
        i++;
    }
    sceClose(fd);
    return atoi(buf + (i - 9)) > 0x1315670;
}

extern void func_003B06D8(int);
extern void func_003B0740(int);
extern void func_003AF9A0(int, int);
extern int func_003AF980(int, int, int);

// FUNCTION: GAME 0x395F68
int func_00395F68(int a)
{
    struct Gs *p = func_00395388();
    int old = p->m_8;
    if (a == 0) {
        func_003B06D8(2);
        func_003AF9A0(2, p->m_C);
        p->m_C = 0;
        p->m_8 = 0;
    } else {
        if (old != 0) {
            func_003B06D8(2);
            func_003AF9A0(2, p->m_C);
        }
        p->m_8 = a;
        p->m_C = func_003AF980(2, a, -1);
        func_003B0740(2);
    }
    return old;
}

extern int D_003F86A0, D_003F86A4, D_003F8674, D_003F8668, D_003F8654;
extern int D_0077C3C0, D_003F8660, D_003F866C, D_003F8670;
extern void iSignalSema(int);
extern void SignalSema(int);
extern void DeleteSema(int);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern void func_003B2500(int);

// FUNCTION: GAME 0x3984D8
void func_003984D8(int *a)
{
    D_003F86A0 = *a;
    D_003F86A4 = D_003F86A0;
    if (D_003F86A0 == 0xB) {
        D_003F86A0 = 0;
        D_003F8674 = 0;
        return;
    }
    iSignalSema(D_003F8668);
    if (D_003F8654 && D_0077C3C0)
        iSignalSema(D_003F8660);
    else
        D_003F8674 = 0;
    D_003F86A0 = 0;
}

// FUNCTION: GAME 0x398720
void func_00398720(void)
{
    int en;
    if (D_003F8654) {
        D_003F86A0 = -1;
        SignalSema(D_003F8660);
    }
    DeleteSema(D_003F8668);
    DeleteSema(D_003F866C);
    DeleteSema(D_003F8670);
    DeleteSema(D_003F8660);
    en = func_003B63A0();
    func_003B2500(0x80000012);
    if (en)
        func_003B63F0();
}

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

// FUNCTION: GAME 0x398DA0
int func_00398DA0(int a)
{
    if (a == 0) {
        if (D_003F8650 > 0)
            scePrintf(D_0045E2A0);
        while (D_003F8674 || func_003B3328(D_003F9810))
            DelayThread(4000);
        return 0;
    }
    {
        int r = 1;
        if (!D_003F8674) {
            if (!func_003B3328(D_003F9810))
                r = 0;
        }
        return r;
    }
}
