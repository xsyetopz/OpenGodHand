#include "game/cObj.h"

// FUNCTION: GAME 0x14E768
void cObj::R0_scenario()
{
}

// FUNCTION: GAME 0x14E928
void cObj::Release()
{
}

// FUNCTION: GAME 0x14E930
void cObj::setSuspend(bool b)
{
    if (b == 1)
        m_flags |= 0x8000;
    else
        m_flags &= ~0x8000;
}
