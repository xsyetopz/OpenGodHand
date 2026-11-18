#include "game/cOm1f.h"
#include "game/cOm4f.h"

// Virtual-method stubs of the 0x19xxxx-0x1Axxxx map-object classes, written as free functions.
extern "C" void func_001C29D0(cOmBase *self);
extern "C" void func_001BC0A0(cOmBase *self);
extern "C" void func_001BFB80(cOmBase *self);
extern "C" void func_001A6F00(cOmBase *self);

// FUNCTION: GAME 0x001A0320
extern "C" void func_001A0320(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A0598
extern "C" void func_001A0598(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A0810
extern "C" void func_001A0810(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A0A80
extern "C" void func_001A0A80(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A0CF8
extern "C" void func_001A0CF8(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A20A8
extern "C" void func_001A20A8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A34A0
extern "C" void func_001A34A0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A3CA0
extern "C" void func_001A3CA0(cOmBase *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x001A4B70
extern "C" void func_001A4B70(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A4B90
extern "C" void func_001A4B90(cOmBase *self)
{
    ((cOm4f *)self)->setOpen();
}

// FUNCTION: GAME 0x001A4BB0
extern "C" void func_001A4BB0(cOmBase *self)
{
    ((cOm4f *)self)->setClose();
}

// FUNCTION: GAME 0x001A5B08
extern "C" void func_001A5B08(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A6CD8
extern "C" void func_001A6CD8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A6EC0
extern "C" void func_001A6EC0(cOmBase *self)
{
    func_001A6F00(self);
}

// FUNCTION: GAME 0x001A6EE0
extern "C" void func_001A6EE0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A7EA0
extern "C" void func_001A7EA0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A82D8
extern "C" void func_001A82D8(cOmBase *self)
{
    func_001BC0A0(self);
}

// FUNCTION: GAME 0x001A8688
extern "C" void func_001A8688(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A8840
extern "C" void func_001A8840(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A91F0
extern "C" void func_001A91F0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001A97E8
extern "C" void func_001A97E8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001AA8B8
extern "C" void func_001AA8B8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001AD8C8
extern "C" void func_001AD8C8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001ADDD8
extern "C" void func_001ADDD8(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x001AFBB0
extern "C" void func_001AFBB0(cOmBase *self)
{
    self->dieCommon();
}

// FUNCTION: GAME 0x194550
extern "C" void func_00194550()
{
}

extern "C" void func_001B6FB8(void *self);

// FUNCTION: GAME 0x195EF8
extern "C" int func_00195EF8(void *self)
{
    func_001B6FB8(self);
    return 1;
}

// FUNCTION: GAME 0x195FE0
extern "C" void func_00195FE0()
{
}

// FUNCTION: GAME 0x1A6550
extern "C" void func_001A6550()
{
}

// FUNCTION: GAME 0x1A50F0
extern "C" char *func_001A50F0(char *self)
{
    return self + 0x780;
}

// FUNCTION: GAME 0x1ADA70
extern "C" void func_001ADA70(char *self, float f)
{
    *(float *)(self + 0x790) = f;
}
