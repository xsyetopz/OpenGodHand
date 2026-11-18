// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct Fn379T {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    unsigned char m_8;
    char _p9[0x37];
};
extern Fn379T D_0076F050[];

// FUNCTION: GAME 0x3769B0
extern "C" Fn379T *func_003769B0(int id)
{
    Fn379T *e = D_0076F050;
    int i = 0;
    do {
        if (e->m_0 && !(e->m_8 & 0x10)) {
            if (id == 0)
                return e;
            if (e->m_4 == id)
                return e;
        }
        i++;
        e++;
    } while (i < 0x60);
    return 0;
}

extern "C" int func_00379EC0(void *);
extern "C" void func_0037A1F0(void *);
extern "C" int func_0037A4C8(void *);
extern "C" int func_0037AD08(void *);
extern "C" void func_0037AD88(void *);
extern "C" void func_0037A298(void *);

// FUNCTION: GAME 0x37ACA0
extern "C" void func_0037ACA0(void *p)
{
    if (func_00379EC0(p))
        return;
    func_0037A1F0(p);
    if (!func_0037A4C8(p) && !func_0037AD08(p))
        func_0037AD88(p);
    func_0037A298(p);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x378180
// diff: 21 words; original uses beql/subu (no movn) with divisor in a2 and FP constants loaded after cvt; ours uses movn. Tried single-expression, d<180 else form, early-return duplicate, float-select form
extern "C" int func_00378180(short a, short *out)
{
    int n = 360;
    int d = a % n;
    if (d >= 180)
        d = n - d;
    float f = (float)d;
    f = f * 127.0f;
    f = f / 180.0f;
    *out = (int)(f + 0.5f);
    return 0;
}
#endif

struct Fn379U {
    char _p0[0x28];
    signed char m_28;
    char _p29[0xF];
    unsigned m_38;
};

// FUNCTION: GAME 0x37B798
extern "C" int func_0037B798(Fn379U *p)
{
    signed char old = p->m_28;
    if (p->m_38 & 0x1000)
        p->m_28--;
    if (p->m_38 & 0x4000)
        p->m_28++;
    if (p->m_28 < 0)
        p->m_28 = 5;
    if (!(p->m_28 < 6))
        p->m_28 = 0;
    return p->m_28 != old;
}

struct Fn379V {
    unsigned short m_0;
    char _p2[2];
    unsigned char m_4;
    unsigned char m_5;
    unsigned short m_6;
    char _p8[4];
    int m_C;
    int m_10;
    int m_14;
    unsigned short m_18;
    unsigned short m_1A;
    unsigned short m_1C;
    unsigned short m_1E;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
};
struct Fn379W {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    int m_8;
    unsigned char m_C;
    unsigned char m_D;
    char _pE[4];
    unsigned short m_12;
    unsigned short m_14;
    unsigned short m_16;
    char _p18[8];
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    char _p26[6];
    unsigned short m_2C;
};

// FUNCTION: GAME 0x37C1B8
extern "C" void func_0037C1B8(Fn379V *d, Fn379W *s)
{
    d->m_0 = s->m_0;
    d->m_4 = s->m_C;
    d->m_5 = s->m_D;
    d->m_6 = 0;
    d->m_C = 0;
    d->m_10 = s->m_4;
    d->m_14 = s->m_8;
    d->m_18 = s->m_12;
    d->m_1A = s->m_14;
    d->m_1C = s->m_20;
    d->m_1E = s->m_22;
    d->m_20 = s->m_24;
    d->m_22 = s->m_2C;
    d->m_24 = s->m_16;
}

struct Fn379X {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    char _p8[4];
    unsigned char m_C;
    unsigned char m_D;
    char _pE[0x12];
    short m_20;
    char _p22[0x2E];
};
extern Fn379X D_0076B9C0[];

// FUNCTION: GAME 0x37D220
extern "C" Fn379X *func_0037D220(unsigned char a, short b)
{
    Fn379X *e = D_0076B9C0;
    Fn379X *end = D_0076B9C0 + 0xF00 / 0x50;
    do {
        if (e->m_0 && !(e->m_C & 0x10) && (e->m_D & a) && e->m_20 == b)
            return e;
        e++;
    } while ((int)e < (int)end);
    return 0;
}

struct Fn379Y {
    char _p0[0xB];
    unsigned char m_B;
};
struct Fn379Z {
    char _p0[4];
    Fn379Y *m_4;
};
struct Fn379Q2 {
    char _p0[0x20];
    short m_20;
    char _p22[0xC];
    unsigned short m_2E;
};
extern Fn379Z *D_00773250[];
extern int D_0076A7A4;

// FUNCTION: GAME 0x37C630
extern "C" int func_0037C630(Fn379Q2 *p)
{
    Fn379Z *z = D_00773250[p->m_20];
    if (((z->m_4->m_B >> 2) & 3) >= 2)
        return 0;
    if (D_0076A7A4 == 2)
        return ((p->m_2E >> 2) ^ 1) & 1;
    return ((p->m_2E >> 1) ^ 1) & 1;
}
