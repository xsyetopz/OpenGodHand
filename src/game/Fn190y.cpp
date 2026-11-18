// Non-family units in 0x190000-0x1A0000 (ee-gcc2.95.3-136, C++).
struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001BFB28(void *);

// FUNCTION: GAME 0x19D640
extern "C" int func_0019D640(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    a.x = 1.0f;
    a.y = 1.3600000143051147f;
    a.z = 0.20000000298023224f;
    pa->w = 1.0f;
    b.x = 1.0f;
    b.y = 1.3600000143051147f;
    b.z = 0.20000000298023224f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = a.y * -0.5f;
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
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001BFB28(self);
    return 1;
}

// FUNCTION: GAME 0x199E58
extern "C" int func_00199E58(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    a.x = 2.0f;
    a.y = 2.0f;
    a.z = 0.4000000059604645f;
    pa->w = 1.0f;
    b.x = 2.0f;
    b.y = 2.0f;
    b.z = 0.4000000059604645f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = b.y * -0.5f;
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
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001BFB28(self);
    *(unsigned *)(self + 0x5B8) |= 0x200;
    return 1;
}

// FUNCTION: GAME 0x19D848
extern "C" int func_0019D848(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    a.x = 1.600000023841858f;
    a.y = 1.5f;
    a.z = 0.20000000298023224f;
    pa->w = 1.0f;
    b.x = 1.600000023841858f;
    b.y = 1.5f;
    b.z = 0.20000000298023224f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = a.y * -0.5f;
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
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001BFB28(self);
    return 1;
}
