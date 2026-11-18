// COMPILER: ee-gcc2.9-991111

#ifdef NONMATCHING
// DRAFT: GAME 0x31E978 (30 words differ: block order of the cls==2 / cls<2 / cls==4 tests differs from the original)
struct F { int cls; int sign; int exp; unsigned long long frac; };
extern void func_0031DFA8(long long *, struct F *);
int func_0031E978(long long x)
{
    struct F u;
    int v;
    func_0031DFA8(&x, &u);
    if (u.cls == 2 || (unsigned)u.cls < 2)
        return 0;
    if (u.cls == 4)
        goto sat;
    if (u.exp < 0)
        return 0;
    if (u.exp >= 0x1F)
        goto sat;
    v = (int)(u.frac >> (0x3C - u.exp));
    return u.sign ? -v : v;
sat:
    return u.sign ? 0x80000000 : 0x7FFFFFFF;
}

// DRAFT: GAME 0x31DAA0 (30 words differ: 2.9 peels the first loop test and keeps the pointer and the counter in swapped s0/s1)
extern int D_003FC880[];
void func_0031DAA0(void)
{
    long long n = D_003FC880[0];
    long long t;
    int *q;
    int i;
    if (n == -1) {
        n = 0;
        if (D_003FC880[1]) {
            for (n = 1; D_003FC880[(int)(t = n + 1)]; n = t)
                ;
        }
    }
    i = (int)n;
    if (i) {
        q = &D_003FC880[i];
        do {
            ((void (*)(void))*q)();
            q--;
            i--;
        } while (i);
    }
}
#endif
