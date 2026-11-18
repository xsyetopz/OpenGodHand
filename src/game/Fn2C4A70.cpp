#include "game/cScenario.h"
#include "game/cVec.h"

struct sSaveMgr;
extern int g_CasinoWork;
extern unsigned int D_00747A24;
extern sSaveMgr *g_SaveManager;
extern cScenario *g_Sce;
extern "C" void setCheckPoint__12cSaveManagerbPC4cVecT2(sSaveMgr *, int, int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2C4A70
void cScenario::beginKurohukuBattle()
{
    sVec4 a;
    sVec4 b;
    g_CasinoWork |= 8;
    a.x = 4.2f;
    a.z = -44.2f;
    a.y = 0;
    a.w = 1.0f;
    g_Sce->m_jumpRoom = 0;
    *(cVec *)&g_Sce->m_jumpPos = *(cVec *)&a;
    g_Sce->m_jumpAng = -1.5707964f;
    setCheckPoint__12cSaveManagerbPC4cVecT2(g_SaveManager, 0, 0, 0);
    D_00747A24 |= 0x08000000;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    b.w = 1.0f;
    g_Sce->beginRoomJump(0x4F, *(cVec *)&b, 0, 0, 0, 1);
}
#endif
