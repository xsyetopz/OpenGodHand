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
// DRAFT: GAME 0x19BCA0 - 15 words differ: tail const-load/store order (orig 1,pp,0xC,7 in v1,a1-a3; 54A not last); 4-arg call decl worse (25), store permutations no effect.
extern "C" int func_0019BCA0(char *self)
{
    F19B_HEAD(4.0f, 1.0f, 2.0f)
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 0xC;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x1A0208 - 17 words differ: same tail const/store order issue as 0x19BCA0.
extern "C" int func_001A0208(char *self)
{
    F19B_HEAD(1.0f, 2.0f, 1.0f)
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 0x11;
    *(short *)(self + 0x5F6) = 0x2E;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x1A0968 - 17 words differ: identical code to 0x1A0208.
extern "C" int func_001A0968(char *self)
{
    F19B_HEAD(1.0f, 2.0f, 1.0f)
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 0x11;
    *(short *)(self + 0x5F6) = 0x2E;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}
#endif
