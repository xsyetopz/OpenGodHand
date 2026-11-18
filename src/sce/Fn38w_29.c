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

union doubleword {
    double d;
    unsigned int u[2];
};
#define HIWORD 1
#define LOWORD 0
#define word0(x) ({ union doubleword _du; _du.d = (x); _du.u[HIWORD]; })
#define setwords(D, W0, W1) ({ union doubleword _du; \
    _du.u[HIWORD] = (W0); _du.u[LOWORD] = (W1); (D) = _du.d; })

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

#define addword0(D, W) \
    ({ union doubleword _du; _du.d = (D); _du.u[HIWORD] += (W); (D) = _du.d; })

typedef struct Bigint {
    struct Bigint *next;
    int k;
    int maxwds;
    short on_stack;
    short sign;
    int wds;
    unsigned int x[1];
} Bigint;

extern Bigint *func_0038F5B8(Bigint *, int);
extern double func_00390078(Bigint *, int *);

// multadd
// FUNCTION: GAME 0x38F630
Bigint *func_0038F630(Bigint *b, int m, int a)
{
    int i, wds;
    unsigned int *x, y, xi, z;

    wds = b->wds;
    x = b->x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->maxwds)
            b = func_0038F5B8(b, b->k + 1);
        b->x[wds++] = a;
        b->wds = wds;
    }
    return b;
}

// s2b
// FUNCTION: GAME 0x38F700
Bigint *func_0038F700(Bigint *result, const char *s, int nd0, int nd, unsigned int y9)
{
    int i, k;
    int x, y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++)
        ;
    result = func_0038F5B8(result, k);
    result->x[0] = y9;
    result->wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do
            result = func_0038F630(result, 10, *s++ - '0');
        while (++i < nd0);
        s++;
    } else
        s += 10;
    for (; i < nd; i++)
        result = func_0038F630(result, 10, *s++ - '0');
    return result;
}

// ratio
// FUNCTION: GAME 0x390318
double func_00390318(Bigint *a, Bigint *b)
{
    double da, db;
    int k, ka, kb;

    da = func_00390078(a, &ka);
    db = func_00390078(b, &kb);
    k = ka - kb + 32 * (a->wds - b->wds);
    if (k > 0)
        addword0(da, k * 0x100000);
    else {
        k = -k;
        addword0(db, k * 0x100000);
    }
    return da / db;
}
