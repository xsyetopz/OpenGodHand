#ifndef CEMWRAP_H
#define CEMWRAP_H

#include "game/cVec.h"

enum eObjId { EOBJID_DUMMY };

class cEmBase {
public:
    int checkDeadFlag();

    char _pad0[0xF0];
    cVec *m_pos;
    char _pad0F4[0x100 - 0xF4];
    cVec m_rot;
    char _pad10C[0x531 - 0x10C];
    signed char m_raderType;
    char _pad532[0x548 - 0x532];
    short m_vitalMax;
    short m_vital;
    float m_mutekiTimer;
    char _pad550[0x560 - 0x550];
    int m_dropItem;
};

class cEmWrap {
public:
    const cVec *getPos();
    const cVec *getRot();
    void setMutekiTimer(float t);
    void setDead();
    int isDead();
    void SetVital(int v);
    void SetVitalMax(int v);
    int GetVital();
    int GetVitalMax();
    void setDropItem(eObjId id);
    void SetRaderType(signed char t);

    unsigned char m_id;
    char _pad1[3];
    cEmBase *m_em;
};

#endif
