#include "game/cSceAtManager.h"

extern "C" cSceAtUnit *atIterBegin(cSceAtManager *) __asm__("func_002C30C0");
extern "C" cSceAtUnit *atIterNext(cSceAtManager *, cSceAtUnit *) __asm__("func_002C30C8");

// FUNCTION: GAME 0x2C3118
cSceAtUnit *cSceAtManager::getUnit(unsigned int id)
{
    if (id == 0xFFFFF)
        return 0;
    cSceAtUnit *u = atIterBegin(this);
    while ((u = atIterNext(this, u)) != 0) {
        if (u->m_unk36 == id)
            return u;
    }
    return 0;
}

// FUNCTION: GAME 0x2C2AE0
cSceAtUnit *cSceAtManager::getJumpPointAt(unsigned int id)
{
    cSceAtUnit *u = atIterBegin(this);
    while ((u = atIterNext(this, u)) != 0) {
        if (u->m_type == 1 && u->m_unk79 == id)
            return u;
    }
    return 0;
}
