// Constructor and collision-box units in .text 0x170000-0x17FFFF.
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);

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

extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001BFB28(void *);

#define FN170_BOX(NAME, X, Y, Z) \
extern "C" int NAME(char *self) \
{ \
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
    c.y = b.y * -0.5f; \
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
    } \
    *(short *)(self + 0x548) = 1; \
    *(short *)(self + 0x54A) = 1; \
    func_001BFB28(self); \
    return 1; \
}

// FUNCTION: GAME 0x1705D0
FN170_BOX(func_001705D0, 3.1f, 2.91f, 0.2f)

// FUNCTION: GAME 0x170860
FN170_BOX(func_00170860, 3.07599998f, 0.773999989f, 0.763999999f)

// FUNCTION: GAME 0x170AF0
FN170_BOX(func_00170AF0, 2.76600003f, 0.773999989f, 0.763999999f)

// FUNCTION: GAME 0x170D80
FN170_BOX(func_00170D80, 3.29200006f, 0.773999989f, 0.698000014f)
