#include "game/cEmWrap.h"

extern "C" int func_00295978(cEmWrap *);
extern "C" void func_0028FB08(cEmBase *);
extern cVec ZeroVec;

// FUNCTION: GAME 0x295AB8
const cVec *cEmWrap::getPos()
{
    if (!func_00295978(this)) {
        return &ZeroVec;
    }
    return m_em->m_pos;
}

// FUNCTION: GAME 0x295AF8
const cVec *cEmWrap::getRot()
{
    if (!func_00295978(this)) {
        return &ZeroVec;
    }
    return &m_em->m_rot;
}

// FUNCTION: GAME 0x295B80
void cEmWrap::setMutekiTimer(float t)
{
    if (func_00295978(this)) {
        m_em->m_mutekiTimer = t;
    }
}

// FUNCTION: GAME 0x295C70
void cEmWrap::setDead()
{
    if (func_00295978(this)) {
        func_0028FB08(m_em);
    }
}

// FUNCTION: GAME 0x295CA8
int cEmWrap::isDead()
{
    if (!func_00295978(this)) {
        return 1;
    }
    return m_em->checkDeadFlag();
}

// FUNCTION: GAME 0x295D30
void cEmWrap::SetVital(int v)
{
    if (func_00295978(this)) {
        if (v >= m_em->m_vitalMax) {
            m_em->m_vital = m_em->m_vitalMax;
        } else {
            m_em->m_vital = v;
        }
    }
}

// FUNCTION: GAME 0x295D88
void cEmWrap::SetVitalMax(int v)
{
    if (func_00295978(this)) {
        m_em->m_vitalMax = v;
    }
}

// FUNCTION: GAME 0x295DC8
int cEmWrap::GetVital()
{
    if (!func_00295978(this)) {
        return 0;
    }
    return m_em->m_vital;
}

// FUNCTION: GAME 0x295E00
int cEmWrap::GetVitalMax()
{
    if (!func_00295978(this)) {
        return 0;
    }
    return m_em->m_vitalMax;
}

// FUNCTION: GAME 0x295E38
void cEmWrap::setDropItem(eObjId id)
{
    if (func_00295978(this)) {
        m_em->m_dropItem = id;
    }
}

// FUNCTION: GAME 0x295EE0
void cEmWrap::SetRaderType(signed char t)
{
    if (func_00295978(this)) {
        m_em->m_raderType = t;
    }
}
