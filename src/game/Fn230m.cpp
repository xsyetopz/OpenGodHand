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
