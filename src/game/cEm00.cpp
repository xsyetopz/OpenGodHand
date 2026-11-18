#include "game/cEm00.h"

// FUNCTION: GAME 0x26F0E0
int cEm00::ckDown()
{
    if (!(m_unk3AC & 8))
        return 0;
    int r = 1;
    if ((*(unsigned long *)&m_unk2F0 & 0xFFFF00000000UL) == 0x020200000000UL)
        r = 0;
    return r;
}

// FUNCTION: GAME 0x273640
int cEm00::CkDevilEvent()
{
    if (m_act0 != 0)
        return 0;
    if (m_act1 != 4)
        return 0;
    return m_act2 >= 2;
}

// FUNCTION: GAME 0x273D28
void cEm00::setAlphaMode(bool b)
{
    m_alphaMode = b;
}

// FUNCTION: GAME 0x274140
void cEm00::setNoLost()
{
    m_flagsB |= 0x1000;
}

// FUNCTION: GAME 0x2751C8
void cEm00::setR302Switch()
{
    int d = m_id ^ 0x252;
    if (d == 0) {
        m_act0 = 0;
        m_act1 = 0x8F;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x275638
void cEm00::setDevilEventFlag()
{
    m_unk1644 |= 0x800000;
}

// FUNCTION: GAME 0x275650
bool cEm00::ckBananaDance()
{
    unsigned int m = 0x2000000;
    return (m_flagsB & m) != 0;
}

// FUNCTION: GAME 0x2761B0
void cEm00::setR608EventEnd()
{
    m_act0 = 0;
    m_act1 = 0x68;
    m_act2 = 4;
    m_act3 = 0;
}

// FUNCTION: GAME 0x2761D0
void cEm00::setEm65Separate()
{
    m_unk54C = 3.0f;
    m_act0 = 0;
    m_act1 = 0x9A;
    m_act2 = 0;
    m_act3 = 0;
}

// FUNCTION: GAME 0x2761F8
void cEm00::setNeckMoveOff()
{
    m_flagsB |= 0x80000000;
}

// FUNCTION: GAME 0x276210
void cEm00::setNeckMoveOn()
{
    m_flagsB &= 0x7FFFFFFF;
}

// FUNCTION: GAME 0x273678
void cEm00::setSitChair(const cVec &pos, float rot)
{
    m_flagsA &= 0xDFFFFFFF;
    m_unk16EC = 0;
    m_sitPos = pos;
    *m_pos = m_sitPos;
    m_rotY = rot;
    m_unk1650 = 5;
    m_act0 = 0;
    m_act1 = 1;
    m_act2 = 0;
    m_act3 = 0;
}
