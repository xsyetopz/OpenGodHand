#include "game/cObj.h"
#include "game/cGameObj.h"

class cGameObj;
class cCollisionSolidManage {
public:
    void ReleaseUnit(cGameObj *obj);
};
extern cCollisionSolidManage g_CollSolidManage;
extern unsigned int D_00747A80[];

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

// FUNCTION: GAME 0x27DCB8
void func_0027DCB8(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 9;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x27DCD0
void func_0027DCD0(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 10;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x27DCE8
void func_0027DCE8(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 3;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x281320
void func_00281320(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 4;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x281338
void func_00281338(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 5;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x281350
void func_00281350(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 6;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x2813C0
void func_002813C0(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 8;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x2813D8
void func_002813D8(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 9;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x281458
void func_00281458(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 14;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x2814B8
void func_002814B8(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 11;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x2814D0
void func_002814D0(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 12;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x2814E8
void func_002814E8(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 13;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x283170
void func_00283170(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 0;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

}
