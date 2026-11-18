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

// FUNCTION: GAME 0x2A9350
void cGameObj::setSuspend(bool suspend)
{
    if (suspend == 1)
        m_flags250 |= 0x8000;
    else
        m_flags250 &= ~0x8000;
    if (suspend == 1)
        m_flags5A0 |= 8;
    else
        m_flags5A0 &= ~8;
}

// FUNCTION: GAME 0x2A7498
void cGameObj::SetTgtTurn(const cVec &tgt, float speed)
{
    m_rot.y = Adjust_theta(m_rot.y + Turn_dest((const float *)m_pPos, m_rot.y, (const float *)&tgt, speed * D_007479FC));
}

extern int cModel_isClip(const void *) __asm__("isClip__C6cModel");

// FUNCTION: GAME 0x2A7448
bool cGameObj::isClip() const
{
    if (m_f0)
        return true;
    if (m_f1)
        return true;
    return cModel_isClip(this) != 0;
}
