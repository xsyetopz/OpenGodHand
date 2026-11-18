#include "game/cGameObj.h"

// FUNCTION: GAME 0x2A9458
cVec *cGameObj::getPos()
{
    return m_pPos;
}

// FUNCTION: GAME 0x2A9460
cVec *cGameObj::getRot()
{
    return &m_rot;
}
