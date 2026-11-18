#include "game/cObjSimple.h"

// FUNCTION: GAME 0x2B6918
void cObjSimple::R0_Init()
{
    m_act0 = 1;
    m_act1 = 0;
    m_act2 = 0;
    m_act3 = 0;
}

// FUNCTION: GAME 0x2B84F8
void cObjSimple::SetRingFlag(bool b)
{
    m_ringFlag = b;
}

// FUNCTION: GAME 0x2B8500
void cObjSimple::SetBustFlag(bool b)
{
    m_bustFlag = b;
}

// FUNCTION: GAME 0x2B8570
void cObjSimple::SetPackIndex(int i)
{
    if (i >= 0) {
        m_packIndex = i;
        m_packSet = 1;
    }
}
