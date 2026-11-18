struct B32 {
    unsigned m0;
    int m4, m8, mC;
    int w10[2];
    char pad18[0x28];
    struct { int a40, a44; unsigned a48; int a4C; } r[2];
    int w60[2];
    unsigned m68;
    int m6C;
    unsigned m70, m74;
    char pad78[0x0C];
    int w84[4];
};
extern "C" int func_003B2148(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2D3278
// 47 differing words: original recomputes b+(i<<4) four times (no CSE) and sets s2 per branch; tried if/else order swaps, raw offset arithmetic, q pointer
extern "C" void func_002D3278(B32 *b, int i)
{
    unsigned n;
    if (b->m4 == 0) {
        n = b->m74;
    } else {
        unsigned a = b->m74;
        unsigned c = b->m68;
        n = (a < c) ? a : c;
    }
    if (n == 0) {
        b->w10[i] = 3;
    } else {
        int o = i << 4;
        *(int *)((int)b + o + 0x40) = b->m8 + b->m70;
        int k = i << 2;
        int s;
        if (b->m4 == 0) {
            s = i << 2;
            *(int *)((int)b + o + 0x44) = b->mC + b->m70;
        } else {
            s = k;
            *(int *)((int)b + o + 0x44) = *(int *)((int)b + k + 0x84);
        }
        char *q = (char *)b + o;
        *(unsigned *)(q + 0x48) = n;
        *(int *)(q + 0x4C) = 0;
        *(int *)((int)b + s + 0x60) = func_003B2148((char *)b + (o + 0x40), 1);
        b->m70 += n;
        b->m74 -= n;
        b->m0 |= 2;
    }
}
#endif
