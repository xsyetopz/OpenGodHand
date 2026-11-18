// Small unnamed functions in 0x1C0000-0x1DFFFF (round 16).
extern "C" void dieCommon__7cOmBase(void *);
extern "C" void func_001D4F48(void *);
extern "C" void func_001DF940(void *);

#define EMPTY(a) extern "C" void func_##a(void) {}
// FUNCTION: GAME 0x1D4B70
EMPTY(001D4B70)
// FUNCTION: GAME 0x1DCE60
EMPTY(001DCE60)

struct Om {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x630 - 0x2F8];
    int m_630;
    char _pad3[0x660 - 0x634];
    unsigned char m_660;
    char _pad4[0x674 - 0x661];
    unsigned char m_674;
};

struct Pair {
    int m_a;
    int m_b;
};

// FUNCTION: GAME 0x1D6DB0
extern "C" Pair *func_001D6DB0(Pair *self)
{
    self->m_a = 0;
    self->m_b = 8;
    return self;
}

// FUNCTION: GAME 0x1D07C8
extern "C" void setWing__9cOmWeapon(Om *self)
{
    self->m_b = 10;
    self->m_a = 0;
    self->m_c = 0;
    self->m_d = 0;
}

// FUNCTION: GAME 0x1C2260
extern "C" void func_001C2260(void *self)
{
    dieCommon__7cOmBase(self);
}

// FUNCTION: GAME 0x1C3070
extern "C" void func_001C3070(void *self)
{
    dieCommon__7cOmBase(self);
}

// FUNCTION: GAME 0x1D11E8
extern "C" void Release__9BlackJack(void *self)
{
    func_001D4F48(self);
}

// FUNCTION: GAME 0x1D72B0
extern "C" void Release__5Poker(void *self)
{
    func_001DF940(self);
}

struct Om2 {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x630 - 0x2F8];
    int m_630;
    char _pad3[0x660 - 0x634];
    unsigned char m_660;
    char _pad4[0x674 - 0x661];
    unsigned char m_674;
};

// FUNCTION: GAME 0x1C20C8
extern "C" void func_001C20C8(Om2 *self)
{
    self->m_674 = 1;
}

// FUNCTION: GAME 0x1C2308
extern "C" void func_001C2308(Om2 *self)
{
    self->m_c = 6;
}

// FUNCTION: GAME 0x1C2490
extern "C" int func_001C2490(Om2 *self)
{
    unsigned char v = self->m_660;
    return v != 0;
}

// FUNCTION: GAME 0x1C2318
extern "C" void func_001C2318(Om2 *self)
{
    self->m_630 = 0;
    self->m_c = 2;
}
