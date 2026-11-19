// Fn00275888: VU0 units 0x275888, 0x276DC8, 0x279D88, 0x27E7F0.
extern "C" void MtxInitRotY__FR7cMatrixf(void *m, float a);
extern "C" void sceVu0ApplyMatrix(char *, void *, char *);
extern "C" int func_002744B8(char *self);
extern "C" void func_00104010(void *, void *, void *);
extern "C" int func_00279F68(void *);
extern "C" void func_0028EBF0(void *, void *, int);
extern "C" void calcParts__6cModel(void *);
extern "C" void calcWorldParts__6cModel(void *);
extern "C" void InverseKinematics__2IKP8cObjBase(void *, void *);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void setRotationOrder__6cPartsUc(void *, int);
extern char g_CollSolidManage;
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(void *, void *, void *, int, int, int, int, int, int, int, int, int, int);
void func_00147C40(char *, float *);

struct Qv { float f[4]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x275888
// 29 differing words. Attempt 1 (=m sqc2 zeroing) gave 60 with sdc2 $0 and frame 0xD0. Attempt 2 (ZQ pointer-based sqc2) gave 29. Attempt 3 (int ret=1 with guarded return, b-store reorder) gave frame 0x100 and was reverted.
#define ZQ0(p) __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory")
extern "C" int func_00275888(char *self, float f)
{
    Qv a;
    Qv b;
    float m[16] __attribute__((aligned(16)));
    ZQ0(&a);
    ZQ0(&b);
    MtxInitRotY__FR7cMatrixf(m, *(float *)(self + 0x104));
    func_00147C40((char *)m, *(float **)(self + 0xF0));
    b.f[1] = 0.5f;
    b.f[2] = f;
    a.f[0] = 0;
    a.f[1] = 0.5f;
    a.f[2] = 0;
    b.f[0] = 0;
    sceVu0ApplyMatrix((char *)a.f, m, (char *)a.f);
    sceVu0ApplyMatrix((char *)b.f, m, (char *)b.f);
    return ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(a.f, b.f, 0, 0, 1, 0x124, 0, 1, 0, 0, 0, 0, 1) != 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x276DC8
// 13 differing words: callee-saved CSE of sp+0x40 into $s0 across the call; the original recomputes sp+0x40 and guards on self+0x2190 via $v1. Variants tried (7 attempts): reversed guard operands, v.f addressing, plain copy in original order, store-order and temp-based copies.
extern "C" void func_00276DC8(char *self)
{
    char *s0 = *(char **)(self + 0x21B0);
    *(int *)(self + 0x218C) = 0x100;
    if (s0 != 0) {
        if (func_002744B8(s0) != 0) {
            float m[16] __attribute__((aligned(16)));
            Qv v;
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(v));
            MtxInitRotY__FR7cMatrixf(m, *(float *)(s0 + 0x104));
            v.f[1] = 0.01f;
            v.f[2] = -0.01f;
            v.f[0] = 0;
            sceVu0ApplyMatrix((char *)v.f, m, (char *)v.f);
            if ((char *)v.f != self + 0x2190) {
                float *d = (float *)(self + 0x2190);
                d[0] = v.f[0];
                d[1] = v.f[1];
                d[2] = v.f[2];
            }
            *(int *)(self + 0x218C) = 0x500;
        }
    }
    func_00104010(self, self + 0x2130, self + 0x5B0);
}

// DRAFT: GAME 0x279D88
// 2 differing words: the 0x54A and 0x548 short stores swap at 00279E44/00279E54. Variants tried (8 attempts): guard as != 0, unsigned short stores, and tail store orders 548-first, 617-first, 1568-before-548 (best: 617, 54A, float, 1568, 548).
extern "C" int func_00279D88(char *self)
{
    char blk[0x34] __attribute__((aligned(16)));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(blk + 0x10)));
    *(unsigned char *)(blk + 0x31) = 0xFF;
    *(int *)(self + 0x564) = 0x23F;
    *(int *)(blk + 0x10) = 0;
    *(int *)(blk + 0x14) = 0;
    *(int *)(blk + 0x18) = 0;
    *(int *)(blk + 0x20) = 0;
    if (func_00279F68(self) != 0) {
        func_0028EBF0(self, blk, 0);
        *(int *)(self + 0x1580) = 0;
        *(int *)(self + 0x1584) = 0;
        calcParts__6cModel(self);
        InverseKinematics__2IKP8cObjBase(self + 0x448, self);
        calcWorldParts__6cModel(self);
        *(unsigned char *)(self + 0x616) = 1;
        *(signed char *)(self + 0x531) = -1;
        SetActive__21cCollisionSolidManageP8cGameObjb(&g_CollSolidManage, self, 0);
        setRotationOrder__6cPartsUc(self, 4);
        *(unsigned char *)(self + 0x617) = 0;
        *(unsigned short *)(self + 0x54A) = 1;
        *(float *)(self + 0x1564) = 0.02f;
        *(int *)(self + 0x1568) = 0;
        *(unsigned short *)(self + 0x548) = 1;
        return 1;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27E7F0
// Not yet measured. Draft from asm: clears flag 0x10 at +0x250, sets +0x24C = 1.0f, obj from +0x278 chain, copy-matrix path when arg1 != 0.
extern "C" void func_0027E7F0(char *self, char *arg1)
{
    int flag = *(unsigned char *)(self + 0x2B4);
    float m[16] __attribute__((aligned(16)));
    Qv a;
    Qv c;
    Qv b;
    char *obj = 0;
    *(unsigned int *)(self + 0x250) &= 0xFFFFFFEFu;
    *(float *)(self + 0x24C) = 1.0f;
    *(int *)(self + 0x1580) = 0;
    if (flag != 0) {
        obj = *(char **)(*(char **)(self + 0x278));
    }
    if (obj != 0) {
        *(char **)(obj + 0x148) = self;
        if (arg1 != 0) {
            ZQ0(&a);
            MtxInitRotY__FR7cMatrixf(m, *(float *)(arg1 + 0x104));
            func_00147C40((char *)m, *(float **)(arg1 + 0xF0));
            a.f[0] = 0.1973000019788742f;
            a.f[1] = 0;
            a.f[2] = -1.6928999423980713f;
            b = a;
            sceVu0ApplyMatrix((char *)b.f, m, (char *)b.f);
            c = b;
            if (*(char **)(self + 0xF0) != (char *)c.f) {
                float *d = *(float **)(self + 0xF0);
                d[0] = c.f[0];
                d[1] = c.f[1];
                d[2] = c.f[2];
            }
            if (self + 0x100 != arg1 + 0x100) {
                *(float *)(self + 0x100) = *(float *)(arg1 + 0x100);
                *(float *)(self + 0x104) = *(float *)(arg1 + 0x104);
                *(float *)(self + 0x108) = *(float *)(arg1 + 0x108);
            }
            calcParts__6cModel(self);
        }
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
    }
}
#endif
