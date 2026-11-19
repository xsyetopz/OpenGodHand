extern "C" float fRand1_1__Fv();
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);
extern char g_DmgManage[];

#ifdef NONMATCHING
// DRAFT: GAME 0x193550
// 84 differing words: frame is 0x70 vs 0x90, which shifts every sp offset; f20 save and constant-load order differ.
// Tried: a/b/c/v order (85), hoisted one (84, kept), pointer read of a[2] (84, reverted).
extern "C" int func_00193550(char *self)
{
    float a[4];
    float b[4];
    float c[4];
    float v[4];
    func_001B6FB8(self);
    float one = 1.0f;
    a[0] = 1.18f;
    a[1] = 1.61f;
    a[2] = 0.67f;
    a[3] = one;
    b[0] = 1.18f;
    b[1] = 1.61f;
    b[2] = 0.67f;
    b[3] = one;
    c[0] = 0.0f;
    c[1] = 0.0f;
    c[2] = a[2] * 0.5f;
    c[3] = one;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t != 0) {
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = one;
        func_001FD9D8(t, self + 0x80, c, v, b);
        char *p = *(char **)(self + 0x600);
        if (p != 0) {
            *(unsigned int *)p |= 1;
        }
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 5, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x173258
// 10 differing words: timer test is andi (original sll/beqz); *s1 and 1.0 register order swapped.
// Tried: int timer with (short) test (77 words), p[2] hoisted (kept).
extern "C" void func_00173258(char *self)
{
    if (*(short *)(self + 0xDA0) > 0) {
        unsigned short t = (unsigned short)(*(short *)(self + 0xDA0) - 1);
        *(short *)(self + 0xDA0) = t;
        if (t != 0) {
            char *obj = *(char **)(self + 0x214);
            char *s0 = self + *(short *)(obj + 0x70);
            char *s2 = obj + 0x70;
            float *s1 = ((float *(*)(void *))(*(void **)(obj + 0x84)))(self + *(short *)(obj + 0x80));
            float f20 = *(float *)(self + 0xDA4) + fRand1_1__Fv() * 0.02617994f;
            char *obj2 = *(char **)(self + 0x214);
            float *p = ((float *(*)(void *))(*(void **)(obj2 + 0x84)))(self + *(short *)(obj2 + 0x80));
            float p2z = p[2];
            float buf[4];
            buf[0] = *s1;
            buf[1] = f20;
            buf[2] = p2z;
            buf[3] = 1.0f;
            ((void (*)(void *, float *))(*(void **)(s2 + 4)))(s0, buf);
            return;
        }
        char *obj3 = *(char **)(self + 0x214);
        char *s0b = self + *(short *)(obj3 + 0x70);
        char *s2b = obj3 + 0x70;
        float *s1b = ((float *(*)(void *))(*(void **)(obj3 + 0x84)))(self + *(short *)(obj3 + 0x80));
        char *obj4 = *(char **)(self + 0x214);
        float *p2 = ((float *(*)(void *))(*(void **)(obj4 + 0x84)))(self + *(short *)(obj4 + 0x80));
        float p2z = p2[2];
        float buf2[4];
        buf2[0] = *s1b;
        buf2[1] = *(float *)(self + 0xDA4);
        buf2[2] = p2z;
        buf2[3] = 1.0f;
        ((void (*)(void *, float *))(*(void **)(s2b + 4)))(s0b, buf2);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1AEF40
// 17 differing words: timer test is andi (original sll/beqz); branch A s1/s2 registers reversed; branch B load order.
// Tried: int timer with (t << 16) test (78 words), rnd/term reorder (17), split s1 declaration (17), p[1] hoist in branch B (19).
extern "C" void func_001AEF40(char *self)
{
    if (*(short *)(self + 0x986) > 0) {
        unsigned short t = (unsigned short)(*(short *)(self + 0x986) - 1);
        *(short *)(self + 0x986) = t;
        if (t != 0) {
            char *obj = *(char **)(self + 0x214);
            char *s0 = self + *(short *)(obj + 0x78);
            char *s3 = obj + 0x78;
            float *s2 = ((float *(*)(void *))(*(void **)(obj + 0x8C)))(self + *(short *)(obj + 0x88));
            char *obj2 = *(char **)(self + 0x214);
            float *s1 = ((float *(*)(void *))(*(void **)(obj2 + 0x8C)))(self + *(short *)(obj2 + 0x88));
            float rnd = fRand1_1__Fv();
            float term = rnd * 0.034906585f;
            float buf[4];
            buf[0] = s2[0];
            buf[1] = s1[1];
            buf[3] = 1.0f;
            buf[2] = *(float *)(self + 0x988) + term;
            ((void (*)(void *, float *))(*(void **)(s3 + 4)))(s0, buf);
            return;
        }
        char *obj3 = *(char **)(self + 0x214);
        char *s0b = self + *(short *)(obj3 + 0x78);
        char *s2b = obj3 + 0x78;
        float *s1b = ((float *(*)(void *))(*(void **)(obj3 + 0x8C)))(self + *(short *)(obj3 + 0x88));
        char *obj4 = *(char **)(self + 0x214);
        float *p = ((float *(*)(void *))(*(void **)(obj4 + 0x8C)))(self + *(short *)(obj4 + 0x88));
        float buf2[4];
        buf2[0] = s1b[0];
        buf2[1] = p[1];
        buf2[2] = *(float *)(self + 0x988);
        buf2[3] = 1.0f;
        ((void (*)(void *, float *))(*(void **)(s2b + 4)))(s0b, buf2);
    }
}
#endif
