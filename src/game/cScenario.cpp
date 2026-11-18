#include "game/cScenario.h"

extern "C" void *memset(void *, int, unsigned int);

extern "C" void func_002C3968(cScenario *self, int n);
extern "C" int func_002C4350(cScenario *self);

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

extern cScenario *g_Sce;
extern unsigned int D_00747A84;
extern "C" void *Getplayer__Fv();
extern "C" int func_0012BAF0(void *);

// FUNCTION: GAME 0x2C3E40
int cScenario::isEventStartOk()
{
    if (D_00747A84 & 0x40000000)
        return 0;
    return func_0012BAF0(Getplayer__Fv()) != 0;
}

// FUNCTION: GAME 0x2C3E88
void cScenario::waitEventStartOk()
{
    cTaskManager *t = &m_task;
    while (!isEventStartOk())
        t->m_work->sleep(1);
}

// FUNCTION: GAME 0x2C4078
void cScenario::waitCam()
{
    while (!isCamEnd())
        g_Sce->m_task.m_work->sleep(1);
}

// FUNCTION: GAME 0x2C42E0
void cScenario::setMess(unsigned int no)
{
    if (m_messNo != 0xFFFF)
        endMess();
    if (Message->create(no, 0, 0, 0) != 0xFFFF)
        m_messNo = no;
}

// FUNCTION: GAME 0x2C43D8
void cScenario::waitMess()
{
    while (func_002C4350(this) == 1)
        g_Sce->m_task.m_work->sleep(1);
    endMess();
}

// FUNCTION: GAME 0x2C52B0
void cScenario::setOmBreak(const char *name)
{
    sRoomSave *rs = &g_RoomSave;
    long h = 0;
    int i = 0;
    if (*name) {
        do {
            h |= (long)*name << (i * 8);
            i++;
            name++;
        } while (i < 8 && *name);
    }
    func_002BECB0(rs, h);
}

extern cObjBaseArray objbaseArray;
extern "C" int func_002BED08(sRoomSave *, unsigned long);

// FUNCTION: GAME 0x2C5110
int cScenario::isOmBreak(cOmBase *om)
{
    if (!om)
        return 1;
    if (func_002BED08(&g_RoomSave, om->m_id) == 1)
        return 1;
    long f = om->m_flags;
    int r = 0;
    if ((f >> 1) & 1)
        r = 1;
    return r;
}

// FUNCTION: GAME 0x2C5168
int cScenario::isOmBreak(const char *name)
{
    cObjBaseArray *arr = &objbaseArray;
    long h = 0;
    int i = 0;
    if (*name) {
        do {
            h |= (long)*name << (i * 8);
            i++;
            name++;
        } while (i < 8 && *name);
    }
    return isOmBreak(arr->SearchOM(h));
}

// FUNCTION: GAME 0x2C5220
int cScenario::isOmBreak(unsigned short room, const char *name)
{
    sRoomSave *rs = &g_RoomSave;
    long h = 0;
    int i = 0;
    if (*name) {
        do {
            h |= (long)*name << (i * 8);
            i++;
            name++;
        } while (i < 8 && *name);
    }
    return func_002BED60(rs, room, h);
}

extern unsigned int D_00747A78;
extern cCamManager CamManager;

// FUNCTION: GAME 0x2C3FC0
void cScenario::resetCam()
{
    D_00747A78 &= 0xFFDFFFFF;
    cCamManager *cm = &CamManager;
    cPlCamera *pc = cm;
    if (pc)
        pc->setCamUpdate(0);
    cm->setPlCamera(0);
    ((pl00 *)Getplayer__Fv())->clearMotionCam(0, 1);
    m_camWait = 0;
}

// 0x2C5068 setOmSuspend near-miss: see src/scratch/cScenario/setOmSuspend.cpp (38 words differ: objbaseArray
// addressed addiu+reload vs lui+lo-folded lw; kind test slti/slti vs addiu/sltiu; flags2>>6 lwu+dsra vs lw+dsll32/dsrl32).


extern sSaveManager *g_SaveManager;
extern unsigned int D_00747A24;
extern "C" void func_002BFC80(sSaveManager *);

// 0x2C4868 near-miss: all calls and fields right, but original loads g_SaveManager/g_Sce earlier
// (hoisted before the branch, sltiu in the func_002BFC80 delay slot) and branches on s0 differently;
// 50 words differ, mostly scheduling.
#ifdef NONMATCHING
// FUNCTION: GAME 0x2C4868
void cScenario::endExtraGame()
{
    if (m_jumpPending == 1) {
        m_jumpPending = 0;
        unsigned short room = m_jumpRoom;
        sVec4 pos = m_jumpPos;
        float ang = m_jumpAng;
        int first = ((pl00 *)Getplayer__Fv())->m_x54A == 0;
        func_002BFC80(g_SaveManager);
        if (!first)
            g_Sce->beginRoomJump(room, *(cVec *)&pos, ang, 0, 2, 1);
        else
            g_Sce->beginRoomJump(room, *(cVec *)&pos, ang, 0, 0, 1);
        D_00747A24 = (D_00747A24 | 0x1000000) & 0xF7FFFFFF;
    }
}
#endif

extern "C" int func_002D5580(cTaskManager *, void *, void *, int);
extern "C" void func_002C4150(cScenario *, unsigned short, void *, bool, unsigned char, int);
extern "C" void setPlayerPos__FRC4cVecf(const cVec &, float);

