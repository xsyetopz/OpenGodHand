#include "game/pl00Decls.h"

// FUNCTION: GAME 0x12C748
extern "C" int func_0012C748(pl00 *self)
{
    if (self->m_unk5FC)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x101E98
extern "C" void func_00101E98()
{
    func_00100FB8(1, 0xFFFF);
}

// FUNCTION: GAME 0x1267F8
extern "C" void func_001267F8(pl00 *self)
{
    if (self->m_unk165C)
        ((cActionButtonUnit *)self->m_unk165C)->setOk();
}

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

// FUNCTION: GAME 0x124E68
extern "C" void func_00124E68(pl00 *self, float a)
{
    cVObj *o = self->m_unk640;
    if (o)
        ((cGameObj *)self)->SetTgtTurn(*o->m_vtab->m_fn((char *)o + o->m_vtab->m_delta), a);
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

// FUNCTION: GAME 0x1020F0
extern "C" int func_001020F0(cModel *self)
{
    if (D_00747A80 < 0)
        return 1;
    return self->isClip() != 0;
}

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

// FUNCTION: GAME 0x2C4350
extern "C" int func_002C4350(cMsgHolder *m)
{
    if (m->m_unk112 == 0xFFFF)
        return 0;
    return Message->ckMessage(m->m_unk112);
}

// FUNCTION: GAME 0x2CC4A0
extern "C" void func_002CC4A0(sIdPair *a)
{
    a->m_unk4 = 0;
    a->m_id1 = -1;
    a->m_id0 = -1;
}

// FUNCTION: GAME 0x2CC4C8
extern "C" char *func_002CC4C8(sTblBase *b, int i)
{
    return b->m_unk34 + i * 0x50;
}

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

// FUNCTION: GAME 0x2CF868
extern "C" int func_002CF868(sHasShort2C *e)
{
    return func_00375128(e->m_unk2C) == 0;
}
