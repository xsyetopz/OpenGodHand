#ifndef CEMWRAP_H
#define CEMWRAP_H

#include "game/cVec.h"
#include "game/cEmBase.h"
#include "game/cEmManage.h"

enum eObjId { EOBJID_DUMMY };
enum EM00_GOTO_TYPE { EM00_GOTO_DUMMY };

class cEmWrap {
public:
    int release();
    void setPos(const cVec &p);
    void setPos(const cVec &p, float f);
    void setLockOff(bool b);
    void StartAction();
    void setScrCollEnable(bool b);
    int CkActive();
    void setSuspend(bool b);
    void setGoto(const cVec &p, EM00_GOTO_TYPE t, unsigned u, float f);
    int ckGoto();
    void SetKeepPos(const cVec &p);
    void SetKeepLength(float f);
    void clearNoMove();
    void StartEscape();
    void SetEscPos(const cVec &p);
    void setAlphaMode(bool b);

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
