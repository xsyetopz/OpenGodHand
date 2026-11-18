#ifndef COM4F_H
#define COM4F_H

#include "game/cOmBase.h"

class cOm4f : public cOmBase {
public:
    unsigned char isOpen();
    unsigned char isActive();
    void setEventMode(bool on);
    void setLock(bool on);

    char _pad5B8[0x760 - 0x5B8];
    unsigned char m_active;
    unsigned char m_open;
    unsigned char m_lock;
    unsigned char m_eventMode;
};

#endif
