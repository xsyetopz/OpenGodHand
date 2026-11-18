// FLAGS: -O0
// Unoptimised classFADE members at 0x3076E0-0x307760 (2.95.3-136 C++).
enum eOtType { OT0 };

class classFADE {
public:
    char _p[0x1C];
    unsigned char m_1c;
    unsigned m_20, m_24;
    void kill();
    unsigned char status();
    void setOt(eOtType, unsigned);
};

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
