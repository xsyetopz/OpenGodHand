// Small unnamed functions in 0x180000-0x19FFFF.
extern "C" void func_001BBF00(void *self, int flag);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern const char D_00425D48[];

// FUNCTION: GAME 0x19D3C8
extern "C" void func_0019D3C8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00425D48;
    func_001BBF00(self, flag);
}

struct VT {
    char _pad[0x68];
    short m_adj;
    short _pad2;
    void (*m_fn)(void *);
};


// FUNCTION: GAME 0x18A3B8
struct UnitArr {
    char _pad[0x600];
    void *m_u[1];
};
extern "C" void func_0018A3B8(UnitArr *self, int idx)
{
    void *u = self->m_u[idx];
    if (u)
        SetDamageCollActive__11cDamageUnitb(u, 0);
}

struct cVec {
    float x, y, z;
};
struct cOm1f {
    char _pad[0xB10];
    cVec m_home;
    void setHomePos(const cVec &v);
};

// FUNCTION: GAME 0x195B88
void cOm1f::setHomePos(const cVec &v)
{
    cVec *h = &m_home;
    if (h != &v) {
        m_home.x = v.x;
        h->y = v.y;
        h->z = v.z;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x195980
// diff: register allocation (adj/fn in v1/a1 vs a1/v0)
extern "C" void func_00195980(char *self)
{
    VT *vt = *(VT **)(self + 0x214);
    int adj = vt->m_adj;
    void (*fn)(void *) = vt->m_fn;
    fn(self + adj);
}
#endif
