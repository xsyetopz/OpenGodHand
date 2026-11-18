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
