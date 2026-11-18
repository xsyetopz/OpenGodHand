// Unnamed state setters writing the 4-byte command block at 0x2F4.
struct CmdBlk {
    char _pad[0x2F4];
    unsigned char m_f4, m_f5, m_f6, m_f7;
};

// FUNCTION: GAME 0x1D04D0
extern "C" void func_001D04D0(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x6;
    self->m_f6 = 0;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D04E8
extern "C" void func_001D04E8(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x6;
    self->m_f6 = 0x2;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0508
extern "C" void func_001D0508(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x6;
    self->m_f6 = 0x4;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0528
extern "C" void func_001D0528(CmdBlk *self, unsigned char x)
{
    self->m_f4 = 0;
    self->m_f5 = 0x6;
    self->m_f6 = 0x6;
    self->m_f7 = x;
}

// FUNCTION: GAME 0x1D0540
extern "C" void func_001D0540(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x6;
    self->m_f6 = 0xC;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0560
extern "C" void func_001D0560(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x6;
    self->m_f6 = 0x8;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0580
extern "C" void func_001D0580(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x6;
    self->m_f6 = 0xA;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D05A0
extern "C" void func_001D05A0(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x6;
    self->m_f6 = 0xE;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D05C0
extern "C" void func_001D05C0(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D05D8
extern "C" void func_001D05D8(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x2;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D05F8
extern "C" void func_001D05F8(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x4;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0618
extern "C" void func_001D0618(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x6;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0638
extern "C" void func_001D0638(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x8;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0658
extern "C" void func_001D0658(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x7;
    self->m_f6 = 0xA;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0678
extern "C" void func_001D0678(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x7;
    self->m_f6 = 0xC;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0698
extern "C" void func_001D0698(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x7;
    self->m_f6 = 0xE;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D06B8
extern "C" void func_001D06B8(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x10;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D06D8
extern "C" void func_001D06D8(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x12;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D06F8
extern "C" void func_001D06F8(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x14;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0718
extern "C" void func_001D0718(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x16;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0738
extern "C" void func_001D0738(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x18;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0758
extern "C" void func_001D0758(CmdBlk *self, unsigned char x)
{
    self->m_f7 = x;
    self->m_f5 = 0x7;
    self->m_f6 = 0x1A;
    self->m_f4 = 0;
}

// FUNCTION: GAME 0x1D0778
extern "C" void func_001D0778(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x7;
    self->m_f6 = 0x1C;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D0798
extern "C" void func_001D0798(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x8;
    self->m_f6 = 0;
    self->m_f7 = 0;
}

// FUNCTION: GAME 0x1D07B0
extern "C" void func_001D07B0(CmdBlk *self)
{
    self->m_f4 = 0;
    self->m_f5 = 0x9;
    self->m_f6 = 0;
    self->m_f7 = 0;
}

struct FltBlk {
    char _pad[0x66C];
    float m_f66C;
};

// FUNCTION: GAME 0x1D0AD0
extern "C" void func_001D0AD0(FltBlk *self)
{
    self->m_f66C = 450.0f;
}

// FUNCTION: GAME 0x1D0AE0
extern "C" int func_001D0AE0(FltBlk *self)
{
    return self->m_f66C > 0.0f;
}

struct TwoWord {
    int m_a;
    int m_b;
};

// FUNCTION: GAME 0x1D0C78
extern "C" TwoWord *func_001D0C78(TwoWord *self)
{
    self->m_a = 0;
    self->m_b = 2;
    return self;
}
