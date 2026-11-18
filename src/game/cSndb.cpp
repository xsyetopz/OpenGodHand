#include "game/cSnd.h"

// FUNCTION: GAME 0x2D1610
void cSnd::BgmEventStart(eBgmReqNo r, int a, int b)
{
    sBgmNode *p = (sBgmNode *)func_002D22B0(this, 0, r);
    if (p && (p->m_flags & 1)) {
        func_002CCAC8(p);
    } else {
        p = (sBgmNode *)func_002D2228(this);
        if (!p) {
            BgmEventStop(false);
            return;
        }
        func_002CC900(p, 0, r, 5, 0xFFFFFFFFu, a, b);
    }
    m_flagsB0 |= 0x10000000;
    m_flagsAC |= 0x10000000;
    if (p->m_unk5E == 0) {
        for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
            if (!(n->m_flags & 0x180000)) {
                unsigned t = n->m_flags & 1;
                if (n != p && t != 1) {
                    n->m_flags |= 0x1000;
                    if (n->m_state != 2)
                        func_002CD4A8(n, 10.0f);
                }
            }
        }
    }
}

// FUNCTION: GAME 0x2CB8A0
int cSnd::SeCall(eSeBlk b, short s1, short s2, short s3, unsigned u, int i)
{
    if (!GetSeData(b)->IsAlive())
        return 0;
    void *p = func_002CBEC0(this);
    if (!p)
        return 0;
    return func_002CDF18(p, b, s1, s2, s3, u, i);
}

// FUNCTION: GAME 0x2CB968
int cSnd::SeCall(eSeBlk b, short s, float *f, unsigned u, int i)
{
    if (!GetSeData(b)->IsAlive())
        return 0;
    void *p = func_002CBEC0(this);
    if (!p)
        return 0;
    if (!f)
        return func_002CDF18(p, b, s, u, i, 0, 0);
    return func_002CDE28(p, b, s, f, u, i);
}

// FUNCTION: GAME 0x2D1800
void cSnd::BgmEventStop(bool b)
{
    m_flagsB0 &= 0xEFFFFFFF;
    m_flagsAC &= 0xEFFFFFFF;
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (n->m_b == 5) {
            if (b != 1)
                func_002CD4A8(n, 0.0f);
        } else if (n->m_flags & 0x1000) {
            n->m_flags &= ~0x1000;
            if (!(n->m_flags & 0x1FF00)) {
                if (n->m_state != 2)
                    func_002CD470(n, 15.0f);
            }
        }
    }
}

// FUNCTION: GAME 0x2D1A30
void cSnd::BgmEvCutSet(int x)
{
    if (func_002CFF68(GetBgmData(1))) {
        sBgmHead *head = GetBgmData(1)->GetHeadPtr();
        for (unsigned i = 0; i < head->m_count; i++) {
            sBgmTbl *t = GetBgmData(1)->GetTblPtr(i);
            if (t && t->m_unkB != 0x80) {
                if (t->m_unk11 == x) {
                    BgmEvStart((eBgmPt)1, (eBgmReqNo)i, 0);
                } else if (t->m_unk12 == 0) {
                    if (t->m_unk11 == x + 1)
                        BgmEvSet((eBgmPt)1, (eBgmReqNo)i);
                } else if (t->m_unk12 == x) {
                    BgmEvSet((eBgmPt)1, (eBgmReqNo)i);
                }
            }
        }
    }
}

// FUNCTION: GAME 0x2D1B70
int cSnd::BgmEvCutCheck(int x)
{
    if (!func_002CFF68(GetBgmData(1)))
        return 1;
    sBgmHead *head = GetBgmData(1)->GetHeadPtr();
    for (unsigned i = 0; i < head->m_count; i++) {
        sBgmTbl *t = GetBgmData(1)->GetTblPtr(i);
        if (t && t->m_unkB != 0x80 && t->m_unk11 == x) {
            if (func_002D1DD0(this, 1, i) != 1)
                return 0;
        }
    }
    return 1;
}

// FUNCTION: GAME 0x2D1EE8
void cSnd::BgmEvReStart(eBgmPt a, eBgmReqNo b, int c)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (b == -1 || (n->m_kind - 0x80 == a && n->m_a == b)) {
            if (n->m_b == 4) {
                func_002CCAC8(n);
                if (c >= 0)
                    func_00373A18(n, c);
            }
        }
    }
}

// FUNCTION: GAME 0x2D1FA0
void cSnd::BgmEvFadeSet(eBgmPt a, eBgmReqNo b, float x, float y, float z)
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
        if (b == -1 || (n->m_kind - 0x80 == a && n->m_a == b)) {
            if (0.0f <= z)
                func_00373560(n, -1, func_00373938(n, 0) * z);
            func_002CD4E0(n, x, y);
        }
    }
}

// FUNCTION: GAME 0x2D2C18
void cSnd::BgmHitBeSet(bool b, unsigned short id)
{
    if (m_hitBe) {
        if (strcmp((char *)m_hitBe, D_0044D100) == 0 && m_hitBe->m_ver == 1.3f && m_hitBe->m_count) {
            sHitEntry *e = (sHitEntry *)((char *)m_hitBe + 0x10);
            for (unsigned i = 0; i < m_hitBe->m_count; i++, e++) {
                if (e->m_id == id) {
                    if (b == 1)
                        e->m_flag |= 1;
                    else
                        e->m_flag &= 0xFE;
                }
            }
        }
    }
}

// FUNCTION: GAME 0x2D0938
void cSnd::BgmControl()
{
    for (sBgmNode *n = m_bgmList; n; n = n->m_next)
        func_002CC628(n);
    if (m_flagsAC & 0x10000000) {
        int found = 0;
        for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
            if (n->m_b == 5) {
                found = 1;
                break;
            }
        }
        if (!found)
            BgmEventStop(false);
    }
    unsigned ga = D_00747A84 & 0x20000000;
    unsigned gb;
    if (ga || (gb = D_00747A84 & 0x80000, gb)) {
        for (sBgmNode *n = m_bgmList; n; n = n->m_next) {
            if (n->m_state != 2 && n->m_unk60 && !func_00373A78(n))
                func_002CD4A8(n, 30.0f);
        }
        m_unk128 = -2;
        m_unk138 = 3;
    }
    if (m_flagsAC & 0x200000) {
        if (!(m_flagsAC & 0x100000)) {
            unsigned d = D_00747A84;
            unsigned a = d & 0x20000000;
            if (!a) {
                unsigned b = d & 0x80000;
                if (!b)
                    func_002D0EA0(this);
            }
        }
    }
}
