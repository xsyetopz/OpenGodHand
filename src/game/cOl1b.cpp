#include "game/cOl1b.h"

// FUNCTION: GAME 0x17B6E8
void cOl1b::setClose()
{
    if (m_open == 1) {
        m_active = 1;
        m_act0 = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17B818
unsigned char cOl1b::isActive()
{
    return m_active;
}
