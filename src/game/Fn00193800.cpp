struct V4 { float x, y, z, w; };
extern char g_DmgManage[];
extern "C" {
void func_001B6FB8(void *);
void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
void *func_001FD9D8(void *, void *, void *, void *, void *);
void func_001C28A0(void *, ...);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x19AA80
// 47 words differ: lui a0 and s1/s2 setup scheduled earlier; store order and d-branch/tail registers differ.
extern "C" int func_0019AA80(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    pb->x = 2.8f;
    pa->y = 0.6f;
    pb->z = 1.6f;
    pa->x = 2.8f;
    pa->z = 1.6f;
    pa->w = 1.0f;
    pb->y = 1.0f;
    pb->w = 1.0f;
    pc->x = 0;
    pc->y = 0;
    pc->z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, pc, &d, pb);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(void **)(self + 0x608) = self + 0x620;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(unsigned char *)(self + 0x60C) = 7;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, 1, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x19AD00
// 39 words differ: store base (sp vs s2) for b.y/b.z and tail register allocation; direct-member stores tried and worse.
extern "C" int func_0019AD00(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    pb->x = 3.2f;
    pb->y = 1.1f;
    pb->z = 1.4f;
    pa->x = 3.2f;
    pa->y = 1.1f;
    pa->z = 1.4f;
    pa->w = 1.0f;
    pb->w = 1.0f;
    pc->x = 0;
    pc->y = 0;
    pc->z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, pc, &d, pb);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(void **)(self + 0x608) = self + 0x620;
    *(int *)(self + 0x5EC) = 7;
    *(unsigned char *)(self + 0x60C) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, 1, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x193800
// 38 words differ: self+0x620 computed twice (extra copy); constant and tail register allocation differs.
extern "C" int func_00193800(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    V4 *pa = &a;
    V4 *pb = &b;
    V4 *pc = &c;
    pb->x = 2.5f;
    pb->y = 0.9291f;
    pb->z = 0.2f;
    pa->x = 2.5f;
    pa->y = 0.9291f;
    pa->z = 0.2f;
    pa->w = 1.0f;
    pb->w = 1.0f;
    pc->x = 0;
    pc->y = 0;
    pc->z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, pc, &d, pb);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(void **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 5, 7);
    return 1;
}
#endif
