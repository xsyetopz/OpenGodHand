#include "game/cOl22.h"

// FUNCTION: GAME 0x17E678
void cOl22::setOpen()
{
    if (m_open == 0) {
        m_active = 1;
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17E7D0
unsigned char cOl22::isOpen()
{
    return m_open;
}
