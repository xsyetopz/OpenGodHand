// Fn1380A8: free units 0x1380A8, 0x2B8E10, 0x2BDA20, 0x14F928 (camera, collision, VU0 paths).
extern unsigned D_00747A84;
extern "C" void VecRotVec__FR4cVecRC4cVecT1Uc(void *, void *, void *, unsigned char);

// FUNCTION: GAME 0x14F928
extern "C" void addNullSpeed__8cObjBasef(char *self, float fparg0)
{
    if (!(D_00747A84 & 0x20000000)) {
        float v[4];
        __asm__ volatile("sqc2 $vf0,0x0(%0)" : : "r"(v) : "memory");
        v[0] = *(float *)(self + 0x330) * *(float *)(self + 0x110) * fparg0;
        v[1] = *(float *)(self + 0x334) * *(float *)(self + 0x114) * fparg0;
        v[2] = *(float *)(self + 0x338) * *(float *)(self + 0x118) * fparg0;
        VecRotVec__FR4cVecRC4cVecT1Uc(v, v, self + 0x100, 0);
        *(float *)(*(char **)(self + 0xF0) + 0) += v[0];
        *(float *)(*(char **)(self + 0xF0) + 4) += v[1];
        *(float *)(*(char **)(self + 0xF0) + 8) += v[2];
    }
}

extern "C" int func_002B8A30(void *, unsigned);
extern "C" float capVu0LengthSq__FPCf(const float *v);
extern "C" void func_002BB760(void *, float *, float *, float);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B8E10 - 56 words; null check before mask, do-while loop; frame 0xB0 vs 0xC0, s-reg order differs
extern "C" char *checkNearCollision__17cCollisionManager15eCollisionLayerRC4cVecf(char *self, int layer, float *pos, float r)
{
    float rr = r * r;
    int id = func_002B8A30(self, layer);
    float a[4];
    __asm__ volatile("sqc2 $vf0,0x0(%0)" : : "r"(a) : "memory");
    char *node = *(char **)(self + 0x10);
    if (node == 0) return 0;
    unsigned *mask = (unsigned *)(self + 0x1C + (layer << 2));
    do {
        int ok = ((*(unsigned *)node & 0x203) == 3);
        if (ok == 1 && *(unsigned char *)(node + 0xC) != id && (*mask & (ok << *(int *)(node + 0x10)))) {
            char *obj = *(char **)(node + 0x34);
            float *v = *(float **)(obj + 0xC0);
            float d[4];
            float t[4];
            __asm__ volatile("sqc2 $vf0,0x0(%0)" : : "r"(d) : "memory");
            __asm__ volatile("lqc2 $vf4,0x0(%0)\n\tlqc2 $vf5,0x0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0x0(%2)" : : "r"(v), "r"(pos), "r"(d) : "memory");
            __asm__ volatile("lqc2 $vf4,0x0(%0)\n\tsqc2 $vf4,0x0(%1)" : : "r"(d), "r"(t) : "memory");
            float *pt = t;
            if (pt != a) {
                a[0] = pt[0];
                a[1] = pt[1];
                a[2] = pt[2];
            }
            if (capVu0LengthSq__FPCf(a) < rr) return node;
        }
        node = *(char **)(node + 4);
    } while (node != 0);
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2BDA20 - 79 words; eight-corner array via explicit stores, halving in C, call void
extern "C" void checkRectboxPoint__15cCollisionUtilsRC7cMatrixRC4cVecT2(char *mtx, float *va, float *vb)
{
    float q[8][4];
    float h[4];
    int i;
    float *p = &q[0][0];
    for (i = 7; i != -1; i--) {
        __asm__ volatile("sqc2 $vf0,0x0(%0)" : : "r"(p) : "memory");
        p += 4;
    }
    __asm__ volatile("lqc2 $vf4,0x0(%1)\n\tsqc2 $vf4,0x0(%0)" : : "r"(h), "r"(va) : "memory");
    __asm__ volatile("lqc2 $vf4,0x0(%0)\n\tqmtc2.ni %1,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,0x0(%0)" : : "r"(h), "r"(0.5f) : "memory");
    q[1][0] = h[0];
    q[0][2] = -h[2];
    q[0][1] = 0.0f;
    q[0][0] = -h[0];
    q[1][2] = -h[2];
    q[1][1] = 0.0f;
    q[2][0] = -h[0]; q[2][1] = 0.0f; q[2][2] = h[2];
    q[3][0] = h[0];  q[3][1] = 0.0f; q[3][2] = h[2];
    q[4][0] = -h[0]; q[4][1] = va[1]; q[4][2] = -h[2];
    q[5][0] = h[0];  q[5][1] = va[1]; q[5][2] = -h[2];
    q[6][0] = -h[0]; q[6][1] = va[1]; q[6][2] = h[2];
    q[7][0] = h[0];  q[7][1] = va[1]; q[7][2] = h[2];
    func_002BB760(vb, (float *)mtx, &q[0][0], 0.0f);
}
#endif

extern char D_0041D8B8;
extern "C" void reset__7cCamera(void *);

#define CAM_ZERO_BLOCK(b) __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(b) : "memory")
// FUNCTION: GAME 0x1380A8
extern "C" void *__7cCamera(void *self)
{
    *(char **)((char *)self + 0x35C) = &D_0041D8B8;
    __asm__ volatile("sqc2 $vf0,0x1D0(%0)\n\tsqc2 $vf0,0x1E0(%0)\n\tsqc2 $vf0,0x200(%0)\n\tsqc2 $vf0,0x210(%0)\n\tsqc2 $vf0,0x220(%0)\n\tsqc2 $vf0,0x230(%0)\n\tsqc2 $vf0,0x240(%0)\n\tsqc2 $vf0,0x280(%0)\n\tsqc2 $vf0,0x290(%0)\n\tsqc2 $vf0,0x2A0(%0)\n\tsqc2 $vf0,0x300(%0)\n\tsqc2 $vf0,0x320(%0)\n\tsqc2 $vf0,0x330(%0)\n\tsqc2 $vf0,0x340(%0)" : : "r"(self) : "memory");
    CAM_ZERO_BLOCK((char *)self);
    CAM_ZERO_BLOCK((char *)self + 0x40);
    CAM_ZERO_BLOCK((char *)self + 0x80);
    CAM_ZERO_BLOCK((char *)self + 0xC0);
    CAM_ZERO_BLOCK((char *)self + 0x100);
    CAM_ZERO_BLOCK((char *)self + 0x140);
    CAM_ZERO_BLOCK((char *)self + 0x180);
    reset__7cCamera(self);
    return self;
}
