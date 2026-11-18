// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct Fn379X {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    char _p8[4];
    unsigned char m_C;
    unsigned char m_D;
    char _pE[0x42];
};
extern Fn379X D_0076B9C0[];

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
// diff: 24 words; register assignment (original puts the bit in a3, mask word in t0, idx*8 in a2)
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

#ifdef NONMATCHING
// DRAFT: GAME 0x37BE98
// diff: 2 words; the original keeps `nop` in the first beqz delay slot, ours fills it with the arg move
extern "C" void func_0037BE98(void)
{
    Fn379X *e = D_0076B9C0;
    Fn379X *end = D_0076B9C0 + 0xF00 / 0x50;
    do {
        if (e->m_0) {
            if (e->m_C & 0x10) {
                func_0037C330(e);
                e->m_0 = 0;
            } else {
                func_0037BF10(e);
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

// DRAFT: GAME 0x376EA0
// diff: 2 words; same delay-slot fill as 0x37BE98
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
#endif

struct Fn379D1 {
    unsigned short m_0;
    char _p2[0x4E];
};
extern Fn379D1 D_0076CF20[];

// FUNCTION: GAME 0x37D310
extern "C" Fn379D1 *func_0037D310(signed char a)
{
    int n = 24;
    int base = a / n * n;
    int cnt = 24;
    if (base == 0x30)
        cnt = 3;
    int i = 0;
    if (cnt != 0) {
        Fn379D1 *e = D_0076CF20 + base;
        do {
            if (e->m_0 == 0)
                return e;
            i++;
            e++;
        } while (i < cnt);
    }
    return 0;
}

struct Fn379E1 {
    char _p0[6];
    unsigned short m_6;
    char _p8[0x12];
    short m_1A;
};
struct Fn379E2 {
    char _p0[0xC];
    unsigned char m_C;
};
struct Fn379E3 {
    char _p0[4];
    char *m_4;
};
struct Fn379E4 {
    char _p0[8];
    Fn379E1 *m_8;
    char _pC[0x2C];
    short m_38;
    short m_3A;
};
extern Fn379E3 *D_00773250[];

// FUNCTION: GAME 0x37C6A0
extern "C" void func_0037C6A0(Fn379E4 *o)
{
    Fn379E1 *r = o->m_8;
    Fn379E3 *z = D_00773250[r->m_1A];
    if (z) {
        int n = 0x7F;
        int m = 0x7F;
        Fn379E2 *e = (Fn379E2 *)(z->m_4 + r->m_6 * 0x20);
        o->m_38 = e->m_C * o->m_38 / n;
        o->m_3A = e->m_C * o->m_3A / m;
    }
}
