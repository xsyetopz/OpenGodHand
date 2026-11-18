#ifndef COL1B_H
#define COL1B_H

#include "game/cObj.h"

class cOl1b : public cObj {
public:
    void setClose();
    unsigned char isActive();

    char _pad2F8[0x600 - 0x2F8];
    unsigned char m_active;
    unsigned char m_open;
};

#endif
