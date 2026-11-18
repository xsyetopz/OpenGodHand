// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct Fn379F1 {
    char _p0[0x26];
    signed char m_26;
    char _p27[5];
    unsigned m_2C;
    char _p30[8];
    unsigned m_38;
};

// FUNCTION: GAME 0x37AD08
extern "C" int func_0037AD08(Fn379F1 *p)
{
    signed char old = p->m_26;
    if (p->m_2C & 0x80)
        return 0;
    if (p->m_38 & 0x1000)
        p->m_26--;
    if (p->m_38 & 0x4000)
        p->m_26++;
    if (p->m_26 < 0)
        p->m_26 = 6;
    if (!(p->m_26 < 7))
        p->m_26 = 0;
    return p->m_26 != old;
}

struct Fn379F2 {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    unsigned char m_8;
    unsigned char m_9;
    unsigned short m_A;
    char _pC[0x16];
    short m_22;
    char _p24[2];
    short m_26;
};
extern "C" Fn379F2 *func_00376978(void);

// FUNCTION: GAME 0x375E78
extern "C" int func_00375E78(int a, short b, short c)
{
    Fn379F2 *e = func_00376978();
    if (!e)
        return -1;
    e->m_0 = 1;
    e->m_26 = c;
    e->m_4 = a;
    e->m_8 = 0x10;
    e->m_9 = 4;
    e->m_22 = b;
    e->m_A = 0;
    return 0;
}

struct Fn379F3 {
    char _p0[0x26];
    unsigned short m_26;
    unsigned short m_28;
    char _p2A[6];
    short m_30;
    short m_32;
    short m_34;
    short m_36;
    unsigned short m_38;
    unsigned short m_3A;
};
struct Fn379F4 {
    char _p0[0xD];
    unsigned char m_D;
    char _pE[0x4];
    char _p12[6];
    unsigned short m_18;
    unsigned short m_1A;
    char _p1C[0x14];
    unsigned short m_30;
    unsigned short m_32;
};
extern "C" void func_0037C6A0(Fn379F3 *);
extern "C" void func_0037D3C8(Fn379F3 *);

// FUNCTION: GAME 0x37C228
extern "C" void func_0037C228(Fn379F3 *o, Fn379F4 *s)
{
    o->m_30 = 0x7F00;
    o->m_32 = 0;
    o->m_34 = 0;
    o->m_36 = 0;
    o->m_38 = s->m_30;
    o->m_3A = s->m_32;
    if (s->m_D & 8)
        func_0037C6A0(o);
    o->m_26 = s->m_18;
    o->m_28 = s->m_1A;
    func_0037D3C8(o);
}

// FUNCTION: GAME 0x374B00
struct Fn379G1 {
    int w[8];
};
extern Fn379G1 D_0076B040[];
extern Fn379G1 D_0076A7D4[];
extern "C" void func_00374B00(void)
{
    Fn379G1 *d = D_0076B040;
    Fn379G1 *s = D_0076A7D4;
    int i = 1;
    do {
        *d = *s;
        i--;
        d++;
        s++;
    } while (i >= 0);
}

extern "C" int func_0032DC58(int);
// FUNCTION: GAME 0x3748A8
extern "C" int func_003748A8(int *p)
{
    int v = *p;
    if (v == 0)
        return 0;
    switch (func_0032DC58(v)) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
    default:
        return 6;
    }
}

#ifdef NONMATCHING
struct Fn379G2 {
    unsigned short m_0;
    char _p2[0x12];
    unsigned short m_14;
    char _p16[0x8A];
};
typedef void (*Fn379Fp)(Fn379G2 *);
extern Fn379G2 D_0076E910[];
extern Fn379Fp D_003F21A8[];
// DRAFT: GAME 0x3774A8
// diff: 3 words; original fills the beql slot with the pointer step and
// the jalr slot with the a0 move; ours hoists the move and leaves a nop.
extern "C" void func_003774A8(void)
{
    Fn379G2 *e = D_0076E910;
    Fn379G2 *end = e + 2;
    do {
        if (e->m_0) {
            Fn379Fp f = D_003F21A8[e->m_14];
            f(e);
        }
        e++;
    } while ((int)e < (int)end);
}
#endif

struct Fn379H1 {
    int m_0;
    char _p4[8];
    int m_C;
};
extern "C" int func_00374928(Fn379H1 *, int);
extern "C" void func_0032A6D0(int, int, int);
// FUNCTION: GAME 0x374820
extern "C" void func_00374820(Fn379H1 *o, int a, int b)
{
    if (o->m_0) {
        int i = 0;
        if (o->m_C > 0) {
            do {
                int r = func_00374928(o, i);
                i++;
                func_0032A6D0(r, a, b);
            } while (i < o->m_C);
        }
    }
}

struct Fn379H2 {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    int m_8;
    char m_C;
    char m_D;
    short m_E;
    short m_10;
    short m_12;
    short m_14;
    short m_16;
    short m_18;
    short m_1A;
    short m_1C;
    short m_1E;
};
extern "C" Fn379H2 *func_0037D170(void);
#ifdef NONMATCHING
// DRAFT: GAME 0x375050
// diff: original keeps e in a1 (beqz out of line to the -1 return); ours puts e in a2.
extern "C" int func_00375050(int a, short b)
{
    Fn379H2 *e = func_0037D170();
    if (e) {
        e->m_C = 0x10;
        e->m_4 = a;
        e->m_D = 1;
        e->m_10 = b;
        e->m_12 = -1;
        e->m_1E = 0;
        e->m_0 = 1;
        e->m_8 = 0;
        e->m_E = 0;
        e->m_14 = 0;
        e->m_16 = 0;
        e->m_18 = 0;
        e->m_1A = 0;
        e->m_1C = 0;
        return 0;
    }
    return -1;
}
#endif

struct Fn379H3 {
    int w;
};
extern "C" int func_00373A50(Fn379H3 *);
extern "C" int func_00373B20(Fn379H3 *);
extern "C" void func_00374720(Fn379H3 *, Fn379H3 *, float, float);
extern "C" void func_003740C8(Fn379H3 *, float, float);
#ifdef NONMATCHING
// DRAFT: GAME 0x3735E0
// diff: 3 words; original moves a1 into the jal delay slot after the mov.s pair.
extern "C" void func_003735E0(Fn379H3 *o, Fn379H3 *p, float x, float y)
{
    if (func_00373A50(o)) {
        if (x < 0.001f)
            x = 0.0f;
        if (func_00373B20(o) == 1)
            func_00374720(o, p, x, y);
        else
            func_003740C8(o, x, y);
    }
}
#endif
