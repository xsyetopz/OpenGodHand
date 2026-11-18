#ifndef CEMWRAP_H
#define CEMWRAP_H

#include "game/cVec.h"

enum eObjId { EOBJID_DUMMY };

struct cVEnt {
    short delta;
    short _pad;
    void (*fn)(void *, const void *);
};

class cEmBase {
public:
    int checkDeadFlag();
    void vcall(int off, const void *arg)
    {
        cVEnt *e = (cVEnt *)((char *)m_vt + off);
        e->fn((char *)this + e->delta, arg);
    }
    void vcall0(int off)
    {
        cVEnt *e = (cVEnt *)((char *)m_vt + off);
        ((void (*)(void *))e->fn)((char *)this + e->delta);
    }

    char _pad0[0xF0];
    cVec *m_pos;
    char _pad0F4[0x100 - 0xF4];
    cVec m_rot;
    char _pad10C[0x214 - 0x10C];
    cVEnt *m_vt;
    char _pad218[0x4AC - 0x218];
    const char *m_name;
    char _pad4B0[0x531 - 0x4B0];
    signed char m_raderType;
    char _pad532[0x548 - 0x532];
    short m_vitalMax;
    short m_vital;
    float m_mutekiTimer;
    char _pad550[0x560 - 0x550];
    int m_dropItem;
    char _pad564[0x5A0 - 0x564];
    int m_flags;
};

class cEmManage {
public:
    int ReleaseEm(cEmBase *em);
};

class cEmWrap {
public:
    int release();
    void setPos(const cVec &p);
    void setPos(const cVec &p, float f);
    void setLockOff(bool b);
    void StartAction();
    void setScrCollEnable(bool b);
    int CkActive();

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
