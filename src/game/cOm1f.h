#ifndef COM1F_H
#define COM1F_H

#include "game/cOmBase.h"

class cOm1f : public cOmBase {
public:
    void setMoveRange(float a, float b, float c, float d);

    char _pad5B8[0xAF8 - 0x5B8];
    float m_rangeA;
    float m_rangeB;
    float m_rangeC;
    float m_rangeD;
};

#endif
