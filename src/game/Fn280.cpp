// Small units in 0x280000-0x28FFFF (round 24).
extern char g_RoomSave[];
extern "C" void EmClothMove__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(int, void *, void *, void *);
extern "C" void setEmDeadFlag__9cRoomSaveUi(void *, unsigned);
extern "C" char *func_002BEF60(void *, unsigned);
extern "C" void func_002A84A8(void *);
extern "C" void func_00281940(void *);
extern "C" void func_0028EB88(void *, void *);
extern "C" void *func_0028EB00(void *);
extern const char D_00448788[];
extern const char D_0044A528[];
extern const char D_0044A510[];

// FUNCTION: GAME 0x28CEA8
extern "C" void func_0028CEA8(char *self)
{
    void *c = *(void **)(self + 0x1630);
    if (c)
        EmClothMove__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(*(int *)(self + 0x564), self, c, self + 0x15B0);
}

// FUNCTION: GAME 0x28FB08
extern "C" void func_0028FB08(char *self)
{
    unsigned h = *(unsigned short *)(self + 0x640);
    if (h != 0xFF)
        setEmDeadFlag__9cRoomSaveUi(g_RoomSave, h);
}

struct Ema {
    char _pad[0x15A0];
    float m_x, m_y, m_z;
    char _pad2[0x15B0 - 0x15AC];
    unsigned m_f;
};

// FUNCTION: GAME 0x289480
extern "C" void gotoSwitch__5cEma2RC4cVec(Ema *self, const float *v)
{
    if (&self->m_x != v) {
        float *d = &self->m_x;
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
    self->m_f |= 0x80;
}

// FUNCTION: GAME 0x28FB38
extern "C" int checkDeadFlag__7cEmBase(char *self)
{
    unsigned h = *(unsigned short *)(self + 0x640);
    if (h == 0xFF)
        return 0;
    char *p = func_002BEF60(g_RoomSave, h);
    if (p) {
        unsigned char t = p[0x14] ^ 1;
        return t == 0;
    }
    return 1;
}

struct Tm {
    char _pad[0x5A8];
    float m_5a8;
    char _pad2[0x5B4 - 0x5AC];
    int m_5b4;
    float m_5b8;
};

// FUNCTION: GAME 0x28ED28
extern "C" void func_0028ED28(Tm *s, int a)
{
    s->m_5b4 += a;
    if (s->m_5b4 < 0)
        s->m_5b4 = 0;
    if (s->m_5b4 > 100000)
        s->m_5b4 = 100000;
    if (a > 0)
        s->m_5b8 = 90.0f;
}

// FUNCTION: GAME 0x281690
extern "C" void func_00281690(char *self, void *a)
{
    *(const void **)(self + 0x214) = D_00448788;
    func_002A84A8(self);
    func_00281940(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x28E018
extern "C" char *func_0028E018(char *self)
{
    func_0028EB00(self);
    *(const void **)(self + 0x214) = D_0044A528;
    char *q = self + 0x1510;
    __asm__ volatile("sqc2 $vf0,0x1520(%0)" : : "r"(self) : "memory");
    *(unsigned char *)(q + 0x31) = 0xFF;
    *(const void **)(self + 0x4AC) = D_0044A510;
    return self;
}

// FUNCTION: GAME 0x28ED78
extern "C" void func_0028ED78(Tm *s)
{
    if (s->m_5b4 > 0) {
        s->m_5b8 -= s->m_5a8;
        if (s->m_5b8 <= 0.0f) {
            s->m_5b4 -= 30;
            s->m_5b8 = 90.0f;
        }
        if (s->m_5b4 < 0)
            s->m_5b4 = 0;
    }
}
