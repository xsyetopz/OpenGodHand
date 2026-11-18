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
    void setSuspend(bool suspend);
    bool isClip() const;
    void SetTgtTurn(const cVec &tgt, float speed);

    char _pad0[0xF0];
    cVec *m_pPos;
    char _padF4[0xC];
    cVec m_rot;
    char _pad10C[0x214 - 0x10C];
    cGameObjVTable *m_vt;
    char _pad218[0x250 - 0x218];
    unsigned int m_flags250;
    char _pad254[0x490 - 0x254];
    cVec m_pos;
    char _pad49C[0x5A0 - 0x49C];
    union {
        int m_flags5A0;
        struct {
            unsigned long long m_f0 : 1;
            unsigned long long m_f1 : 1;
        };
    };
};

extern float D_007479FC;
float Turn_dest(const float *, float, const float *, float);
float Adjust_theta(float);

#endif
