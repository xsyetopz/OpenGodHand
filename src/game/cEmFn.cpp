#include "game/cObj.h"

class cGameObj;
class cCollisionSolidManage {
public:
    void ReleaseUnit(cGameObj *obj);
};
extern cCollisionSolidManage g_CollSolidManage;

struct sEmGen : cObj {
    char _pad2F8[0x1560 - 0x2F8];
    unsigned int m_flags;
    char _pad1564[0x1580 - 0x1564];
    int m_unk1580;
    char _pad1584[0x15B4 - 0x1584];
    float m_unk15B4;
};

extern "C" {
void func_0028CE70(sEmGen *);

// FUNCTION: GAME 0x278368
void func_00278368(cGameObj *obj)
{
    g_CollSolidManage.ReleaseUnit(obj);
}

// FUNCTION: GAME 0x2815C0
unsigned int func_002815C0(sEmGen *self)
{
    return self->m_flags & 1;
}

// FUNCTION: GAME 0x2815D0
int func_002815D0(sEmGen *self)
{
    unsigned int t = self->m_flags & 2;
    return t != 0;
}

// FUNCTION: GAME 0x27DD10
void func_0027DD10(sEmGen *self, float f)
{
    if (self->m_unk15B4 < f)
        self->m_unk15B4 = f;
}

// FUNCTION: GAME 0x27DAF0
void func_0027DAF0(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 2;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x27DB08
void func_0027DB08(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 4;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x281278
void func_00281278(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 1;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x281290
void func_00281290(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 2;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x281260
void func_00281260(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 0;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x28BEA8
void func_0028BEA8(sEmGen *self)
{
    func_0028CE70(self);
}
}
