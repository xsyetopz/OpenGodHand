// 0x19A0B8-0x19A808 sphere-collider unit initialisers (DRAFT; tail store order unresolved).
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *);

#define FN19A_SPH(NAME, X, Y, Z, K, K2) \
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
    } \
    char *pp = self + 0x620; \
    *(int *)(self + 0x5E8) = 0; \
    *(int *)(self + 0x5E4) = 0; \
    *(int *)(self + 0x5F0) = 0; \
    *(short *)(self + 0x5F6) = 0; \
    *(short *)(self + 0x54A) = 1; \
    *(char **)(self + 0x608) = self + 0x620; \
    *(int *)(self + 0x5EC) = (K); \
    *(short *)(self + 0x548) = 1; \
    *(unsigned char *)(self + 0x60C) = (K2); \
    *(short *)(self + 0x5F4) = -1; \
    func_001C28A0(self); \
    return 1; \
}


#ifdef NONMATCHING
// DRAFT: GAME 0x19A0B8
// diff: 12 words, tail store order and v0/v1 assignment (self+0x620 vs -1); tried pp/m hoisting, 1-move/swap store-order neighbours (best 10 words with e4,f0,e8 head, not applied)
FN19A_SPH(func_0019A0B8, 3.59999990f, 3.5f, 3.59999990f, 7, 7)

// DRAFT: GAME 0x19A328
// diff: 12 words, same tail diff
FN19A_SPH(func_0019A328, 2.79999995f, 2.79999995f, 2.79999995f, 7, 7)

// DRAFT: GAME 0x19A590
// diff: 12 words (constants fixed to 3.6/2.8/2.8), same tail store order/v0-v1 diff; single-store moves reach 10 words with order 5E4,5F0,5E8 head
FN19A_SPH(func_0019A590, 3.59999990f, 2.79999995f, 2.79999995f, 7, 7)

// DRAFT: GAME 0x19A808
// diff: 17 words, same tail diff
FN19A_SPH(func_0019A808, 2.0f, 1.0f, 2.40000010f, 7, 5)
#endif
