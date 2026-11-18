#ifndef COM60_H
#define COM60_H

#include "game/cOmBase.h"

class cOm60 : public cOmBase {
public:
    int ckParent();

    char _pad5B8[0x600 - 0x5B8];
    void *m_parent;
};

#endif
