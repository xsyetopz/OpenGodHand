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

// FUNCTION: GAME 0x2D5D80
CustomIDWork::~CustomIDWork()
{
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

// FUNCTION: GAME 0x2D6490
void CustomIDWork::SetDisp(bool b)
{
    cIDWork *w = m_work;
    if (w) {
        int d = b ^ 1;
        if (d != 0)
            w->m_flags |= 0x20000000;
        else
            w->m_flags &= ~0x20000000;
    }
}

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

// FUNCTION: GAME 0x2D6630
void CustomIDWork::SetLocalPosX(int x)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posX = (float)x;
    }
}

// FUNCTION: GAME 0x2D6658
void CustomIDWork::SetLocalPosY(int y)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posY = (float)y;
    }
}

// FUNCTION: GAME 0x2D6680
void CustomIDWork::SetLocalPosXY(int x, int y)
{
    if (m_work) {
        m_unk8 = 0;
        m_work->m_posX = (float)x;
        m_work->m_posY = (float)y;
    }
}

// FUNCTION: GAME 0x2D66D0
void CustomIDWork::SetOffsetPosX(int x)
{
    if (m_work) {
        m_unk28 = 0;
        m_work->m_offsetX = (float)x;
    }
}

// FUNCTION: GAME 0x2D6720
void CustomIDWork::SetOffsetPosXY(int x, int y)
{
    if (m_work) {
        m_unk28 = 0;
        m_work->m_offsetX = (float)x;
        m_work->m_offsetY = (float)y;
    }
}

// FUNCTION: GAME 0x2D6768
void CustomIDWork::SetMoveOffsetPosX(int a, int b, unsigned short t)
{
    if (m_work) {
        m_unk2C = (float)a;
        m_unk28 = 3;
        m_unk34 = (float)b;
        m_unk44 = t;
        m_unk46 = 0;
    }
}

// FUNCTION: GAME 0x2D67B0
void CustomIDWork::SetMoveOffsetPosXSin(int a, unsigned short t)
{
    if (m_work) {
        m_unk28 = 5;
        m_unk3C = (float)a;
        m_unk44 = t;
        m_unk46 = 0;
    }
}

// FUNCTION: GAME 0x2D67F0
void CustomIDWork::SetMoveOffsetPosY(int a, int b, unsigned short t)
{
    if (m_work) {
        m_unk28 = 9;
        m_unk30 = (float)a;
        m_unk38 = (float)b;
        m_unk44 = t;
        m_unk46 = 0;
    }
}

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

// FUNCTION: GAME 0x2D6898
void CustomIDWork::SetColorAnimNormal(COL c, unsigned short t)
{
    if (m_work) {
        m_unk48 = 3;
        m_unk50 = m_work->m_unk4C;
        m_unk54 = c.c;
        m_unk58 = t;
        if (t == 0)
            m_unk58 = 1;
        m_unk5A = 0;
    }
}

// FUNCTION: GAME 0x2D68D8
void CustomIDWork::SetColorAnimNormal(COL a, COL b, unsigned short t)
{
    if (m_work) {
        m_unk50 = a.c;
        m_unk48 = 3;
        m_unk54 = b.c;
        m_unk58 = t;
        if (t == 0)
            m_unk58 = 1;
        m_unk5A = 0;
    }
}

// FUNCTION: GAME 0x2D6910
void CustomIDWork::SetColorAnimSin(COL a, COL b, unsigned short t)
{
    if (m_work) {
        m_unk50 = a.c;
        m_unk48 = 5;
        m_unk54 = b.c;
        m_unk58 = t;
        if (t == 0)
            m_unk58 = 1;
        m_unk5A = 0;
    }
}
