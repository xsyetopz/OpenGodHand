// Stack-vector constructor template: four stack V4 temporaries passed to the
// damage-take setup (0x1FD9D8). Same form as FN170_BOX in Fn170n.cpp.
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001BFB28(void *);

#define SVT_BOX(NAME, X, Y, Z, CY) \
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
    c.y = CY * -0.5f; \
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

// FUNCTION: GAME 0x1833E0
SVT_BOX(func_001833E0, 2.7f, 1.7f, 0.2f, b.y)

// FUNCTION: GAME 0x18ED30
SVT_BOX(func_0018ED30, 0.906399965f, 2.0f, 0.2f, a.y)
