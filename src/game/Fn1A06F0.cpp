// Damage-take unit initialisers at 0x1A06F0, 0x1A0BD8, 0x1A3B80.
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *, char, int, short);

#define F1A_HEAD(X, Y, Z) \
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

static inline void F1ATail(char *self, int a, int b, int c)
{
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = a;
    *(int *)(self + 0x5EC) = b;
    *(short *)(self + 0x5F6) = c;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, a, b, c);
}
#define F1A_TAIL(A, B, C) F1ATail(self, A, B, C);

#ifdef NONMATCHING
// DRAFT: GAME 0x1A06F0
extern "C" int func_001A06F0(char *self)
{
    F1A_HEAD(1.2f, 1.5f, 1.2f)
    F1A_TAIL(6, 0x11, 0x2E)
    return 1;
}
#endif
