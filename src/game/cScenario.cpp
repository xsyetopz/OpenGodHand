#include "game/cScenario.h"

// FUNCTION: GAME 0x2C4DC0
void cScenario::SetRoomExitFunc(void *func, void *arg)
{
    m_roomExitFunc = func;
    m_roomExitArg = arg;
}
