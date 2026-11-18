#ifndef COL26_H
#define COL26_H

#include "game/cObj.h"

class cOl26 : public cObj {
public:
    void setOpen();
    unsigned char isOpen();

    char _pad2F8[0x600 - 0x2F8];
    unsigned char m_open;
};

#endif
