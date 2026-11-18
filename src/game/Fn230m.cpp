// Game functions in 0x230000-0x260000.
struct Mo;
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_0026F120(void *);
extern "C" void func_00270C78(void *);
extern char g_CollSolidManage[];
extern "C" unsigned func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002705D8(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);

struct Pm {
    char _pad[0x1F70];
    int m_1F70;
    int m_1F74;
    int m_1F78;
    int m_1F7C;
};

struct Em {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    Pm *m_304;
    char _pad2[0x564 - 0x308];
    int m_564;
    short m_568;
    char _pad3[0x617 - 0x56A];
    unsigned char m_617;
    char _pad4[0x623 - 0x618];
    unsigned char m_623;
};

// DRAFT: GAME 0x247218
// diff: 7 words; original keeps the loaded offsets in v1/a0 and adds the base into a1/a2, mine loads straight into a1/a2
#ifdef NONMATCHING
extern "C" void func_00247218(Em *self)
{
    self->m_617 = 1;
    switch (self->m_2F6) {
    case 0: {
        int t = func_00276468(self) & 0xFFFF;
        Pm *p;
        int a, b;
        if (self->m_564 == 0x24F) {
            p = self->m_304;
            a = p->m_1F70;
            b = p->m_1F74;
        } else {
            p = self->m_304;
            a = p->m_1F78;
            b = p->m_1F7C;
        }
        a += (int)p;
        b += (int)p;
        func_002A8578(self, a, b, 10, t, 0, 0.0f);
        self->m_568 = 10;
        self->m_623 = 1;
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (self->m_568 > 0)
            self->m_568--;
        else
            self->m_623 = 0;
    }
}
#endif

// DRAFT: GAME 0x246F40
// diff: 3 words; the original increments m_2F6 through v1, mine through v0
#ifdef NONMATCHING
struct Ef {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x5B4 - 0x308];
    int m_5B4;
    char _pad3[0x16D0 - 0x5B8];
    unsigned m_16D0;
};

extern "C" void func_00246F40(Ef *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    self->m_16D0 |= 0x20000;
    self->m_16D0 |= 0x10000;
    switch (self->m_2F6) {
    case 0: {
        int t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0xC34) + (int)p, *(int *)(p + 0xC38) + (int)p, 10, t, 0, 80.0f);
        self->m_5B4 = 100000;
        func_0026F120(self);
        unsigned char n = self->m_2F6 + 1;
        self->m_2F6 = n;
    }
    case 1:
        self->m_16D0 |= 0x20000;
        if (moveMotion__FP8cObjBase(self))
            func_00270C78(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
}
#endif

extern "C" int irand__Fv(void);
extern "C" void func_002814E8(int, int);
extern "C" void func_002833C0(int, int);
extern "C" int func_0026F1D8(void *);

struct Eg {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    unsigned char m_2F7;
    char _pad1[0x304 - 0x2F8];
    char *m_304;
    char _pad2[0x748 - 0x308];
    int m_748;
    int m_74C;
    int m_750;
    char _pad3[0x16D0 - 0x754];
    unsigned m_16D0;
};

// DRAFT: GAME 0x25B5A8
// diff: 8 words; original loads the two offsets into v1/a0 off v0 and adds before the flag update
#ifdef NONMATCHING
extern "C" void func_0025B5A8(Eg *self)
{
    switch (self->m_2F6) {
    case 0: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p, *a, *b;
        if (self->m_2F7 = irand__Fv() & 1) {
            p = self->m_304;
            a = p + *(int *)(p + 0x3DF4);
            b = p + *(int *)(p + 0x3DF8);
        } else {
            p = self->m_304;
            a = p + *(int *)(p + 0x3DEC);
            b = p + *(int *)(p + 0x3DF0);
        }
        self->m_16D0 &= 0xFEFFFFFF;
        func_002A8578(self, (int)a, (int)b, 2, t, 0, 0.0f);
        if (self->m_748)
            func_002814E8(self->m_748, self->m_2F7);
        if (self->m_74C)
            func_002833C0(self->m_74C, self->m_2F7);
        if (self->m_750)
            func_002833C0(self->m_750, self->m_2F7);
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            func_0026F120(self);
            if (func_0026F1D8(self))
                func_00270C78(self);
            else
                func_002705D8(self);
        }
    }
}
#endif

extern "C" void *Getplayer__Fv(void);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void func_00281260(int);
extern "C" void func_00283170(int);
extern "C" void func_002495E0(void *, float);
extern "C" void func_00262AA8(void *);
extern char D_005850B0[];
extern unsigned char g_HeatSys[];

static inline int HeatFlag(unsigned char *h) { return h[0x10]; }

struct Eh {
    char _pad0[0xF0];
    float *m_F0;
    char _pad1[0x2F6 - 0xF4];
    unsigned char m_2F6;
    char _pad2[0x304 - 0x2F7];
    char *m_304;
    char _pad3[0x748 - 0x308];
    int m_748;
    int m_74C;
    int m_750;
    char _pad4[0x16D0 - 0x754];
    unsigned m_16D0;
    char _pad5[0x1864 - 0x16D4];
    unsigned char m_1864;
};

