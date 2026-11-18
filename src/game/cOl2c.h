#ifndef COL2C_H
#define COL2C_H

#include "game/cObj.h"

class cOl2c : public cObj {
public:
    unsigned char isFireStart();
    unsigned char isFire();

    char _pad2F8[0x770 - 0x2F8];
    unsigned char m_fireStart;
    unsigned char m_fire;
};

#endif
