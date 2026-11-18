#include "game/cOl29.h"

// FUNCTION: GAME 0x17F9B0
void cOl29::setOpen()
{
    if (m_open == 0) {
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17F9D8
void cOl29::setClose()
{
    if (m_open == 1) {
        m_act0 = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17FAF0
unsigned char cOl29::isOpen()
{
    return m_open;
}

// FUNCTION: GAME 0x17FA00
void cOl29::setOpenFix()
{
    if (m_open == 0) {
        cVec16 v;
        cObjCopyVec(&v, vGetPos());
        vSetPos(*(cVec *)&v);
        m_open = 1;
        m_act0 = 0;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17FA78
void cOl29::setCloseFix()
{
    if (m_open == 1) {
        cVec16 v;
        cObjCopyVec(&v, vGetPos());
        vSetPos(*(cVec *)&v);
        m_open = 0;
        m_act0 = 0;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}
