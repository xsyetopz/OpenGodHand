// Unit initialisers at 0x19BCA0, 0x1A0208, 0x1A0968 (stack-vector damage-take setup).
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *);

#define F19B_HEAD(X, Y, Z) \
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

#ifdef NONMATCHING
// DRAFT: GAME 0x19BCA0 - 12 words differ (was 15): hoisted consts in orig load order 1,pp,0xC,7,-1; regs a3/v0/v1/a1/a2 vs orig v1/a1/a2/a3/v0; 54A store lands in delay slot. Tried: const decl reorder (one or m1 first/last), 54A store moved first: no change.
extern "C" int func_0019BCA0(char *self)
{
    F19B_HEAD(4.0f, 1.0f, 2.0f)
    short one = 1;
    char *pp = self + 0x620;
    unsigned char c12 = 0xC;
    int c7 = 7;
    short m1 = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = c12;
    *(int *)(self + 0x5EC) = c7;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = m1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x1A0208 - 16 words differ (was 17): hoisted consts (1,pp,5,0x11,0x2E,-1); regs shifted one vs orig; 54A store lands in delay slot.
extern "C" int func_001A0208(char *self)
{
    F19B_HEAD(1.0f, 2.0f, 1.0f)
    short one = 1;
    char *pp = self + 0x620;
    unsigned char c5 = 5;
    int c11 = 0x11;
    short c2e = 0x2E;
    short m1 = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = c5;
    *(int *)(self + 0x5EC) = c11;
    *(short *)(self + 0x5F6) = c2e;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = m1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x1A0968 - 16 words differ: head matches; tail differs from 0x1A0A18 (pp in v0 vs v1; 0x54A store in delay slot where orig has 0x5F4). Same body as the 0x1A0208 draft, hoisted consts variant.
extern "C" int func_001A0968(char *self)
{
    F19B_HEAD(1.0f, 2.0f, 1.0f)
    short one = 1;
    char *pp = self + 0x620;
    unsigned char c5 = 5;
    int c11 = 0x11;
    short c2e = 0x2E;
    short m1 = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = c5;
    *(int *)(self + 0x5EC) = c11;
    *(short *)(self + 0x5F6) = c2e;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = m1;
    func_001C28A0(self);
    return 1;
}

#endif
