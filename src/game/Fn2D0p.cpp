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
extern "C" void func_002DB978(char *);

class cGameObj;
class cCollisionSolidManage {
public:
    void SetActive(cGameObj *, bool);
};
extern cCollisionSolidManage g_CollSolidManage;
extern "C" void func_00129718(Plr2D *, char *, int);

#define ENTER_STATE2(NAME, ID, ARG)                                                                  \
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
        func_00129718(p, self, ARG);                                                             \
    }

#define ENTER_STATE(NAME, ID) ENTER_STATE2(NAME, ID, ID)

// FUNCTION: GAME 0x2DD300
ENTER_STATE(func_002DD300, 0x1D)
// FUNCTION: GAME 0x2DD3C0
ENTER_STATE(func_002DD3C0, 0x1E)
// FUNCTION: GAME 0x2DD480
ENTER_STATE(func_002DD480, 0x1F)
// FUNCTION: GAME 0x2DD540
ENTER_STATE(func_002DD540, 0x20)
// FUNCTION: GAME 0x2DD600
ENTER_STATE(func_002DD600, 0x21)
// FUNCTION: GAME 0x2DD7B0
ENTER_STATE2(func_002DD7B0, 0x24, 0x23)
// FUNCTION: GAME 0x2DD870
ENTER_STATE2(func_002DD870, 0x25, 0x24)
// FUNCTION: GAME 0x2DD930
ENTER_STATE2(func_002DD930, 0x26, 0x25)
// FUNCTION: GAME 0x2DD9F0
ENTER_STATE2(func_002DD9F0, 0x27, 0x26)

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

class pl00 {
public:
    void clearMotionCam(unsigned, unsigned);
    char _p[0x2F4];
    char m_2f4, m_2f5, m_2f6, m_2f7;
};

#define CAM_STATE(NAME, ID)                                                                       \
    extern "C" void NAME()                                                                        \
    {                                                                                             \
        Plr2D *q = Getplayer();                                                                   \
        if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 ||                     \
            g_EmManage.CkPlCatched())                                                             \
            return;                                                                               \
        pl00 *s = (pl00 *)q;                                                                      \
        s->m_2f4 = 0;                                                                             \
        s->m_2f6 = 0;                                                                             \
        s->m_2f7 = 0;                                                                             \
        s->m_2f5 = ID;                                                                            \
        s->clearMotionCam(0, 0);                                                                  \
    }

#define PLAIN_STATE(NAME, ID)                                                                     \
    extern "C" void NAME()                                                                        \
    {                                                                                             \
        Plr2D *q = Getplayer();                                                                   \
        if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 ||                     \
            g_EmManage.CkPlCatched())                                                             \
            return;                                                                               \
        pl00 *s = (pl00 *)q;                                                                      \
        s->m_2f5 = ID;                                                                            \
        s->m_2f4 = 0;                                                                             \
        s->m_2f6 = 0;                                                                             \
        s->m_2f7 = 0;                                                                             \
    }

// FUNCTION: GAME 0x2DBF20
CAM_STATE(func_002DBF20, 0x2E)
// FUNCTION: GAME 0x2DBE08
CAM_STATE(func_002DBE08, 0x2D)
// FUNCTION: GAME 0x2DC078
CAM_STATE(func_002DC078, 0x2F)
// FUNCTION: GAME 0x2DC1D0
CAM_STATE(func_002DC1D0, 0x30)
// FUNCTION: GAME 0x2DBB90
PLAIN_STATE(func_002DBB90, 0x13)
// FUNCTION: GAME 0x2DBA88
PLAIN_STATE(func_002DBA88, 0x12)

float Turn_dest(const float *, float, const float *, float);
float Adjust_theta(float);

#define PL_F(s, o, T) (*(T *)((char *)(s) + (o)))

// FUNCTION: GAME 0x2DD270
extern "C" void func_002DD270(char *arg)
{
    Plr2D *q = Getplayer();
    if (arg == 0 || q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    PL_F(q, 0x640, char *) = arg;
    PL_F(q, 0x648, char) = 0x14;
    func_00129718(q, arg, 0x1C);
}

// FUNCTION: GAME 0x2DBCA0
extern "C" void func_002DBCA0(char *arg)
{
    Plr2D *q = Getplayer();
    if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    pl00 *s = (pl00 *)q;
    PL_F(s, 0x640, char *) = arg;
    s->m_2f4 = 0;
    s->m_2f6 = 0;
    s->m_2f7 = 0;
    s->m_2f5 = 0x11;
    PL_F(s, 0x648, char) = 0x14;
    s->clearMotionCam(0, 0);
}

// FUNCTION: GAME 0x2DC2F0
extern "C" void func_002DC2F0(char *arg)
{
    Plr2D *q = Getplayer();
    if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    pl00 *s = (pl00 *)q;
    s->m_2f4 = 0;
    s->m_2f5 = 0x17;
    s->m_2f6 = 0;
    s->m_2f7 = 0;
    Turn_dest(PL_F(s, 0xF0, const float *), PL_F(s, 0x104, float), PL_F(arg, 0xF0, const float *), 3.1415927f);
}

// FUNCTION: GAME 0x2DC670
extern "C" void func_002DC670(char *arg)
{
    Plr2D *q = Getplayer();
    if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    pl00 *s = (pl00 *)q;
    s->m_2f5 = 0x17;
    s->m_2f7 = 1;
    s->m_2f4 = 0;
    s->m_2f6 = 0;
    float pi = 3.1415927f;
    float t = Turn_dest(PL_F(s, 0xF0, const float *), PL_F(s, 0x104, float), PL_F(arg, 0xF0, const float *), pi);
    t += pi;
    PL_F(s, 0x104, float) = PL_F(s, 0x104, float) + t;
    PL_F(s, 0x104, float) = Adjust_theta(PL_F(s, 0x104, float));
}

// FUNCTION: GAME 0x2DD6C0
extern "C" void func_002DD6C0(char *self)
{
    Plr2D *p = Getplayer();
    if (self == 0 || p->m_54a <= 0 || func_0010B698(p) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    float v = PL_F(self, 0x770, float);
    PL_F(self, 0x54C, float) = 30.0f;
    if (v > 0.0f && v < 10.0f)
        PL_F(self, 0x770, float) = 10.0f;
    self[0x2F6] = 0;
    self[0x2F7] = 0;
    self[0x2F4] = 1;
    self[0x2F5] = 0x22;
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    func_00129718(p, self, 0x22);
}

extern char D_0044D420[];
extern "C" int strcmp(const char *, const char *);
extern "C" void func_001C24E8(char *);

// FUNCTION: GAME 0x2DB978
extern "C" void func_002DB978(char *self)
{
    Plr2D *p = Getplayer();
    if (p->m_54a <= 0 || func_0010B698(p) || D_00586A04 > 0 || self == 0 || PL_F(self, 0x250, int) < 0 ||
        strcmp(D_0044D420, PL_F(self, 0x4AC, const char *)))
        return;
    func_001C24E8(self);
}
