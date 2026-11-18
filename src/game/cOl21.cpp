#include "game/cOl21.h"

// FUNCTION: GAME 0x17E010
void cOl21::setCollisionActive(bool b, float f)
{
    for (int i = 0; i < 8; i++) {
        cOl21Col *c = m_col[i];
        if (b == 1)
            c->m_flags |= 1;
        else
            c->m_flags &= ~1;
    }
    m_unk608 = f;
}
