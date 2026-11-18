#ifndef CSCEATMANAGER_H
#define CSCEATMANAGER_H

#include "game/cSceAtUnit.h"
#include "game/cVec.h"

class cSceAtManager {
public:
    void SetDoorFunc(cSceAtUnit *unit, void *a, void *b);
    void AtDataReset(cSceAtUnit *unit);
    void AtDataReset(unsigned short id);
    void AtExecute(cSceAtUnit *unit);
    void AtExecute(unsigned short id);
    cSceAtUnit *getUnit(unsigned int id);
    void AtDataSet_exec(cSceAtUnit *unit, int a, void *b, void *c, eAreaTrgType trg);
    void AtDataSet_exec(unsigned short id, int a, void *b, void *c, eAreaTrgType trg);
    int SetEnable(cSceAtUnit *unit);
    int SetEnable(unsigned short id);
    int SetDisable(cSceAtUnit *unit);
    int SetDisable(unsigned short id);
    cSceAtUnit *getJumpPointAt(unsigned int id);
    int isHit(unsigned int id, eScehitType t);
    void getCenterPos(unsigned short id, cVec &out);
    void delUnitData(cSceAtUnit *unit);

    int m_unk0;
    char _pad4[0x5C - 4];
};

extern "C" cSceAtUnit *func_002C30C0(cSceAtManager *);
extern "C" cSceAtUnit *func_002C30C8(cSceAtManager *);

extern "C" int func_002C0ED0(cSceAtUnit *, eScehitType);
extern "C" void func_002C3058(cSceAtManager *, void *, cSceAtUnit *);

struct cSceAtExecEntry {
    void (*m_fn)(cSceAtUnit *, int);
    int m_unk4;
};
extern cSceAtExecEntry D_003C2650[];

#endif
