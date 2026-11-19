#include "game/cSnd.h"

// FUNCTION: GAME 0x2CC4B8
cSeData *cSnd::GetSeData(int i)
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
cBgmData *cSnd::GetBgmData(int i)
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

// FUNCTION: GAME 0x2D1958
void cSnd::BgmEvDataEnd()
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (n->m_kind - 0x80 == 1)
            func_002CD4A8(n, 10.0f);
    }
    func_002CFF90(GetBgmData(1));
}

// FUNCTION: GAME 0x2D19D8
int cSnd::BgmEvDataCheck()
{
    if (func_002CFF78(GetBgmData(1)) == 1)
        return 1;
    return func_002CFF68(GetBgmData(1));
}

// FUNCTION: GAME 0x2D1C78
int cSnd::BgmEvSet(eBgmPt a, eBgmReqNo b)
{
    void *p = func_002D22B0(this, a, b);
    if (p)
        func_002CCB10(p);
    p = func_002D2228(this);
    return p ? func_002CC9C0(p, a, b, 4, 0xFFFFFFFFu, 0, 0) != 0 : 0;
}

// FUNCTION: GAME 0x2D1E48
void cSnd::BgmEvPause(eBgmPt a, eBgmReqNo b)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (b == -1 || (n->m_kind - 0x80 == a && n->m_a == b)) {
            if (n->m_b == 4)
                func_00373488(n);
        }
    }
}

// FUNCTION: GAME 0x2D2178
void cSnd::BgmFadeOutAll(float f, eBgmPt a, eBgmReqNo b)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (n->m_kind - 0x80 == a && n->m_a != b) {
            if (func_00373A58(n) == 1)
                func_002CD4A8(n, 3.0f);
            else
                func_002CD4A8(n, f);
        }
    }
}

// FUNCTION: GAME 0x2D1768
void cSnd::BgmEventFade(eBgmReqNo r, float a, float b, float c)
{
    void *p = func_002D22B0(this, 0, r);
    if (p) {
        if (0.0f <= c) {
            func_00373560(p, -1, func_00373938(p, 0) * c);
        }
        func_002CD4E0(p, b, a);
    }
}

// FUNCTION: GAME 0x2CA718
void cSnd::DieDemoStart()
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        n->m_flags |= 0x10000;
        func_002CD4A8(n, 180.0f);
    }
    m_flagsB0 |= 0x100000;
    m_flagsAC |= 0x100000;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2CB418 - 23 words differ (same size): saved regs (orig s0=id,s1=this,s2=i,s3=want,s4=1) and movn vs movz; tried want=id+if/int c=t>0 (merges, 45), ?: form (best), i declared first/last
int cSnd::EmSeCheck(eObjId id)
{
    int t = func_002CB3A8(this, id);
    int want = (t > 0) ? t : (int)id;
    unsigned i = 0;
    for (; i < 12; i++) {
        if (GetSeData(D_0044CE48[i])->IsAlive()
            && GetSeData(D_0044CE48[i])->m_unk3C == want
            && func_002CFC88(GetSeData(D_0044CE48[i])) != 1)
            return D_0044CE48[i];
    }
    return -1;
}
#endif

// FUNCTION: GAME 0x2D1D00
int cSnd::BgmEvStart(eBgmPt a, eBgmReqNo b, int c)
{
    sBgmNode *p = (sBgmNode *)func_002D22B0(this, a, b);
    if (p) {
        if (p->m_flags & 1)
            func_002CCAC8(p);
        return 1;
    }
    p = (sBgmNode *)func_002D2228(this);
    if (p && func_002CC900(p, a, b, 4, 0xFFFFFFFFu, 0, 0)) {
        func_00373A18(p, c);
        return 1;
    }
    return 0;
}
