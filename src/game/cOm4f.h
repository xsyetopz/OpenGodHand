#ifndef COM4F_H
#define COM4F_H

#include "game/cOmBase.h"

class cOm5f;

class cOm4f : public cOmBase {
public:
    unsigned char isOpen();
    unsigned char isActive();
    void setEventMode(bool on);
    void setLock(bool on);
    void setOpen();
    void setClose();
    void connectDoor(cOm5f *door);

    char _pad5B8[0x760 - 0x5B8];
    unsigned char m_active;
    unsigned char m_open;
    unsigned char m_lock;
    unsigned char m_eventMode;
    char _pad764[0x790 - 0x764];
    cOm5f *m_door;
};

#endif
