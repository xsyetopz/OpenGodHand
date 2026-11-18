// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ dtoa/mprec bit helpers (same family as the Bigint helpers in Fn39s_29.c).

// FUNCTION: GAME 0x38F838
int func_0038F838(unsigned int x)
{
    int k = 0;

    if (!(x & 0xFFFF0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xFF000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xF0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xC0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000))
            return 32;
    }
    return k;
}

// FUNCTION: GAME 0x38F8C0
int func_0038F8C0(unsigned int *y)
{
    int k;
    unsigned int x = *y;

    if (x & 7) {
        if (x & 1)
            return 0;
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xFFFF)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xFF)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xF)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 0x3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x)
            return 32;
    }
    *y = x;
    return k;
}

#define word0(x) ((unsigned int *)&x)[1]
#define word1(x) ((unsigned int *)&x)[0]
#define setwords(D, W0, W1) (word0(D) = (W0), word1(D) = (W1))

// FUNCTION: GAME 0x38FFE0
double func_0038FFE0(double x)
{
    register int L;
    double a;

    L = (word0(x) & 0x7FF00000) - 0x3400000;
    if (L > 0) {
        setwords(a, L, 0);
    } else {
        L = -L >> 20;
        if (L < 20)
            setwords(a, 0x80000 >> L, 0);
        else {
            L -= 20;
            setwords(a, 0, L >= 31 ? 1 : 1 << (31 - L));
        }
    }
    return a;
}
