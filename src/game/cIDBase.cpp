// Small free functions in the cIDBase neighbourhood (0x13C000-0x13EFFF).

struct sIDWorkA {
    char _pad0[0x74];
    unsigned char m_unk74;
    char _pad75[3];
    unsigned char m_unk78;
    unsigned char m_unk79;
    unsigned char m_unk7A;
    unsigned char m_unk7B;
    unsigned char m_unk7C;
};

struct sIDWorkB {
    char _pad0[0x90];
    int m_unk90;
    int m_unk94;
    char _pad98[4];
    int m_unk9C;
    int m_unkA0;
    float m_unkA4;
    char _padA8[0xB8 - 0xA8];
    int m_unkB8;
};

struct sIDWorkC {
    char _pad0[0x90];
    short m_unk90;
    unsigned char m_unk92;
    unsigned char m_unk93;
};

// FUNCTION: GAME 0x13C618
extern "C" void func_0013C618(sIDWorkA *self)
{
    self->m_unk74 = 0;
    self->m_unk79 = 0;
    self->m_unk7A = 0;
    self->m_unk7B = 0;
    self->m_unk7C = 0;
}

// FUNCTION: GAME 0x13C750
extern "C" void func_0013C750()
{
}

// FUNCTION: GAME 0x13C808
extern "C" void func_0013C808(sIDWorkB *self)
{
    self->m_unk94 = 0;
    self->m_unk9C = 0;
}

// FUNCTION: GAME 0x13C930
extern "C" void func_0013C930(sIDWorkB *self)
{
    self->m_unkA4 = 1.0f;
    self->m_unk94 = 0;
    self->m_unk9C = 0;
    self->m_unkA0 = 0;
    self->m_unkB8 = 0;
}

// FUNCTION: GAME 0x13D148
extern "C" void func_0013D148()
{
}

// FUNCTION: GAME 0x13D1D0
extern "C" void func_0013D1D0(sIDWorkC *self)
{
    self->m_unk90 = 6;
    self->m_unk93 = 0;
    self->m_unk92 = 0;
}

// FUNCTION: GAME 0x13D1E8
extern "C" void func_0013D1E8(sIDWorkC *self)
{
    self->m_unk90 = 6;
    self->m_unk93 = 0;
    self->m_unk92 = 0;
}

// FUNCTION: GAME 0x13E3F8
extern "C" void func_0013E3F8(char *self)
{
    self[0x104] = 0;
}

// FUNCTION: GAME 0x13E400
extern "C" void func_0013E400(sIDWorkB *self)
{
    if (self->m_unk90)
        self->m_unk90 = 0;
}

// FUNCTION: GAME 0x13E7D8
extern "C" void func_0013E7D8(sIDWorkB *self)
{
    self->m_unk94 = 0;
    self->m_unk9C = 0;
}
