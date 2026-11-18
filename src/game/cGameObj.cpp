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

// FUNCTION: GAME 0x2A9468
cVec *cGameObj::getHitCheckPos()
{
    cGameObjVTable *vt = m_vt;
    return vt->m_fn((char *)this + vt->m_delta);
}

// FUNCTION: GAME 0x2A93A8
cVec *cGameObj::getLockOnPos()
{
    cGameObjVTable *vt = m_vt;
    return vt->m_fn((char *)this + vt->m_delta);
}

// FUNCTION: GAME 0x2A93D0
void cGameObj::setPos(const cVec &pos)
{
    m_pos = pos;
    *m_pPos = m_pos;
}

// FUNCTION: GAME 0x2A9420
void cGameObj::setRot(const cVec &rot)
{
    m_rot = rot;
}
