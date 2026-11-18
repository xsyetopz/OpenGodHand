// Small unnamed functions in 0x2E0000-0x2EFFFF, placed next to ESLib.
#include "game/ESLibFn.h"

extern "C" const char D_0044E300[];

// FUNCTION: GAME 0x2EBC50
extern "C" void func_002EBC50(EsObj *s, int a1)
{
    EsObjD *self = (EsObjD *)s;
    self->vt = D_0044E960;
    FREE_BLOCK(self->p2CC);
    FREE_BLOCK(self->p2D0);
    FREE_BLOCK(self->p2C4);
    FREE_BLOCK(self->p2C8);
    FREE_BLOCK(self->p2BC);
    FREE_BLOCK(self->p2C0);
    func_002FBE28(self, a1);
}

// FUNCTION: GAME 0x2E3500
extern "C" void func_002E3500(EsObjE *self, int a1)
{
    self->vt = D_0044E300;
    FREE_BLOCK(self->p330);
    FREE_BLOCK(self->p334);
    FREE_BLOCK(self->p338);
    FREE_BLOCK(self->p33C);
    FREE_BLOCK(self->p324);
    FREE_BLOCK(self->p30C);
    func_002EBC50(self, a1);
}

// FUNCTION: GAME 0x2E8168
extern "C" void func_002E8168(EsObjF *self, float step)
{
    D_0061B540[0] = 0;
    float f = 0.0f;
    for (unsigned int i = 1; i < self->n; i++) {
        if ((i & 1) == 0) {
            D_0061B540[i] = (int)-f;
        } else {
            D_0061B540[i] = (int)f;
            f += step;
        }
    }
}

// 0x2E2800 NEAR-MISS: ~20 words differ; original reloads flags after the byte store and shares the epilogue
#ifdef NONMATCHING
extern "C" void func_002E2800(EsObjG *self)
{
    func_002FBED0(self);
    if (!(*(unsigned char *)&self->flags & 1)) {
        switch ((unsigned int)self->i2C4) {
        case 0:
            func_002E2C50(self);
            break;
        case 1:
            func_002E2D40(self);
            break;
        case 2:
            func_002E2E00(self);
            break;
        default:
            func_002FBE50(self);
            break;
        }
    } else if (self->flags & 4) {
        self->b24C = self->b2D5 ? self->b2D5 : 30;
        self->flags &= ~4;
    }
}
#endif

// FUNCTION: GAME 0x2EA9F0
extern "C" void func_002EA9F0(EsObjJ *self)
{
    self->f2B8 += self->f2C0;
    self->f2BC += self->f2C4;
    if (self->f2B8 > 2.0f)
        self->f2B8 -= 2.0f;
    if (self->f2BC > 2.0f)
        self->f2BC -= 2.0f;
    if (self->f2B8 < -2.0f)
        self->f2B8 += 2.0f;
    if (self->f2BC < -2.0f)
        self->f2BC += 2.0f;
    func_002FBED0(self);
}

// 0x2EA908 NEAR-MISS: 4 words differ; register choice $a2 vs $v1 for s->b18F
#ifdef NONMATCHING
extern "C" int func_002EA908(EsObjK *self)
{
    self->i2B8 = 0;
    self->i2BC = 0;
    EsSrcK *s = self->src;
    self->f2C0 = s->f13C * 0.1f;
    self->f2C4 = s->f140 * 0.1f;
    self->i2C8 = s->b18C + 2;
    self->f2B0 = (float)s->b18D * 0.1f + 1.0f;
    self->f2B4 = (float)s->b18E * 0.1f + 1.0f;
    unsigned int k = s->b18F;
    self->i2CC = k;
    if (k >= 4) {
        func_002D9F68(self, D_0044E808);
        self->i2CC = 0;
        return 0;
    }
    if (k != 0 && self->i2C8 == 2)
        self->i2C8 = 3;
    return 1;
}
#endif

