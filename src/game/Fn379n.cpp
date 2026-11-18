// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct Fn379HC {
    char _p0[0xA];
    short m_A;
};
struct Fn379H {
    char _p0[0x25];
    char m_25;
    char _p26[0xA6];
    Fn379HC m_CC;
};
extern "C" int func_00387430(int);
extern "C" void func_00387160(int, void *);

// FUNCTION: GAME 0x37AAB0
extern "C" void func_0037AAB0(Fn379H *p)
{
    Fn379HC *q = &p->m_CC;
    if (p->m_25 == 7) {
        if (func_00387430(0) & 8) {
            q->m_A = 1;
            func_00387160(0, q);
        }
    }
}

struct Fn379I {
    char _p0[0x2E];
    unsigned short m_2E;
    char _p30[0x16];
    short m_46;
    unsigned short m_48;
};
struct Fn379J {
    char _p0[0x1E];
    unsigned short m_1E;
    char _p20[0x1C];
    unsigned short m_3C;
};
extern "C" short func_0037D760(void *);
extern "C" void func_0037D728(Fn379I *);

// FUNCTION: GAME 0x37C2E0
extern "C" void func_0037C2E0(Fn379I *a, Fn379J *b)
{
    a->m_46 = func_0037D760((char *)b + 0x20);
    a->m_48 = b->m_3C;
    a->m_2E = b->m_1E;
    func_0037D728(a);
}

struct Fn379F {
    unsigned short m_0;
};
extern "C" Fn379F *func_00376A90(int);
struct Fn379T;
extern "C" Fn379T *func_003769B0(int);

// FUNCTION: GAME 0x375EF8
extern "C" int func_00375EF8(int a)
{
    if (func_003769B0(a))
        return 1;
    Fn379F *e = func_00376A90(a);
    if (e)
        return (e->m_0 & 0x100) ? 6 : 2;
    return 0;
}

struct Fn379K {
    char _p0[0x20];
    unsigned short m_20;
    unsigned short m_22;
};
extern Fn379K D_0076A790;

// FUNCTION: GAME 0x375748
extern "C" void SdePlayVolReset(unsigned char f)
{
    Fn379K *k = &D_0076A790;
    if (f & 1)
        k->m_22 |= 1;
    if (f & 2)
        k->m_22 |= 4;
    if (f & 4)
        k->m_22 |= 0x10;
}

struct Fn379L {
    unsigned short m_0;
    char _p2[6];
    unsigned char m_8;
    char _p9[3];
    short m_C;
    char _pE[0x62];
};
extern Fn379L D_0076E590[];

// FUNCTION: GAME 0x3779D0
extern "C" Fn379L *func_003779D0(short id)
{
    Fn379L *e = D_0076E590;
    Fn379L *end = D_0076E590 + 0x380 / 0x70;
    do {
        if (e->m_0 && !(e->m_8 & 0x10) && e->m_C == id)
            return e;
        e++;
    } while ((int)e < (int)end);
    return 0;
}

struct Fn379M {
    char _p0[2];
    char m_2;
};
extern "C" int func_003244C8(int);
extern "C" int func_0037FD28(Fn379M *, void *);

// FUNCTION: GAME 0x37FCC8
extern "C" void func_0037FCC8(Fn379M *p)
{
    char *q = (char *)p + 0x370;
    if (func_003244C8(*(int *)(q + 0xF4)) == 3)
        {
        if (!func_0037FD28(p, q))
            p->m_2 = 6;
        else
            p->m_2 = 10;
    }
}

struct Fn379N {
    int m_0;
    char _p4[0x14];
    float m_18;
    float m_1C;
    char _p20[4];
    float m_24;
    float m_28;
};

// FUNCTION: GAME 0x3740C8
extern "C" void func_003740C8(Fn379N *o, float a, float b)
{
    if (o->m_0) {
        if (b == 0) {
            if (a <= o->m_18)
                o->m_1C = o->m_28;
            else
                o->m_1C = o->m_24;
        } else
            o->m_1C = b;
        o->m_18 = a;
    }
}

struct Fn379P {
    unsigned short m_0;
    char _p2[0x12];
    short m_14;
    unsigned short m_16;
    char _p18[0x22];
    short m_3A;
};
extern "C" void func_00377A28(Fn379P *);

#ifdef NONMATCHING
// DRAFT: GAME 0x377530
// diff: 4 words; the original hoists the ori into the beqz delay slot and stores +0x14 before +0x0
extern "C" void func_00377530(Fn379P *p)
{
    unsigned short f = p->m_0;
    if ((f & 0x10) && p->m_3A == 0) {
        p->m_0 = f & 0xFFEF;
        func_00377A28(p);
    } else if (f & 2) {
        if (p->m_16) {
            p->m_14 = 2;
            p->m_0 = f | 4;
        }
    }
}
#endif

struct Fn379Q {
    unsigned short m_0;
    char _p2[4];
    unsigned short m_6;
    char _p8[0x28];
    short m_30;
    short m_32;
};
extern "C" void func_0037D820(Fn379Q *);
extern "C" void func_00378070(void *);

// FUNCTION: GAME 0x37CC78
extern "C" void func_0037CC78(Fn379Q *p)
{
    unsigned short f = p->m_0;
    if (f & 0x40) {
        if (p->m_30 == p->m_32) {
            p->m_0 = f | 0x20;
            func_0037D820(p);
        } else {
            func_00378070(&p->m_30);
            p->m_6 |= 9;
        }
    }
}


#ifdef NONMATCHING
// DRAFT: GAME 0x377FA0
// diff: 22 words; the original reloads m_20 three times and branches with bne, ours uses movz and a different register assignment
extern "C" int func_00377FA0(void)
{
    Fn379K *r = &D_0076A790;
    short v = r->m_20;
    int t = (short)(v * 3) >> 8;
    int a = ((unsigned short)r->m_20 + t) & 0xFF;
    int n = a | ((t & 0xFF) << 8);
    int m = n;
    unsigned short old = r->m_20;
    if (old == (short)n)
        m = old + 1;
    r->m_20 = m;
    return n & 0xFF;
}
#endif

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

// FUNCTION: GAME 0x378180
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
