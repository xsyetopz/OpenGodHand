#include "game/cOm5a.h"

// FUNCTION: GAME 0x1ADA78
unsigned char cOm5a::isOpen()
{
    return m_open;
}

// FUNCTION: GAME 0x1ADA80
unsigned char cOm5a::isActive()
{
    return m_active;
}

// FUNCTION: GAME 0x1ADAE8
void cOm5a::setFaceOpen()
{
    m_unk604 = 0;
    m_unk608 = 1;
}

// FUNCTION: GAME 0x1AD8E8
void cOm5a::setClose()
{
    if (m_open == 1) {
        m_active = m_open;
        m_mode2F4 = 2;
        m_mode2F5 = 0;
        m_mode2F6 = 0;
        m_mode2F7 = 0;
    }
}

// FUNCTION: GAME 0x1ADAF8
void cOm5a::setFaceClose()
{
    m_unk608 = 2;
    m_unk604 = 0;
    if (m_dmgUnit)
        m_dmgUnit->SetDamageCollActive(false);
}
