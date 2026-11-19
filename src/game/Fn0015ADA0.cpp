// Units at 0x15ADA0, 0x178618, 0x2D4C20, 0x300458, 0x308BC0.
extern char D_0071B940[], D_00741940[], D_00741960[], D_00741980[];
extern "C" void *func_00304D48(void *);
extern "C" void *func_00304D70(void *);
extern "C" void *func_00304DB0(void *);
extern "C" void *func_00304DF0(void *);
extern "C" void *memset(void *d, int c, unsigned int n);
extern "C" void func_002D4DA0(int, int, int, int);
extern "C" char *objbaseArray;
extern "C" char *getMeshPtr__6cModeli(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x300458
// 66 differing words (vs 380 bytes). Frame and dispatch match; loop shape and lt2 slti order still differ. Tried: switch dispatch (95), if-chain (94), hoisted constants (77), signed kind (77), c/b pointer order (66).
extern "C" void *func_00300458(int arg)
{
    int kind = arg & 0xFF;
    int lt2 = kind < 2;
    int k1 = 1;
    int k2 = 2;
    int k3 = 3;
    char *blk = D_0071B940;
    unsigned i = 0;
    do {
        unsigned off = (i >> 5) * 4;
        unsigned bit = 0x80000000u >> (i & 0x1F);
        unsigned *used = (unsigned *)(D_00741940 + off);
        unsigned w = *used;
        i++;
        if (!(w & bit)) {
            unsigned *c = (unsigned *)(D_00741960 + off);
            unsigned *b = (unsigned *)(D_00741980 + off);
            unsigned nm = ~bit;
            *used = w | bit;
            *c &= nm;
            *b &= nm;
            memset(blk, 0, 0x260);
            char *r;
            if (kind == k1) r = (char *)func_00304D70(blk);
            else if (lt2) r = (char *)func_00304D48(blk);
            else if (kind == k2) r = (char *)func_00304DB0(blk);
            else if (kind == k3) r = (char *)func_00304DF0(blk);
            else r = (char *)func_00304D48(blk);
            r[0x190] = kind;
            return r;
        } else {
            blk += 0x260;
            if ((int)i >= 0x100) {
                return 0;
            }
        }
    } while (1);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2D4C20
// 80 differing words (412 vs 384 bytes; frame 0xD0 vs 0xC0). Tried: hoisted volatile pointers (96), unsigned mask local (102). Frame size unresolved.
extern "C" void func_002D4C20(int arg0, int arg1, int arg2, int arg3)
{
    int sh = arg3 << 2;
    int v1;
    int s0;
    int s2;
    unsigned s3;
    *(volatile unsigned *)0x1000E020 = 0xFFFFFC00u;
    *(volatile unsigned *)0x1000E010 = 0x200;
    *(volatile unsigned *)0x1000D410 = arg2;
    *(volatile unsigned *)0x1000D420 = 0x40;
    *(volatile unsigned *)0x1000D480 = 0x70000000u;
    *(volatile unsigned *)0x1000E020 |= 0x200;
    *(volatile unsigned *)0x1000D400 = 0x101;
    func_002D4DA0(arg0, arg1, 0x1000D400, sh);
    v1 = 0x100;
    s0 = arg1;
    s2 = 0xF;
    s3 = 0x70000000u;
    do {
        s2 -= 1;
        *(volatile unsigned *)0x1000E020 = 0xFFFFFC00u;
        *(volatile unsigned *)0x1000E010 = v1;
        *(volatile unsigned *)0x1000D010 = s0;
        *(volatile unsigned *)0x1000D020 = 4;
        *(volatile unsigned *)0x1000D080 = s3;
        s0 += sh;
        s3 += 0x40;
        *(volatile unsigned *)0x1000E020 |= 0x100;
        *(volatile unsigned *)0x1000D000 = v1;
        func_002D4DA0(arg0, arg1, 0x1000D400, sh);
    } while (s2 >= 0);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x308BC0
// 59 differing words (320 vs 384 bytes); loop 1 matches, loop 2 range tests are about 16 instructions short. Tried: nested unsigned char flag (61), ternary ranges with unsigned short (61), int v (61), if/else range chain (61).
extern "C" void func_00308BC0(void *arr)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        char *p = *(char **)((int)arr + (i << 2));
        if (p) {
            char *m = getMeshPtr__6cModeli(p, 0);
            if (m) {
                do {
                    *(unsigned *)(m + 0x380) &= 0xFFFFFFFEu;
                    m = *(char **)(m + 0x404);
                } while (m);
            }
        }
    }
    unsigned a = *(unsigned *)(objbaseArray + 4);
    if (a < *(unsigned *)(objbaseArray + 8)) {
        do {
            char *o = *(char **)a;
            unsigned short v = *(unsigned short *)(o + 0x2FE);
            int f = 0;
            if (v >= 0x100 && v < 0x1FF) f = 1;
            else if (v >= 0x200 && v < 0x300) f = 1;
            else if (v >= 0x300 && v < 0x500) f = 1;
            else if (v >= 0x500 && v < 0x600) f = 1;
            if (f) *(unsigned *)(o + 0x5A0) &= 0xFFFFFFFDu;
            a += 4;
        } while (a < *(unsigned *)(objbaseArray + 8));
    }
}
#endif
