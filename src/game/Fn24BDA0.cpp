// Turn-to-target state entry check (CoreSave-family enemy); returns 1 when the turn is accepted.
struct Qv { float f[4]; };
struct Sv {
    float v[4] __attribute__((aligned(16)));
    Sv() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)v)); }
    Sv &operator=(const float *o)
    {
        if (v != o) { v[0] = o[0]; v[1] = o[1]; v[2] = o[2]; }
        return *this;
    }
};
extern "C" float Turn_dest__FPCffT0f(const float *, float, const float *, float);
extern "C" float Turn_dest_dir__Ffff(float, float, float);
extern "C" int func_002C2B58(void *, void *, float *, float *);
extern char g_SceAt[];
extern char Sys[];

struct Ek {
    char _p0[0xF0];
    void *m_F0;
    char _p1[0x104 - 0xF4];
    float m_104;
    char _p2[0x2F4 - 0x108];
    unsigned char m_2F4, m_2F5, m_2F6, m_2F7;
    char _p3[0x490 - 0x2F8];
    float m_490[4];
    char _p4[0x564 - 0x4A0];
    int m_564;
    char _p5[0x6D0 - 0x568];
    Sv m_6D0;
    float m_6E0;
    char _p6[0x16A0 - 0x6E4];
    float m_16A0[4];
    char _p7[0x17D0 - 0x16B0];
    unsigned m_17D0;
};

// FUNCTION: GAME 0x24BDA0
extern "C" int func_0024BDA0(Ek *self)
{
    int m = self->m_564;
    if (m < 0x223) {
        if (m < 0x220)
            goto chk;
    } else {
    chk:
        unsigned *sy = (unsigned *)Sys;
        if ((sy[0x210 / 4] & 7) != (self->m_17D0 & 7))
            return 0;
        unsigned short *sh = (unsigned short *)Sys;
        if (sh[0x5B0 / 2] == 0x100)
            return 0;
    }
    Sv a;
    float b[4] __attribute__((aligned(16)));
    float pi = 3.1415927f;
    float d = Turn_dest__FPCffT0f(self->m_490, self->m_104, self->m_16A0, pi);
    float ad = d;
    if (d < 0.0f)
        ad = -d;
    if (0.5235988f < ad)
        return 0;
    if (!func_002C2B58(g_SceAt, self->m_F0, a.v, b))
        return 0;
    float e = Turn_dest_dir__Ffff(self->m_104, b[0], pi);
    float ae = e;
    if (e < 0.0f)
        ae = -e;
    if (0.7853982f < ae)
        return 0;
    self->m_6D0 = a.v;
    self->m_6E0 = b[0];
    self->m_2F5 = 0x74;
    self->m_2F7 = 0;
    self->m_2F4 = 0;
    self->m_2F6 = 0;
    return 1;
}
