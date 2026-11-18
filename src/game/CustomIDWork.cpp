#include "game/CustomIDWork.h"

#ifdef NONMATCHING
// GAME 0x2D6510: 13 words differ under SN 2.95.3-136.
void CustomIDWork::SetChildNoDisp(bool b)
{
    cIDWork *w = m_work;
    if (w) {
        if (b)
            w->m_flags |= 8;
        else
            w->m_flags &= ~8;
    }
}
#endif

// FUNCTION: GAME 0x2D6548
void CustomIDWork::SetNumber(int n)
{
    if (m_work)
        m_work->m_number = n;
}

// FUNCTION: GAME 0x2D6560
void CustomIDWork::SetMessNo(int n)
{
    if (m_work)
        m_work->m_messNo = n;
}

// FUNCTION: GAME 0x2D6948
void CustomIDWork::ResetColorAnim()
{
    cIDWork *w = m_work;
    if (w) {
        m_unk48 = 0;
        w->m_unk4C = m_unk4C;
    }
}
