// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE DMA and GS helpers.

#define REG(a) (*(volatile unsigned int *)(a))

struct Dma {
    char _pad[0x1C0];
    int m_1C0;
    char _pad2[0x828 - 0x1C4];
    int m_828;
};
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern void func_003BACA0(int, int);

// FUNCTION: GAME 0x39A078
void func_0039A078(struct Dma *d)
{
    int r;
    d->m_828 = 1;
    d->m_1C0 = 0;
    r = func_003B63A0();
    REG(0x1000F590) = REG(0x1000F520) | 0x10000;
    REG(0x1000B000) = 0;
    REG(0x1000B400) = 0;
    REG(0x1000D400) = 0;
    REG(0x1000F590) = REG(0x1000F520) & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
    REG(0x1000B020) = 0;
    REG(0x1000B420) = 0;
    REG(0x1000D420) = 0;
    REG(0x10002010) = 0x40000000;
    func_003BACA0(0, 0);
}

extern int scePrintf(const char *, ...);
extern char D_0045DF98[];

// FUNCTION: GAME 0x396D60
int func_00396D60(unsigned long *p)
{
    unsigned int i = 0;
    while (REG(0x1000A000) & 0x100) {
        if (i++ > 0x1000000) {
            scePrintf(D_0045DF98);
            return -1;
        }
    }
    REG(0x1000A020) = (int)(*p & 0x7FFF) + 1;
    if (((unsigned int)p & 0x70000000) == 0x70000000)
        REG(0x1000A010) = ((unsigned int)p & 0xFFFFFFF) | 0x80000000;
    else
        REG(0x1000A010) = (unsigned int)p & 0xFFFFFFF;
    REG(0x1000A000) = 0x101;
    return 0;
}

extern unsigned long *func_00395388(void);

// FUNCTION: GAME 0x3969A8
short func_003969A8(short a, short b, short c)
{
    unsigned long *p = func_00395388();
    int bw = (b + 63) / 64;
    int cw;
    int m;
    if (a & 2)
        cw = (c + 63) / 64;
    else
        cw = (c + 31) / 32;
    if ((*p & 0xFFFF0000FFFFUL) == 1)
        return bw * cw;
    return bw * cw * 2;
}

struct E39 {
    char _pad[0x10];
    int m_10;
    int m_14;
    int m_18;
};
struct G39 {
    struct E39 e[4];
};
struct Rpc {
    int m_0;
    int _p4[2];
    int m_C;
    int m_10;
    int m_14;
};
extern struct G39 D_0077C110[];
extern struct Rpc D_0077C300;
extern char D_0077C0C0[];
extern int D_003F85D4;
extern int D_003F85D0;
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern void func_003B2488(unsigned int, void (*)(), int);
extern void func_00397780();

#ifdef NONMATCHING
// DRAFT: GAME 0x3977C8
// diff: 3 words; the store s->m_10 = 0 is scheduled after the a0 addiu in the original.
int func_003977C8(void)
{
    int i;
    struct Rpc *s;
    int r;
    for (i = 0; i < 4; i++) {
        D_0077C110[0].e[i].m_10 = 0;
        D_0077C110[0].e[i].m_18 = 0;
        D_0077C110[0].e[i].m_14 = 0;
        D_0077C110[1].e[i].m_10 = 0;
        D_0077C110[1].e[i].m_18 = 0;
        D_0077C110[1].e[i].m_14 = 0;
    }
    s = &D_0077C300;
    s->m_10 = 0;
    D_0077C300.m_0 = 0x10;
    s->m_14 = D_003F85D4;
    if (sceSifCallRpc(D_0077C0C0, 1, 0, s, 0x80, s, 0x80, 0, 0) < 0)
        return 0;
    D_003F85D0 = 0;
    r = func_003B63A0();
    func_003B2488(0x80000019, func_00397780, 0);
    if (r == 1)
        func_003B63F0();
    return s->m_C;
}
#endif
