// ProDG-built (sq prologue) units inside the 0x3B0000+ library span.
extern "C" int *func_003BB058(int *);
extern "C" void *malloc(unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" int *func_0031D6E8(int);
extern "C" int *func_0031D928(int);
extern int *D_003C4030[];


// FUNCTION: GAME 0x3BB468
extern "C" int **func_003BB468(int **src, int **end, int **dst)
{
    for (; src != end; dst++, src++) {
        if (dst) {
            int *v = *src;
            int *a = v - 4;
            if (a[3] != 0)
                v = func_003BB058(a);
            else
                a[2]++;
            *dst = v;
        }
    }
    return dst;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3BB058 (compiler folds tot=0x20 and allocates s3; original keeps cap+16 unfolded in 3 s-regs)
extern "C" int *func_003BB058(int *s)
{
    unsigned cap = 16;
    unsigned tot = cap + 16;
    int *p;
    if (cap < (unsigned)(s[0] + 1)) {
        do {
            cap <<= 1;
        } while (cap < (unsigned)(s[0] + 1));
        tot = cap + 16;
    }
    if (tot > 0x80) {
        p = (int *)malloc(tot);
        if (!p)
            p = func_0031D6E8(tot);
    } else {
        int **slot = (int **)((char *)D_003C4030 + ((((cap + 23) >> 3) - 1) << 2));
        int *h = *slot;
        if (h) {
            p = h;
            *slot = *(int **)h;
        } else {
            p = func_0031D928((cap + 23) & ~7);
        }
    }
    p[1] = cap;
    p[2] = 1;
    p[3] = 0;
    if (s[0])
        memcpy(p + 4, s + 4, s[0]);
    p[0] = s[0];
    return p + 4;
}
#endif

struct Ent8 {
    int *p;
    char c;
};

// FUNCTION: GAME 0x3BB980
extern "C" Ent8 *func_003BB980(Ent8 *src, Ent8 *end, Ent8 *dst)
{
    for (; src != end; dst++, src++) {
        if (dst) {
            int *v = src->p;
            int *a = v - 4;
            if (a[3] != 0)
                v = func_003BB058(a);
            else
                a[2]++;
            dst->p = v;
            dst->c = src->c;
        }
    }
    return dst;
}
