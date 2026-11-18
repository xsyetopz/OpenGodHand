// Units in .text 0x170000-0x17FFFF: damage-check handlers.
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);

#define FN170_HIT(NAME, ARR, N)                                                 \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        unsigned short *hp = (unsigned short *)(self + ARR);                                      \
        void **dp = (void **)(self + 0x600);                                    \
        for (int i = 0; i < N; i++, hp++, dp++) {                               \
            int r = checkDamage__7cOmBaseP11cDamageTake(self, *dp);            \
            if (r == 1) {                                                       \
                int d = *(int *)((char *)*dp + 0x4C);                           \
                int t = *hp - d;                                                \
                *hp = t;                                                        \
                if ((short)t < 0) {                                                \
                    *(unsigned char *)(self + ARR + 4) = i;                     \
                    *(unsigned char *)(self + 0x2F4) = 2;                       \
                    *(unsigned char *)(self + 0x2F5) = 0;                       \
                    *(unsigned char *)(self + 0x2F6) = 0;                       \
                    *(unsigned char *)(self + 0x2F7) = 0;                       \
                    *(int *)(self + 0x5B0) |= 1;                                \
                } else {                                                        \
                    *(unsigned char *)(self + 0x2F4) = r;                       \
                    *(unsigned char *)(self + 0x2F5) = 0;                       \
                    *(unsigned char *)(self + 0x2F6) = 0;                       \
                    *(unsigned char *)(self + 0x2F7) = 0;                       \
                }                                                               \
            }                                                                   \
        }                                                                       \
    }

// FUNCTION: GAME 0x175E00
FN170_HIT(func_00175E00, 0xD38, 2)
// FUNCTION: GAME 0x177488
FN170_HIT(func_00177488, 0xD38, 2)

extern "C" void func_001731B8(void *);
extern "C" void func_001B7EE0(void *, float);
extern "C" void func_00173258(void *);

// FUNCTION: GAME 0x172490
extern "C" void func_00172490(char *self)
{
    unsigned short *hp = (unsigned short *)(self + 0xD98);
    void **dp = (void **)(self + 0x600);
    for (int i = 0; i < 1; hp++, i++, dp++) {
        int r = checkDamage__7cOmBaseP11cDamageTake(self, *dp);
        if (r == 1) {
            int d = *(int *)((char *)*dp + 0x4C);
            int t = *hp - d;
            *hp = t;
            if ((short)t < 0) {
                *(unsigned char *)(self + 0x2F4) = 2;
                *(unsigned char *)(self + 0x2F5) = 0;
                *(unsigned char *)(self + 0x2F6) = 0;
                *(unsigned char *)(self + 0x2F7) = 0;
                *(int *)(self + 0x5B0) |= 1;
                *(unsigned char *)(self + 0xD9A) = i;
            } else {
                func_001731B8(self);
            }
        }
    }
    func_001B7EE0(self, 2.5f);
    func_00173258(self);
}

extern "C" int func_0017B810(void *);
extern "C" void func_0017AEA0(void *);
extern "C" void func_0017AEB0(void *);
extern "C" void setClose__5cOl1b(void *);
extern "C" int isActive__5cOl1b(void *);

// FUNCTION: GAME 0x17B010
extern "C" void func_0017B010(char *self)
{
    if (*(unsigned char *)(self + 0x602) == 0) {
        int v = func_0017B810(self);
        if (v == 1 && checkDamage__7cOmBaseP11cDamageTake(self, *(void **)(self + 0x60C)) == v) {
            *(float *)(self + 0x54C) = 3.0f;
            if (*(short *)(self + 0x54A) <= 0)
                setClose__5cOl1b(self);
            else
                func_0017AEA0(self);
        }
    }
    func_0017AEB0(self);
    if (func_0017B810(self) == 1 && !isActive__5cOl1b(self))
        func_001B7EE0(self, 2.0f);
}

#ifdef NONMATCHING
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void func_001C28A0(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" int AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(void *, void *, void *, void *, float, float);

#define FN170_INIT(NAME)                                                                                   \
    extern "C" int NAME(char *self)                                                                        \
    {                                                                                                      \
        func_001B6FB8(self);                                                                               \
        V4 c, d;                                                                                           \
        V4 *pc = &c;                                                                                       \
        c.x = 0;                                                                                           \
        c.y = 0;                                                                                           \
        c.z = 0;                                                                                           \
        pc->w = 1.0f;                                                                                      \
        void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);              \
        *(void **)(self + 0x600) = t;                                                                      \
        if (t) {                                                                                           \
            V4 *pd = &d;                                                                                   \
            d.x = 0;                                                                                       \
            d.y = 0;                                                                                       \
            d.z = 0;                                                                                       \
            pd->w = 1.0f;                                                                                  \
            AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(t, self + 0x80, &c, &d, 4.0f, 0.8f); \
        }                                                                                                  \
        *(short *)(self + 0x5F4) = -1;                                                                     \
        *(unsigned char *)(self + 0x60C) = 8;                                                              \
        *(void **)(self + 0x608) = self + 0x620;                                                           \
        *(short *)(self + 0x548) = 1;                                                                      \
        *(short *)(self + 0x54A) = 1;                                                                      \
        *(int *)(self + 0x5E8) = 0;                                                                        \
        *(int *)(self + 0x5E4) = 0;                                                                        \
        *(int *)(self + 0x5F0) = 0;                                                                        \
        *(int *)(self + 0x5EC) = 0;                                                                        \
        *(short *)(self + 0x5F6) = 0;                                                                      \
        func_001C28A0(self);                                                                               \
        return 1;                                                                                          \
    }

