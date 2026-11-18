// COMPILER: ee-gcc2.9-991111
extern int func_003B63A0(void);
extern void func_003B63F0(void);

struct E {
    char _p[0x10];
    unsigned f;
    struct E *m14;
    int m18;
    char _q[0x24];
};
struct T {
    int m0;
    struct E *m4;
    int m8;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x3B2AC8
// diff: 21 words (return 0 not placed in jal delay slot)
struct E *func_003B2AC8(struct T *t)
{
    struct E *e;
    int i;
    int c;
    func_003B63A0();
    e = t->m4;
    for (i = 0; i < t->m8; i++, e++) {
        if ((e->f & 1) == 0) {
            e->f = (i << 16) | 5;
            c = t->m0 + 1;
            t->m0 = c;
            if (c == 1) {
                t->m0 = c + 1;
            }
            e->m14 = e;
            e->m18 = c;
            func_003B63F0();
            return e;
        }
    }
    func_003B63F0();
    return 0;
}
#endif

extern struct { char _p[0x18]; struct L *m18; } D_003FBE90;
struct L {
    struct L *m0;
    struct L *m4;
    char _p[8];
    long m10;
    long m18;
    long m20;
};

// FUNCTION: GAME 0x3B6DB8
void *func_003B6DB8(struct L *n)
{
    struct L *prev;
    struct L *cur;
    unsigned long end;
    prev = 0;
    end = n->m20 + n->m10 - n->m18;
    for (cur = D_003FBE90.m18; cur != 0; prev = cur, cur = prev->m0) {
        if (end < cur->m20 + cur->m10 - cur->m18) {
            break;
        }
    }
    n->m4 = prev;
    n->m0 = cur;
    if (cur != 0) {
        cur->m4 = n;
    }
    if (prev != 0) {
        prev->m0 = n;
        return &D_003FBE90;
    }
    D_003FBE90.m18 = n;
    return &D_003FBE90;
}

extern unsigned long D_003FBE90q __asm__("D_003FBE90");

#ifdef NONMATCHING
// DRAFT: GAME 0x3B7180
// diff: 20 words (lwu base reg allocation)
unsigned long func_003B7180(void)
{
    int r;
    unsigned long cnt;
    unsigned long hi;
    unsigned int mode;
    int sh;
    unsigned int *p = (unsigned int *)0x10001000;
    r = func_003B63A0();
    cnt = p[0];
    mode = p[4];
    hi = D_003FBE90q;
    if (mode & 0x800) {
        __asm__ volatile("" : : : "memory");
        cnt = p[0];
        hi++;
    }
    mode &= 3;
    sh = mode ? 2 : 0;
    sh <<= mode;
    cnt = (cnt | (hi << 16)) << sh;
    if (r) {
        func_003B63F0();
    }
    return cnt;
}
#endif

struct H {
    char _p[8];
    int m8;
    unsigned mC;
    long m10;
};
struct G {
    char _p[0x1C];
    int m1C;
};
extern struct G D_003FBE90s __asm__("D_003FBE90");
extern long func_003B7130(void);
extern void func_003B6C28(long);

// FUNCTION: GAME 0x3B72D0
int func_003B72D0(int h)
{
    struct H *n = (struct H *)((unsigned)h >> 10 << 6);
    long s;
    struct G *g;
    if (h < 0 || (h & 0x3FF) != n->m8) {
        return 0x80008002;
    }
    g = &D_003FBE90s;
    if (*(volatile int *)&g->m1C == h) {
        return 0x80000010;
    }
    if ((n->mC & 1) == 0) {
        s = func_003B7130();
        n->m10 = s;
        n->mC |= 1;
        if (n->mC & 2) {
            func_003B6DB8((struct L *)n);
            func_003B6C28(s);
        }
        return 0;
    }
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3B3400
// diff: 8 words; the store of e->m_3C lands in the bnez delay slot in mine, the original stores m_3C first and m_40 in the delay slot (5 variants tried)
struct RpcEv {
    int m_0;
    int m_4;
    int m_8;
    int _pC;
    int m_10;
    int m_14;
    char _p18[0x20];
    struct RpcEv *m_38;
    int m_3C;
    struct RpcQ *m_40;
};
struct RpcQ {
    int _p0[2];
    struct RpcEv *m_8;
};
extern int func_003B63A0(void);
extern void func_003B63F0(void);
void sceSifRegisterRpc(struct RpcEv *e, int a, int b, int c, int d, int f, struct RpcQ *q)
{
    struct RpcEv *p;
    func_003B63A0();
    e->m_3C = 0;
    e->m_38 = 0;
    e->m_0 = a;
    e->m_4 = b;
    e->m_8 = c;
    e->m_10 = d;
    e->m_14 = f;
    e->m_40 = q;
    if (q->m_8 == 0) {
        q->m_8 = e;
    } else {
        for (p = q->m_8; p->m_38; p = p->m_38)
            ;
        p->m_38 = e;
    }
    func_003B63F0();
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B2080
// diff: 2 words; original loads D_0077E520 after the addiu of D_00460040 (3 variants tried)
struct RpcEnt {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
};
extern void *memcpy(void *, const void *, unsigned);
extern int D_0077E520;
extern char D_00460040[];
extern int func_003B0060();
extern int func_003B0070();
int func_003B2080(void *src, int n, int flag)
{
    struct RpcEnt buf[32];
    if (n < 0x20) {
        memcpy(buf, src, n << 4);
        buf[n].m_0 = (int)D_00460040;
        buf[n].m_4 = D_0077E520;
        buf[n].m_8 = 0x10;
        buf[n].m_C = 0x44;
        n++;
        if (flag == 0)
            return func_003B0060(buf, n);
        return func_003B0070(buf, n);
    }
    return 0;
}
#endif
