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

// FUNCTION: GAME 0x283188
void func_00283188(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 1;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x2831B0
void func_002831B0(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 2;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x283240
void func_00283240(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 4;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x283258
void func_00283258(sEmGen *self)
{
    self->m_act0 = 0;
    self->m_act1 = 5;
    self->m_act2 = 0;
    self->m_act3 = 0;
}

// FUNCTION: GAME 0x283270
void func_00283270(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 7;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x283288
void func_00283288(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 8;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x283360
void func_00283360(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 11;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x2833C0
void func_002833C0(sEmGen *self, unsigned char a)
{
    self->m_act0 = 0;
    self->m_act1 = 10;
    self->m_act2 = 0;
    self->m_act3 = a;
}

// FUNCTION: GAME 0x2798D0
int func_002798D0(cGameObj *self)
{
    if (D_00747A80[0] & 0x40000000)
        return 1;
    if (self->isClip())
        return 1;
    unsigned int t = D_00747A80[-21] & 0x400000;
    return t != 0;
}

// FUNCTION: GAME 0x27D0E8
int func_0027D0E8(cGameObj *self)
{
    if (D_00747A80[0] & 0x40000000)
        return 1;
    if (self->isClip())
        return 1;
    unsigned int t = D_00747A80[-21] & 0x400000;
    return t != 0;
}
}
