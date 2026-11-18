// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern int D_0076A7A4;
extern "C" void func_0032BA30(int);
extern "C" void func_00375DE0(short, short);
extern "C" void func_00375E78(void);

struct Fn37Ent40 {
    unsigned short m_0;
    char _pad[0x3E];
};
extern Fn37Ent40 D_0076F050[];

struct Fn37Ent70 {
    unsigned short m_0;
    char _pad[0x6E];
};
extern Fn37Ent70 D_0076E590[];

// FUNCTION: GAME 0x375700
extern "C" void SdeSystemOutModeSet(int a)
{
    if (a == 0)
        func_0032BA30(1);
    else
        func_0032BA30(0);
    D_0076A7A4 = a;
}

// FUNCTION: GAME 0x375D98
extern "C" void func_00375D98(int a, short b, short c)
{
    if (a == 0)
        func_00375DE0(b, c);
    else
        func_00375E78();
}

// FUNCTION: GAME 0x376978
extern "C" Fn37Ent40 *func_00376978(void)
{
    for (int i = 0; i < 0x60; i++) {
        if (D_0076F050[i].m_0 == 0)
            return &D_0076F050[i];
    }
    return 0;
}

// FUNCTION: GAME 0x377998
extern "C" Fn37Ent70 *func_00377998(void)
{
    for (int i = 0; i < 8; i++) {
        if (D_0076E590[i].m_0 == 0)
            return &D_0076E590[i];
    }
    return 0;
}

struct Fn37Ramp {
    unsigned short m_0;
    unsigned short m_2;
    short m_4;
    short m_6;
};

// FUNCTION: GAME 0x378020
extern "C" void func_00378020(Fn37Ramp *p)
{
    int d = (short)(p->m_2 - p->m_0);
    int q = d / p->m_6;
    p->m_4 = q;
    if ((q << 16) == 0)
        p->m_4 = d > 0 ? 1 : -1;
    p->m_6 = 0;
}

struct Fn37Clamp {
    short m_0;
    short m_2;
    short m_4;
    unsigned short m_6;
};

// FUNCTION: GAME 0x378070
extern "C" void func_00378070(Fn37Clamp *p)
{
    int s = p->m_0 + p->m_4;
    if (p->m_4 > 0) {
        if (p->m_2 < s)
            s = p->m_2;
    } else {
        if (s < p->m_2)
            s = p->m_2;
    }
    p->m_0 = s;
    p->m_6++;
}

// FUNCTION: GAME 0x3780B0
extern "C" short func_003780B0(short a, short b)
{
    int v = a << 8;
    if ((a ^ 0x80) == 0)
        v = 0x7FFF;
    return v * b / 0x7F00;
}

extern "C" void func_00378C48(void *);
extern "C" void func_0037B0E0(void *);
extern "C" void func_00379190(void *);
extern "C" void func_00379BC0(void *);
struct Fn37Sel {
    char _pad[6];
    signed char m_6;
};

// FUNCTION: GAME 0x378BF8
extern "C" void func_00378BF8(Fn37Sel *p)
{
    func_00378C48(p);
    func_0037B0E0(p);
    if (p->m_6 == 0)
        func_00379190(p);
    else
        func_00379BC0(p);
}
