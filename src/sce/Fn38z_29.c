// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ dtoa (upstream gcc-2.95 floatconv.c): b2d, d2b.

typedef struct Bigint {
    struct Bigint *next;
    int k;
    int maxwds;
    short on_stack;
    short sign;
    int wds;
    unsigned int x[1];
} Bigint;

union doubleword {
    double d;
    unsigned int u[2];
};
#define HIWORD 1
#define LOWORD 0
#define word0(x) ({ union doubleword _du; _du.d = (x); _du.u[HIWORD]; })
#define word1(x) ({ union doubleword _du; _du.d = (x); _du.u[LOWORD]; })
#define setwords(D, W0, W1) ({ union doubleword _du; \
    _du.u[HIWORD] = (W0); _du.u[LOWORD] = (W1); (D) = _du.d; })

#define Exp_shift 20
#define Exp_msk11 0x100000
#define Exp_1 0x3ff00000
#define Bias 1023
#define P 53
#define Ebits 11
#define Frac_mask 0xfffff

extern Bigint *func_0038F5B8(Bigint *, int);
extern int func_0038F838(unsigned int);
extern int func_0038F8C0(unsigned int *);

// b2d
// FUNCTION: GAME 0x390078
double func_00390078(Bigint *a, int *e)
{
    unsigned int *xa, *xa0, w, y, z;
    int k;
    double d;
    unsigned int d0, d1;

    xa0 = a->x;
    xa = xa0 + a->wds;
    y = *--xa;
    k = func_0038F838(y);
    *e = 32 - k;
    if (k < Ebits) {
        d0 = Exp_1 | y >> (Ebits - k);
        w = xa > xa0 ? *--xa : 0;
        d1 = y << ((32 - Ebits) + k) | w >> (Ebits - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= Ebits) {
        d0 = Exp_1 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d1 = z << k | y >> (32 - k);
    } else {
        d0 = Exp_1 | y;
        d1 = z;
    }
ret_d:
    setwords(d, d0, d1);
    return d;
}

// d2b
// FUNCTION: GAME 0x3901A8
Bigint *func_003901A8(Bigint *result, double d, int *e, int *bits)
{
    int de, i, k;
    unsigned int *x, y, z;
    unsigned int d0, d1;

    d0 = word0(d);
    d1 = word1(d);

    result = func_0038F5B8(result, 1);
    x = result->x;

    z = d0 & Frac_mask;
    d0 &= 0x7fffffff;

    de = (int)(d0 >> Exp_shift);

    if (de)
        z |= Exp_msk11;

    if ((y = d1)) {
        if ((k = func_0038F8C0(&y))) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else
            x[0] = y;
        i = result->wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_0038F8C0(&z);
        x[0] = z;
        i = result->wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - Bias - (P - 1) + k;
        *bits = P - k;
    } else {
        *e = de - Bias - (P - 1) + 1 + k;
        *bits = 32 * i - func_0038F838(x[i - 1]);
    }
    return result;
}

#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, \
    ((unsigned short *)a)[0] = (unsigned short)c, a++)

// lshift
// FUNCTION: GAME 0x38FC68
Bigint *func_0038FC68(Bigint *b, int k)
{
    int i;
    unsigned int *x, *x1, *xe;
    int old_wds = b->wds;
    int n = k >> 5;
    int k1 = b->k;
    int n1 = n + old_wds + 1;

    if (k == 0)
        return b;

    for (i = b->maxwds; n1 > i; i <<= 1)
        k1++;
    b = func_0038F5B8(b, k1);

    xe = b->x;
    x = xe + old_wds;
    x1 = x + n;
    if (k &= 0x1f) {
        int k1 = 32 - k;
        unsigned int z = *--x;
        if ((*x1 = (z >> k1)) != 0) {
            ++n1;
        }
        while (x > xe) {
            unsigned int w = *--x;
            *--x1 = (z << k) | (w >> k1);
            z = w;
        }
        *--x1 = z << k;
    } else
        do {
            *--x1 = *--x;
        } while (x > xe);
    while (x1 > xe)
        *--x1 = 0;
    b->wds = n1 - 1;
    return b;
}

// cmp
// FUNCTION: GAME 0x38FDE8
int func_0038FDE8(Bigint *a, Bigint *b)
{
    unsigned int *xa, *xa0, *xb, *xb0;
    int i, j;

    i = a->wds;
    j = b->wds;
    if (i -= j)
        return i;
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb)
            return *xa < *xb ? -1 : 1;
        if (xa <= xa0)
            break;
    }
    return 0;
}

// diff
// FUNCTION: GAME 0x38FE50
Bigint *func_0038FE50(Bigint *c, Bigint *a, Bigint *b)
{
    int i, wa, wb;
    int borrow, y;
    unsigned int *xa, *xae, *xb, *xbe, *xc;
    int z;

    i = func_0038FDE8(a, b);
    if (!i) {
        c = func_0038F5B8(c, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        Bigint *tmp = a;
        a = b;
        b = tmp;
        i = 1;
    } else
        i = 0;
    c = func_0038F5B8(c, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    }
    while (!*--xc)
        wa--;
    c->wds = wa;
    return c;
}
