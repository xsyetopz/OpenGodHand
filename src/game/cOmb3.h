#ifndef COMB3_H
#define COMB3_H

#include "game/cOmBase.h"
#include "game/cVec.h"

class cOmb3 : public cOmBase {
public:
    void SetPointTbl(cVec *tbl, unsigned short n);
    void SetNextPoint(unsigned short n);

    char _pad5B8[0x604 - 0x5B8];
    cVec *m_pointTbl;
    unsigned short m_pointNum;
    unsigned short m_nextPoint;
};

#endif
