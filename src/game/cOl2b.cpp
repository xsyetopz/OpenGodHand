#include "game/cOl2b.h"

// FUNCTION: GAME 0x180310
void cOl2b::setOpen()
{
    if (m_state != 1) {
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180338
void cOl2b::setClose()
{
    if (m_state != 2) {
        m_act0 = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180360
void cOl2b::setInit()
{
    if (m_state != 0) {
        m_act0 = 3;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180688
int cOl2b::getState()
{
    return m_state;
}

// FUNCTION: GAME 0x180690
unsigned char cOl2b::isActive()
{
    return m_active;
}

extern cVec16 D_00567FF0[3];
extern cVec16 D_00568020[3];
extern cVec16 D_00567FC0[3];

// FUNCTION: GAME 0x180388
void cOl2b::setOpenFix()
{
    if (m_state != 1) {
        for (int i = 0; i < 3; i++) {
            cObjParts *p = getParts(i);
            if (p)
                p->m_v = *(cVec *)&D_00567FF0[i];
        }
        m_act0 = 0;
        m_state = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}
