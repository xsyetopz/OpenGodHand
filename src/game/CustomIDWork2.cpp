#include "game/CustomIDWork.h"

// FUNCTION: GAME 0x2D66F8
void CustomIDWork::SetOffsetPosY(int a)
{
    if (m_work) {
        m_unk28 = 0;
        m_work->m_offsetY = (float)a;
    }
}

// FUNCTION: GAME 0x2D69F0
void CustomIDWork::SetScaleAnimSin(float a, float b, unsigned short t)
{
    if (m_work) {
        m_unk64 = a;
        m_unk68 = b;
        m_unk6C = a;
        m_unk5C = 5;
        m_unk70 = b;
        m_unk74 = t;
        if (t == 0)
            m_unk74 = 1;
        m_unk76 = 0;
    }
}
