#ifndef CGAMEOBJ_H
#define CGAMEOBJ_H

#include "game/cVec.h"

struct cGameObjVTable {
    char _pad0[0x80];
    short m_delta;
    short m_index;
    cVec *(*m_fn)(void *);
};

class cGameObj {
public:
    void setPos(const cVec &pos);
    void setRot(const cVec &rot);
    cVec *getPos();
    cVec *getRot();
    cVec *getHitCheckPos();
    cVec *getLockOnPos();

    char _pad0[0xF0];
    cVec *m_pPos;
    char _padF4[0xC];
    cVec m_rot;
    char _pad10C[0x214 - 0x10C];
    cGameObjVTable *m_vt;
    char _pad218[0x490 - 0x218];
    cVec m_pos;
};

#endif
