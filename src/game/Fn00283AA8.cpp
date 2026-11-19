struct Qv2 { float f[4]; };
extern "C" void setParent__9cOmWeaponP8cGameObjUiRC4cVecT3(void *, void *, unsigned, void *, void *);
extern "C" void sceVu0ApplyMatrix(float *, void *, float *);
extern "C" void MtxInitRotY__FR7cMatrixf(void *, float);
extern "C" float capVu0Atan2__Fff(float, float);
extern "C" void func_00104010(void *, void *, void *);
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(void *, void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void *Getplayer__Fv();
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern char g_CollSolidManage[];
extern int D_00747A2C;

// FUNCTION: GAME 0x28D3D8
extern "C" void func_0028D3D8(char *self, void *w, int flag)
{
    Qv2 pos;
    Qv2 rot;
    unsigned n;
    if (!w)
        return;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(pos));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(rot));
    if (*(int *)(self + 0x564) != 0x225 && *(int *)(self + 0x564) != 0x24D) {
        n = 10;
        pos.f[0] = -0.28f; pos.f[1] = -0.035f; pos.f[2] = 0.185f;
        rot.f[0] = 0.0f; rot.f[1] = -0.7853982f; rot.f[2] = 0.0f;
        if (flag) {
            pos.f[0] = 0.28f;
            n = 16;
            rot.f[1] = 0.7853982f;
        }
    } else {
        pos.f[0] = -0.08f; pos.f[1] = -0.03f; pos.f[2] = 0.0f;
        rot.f[0] = 0.0f; rot.f[1] = 0.0f; rot.f[2] = 0.0f;
        n = 10;
        if (flag) {
            pos.f[0] = 0.08f;
            n = 16;
            rot.f[2] = 3.1415927f;
        }
    }
    setParent__9cOmWeaponP8cGameObjUiRC4cVecT3(w, self, n, &pos, &rot);
}

// DRAFT: GAME 0x283AA8 - 69 words; frame 0xA0 vs 0x90 (extra s0 holding &f.vec CSE'd across calls, self in s2 not s1); tried struct frame, 2<k, decl order, "+m" asm operand: count unchanged
#ifdef NONMATCHING
extern "C" void func_00283AA8(char *self)
{
    char *p;
    char *s0;
    float ang;
    struct Frame {
        float mtx[16];
        float vec[4];
        int k;
    } f;

    *(int *)(self + 0x218C) = 0x100;
    p = *(char **)(self + 0x21B0);
    if (p != 0 && *(short *)(p + 0x54A) > 0) {
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(f.vec));
        f.k = *(unsigned char *)(p + 0x2B4);
        if (2 < f.k)
            s0 = *(char **)(*(char **)(p + 0x278) + 8);
        else
            s0 = 0;
        if (s0 != 0) {
            f.vec[0] = 0.0f;
            f.vec[2] = 1.0f;
            f.vec[1] = 0.0f;
            sceVu0ApplyMatrix(f.vec, s0 + 0x80, f.vec);
            __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0"
                             : "+m"(f.vec) : "r"(*(char **)(s0 + 0xF0)));
            ang = capVu0Atan2__Fff(f.vec[0], f.vec[2]);
        } else {
            ang = *(float *)(p + 0x104);
        }
        MtxInitRotY__FR7cMatrixf(f.mtx, ang);
        f.vec[1] = 0.01f;
        f.vec[2] = -0.01f;
        f.vec[0] = 0.0f;
        sceVu0ApplyMatrix(f.vec, f.mtx, f.vec);
        if ((float *)(self + 0x2190) != f.vec) {
            *(float *)(self + 0x2190) = f.vec[0];
            *(float *)(self + 0x2194) = f.vec[1];
            *(float *)(self + 0x2198) = f.vec[2];
        }
        *(int *)(self + 0x218C) = 0x500;
    }
    func_00104010(self, self + 0x2130, self + 0x5B0);
}
#endif

// FUNCTION: GAME 0x289328
extern "C" int func_00289328(char *self)
{
    Qv2 a;
    Qv2 b;
    float one;
    char *v;
    char *pa;
    int r;
    int res;

    pa = (char *)&a;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(b));
    v = *(char **)(self + 0xF0);
    if (pa != v) {
        *(float *)pa = *(float *)v;
        *(float *)(pa + 4) = *(float *)(v + 4);
        *(float *)(pa + 8) = *(float *)(v + 8);
    }
    one = 1.0f;
    a.f[1] = a.f[1] + one;
    v = *(char **)((char *)Getplayer__Fv() + 0xF0);
    if ((char *)&b != v) {
        b.f[0] = *(float *)v;
        b.f[1] = *(float *)(v + 4);
        b.f[2] = *(float *)(v + 8);
    }
    b.f[1] = b.f[1] + one;
    res = 1;
    r = ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(&a, &b, 0, 0, 1, 0x18, 0, 0, 0, 0, 0, 0, res);
    if ((r ^ 1) == 0)
        res = 0;
    return res;
}

// DRAFT: GAME 0x2894B8 - 1 word; dsrl vs sra on D_00747A2C>>3 test
#ifdef NONMATCHING
extern "C" int func_002894B8(char *self)
{
    Qv2 a;
    Qv2 b;
    char *p;
    char *v;
    char *pa;
    int res;
    int r;

    p = (char *)Getplayer__Fv();
    if (*(float *)(p + 0x54C) > 0.0f)
        return 0;
    if (((unsigned long)D_00747A2C >> 3) & 1)
        return 0;
    if (*(short *)(p + 0x54A) <= 0)
        return 0;
    pa = (char *)&a;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(b));
    v = *(char **)(self + 0xF0);
    if (pa != v) {
        a.f[0] = *(float *)v;
        *(float *)(pa + 4) = *(float *)(v + 4);
        *(float *)(pa + 8) = *(float *)(v + 8);
    }
    v = *(char **)((char *)Getplayer__Fv() + 0xF0);
    if ((char *)&b != v) {
        b.f[0] = *(float *)v;
        b.f[1] = *(float *)(v + 4);
        b.f[2] = *(float *)(v + 8);
    }
    a.f[1] = a.f[1] + 0.5f;
    b.f[1] = b.f[1] + 0.5f;
    res = 1;
    r = ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(&a, &b, 0, 0, 1, 0x18, 0, 0, 0, 0, 0, 0, res);
    if (r == 1)
        return 0;
    *(float *)(self + 0x54C) = 30.0f;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    return 1;
}
#endif
