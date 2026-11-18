// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

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
// tried: direct call, pre-increment, ++e < end (4 words), continue form (19)
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
extern "C" void func_00374720(Fn379H3 *, float, float, Fn379H3 *);
extern "C" void func_003740C8(Fn379H3 *, float, float);
// FUNCTION: GAME 0x3735E0
// func_00374720 takes (o, x, y, p) so the pointer move lands in the jal delay slot.
extern "C" void func_003735E0(Fn379H3 *o, Fn379H3 *p, float x, float y)
{
    if (func_00373A50(o)) {
        if (x < 0.001f)
            x = 0.0f;
        if (func_00373B20(o) == 1)
            func_00374720(o, x, y, p);
        else
            func_003740C8(o, x, y);
    }
}

struct Fn379S {
    char m_0[0x40];
    int m_40;
    char m_44[0x40];
    char _p84[0x58];
    char m_DC[0x24];
    int m_100;
};
extern "C" int sceSifBindRpc(void *, int, int);
extern Fn379S D_0076A880;
// FUNCTION: GAME 0x375860
extern "C" void func_00375860(void)
{
    Fn379S *s = &D_0076A880;
    do {
        if (sceSifBindRpc(s->m_DC, 0x19720317, 0) < 0) {
            for (;;) {
            }
        }
        int i = 9999;
        do {
            i--;
        } while (i != -1);
    } while (s->m_100 == 0);
}

extern "C" int sceSifCheckStatRpc(void *);
extern "C" int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
// FUNCTION: GAME 0x3758E8
extern "C" int func_003758E8(int a)
{
    Fn379S *s = &D_0076A880;
    while (sceSifCheckStatRpc(s->m_DC) != 0) {
        int i = 9999;
        do {
            i--;
        } while (i != -1);
    }
    sceSifCallRpc(s->m_DC, a, 1, s, 0x40, &s->m_40, 0x40, 0, 0);
    return s->m_40;
}

struct Fn379K1 {
    unsigned short m_0;
    char _p2[0xE];
    signed char m_10;
    char _p11[0xCF];
};
struct Fn379K2 {
    char _p0[8];
    signed char m_8;
    signed char m_9;
    char _pA[4];
    unsigned short m_E;
};
extern Fn379K1 D_00770850[];
extern "C" void func_00376AE0(Fn379K1 *, int);
// FUNCTION: GAME 0x376A10
extern "C" Fn379K1 *func_00376A10(Fn379K2 *o)
{
    Fn379K1 *e = &D_00770850[o->m_9];
    if (e->m_0 == 0)
        return e;
    if (o->m_8 < e->m_10)
        return 0;
    if (o->m_8 == e->m_10) {
        if (!(o->m_E & 0x20))
            return 0;
    }
    func_00376AE0(e, -1);
    return e;
}
