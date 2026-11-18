struct T5 { unsigned a[5]; };
extern T5 D_0042B8D0;
extern "C" void displayScrollLayer__FUib(unsigned, bool);

// FUNCTION: GAME 0x1E4200
extern "C" void func_001E4200(char *s, unsigned short n, int f, int g)
{
    T5 t = D_0042B8D0;
    if (n < 5) {
        unsigned w = n << 11;
        unsigned *p;
        *(unsigned short *)(s + 0x4AC) = w;
        if (g)
            *(unsigned short *)(s + 0x4AC) = w | 0x8000;
        p = (unsigned *)(s + 0x400);
        if (f) {
            *(unsigned short *)(s + 0x4AC) |= 0x4000;
            int i = 0;
            for (; i < 5; i++)
                displayScrollLayer__FUib(*(unsigned *)((char *)p + (t.a[i] << 2)), i == n);
        } else {
            unsigned *q = t.a;
            int i = 4;
            for (; i >= 0; i--)
                displayScrollLayer__FUib(*(unsigned *)((char *)p + (*q++ << 2)), 0);
        }
    }
}
