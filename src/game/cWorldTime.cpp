#include "game/cWorldTime.h"

extern "C" void func_002D9D50(cWorldTime *, unsigned int, unsigned int *, unsigned int *, unsigned int *);

// FUNCTION: GAME 0x2D9BC0
void cWorldTime::gameInit()
{
    m_globalTime = 0;
}

// FUNCTION: GAME 0x2D9D40
void cWorldTime::setGlobalTime(unsigned int t)
{
    m_globalTime = t;
}

// FUNCTION: GAME 0x2D9DB8
void cWorldTime::getGlobalHMS(unsigned int *h, unsigned int *m, unsigned int *s)
{
    func_002D9D50(this, m_globalTime, h, m, s);
}

// FUNCTION: GAME 0x2D9DE8
void cWorldTime::getStageHMS(unsigned int *h, unsigned int *m, unsigned int *s)
{
    func_002D9D50(this, m_stageTime, h, m, s);
}
