#include "game/cSceAtManager.h"

#ifdef NONMATCHING
// DRAFT: GAME 0x2C2870
// 7 words: original loads m_type into v1 and the table base into v0, then reuses v0 for fn; ours loads the base into a2 and fn into v1. Tried entry ptr, cast arithmetic, hoisted base, early return, 2D array, temp index, direct member call, unsigned char index, int index cast.
void cSceAtManager::AtExecute(cSceAtUnit *unit)
{
    if (unit != 0) {
        cSceAtExecEntry *e = &D_003C2650[unit->m_type];
        e->m_fn(unit, 0xFF);
    }
}

// DRAFT: GAME 0x2C28B0
// 7 words: same register allocation difference as AtExecute(unit). Tried unsigned char index (7) and int index cast (7).
void cSceAtManager::AtExecute(unsigned short id)
{
    cSceAtUnit *unit = getUnit(id);
    if (unit != 0) {
        cSceAtExecEntry *e = &D_003C2650[unit->m_type];
        e->m_fn(unit, 0xFF);
    }
}
#endif
