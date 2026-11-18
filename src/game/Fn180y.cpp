// Near-miss drafts for small cOm* units in 0x180000-0x1C0000 (ee-gcc2.95.3-136, C++).
#ifdef NONMATCHING
extern const unsigned char D_00422A10[];
extern const unsigned char D_00427948[];
extern unsigned D_00747A78[];
extern char *g_Sce;
struct E {
    char p[0x50];
    unsigned char f;
    char q[7];
};
extern "C" void func_001B6FB8(void *);
extern char g_DmgManage[];
struct V4 {
    float x, y, z, w;
};
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(void *, int, void *);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" int AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, void *, void *, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void func_001C28A0(void *);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *, void *);
extern "C" void SetInitialPosition__5cOl30RC4cVecT1(void *, void *, void *);
extern "C" void func_001A9210(void *, void *, void *);
extern "C" void KeyStop__Fv(void);
extern "C" void func_001BF8C8(void *);
extern "C" int taskExec__9cScenarioPvT1i(void *, void *, void *, int);

static inline int InRangeo(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotNo(char *o, int i)
{
    if ((unsigned char)InRangeo(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}

// DRAFT: GAME 0x182958
// diff: 17 words; original keeps a zero register for the i >= 0 test and builds the flag with slt/bnez, not bltz/movz
extern "C" int func_00182958(char *self)
{
    func_001B6FB8(self);
    SetInitialPosition__5cOl30RC4cVecT1(self, *(void **)(self + 0xF0), self + 0x100);
    for (int j = 0; j < 7; j++) {
        int idx = D_00422A10[j];
        int k = 0;
        do {
            char *p = SlotNo(self, idx);
            *(int *)(p + 0x154) |= 0x18;
            idx++;
        } while (--k >= 0);
    }
    return 1;
}

// DRAFT: GAME 0x1A8980
// diff: 10 words; same zero-register range test as 0x182958 (bltz/movz instead of slt/bnez)
extern "C" int func_001A8980(char *self)
{
    func_001B6FB8(self);
    func_001A9210(self, *(void **)(self + 0xF0), self + 0x100);
    int i = 0;
    do {
        int q = i / 2;
        int r = i - q * 2;
        for (int k = 1; k < 5; k++) {
            if (r == 0) {
                char *p = SlotNo(self, D_00427948[q] + k - 1);
                *(int *)(p + 0x154) |= 0x18;
            }
        }
        i++;
    } while (i < 3);
    *(int *)(self + 0x5A0) |= 0x10;
    return 1;
}

// DRAFT: GAME 0x1BF7D8
// diff: 18 words; original keeps i in v0 (bltz v0, mult v0) and loads g_Sce into a0 first; mine copies i to a0; tried E* temp, i*0x58 byte math, goto, long i, int-cast table
extern "C" void func_001BF7D8(char *self)
{
    (*(unsigned char *)(self + 0x2F5))++;
    unsigned f = D_00747A78[0];
    f |= 0x80000000;
    f |= 0x40000000;
    f |= 0x20000000;
    f |= 0x10000000;
    f |= 0x8000000;
    f |= 0x4000000;
    f |= 0x800000;
    f |= 0x400000;
    f |= 0x100000;
    D_00747A78[2] |= 0x100000;
    D_00747A78[0] = f;
    KeyStop__Fv();
    int i = taskExec__9cScenarioPvT1i(g_Sce, (void *)func_001BF8C8, self, 1);
    if (i >= 0)
        (*(E **)(g_Sce + 0x1C))[i].f |= 1;
    *(unsigned *)(g_Sce + 0x48) |= 1;
}

// Sphere-collider unit initialisers: bodies match through the last call; the constant registers of the tail stores differ.
#define FN180_HEAD(X, Y, Z) \
    func_001B6FB8(self); \
    V4 a, b, c, d; \
    V4 *pa = &a; \
    V4 *pb = &b; \
    V4 *pc = &c; \
    a.x = (X); \
    a.y = (Y); \
    a.z = (Z); \
    pa->w = 1.0f; \
    b.x = (X); \
    b.y = (Y); \
    b.z = (Z); \
    pb->w = 1.0f; \
    c.x = 0; \
    c.y = 0; \
    c.z = 0; \
    pc->w = 1.0f; \
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2); \
    *(void **)(self + 0x600) = t; \
    if (t) { \
        V4 *pd = &d; \
        d.x = 0; \
        d.y = 0; \
        d.z = 0; \
        pd->w = 1.0f; \
        func_001FD9D8(t, self + 0x80, &c, &d, &b); \
    }

#define FN180_GIVE \
    void *g = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 0, self); \
    *(void **)(self + 0x604) = g; \
    if (g) { \
        V4 *pd = &d; \
        d.x = 0; \
        d.y = 0; \
        d.z = 0; \
        pd->w = 1.0f; \
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(g, self + 0x80, &d, 2.0f); \
        *(short *)(*(char **)(self + 0x604) + 0x46) = 0x2E; \
        *(int *)(*(char **)(self + 0x604) + 0x4C) = 0; \
        SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x604), 0); \
    }

