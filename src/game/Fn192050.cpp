struct Vq {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" void func_001BBF68(char *);
extern "C" int func_001C28A0(void *, void *, int, int);
extern "C" void *func_001FD8D8(void *, int);
extern "C" void *Getplayer__Fv();

#ifdef NONMATCHING
// DRAFT: GAME 0x192050
// 82 words: frame 0x80 vs 0x90, const load order; volatile a.x read gave 82 (312 bytes)
extern "C" int func_00192050(char *self)
{
    Vq a, b, c, d;
    func_001B6FB8(self);
    a.x = 1.45f;
    a.y = 3.0f;
    a.z = 0.2f;
    a.w = 1.0f;
    b.x = 1.45f;
    b.y = 3.0f;
    b.z = 0.2f;
    b.w = 1.0f;
    c.x = a.x * -0.5f;
    c.y = 0;
    c.z = 0;
    c.w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    Vq *dst = (Vq *)(self + 0x610);
    if (dst != &a) {
        dst->x = a.x;
        dst->y = a.y;
        dst->z = a.z;
    }
    setObjCollision__7cOmDoor(self);
    *(unsigned char *)(self + 0x624) = 1;
    *(void **)(self + 0x628) = self + 0x650;
    func_001BBF68(self);
    *(int *)(self + 0x5B8) = *(int *)(self + 0x5B8) | 2;
    return 1;
}

// DRAFT: GAME 0x19C3D0
// 80 words (300 vs 324 bytes): 0x192050 skeleton with constants 1.5/2.4/0.2/0.5, tail sb 7 at 0x624
extern "C" int func_0019C3D0(char *self)
{
    Vq a, b, c, d;
    func_001B6FB8(self);
    a.x = 1.5f;
    a.y = 2.4f;
    a.z = 0.2f;
    a.w = 1.0f;
    b.x = 1.5f;
    b.y = 2.4f;
    b.z = 0.2f;
    b.w = 1.0f;
    c.x = a.x * 0.5f;
    c.y = 0;
    c.z = 0;
    c.w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    Vq *dst = (Vq *)(self + 0x610);
    if (dst != &a) {
        dst->x = a.x;
        dst->y = a.y;
        dst->z = a.z;
    }
    setObjCollision__7cOmDoor(self);
    *(unsigned char *)(self + 0x624) = 7;
    *(void **)(self + 0x628) = self + 0x650;
    func_001BBF68(self);
    *(int *)(self + 0x5B8) = *(int *)(self + 0x5B8) | 2;
    return 1;
}

// DRAFT: GAME 0x192A98
// 75 words: frame 0x70 vs 0x90 (save slots differ), constant load order f2/f1/f0; tail via func_001C28A0
extern "C" int func_00192A98(char *self)
{
    Vq a, b, c, d;
    func_001B6FB8(self);
    a.x = 4.2f;
    a.y = 1.2f;
    a.z = 0.4f;
    a.w = 1.0f;
    b.x = 4.2f;
    b.y = 1.2f;
    b.z = 0.4f;
    b.w = 1.0f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    c.w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(void **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 6;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 6, 7);
    return 1;
}

// DRAFT: GAME 0x195850
// 64 words (308 vs 304 bytes): first diff at 0x19586C, target beql on $a0 with 0x214 load in delay slot, ours beqz; vtable-chain and 0x620-0x628 store order differ. Hoisting 0x214 load to entry gave 70 words (worse).
extern "C" void *func_00195850(char *self)
{
    char *pos = self + 0x620;
    if (*(void **)(self + 0x604) != 0) {
        void *r = func_001FD8D8(*(void **)(self + 0x604), *(int *)(self + 0x60C));
        if (r != 0 && (((unsigned int)*(int *)r & 0x203) == 3)) {
            char *obj = *(char **)(*(char **)(self + 0x214) + 0x34);
            char *vt = *(char **)(obj + 0x100);
            void *p = ((void *(*)(void *))*(void **)(vt + 0x44))(obj + *(short *)(vt + 0x40));
            if (p != pos) {
                Vq *s = (Vq *)p;
                Vq *d = (Vq *)pos;
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
            *(float *)(self + 0x624) = *(float *)(self + 0x624) - 2.0f;
            char *pl = (char *)Getplayer__Fv();
            char *v2 = *(char **)(pl + 0x214);
            void *q = ((void *(*)(void *))*(void **)(v2 + 0x84))(pl + *(short *)(v2 + 0x80));
            if (*(float *)(self + 0x624) < ((float *)q)[1] + 0.5f) {
                pl = (char *)Getplayer__Fv();
                v2 = *(char **)(pl + 0x214);
                q = ((void *(*)(void *))*(void **)(v2 + 0x84))(pl + *(short *)(v2 + 0x80));
                *(float *)(self + 0x624) = ((float *)q)[1] + 0.5f;
            }
            return pos;
        }
    }
    char *v = *(char **)(self + 0x214);
    return ((void *(*)(void *))*(void **)(v + 0x84))(self + *(short *)(v + 0x80));
}
#endif
