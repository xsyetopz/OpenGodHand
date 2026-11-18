#ifndef COBJSIMPLE_H
#define COBJSIMPLE_H

#include "game/cObj.h"

class cObjSimple : public cObj {
public:
    void R0_Init();
    void SetRingFlag(bool b);
    void SetBustFlag(bool b);
    void SetPackIndex(int i);

    char _pad2F8[0x4D0 - 0x2F8];
    unsigned char m_packSet;
    char _pad4D1[3];
    int m_packIndex;
    char _pad4D8[0x2FA0 - 0x4D8];
    unsigned char m_bustFlag;
    char _pad2FA1[0x2FF0 - 0x2FA1];
    unsigned char m_ringFlag;
};

#endif
