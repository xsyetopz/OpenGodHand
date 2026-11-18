#include "game/pl00.h"
#include "game/cMessage.h"

extern "C" void func_001CF8B0(void *p);
extern "C" int func_0010B698(pl00 *p);
class cEmManage {
public:
    int CkPlCatched();
};
extern cEmManage g_EmManage;
extern "C" void func_001269E0(pl00 *p, unsigned int a, int b);

class cPlCamera {
public:
    void setCamUpdate(unsigned int a);
};
class cCamManager : public cPlCamera {
public:
    void setPlCamera(unsigned char v);
    int isCk_CamClass(unsigned int a);
};
extern cCamManager CamManager;

// FUNCTION: GAME 0x10BD08
void pl00::SetCannonReflect(unsigned char v)
{
    m_modeA = 6;
    m_modeB = 0;
    m_modeC = 2;
    m_modeD = v;
}

// FUNCTION: GAME 0x124FC8
int pl00::ckMotionCam()
{
    if (m_unk15F4 & 2)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x12AC60
void pl00::DiscardWeapon()
{
    if (m_unk698) {
        func_001CF8B0(m_unk698);
        m_unk698 = 0;
    }
}

#ifdef NONMATCHING
// 0x12BAB8: switch form is 5 words off: original returns via slti/beqz+bltz range check back to a shared 'return 0'
int pl00::CkSubScreen()
{
    if (m_modeA)
        return 0;
    switch (m_modeB) {
    case 0: case 1: case 2: case 3:
        return 1;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x12BF50
int pl00::ckAtkActBtnEnable()
{
    if (m_unk6A0)
        return 0;
    if (m_unk54A <= 0)
        return 0;
    if (func_0010B698(this))
        return 0;
    if (g_EmManage.CkPlCatched())
        return 0;
    return ((unsigned char *)&m_unk15F4)[1] & 1;
}

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
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CD90
void pl00::setIgnition(const cVec &pos, float v)
{
    if (&m_unk660 != &pos)
        m_unk660 = pos;
    m_modeA = 0;
    m_modeB = 0x34;
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CDD0
void pl00::setPyramidIn()
{
    m_modeA = 0;
    m_modeB = 0x36;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x12CE20
void pl00::lookCliff(const cVec &pos, float v)
{
    if (&m_unk660 != &pos)
        m_unk660 = pos;
    m_modeA = 0;
    m_modeB = 0x35;
    m_unk670 = v;
    m_modeC = 0;
    m_modeD = 0;
}

// FUNCTION: GAME 0x10B980
void pl00::SubscreenMotSet(unsigned int a)
{
    func_001269E0(this, a, 1);
    m_modeA = 5;
    m_modeB = 0;
    m_modeC = 2;
    m_modeD = 0;
}

// FUNCTION: GAME 0x10BCC0
void pl00::CannonGameMode(unsigned int on)
{
    if (on) {
        m_modeA = 6;
        m_unk54C = 5.0f;
        m_modeB = 0;
        m_modeC = 0;
        m_modeD = 0;
    } else {
        reset();
    }
}

// FUNCTION: GAME 0x124F60
void pl00::clearMotionCam(unsigned int a, unsigned int b)
{
    if (!(b & 1)) {
        if (!(m_unk15F4 & 2))
            return;
        m_unk15F4 &= ~2;
    }
    cPlCamera *c = &CamManager;
    if (c)
        c->setCamUpdate(a);
    CamManager.setPlCamera(0);
}

class cObjBase {
public:
    void R0_scenario();
    void KageDraw();
};

// FUNCTION: GAME 0x10B5B8
extern "C" int func_0010B5B8(pl00 *self)
{
    return self->m_modeA == 1;
}

// FUNCTION: GAME 0x10B5C8
extern "C" int func_0010B5C8(pl00 *self)
{
    if (self->m_modeA)
        return 0;
    return self->m_modeB == 6;
}

// FUNCTION: GAME 0x10B5F0
extern "C" int func_0010B5F0(pl00 *self)
{
    if (self->m_modeA)
        return 0;
    if (self->m_modeB != 0 && self->m_modeB != 10)
        return 0;
    return 1;
}

// FUNCTION: GAME 0x10B620
extern "C" int func_0010B620(pl00 *self)
{
    if (self->m_modeA)
        return 0;
    return self->m_modeB == 3;
}

// FUNCTION: GAME 0x10B648
extern "C" int func_0010B648(pl00 *self)
{
    if (self->m_modeA)
        return 0;
    return self->m_modeB == 0x11;
}

// FUNCTION: GAME 0x10B670
extern "C" int func_0010B670(pl00 *self)
{
    if (self->m_modeA)
        return 0;
    return self->m_modeB == 7;
}

// FUNCTION: GAME 0x10B698
extern "C" int func_0010B698(pl00 *self)
{
    if (self->m_unk15F4 & 0x400000)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x10B760
extern "C" void func_0010B760(cObjBase *self)
{
    self->R0_scenario();
}

// FUNCTION: GAME 0x10BE10
extern "C" void func_0010BE10(pl00 *self)
{
    self->m_modeA = 0;
}

// FUNCTION: GAME 0x124E58
extern "C" void func_00124E58(pl00 *self)
{
    self->m_unk640 = 0;
    self->m_unk648 = 0;
}

// FUNCTION: GAME 0x12BBE0
extern "C" void func_0012BBE0(cObjBase *self)
{
    self->KageDraw();
}

// FUNCTION: GAME 0x12C530
extern "C" int func_0012C530(pl00 *self)
{
    if (self->m_unk15F4 & 0x1000)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x12CA48
extern "C" int func_0012CA48(pl00 *self)
{
    if (self->m_unk15F4 & 0x100000)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x12CED8
extern "C" int func_0012CED8(pl00 *self)
{
    if (self->m_unk15F4 & 0x1000000)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x12CEF0
extern "C" unsigned long func_0012CEF0(pl00 *self)
{
    unsigned long v = ((unsigned char *)&self->m_unk15F4)[0];
    return v >> 7;
}

extern const unsigned short D_00747A50;
class cSceAtManager {
public:
    char _pad[0x68];
    void *m_unk68;
    void *m_unk6C;
};
extern cSceAtManager g_SceAt;
extern "C" int func_002C2568(cSceAtManager *m, cVec *p, int a);
extern "C" void func_002DBE98();

#ifdef NONMATCHING
// 0x12C758: 21 words differ; original tests m_unk698 with beql into the m_unk6A0 test and an explicit 'return 0' branch, mine uses bnez
extern "C" int func_0012C758(pl00 *self)
{
    if (D_00747A50 != 0x608)
        return 0;
    if (self->m_unk698)
        return 0;
    else if (!self->m_unk6A0) {
        if (func_002C2568(&g_SceAt, self->m_pos, 0) == 1) {
            func_002DBE98();
            return 1;
        }
    }
    return 0;
}
#endif

class cEm00 {
public:
    int ckDown();
    char _pad[0x2FE];
    unsigned short m_unk2FE;
};

#ifdef NONMATCHING
// 0x124FD8: original keeps both range tests as unfolded slti pairs (a2 bool temps); gcc folds them to addiu+sltiu here
extern "C" int func_00124FD8(pl00 *self, cEm00 *em)
{
    int v = em->m_unk2FE;
    bool a = v >= 0x200 && v < 0x300;
    if (!a)
        return 0;
    bool b = v >= 0x2A0 && v < 0x300;
    if (b)
        return 0;
    return em->ckDown() != 0;
}
#endif

// FUNCTION: GAME 0x12C748
extern "C" int func_0012C748(pl00 *self)
{
    if (self->m_unk5FC)
        return 1;
    return 0;
}

extern "C" void func_00100FB8(int a, int b);

// FUNCTION: GAME 0x101E98
extern "C" void func_00101E98()
{
    func_00100FB8(1, 0xFFFF);
}

class cActionButtonUnit {
public:
    void setOk();
};

// FUNCTION: GAME 0x1267F8
extern "C" void func_001267F8(pl00 *self)
{
    if (self->m_unk165C)
        ((cActionButtonUnit *)self->m_unk165C)->setOk();
}

class cOmWeapon {
public:
    void setFall();
};

// FUNCTION: GAME 0x12AC28
extern "C" void func_0012AC28(pl00 *self)
{
    if (self->m_unk698) {
        ((cOmWeapon *)self->m_unk698)->setFall();
        self->m_unk698 = 0;
    }
}

// FUNCTION: GAME 0x1268F0
extern "C" void func_001268F0(pl00 *self)
{
    for (unsigned i = 0; i < 5; i++)
        self->m_unk1644[i] = 0;
}

enum eEffDataType { EFF_DATA_0 = 0 };
enum eEffId { EFF_61 = 0x61, EFF_79 = 0x79 };
enum eEspEraseMode { ESP_ERASE_2 = 2 };
void KillEffect(eEffDataType type, eEffId id, eEspEraseMode mode);

struct cEffObj {
    char _pad[0x564];
    int m_unk564;
};

// FUNCTION: GAME 0x12CC00
extern "C" void func_0012CC00(pl00 *self)
{
    if (self->m_unk644 && !(self->m_unk15F4 & 0x800000)) {
        if (self->m_unk644->m_unk564 == 0x26A)
            KillEffect(EFF_DATA_0, EFF_79, ESP_ERASE_2);
        KillEffect(EFF_DATA_0, EFF_61, ESP_ERASE_2);
        self->m_unk644 = 0;
    }
}

struct cFlagObj {
    char _pad[0x2F0];
    unsigned int m_flags;
};

// FUNCTION: GAME 0x12CE60
extern "C" void func_0012CE60(pl00 *self, const cVec &v)
{
    *self->m_pos = v;
    self->m_unk490 = v;
    self->m_unkB0.x = v.x;
    self->m_unkB0.y = v.y;
    self->m_unkB0.z = v.z;
    if (self->m_unk68C)
        self->m_unk68C->m_flags |= 1;
}

struct cVTab {
    char _pad[0x68];
    short m_delta;
    short m_pad;
    const cVec *(*m_fn)(void *);
};
struct cVObj {
    char _pad[0x214];
    cVTab *m_vtab;
};
class cGameObj {
public:
    void SetTgtTurn(const cVec &v, float a);
    int isClip() const;
};

// FUNCTION: GAME 0x124E68
extern "C" void func_00124E68(pl00 *self, float a)
{
    cVObj *o = self->m_unk640;
    if (o)
        ((cGameObj *)self)->SetTgtTurn(*o->m_vtab->m_fn((char *)o + o->m_vtab->m_delta), a);
}

struct cHolder {
    struct pl00 *m_first;
};

static inline pl00 *getHolderObj(pl00 *self, const unsigned int &i)
{
    if (i)
        return self->m_unk278->m_first;
    return 0;
}

#ifdef NONMATCHING
// 0x12CA60: original spills the index byte to 0(sp) (sp frame 0x10, address-taken temp in an inlined helper); mine has no frame
extern "C" int func_0012CA60(pl00 *self)
{
    if (self->m_unk15F4 & 0x200000)
        return 1;
    unsigned int idx = self->m_unk2B4;
    pl00 *o = getHolderObj(self, idx);
    if (!o)
        return 0;
    if (o->m_pos->y < self->m_pos->y + 0.8f)
        return 1;
    return 0;
}
#endif

// FUNCTION: GAME 0x10A408
extern "C" void func_0010A408(pl00 *self, int a, int b, int c, int d, short e)
{
    self->m_unk1660[2] = a;
    self->m_unk1660[0] = b;
    self->m_unk1660[4] = c;
    self->m_unk1660[6] = d;
    self->m_unk1680[0] = e;
}

// FUNCTION: GAME 0x10A420
extern "C" void func_0010A420(pl00 *self, int a, int b, int c, int d, short e)
{
    self->m_unk1660[3] = a;
    self->m_unk1660[1] = b;
    self->m_unk1660[5] = c;
    self->m_unk1660[7] = d;
    self->m_unk1680[1] = e;
}

struct sD_004615F0 {
    float x, y, z, w;
};
extern sD_004615F0 D_004615F0;

// FUNCTION: GAME 0x107DE0
extern "C" void func_00107DE0(int a, int b)
{
    if (b == 0xFFFF && a) {
        D_004615F0.x = 0;
        D_004615F0.w = 1.0f;
        D_004615F0.z = 0;
        D_004615F0.y = 0;
    }
}

#ifdef NONMATCHING
// 0x123908: 11 words differ (original has 0x20 frame, s0 = &CamManager, tail call to func_138F88)
extern "C" int func_00123908()
{
    return CamManager.isCk_CamClass(1);
}
#endif

class cModel {
public:
    int isClip() const;
};
extern int D_00747A80;

// FUNCTION: GAME 0x1020F0
extern "C" int func_001020F0(cModel *self)
{
    if (D_00747A80 < 0)
        return 1;
    return self->isClip() != 0;
}

void capVu0Length(const float *p);

// FUNCTION: GAME 0x101E28
extern "C" void func_00101E28(const float *p)
{
    capVu0Length(p);
}

// FUNCTION: GAME 0x1004C8
extern "C" int func_001004C8(cModel *self)
{
    if (D_00747A80 & 0x200000)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x107F20
extern "C" int func_00107F20(cGameObj *self)
{
    if (D_00747A80 < 0)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x100318
extern "C" void func_00100318()
{
}

struct cDtorObj {
    char _pad[0x214];
    void *m_vptr;
};
extern char D_0041B730[];
extern char D_0041B6A0[];
extern "C" void _$_7cPlBase(cDtorObj *);
extern "C" void _$_8cObjBase(cDtorObj *);

// FUNCTION: GAME 0x102128
extern "C" void func_00102128(cDtorObj *self)
{
    self->m_vptr = D_0041B730;
    _$_7cPlBase(self);
}

// FUNCTION: GAME 0x100508
extern "C" void func_00100508(cDtorObj *self)
{
    self->m_vptr = D_0041B6A0;
    _$_8cObjBase(self);
}

extern int D_005FEAC0;

// FUNCTION: GAME 0x2C23E0
extern "C" int func_002C23E0(int a)
{
    D_005FEAC0 = a;
    return 0;
}

// FUNCTION: GAME 0x2C3040
extern "C" void func_002C3040(int, unsigned *a1, unsigned *a2)
{
    *a2 = *a1;
    *a1 = (unsigned)a2 | 0x80000000;
}

// FUNCTION: GAME 0x2C23F8
extern "C" int func_002C23F8(char *a)
{
    g_SceAt.m_unk68 = a + 0x5C;
    g_SceAt.m_unk6C = a + 0x7C;
    return 0;
}

extern "C" void func_002AE740(int);
extern "C" void func_002AE7F0(int);

// FUNCTION: GAME 0x2C09E8
extern "C" void func_002C09E8()
{
    func_002AE740(2);
}

// FUNCTION: GAME 0x2C0A08
extern "C" void func_002C0A08()
{
    func_002AE7F0(2);
}

extern "C" void func_002D56A8(char *);
extern "C" void func_002D50E8(char *, int, int, int);
extern "C" void func_002D51F0(char *);
struct cSubS {
    char _pad[0x14];
    char m_unk14;
};

// FUNCTION: GAME 0x2C32C0
extern "C" void func_002C32C0(cSubS *s)
{
    func_002D56A8((char *)s + 0x1C);
    s->m_unk14 = 0;
}

// FUNCTION: GAME 0x2C3280
extern "C" void func_002C3280(cSubS *s)
{
    char *p = (char *)s + 0x1C;
    func_002D50E8(p, 0x10, 0x1800, 0x30);
    func_002D51F0(p);
}

struct cBitSet {
    char _pad[0x68];
    unsigned *m_unk68;
};

// FUNCTION: GAME 0x2C3190
extern "C" int func_002C3190(cBitSet *b, unsigned char n)
{
    int r = 1;
    unsigned *p = b->m_unk68;
    if (p) {
        if (p[n >> 5] & (0x80000000u >> (n & 31)))
            r = 0;
    }
    return r;
}

struct cMsgHolder {
    char _pad[0x112];
    unsigned short m_unk112;
};
extern cMessage *Message;

// FUNCTION: GAME 0x2C4350
extern "C" int func_002C4350(cMsgHolder *m)
{
    if (m->m_unk112 == 0xFFFF)
        return 0;
    return Message->ckMessage(m->m_unk112);
}

struct sIdPair {
    short m_id0;
    short m_id1;
    int m_unk4;
};

// FUNCTION: GAME 0x2CC4A0
extern "C" void func_002CC4A0(sIdPair *a)
{
    a->m_unk4 = 0;
    a->m_id1 = -1;
    a->m_id0 = -1;
}

struct sTblBase {
    char _pad[0x34];
    char *m_unk34;
};

// FUNCTION: GAME 0x2CC4C8
extern "C" char *func_002CC4C8(sTblBase *b, int i)
{
    return b->m_unk34 + i * 0x50;
}

struct sFlagWord {
    int m_unk0;
    int m_unk4;
    int _pad8[3];
    int m_unk14;
};

// FUNCTION: GAME 0x2CDA38
extern "C" int func_002CDA38(sFlagWord *c)
{
    return c->m_unk14 != 0;
}

// FUNCTION: GAME 0x2CFC98
extern "C" void func_002CFC98(sFlagWord *c)
{
    if (c->m_unk0)
        c->m_unk0 = 3;
}

// FUNCTION: GAME 0x2CFD38
extern "C" int func_002CFD38(sFlagWord *c, int m)
{
    return (c->m_unk4 & m) == m;
}

struct sHasPtrC {
    char _pad[0xC];
    void *m_unkC;
};
extern "C" void func_002CD7C8(void *);
extern "C" void func_002CD890(void *);

// FUNCTION: GAME 0x2CFE28
extern "C" void func_002CFE28(sHasPtrC *d)
{
    func_002CD7C8(d->m_unkC);
}

// FUNCTION: GAME 0x2CFE48
extern "C" void func_002CFE48(sHasPtrC *d)
{
    func_002CD890(d->m_unkC);
}

extern "C" int func_00375128(int);
struct sHasShort2C {
    char _pad[0x2C];
    short m_unk2C;
};

// FUNCTION: GAME 0x2CF868
extern "C" int func_002CF868(sHasShort2C *e)
{
    return func_00375128(e->m_unk2C) == 0;
}

extern "C" void func_00325DC0(int);

// FUNCTION: GAME 0x2CA690
extern "C" void func_002CA690()
{
    func_00325DC0(0);
}

struct sSndNode {
    char _pad[0x84];
    sSndNode *m_unk84;
    sSndNode *m_unk88;
};
struct sSndList {
    char _pad[0x18];
    sSndNode *m_unk18;
};
extern sSndList Snd;

#ifdef NONMATCHING
// 0x2CC5C0: 4 words differ; original uses bnel with the m84 store in the delay slot, mine uses bnez plus nop
extern "C" void func_002CC5C0(sSndNode *n)
{
    n->m_unk88 = Snd.m_unk18;
    if (!Snd.m_unk18) {
        Snd.m_unk18 = n;
        return;
    }
    Snd.m_unk18->m_unk84 = n;
}
#endif

struct sClr {
    char m0;
    char m1;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

#ifdef NONMATCHING
// 0x2CFF30: 8 words differ; mine hoists the m18 store above m20 and the byte stores
extern "C" sClr *func_002CFF30(sClr *f)
{
    f->m20 = -1;
    f->m0 = 0;
    f->m1 = 0;
    f->m4 = 0;
    f->mC = 0;
    f->m10 = 0;
    f->m14 = 0;
    f->m18 = -1;
    return f;
}
#endif
