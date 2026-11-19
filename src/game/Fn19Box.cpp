// Damage-take box initializers in .text 0x190000-0x19FFFF.
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *);

#ifdef NONMATCHING
#define FN19_BOX(NAME, X, Y, Z, K) \
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
    char k = (K); \
    void *p = self + 0x620; \
    *(int *)(self + 0x5E8) = 0; \
    *(int *)(self + 0x5E4) = 0; \
    *(int *)(self + 0x5F0) = 0; \
    *(short *)(self + 0x5F6) = 0; \
    *(short *)(self + 0x54A) = 1; \
    *(void **)(self + 0x608) = p; \
    *(char *)(self + 0x60C) = k; \
    *(int *)(self + 0x5EC) = 7; \
    *(short *)(self + 0x548) = 1; \
    *(short *)(self + 0x5F4) = -1; \
    func_001C28A0(self); \
    return 1; \
}

// DRAFT: GAME 0x1932D8
// 11 words differ: constants land in rotated registers (1,4,7,-1) and sh 54A sits in the jal delay slot. Tried: void *p hoisted (74), short one=1 (74), seven/neg locals (12), char k for the 60C store (11, kept).
FN19_BOX(func_001932D8, 0.8f, 1.7f, 0.8f, 4)

// DRAFT: GAME 0x19BF10
// 11 words differ, same tail as 0x1932D8.
FN19_BOX(func_0019BF10, 1.4f, 2.2f, 1.4f, 8)

// DRAFT: GAME 0x19E530
// 11 words differ, same tail as 0x1932D8.
FN19_BOX(func_0019E530, 3.4f, 1.0f, 2.0f, 10)
#endif
