#ifndef COL29_H
#define COL29_H

#include "game/cObj.h"

class cOl29 : public cObj {
public:
    void setOpen();
    void setClose();
    unsigned char isOpen();
    void setOpenFix();
    void setCloseFix();

    char _pad2F8[0x764 - 0x2F8];
    unsigned char m_open;
};

#endif
