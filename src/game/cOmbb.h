#ifndef COMBB_H
#define COMBB_H

#include "game/cOmBase.h"

class cOmbb : public cOmBase {
public:
    unsigned char ckBomb();

    char _pad5B8[0x601 - 0x5B8];
    unsigned char m_bomb;
};

#endif
