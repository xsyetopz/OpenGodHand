// COMPILER: ee-gcc2.9-991111

#ifdef NONMATCHING
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
