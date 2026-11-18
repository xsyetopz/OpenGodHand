#ifndef COM53_H
#define COM53_H

#include "game/cOmBase.h"

class cOm53 : public cOmBase {
public:
    void setRiseWaitTime(unsigned int t);
    void setDownPos(float y);
    int setGetOffEm(unsigned int n);

    char _pad5B8[0x612 - 0x5B8];
    unsigned char m_unk612;
    char _pad613[0x615 - 0x613];
    unsigned char m_unk615;
    char _pad616[0x620 - 0x616];
    float m_downPos;
    char _pad624[0x628 - 0x624];
    unsigned int m_riseWaitTime;
};

#endif
