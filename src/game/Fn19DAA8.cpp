// Units at 0x19DAA8, 0x19EA20, 0x1A6FB0, 0x1B0838.
struct Vec4 {
    float x, y, z, w;
};

extern char g_DmgManage[];
extern char Snd[];
extern char D_003BDCB0[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *, void *);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_001B0540(char *);
extern "C" void func_001B7EE0(char *, float);

#ifdef NONMATCHING
// DRAFT: GAME 0x19DAA8 - 75 words; Tried: Vec4 locals from constant tables (75); hoisted 1.0f with extra unused Vec4 (97, reverted); prologue and Vec4 stack layout differ
extern "C" int func_0019DAA8(char *self)
{
    Vec4 b = {1.3f, 1.9f, 0.8f, 1.0f};
    Vec4 c = {0.0f, 0.0f, 0.0f, 1.0f};
    func_001B6FB8(self);
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        Vec4 d = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 5;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 5, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x19EA20 - 75 words; Tried: initial draft from 0x19DAA8 layout (sb 6); 296-byte size gap, same prologue and Vec4 differences
extern "C" int func_0019EA20(char *self)
{
    Vec4 b = {1.5f, 1.1f, 1.2f, 1.0f};
    Vec4 c = {0.0f, 0.0f, 0.0f, 1.0f};
    func_001B6FB8(self);
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        Vec4 d = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 6;
    *(int *)(self + 0x5EC) = 7;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 6, 7);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1A6FB0 - 68 words; Tried: initial loop draft (240 vs 292 bytes); loop body and float tail not yet aligned
extern "C" void func_001A6FB0(char *self)
{
    float *a2 = (float *)(self + 0x6C8);
    float *a3 = (float *)(self + 0x644);
    for (int i = 1; i < 32; i++) {
        char *a1 = 0;
        if (i < *(unsigned char *)(self + 0x2B4))
            a1 = *(char **)((int)*(char **)(self + 0x278) + (i << 2));
        if (a1 != 0) {
            float d = *(float *)(*(char **)(a1 + 0xD0) + 8) - *a2;
            *a2 = *(float *)(*(char **)(a1 + 0xD0) + 8);
            *a3 = d;
            if (0.0f < *(float *)(*(char **)(a1 + 0xD0) + 8))
                *a3 = d - 0.1f;
            if (*(float *)(*(char **)(a1 + 0xD0) + 8) < 0.0f)
                *a3 = *a3 + 0.1f;
            *(float *)(*(char **)(a1 + 0xD0) + 8) += *a3;
            *(float *)(*(char **)(a1 + 0xD0) + 8) = 0.0f;
            *(unsigned char *)(self + 0x748 + i) = 0;
        }
        a2++;
        a3++;
    }
    *(unsigned char *)(self + 0x768) = 1;
    *(unsigned char *)(self + 0x748) = 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1B0838 - 76 words; Tried: initial checkDamage and dispatch draft (260 vs 316 bytes); dispatch and clamp branch shape differ
extern "C" void func_001B0838(char *self)
{
    if (checkDamage__7cOmBaseP11cDamageTake(self, *(void **)(self + 0x600)) == 1) {
        if (1000 < *(short *)(self + 0x548))
            *(short *)(self + 0x54A) = 1000;
        else
            *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
        *(float *)(self + 0x54C) = 5.0f;
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 45, self, 0, 0, 0, 0);
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    unsigned idx = *(unsigned char *)(self + 0x2F5);
    char *e = D_003BDCB0 + idx * 8;
    short sub = *(short *)(e + 2);
    void *fn;
    int argoff;
    if (sub < 0) {
        fn = *(void **)(e + 4);
        argoff = *(short *)e;
    } else {
        char *base = *(char **)(self + *(short *)(e + 4));
        int *w = (int *)(base + sub * 8 - 8);
        fn = (void *)w[1];
        argoff = (short)(w[0] & 0xFFFF) + *(short *)e;
    }
    ((void (*)(char *))fn)(self + argoff);
    func_001B0540(self);
    func_001B7EE0(self, 2.5f);
}
#endif
