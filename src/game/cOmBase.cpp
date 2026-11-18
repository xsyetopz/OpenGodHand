#include "game/cOmBase.h"

struct cCollScr {
    char _unk;
};
extern cCollScr g_CollScr;
extern "C" void func_001331B8(cCollScr *coll, long id, bool enable);

// FUNCTION: GAME 0x1B79D0
unsigned long cOmBase::canCarry()
{
    long v = m_flags;
    return (v >> 3) & 1;
}

// FUNCTION: GAME 0x1B7680
void cOmBase::setScrSollEnable(bool enable)
{
    long id = (long)m_collId;
    cCollScr *c = &g_CollScr;
    func_001331B8(c, id, enable);
}
