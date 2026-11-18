extern "C" void free__5cHeapPv(void *, void *);
extern "C" void *memset(void *, int, unsigned);

extern "C" int *func_002B4FE8(void *, int);

// FUNCTION: GAME 0x2B5BB8
extern "C" void func_002B5BB8(void *a, int b, int c)
{
    int *p = func_002B4FE8(a, c);
    void *h = (void *)p[1];
    if (p[0]) {
        free__5cHeapPv(h, (void *)p[0]);
    }
    p[0] = 0;
    p[1] = 0;
}

extern int *D_007479F4;
extern "C" void stopSeq__7cPadVib(void *);

// FUNCTION: GAME 0x2BDB78
extern "C" void func_002BDB78(int *self)
{
    int *t = D_007479F4;
    self[0] = t[1] + (int)t;
    stopSeq__7cPadVib(self);
    self[4] |= 1;
}

extern unsigned D_00747A78;
extern "C" void func_002C1618(char *);

// FUNCTION: GAME 0x2C14F8
extern "C" void func_002C14F8(char *self)
{
    if (!(D_00747A78 & 0x100000)) {
        *(int *)(self + 0x60) = 0;
        *(int *)(self + 0x68) = 0;
        *(int *)(self + 0x6C) = 0;
        *(int *)(self + 0x70) = 0;
        self[0x64] = 0;
        func_002C1618(self);
    }
}

extern char D_005E9CB8[];

class cRoomSave {
public:
    void systemInit();
};

// FUNCTION: GAME 0x2BEB80
void cRoomSave::systemInit()
{
    memset(D_005E9CB8, 0, 0x9C30);
    memset((char *)this + 8, 0, 0x1650);
    *(int *)this = 0;
}

class cScrSpriteDraw {
public:
    void drawInit();
};

// near-miss: 11 differing words; store order differs (original: 0x8, 0x30, 0x2C, 0x28, 0x24..0xC, with constants loaded as 5, 6, 0xFFFF)
#ifdef NONMATCHING
// DRAFT: GAME 0x2C54E8
void cScrSpriteDraw::drawInit()
{
    float *f = (float *)this;
    f[2] = 1.0f;
    *(unsigned short *)((char *)this + 0x30) = 0xFFFF;
    *(int *)((char *)this + 0x2C) = 5;
    *(int *)((char *)this + 0x28) = 6;
    f[9] = 1.0f;
    f[8] = 1.0f;
    f[7] = 1.0f;
    f[6] = 1.0f;
    f[5] = 1.0f;
    f[4] = 1.0f;
    f[3] = 1.0f;
}
#endif

extern int D_005FEE1C;

// FUNCTION: GAME 0x2CE3E8
extern "C" void func_002CE3E8(int *self)
{
    int *prev = (int *)self[0];
    if (prev) {
        prev[1] = self[1];
    } else {
        D_005FEE1C = self[1];
    }
    int *next = (int *)self[1];
    if (next) {
        next[0] = self[0];
    }
    self[14] = 0;
    self[15] = 0;
    self[5] = 0;
}

// FUNCTION: GAME 0x2C7F88
extern "C" int func_002C7F88(unsigned char *p)
{
    if (!p) {
        return 0;
    }
    return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24)) == 0x514553;
}

extern "C" void func_002BE6C8(int *);

// FUNCTION: GAME 0x2BE5F0
extern "C" void func_002BE5F0(int *self)
{
    func_002BE6C8(self);
    char *p = (char *)self[0];
    if (p) {
        free__5cHeapPv(*(void **)(p - 0x20), p);
    }
    ((char *)self)[4] = 0;
    self[0] = 0;
}

extern char CoreSave;
extern "C" int getSkill__9cCoreSave8PL_SKILL(void *, int);

// FUNCTION: GAME 0x2C9AD0
extern "C" int func_002C9AD0(char *self, int idx)
{
    if (!*(int *)self) {
        return 0;
    }
    return getSkill__9cCoreSave8PL_SKILL(&CoreSave, (self + idx)[0x14]) == 1;
}

// FUNCTION: GAME 0x2B8D88
extern "C" void func_002B8D88(char *self, int mode, int a, int b)
{
    int *p = (int *)(self + 0x1C);
    if (mode == 1) {
        p[a] |= 1 << b;
        p[b] |= 1 << a;
    } else {
        p[a] &= ~(1 << b);
        p[b] |= ~(1 << a);
    }
}

// FUNCTION: GAME 0x2C0D18
extern "C" void AtInit__10cSceAtUnit9eSceAt_id12eAreaHitType12eAreaTrgType8eActType(
    char *self, int id, int hit, int trg, int act)
{
    memset(self, 0, 0x9C);
    self[0x3B] = trg;
    self[0x38] = hit;
    self[0x3A] = act;
    self[0x35] = id;
    *(unsigned short *)(self + 0x36) = 0xFFFF;
    self[0x34] = 3;
    self[0x39] = 8;
    self[0x54] = 0x31;
}
