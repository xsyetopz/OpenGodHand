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
// diff: 21 words; same size, but the original keeps the divisor in a2 and loads the FP constants after the cvt, ours differs in register choice and scheduling
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

struct Fn379A1 {
    char _p0[0x2C];
    float m_2C;
    float m_30;
    char _p34[8];
    float m_3C;
    float m_40;
};
extern "C" int func_00373A50(Fn379A1 *);
extern "C" int func_00373B20(Fn379A1 *);

// FUNCTION: GAME 0x3739A0
extern "C" void func_003739A0(Fn379A1 *o, int k, float f)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1) {
            o->m_40 = f;
            if (k == 1)
                o->m_3C = f;
        } else {
            o->m_30 = f;
            if (k == 1)
                o->m_2C = f;
        }
    }
}

struct Fn379A2 {
    char _p0[0xE];
    unsigned short m_E;
    char _p10[4];
    unsigned short m_14;
    unsigned short m_16;
};
extern "C" int func_00378180(short, short *);

// FUNCTION: GAME 0x3752A0
extern "C" int func_003752A0(Fn379A2 *o, short a)
{
    int v = 0;
    short r;
    if (!(o->m_E & 2)) {
        v = func_00378180(a, &r);
        if (v == 0)
            o->m_14 = r;
    }
    if (!(o->m_E & 4))
        o->m_16 = a;
    return v;
}

struct Fn379A3 {
    char _p0[0x10];
    unsigned short m_10;
    char _p12[0x46];
    unsigned m_58;
};
struct Fn379Pr {
    char _p0[0x38];
    short m_38;
    short m_3A;
};
extern "C" void func_00378070(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x377688
// diff: ~14 words; register assignment (original puts the bit in a3, mask word in t0, idx*8 in a2)
extern "C" void func_00377688(Fn379A3 *o, int idx)
{
    unsigned bit = 1 << idx;
    unsigned m = o->m_58;
    if (bit & m) {
        Fn379Pr *q = (Fn379Pr *)((char *)o + idx * 8);
        if (q->m_38 == q->m_3A) {
            o->m_58 = m & ~bit;
        } else {
            func_00378070((char *)o + idx * 8 + 0x38);
            o->m_10 |= 1;
        }
    }
}
#endif

// FUNCTION: GAME 0x37D1A8
extern "C" Fn379X *func_0037D1A8(unsigned char a, int id)
{
    Fn379X *e = D_0076B9C0;
    Fn379X *end = D_0076B9C0 + 0xF00 / 0x50;
    do {
        if (e->m_0 && !(e->m_C & 0x10) && (e->m_D & a)) {
            if (id == 0)
                return e;
            if (e->m_4 == id)
                return e;
        }
        e++;
    } while ((int)e < (int)end);
    return 0;
}

struct Fn379B2 {
    char _p0[0x10];
    unsigned short m_10;
    char _p12[0x4A];
    unsigned short m_5C;
    unsigned short m_5E;
    char _p60[0x10];
    unsigned short m_70;
    unsigned short m_72;
};
struct Fn379B3 {
    char _p0[0x1A];
    unsigned short m_1A;
    char _p1C[0x28];
    unsigned short m_44;
    unsigned short m_46;
    unsigned short m_48;
    unsigned short m_4A;
};

// FUNCTION: GAME 0x377428
extern "C" void func_00377428(Fn379B2 *o, Fn379B3 *s)
{
    if (s->m_1A & 1) {
        o->m_5C = s->m_44;
        o->m_10 |= 1;
    }
    if (s->m_1A & 2) {
        o->m_5E = s->m_46;
        o->m_10 |= 1;
    }
    if (s->m_1A & 4) {
        o->m_70 = s->m_48;
        o->m_72 = s->m_4A;
        o->m_10 |= 2;
    }
}

extern "C" void func_0037C330(Fn379X *);
extern "C" void func_0037BF10(Fn379X *);

// FUNCTION: GAME 0x37BE98
extern "C" void func_0037BE98(void)
{
    Fn379X *e = D_0076B9C0;
    Fn379X *end = D_0076B9C0 + 0xF00 / 0x50;
    do {
        if (e->m_0) {
            if (!(e->m_C & 0x10)) {
                func_0037BF10(e);
                e->m_0 = 0;
            } else {
                func_0037C330(e);
                e->m_0 = 0;
            }
        }
        e++;
    } while ((int)e < (int)end);
}

struct Fn379C1 {
    unsigned short m_0;
    char _p2[6];
    unsigned char m_8;
    char _p9[0x67];
};
extern Fn379C1 D_0076E590[];
extern "C" void func_003772D8(Fn379C1 *);
extern "C" void func_00376F18(Fn379C1 *);

// FUNCTION: GAME 0x376EA0
extern "C" void func_00376EA0(void)
{
    Fn379C1 *e = D_0076E590;
    Fn379C1 *end = D_0076E590 + 0x380 / 0x70;
    do {
        if (e->m_0) {
            if (e->m_8 & 0x10) {
                func_003772D8(e);
                e->m_0 = 0;
            } else {
                func_00376F18(e);
                e->m_0 = 0;
            }
        }
        e++;
    } while ((int)e < (int)end);
}
