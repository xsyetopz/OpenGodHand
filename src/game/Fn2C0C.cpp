// Second half of Fn2C0 (split to keep files under 300 lines).
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void *memset(void *, int, unsigned);

extern "C" int *func_002B4FE8(void *, int);

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
extern "C" void func_002A7280(void *);

// FUNCTION: GAME 0x2BA1C8
// func_002A7280 takes only self; declaring a second arg changed the prologue schedule
extern "C" int func_002BA1C8(char *self, int n)
{
    func_002A7280(self);
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
