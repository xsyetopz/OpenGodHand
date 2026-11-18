#include "game/cSceAtManager.h"

// FUNCTION: GAME 0x2C2728
void cSceAtManager::SetDoorFunc(cSceAtUnit *unit, void *a, void *b)
{
    if (unit && unit->m_type == 1) {
        unit->m_unk74 = a;
        unit->m_unk70 = b;
    }
}

#ifdef NONMATCHING
// 0x2C2808 NEAR-MISS: 3 words: store order; original sw 0x3C in beql delay slot, sb 0x44 last
void cSceAtManager::AtDataReset(cSceAtUnit *unit)
{
    if (unit) {
        if (unit->m_unk4E) {
            unit->m_unk3B = unit->m_unk4E;
            unit->m_unk4E = 0;
        }
        unit->m_unk3C = 0;
        unit->m_unk44 = 0;
    }
}
#endif

// FUNCTION: GAME 0x2C2838
void cSceAtManager::AtDataReset(unsigned short id)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit)
        AtDataReset(unit);
}

#ifdef NONMATCHING
// 0x2C2870 NEAR-MISS: 7 words: original keeps unit in a0 and table base in v0; ours reuses v0 for unit, v1 for fn ptr
void cSceAtManager::AtExecute(cSceAtUnit *unit)
{
    if (unit)
        D_003C2650[unit->m_type].m_fn(unit, 0xFF);
}
#endif

#ifdef NONMATCHING
// 0x2C28B0 NEAR-MISS: 7 words: same as AtExecute(unit)
void cSceAtManager::AtExecute(unsigned short id)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit)
        D_003C2650[unit->m_type].m_fn(unit, 0xFF);
}
#endif

#ifdef NONMATCHING
// 0x2C3118 NEAR-MISS: 19 words: original loops with b to a check and bnel delay-slot lhu; ours tests null first and keeps nops
cSceAtUnit *cSceAtManager::getUnit(unsigned int id)
{
    if (id == 0xFFFFF)
        return 0;
    for (cSceAtUnit *u = func_002C30C0(this); u; u = func_002C30C8(this)) {
        if (u->m_unk36 == id)
            return u;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x2C2750
void cSceAtManager::AtDataSet_exec(cSceAtUnit *unit, int a, void *b, void *c, eAreaTrgType trg)
{
    if (unit) {
        if (trg) {
            if (!unit->m_unk4E)
                unit->m_unk4E = unit->m_unk3B;
            unit->m_unk3B = trg;
        }
        unit->m_unk44 = a;
        unit->m_unk3C = (unsigned int)b;
        unit->m_unk40 = c;
    }
}

// FUNCTION: GAME 0x2C2790
void cSceAtManager::AtDataSet_exec(unsigned short id, int a, void *b, void *c, eAreaTrgType trg)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit)
        AtDataSet_exec(unit, a, b, c, trg);
}

// FUNCTION: GAME 0x2C28F8
int cSceAtManager::SetEnable(cSceAtUnit *unit)
{
    if (!m_unk0)
        return 0;
    if (!unit)
        return 0;
    if (!func_002C0E68(unit))
        unit->SetEnable(0);
    return 1;
}

// FUNCTION: GAME 0x2C2950
int cSceAtManager::SetEnable(unsigned short id)
{
    if (!m_unk0)
        return 0;
    cSceAtUnit *unit = getUnit(id);
    if (!unit)
        return 0;
    return SetEnable(unit);
}

// FUNCTION: GAME 0x2C2A48
void cSceAtManager::getCenterPos(unsigned short id, cVec &out)
{
    if (m_unk0) {
        cSceAtUnit *unit = getUnit(id);
        if (unit)
            unit->getCenterPos(out);
    }
}

// FUNCTION: GAME 0x2C2FD8
void cSceAtManager::delUnitData(cSceAtUnit *unit)
{
    if (unit)
        func_002C3058(this, (char *)this + 0x5C, unit);
}

// FUNCTION: GAME 0x2C29A0
int cSceAtManager::SetDisable(cSceAtUnit *unit)
{
    if (!m_unk0)
        return 0;
    if (!unit)
        return 0;
    if (func_002C0E68(unit))
        unit->SetDisable(0);
    return 1;
}

// FUNCTION: GAME 0x2C29F8
int cSceAtManager::SetDisable(unsigned short id)
{
    if (!m_unk0)
        return 0;
    cSceAtUnit *unit = getUnit(id);
    if (!unit)
        return 0;
    return SetDisable(unit);
}

// 0x2C2A98: 10 words differ (not matched)
#ifdef NONMATCHING
int cSceAtManager::isHit(unsigned int id, eScehitType t)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit)
        return func_002C0ED0(unit, t);
    return 0;
}

#endif

// 0x2C2AE0: 9 words differ (not matched)
#ifdef NONMATCHING
cSceAtUnit *cSceAtManager::getJumpPointAt(unsigned int id)
{
    for (cSceAtUnit *u = func_002C30C0(this); u; u = func_002C30C8(this)) {
        if (u->m_type == 1 && u->m_unk79 == id)
            return u;
    }
    return 0;
}
#endif
