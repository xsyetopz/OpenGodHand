// Scroll layer helpers (0x2DB000 range).
struct ScrObj2D {
    char _p[0x250];
    unsigned m_250;
    char _p1[0x2FD - 0x254];
    unsigned char m_2fd;
};
struct ScrVec2D {
    int m_0;
    ScrObj2D **m_4;
    ScrObj2D **m_8;
};
extern ScrVec2D *scrArray;
// Raw byte-offset access keeps gcc from treating scrArray as loop-invariant (original reloads it).
#define SCRU(o, off) *(unsigned *)((char *)(o) + (off))

extern "C" {

// DRAFT: GAME 0x2DB518
// diff: 7 words, original keeps the scrArray load in v0 and fills the beq slot with the a0 move; ours schedules the move first
#ifdef NONMATCHING
void SetSuspendScrollLayerAll__FPCUi(const unsigned *mask)
{
    ScrVec2D *s = scrArray;
    ScrObj2D **p = s->m_4;
    if (s->m_8 == p)
        return;
    do {
        ScrObj2D *o = *p;
        unsigned id = o->m_2fd;
        if (mask[id >> 5] & (0x80000000u >> (id & 31)))
            SCRU(o, 0x250) |= 0x8000;
        else
            SCRU(o, 0x250) &= 0xFFFF7FFF;
        p++;
    } while (p != scrArray->m_8);
}
#endif

// DRAFT: GAME 0x2DB620
// diff: 7 words, same prologue as 0x2DB518: the a0 move precedes the loads in ours and sits in the beq slot in the original
#ifdef NONMATCHING
void SetViewScrollIdAll__FPCUi(const unsigned *mask)
{
    ScrVec2D *s = scrArray;
    for (ScrObj2D **p = s->m_4; p != s->m_8; p++) {
        ScrObj2D *o = *p;
        unsigned id = o->m_2fd;
        if (id < 0x100) {
            if (mask[id >> 5] & (0x80000000u >> (id & 31)))
                SCRU(o, 0x250) |= 2;
            else
                SCRU(o, 0x250) &= 0xFFFFFFFD;
        }
        s = scrArray;
    }
}
#endif

}

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
extern "C" void func_002DBA88(void);
extern "C" void func_002DBCA0(void);
extern "C" void func_002DC2F0(void);
extern "C" void func_002DC1D0(void);
extern "C" int func_002DB7E0(void *);

// FUNCTION: GAME 0x2DBA00
void SetActionKickBomb()
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)3, (eActBtnType)0, (void *)func_002DBA88, 0, (eActFunc)0);
}

// FUNCTION: GAME 0x2DBC10
void SetActionStamp(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xA, (eActType)4, (eActBtnType)0, (void *)func_002DBCA0, arg, (eActFunc)0);
}

// FUNCTION: GAME 0x2DC260
extern "C" void func_002DC260(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    g_ActBtn.set((eScePriority)0xB, (eActType)0xC, (eActBtnType)0, (void *)func_002DC2F0, arg, (eActFunc)0);
}

// FUNCTION: GAME 0x2DC108
extern "C" void func_002DC108(void *arg)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    if (func_002DB7E0(arg))
        g_ActBtn.set((eScePriority)8, (eActType)7, (eActBtnType)0, (void *)func_002DC1D0, 0, (eActFunc)0);
    else
        g_ActBtn.set((eScePriority)7, (eActType)7, (eActBtnType)0, (void *)func_002DC1D0, 0, (eActFunc)0);
}
