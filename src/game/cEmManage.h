#ifndef CEMMANAGE_H
#define CEMMANAGE_H

// Full cEmManage layout. Do not include together with cEmWrap.h, which holds a
// minimal cEmManage declaration.
class cEmBase;

struct cEmNode {
    char _pad0[4];
    cEmNode *m_next;
    cEmBase *m_em;
    char _pad0C[4];
    unsigned char m_state;
};

class cEmManage {
public:
    cEmBase *GetEm(unsigned char id);
    int ChkActiveEm(cEmBase *em);
    int DarkWorldCk();
    void SetSlotWait(int n);
    void SetBigHitEffWait(int n);
    void SetSpeedRate(float r);
    float GetSpeedRate();
    void SetPlBombHit();
    void SetPlCatched();
    int CkPlCatched();
    void SetPlSorry();

    char _pad0[0x500];
    cEmNode *m_list;
    char _pad504[0x514 - 0x504];
    int m_slotWait;
    unsigned char m_darkWorld;
    char _pad519[0x538 - 0x519];
    signed char m_bigHitEffWait;
    char _pad539[2];
    signed char m_plBombHit;
    signed char m_plCatched;
    signed char m_plSorry;
    char _pad53E[0x548 - 0x53E];
    float m_speedRate;
};

#endif
