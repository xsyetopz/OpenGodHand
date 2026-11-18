#ifndef CEMSETPARAM_H
#define CEMSETPARAM_H

#include "game/cObj.h"

class cEmSetParam {
public:
    void roomInit();
    void setEmAll();
    void rewriteDataSet(void *p);
    void setEmData(void *p);
    void updateSetDataAppPattern(unsigned int idx, unsigned char pat);
    void updateSetDataFlag(unsigned int idx, unsigned int flag);
    void updateSetDataRot(unsigned int idx, float rot);
    void updateSetDataPos(unsigned int idx, const cVec &pos);
    int setEm(unsigned char idx);
    cVec16 getSetDataPos(unsigned int idx);
    void stopEmSet1Time();

    unsigned char m_stop1Time;
    char _pad1[7];
    int m_unk08;
    int m_unk0C;
};

#endif
