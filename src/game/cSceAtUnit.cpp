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

#ifdef NONMATCHING
// 0x2C0D18 NEAR-MISS: 14 words: store scheduling/register allocation of a1..t0 (s1..s4) differs; offset-order source made it worse
void cSceAtUnit::AtInit(eSceAt_id id, eAreaHitType hit, eAreaTrgType trg, eActType act)
{
    memset(this, 0, 0x9C);
    m_type = id;
    m_unk3B = trg;
    _pad38[0] = hit;
    m_unk3A = act;
    m_unk36 = 0xFFFF;
    m_flags = 3;
    _pad38[1] = 8;
    m_unk54 = 0x31;
}
#endif

// FUNCTION: GAME 0x2C0E78
void cSceAtUnit::getCenterPos(cVec &out)
{
    unsigned char t = m_flags ^ 1;
    if ((t & 1) == 0) {
        ((cArea *)((char *)this + 4))->AreaGetCenterPos(out);
        out.y = out.y + 0.4f;
    }
}
