#ifndef COL2B_H
#define COL2B_H

#include "game/cObj.h"

class cOl2b : public cObj {
public:
    void setOpen();
    void setClose();
    void setInit();
    int getState();
    unsigned char isActive();

    char _pad2F8[0xA24 - 0x2F8];
    int m_state;
    unsigned char m_active;
    unsigned char m_fire;
};

#endif
