// COMPILER: ee-gcc2.9-991111
extern int func_003B6990();
extern int func_003B63A0();
extern void func_003B63F0();
extern int func_003B7200();
extern int func_003B72D0();
extern int func_003B7400();
extern int func_003B00B0();
extern void func_003B0120();
extern void func_003B79C0();

// FUNCTION: GAME 0x3B7270
int func_003B7270(void)
{
    int s = func_003B63A0();
    int r = func_003B7200();
    if (s)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B7380
int func_003B7380(int a)
{
    int s = func_003B63A0();
    int r = func_003B72D0(a);
    if (s)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B6240
int func_003B6240(void)
{
    if (func_003B00B0(4) & 0x40000) {
        func_003B0120();
        func_003B79C0(1, 1);
        func_003B79C0(0, 1);
        return 1;
    }
    return 0;
}

struct Cell {
    struct Cell *next;
    int x;
    int (*fn)();
    int arg;
};
extern struct Cell D_00783C40[64];
extern struct Cell *D_00784040;

// FUNCTION: GAME 0x3B76B8
int func_003B76B8(void)
{
    int i;
    D_00784040 = D_00783C40;
    for (i = 63; i >= 0; i--)
        D_00783C40[i].next = &D_00783C40[i + 1];
    D_00783C40[63].next = 0;
    return 0;
}

// DRAFT: GAME 0x3B7708
// diff: free-list push in the r==0 path is scheduled differently (D_00784040 lui/lw order, ra reload duplicated in original)
#ifdef NONMATCHING
int func_003B7708(int a, int b, int c, struct Cell *n)
{
    int r = n->fn(((int)n << 4) | (a & 0xFE) | 1, b, c, n->arg);
    if (r)
        return r;
    n->next = D_00784040;
    D_00784040 = n;
    n->x = 0;
    return -1;
}
#endif

extern long long func_0031E870();
extern long long func_0031E2E0();
extern long long func_003B8730();

// DRAFT: GAME 0x3B86D0
// diff: original keeps the zero argument in s1 across calls (frame 0x30); ours folds it into a constant (frame 0x20)
#ifdef NONMATCHING
long long func_003B86D0(long long a)
{
    long long z = 0;
    if (func_0031E870(a, z) < 0)
        return -func_003B8730(func_0031E2E0(z, a));
    return func_003B8730(a);
}
#endif

extern unsigned long long D_003FBE90;

// DRAFT: GAME 0x3B7130
// diff: original reads the u32 timer regs with lwu into 64-bit values and uses movz/dsllv (76 bytes); 2.9/2.96/3.2 emit lw+dsll32/dsrl32 (92-96 bytes)
#ifdef NONMATCHING
unsigned long long func_003B7130(void)
{
    volatile unsigned *r = (volatile unsigned *)0x10001000;
    unsigned long long v = r[0];
    unsigned m = r[4];
    unsigned long long c = D_003FBE90;
    unsigned sh;
    if (m & 0x800) {
        v = r[0];
        c++;
    }
    m &= 3;
    sh = (m ? 2 : 0) << m;
    return (v | (c << 16)) << sh;
}
#endif

// FUNCTION: GAME 0x3B7510
int func_003B7510(int a, int b, int c, int d)
{
    int s = func_003B63A0();
    int r = func_003B7400(a, b, c, d);
    if (s)
        func_003B63F0();
    return r;
}

extern int D_003FC240[];
extern int D_003FC238;
extern char D_003FBEC0[];
extern int FlushCache();
extern int func_003B7B30();
extern int func_003B7B20();
extern int func_003B7AD8();

// DRAFT: GAME 0x3B7B40
// diff: 4 words: lw a0/a1 order of the s[4]/s[5] call, and sltiu result in v1 instead of v0 (loop temp)
#ifdef NONMATCHING
void func_003B7B40(void)
{
    int *s = D_003FC240;
    int *p = s + 6;
    unsigned i = 3;
    func_003B7B30(s[0], s[1]);
    func_003B7AD8(0x80075000, D_003FBEC0, 0x330);
    FlushCache(0);
    FlushCache(2);
    func_003B7B30(s[2], s[3]);
    {
        int x = s[4];
        func_003B7B30(x, s[5]);
    }
    do {
        int r = func_003B7B20(p[0]);
        func_003B7B30(p[0], r);
        i++;
        p += 2;
    } while (i < 8);
    D_003FC238 = func_003B7B20(3);
}
#endif
