struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
struct V3 {
    float x, y, z;
};
extern char g_DmgManage[];
extern char EspSys[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" int func_001C28A0(char *, char *, int, int);
extern "C" int func_001FD9D8(char *, char *, const Vq &, const Vq &, const Vq &);
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" void func_001BBF68(char *);

// DRAFT: GAME 0x16F4A8 - 69 words differ: frame 0x70 vs 0x90 (original keeps s2 live across CreateDamageTake), tail store order and a1/a2 choice differ. Tried dead leading Vq (79->72), a before dead Vq (69), pointer to a held across call (69, rejected)
#ifdef NONMATCHING
extern "C" int func_0016F4A8(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq a(1.6f, 1.0f, 1.2f, one);
    Vq unused(1.6f, 1.0f, 1.2f, one);
    Vq z1(0.0f, 0.0f, 0.0f, one);
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq z2(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, z1, z2, a);
    }
    *(int *)(self + 0x5E4) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(int *)(self + 0x5F0) = 0x258;
    *(int *)(self + 0x5E8) = 0x258;
    char *p = self + 0x620;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 6;
    *(short *)(self + 0x5F4) = -1;
    *(int *)(self + 0x5EC) = 1;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001C28A0(self, (char *)6, -1, 0x258);
    char *q = *(char **)(self + 0x304);
    effDataRegist__6espSys12eEffDataTypePv(EspSys, 0x258, (void *)(*(int *)(q + 0xC) + (int)q));
    return 1;
}
#endif

// DRAFT: GAME 0x178E18 - 52 words differ, 328 vs 316 bytes: b/c register roles swap (original s2=sp+0x10 for b, s1=sp+0x20 for c), d/a3 setup and zero-store order at sp+0x30..0x38, 0x5B8 |= 0x800 placement and halfword store order in tail. Tried pb/pc locals (71->52, kept), dead Vq removal (79), c before b (55), 0x5B8 load at tail (52, no gain), hoisted d (69)
#ifdef NONMATCHING
extern "C" int func_00178E18(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq unused(4.8f, 3.0f, 4.8f, one);
    Vq b(4.8f, 3.0f, 4.8f, one);
    Vq c(0.0f, 0.0f, 0.0f, one);
    Vq *pb = &b;
    Vq *pc = &c;
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, *pc, d, *pb);
        **(int **)(self + 0x600) |= 1;
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 0x12;
    *(int *)(self + 0x5EC) = 0x11;
    *(short *)(self + 0x5F4) = -1;
    *(short *)(self + 0x5F6) = 5;
    *(short *)(self + 0x548) = 1;
    *(int *)(self + 0x5B8) |= 0x800;
    func_001C28A0(self, (char *)0x11, 5, (int)p);
    return 1;
}
#endif

// DRAFT: GAME 0x1867E8 - 41 words differ, 320 vs 320 bytes: constant-load order (1.5f in f0 vs f2, 0.2f in f2 vs f0), s1/s2 pointer roles, store interleaving for a/b/c, tail register swap (0x650 in v1 vs v0, 7 in v0 vs v1), sb/sw order for 0x624/0x628. Tried pb/pc locals (75->41, kept), pc before pb (41), named q local for 0x650 (41), b before a (43)
#ifdef NONMATCHING
extern "C" int func_001867E8(char *self)
{
    func_001B6FB8(self);
    float one = 1.0f;
    Vq a(1.5f, 2.4f, 0.2f, one);
    Vq b(1.5f, 2.4f, 0.2f, one);
    Vq c(a.x * -0.5f, 0.0f, 0.0f, one);
    Vq *pb = &b;
    Vq *pc = &c;
    char *t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, one);
        func_001FD9D8(t, self + 0x80, *pc, d, *pb);
    }
    *(short *)(self + 0x54A) = 1;
    *(short *)(self + 0x548) = 1;
    V3 *dst = (V3 *)(self + 0x610);
    if (dst != (V3 *)&a) {
        dst->x = a.x;
        dst->y = a.y;
        dst->z = a.z;
    }
    setObjCollision__7cOmDoor(self);
    *(unsigned char *)(self + 0x624) = 7;
    *(char **)(self + 0x628) = self + 0x650;
    func_001BBF68(self);
    return 1;
}
#endif
