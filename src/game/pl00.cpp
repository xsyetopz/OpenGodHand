#include "game/pl00.h"

extern "C" void func_001CF8B0(void *p);
extern "C" int func_0010B698(pl00 *p);
class cEmManage {
public:
    int CkPlCatched();
};
extern cEmManage g_EmManage;
extern "C" void func_001269E0(pl00 *p, unsigned int a, int b);

class cPlCamera {
public:
    void setCamUpdate(unsigned int a);
};
class cCamManager : public cPlCamera {
public:
    void setPlCamera(unsigned char v);
};
extern cCamManager CamManager;

// FUNCTION: GAME 0x10BD08
void pl00::SetCannonReflect(unsigned char v)
{
    m_modeA = 6;
    m_modeB = 0;
    m_modeC = 2;
    m_modeD = v;
}

#ifdef NONMATCHING
// 0x124FC8: compiles sra+andi instead of andi+sltu for the single-bit test
bool pl00::ckMotionCam()
{
    return !!(m_unk15F4 & 2);
}
#endif

// FUNCTION: GAME 0x12AC60
void pl00::DiscardWeapon()
{
    if (m_unk698) {
        func_001CF8B0(m_unk698);
        m_unk698 = 0;
    }
}

#ifdef NONMATCHING
// 0x12BAB8: switch form is 5 words off: original returns via slti/beqz+bltz range check back to a shared 'return 0'
int pl00::CkSubScreen()
{
    if (m_modeA)
        return 0;
    switch (m_modeB) {
    case 0: case 1: case 2: case 3:
        return 1;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x12BF50
int pl00::ckAtkActBtnEnable()
{
    if (m_unk6A0)
        return 0;
    if (m_unk54A <= 0)
        return 0;
    if (func_0010B698(this))
        return 0;
    if (g_EmManage.CkPlCatched())
        return 0;
    return ((unsigned char *)&m_unk15F4)[1] & 1;
}

// FUNCTION: GAME 0x12C0D8
void pl00::setEventWait()
{
    m_modeA = 0;
    m_modeB = 0x45;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CD70
void pl00::setJump(float v)
{
    m_modeA = 0;
    m_modeB = 0x33;
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CD90
void pl00::setIgnition(const cVec &pos, float v)
{
    if (&m_unk660 != &pos)
        m_unk660 = pos;
    m_modeA = 0;
    m_modeB = 0x34;
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CDD0
void pl00::setPyramidIn()
{
    m_modeA = 0;
    m_modeB = 0x36;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CE20
void pl00::lookCliff(const cVec &pos, float v)
{
    if (&m_unk660 != &pos)
        m_unk660 = pos;
    m_modeA = 0;
    m_modeB = 0x35;
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x10B980
void pl00::SubscreenMotSet(unsigned int a)
{
    func_001269E0(this, a, 1);
    m_modeA = 5;
    m_modeB = 0;
    m_modeC = 2;
    m_modeD = 0;
}

// FUNCTION: GAME 0x10BCC0
void pl00::CannonGameMode(unsigned int on)
{
    if (on) {
        m_modeA = 6;
        m_unk54C = 5.0f;
        m_modeB = 0;
        m_modeC = 0;
        m_modeD = 0;
    } else {
        reset();
    }
}

// FUNCTION: GAME 0x124F60
void pl00::clearMotionCam(unsigned int a, unsigned int b)
{
    if (!(b & 1)) {
        if (!(m_unk15F4 & 2))
            return;
        m_unk15F4 &= ~2;
    }
    cPlCamera *c = &CamManager;
    if (c)
        c->setCamUpdate(a);
    CamManager.setPlCamera(0);
}
