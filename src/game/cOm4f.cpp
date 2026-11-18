#include "game/cOm4f.h"

// FUNCTION: GAME 0x1A4F10
unsigned char cOm4f::isOpen()
{
    return m_open;
}

// FUNCTION: GAME 0x1A4F18
unsigned char cOm4f::isActive()
{
    return m_active;
}

// FUNCTION: GAME 0x1A4F20
void cOm4f::setEventMode(bool on)
{
    m_eventMode = on;
}

// FUNCTION: GAME 0x1A4F28
void cOm4f::setLock(bool on)
{
    m_lock = on;
}
