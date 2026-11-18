struct V3 { float x, y, z; V3 &operator=(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; } };
class cFnQ;
typedef void (cFnQ::*cFnQPmf)();
class cFnQ {
public:
    virtual void v();
    char pad[0x2F4 - 4];
};
struct Q { void *vt; char p0[0xF0 - 4]; V3 *pv; char p1[0x100 - 0xF4]; V3 v100; };
extern cFnQPmf D_003BDD88[];
extern "C" int func_001B76B0(void *);
extern "C" void calcParts__6cModel(void *);
// FUNCTION: GAME 0x1B8228
extern "C" void func_001B8228(cFnQ *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDD88[*((unsigned char *)self + 0x2F4)])();
        calcParts__6cModel(self);
        *(V3 *)((char *)self + 0x490) = *((Q *)self)->pv;
        *(V3 *)((char *)self + 0x5D0) = ((Q *)self)->v100;
    }
}

class cFnO;
typedef void (cFnO::*cFnOPmf)();
class cFnO {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    char p2[0x5A8 - 0x2F5];
    float spd;
};
extern char g_EmManage[];
extern char g_CollSolidManage[];
extern char g_DmgManage[];
extern cFnOPmf D_003BDC68[];
extern cFnOPmf D_003BDCC0[];
extern "C" float GetSpeedRate__9cEmManage(void *);
extern "C" void func_001B76D8(void *);
extern "C" void func_002A87E8(void *, int);
extern "C" void ScrollTexture__6cModelf(void *, float);
extern "C" void ChkHit__21cCollisionSolidManageP8cGameObj(void *, void *);
extern "C" int CkHitStop__13cDamageManage(void *);
extern "C" void func_001B1860(void *);
extern "C" void func_001B1938(void *);
extern "C" void func_001B1630(void *);
// FUNCTION: GAME 0x1AEDB0
extern "C" void func_001AEDB0(cFnO *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDC68[self->type])();
        float r = GetSpeedRate__9cEmManage(g_EmManage);
        self->spd = r;
        ScrollTexture__6cModelf(self, r);
        ChkHit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}
// FUNCTION: GAME 0x1B0F70
extern "C" void func_001B0F70(cFnO *self)
{
    if (func_001B76B0(self)) {
        if (!CkHitStop__13cDamageManage(g_DmgManage)) {
            func_001B1860(self);
            self->spd = GetSpeedRate__9cEmManage(g_EmManage);
            (self->*D_003BDCC0[self->type])();
            func_001B1938(self);
            func_001B1630(self);
            func_001B76D8(self);
        }
    }
}

class cFnN;
typedef void (cFnN::*cFnNPmf)();
class cFnN {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char b4, b5, b6, b7;
    char p1[0x520 - 0x2F8];
    int w520;
};
struct TabN1 { cFnNPmf p[1]; };
struct TabN3 { cFnNPmf p[3]; };
struct DU { char p[0x46]; short h46; char p2[4]; int w4C; };
struct V3N { float x, y, z; V3N &operator=(const V3N &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; } };
struct QN { void *vt; char p0[0xF0 - 4]; V3N *pv; char p1[0x100 - 0xF4]; V3N v100; };
extern const char D_00429DD0[], D_00429278[];
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *, void *);
// FUNCTION: GAME 0x1C7E30
extern "C" void func_001C7E30(cFnN *self)
{
    if (func_001B76B0(self)) {
        DU *u = *(DU **)((char *)self + 0x600);
        if (u) {
            u->h46 = 0;
            (*(DU **)((char *)self + 0x600))->w4C = 0;
            SetDamageCollActive__11cDamageUnitb(*(void **)((char *)self + 0x600), 0);
        }
        TabN1 t = *(const TabN1 *)D_00429DD0;
        (self->*t.p[self->b4])();
        calcParts__6cModel(self);
        *(V3N *)((char *)self + 0x490) = *((QN *)self)->pv;
        *(V3N *)((char *)self + 0x5D0) = ((QN *)self)->v100;
    }
}
// FUNCTION: GAME 0x1BC1C8
extern "C" void func_001BC1C8(cFnN *self)
{
    TabN3 t = *(const TabN3 *)D_00429278;
    (self->*t.p[self->b5])();
    if (checkDamage__7cOmBaseP11cDamageTake(self, *(void **)((char *)self + 0x600)) == 1) {
        if (*(short *)((char *)self + 0x54A) <= 0) {
            self->b4 = 2;
            self->b6 = 0;
            *(unsigned *)((char *)self + 0x5B0) |= 1;
            self->b7 = 0;
            self->b5 = 0;
        } else {
            self->b4 = 1;
            self->b5 = 0;
            self->b6 = 0;
            self->b7 = 0;
        }
    }
}

