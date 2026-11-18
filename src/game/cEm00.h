#ifndef CEM00_H
#define CEM00_H

#include "game/cVec.h"

class cEm00 {
public:
    int ckDown();
    int CkDevilEvent();
    void setAlphaMode(bool b);
    void setNoLost();
    void setR302Switch();
    void setDevilEventFlag();
    bool ckBananaDance();
    void setR608EventEnd();
    void setEm65Separate();
    void setNeckMoveOff();
    void setNeckMoveOn();
    void setSitChair(const cVec &pos, float rot);

    char _pad0[0xF0];
    cVec *m_pos;
    char _pad0F4[0x104 - 0xF4];
    float m_rotY;
    char _pad108[0x2F0 - 0x108];
    unsigned int m_unk2F0;
    unsigned char m_act0;
    unsigned char m_act1;
    unsigned char m_act2;
    unsigned char m_act3;
    char _pad2F8[0x3AC - 0x2F8];
    unsigned short m_unk3AC;
    char _pad3AE[0x490 - 0x3AE];
    cVec m_sitPos;
    char _pad49C[0x54C - 0x49C];
    float m_unk54C;
    char _pad550[0x564 - 0x550];
    int m_id;
    char _pad568[0x1644 - 0x568];
    unsigned int m_unk1644;
    char _pad1648[0x1650 - 0x1648];
    unsigned char m_unk1650;
    char _pad1651[0x16D0 - 0x1651];
    unsigned int m_flagsA;
    unsigned int m_flagsB;
    char _pad16D8[0x16EC - 0x16D8];
    int m_unk16EC;
    char _pad16F0[0x1868 - 0x16F0];
    unsigned char m_alphaMode;
};

#endif