// DRAFT: GAME 0x249960
// diff: 12 words; the original materializes &g_HeatSys with lui+addiu and then lbu 0x10, mine folds the offset into lbu
#ifdef NONMATCHING
extern "C" void func_00249960(Eh *self)
{
    capVu0MagnitudeSqXZ__FPCfT0(((Eh *)Getplayer__Fv())->m_F0, (const float *)D_005850B0);
    self->m_16D0 |= 0x30400;
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x3D34) + (int)p, *(int *)(p + 0x3D38) + (int)p, 10, t, 0, 0.0f);
        if (self->m_748)
            func_00281260(self->m_748);
        if (self->m_74C)
            func_00283170(self->m_74C);
        if (self->m_750)
            func_00283170(self->m_750);
        self->m_16D0 &= 0xFCFFFFFF;
        self->m_2F6++;
    }
    case 1:
        func_002495E0(self, 0.0f);
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
    if (!HeatFlag(g_HeatSys))
        func_00262AA8(self);
}
#endif

struct Ei {
    char _pad0[0x2F4];
    unsigned char m_2F4;
    unsigned char m_2F5;
    unsigned char m_2F6;
    unsigned char m_2F7;
    char _pad1[0x304 - 0x2F8];
    char *m_304;
    char _pad2[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad3[0x564 - 0x3AE];
    int m_564;
    char _pad4[0x16D0 - 0x568];
    unsigned m_16D0;
    char _pad5[0x1864 - 0x16D4];
    unsigned char m_1864;
};

// DRAFT: GAME 0x23D410
// diff: about 25 words; the original keeps a chain of m_564 range tests whose arms all load the same 0xC4C/0xC50 offsets
#ifdef NONMATCHING
extern "C" void func_0023D410(Ei *self)
{
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        char *p = self->m_304;
        int a = *(int *)(p + 0xC4C) + (int)p;
        int b = *(int *)(p + 0xC50) + (int)p;
        unsigned t = func_00276468(self) & 0xFFFF;
        func_002A8578(self, a, b, 10, t, 0, 0.0f);
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            self->m_2F4 = 0;
            self->m_2F5 = 0x6E;
            self->m_2F6 = 0;
            self->m_2F7 = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
    if (self->m_3AC & 8)
        self->m_16D0 |= 0x4000;
}
#endif

// DRAFT: GAME 0x258C40
// diff: about 25 words; same m_564 range-test chain as 0x23D410
#ifdef NONMATCHING
extern "C" void func_00258C40(Ei *self)
{
    self->m_16D0 |= 0x4000;
    switch (self->m_2F6) {
    case 0: {
        char *p = self->m_304;
        int a = *(int *)(p + 0xC4C) + (int)p;
        int b = *(int *)(p + 0xC50) + (int)p;
        unsigned t = func_00276468(self) & 0xFFFF;
        func_002A8578(self, a, b, 10, t, 0, 0.0f);
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            self->m_2F4 = 0;
            self->m_2F5 = 0x6E;
            self->m_2F6 = 0;
            self->m_2F7 = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
}
#endif

extern "C" int GetSeqSEBase__FP8cObjBase(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern char Snd[];

struct Ej {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x54C - 0x308];
    float m_54C;
    char _pad3[0x564 - 0x550];
    int m_564;
};

// DRAFT: GAME 0x2311A8
// diff: 13 words; the original loads the offset pair into v1/a0 then adds the base, mine loads into a1/a2; m_2F6 increment via v1
#ifdef NONMATCHING
extern "C" void func_002311A8(Ej *self)
{
    switch (self->m_2F6) {
    case 0: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p;
        int a, b;
        switch (self->m_564) {
        case 0x20A ... 0x20E:
        case 0x218:
        case 0x245 ... 0x247:
        case 0x24F:
        case 0x278 ... 0x279:
            p = self->m_304;
            a = *(int *)(p + 0x948);
            b = *(int *)(p + 0x94C);
            break;
        case 0x21A ... 0x21E:
        case 0x225:
        case 0x22C ... 0x22F:
        case 0x248 ... 0x249:
        case 0x24C ... 0x24E:
        case 0x252:
        case 0x25A:
            p = self->m_304;
            a = *(int *)(p + 0x11A0);
            b = *(int *)(p + 0x11A4);
            break;
        default:
            p = self->m_304;
            a = *(int *)(p + 0x1C0);
            b = *(int *)(p + 0x1C4);
            break;
        }
        func_002A8578(self, a + (int)p, b + (int)p, 10, t, 0, 0.0f);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, (short)GetSeqSEBase__FP8cObjBase(self), self, 0, 0, 0, 0);
        self->m_54C = 2.0f;
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
}
#endif
