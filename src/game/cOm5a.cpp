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
