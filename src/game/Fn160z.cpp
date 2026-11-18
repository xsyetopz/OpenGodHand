// Free functions in 0x160000-0x170000.

#include "game/cIDBase.h"

struct sIDInner160z {
    char _pad0[0xB0];
    int m_b0;
    int m_b4;
};
struct sIDSys160z {
    sIDInner160z *m_inner;
};
extern sIDSys160z *IDSys;
struct sWork160z;
extern "C" void func_001615F0(sWork160z *self);
extern "C" void func_00161590(void *self);

// FUNCTION: GAME 0x168080
extern "C" void func_00168080(cIDBase *self)
{
    func_001615F0((sWork160z *)self);
    if (((unsigned char *)self)[0x64] == 1) {
        ((char *)self)[0x90] = 0;
    }
    sIDSys160z *sys = IDSys;
    self->release();
    sIDInner160z *in = sys->m_inner;
    in->m_b4 = 0;
    in->m_b0 = 0;
    func_00161590(self);
}
