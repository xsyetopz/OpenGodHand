#ifndef CSCEATMANAGER_H
#define CSCEATMANAGER_H

#include "game/cSceAtUnit.h"

class cSceAtManager {
public:
    void SetDoorFunc(cSceAtUnit *unit, void *a, void *b);
    void AtDataReset(cSceAtUnit *unit);
    void AtDataReset(unsigned short id);
    void AtExecute(cSceAtUnit *unit);
    void AtExecute(unsigned short id);
    cSceAtUnit *getUnit(unsigned int id);
};

struct cSceAtExecEntry {
    void (*m_fn)(cSceAtUnit *, int);
    int m_unk4;
};
extern cSceAtExecEntry D_003C2650[];

#endif
