#include "game/cOmBase.h"

// Small unnamed functions of the cOl* object units in 0x180000-0x18FFFF.

extern "C" void func_001BC0A0();
extern "C" void func_001C29D0();
extern "C" void func_001BFB80();
extern "C" void func_001BBF00(void *);
extern "C" void func_00180698(int, unsigned);
extern "C" char D_00422770[];

class cObjBase {
public:
    void KageDraw();
};

// FUNCTION: GAME 0x1812B0
extern "C" void func_001812B0()
{
}

// FUNCTION: GAME 0x1815A8
extern "C" void func_001815A8()
{
}

// FUNCTION: GAME 0x1808C8
extern "C" void func_001808C8()
{
    func_00180698(1, 0xFFFF);
}

// FUNCTION: GAME 0x1816C0
extern "C" void func_001816C0(char *self)
{
    *(char **)(self + 0x214) = D_00422770;
    func_001BBF00(self);
}

// FUNCTION: GAME 0x1866A0
extern "C" void func_001866A0(cObjBase *self)
{
    self->KageDraw();
}

// FUNCTION: GAME 0x1815B0
extern "C" void func_001815B0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x1817C8
extern "C" void func_001817C8()
{
    func_001BC0A0();
}

// FUNCTION: GAME 0x182020
extern "C" void func_00182020(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x182818
extern "C" void func_00182818()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x182FD8
extern "C" void func_00182FD8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x1834F0
extern "C" void func_001834F0()
{
    func_001BFB80();
}

// FUNCTION: GAME 0x1837D8
extern "C" void func_001837D8()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x184A20
extern "C" void func_00184A20(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x186928
extern "C" void func_00186928()
{
    func_001BC0A0();
}

// FUNCTION: GAME 0x187190
extern "C" void func_00187190(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x187958
extern "C" void func_00187958()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x187C18
extern "C" void func_00187C18()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x188528
extern "C" void func_00188528(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x188C88
extern "C" void func_00188C88()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x188F10
extern "C" void func_00188F10()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x18A110
extern "C" void func_0018A110(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18AD88
extern "C" void func_0018AD88(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18BAA0
extern "C" void func_0018BAA0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18C8A8
extern "C" void func_0018C8A8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18D698
extern "C" void func_0018D698(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18E450
extern "C" void func_0018E450(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x18EC28
extern "C" void func_0018EC28()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x18EE38
extern "C" void func_0018EE38()
{
    func_001BFB80();
}

// FUNCTION: GAME 0x18F0A0
extern "C" void func_0018F0A0()
{
    func_001BC0A0();
}

// FUNCTION: GAME 0x18FBF0
extern "C" void func_0018FBF0(cOmBase *self)
{
    self->dieCommon();
}
