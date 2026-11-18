#ifndef COM5A_H
#define COM5A_H

#include "game/cOmBase.h"

class cOm5a : public cOmBase {
public:
    unsigned char isOpen();
    unsigned char isActive();
    void setFaceOpen();

    char _pad5B8[0x604 - 0x5B8];
    int m_unk604;
    int m_unk608;
    char _pad60C[0x60D - 0x60C];
    unsigned char m_open;
    unsigned char m_active;
};

#endif
