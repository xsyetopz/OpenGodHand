// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ trivial accessors in 0x388000-0x393F30.

// FUNCTION: GAME 0x389F30
int func_00389F30(int *self)
{
    return self[1];
}

// FUNCTION: GAME 0x389FD8
void func_00389FD8(void)
{
}

// FUNCTION: GAME 0x393918
char *func_00393918(char *self)
{
    return self + 8;
}

/* dtoa Bigint helpers (0x38F4C0-0x38F9A0). */
typedef unsigned long ULong32;
struct Bigint {
    struct Bigint *next;
    int k;
    int maxwds;
    short sign;
    short wds0;
    int wds;
    unsigned int x[1];
};

extern void *malloc(unsigned int);
extern void free(void *);

// FUNCTION: GAME 0x38F4E8
struct Bigint *func_0038F4E8(int k)
{
    int x;
    struct Bigint *rv;
    if (k < 3)
        k = 3;
    x = 1 << k;
    rv = (struct Bigint *)malloc(x * 4 + 0x14);
    rv->k = k;
    rv->maxwds = x;
    rv->wds = 0;
    rv->wds0 = 0;
    rv->sign = 0;
    return rv;
}

// FUNCTION: GAME 0x38F548
void func_0038F548(struct Bigint *v)
{
    if (v && !v->sign)
        free(v);
}

// FUNCTION: GAME 0x38F570
void func_0038F570(struct Bigint *a, struct Bigint *b)
{
    int n = b->wds;
    unsigned int *x = a->x;
    unsigned int *y = b->x;
    a->wds = n;
    a->wds0 = b->wds0;
    while (--n >= 0)
        *x++ = *y++;
}

// FUNCTION: GAME 0x38F5B8
struct Bigint *func_0038F5B8(struct Bigint *v, int k)
{
    struct Bigint *r;
    if (!v)
        return func_0038F4E8(k);
    if (v->k >= k)
        return v;
    r = func_0038F4E8(k);
    func_0038F570(r, v);
    func_0038F548(v);
    return r;
}

// FUNCTION: GAME 0x38F980
struct Bigint *func_0038F980(struct Bigint *v, int i)
{
    struct Bigint *b = func_0038F5B8(v, 1);
    b->x[0] = i;
    b->wds = 1;
    return b;
}

// FUNCTION: GAME 0x38F4C0
struct Bigint *func_0038F4C0(struct Bigint *b)
{
    b->sign = 1;
    b->k = 3;
    b->maxwds = 8;
    b->wds = 0;
    b->wds0 = 0;
    return b;
}

extern int _IO_file_setbuf(void *, char *, long);
extern int func_0038B138(void *, char *, int);

// FUNCTION: GAME 0x38EF60
int func_0038EF60(void *f, char *p, int n)
{
    return _IO_file_setbuf(f, p, n);
}

// FUNCTION: GAME 0x38F120
int func_0038F120(void *f, char *p, int n)
{
    return func_0038B138(f, p, n);
}
