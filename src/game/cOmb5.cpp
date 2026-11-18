#include "game/cOmb5.h"

// FUNCTION: GAME 0x1B6680
void cOmb5::setActive(bool on)
{
    if (on)
        m_flags5B8 |= 1;
    else
        m_flags5B8 &= ~1;
}
