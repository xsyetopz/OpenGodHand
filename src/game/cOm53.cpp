#include "game/cOm53.h"

// FUNCTION: GAME 0x1A80F0
void cOm53::setRiseWaitTime(unsigned int t)
{
    m_riseWaitTime = t;
}

// FUNCTION: GAME 0x1A80F8
void cOm53::setDownPos(float y)
{
    m_downPos = y;
}

// FUNCTION: GAME 0x1A7F20
int cOm53::setGetOffEm(unsigned int n)
{
    if (!m_unk612)
        return 0;
    if (!n)
        return 0;
    m_unk615 += n;
    return 1;
}
