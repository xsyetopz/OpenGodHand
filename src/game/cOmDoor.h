#ifndef COMDOOR_H
#define COMDOOR_H

#include "game/cOmBase.h"

class cOmDoor : public cOmBase {
public:
    void setLock(bool on);

    char _pad5B8[0x620 - 0x5B8];
    int m_doorFlags;
};

#endif
