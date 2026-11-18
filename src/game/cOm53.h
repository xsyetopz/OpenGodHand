#ifndef COM53_H
#define COM53_H

#include "game/cOmBase.h"

class cOm53 : public cOmBase {
public:
    void setRiseWaitTime(unsigned int t);
    void setDownPos(float y);

    char _pad5B8[0x620 - 0x5B8];
    float m_downPos;
    char _pad624[0x628 - 0x624];
    unsigned int m_riseWaitTime;
};

#endif
