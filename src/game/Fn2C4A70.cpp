#include "game/cScenario.h"
#include "game/cVec.h"

struct sSaveMgr;
extern int g_CasinoWork;
extern unsigned int D_00747A24;
extern sSaveMgr *g_SaveManager;
extern char *g_Sce;
extern "C" void setCheckPoint__12cSaveManagerbPC4cVecT2(sSaveMgr *, int, int, int);

// FUNCTION: GAME 0x2C4A70
void cScenario::beginKurohukuBattle()
{
    sVec4 a;
    sVec4 b;
    g_CasinoWork |= 8;
    a.x = 4.2f;
    a.z = -44.2f;
    a.y = 0;
    a.w = 1.0f;
    *(unsigned short *)(g_Sce + 0x16) = 0;
    *(cVec *)g_Sce = *(cVec *)&a;
    *(float *)(g_Sce + 0x10) = -1.5707964f;
    setCheckPoint__12cSaveManagerbPC4cVecT2(g_SaveManager, 0, 0, 0);
    D_00747A24 |= 0x08000000;
    sVec4 *p = &b;
    *(int *)&b.x = 0;
    *(int *)&b.y = 0;
    *(int *)&b.z = 0;
    p->w = 1.0f;
    ((cScenario *)g_Sce)->beginRoomJump(0x4F, *(cVec *)p, 0, 0, 0x80000000, 1);
}
