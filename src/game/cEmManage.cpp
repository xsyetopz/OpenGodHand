#include "game/cEmManage.h"

class cObj {
public:
    char _pad0[0x2FE];
    unsigned short m_type;
};
struct cObjArray {
    char _pad0[4];
    cObj **m_begin;
    cObj **m_end;
};
void ReleaseObj(cObj *);
extern cObjArray *objbaseArray;

extern float D_00741DC0;
extern float D_00754C48;
extern const float D_00747A14;

// FUNCTION: GAME 0x291FC0
int cEmManage::DarkWorldCk()
{
    return m_darkWorld != 0;
}

// FUNCTION: GAME 0x292030
void cEmManage::SetSlotWait(int n)
{
    if (m_slotWait < n) {
        m_slotWait = n;
    }
}

// FUNCTION: GAME 0x292EF0
void cEmManage::SetBigHitEffWait(int n)
{
    if (m_bigHitEffWait < n) {
        m_bigHitEffWait = n;
    }
}

// FUNCTION: GAME 0x292F38
void cEmManage::SetSpeedRate(float r)
{
    m_speedRate = r;
    D_00741DC0 = r;
    D_00754C48 = r;
}

// FUNCTION: GAME 0x292F50
float cEmManage::GetSpeedRate()
{
    return m_speedRate * D_00747A14;
}

// FUNCTION: GAME 0x2930D0
void cEmManage::SetPlBombHit()
{
    m_plBombHit = 60;
}

// FUNCTION: GAME 0x2930F0
void cEmManage::SetPlCatched()
{
    m_plCatched = 2;
}

// FUNCTION: GAME 0x293100
int cEmManage::CkPlCatched()
{
    return m_plCatched != 0;
}

// FUNCTION: GAME 0x293110
void cEmManage::SetPlSorry()
{
    m_plSorry = 2;
}

// FUNCTION: GAME 0x290868
cEmBase *cEmManage::GetEm(unsigned char id)
{
    if (id == 0xFF) {
        return 0;
    }
    for (cEmNode *n = m_list; n; n = n->m_next) {
        if (n->m_em->m_id == id) {
            return n->m_em;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2909B8
int cEmManage::ChkActiveEm(cEmBase *em)
{
    if (!em) {
        return 0;
    }
    for (cEmNode *n = m_list; n; n = n->m_next) {
        if (n->m_em == em && n->m_state == 1) {
            return 1;
        }
    }
    return 0;
}

#ifdef NONMATCHING
// 0x2908C0: 4 words differ: original has a real nop between the jal delay-slot lw and the bnel; ours emits none
void cEmManage::ReleaseEmAll()
{
    for (cEmNode *n = m_list; n;) {
        cEmBase *em = n->m_em;
        n = n->m_next;
        ReleaseEm(em);
    }
    for (cObj **p = objbaseArray->m_begin; p != objbaseArray->m_end; p++) {
        if ((*p)->m_type == 0x364) {
            ReleaseObj(*p);
        }
    }
}
#endif
