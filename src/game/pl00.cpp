#include "game/pl00.h"

extern "C" void func_001CF8B0(void *p);
extern "C" int func_0010B698(pl00 *p);
class cEmManage {
public:
    int CkPlCatched();
};
extern cEmManage g_EmManage;

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
// 0x12BAB8: original is lbu+slti+bltz range check; compiler folds unsigned char test to sltiu
int pl00::CkSubScreen()
{
    if (m_modeA)
        return 0;
    int v = *(volatile unsigned char *)&m_modeB;
    return v < 4 && v >= 0;
}
#endif

#ifdef NONMATCHING
// 0x12BF50: delay slot of jal func_0010B698 is nop; original refills a0 from s0 (daddu)
int pl00::ckAtkActBtnEnable()
{
    if (!m_unk6A0 && m_unk54A > 0 && !func_0010B698(this) && !g_EmManage.CkPlCatched())
        return ((unsigned char *)&m_unk15F4)[1] & 1;
    return 0;
}
#endif

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
    m_modeC = 0;
    m_modeD = 0;
    m_unk670 = v;
}

// FUNCTION: GAME 0x12CD90
void pl00::setIgnition(const cVec &pos, float v)
{
    if (&m_unk660 != &pos)
        m_unk660 = pos;
    m_modeA = 0;
    m_modeB = 0x34;
    m_modeC = 0;
    m_modeD = 0;
    m_unk670 = v;
}

// FUNCTION: GAME 0x12CDD0
void pl00::setPyramidIn()
{
    m_modeA = 0;
    m_modeB = 0x36;
    m_modeC = 0;
    m_modeD = 0;
}
