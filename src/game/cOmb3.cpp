#include "game/cOmb3.h"

// FUNCTION: GAME 0x1B5180
void cOmb3::SetPointTbl(cVec *tbl, unsigned short n)
{
    m_pointTbl = tbl;
    m_pointNum = n;
}

// FUNCTION: GAME 0x1B5190
void cOmb3::SetNextPoint(unsigned short n)
{
    if (n < m_pointNum)
        m_nextPoint = n;
}
