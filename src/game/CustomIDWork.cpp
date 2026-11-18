#include "game/CustomIDWork.h"

// FUNCTION: GAME 0x2D5D60
CustomIDWork::CustomIDWork()
{
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk28 = 0;
    m_unk48 = 0;
    m_unk5C = 0;
    m_work = 0;
}

// FUNCTION: GAME 0x2D5DA8
void CustomIDWork::Initialize(cIDWork *work)
{
    if (work) {
        m_work = work;
        m_unkC = work->m_posX;
        m_unk10 = work->m_posY;
        m_unk4C = work->m_unk4C;
        m_unk78 = work->m_unk2B;
    }
}

#ifdef NONMATCHING
// 0x2D6490: 2 words differ. The original compares with `xori $v0,$a1,1; beql $v0,$zero`;
// the compiler emits `addiu $v0,$zero,1; beql $a1,$v0` for every spelling tried.
void CustomIDWork::SetDisp(bool b)
{
    cIDWork *w = m_work;
    if (w) {
        if (b != 1)
            w->m_flags |= 0x20000000;
        else
            w->m_flags &= ~0x20000000;
    }
}
#endif

// FUNCTION: GAME 0x2D6510
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

#ifdef NONMATCHING
// 0x2D6630: 6 words differ. The original keeps a `nop` between mtc1 and cvt.s.w
// (36 bytes); the compiler emits none (32 bytes). Same pattern in SetLocalPosY
// (0x2D6658) and SetOffsetPosX (0x2D66D0).
void CustomIDWork::SetLocalPosX(int x)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posX = (float)x;
    }
}

// 0x2D6658
void CustomIDWork::SetLocalPosY(int y)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posY = (float)y;
    }
}

// 0x2D6680: same missing nop, twice.
void CustomIDWork::SetLocalPosXY(int x, int y)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posX = (float)x;
        m_work->m_posY = (float)y;
    }
}

// 0x2D66D0
void CustomIDWork::SetOffsetPosX(int x)
{
    if (m_work) {
        m_unk28 = 0;
        m_work->m_offsetX = (float)x;
    }
}
#endif

// FUNCTION: GAME 0x2D6870
void CustomIDWork::ResetMoveOffsetPos()
{
    if (m_work) {
        m_unk28 = 0;
        m_work->m_offsetX = 0;
        m_work->m_offsetY = 0;
    }
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

// FUNCTION: GAME 0x2D6968
void CustomIDWork::SetScaleAnimNormal(float a, float b, unsigned short t)
{
    if (m_work) {
        m_unk64 = a;
        m_unk5C = 3;
        m_unk68 = b;
        m_unk6C = a;
        m_unk70 = b;
        m_unk74 = t;
        if (t == 0)
            m_unk74 = 1;
        m_unk76 = 0;
    }
}

// FUNCTION: GAME 0x2D6A30
void CustomIDWork::ResetScaleAnim()
{
    if (m_work) {
        m_unk5C = 0;
        m_work->m_scaleX = m_unk60;
        m_work->m_scaleY = m_unk60;
    }
}
