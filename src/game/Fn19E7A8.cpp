// Unit initialisers at 0x19E7A8, 0x19ECA0, 0x19EF18, 0x19FF90, 0x1A0478 (stack-vector damage-take setup).
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *);

#define F19E_HEAD(X, Y, Z) \
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
// DRAFT: GAME 0x19E7A8 - 9 words differ: only reg naming (orig v1=1,a1=pp,v0=-1; ours a1=1,v0=pp,v1=-1); ~100 random variants of temps/literals/decl position/store order, 4-arg callee (25, worse); also typed struct (12), inline helper with pp param (12), negative offsets from pp (25), (short)0xFFFF (12), unsigned short temp (11).
extern "C" int func_0019E7A8(char *self)
{
    F19E_HEAD(0.8f, 1.15f, 0.8f)
    int six = 6;
    int seven = 7;
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = six;
    *(short *)(self + 0x548) = 1;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x19ECA0 - same tail issue as 0x19E7A8; 11 words differ.
extern "C" int func_0019ECA0(char *self)
{
    F19E_HEAD(0.6f, 0.7f, 0.6f)
    int one = 1;
    int four = 4;
    int k = 0xF;
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(int *)(self + 0x5EC) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = four;
    *(short *)(self + 0x5F6) = k;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x19EF18 - same tail issue as 0x19E7A8; 10 words differ.
extern "C" int func_0019EF18(char *self)
{
    F19E_HEAD(0.6f, 0.7f, 0.6f)
    int one = 1;
    int six = 6;
    int seven = 7;
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = six;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x19FF90 - same tail issue as 0x19E7A8; 13 words differ.
extern "C" int func_0019FF90(char *self)
{
    F19E_HEAD(1.2f, 1.5f, 1.2f)
    int one = 1;
    int six = 6;
    int a2 = 0x11;
    int a3 = 0x2E;
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = six;
    *(int *)(self + 0x5EC) = a2;
    *(short *)(self + 0x5F6) = a3;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}

// DRAFT: GAME 0x1A0478 - same tail issue as 0x19E7A8; 13 words differ.
extern "C" int func_001A0478(char *self)
{
    F19E_HEAD(1.2f, 1.5f, 1.2f)
    int one = 1;
    int six = 6;
    int a2 = 0x11;
    int a3 = 0x2E;
    char *pp = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = pp;
    *(unsigned char *)(self + 0x60C) = six;
    *(int *)(self + 0x5EC) = a2;
    *(short *)(self + 0x5F6) = a3;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}
#endif