class cFnL;
typedef void (cFnL::*cFnLPmf)();
class cFnL {
public:
    virtual void v();
    char pad[0x4F0];
    int w4F0;
};
struct TabL2 { cFnLPmf p[2]; };
extern const char D_0041DBA0[];
// FUNCTION: GAME 0x13B388
extern "C" void func_0013B388(cFnL *self)
{
    TabL2 t = *(const TabL2 *)D_0041DBA0;
    (self->*t.p[self->w4F0])();
}
typedef unsigned long DmaU64;
typedef unsigned int DmaU32;
struct DmaTag { DmaU64 a, b; };
struct DmaChain { DmaU32 base; char pad[0x1C]; DmaU32 n; };
// FUNCTION: GAME 0x14FE78
extern "C" void func_0014FE78(DmaChain *self)
{
    DmaU32 i;
    DmaTag *q = (DmaTag *)(self->base | 0x20000000);
    for (i = 0; i < self->n - 1; i++, q++) {
        q->b = 0;
        q->a = (DmaU64)(((DmaU32)q & 0xFFFFFFF) + 0x10) << 32 | 0x20000000;
    }
    q->b = 0;
    q->a = (DmaU64)((DmaU32)self + 0x10) << 32 | 0x20000000;
    ((DmaU64 *)self)[2] = 0x70000000;
    ((DmaU64 *)self)[3] = 0;
}
extern unsigned short D_003BD70C;
extern const char D_003BD6F8[];
extern "C" void func_001450A0(char *self, void *src, short n);
extern "C" void func_00145100(char *self, void *src, short n);
extern "C" void func_001451A0(char *self, void *src, short n);
extern "C" void func_00145160(char *self, const void *src);
// FUNCTION: GAME 0x144FD8
extern "C" void func_00144FD8(char *self, void *a, void *b, void *c, short n, unsigned short k)
{
    func_001450A0(self, b, n);
    func_00145100(self, a, n);
    func_001451A0(self, c, n);
    func_00145160(self, D_003BD6F8);
    int i = k - 1;
    if (i < 0)
        *(short *)(self + 0x422) = n - 1;
    else if (i >= 0x24)
        *(short *)(self + 0x422) = 0x23;
    else
        *(short *)(self + 0x422) = i;
    *(unsigned short *)(self + 0x4D0) = D_003BD70C;
}
extern char CoreSave[];
extern "C" void restartAnim__7cIDBase(void *self);
extern "C" int getGold__9cCoreSave(void *);
extern "C" void initAddGold__9cCoreSave(void *);
extern "C" char *getIDWork__7cIDBasei(char *, int);
// FUNCTION: GAME 0x143598
extern "C" void func_00143598(char *self)
{
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    *(int *)(self + 0x90) = getGold__9cCoreSave(CoreSave);
    unsigned short i;
    char **arr = (char **)(self + 0x94);
    for (i = 0; i < 4; i++)
        *(char **)((char *)arr + (i << 2)) = getIDWork__7cIDBasei(self, i);
    char *b;
    for (i = 0, b = self + 0x1B0; i < 0x10; i++)
        b[i] = 0;
    *(unsigned *)(*(char **)(self + 0x9C) + 0x2C) |= 0x8000000;
    *(int *)(*(char **)(self + 0x94) + 0x84) = *(int *)(self + 0x90);
    initAddGold__9cCoreSave(CoreSave);
    self[0x1C0] = 0;
}
