#include "game/cSceAtManager.h"

#ifdef NONMATCHING
// DRAFT: GAME 0x2C2870
// 7 words: original types in v1, table base in v0, fn in v0; ours uses v0/a2/v1. Tried entry ptr, cast arithmetic, hoisted base, early return, 2D array.
void cSceAtManager::AtExecute(cSceAtUnit *unit)
{
    if (unit != 0) {
        cSceAtExecEntry *e = &D_003C2650[unit->m_type];
        e->m_fn(unit, 0xFF);
    }
}

// DRAFT: GAME 0x2C28B0
// 7 words: same register allocation difference as AtExecute(unit).
void cSceAtManager::AtExecute(unsigned short id)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit != 0) {
        cSceAtExecEntry *e = &D_003C2650[unit->m_type];
        e->m_fn(unit, 0xFF);
    }
}
#endif
