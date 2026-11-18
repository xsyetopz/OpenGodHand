// Small free functions after cParts::setRotationOrder (0x150000-0x152FFF).

extern char D_00466470[];
extern "C" void func_00150418(void *);
extern "C" void func_001504B0(void *, void *);
extern "C" void func_001505A8(void *, void *);
extern "C" void func_001523F8(int a, unsigned int b);

// FUNCTION: GAME 0x150078
extern "C" void func_00150078()
{
    func_00150418(D_00466470);
}

// FUNCTION: GAME 0x150098
extern "C" void func_00150098(void *a)
{
    func_001504B0(D_00466470, a);
}

// FUNCTION: GAME 0x150100
extern "C" void func_00150100(void *a)
{
    func_001505A8(D_00466470, a);
}

// FUNCTION: GAME 0x152428
extern "C" void func_00152428()
{
    func_001523F8(1, 0xFFFF);
}

struct sSlot {
    char _pad0[0x14];
    int m_key;
    char _pad18[0xB0 - 0x18];
};
extern sSlot D_00747BA0[256];

// 0x150D78: loop is correct, but the original shares the `(short)i` return block after the `return -1` exit; 12 words differ in layout.
#ifdef NONMATCHING
extern "C" short func_00150D78(void *self, int key)
{
    if (!key)
        return 0;
    int *p = &D_00747BA0[0].m_key;
    int i = 0;
    int n = 0x100;
    do {
        if (*p == key)
            return (short)i;
        p = (int *)((char *)p + 0xB0);
        i++;
    } while (--n);
    return -1;
}
#endif

extern int D_00460D30;
extern const char D_0041ECB8[];
extern "C" void func_0031EEC8(void *, const char *);

// FUNCTION: GAME 0x150638
extern "C" int *func_00150638()
{
    if (!D_00460D30)
        func_0031EEC8(&D_00460D30, D_0041ECB8);
    return &D_00460D30;
}

// 0x151630: gcc emits `movz` for the final 3/2 select where the original branches, and reorders the early `return 2`.
#ifdef NONMATCHING
extern "C" int func_00151630(const char *p)
{
    int r = 2;
    if (p[0] == 'T') {
        if (p[3] == '3')
            return p[5] == 6;
        if (p[3] == '2')
            return 0;
        if (p[1] == 'M')
            r = 3;
    }
    return r;
}
#else
extern "C" int func_00151630(const char *p);
#endif

// FUNCTION: GAME 0x1522C0
extern "C" char *func_001522C0(void *self, char *p, unsigned char idx)
{
    if (func_00151630(p) == 3)
        {
        char *q = p + idx * 4;
        return (char *)*(int *)(q + 0x10) + (int)p;
    }
    return p;
}

struct sPair {
    int m_key;
    int m_val;
};

// FUNCTION: GAME 0x15FD18
extern "C" int func_0015FD18(sPair *tbl, int key)
{
    if (key == -1)
        return 0;
    int i = 0;
    sPair *p = tbl;
    for (; i < 9; i++, p++) {
        int off = i << 3;
        if (p->m_key == key)
            return *(int *)((char *)tbl + off + 4);
    }
    return 0;
}
