// Small helpers in 0x1F0000-0x200000, over raw offsets.
extern "C" void func_001FCD00(void *);

struct WT {
    int a, b;
};
extern WT WorldTime;

// FUNCTION: GAME 0x1F6CF8
extern "C" void func_001F6CF8(char *p)
{
    *(int *)(p + 8) = 0;
    *(short *)(p + 0xC) = 0;
    *(short *)(p + 0xE) = 0;
    *(short *)(p + 0x10) = 0;
    *(short *)(p + 0x12) = 0;
    *(int *)p = 0;
}

// FUNCTION: GAME 0x1F9C30
extern "C" void func_001F9C30(int **p)
{
    int *q = *p;
    *q = WorldTime.a;
    int *r = *p;
    r[1] = WorldTime.b;
}

// FUNCTION: GAME 0x1FC170
extern "C" void func_001FC170(char *p, unsigned a, int v)
{
    p = *(char **)p;
    if (p) {
        unsigned i = a & 0xFF;
        if (i < 10)
            p[i + 0x98] = v;
    }
}

// FUNCTION: GAME 0x1FC198
extern "C" int func_001FC198(char *p, unsigned a)
{
    p = *(char **)p;
    if (!p)
        return 0x1F;
    unsigned i = a & 0xFF;
    if (i < 10)
        return (unsigned char)p[i + 0x98];
    return 0x1F;
}

// FUNCTION: GAME 0x1FC360
extern "C" int func_001FC360(char *p, int bit)
{
    p = *(char **)p;
    int r = 1;
    if (!p)
        return 0;
    if (!(*(int *)(p + 0xB90) & (r << bit)))
        r = 0;
    return r;
}

// FUNCTION: GAME 0x1FCDB8
extern "C" void func_001FCDB8(char *p)
{
    func_001FCD00(p);
    *(int *)(p + 0x34) = 0;
    p[0x49] = 1;
}

// FUNCTION: GAME 0x1FD8D8
extern "C" int func_001FD8D8(char *p, int k)
{
    char *n = *(char **)(p + 0x3C);
    while (n) {
        if (*(short *)(n + 0x2C) == k)
            return *(int *)(n + 0x28);
        n = *(char **)(n + 0x24);
    }
    return 0;
}

// FUNCTION: GAME 0x1F77D0
extern "C" void func_001F77D0(char *p)
{
    char *q = p + 0xE4;
    for (int i = 15; i > 0; i--, q -= 0x10) {
        *(char **)(q + 0x14) = q;
        *(int *)(q + 0x1C) = 0;
    }
    char *r = p + 4;
    *(int *)(r + 4) = 0;
    *(int *)(r + 0xC) = 0;
}
