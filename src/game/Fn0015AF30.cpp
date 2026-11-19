// Units at 0x15AF30, 0x18EF58, 0x191DE8.
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void func_001FD9D8(void *, char *, void *, void *, void *);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" void func_001BBF68(char *);

struct Vec4 {
    float x, y, z, w;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x18EF58 - 11 words differ: prologue stores of b.y/b.z/a.y/a.z in the wrong order, 0x610 copy register choice, 0x624/0x628 tail order. Tried Vec4 array locals (13), named locals with pointers (11), prologue reorders (22, 26), both tail swaps (26).
extern "C" int func_0018EF58(char *self)
{
    Vec4 a, b, c, d;
    func_001B6FB8(self);
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    Vec4 *pc = &c;
    a.x = 1.5f;
    b.y = 2.4f;
    b.z = 0.2f;
    a.y = 2.4f;
    a.z = 0.2f;
    b.x = 1.5f;
    pa->w = 1.0f;
    pb->w = 1.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    c.x = -a.x * 0.5f;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t != 0) {
        Vec4 *pd = &d;
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, pc, pd, pb);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    if ((char *)(self + 0x610) != (char *)pa) {
        *(float *)(self + 0x610) = a.x;
        *(float *)(self + 0x614) = a.y;
        *(float *)(self + 0x618) = a.z;
    }
    setObjCollision__7cOmDoor(self);
    *(char **)(self + 0x628) = self + 0x650;
    *(char *)(self + 0x624) = 7;
    func_001BBF68(self);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x191DE8 - 11 words differ, same differences as 0x18EF58 (prologue store order, 0x610 copy register choice, tail 0x624/0x628 order). Tried the 0x18EF58 template with 0x191DE8 constants (1.449, 2.43179989, c.x = a.x * -0.5).
extern "C" int func_00191DE8(char *self)
{
    Vec4 a, b, c, d;
    func_001B6FB8(self);
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    Vec4 *pc = &c;
    a.x = 1.449f;
    b.y = 2.43179989f;
    b.z = 0.2f;
    a.y = 2.43179989f;
    a.z = 0.2f;
    b.x = 1.449f;
    pa->w = 1.0f;
    pb->w = 1.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    c.x = a.x * -0.5f;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t != 0) {
        Vec4 *pd = &d;
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, pc, pd, pb);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    if ((char *)(self + 0x610) != (char *)pa) {
        *(float *)(self + 0x610) = a.x;
        *(float *)(self + 0x614) = a.y;
        *(float *)(self + 0x618) = a.z;
    }
    setObjCollision__7cOmDoor(self);
    *(char **)(self + 0x628) = self + 0x650;
    *(char *)(self + 0x624) = 7;
    func_001BBF68(self);
    return 1;
}
#endif
