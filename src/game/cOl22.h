#ifndef COL22_H
#define COL22_H

#include "game/cObj.h"

class cOl22 : public cObj {
public:
    void setOpen();
    unsigned char isOpen();

    char _pad2F8[0x600 - 0x2F8];
    unsigned char m_active;
    unsigned char m_open;
};

#endif
