#include "game/cOl40.h"

// FUNCTION: GAME 0x186670
unsigned char cOl40::isDead()
{
    return m_dead;
}

// FUNCTION: GAME 0x186678
void cOl40::setVitalMax(int v)
{
    m_vitB[0] = v;
    m_vitA[0] = v;
    m_vitB[1] = v;
    m_vitA[1] = v;
    m_vitB[2] = v;
    m_vitA[2] = v;
    m_vitB[3] = v;
    m_vitA[3] = v;
}
