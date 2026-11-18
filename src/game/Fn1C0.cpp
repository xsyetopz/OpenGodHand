// Small units in 0x1C0000-0x1DFFFF (round 24).
extern "C" void SetMoveOffsetPosXSin__12CustomIDWorkiUs(void *, int, unsigned short);
extern "C" void ResetMoveOffsetPos__12CustomIDWork(void *);
extern "C" void func_002CBA48(void *snd, int a, int b, void *c, int d, int e, int f, int g);
extern "C" void *func_001DD068(void *);
extern "C" void func_001DEC70(void *);
extern char Snd[];

struct OmF {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x5B8 - 0x2F8];
    int m_f;
};

// FUNCTION: GAME 0x1C7E08
extern "C" int func_001C7E08(OmF *s)
{
    s->m_a = 0;
    s->m_b = 0;
    s->m_c = 0;
    s->m_d = 0;
    s->m_f &= ~0x40;
    return 1;
}

struct OmG {
    char _pad[0x24C];
    float m_24c;
    unsigned m_250;
    char _pad2[0x2F4 - 0x254];
    unsigned char m_a, m_b, m_c, m_d;
};

// FUNCTION: GAME 0x1D0108
extern "C" void func_001D0108(OmG *s)
{
    s->m_24c = 1.0f;
    s->m_250 &= ~0x10;
    s->m_a = 0;
    s->m_b = 0x10;
    s->m_c = 0;
    s->m_d = 0;
}

// FUNCTION: GAME 0x1DE050
extern "C" void func_001DE050(char *self, int on)
{
    if (on)
        SetMoveOffsetPosXSin__12CustomIDWorkiUs(self + 0x162C, 4, 8);
    else
        ResetMoveOffsetPos__12CustomIDWork(self + 0x162C);
}

// FUNCTION: GAME 0x1DF820
extern "C" void func_001DF820(char *self, int on)
{
    if (on)
        SetMoveOffsetPosXSin__12CustomIDWorkiUs(self + 0x440, 4, 8);
    else
        ResetMoveOffsetPos__12CustomIDWork(self + 0x440);
}

// FUNCTION: GAME 0x1DF858
extern "C" char *func_001DF858(char *self)
{
    func_001DD068(self);
    func_001DEC70(self + 0x25B0);
    *(int *)(self + 0x2E50) = 0;
    return self;
}

struct VT1C {
    char _pad[0x70];
    short adj;
    short _pad2;
    void (*fn)(void *);
};

// FUNCTION: GAME 0x1C25F0
extern "C" void setFixPos__7cOmItemRC4cVec(char *self)
{
    VT1C *vt = *(VT1C **)(self + 0x214);
    vt->fn(self + vt->adj);
    *(unsigned char *)(self + 0x676) |= 2;
}

// FUNCTION: GAME 0x1C2C00
extern "C" void func_001C2C00(char *self)
{
    short h = *(short *)(self + 0x5F4);
    if (h >= 0)
        func_002CBA48(Snd, 2, h, self, 0, 0, 0, 0);
}

// FUNCTION: GAME 0x1C2D60
extern "C" void func_001C2D60(char *self)
{
    short h = *(short *)(self + 0x5F6);
    if (h >= 0)
        func_002CBA48(Snd, 2, h, self, 0, 0, 0, 0);
}