// FUNCTION: GAME 0x2E8318
extern "C" void func_002E8318(EsObjL *self)
{
    if (self->flags & 0x800000)
        return;
    func_002E9808(self, 4, 12, 2);
    func_002E9808(self, 4, 12, 1);
    func_002E9808(self, 4, 12, 0);
    func_002E8B38(self, 4, 11);
    func_002E83D8(10, 0x3B00, 0x3A00, 0, 1);
    func_002E83D8(10, 0x3A00, 0x3900, 1, 0);
    func_002E8EE8(self, 4, 9, 1);
}

// ---- 0x2F0000 range ----
// FUNCTION: GAME 0x2F0058
extern "C" void func_002F0058() {}
// FUNCTION: GAME 0x2F1750
extern "C" void func_002F1750() {}
// FUNCTION: GAME 0x2F4230
extern "C" void func_002F4230() {}
// FUNCTION: GAME 0x2F4B28
extern "C" void func_002F4B28() {}

// FUNCTION: GAME 0x2F00B8
VT_SET(2F00B8, D_0044EAB8, func_002FBE28)
// FUNCTION: GAME 0x2F11C8
VT_SET(2F11C8, D_0044EB70, func_002FBE28)
// FUNCTION: GAME 0x2F1B18
VT_SET(2F1B18, D_0044EC68, func_002FBE28)
// FUNCTION: GAME 0x2F2FF8
VT_SET(2F2FF8, D_0044EF08, func_002FBE28)
// FUNCTION: GAME 0x2F3E18
VT_SET(2F3E18, D_0044EFA0, func_002FBE28)
// FUNCTION: GAME 0x2F3E40
VT_SET(2F3E40, D_0044F078, func_002FBE28)

#define VT_NEW(addr, vtsym)                                 \
    extern "C" const char vtsym[];                          \
    extern "C" EsObj *func_00##addr(EsObj *self)            \
    {                                                       \
        if (self) {                                         \
            func_002FBCC8(self);                            \
            self->vt = vtsym;                               \
        }                                                   \
        return self;                                        \
    }
// FUNCTION: GAME 0x2F4DA0
VT_SET(2F4DA0, D_0044F270, func_002FBE28)
// FUNCTION: GAME 0x2F5328
VT_SET(2F5328, D_0044F308, func_002FBE28)
// FUNCTION: GAME 0x2F5560
VT_SET(2F5560, D_0044F3A0, func_002FBE28)
// FUNCTION: GAME 0x2F6CD0
VT_SET(2F6CD0, D_0044F598, func_002FBE28)
// FUNCTION: GAME 0x2F70E8
VT_SET(2F70E8, D_0044F630, func_002FBE28)
// FUNCTION: GAME 0x2F6230
VT_SET(2F6230, D_0044F4F8, CALL1_EBC50)
// FUNCTION: GAME 0x2F7178
VT_SET(2F7178, D_0044F6D8, CALL1_EBC50)
// FUNCTION: GAME 0x2FFCC8
VT_NEW(2FFCC8, D_0044EAB8)
// FUNCTION: GAME 0x2FFD08
VT_NEW(2FFD08, D_0044EB70)
// FUNCTION: GAME 0x2FFD48
VT_NEW(2FFD48, D_0044EC68)

// FUNCTION: GAME 0x2FFC88
VT_NEW(2FFC88, D_0044EA10)
// FUNCTION: GAME 0x2FFE10
VT_NEW(2FFE10, D_0044EFA0)
// FUNCTION: GAME 0x2FFE50
VT_NEW(2FFE50, D_0044F078)
// FUNCTION: GAME 0x2FFE90
VT_NEW(2FFE90, D_0044F1C8)
// FUNCTION: GAME 0x2FFED0
VT_NEW(2FFED0, D_0044F270)
// FUNCTION: GAME 0x2FFF50
VT_NEW(2FFF50, D_0044F3A0)
// FUNCTION: GAME 0x2FFC20
VT_NEW(2FFC20, D_0044E820)
struct EsObjZ : EsObj {
    char pad1[0x2B0 - 0xF4];
    int i2B0;
};
extern "C" const char D_0044EE38[];
// FUNCTION: GAME 0x2FFD88
extern "C" EsObj *func_002FFD88(EsObjZ *self)
{
    if (self) {
        func_002FBCC8(self);
        self->i2B0 = 0;
        self->vt = D_0044EE38;
    }
    return self;
}

