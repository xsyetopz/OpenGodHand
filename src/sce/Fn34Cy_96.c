// COMPILER: ee-gcc2.96
int func_0034DD70(int, int);
int func_0034CA98(char *, int);
void func_0034C158(char *, char *, char *, int);
void func_0034C588(int, int, unsigned *, unsigned *);
void func_0034F390(char *, int);
void *func_0035A1C8(char *, int);

// FUNCTION: GAME 0x0034C0E8
int func_0034C0E8(char *p, char *q, int i)
{
    char *b = p + 0x1310;
    char *e = b + i * 0x74;
    char *s = e + 0x10;
    if (*(int *)e != 4)
        return func_0034DD70((int)p, 0xFF000409);
    func_0034C158(s, q, e, *(int *)(q + 4) != 0);
    return 0;
}

// FUNCTION: GAME 0x0034C4F8
void func_0034C4F8(char *p)
{
    unsigned a[2] __attribute__((aligned(16)));
    unsigned b[2] __attribute__((aligned(16)));
    unsigned *s = (unsigned *)(p + 0x18);
    func_0034C588(*(int *)(p + 4), 1, a, b);
    if (*s >= a[0] && *s < a[0] + a[1])
        return;
    if (*s >= b[0] && *s < b[0] + b[1])
        return;
    s[0] = 0;
    s[1] = 0;
}

// FUNCTION: GAME 0x0034E790
void func_0034E790(char *p, unsigned char c, long long x)
{
    void (*f)(void *, void *) = (void (*)(void *, void *))func_0035A1C8(p, 0x5B);
    if (f) {
        struct { unsigned char c; long long x; long long y; } s;
        s.c = c;
        s.x = x;
        s.y = *(long long *)(p + 0x990);
        f(func_0035A1C8(p, 0x5C), &s);
    }
}

// FUNCTION: GAME 0x0034F418
int func_0034F418(char *p)
{
    int *q = (int *)(p + 0x1F74);
    int r = 1;
    if (q[6] != 8)
        r = func_0034CA98(p, q[6]) & 1;
    if (q[5] != 8)
        r &= func_0034CA98(p, q[5]);
    if (q[7] != 8)
        r &= func_0034CA98(p, q[7]);
    return r;
}

// FUNCTION: GAME 0x0034F658
void func_0034F658(char *p, int *out)
{
    int *q = (int *)(p + 0x1F74);
    int *s = (int *)q[2];
    int flag;
    if (func_0034CA98(p, q[4]) == 1) {
        func_0034F390(p, s[0x3C / 4]);
        flag = 1;
    } else
        flag = 0;
    if (out)
        *out = flag;
}
