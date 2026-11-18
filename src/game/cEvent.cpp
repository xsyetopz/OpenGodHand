#include "game/cEvent.h"

extern unsigned int D_00747A84;

// FUNCTION: GAME 0x297C20
int cEvent::isPlaying() const
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    return m_state == 3;
}
