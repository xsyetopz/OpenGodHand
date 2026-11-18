#include "game/cDamageUnit.h"

// FUNCTION: GAME 0x1FD668
void cDamageUnit::SetDamageCollActive(bool on)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (on == 1)
            n->m_coll->m_flags |= 2;
        else
            n->m_coll->m_flags &= ~2;
    }
}

// FUNCTION: GAME 0x1FD610
void cDamageUnit::SetDamageCollActive(int id, bool on)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (n->m_id == id) {
            if (on == 1)
                n->m_coll->m_flags |= 2;
            else
                n->m_coll->m_flags &= ~2;
            return;
        }
    }
}

// FUNCTION: GAME 0x1FD718
void cDamageUnit::SetDamageCollFlashActive(bool on, short flash)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (on == 1)
            n->m_coll->m_flags |= 2;
        else
            n->m_coll->m_flags &= ~2;
        n->m_flash = flash;
    }
}
