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

// FUNCTION: GAME 0x2D2D98
sBgmData *cSnd::GetBgmData(int i)
{
    return m_bgmData + i;
}

// FUNCTION: GAME 0x2CBCF0
int cSnd::SeEndCk(eSndId id)
{
    return func_002CBF48(this, id) == 0;
}

// FUNCTION: GAME 0x2D0630
void cSnd::SetBgmTblNo(unsigned a, int b)
{
    func_002D0658(this, a, b, 0.0f);
}

// FUNCTION: GAME 0x2D0780
void cSnd::SetBgmDefAttr(unsigned a, float f)
{
    *(unsigned *)((char *)this + 0x58) = a;
    func_002D0728(this, a, f);
}

// FUNCTION: GAME 0x2CBC20
int cSnd::SeFadeOut(eSndId id, short t)
{
    if (id == 0)
        return -1;
    return func_00375050(id, t);
}

// FUNCTION: GAME 0x2CBBA0
void cSnd::SeStop(eSndId id)
{
    if (id) {
        func_00375050(id, 5);
        for (unsigned i = 0; i < 8; i++) {
            if (m_seSlot[i] == 0) {
                m_seSlot[i] = id;
                break;
            }
        }
    }
}

// FUNCTION: GAME 0x2D1498
void cSnd::BattleBgmAllPause(float f)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (n->m_state != 2)
            func_002CD500(n, 0x100000, f);
    }
}

// FUNCTION: GAME 0x2D15A8
void cSnd::BgmEventSet(eBgmReqNo r, int a, int b)
{
    void *p = func_002D2228(this);
    if (p)
        func_002CC9C0(p, 0, r, 5, 0xFFFFFFFFu, a, b);
}

// FUNCTION: GAME 0x2D1900
void cSnd::BgmEvDataInit(unsigned a)
{
    func_002CFF90(GetBgmData(1));
    func_002D0128(GetBgmData(1), 1, a);
}

// FUNCTION: GAME 0x2D2088
void cSnd::BgmEvAllSuspend(float f)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        n->m_flags |= 0x800;
        func_002CD4A8(n, f);
    }
}
