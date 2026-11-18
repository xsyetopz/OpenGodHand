struct OmA { char pad[0x2F4]; unsigned char b4, b5, b6; char p1[0x5B0 - 0x2F7]; unsigned w5B0; char p2[0x630 - 0x5B4]; int w630; char p3[0x660 - 0x634]; unsigned char b660; char p4; unsigned short h662; };
struct SaveT;
extern SaveT CoreSave; extern SaveT g_RoomSave;
extern "C" void func_001FB2D8(SaveT *, int);
extern "C" void func_002BECB0(SaveT *, long);
// FUNCTION: GAME 0x1C24E8
extern "C" void func_001C24E8(OmA *s) {
    s->b6 = 4;
    s->b660 = 1;
    long f = s->w5B0;
    s->b4 = 0;
    s->b5 = 0;
    s->w630 = 0;
    if (((f >> 5) & 1) == 0) {
        func_001FB2D8(&CoreSave, s->h662);
    } else {
        func_002BECB0(&g_RoomSave, *(long *)((char *)s + 0x538));
    }
}

struct OmB { char pad[0xF0]; int w0F0; char p1[0x560 - 0xF4]; int w560; char p2[0x5B0 - 0x564]; unsigned w5B0; };
extern char g_EmManage[];
extern "C" int canItemDrop__7cOmBase(OmB *);
extern "C" void CreateItem__9cEmManageRC4cVec6eObjIdUi(void *, int, int, int);
// FUNCTION: GAME 0x1B7BB8
extern "C" void func_001B7BB8(OmB *s) {
    long f = s->w5B0;
    long a = (f >> 4) & 1;
    long k = 1;
    if (a != k) {
        s->w5B0 = (int)s->w5B0 | 0x10;
        if (canItemDrop__7cOmBase((OmB *)s) == k) {
            if (s->w560 != 0xFFFF) {
                CreateItem__9cEmManageRC4cVec6eObjIdUi(g_EmManage, s->w0F0, s->w560, 0);
            } else {
                CreateItem__9cEmManageRC4cVec6eObjIdUi(g_EmManage, s->w0F0, 0xFFFF, 0);
            }
        }
    }
}

static inline int Gt(const int &v, int k) { return v > k; }
static inline char *Slot(char *o, int i)
{
    if (Gt(*(unsigned char *)(o + 0x2B4), i))
        return (*(char ***)(o + 0x278))[i];
    return 0;
}
// FUNCTION: GAME 0x1AD818
extern "C" void func_001AD818(char *self)
{
    if (Slot(self, 1))
        *(int *)(Slot(self, 1) + 0x104) = 0;
    if (Slot(self, 2))
        *(int *)(Slot(self, 2) + 0x104) = 0;
}

struct OmC { char pad[0x538]; long l538, l540; char p2[0x5B0 - 0x548]; unsigned w5B0; char p3[4]; unsigned w5B8; };
extern char g_CollScr[]; extern char g_CollSolidManage[];
extern int D_00747A84;
extern "C" void func_002BECB0(SaveT *, long);
extern "C" void func_001331B8(void *, long, int);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
// FUNCTION: GAME 0x1B7908
extern "C" void func_001B7908(OmC *s)
{
    long f = s->w5B8;
    if (((f >> 9) & 1) == 0 && (D_00747A84 & 0x1000000) == 0) {
        s->w5B8 = (int)s->w5B8 & -0x41;
    }
    func_002BECB0(&g_RoomSave, s->l538);
    func_001331B8(g_CollScr, s->l540, 0);
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, s);
    func_001B7BB8((OmB *)s);
    s->w5B0 = ((int)s->w5B0 | 2) & -9;
}

struct OmD { char pad[0x2F4]; unsigned char b4, b5, b6, b7; char p1[0x60E - 0x2F8]; short h60E; };
// FUNCTION: GAME 0x1C2C40
extern "C" void func_001C2C40(OmD *s)
{
    switch (s->b5) {
    case 0:
        (*(void (**)(void *))(*(char **)((char *)s + 0x214) + 0xAC))((char *)s + *(short *)(*(char **)((char *)s + 0x214) + 0xA8));
        (*(void (**)(void *))(*(char **)((char *)s + 0x214) + 0xBC))((char *)s + *(short *)(*(char **)((char *)s + 0x214) + 0xB8));
        s->h60E = 3;
        s->b5 = 1;
        s->b6 = 0;
        s->b7 = 0;
    case 1:
        if (--s->h60E <= 0) {
            s->b4 = 0;
            s->b5 = 0;
            s->b6 = 0;
            s->b7 = 0;
        }
    }
}

struct OmE { char pad[0x2FE]; unsigned short h2FE; char p1[0x5B0 - 0x300]; unsigned w5B0; char p2[4]; unsigned w5B8; };
// FUNCTION: GAME 0x1B79E0
extern "C" long func_001B79E0(OmE *s)
{
    long k = 1;
    long a = s->w5B0;
    if (((a >> 1) & 1) == k) return 0;
    long b = s->w5B8;
    if (((b >> 13) & 1) == k) return 0;
    if (canItemDrop__7cOmBase((OmB *)s) == k) {
        int h = s->h2FE;
        if (h < 0x3DA) return 1;
        if (h >= 0x3DE && h != 0x3EA) return 1;
    }
    long c = s->w5B8;
    return (c >> 8) & 1;
}

