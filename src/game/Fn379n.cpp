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
extern "C" int func_003769B0(int);

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
