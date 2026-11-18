#ifndef COL21_H
#define COL21_H

#include "game/cObj.h"

struct cOl21Col {
    char _pad0[8];
    int m_flags;
};

class cOl21 : public cObj {
public:
    void setCollisionActive(bool b, float f);

    char _pad2F8[0x608 - 0x2F8];
    float m_unk608;
    char _pad60C[0x654 - 0x60C];
    cOl21Col *m_col[8];
};

#endif