struct OmF { char pad[0x214]; const void *vt; char p1[0x650 - 0x218]; void *w650; int w654; char p2[0x68C - 0x658]; void *w68C; };
struct Hh { char pad[0x2FE]; unsigned short h2FE; };
extern char D_0042AA98[], g_DmgManage[], EspSys[];
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void effDataRelease__6espSys12eEffDataType(void *, int);
extern "C" void dieCommon__7cOmBase(void *);
extern "C" void func_001B6F38(void *, void *);
// FUNCTION: GAME 0x1C91B0
extern "C" void func_001C91B0(OmF *s, void *a1)
{
    s->vt = D_0042AA98;
    if (s->w650) {
        if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, s->w650)) {
            s->w650 = 0;
            s->w654 = -1;
        }
    }
    KillEffect__FPC4cObji13eEspEraseMode(s, 8, 2);
    if (((Hh *)s)->h2FE == 0x3AE)
        effDataRelease__6espSys12eEffDataType(EspSys, 0x206);
    if (s->w68C) {
        dieCommon__7cOmBase(s->w68C);
        s->w68C = 0;
    }
    func_001B6F38(s, a1);
}

class cFnY;
typedef void (cFnY::*cFnYPmf)();
class cFnY {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
};
extern char g_CollSolidManage[];
extern cFnYPmf D_003BDC98[];
extern cFnYPmf D_003BDE40[];
extern "C" int func_001B76B0(cFnY *);
extern "C" void func_001B76D8(cFnY *);
extern "C" void func_002A87E8(cFnY *, int);
extern "C" void func_001C0450(cFnY *);
extern "C" void ChkHit__21cCollisionSolidManageP8cGameObj(void *, void *);

// FUNCTION: GAME 0x1B0468
extern "C" void func_001B0468(cFnY *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDC98[self->type])();
        ChkHit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x1C0378
extern "C" void func_001C0378(cFnY *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDE40[self->type])();
        if (*((unsigned char *)self + 0x675) == 0)
            func_002A87E8(self, 0);
        func_001C0450(self);
        func_001B76D8(self);
    }
}

class cFnW;
typedef void (cFnW::*cFnWPmf)();
class cFnW {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
};
extern cFnWPmf D_003BDD60[];
extern "C" void calcParts__6cModel(void *);
extern "C" void calcWorldParts__6cModel(void *);
// FUNCTION: GAME 0x1B5A58
extern "C" void func_001B5A58(cFnW *self)
{
    if (func_001B76B0((cFnY *)self)) {
        (self->*D_003BDD60[self->type])();
        func_002A87E8((cFnY *)self, 0);
        calcParts__6cModel(self);
        calcWorldParts__6cModel(self);
        func_001B76D8((cFnY *)self);
    }
}

class cFnV;
typedef void (cFnV::*cFnVPmf)();
class cFnV {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    unsigned char type2;
};
extern cFnVPmf D_003BDA08[];
extern cFnVPmf D_003BDC60[];
// FUNCTION: GAME 0x1788A0
extern "C" void func_001788A0(cFnV *self)
{
    if (func_001B76B0((cFnY *)self)) {
        (self->*D_003BDA08[self->type])();
        func_002A87E8((cFnY *)self, 0);
        func_001B76D8((cFnY *)self);
        calcParts__6cModel(self);
        calcWorldParts__6cModel(self);
    }
}
// FUNCTION: GAME 0x1ADD20
extern "C" void func_001ADD20(cFnV *self)
{
    (self->*D_003BDC60[self->type2])();
    calcParts__6cModel(self);
    calcWorldParts__6cModel(self);
}

class cFnT;
typedef void (cFnT::*cFnTPmf)();
class cFnT {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    char p2[0x5A8 - 0x2F5];
    float spd;
    char p3[0x600 - 0x5AC];
    void *u600;
    char p4[4];
    void *u608;
};
extern char g_EmManage[];
extern float D_00747A14;
extern cFnTPmf D_003BDDA8[];
extern cFnTPmf D_003BDC50[];
extern "C" float GetSpeedRate__9cEmManage(void *);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
// FUNCTION: GAME 0x1B92F0
extern "C" void func_001B92F0(cFnT *self)
{
    if (func_001B76B0((cFnY *)self)) {
        if (self->u600) SetDamageCollActive__11cDamageUnitb(self->u600, 0);
        if (self->u608) SetDamageCollActive__11cDamageUnitb(self->u608, 0);
        self->spd = GetSpeedRate__9cEmManage(g_EmManage);
        (self->*D_003BDDA8[self->type])();
        func_001B76D8((cFnY *)self);
    }
}

// FUNCTION: GAME 0x1ADC38
extern "C" void func_001ADC38(cFnT *self)
{
    if (func_001B76B0((cFnY *)self)) {
        self->spd = GetSpeedRate__9cEmManage(g_EmManage) * D_00747A14;
        (self->*D_003BDC50[self->type])();
        func_002A87E8((cFnY *)self, 0);
        func_001B76D8((cFnY *)self);
    }
}
