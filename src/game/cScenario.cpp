#include "game/cScenario.h"

struct sRoomSave;
extern sRoomSave g_RoomSave;
extern unsigned int D_00463964;
extern "C" int func_002BED60(sRoomSave *, unsigned short, unsigned long);
extern "C" void func_002BECB0(sRoomSave *, unsigned long);

// FUNCTION: GAME 0x2C4DC0
void cScenario::SetRoomExitFunc(void *func, void *arg)
{
    m_roomExitFunc = func;
    m_roomExitArg = arg;
}

// FUNCTION: GAME 0x2C4040
int cScenario::isCamEnd()
{
    if (m_camWait == 0)
        return 1;
    if (D_00463964 & 2) {
        m_camWait = 0;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x2C5288
int cScenario::isOmBreak(unsigned short room, unsigned long flag)
{
    return func_002BED60(&g_RoomSave, room, flag);
}

// FUNCTION: GAME 0x2C5318
void cScenario::setOmBreak(unsigned long flag)
{
    func_002BECB0(&g_RoomSave, flag);
}

struct sDoor;
extern sDoor Door;
extern cMessage *Message;
extern "C" void *SearchCameraData__FPCc(const char *);
extern "C" void func_002C3F10(cScenario *, void *);
extern "C" void func_001FFE60(sDoor *, unsigned char, unsigned char, unsigned int, unsigned char);
extern "C" void func_001FFEB8(sDoor *, unsigned short, const cVec &, float, unsigned char, unsigned int, unsigned char);
extern "C" void func_001FFF30(sDoor *, unsigned short, const cVec &, float, unsigned char, unsigned int, unsigned char);

// FUNCTION: GAME 0x2C4390
void cScenario::endMess()
{
    if (m_messNo != 0xFFFF) {
        Message->deleteMessNo(m_messNo);
        m_messNo = 0xFFFF;
    }
}

// FUNCTION: GAME 0x2C3ED8
void cScenario::setCam(const char *name)
{
    func_002C3F10(this, SearchCameraData__FPCc(name));
}

// FUNCTION: GAME 0x2C4510
void cScenario::beginRoomJump(unsigned char a, unsigned char b, unsigned int c, unsigned char d)
{
    func_001FFE60(&Door, a, b, c, d);
}

// FUNCTION: GAME 0x2C4548
void cScenario::beginRoomJump(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c)
{
    func_001FFEB8(&Door, room, pos, ang, a, b, c);
}

// FUNCTION: GAME 0x2C4578
void cScenario::beginRoomJumpForce(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c)
{
    func_001FFF30(&Door, room, pos, ang, a, b, c);
}