// DRAFT: GAME 0x170050
// Diff: body matches through the call; 12 words differ in the tail (constant register choice and store scheduling after AddDamageCollCylinder)
FN170_INIT(func_00170050)

#endif

// Constructors of the 0x160-byte element objects (cOl*-style units).
struct Q16 {
    float f[4];
} __attribute__((aligned(16)));
#define QZ16(p, o) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q16 *)((char *)(p) + (o))))
extern "C" void *func_001B6E90(void *);
extern char D_00421FE8[];

#define ELEM_Q(e, b)                                                                                       \
    QZ16(e, (b) + 0x50);                                                                                   \
    QZ16(e, (b) + 0x60);                                                                                   \
    QZ16(e, (b) + 0x70);                                                                                   \
    QZ16(e, (b) + 0x80);                                                                                   \
    QZ16(e, (b) + 0x90);                                                                                   \
    QZ16(e, (b) + 0xA0);                                                                                   \
    QZ16(e, (b) + 0xB0);                                                                                   \
    QZ16(e, (b) + 0xC0);                                                                                   \
    QZ16(e, (b) + 0xD0);                                                                                   \
    QZ16(e, (b) + 0xE0);                                                                                   \
    QZ16(e, (b) + 0xF0);                                                                                   \
    QZ16(e, (b) + 0x100);                                                                                  \
    QZ16(e, (b) + 0x110);                                                                                  \
    QZ16(e, (b) + 0x120)

#define ELEM_REST(e)                                                                                       \
    *(unsigned char *)((e) + 1) = 0;                                                                       \
    *(unsigned char *)((e) + 2) = 0;                                                                       \
    *(int *)((e) + 4) = 0;                                                                                 \
    *(int *)((e) + 8) = 0;                                                                                 \
    *(int *)((e) + 0x30) = 0;                                                                              \
    *(int *)((e) + 0x34) = 0;                                                                              \
    *(int *)((e) + 0x38) = 0;                                                                              \
    *(int *)((e) + 0x3C) = 0;                                                                              \
    *(int *)((e) + 0x130) = 0;                                                                             \
    *(int *)((e) + 0x134) = 0;                                                                             \
    *(int *)((e) + 0x138) = 0;                                                                             \
    *(int *)((e) + 0x13C) = 0

// FUNCTION: GAME 0x17E0F8
extern "C" void *func_0017E0F8(char *self)
{
    func_001B6E90(self);
    char *e = self + 0x610;
    *(char **)(self + 0x214) = D_00421FE8;
    ELEM_Q(self, 0x610);
    *(unsigned char *)(self + 0x610) = 0;
    ELEM_REST(e);
    unsigned i = 0;
    int *w = (int *)(self + 0x61C);
    do {
        *w = 0;
        i++;
        w++;
    } while (i < 8);
    QZ16(self, 0x770);
    return self;
}

extern char D_00421A08[];

#define ELEM_LOOP(base)                                                                                    \
    {                                                                                                      \
        unsigned i = 0;                                                                                    \
        int *w = (int *)(self + (base) + 0xC);                                                             \
        do {                                                                                               \
            *w = 0;                                                                                        \
            i++;                                                                                           \
            w++;                                                                                           \
        } while (i < 8);                                                                                   \
    }

// FUNCTION: GAME 0x17AAD8
extern "C" void *func_0017AAD8(char *self)
{
    func_001B6E90(self);
    char *e = self + 0x610;
    *(char **)(self + 0x214) = D_00421A08;
    ELEM_Q(self, 0x610);
    *(unsigned char *)(self + 0x610) = 0;
    ELEM_REST(e);
    ELEM_LOOP(0x610)
    char *f = self + 0x770;
    ELEM_Q(self, 0x770);
    *(unsigned char *)(self + 0x770) = 0;
    ELEM_REST(f);
    ELEM_LOOP(0x770)
    QZ16(self, 0x8D0);
    return self;
}

extern char D_00422560[];

// FUNCTION: GAME 0x17FB48
extern "C" void *func_0017FB48(char *self)
{
    func_001B6E90(self);
    char *e = self + 0x600;
    *(char **)(self + 0x214) = D_00422560;
    int n = 2;
    do {
        ELEM_Q(e, 0);
        *(unsigned char *)e = 0;
        char *nx = e + 0x160;
        ELEM_REST(e);
        {
            unsigned i = 0;
            int *w = (int *)(e + 0xC);
            do {
                *w = 0;
                i++;
                w++;
            } while (i < 8);
        }
        e = nx;
    } while (--n != -1);
    return self;
}
