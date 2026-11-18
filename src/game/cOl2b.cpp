#include "game/cOl2b.h"

// FUNCTION: GAME 0x180310
void cOl2b::setOpen()
{
    if (m_state != 1) {
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180338
void cOl2b::setClose()
{
    if (m_state != 2) {
        m_act0 = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180360
void cOl2b::setInit()
{
    if (m_state != 0) {
        m_act0 = 3;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180688
int cOl2b::getState()
{
    return m_state;
}

// FUNCTION: GAME 0x180690
unsigned char cOl2b::isActive()
{
    return m_active;
}
