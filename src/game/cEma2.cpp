#include "game/cEma2.h"

// FUNCTION: GAME 0x2896A0
int cEma2::ckKiss()
{
    return m_unk15B1 & 1;
}

// FUNCTION: GAME 0x289068
void cEma2::SetPoison()
{
    m_act0 = 0;
    m_act1 = 5;
    m_act2 = 0;
    m_act3 = 0;
}

// FUNCTION: GAME 0x289080
void cEma2::SetPoisonDie()
{
    m_act0 = 0;
    m_act1 = 5;
    m_act2 = 2;
    m_act3 = 0;
}
