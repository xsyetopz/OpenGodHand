#include "game/cOl22.h"

// FUNCTION: GAME 0x17E678
void cOl22::setOpen()
{
    if (m_open == 0) {
        m_active = 1;
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17E7D0
unsigned char cOl22::isOpen()
{
    return m_open;
}

// FUNCTION: GAME 0x17E6A0
void cOl22::setOpenFix()
{
    if (m_open == 0) {
        if (getParts(0)) {
            cObjParts *p = getParts(0);
            cVec *v = &p->m_v;
            v->x = -1.5707964f;
            v->y = 0;
            v->z = 0;
        }
        m_open = 1;
        m_active = 0;
        m_act0 = 0;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17E738
void cOl22::setCloseFix()
{
    if (m_open == 1) {
        if (getParts(1)) {
            cObjParts *p = getParts(1);
            cVec *v = &p->m_v;
            v->x = 1.5707964f;
            v->y = 0;
            v->z = 0;
        }
        m_open = 0;
        m_active = 0;
        m_act0 = 0;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}
