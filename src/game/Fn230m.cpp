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
