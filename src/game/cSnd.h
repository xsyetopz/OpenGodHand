#ifndef CSND_H
#define CSND_H

class cSnd;

enum eBgmState { eBgmState_0 };
enum eBgmReqNo { eBgmReqNo_0 };

struct sSeData {
    char _pad[0x40];
};

struct sBgmData {
    char _pad[0x44];
};

struct sBgmNode {
    char _pad0[0x88];
    sBgmNode *m_next;
    char _pad8C[0x98 - 0x8C];
    unsigned m_flags;
    char _pad9C[0xB0 - 0x9C];
    int m_state;
};

enum eSndId { eSndId_0 };

extern "C" {
void *func_002CBF48(cSnd *, eSndId);
int func_00375050(eSndId, int);
void func_002D0658(cSnd *, unsigned, int, float);
void func_002D0728(cSnd *, unsigned, float);
void func_002CD500(sBgmNode *, int, float);
void func_002CD4A8(sBgmNode *, float);
void *func_002D2228(cSnd *);
void func_002CC9C0(void *, int, int, int, unsigned, int, int);
void func_002CFF90(sBgmData *);
void func_002D0128(sBgmData *, int, unsigned);
}

class cSnd {
public:
    sSeData *GetSeData(int i);
    void SetBgmState(eBgmState s);
    void SetBgmLevel(int a, eBgmReqNo b, int c, float f);
    sBgmData *GetBgmData(int i);

    int SeEndCk(eSndId id);
    void SetBgmTblNo(unsigned a, int b);
    void SetBgmDefAttr(unsigned a, float f);
    int SeFadeOut(eSndId id, short t);
    void SeStop(eSndId id);
    void BattleBgmAllPause(float f);
    void BgmEventSet(eBgmReqNo r, int a, int b);
    void BgmEvDataInit(unsigned a);
    void BgmEvAllSuspend(float f);

    char _pad0[0x18];
    sBgmNode *m_bgmList;
    char _pad1C[0x3C - 0x1C];
    sSeData *m_seData;
    sBgmData *m_bgmData;
    char _pad44[0x118 - 0x44];
    int m_bgmLvA;
    int m_bgmLvB;
    int m_bgmLvC;
    float m_bgmLvF;
    char _pad128[0x13C - 0x128];
    int m_bgmState;
    eSndId m_seSlot[8];
};

#endif
