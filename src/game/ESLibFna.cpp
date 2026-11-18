// Small unnamed functions in 0x2E0000-0x2EFFFF, placed next to ESLib.
#include "game/ESLibFn.h"

// FUNCTION: GAME 0x2E0AB8
extern "C" void func_002E0AB8()
{
    func_002DF950(1, 0xFFFF);
}

// FUNCTION: GAME 0x2E0AD8
extern "C" int func_002E0AD8()
{
    return 1;
}

// FUNCTION: GAME 0x2EFB40
extern "C" int func_002EFB40()
{
    return 1;
}

// FUNCTION: GAME 0x2E0AE0
extern "C" int func_002E0AE0(int x)
{
    int m = D_0061B289;
    if (x < -m)
        return 1;
    return DISPLAY_H * 2 + m < x;
}

// FUNCTION: GAME 0x2E16B0
VT_SET(2E16B0, D_0044E090, func_002FBE28)
// FUNCTION: GAME 0x2E3458
VT_SET(2E3458, D_0044E238, func_002FBE28)
// FUNCTION: GAME 0x2E9B40
VT_SET(2E9B40, D_0044E6D8, func_002FBE28)
// FUNCTION: GAME 0x2EA8E0
VT_SET(2EA8E0, D_0044E770, func_002FBE28)
// 0x2EBC20: not a unit start; the unit begins with an 8-byte fragment of the previous function.
// 0x2EFC78: not a unit start; the unit begins with an 8-byte fragment of the previous function.
// FUNCTION: GAME 0x2EBF70
VT_SET(2EBF70, D_0044E8C8, CALL1_EBC50)

// FUNCTION: GAME 0x2E81D8
VT_AFTER(2E81D8, D_0044E6D8)
// FUNCTION: GAME 0x2E9B68
VT_AFTER(2E9B68, D_0044E770)

// FUNCTION: GAME 0x2E1710
TAIL(2E1710, func_002FBED0)
// FUNCTION: GAME 0x2E82F8
TAIL(2E82F8, func_002FBED0)
// FUNCTION: GAME 0x2EFB48
TAIL(2EFB48, func_002FBED0)
// FUNCTION: GAME 0x2E28D0
TAIL(2E28D0, func_002FEB18)

// FUNCTION: GAME 0x2E2558
SINGLETON(2E2558, D_007863B8, D_0044E120, func_00300148)
// FUNCTION: GAME 0x2E3408
SINGLETON(2E3408, D_007863D8, D_0044E2C8, func_00300148)
// FUNCTION: GAME 0x2E76A0
SINGLETON(2E76A0, D_00786408, D_0044E5C8, func_00300148)
// FUNCTION: GAME 0x2E7FE8
SINGLETON(2E7FE8, D_00786418, D_0044E6D0, func_00300148)
// FUNCTION: GAME 0x2E9AF0
SINGLETON(2E9AF0, D_00786428, D_0044E768, func_00300148)
// FUNCTION: GAME 0x2EA890
SINGLETON(2EA890, D_00786438, D_0044E800, func_00300148)
// FUNCTION: GAME 0x2EBBD0
SINGLETON(2EBBD0, D_00786448, D_0044E8B0, func_00300148)
// FUNCTION: GAME 0x2EFC28
SINGLETON(2EFC28, D_00786468, D_0044EAA0, func_00300148)

// FUNCTION: GAME 0x2E16D8
extern "C" int func_002E16D8(EsObjCopy *self)
{
    EsObjSrc *s = self->src;
    self->f2B0 = s->f13C;
    self->f2B4 = s->f140;
    self->f2B8 = s->f144;
    self->f2BC = s->f148;
    self->i2C0 = s->i16C;
    return 1;
}

// FUNCTION: GAME 0x2E7FA8
extern "C" void func_002E7FA8(EsObjFlag *self)
{
    if (!(self->flags & 0x800000) && self->b2CB)
        func_002FEB18((EsObj *)self);
}

// FUNCTION: GAME 0x2E6368
extern "C" const char D_0044E538[];
extern "C" void func_002E6368(EsObjB2 *self, int a1)
{
    self->vt = D_0044E538;
    if (self->m_obj)
        ReleaseObj(self->m_obj);
    func_002FBE28(self, a1);
}

