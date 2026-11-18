#include "game/cEventShared.h"

// FUNCTION: GAME 0x298088
extern "C" void func_00298088(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = getCostumeNo__9cCoreSave(CoreSave);
        if (k == 1639) {
            if (v) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x2980E8
extern "C" void func_002980E8()
{
    func_00297B40(Event, (void *)func_00298110);
}

// FUNCTION: GAME 0x298110
extern "C" void func_00298110(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 16) {
                setMeshDisplay__6cModelPCcb(self, D_0044A9B0, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044A9B8, 1);
            }
            break;
        case 1543:
            if (n >= 16) {
                setMeshDisplay__6cModelPCcb(self, D_0044A9B0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x2981B0
extern "C" void func_002981B0()
{
    func_00297B40(Event, (void *)func_002981D8);
}

// FUNCTION: GAME 0x2981D8
extern "C" void func_002981D8(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 18) {
                setMeshDisplay__6cModelPCcb(self, D_0044A9D0, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044A9D8, 1);
            }
            break;
        case 1543:
            if (n >= 18) {
                setMeshDisplay__6cModelPCcb(self, D_0044A9D0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x298278
extern "C" void func_00298278()
{
    func_00297B40(Event, (void *)func_002982A0);
}

// FUNCTION: GAME 0x2982A0
extern "C" void func_002982A0(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = getCostumeNo__9cCoreSave(CoreSave);
        if (k == 1539) {
            if ((unsigned char)(v - 4) < 2) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x298310
extern "C" void func_00298310()
{
    func_00297B20(Event, (void *)func_00298338);
}

// FUNCTION: GAME 0x298338
extern "C" void func_00298338(int a, float f)
{
    if (f == 0.0f) {
        if (a == 0 || a == 4) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
    }
}

// FUNCTION: GAME 0x298388
extern "C" void func_00298388()
{
    char *d = Event;
    func_00297B20(d, (void *)func_002983D0);
    func_00297B40(d, (void *)func_00298460);
}

// FUNCTION: GAME 0x2983D0
extern "C" void func_002983D0(int a, float f)
{
    switch (a) {
    case 0:
        if (f == 0.0f) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
        break;
    case 13:
        if (f == 101.0f) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
        break;
    }
}

// FUNCTION: GAME 0x2987B0
extern "C" void func_002987B0()
{
    char *d = Event;
    func_00297B20(d, (void *)func_002987F8);
    func_00297B40(d, (void *)func_002988A8);
}

// FUNCTION: GAME 0x298A50
extern "C" void func_00298A50()
{
    func_00297B40(Event, (void *)func_00298A78);
}

// FUNCTION: GAME 0x298BF0
extern "C" void func_00298BF0()
{
    func_00297B20(Event, (void *)func_00298C18);
}

// FUNCTION: GAME 0x298C18
extern "C" void func_00298C18(int a)
{
    if (a == 3) {
        displayScrollLayer__FUib(22, 0);
    } else {
        displayScrollLayer__FUib(22, 1);
    }
}

// FUNCTION: GAME 0x298ED0
extern "C" void func_00298ED0()
{
    func_00297B40(Event, (void *)func_00298EF8);
}

// FUNCTION: GAME 0x2991B0
extern "C" void func_002991B0()
{
    func_00297B40(Event, (void *)func_002991D8);
}

// FUNCTION: GAME 0x299860
extern "C" void func_00299860()
{
}

// FUNCTION: GAME 0x299868
extern "C" void func_00299868(EvBuf *self, long a, long b)
{
    EvPk *p = &self->pk;
    p->cur->lo = b;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x299348
extern "C" void func_00299348(EvBuf *self0)
{
    EvPk2 *self = (EvPk2 *)&self0->pk;
    self->m_c8 = 0;
    self->m_a8 = 0;
    self->m_ac = 0;
    self->m_b0 = 0;
    self->m_a4 = 0;
}

// FUNCTION: GAME 0x2998A0
extern "C" void func_002998A0(EvBuf *self, long a, float x, float y)
{
    EvPk *p = &self->pk;
    float *c = (float *)p->cur;
    c[0] = x;
    c[1] = y;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x2998D8
extern "C" void func_002998D8(EvBuf *self, int tag, long b)
{
    EvPk *p = &self->pk;
    EvQw *c = p->cur;
    p->tag = (unsigned char)tag;
    p->x8 = b;
    p->cnt = 0;
    p->start = c;
    p->cur = c + 1;
}

// FUNCTION: GAME 0x2999D0
extern "C" void func_002999D0(EvBuf *self, long a, long b)
{
    EvPk2 *p = (EvPk2 *)&self->pk;
    p->cur->lo = b;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x299908
extern "C" void func_00299908(EvBuf *self)
{
    EvPk *p = &self->pk;
    p->start->lo = p->cnt | ((long)p->tag << 15) | (1L << 60);
    p->start->hi = p->x8;
}

// FUNCTION: GAME 0x298060
extern "C" void func_00298060()
{
    func_00297B40(Event, (void *)func_00298088);
}

// FUNCTION: GAME 0x299320
void cEventConfig::setEventNo(int n)
{
    EvCfgEnt *e = &D_003C0550[n];
    m_ent = e;
    m_val = e->m_4;
}

// FUNCTION: GAME 0x299368
void classCFILTER_TAG::initialize()
{
    char *b = (char *)this;
    *(unsigned *)(b + 0x10000) = ((unsigned)this | 0x20000000) + 0x10;
    *(unsigned *)(b + 0x14080) = ((unsigned)(b + 0x10080) | 0x20000000) + 0x10;
}

// FUNCTION: GAME 0x298D78
void SetEv61HumanAlive(bool a, bool b, bool c)
{
    D_003C0548[0] = a;
    D_003C0548[1] = b;
    D_003C0548[2] = c;
    func_00297C80((int *)Event, (int)func_00298DB8);
}

// FUNCTION: GAME 0x298C58
extern "C" void func_00298C58()
{
    char *arr = objbaseArray;
    char *s = D_0044ABE0;
    unsigned long key = 0;
    int i = 0;
    while (i < 8 && s[i]) {
        key |= (long)s[i] << (i * 8);
        i++;
    }
    EvObj *o = SearchOM__13cObjBaseArrayUl(arr, key);
    if (o) {
        o->m_flags |= 2;
    }
    func_00297B60(Event, (void *)func_00298CF0);
}
