#include "game/cSceAtUnit.h"

// FUNCTION: GAME 0x2C0DD8
void cSceAtUnit::ActTypeSet(eActType actType, eActType actType2)
{
    m_unk3A = actType;
    m_unk54 = actType2;
}

// FUNCTION: GAME 0x2C0DE8
void cSceAtUnit::SetEnable(unsigned char)
{
    cSceAtUnit *u = this;
    u->m_flags |= 1;
    if (u->m_type == 9)
        func_002C0E20(u);
}

// FUNCTION: GAME 0x2C0E28
void cSceAtUnit::SetDisable(unsigned char)
{
    m_flags &= 0xFE;
    if (m_type == 9)
        func_002C0E60(this);
}

// FUNCTION: GAME 0x2C0E78
void cSceAtUnit::getCenterPos(cVec &out)
{
    unsigned char t = m_flags ^ 1;
    if ((t & 1) == 0) {
        ((cArea *)((char *)this + 4))->AreaGetCenterPos(out);
        out.y = out.y + 0.4f;
    }
}