// FUNCTION: GAME 0x2C3890
int cScenario::taskExec(void (&fn)(), int n)
{
    int r = m_task.execute(fn, n);
    func_002C3968(this, r);
    return r;
}

// FUNCTION: GAME 0x2C3920
int cScenario::taskExec(void *fn, void *arg, int n)
{
    int r = func_002D5580(&m_task, fn, arg, n);
    func_002C3968(this, r);
    return r;
}

// FUNCTION: GAME 0x2C40C8
void cScenario::execUpCut(unsigned short a, const char *name, bool b, unsigned char c, int d)
{
    void *cam = name ? SearchCameraData__FPCc(name) : 0;
    func_002C4150(this, a, cam, b, c, d);
}

struct sObjVT {
    char _pad0[0x70];
    short m_d0;
    short _pad72;
    void (*m_setPos)(void *, const sVec4 *);
    short m_d1;
    short _pad7A;
    void (*m_setRot)(void *, const sVec4 *);
};

struct sObjView {
    char _pad0[0x214];
    sObjVT *m_vt;
    char _pad218[0x2FE - 0x218];
    unsigned short m_kind;
};

// 0x2C4440 near-miss: 9 words differ; the original loads the vtable (lw a2,0x214) before the rot stores and
// reuses it for both reads, mine reloads it after the stores into a different register.
#ifdef NONMATCHING
// FUNCTION: GAME 0x2C4440
void cScenario::moveObjPos(cGameObj *obj, float x, float y, float z, float ang)
{
    sObjView *o = (sObjView *)obj;
    if ((o->m_kind ^ 0x100) != 0) {
        sVec4 pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        pos.w = 1.0f;
        o->m_vt->m_setPos((char *)o + o->m_vt->m_d0, &pos);
        sVec4 rot;
        sVec4 *r = &rot;
        rot.y = ang;
        rot.x = 0;
        rot.z = 0;
        r->w = 1.0f;
        o->m_vt->m_setRot((char *)o + o->m_vt->m_d1, r);
    } else {
        sVec4 pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        pos.w = 1.0f;
        setPlayerPos__FRC4cVecf(*(cVec *)&pos, ang);
    }
}
#endif

struct sSys {
    char _pad0[0x5B0];
    unsigned short m_mode;
    char _pad5B2[0x5E0 - 0x5B2];
    unsigned int m_flags;
};
struct sSceAtDummy;
struct sCallback {
    char _pad0[0xC];
    void (*m_fn)();
};
extern sSys Sys;
extern int D_00747A2C;
extern sSceAtDummy g_SceAt;
extern "C" void func_002C14F8(sSceAtDummy *);
extern "C" void func_002D5358(cTaskManager *);
extern "C" void func_002C4E18(cScenario *);

// 0x2C3678 near-miss (91 words differ): control flow and calls match the asm, but flag tests on m_flags48
// compile to lw/dsll32/dsra32/xori/beqz where the original has lwu/dsra/andi/bnez, the first-block branch
// layout differs, and `g_Sce` is reloaded after the endMess call instead of in its delay slot.
#ifdef NONMATCHING
// FUNCTION: GAME 0x2C3678
void cScenario::move()
{
    if (Sys.m_mode != 0x20 && Getplayer__Fv()) {
        long f = m_flags48;
        if ((f >> 1) & 1) {
            if (((pl00 *)Getplayer__Fv())->m_x54A > 0) {
                m_flags48 &= ~2;
                Sys.m_flags &= 0xFFEFFFFF;
            }
        } else if (((pl00 *)Getplayer__Fv())->m_x54A <= 0) {
            m_flags48 |= 2;
            g_Sce->endMess();
            Sys.m_flags |= 0x100000;
        }
    }
    int *p = &D_00747A2C;
    if (*p >= 0 && !(p[0x58 / 4] & 0x8000000) && !((unsigned long)(unsigned)p[-2] >> 3 & 1) && !(p[0x4C / 4] & 0x10000) && !(p[1] & 1)) {
        long f = m_flags48;
        cTaskManager *tm = &m_task;
        if ((f >> 1) & 1) {
            if (m_cb->m_fn)
                m_cb->m_fn();
            func_002D5358(tm);
        } else {
            func_002C14F8(&g_SceAt);
            if (m_cb->m_fn)
                m_cb->m_fn();
            func_002D5358(tm);
            func_002C4E18(this);
        }
    }
}
#endif

// FUNCTION: GAME 0x2C4DD0
extern "C" void func_002C4DD0(cScenario *self, void *func, void *arg)
{
    self->m_roomExitFunc2 = func;
    self->m_roomExitArg2 = arg;
}

// FUNCTION: GAME 0x2C3968
extern "C" void func_002C3968(cScenario *self, int n)
{
    if (n >= 0)
        memset((char *)self + 0x54 + n * 8, 0, 8);
}

#ifdef NONMATCHING
// 0x2C4350: near-miss; original loads a message global via lui/lw (0x23A4 offset) and calls func_2AEDA0 with different branch layout
extern "C" int func_002C4350(cScenario *self)
{
    if (self->m_messNo != 0xFFFF)
        return Message->ckMessage(self->m_messNo);
    return 0;
}
#endif
