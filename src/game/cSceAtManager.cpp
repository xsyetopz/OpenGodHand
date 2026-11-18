#include "game/cSceAtManager.h"

// FUNCTION: GAME 0x2C2728
void cSceAtManager::SetDoorFunc(cSceAtUnit *unit, void *a, void *b)
{
    if (unit && unit->m_type == 1) {
        unit->m_unk74 = a;
        unit->m_unk70 = b;
    }
}

// FUNCTION: GAME 0x2C2838
void cSceAtManager::AtDataReset(unsigned short id)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit)
        AtDataReset(unit);
}

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
