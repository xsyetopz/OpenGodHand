#ifndef CEMA2_H
#define CEMA2_H

#include "game/cObj.h"

class cEma2 : public cObj {
public:
    int ckKiss();
    void SetPoison();
    void SetPoisonDie();

    char _pad2F8[0x15B1 - 0x2F8];
    unsigned char m_unk15B1;
};

#endif
