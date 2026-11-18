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

#ifdef NONMATCHING
// 2 words differ: original ends with sltu v0,zero,v0; mine uses sra/andi
// DRAFT: GAME 0x2744B8
extern "C" int func_002744B8(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x211) != 0)
        return 0;
    return (*(unsigned *)(self + 0x16D4) & 0x20) != 0;
}
#endif

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

struct Em27b { char _p[0x214]; const void *m_vt; };
extern "C" {
extern const char D_00447BA0[], D_00447D48[], D_004481A8[], D_00448598[];
void func_002A84A8();
void func_0028EB88(void *, void *);
void func_00277540(void *);
void func_00278368(void *);
void func_0027BB30(void *);
void func_0027F170(void *);

}

// FUNCTION: GAME 0x2772F8
extern "C" void func_002772F8(Em27b *self, void *a)
{
    self->m_vt = D_00447BA0;
    func_002A84A8();
    func_00277540(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x2780C0
extern "C" void func_002780C0(Em27b *self, void *a)
{
    self->m_vt = D_00447D48;
    func_002A84A8();
    func_00278368(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x27B7C0
extern "C" void func_0027B7C0(Em27b *self, void *a)
{
    self->m_vt = D_004481A8;
    func_002A84A8();
    func_0027BB30(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x27EEC0
extern "C" void func_0027EEC0(Em27b *self, void *a)
{
    self->m_vt = D_00448598;
    func_002A84A8();
    func_0027F170(self);
    func_0028EB88(self, a);
}

extern "C" int func_0027DD00(void *);

// FUNCTION: GAME 0x275D68
extern "C" int func_00275D68(char *self)
{
    if (*(int *)(self + 0x564) == 0x264) {
        void *p = *(void **)(self + 0x740);
        if (p)
            return func_0027DD00(p) != 0;
    }
    return 0;
}
