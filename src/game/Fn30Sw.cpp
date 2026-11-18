// FLAGS: -O0
// Unoptimised classFADE members at 0x3076E0-0x307760 (2.95.3-136 C++).
enum eOtType { OT0 };

class classFADE {
public:
    unsigned long m_0;
    short m_8, m_a, m_c, m_e;
    unsigned m_10, m_14;
    unsigned short m_18, m_1a;
    unsigned char m_1c, m_1d;
    unsigned m_20, m_24;
    void kill();
    unsigned char status();
    void setOt(eOtType, unsigned);
    void start(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};

extern int DISPLAY_W;
extern int D_00747A04;
extern unsigned short D_00586B80;

// FUNCTION: GAME 0x3076E0
void classFADE::kill()
{
    m_1c = 0;
}

// FUNCTION: GAME 0x307718
unsigned char classFADE::status()
{
    return m_1c;
}

// FUNCTION: GAME 0x307760
void classFADE::setOt(eOtType t, unsigned n)
{
    m_20 = t;
    m_24 = n;
}

// FUNCTION: GAME 0x3077B0
extern "C" void func_003077B0(register int a)
{
}

// FUNCTION: GAME 0x307208
void classFADE::start(unsigned a, unsigned b, unsigned mode, unsigned c, unsigned d, unsigned e)
{
    m_10 = c;
    m_14 = d;
    m_1d = a;
    m_1c = b | 1;
    m_18 = e;
    m_18 = m_18 << D_00747A04;
    m_1a = 0;
    m_8 = (0x800 - DISPLAY_W / 2) << 4;
    m_a = D_00586B80 << 4;
    m_c = 0x2000;
    m_e = 0x1C00;
    switch (mode) {
    case 0: m_0 = 0x8000000044UL; break;
    case 1: m_0 = 0x8000000029UL; break;
    case 2: m_0 = 0x80000000A1UL; break;
    }
    setOt((eOtType)7, 1);
}
