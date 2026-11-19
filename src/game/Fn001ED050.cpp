struct T40 { int a[10]; };
extern T40 D_0042BD70;
extern "C" void SetNumber__12CustomIDWorki(char *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1ED050
// 56 words off: s-reg allocation (offset s2, 10 in s0, 0x7C in s3) and div/mult order; tried n%10, n-q*10, (n/10)*10, &t.a[1]+o.
extern "C" void func_001ED050(char *self, unsigned short i, int n)
{
    if (i < 5) {
        T40 t = D_0042BD70;
        if (n >= 1000)
            n = 999;
        int o = i << 3;
        int q = n / 10;
        SetNumber__12CustomIDWorki(self + (*(int *)((int)&t + o) * 0x7C + 0x60), q);
        SetNumber__12CustomIDWorki(self + (*(int *)((int)&t.a[1] + o) * 0x7C + 0x60), n - (n / 10) * 10);
    }
}
#endif
