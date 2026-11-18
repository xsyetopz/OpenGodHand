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
