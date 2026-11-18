#include "game/cEmManage.h"

enum eScePriority { PRI_0 };
enum eActType { ACT_0 };
enum eActBtnType { BTN_0 };
enum eActFunc { FN_0 };
class cActionButton {
public:
    void set(eScePriority, eActType, eActBtnType, void *, void *, eActFunc);
};
extern cActionButton g_ActBtn;
struct Plr2D {
    char _p[0x54A];
    short m_54a;
};
Plr2D *Getplayer();
extern "C" int func_0010B698(Plr2D *);
extern "C" int func_002DB7E0(void *);
extern int D_00586A04;
extern "C" void func_002DBB90(void);
extern "C" void func_002DBF20(void);
extern "C" void func_002DBE08(void);
extern "C" void func_002DC078(void);
extern "C" void func_002DB978(void);

class cGameObj;
class cCollisionSolidManage {
public:
    void SetActive(cGameObj *, bool);
};
extern cCollisionSolidManage g_CollSolidManage;
extern "C" void func_00129718(Plr2D *, char *, int);

#define ENTER_STATE(NAME, ID)                                                                     \
    extern "C" void NAME(char *self)                                                              \
    {                                                                                             \
        Plr2D *p = Getplayer();                                                                   \
        if (self == 0 || p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 ||        \
            g_EmManage.CkPlCatched())                                                             \
            return;                                                                               \
        self[0x2F6] = 0;                                                                          \
        self[0x2F7] = 0;                                                                          \
        *(float *)(self + 0x54C) = 30.0f;                                                         \
        self[0x2F4] = 1;                                                                          \
        self[0x2F5] = ID;                                                                         \
        g_CollSolidManage.SetActive((cGameObj *)self, false);                                     \
        func_00129718(p, self, ID);                                                               \
    }

// FUNCTION: GAME 0x2DD300
ENTER_STATE(func_002DD300, 0x1D)
// FUNCTION: GAME 0x2DD3C0
ENTER_STATE(func_002DD3C0, 0x1E)
// FUNCTION: GAME 0x2DD480
ENTER_STATE(func_002DD480, 0x1F)

// FUNCTION: GAME 0x2DBB08
extern "C" void func_002DBB08()
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)4, (eActBtnType)0, (void *)func_002DBB90, 0, (eActFunc)0);
}

// FUNCTION: GAME 0x2DBE98
extern "C" void func_002DBE98()
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)7, (eActType)6, (eActBtnType)0, (void *)func_002DBF20, 0, (eActFunc)0);
}

// FUNCTION: GAME 0x2DBD40
extern "C" void func_002DBD40(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    if (func_002DB7E0(arg))
        g_ActBtn.set((eScePriority)8, (eActType)6, (eActBtnType)0, (void *)func_002DBE08, 0, (eActFunc)0);
    else
        g_ActBtn.set((eScePriority)7, (eActType)6, (eActBtnType)0, (void *)func_002DBE08, 0, (eActFunc)0);
}

// FUNCTION: GAME 0x2DBFB0
extern "C" void func_002DBFB0(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    if (func_002DB7E0(arg))
        g_ActBtn.set((eScePriority)8, (eActType)0x17, (eActBtnType)0, (void *)func_002DC078, 0, (eActFunc)0);
    else
        g_ActBtn.set((eScePriority)7, (eActType)0x17, (eActBtnType)0, (void *)func_002DC078, 0, (eActFunc)0);
}

// FUNCTION: GAME 0x2DB8B8
extern "C" void func_002DB8B8(char *self)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || D_00586A04 > 0 || self == 0)
        return;
    if (func_002DB7E0(*(void **)(self + 0xF0)))
        g_ActBtn.set((eScePriority)8, (eActType)6, (eActBtnType)0, (void *)func_002DB978, self, (eActFunc)0);
    else
        g_ActBtn.set((eScePriority)7, (eActType)6, (eActBtnType)0, (void *)func_002DB978, self, (eActFunc)0);
}
