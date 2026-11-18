// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern "C" char *strrchr(const char *, int);
extern "C" int strcmp(const char *, const char *);

struct Fn38Q {
    char _p0[0x38];
    unsigned m_38;
};

struct Fn38S {
    char _p0[0x22];
    unsigned short m_22;
};

extern Fn38S D_0076A790;

extern "C" int func_00380AE8(unsigned char *, unsigned char *, unsigned char *);
extern "C" void func_0032BDC0(int, int, int);
extern "C" void func_00385138(unsigned char *, Fn38Q *);
extern "C" void func_0037D9B0(int, int);
extern "C" int func_00387328(short, short, short, int);

// FUNCTION: GAME 0x385030
extern "C" void func_00385078(unsigned char *, Fn38Q *);
extern "C" void func_00385030(unsigned char *a, Fn38Q *b)
{
    switch ((unsigned char)a[2]) {
    case 0: func_00385078(a, b); break;
    case 1: func_00385138(a, b); break;
    }
}

// FUNCTION: GAME 0x385078
extern "C" void func_00385078(unsigned char *a, Fn38Q *b)
{
    unsigned char *s1 = a + 0x470;
    unsigned char *s2 = a + 0x4BC;
    unsigned f = b->m_38;
    if (f & 0x8000) {
        if (a[7] == 0) a[7] = s1[0x10] - 1; else a[7] = a[7] - 1;
    } else {
        if (!(f & 0x2000)) return;
        if (a[7] < *(unsigned *)(s1 + 0x10) - 1) a[7]++; else a[7] = 0;
    }
    int r = func_00380AE8(a, s2, s1);
    if (r) s1[1] = r;
    else { func_0032BDC0(*(int *)(s2 + 0x30), *(int *)(s1 + 0x84), a[7]); a[2] = 1; }
}

// FUNCTION: GAME 0x3866B8
extern "C" int func_003866B8(int, char *b, char *c)
{
    char *p = strrchr(b, '.');
    if (p == 0) return 0;
    return strcmp(p + 1, c) == 0;
}

// FUNCTION: GAME 0x386D70
extern "C" void func_00386D70(void)
{
    Fn38S *s = &D_0076A790;
    if (s->m_22 & 1) { s->m_22 &= 0xFFFE; func_0037D9B0(1, 1); }
    if (s->m_22 & 2) { s->m_22 &= 0xFFFD; func_0037D9B0(1, 2); }
}

// FUNCTION: GAME 0x387270
extern "C" int func_00387270(short a, short b, short c, int d)
{
    if (a == -1) {
        int i;
        for (i = 0; i < 2; i++)
            if (func_00387328(i, b, c, d) == -1) return -1;
        return 0;
    }
    return func_00387328(a, b, c, d);
}
