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
extern "C" void func_00129718(Plr2D *, char *, int);
extern "C" void func_002DC420(char *);
extern "C" void func_002DC548(char *);
extern "C" void func_002DC670(void);

// FUNCTION: GAME 0x2DC390
extern "C" void func_002DC390(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)0x21, (eActBtnType)0, (void *)func_002DC420, arg, (eActFunc)0);
}

// FUNCTION: GAME 0x2DC4B8
extern "C" void func_002DC4B8(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)0xC, (eActBtnType)0, (void *)func_002DC548, arg, (eActFunc)0);
}

// FUNCTION: GAME 0x2DC5E0
extern "C" void func_002DC5E0(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)0xC, (eActBtnType)0, (void *)func_002DC670, arg, (eActFunc)0);
}

// FUNCTION: GAME 0x2DC420
extern "C" void func_002DC420(char *self)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    self[0x2F4] = 0;
    self[0x2F7] = 0;
    self[0x2F5] = 0x5D;
    self[0x2F6] = 2;
    func_00129718(p, self, 0x16);
}

// FUNCTION: GAME 0x2DC548
extern "C" void func_002DC548(char *self)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    self[0x2F6] = 0;
    self[0x2F7] = 0;
    self[0x2F4] = 1;
    self[0x2F5] = 0x1C;
    func_00129718(p, self, 0x27);
}
