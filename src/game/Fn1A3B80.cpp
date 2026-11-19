// Damage-take unit initialiser at 0x1A3B80 (same shape as Fn19Box.cpp).
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1A3B80 - same tail const-load/store-order problem as 0x1A06F0 (12 words differ with one-arg callee).
extern "C" int func_001A3B80(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    a.x = 1.2f;
    a.y = 4.25f;
    a.z = 1.2f;
    pa->w = 1.0f;
    b.x = 1.2f;
    b.y = 4.25f;
    b.z = 1.2f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        V4 *pd = &d;
        d.x = 0;
        d.y = 0;
        d.z = 0;
        pd->w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    void *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(void **)(self + 0x608) = p;
    *(char *)(self + 0x60C) = 0x14;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self);
    return 1;
}
#endif