// FUNCTION: GAME 0x2E1528
float ESLib::ESHermite(float t, float p0, float p1, float m0, float m1)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float b = t2 * 3.0f;
    float t3x2 = t3 + t3;
    float h11 = t3 - t2;
    float a = t3x2 - b;
    float h01 = -t3x2 + b;
    float h10 = h11 - t2 + t;
    return a * p0 + p0 + p1 * h01 + m0 * h10 + m1 * h11;
}

// FUNCTION: GAME 0x2E1580
float ESLib::ESCatMullRom(float t, float p0, float p1, float p2, float p3)
{
    CatMat m = D_0044E050;
    float v[4];
    float *p = v;
    v[0] = t * t * t;
    v[1] = t * t;
    v[2] = t;
    p[3] = 1.0f;
    sceVu0ApplyMatrix(p, &m, p);
    return p0 * v[0] + p1 * v[1] + p2 * v[2] + p3 * v[3];
}

extern "C" const char D_0044E300[];
extern "C" const char D_0044E8C8[];
// FUNCTION: GAME 0x2E3480
extern "C" EsObjInit *func_002E3480(EsObjInit *self)
{
    func_002FBCC8(self);
    self->f2D4 = 1.0f;
    self->vt = D_0044E300;
    self->i2B0 = 0;
    self->i2B4 = 0;
    self->i2B8 = 0;
    self->i2C0 = 0;
    self->i2C4 = 0;
    self->i2C8 = 0;
    self->i2D8 = 0;
    self->i2DC = 0;
    self->i2BC = 0;
    self->i30C = 0;
    self->i324 = 0;
    self->i330 = 0;
    self->i334 = 0;
    self->i338 = 0;
    self->i33C = 0;
    return self;
}

// FUNCTION: GAME 0x2EBF08
extern "C" EsObjInit *func_002EBF08(EsObjInit *self)
{
    func_002FBCC8(self);
    self->f2D4 = 1.0f;
    self->vt = D_0044E8C8;
    self->i2B0 = 0;
    self->i2B4 = 0;
    self->i2B8 = 0;
    self->i2BC = 0;
    self->i2C0 = 0;
    self->i2C4 = 0;
    self->i2C8 = 0;
    self->i2D8 = 0;
    self->i2DC = 0;
    return self;
}

// FUNCTION: GAME 0x2E6AF8
extern "C" void func_002E6AF8(EsFlagCopy *self)
{
    if (self->src) {
        if (self->src->flags & 2)
            self->dst->flags |= 2;
        else
            self->dst->flags &= ~2;
        if (self->src->flags & 0x8000)
            self->dst->flags |= 0x8000;
        else
            self->dst->flags &= ~0x8000;
    }
}

// FUNCTION: GAME 0x2E0B18
extern "C" int func_002E0B18(int x, int n)
{
    if (x >= DISPLAY_W)
        return 1;
    int d = DISPLAY_W - x;
    int u = D_0061B288;
    if (d < n * u) {
        int idx = d / u;
        if (idx < 0)
            return 1;
        D_0061B298[idx] = 0;
    }
    return 0;
}

// FUNCTION: GAME 0x2E12D8
extern "C" int func_002E12D8(signed char c)
{
    switch (c) {
    case 1:
        return 0x7D;
    case 2:
        return 0x60;
    case 3:
        return 0x7C;
    case 4:
        return 0x7B;
    }
    return c;
}

// FUNCTION: GAME 0x2EFCA8
extern "C" int func_002EFCA8(EsObjB *self, EsParamB *p)
{
    self->f2C4 = p->f40;
    EsSrcB *s = self->src;
    self->i2B0 = s->i16C;
    self->i2B4 = s->b170;
    self->i2B8 = s->b18C;
    self->s2BC = s->b18D;
    self->b2BE = s->b18E;
    self->b2BF = s->b18F;
    self->b2C0 = s->b190;
    if ((unsigned int)self->i2B8 >= 2)
        return 0;
    if (self->b2BF >= 2)
        return 0;
    return self->b2C0 < 2;
}

// FUNCTION: GAME 0x2EC310
extern "C" void func_002EC310(EsObjC *self)
{
    func_002FBED0(self);
    if (self->f2DC != 0.0f) {
        self->f2D8 += self->f2DC;
        if (self->f2D8 > 1.0f)
            self->f2D8 -= 1.0f;
        if (self->f2D8 < 0.0f)
            self->f2D8 += 1.0f;
    }
}
