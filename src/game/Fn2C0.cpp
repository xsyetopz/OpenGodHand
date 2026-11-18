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

#ifdef NONMATCHING
// DRAFT: GAME 0x2B8D88 - prologue/reg copies of a,b differ (140 vs 136 bytes)
extern "C" void func_002B8D88(char *self, int mode, int a, int b)
{
    int x = a;
    int y = b;
    if (mode == 1) {
        int *p = (int *)(self + 0x1C);
        p[x] |= 1 << y;
        p[y] |= 1 << x;
    } else {
        int *p = (int *)(self + 0x1C);
        p[x] &= ~(1 << y);
        p[y] |= ~(1 << x);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2C0D18 - s3/s4 param regs and const-store order differ (8 words)
extern "C" void AtInit__10cSceAtUnit9eSceAt_id12eAreaHitType12eAreaTrgType8eActType(
    char *self, int id, int hit, int trg, int act)
{
    memset(self, 0, 0x9C);
    self[0x35] = id;
    self[0x3A] = act;
    self[0x38] = hit;
    self[0x3B] = trg;
    self[0x54] = 0x31;
    self[0x39] = 8;
    self[0x34] = 3;
    *(unsigned short *)(self + 0x36) = 0xFFFF;
}
#endif

extern "C" void *Font;
extern "C" unsigned char func_002A4C00(void *, unsigned);
extern "C" void func_002B3460(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B33D8 - dsrl/andi bit tests emitted with extra sign-extends (26 words)
extern "C" void func_002B33D8(char *self)
{
    if (*(int *)(self + 0x1C)) {
        unsigned char v = func_002A4C00(Font, **(unsigned short **)(self + 0x8C));
        unsigned long f = *(unsigned long *)(self + 0x14);
        if ((f >> 1) & 1) {
            if (!((f >> 2) & 1)) {
                if (!(v & 1)) {
                    func_002B3460(self);
                    return;
                }
            }
        }
        *(unsigned *)(self + 0x14) |= 2;
    }
}
#endif

struct SeData12 {
    char c[12];
};
extern "C" void *memcpy(void *, const void *, unsigned);

// FUNCTION: GAME 0x2C7DA8
extern "C" SeData12 Motion_seq_readSeData__FPvUc(void *src, unsigned char flag)
{
    SeData12 t;
    memset(&t, 0, 12);
    if (flag == 1) {
        memcpy(&t, src, 12);
    }
    return t;
}

struct VtEnt {
    short off;
    short pad;
    void *(*fn)(void *, ...);
};
struct VtBase {
    char _p[0x10];
    short off0;
    short pad0;
    void *(*fn0)(void *, int);
    char _q[8];
    short off1;
    short pad1;
    void (*fn1)(void *, void *, int);
};
extern "C" void func_002A7280(void *, unsigned);

#ifdef NONMATCHING
// DRAFT: GAME 0x2BA1C8 - prologue schedules daddu s0,a0 before sq s1 (2 words)
extern "C" int func_002BA1C8(char *self, int n)
{
    char *p = self;
    int k = n;
    func_002A7280(self, n);
    self = p;
    n = k;
    VtBase *vt = *(VtBase **)(self + 0x18);
    void *v = vt->fn0(self + vt->off0, *(int *)(self + 8) * n);
    *(int *)(self + 4) = n;
    *(void **)self = v;
    if (n) {
        VtBase *vt2 = *(VtBase **)(self + 0x18);
        vt2->fn1(self + vt2->off1, v, *(int *)(self + 8) * n);
    }
    return 1;
}
#endif

extern "C" unsigned func_002BEDD8(void *);
extern "C" char *func_002BEF08(void *, unsigned);

#ifdef NONMATCHING
// DRAFT: GAME 0x2BF078 - loop-back uses bnez+b instead of bnel with delay-slot arg setup (19 words)
extern "C" int clearEmDeadFlag__9cRoomSaveUi(void *self, unsigned id)
{
    unsigned i;
    for (i = 0; i < func_002BEDD8(self);) {
        char *r = func_002BEF08(self, i++);
        if (r && (unsigned char)r[0x13] == id) {
            r[0x14] = 0;
            return 1;
        }
    }
    return 0;
}
#endif

extern "C" char *getUnit__13cSceAtManagerUi(void *, unsigned);
extern "C" int func_002C0ED0(void *, int);
extern "C" void *GetSeData__4cSndi(void *, int);
extern "C" int func_002CF6F8(void *, int, int);
extern "C" int execute__12cTaskManagerRFPv_vPvi(void *, void *, void *, int);
extern "C" void func_002C3968(void *, int);
extern "C" void func_003734F0(void *);
extern "C" int func_002CC568(void *);

// FUNCTION: GAME 0x2C2A98
extern "C" int isHit__13cSceAtManagerUi11eScehitType(void *self, unsigned id, int type)
{
    char *u = getUnit__13cSceAtManagerUi(self, id);
    if (!u) {
        return 0;
    }
    return func_002C0ED0(u, type);
}

// FUNCTION: GAME 0x2CB6A0
extern "C" int func_002CB6A0(void *a, int b, int c)
{
    return func_002CF6F8(GetSeData__4cSndi(a, b), b, c);
}

// FUNCTION: GAME 0x2C38D8
extern "C" int func_002C38D8(char *self, void *fn, void *arg, int n)
{
    int r = execute__12cTaskManagerRFPv_vPvi(self + 0x1C, fn, arg, n);
    func_002C3968(self, r);
    return r;
}

// FUNCTION: GAME 0x2C8EB0
extern "C" void func_002C8EB0(int *self)
{
    self[0] = 0;
    memset(self + 1, 0, 12);
    memset(self + 5, 0, 0x80);
}

// FUNCTION: GAME 0x2CCAC8
extern "C" void func_002CCAC8(char *self)
{
    if (func_002CC568(self)) {
        *(unsigned *)(self + 0x98) &= 0xFFFFFFFE;
        func_003734F0(self);
    }
}

extern "C" void func_00373430(void *);
extern "C" void func_003733C8(void *);
extern "C" void func_002CC5E8(void *);
extern "C" void func_002CD890(int, int);
extern "C" void SetBgmState__4cSnd9eBgmState(void *, int);
extern "C" void func_002CBE68(void *, int, int);
extern "C" void func_002CFC98(void *);
extern "C" void func_002C3040(void *, void *, void *);

// FUNCTION: GAME 0x2CCB10
extern "C" void func_002CCB10(void *self)
{
    if (func_002CC568(self)) {
        func_00373430(self);
        func_003733C8(self);
        func_002CC5E8(self);
    }
}

// FUNCTION: GAME 0x2CD780
extern "C" void func_002CD780(char *self)
{
    if (*(int *)(self + 0x380)) {
        int a = *(int *)(self + 0x388);
        if (a) {
            func_002CD890(*(int *)(self + 0x38C), a);
        }
        *(int *)(self + 0x380) = 0;
    }
}

// FUNCTION: GAME 0x2C8E60
extern "C" int *func_002C8E60(int *self)
{
    self[0] = 0;
    memset(self + 1, 0, 12);
    memset(self + 5, 0, 0x80);
    return self;
}

// FUNCTION: GAME 0x2CA8C8
extern "C" void func_002CA8C8(char *self)
{
    SetBgmState__4cSnd9eBgmState(self, 0);
    unsigned a = *(unsigned *)(self + 0xB0);
    unsigned b = *(unsigned *)(self + 0xAC);
    *(unsigned *)(self + 0xB0) = a & 0xFFBFFFFF;
    *(unsigned *)(self + 0xAC) = b & 0xFFBFFFFF;
}

// FUNCTION: GAME 0x2CB7E8
extern "C" void func_002CB7E8(void *self, int b)
{
    func_002CBE68(self, b, 1);
    func_002CFC98(GetSeData__4cSndi(self, b));
}

// FUNCTION: GAME 0x2C2F90
extern "C" void addUnitData__13cSceAtManagerP10cSceAtUnit12eScePriorityP4cObjs(
    char *self, char *unit, int prio, void *obj, short n)
{
    if (unit) {
        *(void **)(unit + 0x48) = obj;
        *(short *)(unit + 0x4C) = n;
        unit[0x39] = prio;
        func_002C3040(self, self + 0x20 + prio * 4, unit);
    }
}