// FUNCTION: GAME 0x2D9E30
DTOR_CLONE(func_002D9E30, D_0044D388, 0)
// FUNCTION: GAME 0x31F330
DTOR_CLONE(func_0031F330, D_00451288, 0)
// FUNCTION: GAME 0x31F3C8
DTOR_CLONE(func_0031F3C8, D_00451288, 0)
// FUNCTION: GAME 0x321818
DTOR_CLONE(func_00321818, D_00451288, 0)
// FUNCTION: GAME 0x3218B0
DTOR_CLONE(func_003218B0, D_00451288, 0)
// FUNCTION: GAME 0x1337E0
DTOR_CLONE(_$_21cCollisionScrollSolid, D_0041D5A8, 0x5C)
// FUNCTION: GAME 0x1339C0
DTOR_CLONE(_$_15cCollisionSolid, D_0041D808, 0x30)
// FUNCTION: GAME 0x2D5C38
DTOR_CLONE(func_002D5C38, D_0044D1C8, 0x30)

// 0x173AD8 near-miss (cluster of 6 identical 0x1D4 units; no COP2). See diff note below.
#ifdef NONMATCHING
#include "game/cVec.h"
#include "game/cObj.h"
#include "game/cDamageUnit.h"
#include "game/cDamageManage.h"

struct cV4 : cVec { float w; };

extern "C" {
void func_001B6FB8(void *);
void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
}
extern cDamageManage g_DmgManage;

class Obj173AD8 : public cObj {
public:
    char _pad2F8[0x548 - 0x2F8];
    short m_s548;
    short m_s54A;
    char _pad54C[0x650 - 0x54C];
    cDamageUnit *m_take;
};

// DRAFT: GAME 0x173AD8
// Diff: prologue matches through 0x173BB4 (frame 0x90 vs 0x80); the rest differs. The original keeps a second
// copy of i (a3) for the `i >= lo` test and spills partsNum to 0x10($sp); mine uses 0x40($sp) and a single i.
extern "C" int func_00173AD8(Obj173AD8 *self)
{
    func_001B6FB8(self);
    cV4 a, b;
    cV4 c, d;
    cV4 *pc = &c;
    a.x = 1.02f; a.y = 1.288f; a.z = 1.02f; a.w = 1.0f;
    b.x = 1.02f; b.y = 1.288f; b.z = 1.02f; b.w = 1.0f;
    c.x = 0; c.y = 0; c.z = 0; pc->w = 1.0f;
    self->m_take = (cDamageUnit *)g_DmgManage.CreateDamageTake((cGameObj *)self, (DMG_KIND)2);
    if (self->m_take) {
        cV4 *pd = &d;
        d.x = 0; d.y = 0; d.z = 0; pd->w = 1.0f;
        self->m_take->AddDamageCollCylinder(*(cMatrix *)((char *)self + 0x80), c, d, b.y, b.x * 0.5f);
    }
    self->m_s548 = 1;
    self->m_s54A = 1;
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    if (self->m_partsNum != 1) {
        for (int i = 1; i < 6 && self->m_partsNum != i; i++) {
            *(unsigned *)((char *)self->getParts(i) + 0x154) |= 8;
            *(unsigned *)((char *)self->getParts(i) + 0x154) |= 0x10;
        }
    }
    return 1;
}
#endif
