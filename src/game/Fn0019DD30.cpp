// Units at 0x19DD30, 0x19E2A8, 0x1AA058.
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
struct Vec4 {
    float x, y, z, w;
};
extern "C" char *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(char *, char *, int, Vec4);
extern "C" void func_001FD9D8(void *, char *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);
extern "C" void *func_001FD8D8(int, int);
extern "C" void *Getplayer__Fv();
typedef void *(*VFnA)(void *);
typedef void *(*VFnB)(void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x19DD30 - 65 words differ, same size: frame is 0x80 not 0x90, a3 is set to &a for CreateDamageTake where original leaves it alone, and s-register save order differs. Tried aggregate init (85 words), per-component stores (65), float-argument prototype (90).
extern "C" int func_0019DD30(char *self)
{
    func_001B6FB8(self);
    Vec4 a;
    a.x = 0.8f;
    a.y = 4.6f;
    a.z = 0.8f;
    a.w = 1.0f;
    Vec4 b;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = a.z * 0.5f;
    b.w = 1.0f;
    char *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2, a);
    *(char **)(self + 0x600) = t;
    if (t != 0) {
        Vec4 c = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &b, &c, &a);
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = p;
    *(unsigned char *)(self + 0x60C) = 6;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, p, 6, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x19E2A8 - 66 words differ, 304 vs 300 bytes: same by-value template as 0x19DD30 with a = {2.4, 1.1, 0.2, 1.0}, b zero, 0x60C = 4. Frame is 0x80 not 0x90.
extern "C" int func_0019E2A8(char *self)
{
    func_001B6FB8(self);
    Vec4 a;
    a.x = 2.4f;
    a.y = 1.1f;
    a.z = 0.2f;
    a.w = 1.0f;
    Vec4 b;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    b.w = 1.0f;
    char *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2, a);
    *(char **)(self + 0x600) = t;
    if (t != 0) {
        Vec4 c = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &b, &c, &a);
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

#ifdef NONMATCHING
// DRAFT: GAME 0x1AA058 - 60 words differ, 308 vs 304 bytes: the first difference is the obj copy. The compiler loads obj into a0 and copies it to a1 (daddu), while the original loads obj straight into a1 and adds the vtable offset into a0. Tried int obj, inline offset and dropping the s1 local; all stay at 60.
extern "C" void *func_001AA058(char *self)
{
    if (*(int *)(self + 0x604) != 0) {
        char *v = (char *)func_001FD8D8(*(int *)(self + 0x604), *(int *)(self + 0x618));
        if (v != 0 && ((*(unsigned *)v & 0x203) ^ 3) == 0) {
            char *obj = *(char **)(v + 0x34);
            char *s1 = self + 0x630;
            char *vt = *(char **)(obj + 0x100);
            short off = *(short *)(vt + 0x40);
            VFnB fn = (VFnB)*(void **)(vt + 0x44);
            char *r = (char *)fn(obj + off, obj);
            if (r != s1) {
                *(float *)(self + 0x630) = ((float *)r)[0];
                *(float *)(s1 + 4) = ((float *)r)[1];
                *(float *)(s1 + 8) = ((float *)r)[2];
            }
            *(float *)(self + 0x634) = *(float *)(self + 0x634) - 2.0f;
            char *pl = (char *)Getplayer__Fv();
            char *vt2 = *(char **)(pl + 0x214);
            short off2 = *(short *)(vt2 + 0x80);
            VFnA fn2 = (VFnA)*(void **)(vt2 + 0x84);
            char *q = (char *)fn2(pl + off2);
            if (*(float *)(self + 0x634) < ((float *)q)[1] + 0.5f) {
                char *pl2 = (char *)Getplayer__Fv();
                char *vt3 = *(char **)(pl2 + 0x214);
                short off3 = *(short *)(vt3 + 0x80);
                VFnA fn3 = (VFnA)*(void **)(vt3 + 0x84);
                char *q2 = (char *)fn3(pl2 + off3);
                *(float *)(self + 0x634) = ((float *)q2)[1] + 0.5f;
            }
            return s1;
        }
    }
    char *vt4 = *(char **)(self + 0x214);
    short off4 = *(short *)(vt4 + 0x80);
    VFnA fn4 = (VFnA)*(void **)(vt4 + 0x84);
    return fn4(self + off4);
}
#endif
