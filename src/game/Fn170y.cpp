// Medium units of 0x170000-0x17FFFF.
#include "game/cOl1b.h"

// FUNCTION: GAME 0x17B718
extern "C" void setCloseFix__5cOl1b(cOl1b *self)
{
    if (self->m_open == 1) {
        if (self->getParts(0)) {
            cVec *v = &self->getParts(0)->m_v;
            v->x = 1.3962634f;
            v->y = 0;
            v->z = 0;
        }
        if (self->getParts(2)) {
            cVec *v = &self->getParts(2)->m_v;
            v->x = 1.3962634f;
            v->y = 0;
            v->z = 0;
        }
        self->m_open = 0;
        self->m_active = 0;
        self->m_act0 = 0;
        self->m_act1 = 0;
        self->m_act2 = 0;
        self->m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17B5E0
extern "C" void func_0017B5E0(cOl1b *self)
{
    if (((unsigned char *)self)[0x602] != 1 && self->m_open == 0) {
        if (self->getParts(0)) {
            cVec *v = &self->getParts(0)->m_v;
            v->x = -1.3962634f;
            v->y = 0;
            v->z = 0;
        }
        if (self->getParts(2)) {
            cVec *v = &self->getParts(2)->m_v;
            v->x = -1.3962634f;
            v->y = 0;
            v->z = 0;
        }
        self->m_open = 1;
        self->m_active = 0;
        self->m_act0 = 0;
        self->m_act1 = 0;
        self->m_act2 = 0;
        self->m_act3 = 0;
    }
}

// FUNCTION: GAME 0x17AC90
struct V4 { float x, y, z, w; };
extern char g_DmgManage[];
extern "C" {
void func_001B6FB8(void *);

void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, void *, void *, float);
int func_0017AC90(char *self)
{
    cOl1b *o = (cOl1b *)self;
    func_001B6FB8(self);
    {
    V4 c;
    c.x = 0;
    c.y = 0;
    c.z = 2.28f;
    c.w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x60C) = t;
    if (t) {
        if (o->getParts(0)) {
            AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x60C), (char *)o->getParts(0) + 0x80, &c, 1.0f);
            *(unsigned *)*(void **)(self + 0x60C) |= 1;
        }
    }
    }
    unsigned f = *(unsigned *)(self + 0x250) | 0x10000;
    *(unsigned char *)(self + 0x602) = 0;
    *(unsigned char *)(self + 0x600) = 0;
    *(unsigned *)(self + 0x5B8) |= 8;
    *(short *)(self + 0x548) = 0x78;
    *(short *)(self + 0x54A) = 0x78;
    *(unsigned *)(self + 0x250) = f;
    func_0017B5E0((cOl1b *)self);
    if (o->getParts(0))
        *(float *)(self + 0x608) = o->getParts(0)->m_v.x;
    return 1;
}
}

// FUNCTION: GAME 0x17AEB0
extern char Snd[];
extern "C" {
float fRand1_1__Fv();
int SeCall__4cSnd6eSeBlksssUii(void *, int, short, short, short, unsigned, int);
void func_0017AEB0(char *self)
{
    cOl1b *o = (cOl1b *)self;
    if (*(short *)(self + 0x606) != 0) {
        if (o->m_act0 == 0) {
            *(short *)(self + 0x606) = *(unsigned short *)(self + 0x606) - 1;
            SeCall__4cSnd6eSeBlksssUii(Snd, 2, 0x1E, -1, -1, 0, 0);
            if (*(short *)(self + 0x606) != 0) {
                if (o->getParts(0)) {
                    cObjParts *p = o->getParts(0);
                    p->m_v.x = *(float *)(self + 0x608) + fRand1_1__Fv() * 2 * 0.017453292f;
                }
            } else {
                if (o->getParts(0))
                    o->getParts(0)->m_v.x = *(float *)(self + 0x608);
            }
        } else {
            *(short *)(self + 0x606) = 0;
            if (o->getParts(0))
                o->getParts(0)->m_v.x = *(float *)(self + 0x608);
        }
    }
}
}
