struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" int func_001C28A0(char *, char *, int, int);
extern "C" int func_001FD9D8(char *, char *, const Vq &, const Vq &, const Vq &);

// diff: 70 words, pointer register roles (s1/s2) and constant registers (f0/f1/f2) differ, tail uses v1/v0/a1 where original does; tried ctor vs brace-init aggregate (99 words), a/b declaration order swap, 3-arg vs 4-arg CreateDamageTake
// DRAFT: GAME 0x193050
#ifdef NONMATCHING
extern "C" int func_00193050(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq a(1.3f, 1.9f, 0.8f, one);
    Vq b(1.3f, 1.9f, 0.8f, one);
    Vq c(0.0f, 0.0f, 0.0f, one);
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, p, 5, 7);
    return 1;
}
#endif

// diff: 70 words, same register and tail differences as 0x193050 (constants 3.62/1.1591/0.2, tail arg 5)
// DRAFT: GAME 0x193A80
#ifdef NONMATCHING
extern "C" int func_00193A80(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq a(3.62f, 1.1591f, 0.2f, one);
    Vq b(3.62f, 1.1591f, 0.2f, one);
    Vq c(0.0f, 0.0f, 0.0f, one);
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, p, 5, 7);
    return 1;
}
#endif

// diff: 70 words, same register and tail differences as 0x193050 (constants 2.4306/1.1591/0.2, tail arg 4)
// DRAFT: GAME 0x193D08
#ifdef NONMATCHING
extern "C" int func_00193D08(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq a(2.4306f, 1.1591f, 0.2f, one);
    Vq b(2.4306f, 1.1591f, 0.2f, one);
    Vq c(0.0f, 0.0f, 0.0f, one);
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, c, d, b);
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 4;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, p, 4, 7);
    return 1;
}
#endif
