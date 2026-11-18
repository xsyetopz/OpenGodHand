// Small unnamed functions in 0x260000-0x28FFFF.

// FUNCTION: GAME 0x280A08
extern "C" void func_00280A08(void) {}

// FUNCTION: GAME 0x280AE8
extern "C" void func_00280AE8(void) {}

// FUNCTION: GAME 0x280AF0
extern "C" void func_00280AF0(void) {}

// FUNCTION: GAME 0x280B58
extern "C" void func_00280B58(void) {}

// FUNCTION: GAME 0x282D68
extern "C" void func_00282D68(void) {}

// FUNCTION: GAME 0x282E48
extern "C" void func_00282E48(void) {}

struct Fn260Obj15B0 {
    char _pad0[0x15B0];
    int m_flags;
};

// FUNCTION: GAME 0x2831A0
extern "C" void func_002831A0(Fn260Obj15B0 *self)
{
    *(char *)&self->m_flags = 1;
}

// FUNCTION: GAME 0x289028
extern "C" void func_00289028(Fn260Obj15B0 *self)
{
    self->m_flags |= 8;
}

class cEm30 {
public:
    char _pad0[0x2F4];
    char m_unk2F4;
    char m_unk2F5;
    char m_unk2F6;
    char m_unk2F7;
    void setEvent();
};

// FUNCTION: GAME 0x278000
void cEm30::setEvent()
{
    m_unk2F5 = 4;
    m_unk2F4 = 0;
    m_unk2F6 = 0;
    m_unk2F7 = 0;
}

// FUNCTION: GAME 0x282E50
extern "C" void func_00282E50(void) {}

// FUNCTION: GAME 0x282EB8
extern "C" void func_00282EB8(void) {}

// FUNCTION: GAME 0x288DA0
extern "C" void func_00288DA0(void) {}

// FUNCTION: GAME 0x28AC50
extern "C" void func_0028AC50(void) {}

// FUNCTION: GAME 0x28C3F8
extern "C" void func_0028C3F8(void) {}

// FUNCTION: GAME 0x28E418
extern "C" void func_0028E418(void) {}

// FUNCTION: GAME 0x28EA30
extern "C" void func_0028EA30(void) {}

// FUNCTION: GAME 0x28FE48
extern "C" void func_0028FE48(void) {}

extern "C" void func_00283C70(int, int);
extern "C" void func_00284548(int, int);
extern "C" void func_0028FF80(int, int);
extern "C" void func_00104010(char *, char *, char *);

// FUNCTION: GAME 0x283EA8
extern "C" void func_00283EA8(void) { func_00283C70(1, 0xFFFF); }

// FUNCTION: GAME 0x284A08
extern "C" void func_00284A08(void) { func_00284548(1, 0xFFFF); }

// FUNCTION: GAME 0x28FFE0
extern "C" void func_0028FFE0(void) { func_0028FF80(1, 0xFFFF); }

// FUNCTION: GAME 0x2844A0
extern "C" void func_002844A0(char *self) { func_00104010(self, self + 0x2130, self + 0x5B0); }

class cGameObj;
struct cCollSolidFwd {
    void ReleaseUnit(cGameObj *) __asm__("ReleaseUnit__21cCollisionSolidManageP8cGameObj");
};
extern cCollSolidFwd g_CollSolidManage;

// FUNCTION: GAME 0x277540
extern "C" void func_00277540(cGameObj *o) { g_CollSolidManage.ReleaseUnit(o); }

// FUNCTION: GAME 0x27E088
extern "C" void func_0027E088(cGameObj *o) { g_CollSolidManage.ReleaseUnit(o); }

// FUNCTION: GAME 0x281940
extern "C" void func_00281940(cGameObj *o) { g_CollSolidManage.ReleaseUnit(o); }

// FUNCTION: GAME 0x289E10
extern "C" void func_00289E10(cGameObj *o) { g_CollSolidManage.ReleaseUnit(o); }

// FUNCTION: GAME 0x2896B0
extern "C" void func_002896B0(unsigned char *self)
{
    if (self[0x2F4] == 0 && self[0x2F5] == 8)
        self[0x2F6] = 2;
}

extern "C" void dieCommon__7cOmBase(void *);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void func_0028EB88(void *, int);
extern "C" void func_00279E70(void *);
extern "C" void func_0028BEA8(void *);
extern const char D_00447E68[];
extern const char D_004483A8[];
extern const char D_0044A408[];
struct cEmSetFwd {
    void updateSetDataFlag(unsigned, unsigned) __asm__("updateSetDataFlag__11cEmSetParamUiUi");
};
extern cEmSetFwd g_EmSet;

// FUNCTION: GAME 0x27F170
extern "C" void func_0027F170(cGameObj *o)
{
    g_CollSolidManage.ReleaseUnit(o);
    KillEffect__FPC4cObji13eEspEraseMode(o, 1, 2);
}

struct Fn260State {
    char _pad0[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
};

// FUNCTION: GAME 0x281470
extern "C" void func_00281470(Fn260State *s, unsigned char mode)
{
    switch (mode) {
    case 0:
    default:
        s->m_a = 0;
        s->m_b = 0xF;
        s->m_c = 0;
        s->m_d = 0;
        break;
    case 1:
        s->m_b = 0xF;
        s->m_c = 2;
        s->m_a = 0;
        s->m_d = 0;
        break;
    }
}

// FUNCTION: GAME 0x283378
extern "C" void func_00283378(Fn260State *s, unsigned char mode)
{
    switch (mode) {
    case 0:
    default:
        s->m_a = 0;
        s->m_b = 0xC;
        s->m_c = 0;
        s->m_d = 0;
        break;
    case 1:
        s->m_b = 0xC;
        s->m_c = 2;
        s->m_a = 0;
        s->m_d = 0;
        break;
    }
}

// FUNCTION: GAME 0x279D40
extern "C" void func_00279D40(char *self, int x)
{
    *(const void **)(self + 0x214) = D_00447E68;
    func_00279E70(self);
    func_0028EB88(self, x);
}

// FUNCTION: GAME 0x27DE18
extern "C" void func_0027DE18(char *self, int x)
{
    *(const void **)(self + 0x214) = D_004483A8;
    func_0027E088((cGameObj *)self);
    func_0028EB88(self, x);
}

// FUNCTION: GAME 0x28B148
extern "C" void func_0028B148(char *self, int x)
{
    *(const void **)(self + 0x214) = D_0044A408;
    func_0028BEA8(self);
    func_0028EB88(self, x);
}

// FUNCTION: GAME 0x27BB30
extern "C" void func_0027BB30(char *self)
{
    g_CollSolidManage.ReleaseUnit((cGameObj *)self);
    if (*(void **)(self + 0x15B0)) {
        dieCommon__7cOmBase(*(void **)(self + 0x15B0));
        *(void **)(self + 0x15B0) = 0;
    }
}

// FUNCTION: GAME 0x285678
extern "C" void func_00285678(char *self)
{
    g_CollSolidManage.ReleaseUnit((cGameObj *)self);
    if (*(void **)(self + 0x15EC)) {
        dieCommon__7cOmBase(*(void **)(self + 0x15EC));
        *(void **)(self + 0x15EC) = 0;
    }
}

// FUNCTION: GAME 0x2736F8
extern "C" void func_002736F8(char *self)
{
    unsigned f = *(unsigned *)(self + 0x1644);
    f &= 0xEFFFFFFF;
    f &= 0xFFFF7FFF;
    *(unsigned *)(self + 0x1644) = f;
    g_EmSet.updateSetDataFlag(*(unsigned short *)(self + 0x640), f);
}
