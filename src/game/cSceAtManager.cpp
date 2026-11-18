#include "game/cSceAtManager.h"

// FUNCTION: GAME 0x2C2728
void cSceAtManager::SetDoorFunc(cSceAtUnit *unit, void *a, void *b)
{
    if (unit && unit->m_type == 1) {
        unit->m_unk74 = a;
        unit->m_unk70 = b;
    }
}
