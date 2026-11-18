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

struct Fn38O30 {
    char _p0[0x30];
    int m_30;
    int m_34;
};
extern "C" int func_00329F98(int);
extern "C" void func_003298C0(int);
extern "C" void func_0031C900(int);

// FUNCTION: GAME 0x380D68
extern "C" void func_00380D68(int, Fn38O30 *o)
{
    if (o->m_30 != 0) {
        if (func_00329F98(o->m_30) == 5) {
            func_003298C0(o->m_30);
            o->m_30 = 0;
            func_0031C900(o->m_34);
        }
    }
}

struct Fn38O20 {
    char _p0[0x20];
    int m_20;
    int m_24;
};
extern "C" int func_0032DC58(int);
extern "C" void func_0032D6F0(int);
extern "C" void func_0031C900(int);

// FUNCTION: GAME 0x381CE0
extern "C" void func_00381CE0(int, Fn38O20 *o)
{
    if (o->m_20 != 0) {
        if (func_0032DC58(o->m_20) == 5) {
            func_0032D6F0(o->m_20);
            o->m_20 = 0;
            func_0031C900(o->m_24);
        }
    }
}

struct Fn38P30 {
    char _p0[0x30];
    int m_30;
};
extern "C" int func_00329F98(int);
extern "C" void func_0032B300(int, int);

// FUNCTION: GAME 0x380F10
extern "C" void func_00380F10(int, Fn38P30 *o, unsigned char *p)
{
    if (o->m_30 != 0) {
        int s = func_00329F98(o->m_30);
        if (s != 0 && s != 5 && s != 6) {
            *p ^= 1;
            func_0032B300(o->m_30, *p);
        }
    }
}

struct O30 {
    char _p0[0x20];
    int m_20;
};
extern "C" int func_0032DC58(int);
extern "C" void func_0032E040(int, int);

// FUNCTION: GAME 0x381DC0
extern "C" void func_00381DC0(int, O30 *o, unsigned char *p)
{
    if (o->m_20 != 0) {
        int s = func_0032DC58(o->m_20);
        if (s != 0 && s != 3 && s != 4) {
            *p ^= 1;
            func_0032E040(o->m_20, *p);
        }
    }
}

extern "C" void func_00380E10(char *);
extern "C" void func_00381D38(char *, char *, char *);
extern "C" void func_00383438(char *, char *);
extern "C" void func_00380E88(char *, char *, char *);

// FUNCTION: GAME 0x380DC0
extern "C" void func_00380DC0(char *o)
{
    func_00380E10(o);
    func_00381D38(o, o + 0x348, o + 0x318);
    func_00383438(o, o + 0x370);
    func_00380E88(o, o + 0x484, o + 0x470);
}

struct Fn38O3 {
    char _p0[1];
    unsigned char m_1;
    char _p2;
    unsigned char m_3;
};
extern "C" int func_00380F80(int, char *, Fn38O3 *);

// FUNCTION: GAME 0x3833B0
extern "C" void func_003833B0(int a, Fn38O3 *o)
{
    if ((o->m_3 ^ 1) & 1) {
        int r = func_00380F80(a, (char *)o + 0x34, o);
        if (r)
            o->m_1 = r;
    }
}
