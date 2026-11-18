#include "game/cOmDoor.h"

// FUNCTION: GAME 0x1BD178
void cOmDoor::setLock(bool on)
{
    if (on == 1)
        m_doorFlags |= 2;
    else
        m_doorFlags &= ~2;
}
