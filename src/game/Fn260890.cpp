// Fn260890: VU0/EM units from slice F178 (0x260890, 0x26B4E8, 0x26BDD0, 0x260A10).
extern char g_EmManage[];
extern "C" int EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(char *self, char *data, int a2, char *a3);
extern "C" void *Getplayer__Fv();
extern "C" float Adjust_theta__Ff(float);
extern "C" void MtxInitRotY__FR7cMatrixf(void *, float);
extern "C" float Turn_dest__FPCffT0f(void *, void *, float, float);
extern "C" void func_001CFB28(char *self, void *pos, char *arg);
extern "C" void func_0030A2B0(float *, float *, float *);
extern "C" void func_001D0240(void *, void *, void *);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

#ifdef NONMATCHING
// DRAFT: GAME 0x260890 - 53 words (260 vs 268 bytes); first draft, crashed worker left no variant log
extern "C" void func_00260890(char *self, int type)
{
    char sp[0x50] __attribute__((aligned(16)));
    int chk = *(int *)(self + 0x564) ^ 0x21F;
    if (chk) return;
    ZQ(sp, 0x0);
    char *s1 = sp + 0x10;
    char *p = *(char **)(self + 0xF0);
    if (p != sp) {
        ((float *)sp)[0] = ((float *)p)[0];
        ((float *)sp)[1] = ((float *)p)[1];
        ((float *)sp)[2] = ((float *)p)[2];
    }
    float f3 = *(float *)(self + 0x104);
    ZQ(sp, 0x20);
    unsigned short u = *(unsigned short *)(self + 0x2FE);
    s1[0x31] = 0xFF;
    *(int *)s1 = u;
    float *d = (float *)(sp + 0x20);
    float *s = (float *)sp;
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    *(float *)(sp + 0x30) = f3;
    *(int *)(sp + 0x34) = 0x40C00000;
    *(int *)(sp + 0x38) = *(int *)(self + 0x564);
    *(int *)(sp + 0x3C) = 0;
    sp[0x41] = 0xFF;
    int code;
    switch (type) {
    case 0: code = 0x12; break;
    case 1: code = 0x13; break;
    case 2: code = 0x14; break;
    case 3: code = 0x15; break;
    case 4: code = 0x16; break;
    default: code = 0x12; break;
    }
    sp[0x40] = (char)code;
    EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(g_EmManage, s1, 0, self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x26B4E8 - 7 words (280 vs 280 bytes); first draft, crashed worker left no variant log
extern "C" void func_0026B4E8(char *self)
{
    char sp[0x50] __attribute__((aligned(16)));
    char *s2 = *(char **)(self + 0x700);
    if (s2 == 0) return;
    ZQ(sp, 0x40);
    char *s0 = *(char **)(self + 0xF0);
    char *pl = (char *)Getplayer__Fv();
    int turn_bits = 0x3F860A92;
    float turn_rate = *(float *)&turn_bits;
    float t = Turn_dest__FPCffT0f(s0, *(void **)(pl + 0xF0), *(float *)(self + 0x104), turn_rate);
    float ang = Adjust_theta__Ff(t + *(float *)(self + 0x104));
    MtxInitRotY__FR7cMatrixf(sp, ang);
    ((float *)(sp + 0x40))[2] = 0.3f;
    ((float *)(sp + 0x40))[1] = 0.0f;
    func_0030A2B0((float *)(sp + 0x40), (float *)sp, (float *)(sp + 0x40));
    char *dst = *(char **)(s2 + 0xF0);
    char *src = *(char **)(self + 0xF0);
    if (dst != src) {
        ((float *)dst)[0] = ((float *)src)[0];
        ((float *)dst)[1] = ((float *)src)[1];
        ((float *)dst)[2] = ((float *)src)[2];
    }
    float *f = (float *)*(char **)(s2 + 0xF0);
    f[1] = f[1] + 1.5f;
    float *m = (float *)(s2 + 0x490);
    char *src2 = *(char **)(self + 0xF0);
    if ((char *)m != src2) {
        m[0] = ((float *)src2)[0];
        m[1] = ((float *)src2)[1];
        m[2] = ((float *)src2)[2];
    }
    func_001CFB28(s2, sp + 0x40, self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x26BDD0 - 67 words (288 vs 284 bytes); named-p form (attempt 3) kept
extern "C" void func_0026BDD0(char *self, char *arg1)
{
    char sp[0x70] __attribute__((aligned(16)));
    if (arg1 == 0) return;
    int n = *(unsigned char *)(self + 0x2B4);
    *(int *)sp = n;
    char *v = 0;
    if (10 < n) v = *(char **)(*(char **)(self + 0x278) + 0x28);
    if (v == 0) return;
    ZQ(sp, 0x50);
    ZQ(sp, 0x60);
    char *t = *(char **)(v + 0xF0);
    char *p = sp + 0x50;
    if (p != t) {
        ((float *)p)[0] = ((float *)t)[0];
        ((float *)p)[1] = ((float *)t)[1];
        ((float *)p)[2] = ((float *)t)[2];
    }
    char *dst = *(char **)(arg1 + 0xF0);
    if (dst != p) {
        ((float *)dst)[0] = ((float *)p)[0];
        ((float *)dst)[1] = ((float *)p)[1];
        ((float *)dst)[2] = ((float *)p)[2];
    }
    char *m = arg1 + 0x490;
    if (m != p) {
        ((float *)m)[0] = ((float *)p)[0];
        ((float *)m)[1] = ((float *)p)[1];
        ((float *)m)[2] = ((float *)p)[2];
    }
    char *mat = sp + 0x10;
    MtxInitRotY__FR7cMatrixf(mat, *(float *)(self + 0x104));
    int c_bits = 0x3DCCCCCD;
    *(float *)(sp + 0x68) = *(float *)&c_bits;
    *(int *)(sp + 0x60) = 0;
    *(int *)(sp + 0x64) = 0;
    func_0030A2B0((float *)(sp + 0x60), (float *)mat, (float *)(sp + 0x60));
    func_001D0240(arg1, sp + 0x60, self);
}
#endif
