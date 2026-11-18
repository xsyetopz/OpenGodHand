// Small unnamed functions in 0x260000-0x28FFFF.

// FUNCTION: GAME 0x280A08
extern "C" void func_00280A08(void) {}

// FUNCTION: GAME 0x280AE8
extern "C" void func_00280AE8(void) {}

// FUNCTION: GAME 0x280AF0
extern "C" void func_00280AF0(void) {}

// FUNCTION: GAME 0x280B58
extern "C" void func_00280B58(void) {}

// FUNCTION: GAME 0x282D68
extern "C" void func_00282D68(void) {}

// FUNCTION: GAME 0x282E48
extern "C" void func_00282E48(void) {}

struct Fn260Obj15B0 {
    char _pad0[0x15B0];
    int m_flags;
};

// FUNCTION: GAME 0x2831A0
extern "C" void func_002831A0(Fn260Obj15B0 *self)
{
    *(char *)&self->m_flags = 1;
}

// FUNCTION: GAME 0x289028
extern "C" void func_00289028(Fn260Obj15B0 *self)
{
    self->m_flags |= 8;
}

class cEm30 {
public:
    char _pad0[0x2F4];
    char m_unk2F4;
    char m_unk2F5;
    char m_unk2F6;
    char m_unk2F7;
    void setEvent();
};

// FUNCTION: GAME 0x278000
void cEm30::setEvent()
{
    m_unk2F5 = 4;
    m_unk2F4 = 0;
    m_unk2F6 = 0;
    m_unk2F7 = 0;
}

// FUNCTION: GAME 0x282E50
extern "C" void func_00282E50(void) {}

// FUNCTION: GAME 0x282EB8
extern "C" void func_00282EB8(void) {}

// FUNCTION: GAME 0x288DA0
extern "C" void func_00288DA0(void) {}

// FUNCTION: GAME 0x28AC50
extern "C" void func_0028AC50(void) {}

// FUNCTION: GAME 0x28C3F8
extern "C" void func_0028C3F8(void) {}

// FUNCTION: GAME 0x28E418
extern "C" void func_0028E418(void) {}

// FUNCTION: GAME 0x28EA30
extern "C" void func_0028EA30(void) {}

// FUNCTION: GAME 0x28FE48
extern "C" void func_0028FE48(void) {}
