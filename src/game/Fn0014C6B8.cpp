// Units at 0x14C6B8, 0x188DE0, 0x18EAF8.
extern int D_007476B0;
extern char D_00754C80[];
extern char g_DmgManage[];
extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" void func_0031A600(void *, int, int, char *);
extern "C" void func_0031A650(void *, int, int, char *);
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);

struct Vec4 {
    float x, y, z, w;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x14C6B8 - 6 words differ, same size: compiler puts fl in a0 and p in v1, original has fl in v1 and p in t0. Tried decl order, int/pointer p, named mesh local, inline e+0x70, int fl.
extern "C" void func_0014C6B8(char *self, short h)
{
    int i = D_007476B0 & 1;
    char *q = self + 0x220;
    char *e = *(char **)((int)q + (i << 2));
    char *mesh = getMeshPtr__6cModeli(self, 0);
    int fl = *(int *)(mesh + 0x380);
    int s = *(int *)(self + 0x2C0);
    int p = (int)e + 0x70;
    if (s == 10) {
        if (fl & 0x4080) {
            if (p == 0)
                func_0031A600(D_00754C80, 2, h, e);
            else
                func_0031A650(D_00754C80, 2, h, e);
            return;
        }
        if (p == 0)
            func_0031A600(D_00754C80, 1, 13, e);
        else
            func_0031A650(D_00754C80, 1, 13, e);
        return;
    }
    if (p == 0)
        func_0031A600(D_00754C80, s, *(short *)(self + 0x2AC), e);
    else
        func_0031A650(D_00754C80, s, *(short *)(self + 0x2AC), e);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x188DE0 - 29 words differ, 312 vs 300 bytes: tail constants load in a different order (original: t0=1, v1=p, a1=8, a2=7, a3=4 before the first zero store; draft loads a3=7 first and stores 5EC early). Tried field-wise vec init, by-value Vec4 arg, hoisted tail constants with m1, short/int one, inline -1 at 5F4, inline 1 at 54A/548, reordered tail locals.
extern "C" int func_00188DE0(char *self)
{
    func_001B6FB8(self);
    Vec4 a, b, c, d;
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    Vec4 *pc = &c;
    a.x = 4.4f;
    a.y = 3.0f;
    a.z = 0.6f;
    pa->w = 1.0f;
    b.x = 4.4f;
    b.y = 3.0f;
    b.z = 0.6f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        Vec4 *pd = &d;
        d.x = 0;
        d.y = 0;
        d.z = 0;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    int four = 4;
    int seven = 7;
    int eight = 8;
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = eight;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x5F6) = four;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, (char *)eight, seven, four);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x18EAF8 - 25 words differ, 312 vs 300 bytes: original sets v1=1 first and computes self+0x620 straight into a1 (kept for the call); draft computes it into t2 and copies late. Tried by-value Vec4 arg, int one hoist, short m1, inline self+0x620, hoisted six/seven, volatile on 54A/608 (28 words, reverted), named p local with short one (both decl orders).
extern "C" int func_0018EAF8(char *self)
{
    func_001B6FB8(self);
    Vec4 a, b, c, d;
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    Vec4 *pc = &c;
    a.x = 0.4f;
    a.y = 1.2218f;
    a.z = 4.672f;
    pa->w = 1.0f;
    b.x = 0.4f;
    b.y = 1.2218f;
    b.z = 4.672f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        Vec4 *pd = &d;
        d.x = 0;
        d.y = 0;
        d.z = 0;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    char *p = self + 0x620;
    short one = 1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 6;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, p, 6, 7);
    return 1;
}
#endif
