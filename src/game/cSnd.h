#ifndef CSND_H
#define CSND_H

enum eBgmState { eBgmState_0 };
enum eBgmReqNo { eBgmReqNo_0 };

struct sSeData {
    char _pad[0x40];
};

struct sBgmData {
    char _pad[0x44];
};

class cSnd {
public:
    sSeData *GetSeData(int i);
    void SetBgmState(eBgmState s);
    void SetBgmLevel(int a, eBgmReqNo b, int c, float f);
    sBgmData *GetBgmData(int i);

    char _pad0[0x3C];
    sSeData *m_seData;
    sBgmData *m_bgmData;
    char _pad44[0x118 - 0x44];
    int m_bgmLvA;
    int m_bgmLvB;
    int m_bgmLvC;
    float m_bgmLvF;
    char _pad128[0x13C - 0x128];
    int m_bgmState;
};

#endif
