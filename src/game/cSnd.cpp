#include "game/cSnd.h"

// FUNCTION: GAME 0x2CC4B8
sSeData *cSnd::GetSeData(int i)
{
    return m_seData + i;
}

// FUNCTION: GAME 0x2D0AB8
void cSnd::SetBgmState(eBgmState s)
{
    m_bgmState = s;
}

// FUNCTION: GAME 0x2D2D68
void cSnd::SetBgmLevel(int a, eBgmReqNo b, int c, float f)
{
    m_bgmLvA = a;
    m_bgmLvB = b;
    m_bgmLvC = c;
    m_bgmLvF = f;
}
