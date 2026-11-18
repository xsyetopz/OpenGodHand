#include "game/cCamera.h"

// FUNCTION: GAME 0x138238
void cCamera::setMode(eMode)
{
}

// FUNCTION: GAME 0x138528
void cCamera::resetVib()
{
    m_unk274 = 0;
    m_unk268 = 0;
    m_unk270 = 0;
    m_unk26C = 0;
    m_unk278 = 0;
    m_unk260 = 0;
    m_unk254 = 0;
    m_unk25C = 0;
    m_unk258 = 0;
    m_unk264 = 0;
}

extern "C" void func_00139010(int a, unsigned int b);
extern "C" void func_00139090(void *);
extern void *pCamWork;

// FUNCTION: GAME 0x139040
extern "C" void func_00139040()
{
    func_00139010(1, 0xFFFF);
}

// FUNCTION: GAME 0x138C70
extern "C" void func_00138C70(char *self)
{
    *(int *)(self + 0x1028) = 1;
    func_00139090(self);
    pCamWork = self;
}

// FUNCTION: GAME 0x138BB8
extern "C" void func_00138BB8()
{
}
