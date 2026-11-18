#include "game/cOl26.h"

// FUNCTION: GAME 0x17F1F0
void cOl26::setOpen()
{
    if (m_open == 0) {
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17F218
unsigned char cOl26::isOpen()
{
    return m_open;
}
