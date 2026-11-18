// Small game functions in 0x260000-0x270000.
extern "C" void SetBreak__9cOmWeapon(void *);
extern "C" void setFall__9cOmWeapon(void *);

struct Ew {
    char _pad0[0x2F4];
    unsigned char m_2F4;
    unsigned char m_2F5;
    unsigned char m_2F6;
    unsigned char m_2F7;
    char _pad1[0x2FE - 0x2F8];
    unsigned short m_2FE;
    char _pad2[0x54C - 0x300];
    float m_54C;
    char _pad3[0x564 - 0x550];
    int m_564;
    char _pad4[0x6EC - 0x568];
    void *m_6EC;
    char _pad5[0x710 - 0x6F0];
    void *m_710[8];
    char _pad6[0x16C0 - 0x730];
    float m_16C0;
    char _pad7[0x17A0 - 0x16C4];
    Ew *m_17A0;
};

// FUNCTION: GAME 0x26EA28
extern "C" int func_0026EA28(Ew *self)
{
    return self->m_16C0 <= 0.0f;
}

// FUNCTION: GAME 0x26F2B8
extern "C" int func_0026F2B8(Ew *self)
{
    unsigned char k = self->m_2F4;
    if (k == 1)
        return 1;
    if (k == 2 && self->m_2F5 != k)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x26B1E8
extern "C" void func_0026B1E8(Ew *self)
{
    if (self->m_6EC) {
        if (self->m_564 == 0x279)
            SetBreak__9cOmWeapon(self->m_6EC);
        else
            setFall__9cOmWeapon(self->m_6EC);
        self->m_6EC = 0;
    }
}

// FUNCTION: GAME 0x26EC60
extern "C" void func_0026EC60(Ew *self)
{
    Ew *o = self->m_17A0;
    if (o && o->m_2FE == self->m_2FE && !o->m_2F4 && !(o->m_54C > 0.0f)) {
        o->m_2F4 = 0;
        o->m_2F6 = 0;
        o->m_2F5 = 0x65;
        o->m_2F7 = 0;
    }
}

// FUNCTION: GAME 0x26BB70
extern "C" void func_0026BB70(Ew *self)
{
    if ((self->m_564 ^ 0x211) == 0) {
        unsigned i;
        void **p = self->m_710;
        for (i = 0; i < 8; i++) {
            if (*p) {
                SetBreak__9cOmWeapon(*p);
                *p = 0;
            }
            p++;
        }
    }
}

struct DmgU {
    char _pad0[0x40];
    int m_40;
    short m_44;
    short m_46;
    char _pad1[0x4C - 0x48];
    int m_4C;
};

struct Ep {
    char _pad0[0x34];
    struct Ep *m_34;
    char _pad1[0x2FE - 0x38];
    unsigned short m_2FE;
};

struct Eh {
    char _pad0[0x564];
    int m_564;
    char _pad1[0x670 - 0x568];
    Ep *m_670;
    char _pad2[0x678 - 0x674];
    Ep *m_678;
    char _pad3[0x680 - 0x67C];
    DmgU *m_680;
    int m_684;
    Ep *m_688;
    char _pad4[0x1864 - 0x68C];
    char m_1864;
};

extern "C" void SetDamageCollRadius__11cDamageUnitif(void *, int, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void SetDmgGiveHitVec__11cDamageGiveRC4cVec(void *, void *);
extern char ZeroVec[];

// FUNCTION: GAME 0x262980
extern "C" void func_00262980(Eh *self)
{
    float r = 2.0f;
    if (self->m_564 == 0x260)
        r = 3.0f;
    self->m_680->m_46 = 0x49;
    SetDamageCollRadius__11cDamageUnitif(self->m_680, self->m_684, r);
    self->m_680->m_4C = 0;
    SetDamageCollActive__11cDamageUnitb(self->m_680, 1);
    SetDmgGiveHitVec__11cDamageGiveRC4cVec(self->m_680, ZeroVec);
    self->m_680->m_40 = -1;
    self->m_680->m_44 = 0;
}

// FUNCTION: GAME 0x262A10
extern "C" int func_00262A10(Eh *self)
{
    Ep *q;
    if ((q = self->m_670->m_34) && q->m_2FE == 0x100) {
        self->m_1864 = 1;
        return 1;
    }
    if ((q = self->m_678->m_34) && q->m_2FE == 0x100) {
        self->m_1864 = 1;
        return 1;
    }
    if ((q = ((Ep *)self->m_680)->m_34) && q->m_2FE == 0x100) {
        self->m_1864 = 1;
        return 1;
    }
    if ((q = self->m_688->m_34) && q->m_2FE == 0x100) {
        self->m_1864 = 1;
        return 1;
    }
    return 0;
}
