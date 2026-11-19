// Slice F172 units: 0x2F4BE0, 0x2F4DC8, 0x2F5588, 0x2F6CF8.
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(void *, void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void func_002B6160(float *, void *);
extern "C" void setLocalTranslation__5cNodeRC4cVec(char *, float *);
extern "C" void MtxCopy__FR7cMatrixRC7cMatrix(float *, float *, int);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

struct V4 { float x, y, z, w; };
#define CPV(d, s) __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,0(%1)" : : "r"(&(s)), "r"(&(d)) : "memory")
#define ZV(v) __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&(v)) : "memory")

#ifdef NONMATCHING
// DRAFT: GAME 0x2F4BE0 - 42 differing words (328 vs 328 bytes); var block (t kept in $f1 with mov.s, 10.0 hoisted before the compare) and sp30->sp60 load order differ. Tried: separate t local, ternary both ways, x/z/y field reordering (best 13 differing lines), pointer copy (30 lines).
extern "C" int func_002F4BE0(char *self)
{
    V4 sp30, sp40, sp50, sp60;
    float t = *(float *)(*(char **)(self + 0x110) + 0x144);
    float var = (t == 0.0f) ? 10.0f : t;
    char *o = *(char **)(self + 0xF0);
    ((void (*)(char *))(*(void **)(o + 0x54)))(self + *(short *)(o + 0x50));
    func_002B6160((float *)&sp30, self);
    CPV(sp40, sp30);
    CPV(sp50, sp30);
    ZV(sp60);
    sp40.y += 1.0f;
    sp50.y -= var + 1.0f;
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(&sp40, &sp50, &sp60, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
        sp60.y += *(float *)(*(char **)(self + 0x110) + 0x140);
    } else if (&sp60 != &sp30) {
        sp60.y = sp30.y;
        sp60.x = sp30.x;
        sp60.z = sp30.z;
    }
    setLocalTranslation__5cNodeRC4cVec(self, (float *)&sp60);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2F4DC8 - 57 differing words (220 vs 240 bytes); matrix path via MtxCopy and ApplyMatrix, fallback copy from self+0x2D0. Frame -0x90 vs target -0xA0, ra slot 0x70 vs 0x60. Variants 1-5 gave 58, 57, 57, 57, 58 words.
extern "C" void func_002F4DC8(char *self, float *out)
{
    float sp[16];
    int cnt;
    V4 sp60, sp50;
    char *t = *(char **)(self + 0x2C0);
    if (t != 0) {
        int idx = *(unsigned char *)(self + 0x2BF);
        unsigned char ok = 0;
        int v = 0;
        int *pc = &cnt;
        cnt = *(unsigned char *)(t + 0x2B4);
        if (idx >= 0) ok = idx < cnt;
        if (ok) v = *(int *)((int)*(char **)(t + 0x278) + (idx << 2));
        MtxCopy__FR7cMatrixRC7cMatrix(sp, (float *)(v + 0x80), ok);
        CPV(sp60, *(V4 *)(self + 0x2D0));
        sceVu0ApplyMatrix((float *)&sp60, sp, (float *)&sp60);
        CPV(sp50, sp60);
        if (out != (float *)&sp50) {
            out[0] = sp50.x;
            out[2] = sp50.z;
            out[1] = sp50.y;
        }
    } else {
        float *src = (float *)(self + 0x2D0);
        if (out != src) {
            out[0] = src[0];
            out[1] = src[1];
            out[2] = src[2];
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2F6CF8 - 55 differing words; abs fields, camera vector copy (pCamWork+0x200 or +0x210), three func_0031D168 offsets summed. Target loads 0x220 before the sdc2 zero store; ours zero-stores first; lbu/lw order and pCamWork lui/lw words differ.
extern char *pCamWork;
extern "C" float fabsf(float);
extern "C" float func_0031D168(void *, float);
extern "C" void func_002B5FC8(char *, float *);
extern "C" int func_002F6CF8(char *self)
{
    V4 v, w;
    char *t = *(char **)(self + 0x110);
    float *src;
    *(float *)(self + 0x2B8) = fabsf(*(float *)(t + 0x13C));
    *(float *)(self + 0x2BC) = fabsf(*(float *)(t + 0x140));
    ZV(v);
    unsigned char fl = *(unsigned char *)(t + 0x18C);
    int a = *(int *)(self + 0x220);
    *(int *)(self + 0x2B4) = a;
    *(int *)(self + 0x2B0) = fl;
    if (fl != 0) src = (float *)(pCamWork + 0x200);
    else src = (float *)(pCamWork + 0x210);
    if ((float *)&v != src) {
        v.x = src[0];
        v.y = src[1];
        v.z = src[2];
    }
    float r1 = func_0031D168(self + 0x2B4, -*(float *)(self + 0x2B8));
    float r2 = func_0031D168(self + 0x2B4, -*(float *)(self + 0x2B8));
    float r3 = func_0031D168(self + 0x2B4, -*(float *)(self + 0x2B8));
    v.x += r1;
    v.y += r2;
    v.z += r3;
    CPV(w, v);
    func_002B5FC8(self, (float *)&w);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2F5588 - 71 differing words; two guarded entry lookups, componentwise (second - first) * 0.5, count held in an address-taken local. Target guard keeps ok in a register with slt, and obj/idx register assignment differs. Tried: bool ok (78), address-taken ok (79), idx declared before obj (71).
extern V4 ZeroVec;
extern "C" float *func_002F5588(float *out, char *self)
{
    V4 v, e1, e2;
    int cnt;
    int *pc = &cnt;
    char *obj = *(char **)(self + 0x114);
    int idx = *(signed char *)(*(char **)(self + 0x110) + 0xBE);
    int ok = 0;
    char *e;
    CPV(v, ZeroVec);
    *pc = *(unsigned char *)(obj + 0x2B4);
    if (idx >= 0) ok = idx < cnt;
    if (ok) e =*(char **)((int)*(char **)(obj + 0x278) + (idx << 2));
    else e = 0;
    float *q1 = (float *)&e1;
    q1[0] = *(float *)(e + 0xB0);
    q1[1] = *(float *)(e + 0xB4);
    q1[2] = *(float *)(e + 0xB8);
    q1[3] = 1.0f;
    obj = *(char **)(self + 0x114);
    idx = *(int *)(self + 0x2B0);
    *pc = *(unsigned char *)(obj + 0x2B4);
    ok = 0;
    if (idx >= 0) ok = idx < cnt;
    if (ok) e =*(char **)((int)*(char **)(obj + 0x278) + (idx << 2));
    else e = 0;
    float *q2 = (float *)&e2;
    q2[0] = *(float *)(e + 0xB0);
    q2[1] = *(float *)(e + 0xB4);
    q2[2] = *(float *)(e + 0xB8);
    q2[3] = 1.0f;
    v.x = (e2.x - e1.x) * 0.5f;
    v.y = (e2.y - e1.y) * 0.5f;
    v.z = (e2.z - e1.z) * 0.5f;
    CPV(*(V4 *)out, v);
    return out;
}
#endif
