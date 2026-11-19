struct Vq {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" int func_001C28A0(char *, char *, int, int);
extern "C" int func_001FD9D8(char *, char *, const Vq &, const Vq &, const Vq &);

// diff: 24 words, pointer-local shape (Vq *pa/pb/pc/pd, int one/five/seven/neg declared in that order after p); remaining diffs in the tail after func_001FD9D8: draft keeps t0-t2/v0 and copies into a1-a3 late, original sets a1-a3 before the first store; tried 120 local declaration orders (best 24, 60 at 25), inlined pointer (25)
// DRAFT: GAME 0x193050
#ifdef NONMATCHING
extern "C" int func_00193050(char *self)
{
    func_001B6FB8(self);
    Vq a, b, c, d;
    Vq *pa = &a;
    Vq *pb = &b;
    Vq *pc = &c;
    a.x = 1.3f;
    a.y = 1.9f;
    a.z = 0.8f;
    pa->w = 1.0f;
    b.x = 1.3f;
    b.y = 1.9f;
    b.z = 0.8f;
    pb->w = 1.0f;
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    pc->w = 1.0f;
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq *pd = &d;
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    int one = 1;
    int five = 5;
    int seven = 7;
    int neg = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = five;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = neg;
    func_001C28A0(self, p, five, seven);
    return 1;
}
#endif

// diff: 24 words expected, same shape as 0x193050 (constants 3.62/1.1591/0.2, tail arg 5); tail register order as 0x193050 unmatched
// DRAFT: GAME 0x193A80
#ifdef NONMATCHING
extern "C" int func_00193A80(char *self)
{
    func_001B6FB8(self);
    Vq a, b, c, d;
    Vq *pa = &a;
    Vq *pb = &b;
    Vq *pc = &c;
    a.x = 3.62f;
    a.y = 1.1591f;
    a.z = 0.2f;
    pa->w = 1.0f;
    b.x = 3.62f;
    b.y = 1.1591f;
    b.z = 0.2f;
    pb->w = 1.0f;
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    pc->w = 1.0f;
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq *pd = &d;
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    int one = 1;
    int five = 5;
    int seven = 7;
    int neg = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = five;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = neg;
    func_001C28A0(self, p, five, seven);
    return 1;
}
#endif

// diff: 24 words expected, same shape as 0x193050 (constants 2.4306/1.1591/0.2, tail arg 4); tail register order as 0x193050 unmatched
// DRAFT: GAME 0x193D08
#ifdef NONMATCHING
extern "C" int func_00193D08(char *self)
{
    func_001B6FB8(self);
    Vq a, b, c, d;
    Vq *pa = &a;
    Vq *pb = &b;
    Vq *pc = &c;
    a.x = 2.4306f;
    a.y = 1.1591f;
    a.z = 0.2f;
    pa->w = 1.0f;
    b.x = 2.4306f;
    b.y = 1.1591f;
    b.z = 0.2f;
    pb->w = 1.0f;
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    pc->w = 1.0f;
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq *pd = &d;
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    int one = 1;
    int four = 4;
    int seven = 7;
    int neg = -1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = one;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = four;
    *(int *)(self + 0x5EC) = seven;
    *(short *)(self + 0x548) = one;
    *(short *)(self + 0x5F4) = neg;
    func_001C28A0(self, p, four, seven);
    return 1;
}
#endif
