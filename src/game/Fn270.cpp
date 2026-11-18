// Small free units in 0x270000-0x27FFFF.
enum eObjId { EOBJ_DUMMY };
class cObj;
class cObjBase;
struct PEN_INFO;
struct CLOTH_INFO;
void EmClothInit(eObjId, cObj *, PEN_INFO *, CLOTH_INFO *);
void EmClothMove(eObjId, cObj *, PEN_INFO *, CLOTH_INFO *);
void moveMotion(cObjBase *);

struct Em27 {
    char _p0[0x2F4];
    unsigned char m_2F4, m_2F5, m_2F6, m_2F7;
};

// FUNCTION: GAME 0x2744B8
extern "C" int func_002744B8(char *self)
{
    if (*(int *)(self + 0x564) == 0x211)
        return (*(unsigned *)(self + 0x16D4) & 0x20) != 0;
    return 0;
}

// FUNCTION: GAME 0x27EDC8
extern "C" void func_0027EDC8(char *self)
{
    EmClothInit((eObjId) * (int *)(self + 0x564), (cObj *)self, (PEN_INFO *)(self + 0x1630), (CLOTH_INFO *)(self + 0x15B0));
}

// FUNCTION: GAME 0x27EDF0
extern "C" void func_0027EDF0(char *self)
{
    EmClothMove((eObjId) * (int *)(self + 0x564), (cObj *)self, (PEN_INFO *)(self + 0x1630), (CLOTH_INFO *)(self + 0x15B0));
}

// FUNCTION: GAME 0x2714E8
extern "C" void func_002714E8(char *self)
{
    PEN_INFO *p = *(PEN_INFO **)(self + 0x1860);
    if (p)
        EmClothMove((eObjId) * (int *)(self + 0x564), (cObj *)self, p, (CLOTH_INFO *)(self + 0x17E0));
}

// FUNCTION: GAME 0x27DB20
extern "C" void func_0027DB20(Em27 *self, int v)
{
    int t;
    if (v == 0 || v != 1) {
        t = 5;
        self->m_2F7 = 0;
    } else {
        self->m_2F7 = v;
        t = 5;
    }
    self->m_2F5 = t;
    self->m_2F4 = 0;
    self->m_2F6 = 0;
}

// FUNCTION: GAME 0x27E3F8
extern "C" void func_0027E3F8(Em27 *self)
{
    if (self->m_2F6 == 0)
        self->m_2F6 = 1;
    else if (self->m_2F6 != 1)
        return;
    moveMotion((cObjBase *)self);
}