// DRAFT: GAME 0x191B98
// diff: 12 words (local-decl permutations 11-12, plain constants 15); the 0x54A store is scheduled last and the tail constants take other registers (raw casts and ordered locals tried)
extern "C" int func_00191B98(char *self)
{
    FN180_HEAD(4.3358001708984375f, 0.9010000228881836f, 0.17759999632835388f)
    int one = 1;
    int pp = (int)(self + 0x620);
    int six = 6;
    int seven = 7;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(int *)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = six;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x187838
// diff: 12 words; hoisted k1/pp/eight/s11/s89 locals fixed constants (15->12); 54A store lands last (delay slot) and -1 loads early; 11 random store perms and moving 54A did not help
extern "C" int func_00187838(char *self)
{
    FN180_HEAD(2.0f, 2.0f, 1.60000002f)
    int k1 = 1;
    int pp = (int)(self + 0x620);
    int eight = 8;
    int s11 = 0x11;
    int s89 = 0x89;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(int *)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = eight;
    *(int *)(self + 0x5EC) = s11;
    *(short *)(self + 0x5F6) = s89;
    *(short *)(self + 0x548) = k1;
    *(short *)(self + 0x5F4) = -1;
    *(short *)(self + 0x54A) = k1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x182690
// diff: 11 words; tail constants take other regs and 0x54A store lands last; tried named temps (k1,pp,eight,seven,m1) in all 24 orders of the first four, best 11
extern "C" int func_00182690(char *self)
{
    FN180_HEAD(3.240000009536743f, 1.0f, 1.0f)
    FN180_GIVE
    int k1 = 1;
    int eight = 8;
    int pp = (int)(self + 0x620);
    int seven = 7;
    int m1 = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = k1;
    *(int *)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = eight;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = k1;
    *(short *)(self + 0x5F4) = m1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x183650
// diff: 17 words; same tail register choice; the |= 2 on 0x5B8 and the 0x548 store are scheduled differently
extern "C" int func_00183650(char *self)
{
    FN180_HEAD(1.0f, 1.0f, 1.0f)
    FN180_GIVE
    int k1 = 1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = k1;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x5F4) = -1;
    *(short *)(self + 0x548) = k1;
    *(short *)(self + 0x54A) = k1;
    *(unsigned *)(self + 0x5B8) |= 2;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x195D08
// diff: 39 words; float constants load in a different order (2.4f first) and the tail constants take other registers
extern "C" int func_00195D08(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    a.x = 5.19999981f;
    a.y = 0.800000012f;
    a.z = 2.4000001f;
    pa->w = 1.0f;
    b.x = 5.19999981f;
    b.y = 0.800000012f;
    b.z = 2.4000001f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = -0.400000006f;
    c.z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        V4 *pd = &d;
        d.x = 0;
        d.y = 0;
        d.z = 0;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    **(unsigned **)(self + 0x600) |= 1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x5F6) = 10;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}
#endif
