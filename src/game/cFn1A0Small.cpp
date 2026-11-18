// Small unnamed functions in 0x1A0000-0x1BFFFF.
extern "C" void func_001BD6B0(void);
extern "C" void func_001B6FB8(void);
extern "C" void move__6cOmSub(void *);
extern "C" void dieCommon__7cOmBase(void *);

#define EMPTY(a) extern "C" void func_##a(void) {}
// FUNCTION: GAME 0x1A8838
EMPTY(001A8838)
// FUNCTION: GAME 0x1A97E0
EMPTY(001A97E0)

struct A9E0 {
    char _pad[0x9E0];
    int m_v;
};
struct B660 {
    char _pad[0x660];
    int m_a;
    short m_b;
    char m_c;
};
struct B5B8 {
    char _pad[0x5B8];
    unsigned m_f;
};
// FUNCTION: GAME 0x1BD698
extern "C" int func_001BD698(B5B8 *self)
{
    self->m_f |= 8;
    return 1;
}

// FUNCTION: GAME 0x1B0C78
extern "C" void func_001B0C78(void)
{
    func_001BD6B0();
}

// FUNCTION: GAME 0x1B38D0
extern "C" void func_001B38D0(char *self)
{
    move__6cOmSub(self + 0x610);
}

struct Fl2F4 {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
};
// FUNCTION: GAME 0x1A7A08
extern "C" void func_001A7A08(Fl2F4 *self)
{
    if (((unsigned char *)self)[0x615 - 0x2F4 + 0x2F4]) {
        self->m_b = 1;
        self->m_c = 0;
        self->m_d = 0;
    }
}

// FUNCTION: GAME 0x1A8758
extern "C" int func_001A8758(void)
{
    func_001B6FB8();
    return 1;
}

// FUNCTION: GAME 0x1BBB28
extern "C" int func_001BBB28(void)
{
    func_001B6FB8();
    return 1;
}

struct OmB {
    char _pad[0x531];
    signed char m_x;
};
// FUNCTION: GAME 0x1B15A8
extern "C" void func_001B15A8(OmB *self)
{
    self->m_x = -1;
    dieCommon__7cOmBase(self);
}

struct H2FE {
    char _pad[0x2FE];
    unsigned short m_h;
};
struct F618 {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x618 - 0x2F8];
    int m_n;
};
// FUNCTION: GAME 0x1ACB50
extern "C" void func_001ACB50(F618 *self)
{
    if (self->m_n >= 0x29) {
        self->m_b = 1;
        self->m_c = 0;
        self->m_d = 0;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1B8030
// diff: original branches (result in a0); gcc folds to movn (ternary, inline helper) or addu/sltu (&&); retries failed
extern "C" int func_001B8030(H2FE *self)
{
    int h = self->m_h;
    int r;
    if (h < 0x3C0)
        r = 0;
    else
        r = h < 0x400;
    return r;
}
#endif

// FUNCTION: GAME 0x1AA500
extern "C" void func_001AA500(A9E0 *self)
{
    self->m_v = 8;
}

// FUNCTION: GAME 0x1B1928
extern "C" void func_001B1928(B660 *self, int a, short b)
{
    self->m_a = a;
    self->m_b = b;
    self->m_c = 0;
}
