#ifndef COL40_H
#define COL40_H

#include "game/cObj.h"

class cOl40 : public cObj {
public:
    unsigned char isDead();
    void setVitalMax(int v);

    char _pad2F8[0x61E - 0x2F8];
    short m_vitA[4];
    char _pad626[0x62C - 0x626];
    short m_vitB[4];
    char _pad634[0x65B - 0x634];
    unsigned char m_dead;
};

#endif
