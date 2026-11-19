// Small units in 0x1C0000-0x1FFFFF (slice F166).
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(void *, void *, void *, int, int, int, void *, int, int, int, int, int, int);
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);
extern "C" void SeCall__4cSnd6eSeBlksPfUii(void *, int, int, void *, int, int);
extern "C" void SetMotionStep__FP8cObjBasef(char *, float);
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);
extern char Snd[];

struct Vec4 { float f[4]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x1C8E50 - 12 words; self/&v register swap ($s0/$s1) and save order; variants tried: asm base, mem operand, decl order, vp temp, negated test
extern "C" void func_001C8E50(char *self)
{
    Vec4 v;
    unsigned *hit;
    if (*(unsigned char *)(self + 0x640) == 0) {
        __asm__ volatile("sqc2 $vf0, %0" : "=m"(v) : "r"(&v));
        if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(self + 0x490, *(void **)(self + 0xF0), &v, 0, 7, 0, &hit, 1, 0, 0, 0, 0, 1) != 0 && (hit[1] & 0x400)) {
            SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, 0x55, 0, &v, 1.0f, -1);
            SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 0x50, *(void **)(self + 0xF0), 0, 0);
            *(unsigned char *)(self + 0x640) = 1;
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1D0B38 - 12 words; same self/&v register swap and save order as 0x1C8E50; flag at 0x688
extern "C" void func_001D0B38(char *self)
{
    Vec4 v;
    unsigned *hit;
    if (*(unsigned char *)(self + 0x688) == 0) {
        __asm__ volatile("sqc2 $vf0, %0" : "=m"(v) : "r"(&v));
        if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(self + 0x490, *(void **)(self + 0xF0), &v, 0, 7, 0, &hit, 1, 0, 0, 0, 0, 1) != 0 && (hit[1] & 0x400)) {
            SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, 0x55, 0, &v, 1.0f, -1);
            SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 0x50, *(void **)(self + 0xF0), 0, 0);
            *(unsigned char *)(self + 0x688) = 1;
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1EBA20 - 83 words, size 216 vs 340 bytes; ldl/ldr 0x28-byte copy, sqc2 and loop shape not reproduced
extern "C" void func_001EBA20(char *self)
{
    char *e = self + 0x5C;
    int i;
    for (i = 4; i >= 0; i--, e += 0x40) {
        if (!((*(int *)(e + 0x30) >> 2) & 1)) {
            float v[4];
            char *obj = *(char **)e;
            if (obj != 0) {
                float *src = *(float **)(obj + 0xF0);
                v[0] = src[0];
                v[1] = src[1];
                v[2] = src[2];
            } else {
                v[0] = 0.0f;
                v[1] = 0.0f;
                v[2] = 0.0f;
                v[3] = 1.0f;
            }
            if (v[2] <= v[3] - 30.0f) {
                SetMotionStep__FP8cObjBasef(obj, *(float *)(e + 0x18));
                *(int *)(e + 0x30) = *(int *)(e + 0x30) | 4;
            }
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1F9070 - 81 words, size 320 vs 348 bytes; lqc2/sqc2 VU copies and sceVu0ApplyMatrix call shape not reproduced
extern "C" int func_001F9070(float *obj, const float *mtx, const float *box, float ox, float oy, float oz)
{
    float p[4];
    float t[4];
    float fx, fy, fz;
    p[0] = obj[0];
    p[1] = obj[1];
    p[2] = obj[2];
    p[3] = 1.0f;
    t[0] = p[0];
    t[1] = p[1];
    t[2] = p[2];
    t[3] = p[3];
    sceVu0ApplyMatrix(t, mtx, t);
    p[0] = t[0];
    p[1] = t[1];
    p[2] = t[2];
    fx = obj[3] + ox;
    fy = obj[4] + oy;
    fz = obj[5] + oz;
    if (box[1] <= p[1] + fy && p[1] - fy <= box[1] &&
        box[0] <= p[0] + fx && p[0] - fx <= box[0] &&
        box[2] <= p[2] + fz && p[2] - fz <= box[2]) {
        return 1;
    }
    return 0;
}
#endif
