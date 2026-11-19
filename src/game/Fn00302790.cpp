// Effect-object setup units from the 0x302790 region. Field offsets are written as raw byte offsets
// in asm order; VU0 quad stores (sqc2 $vf0) use inline asm.
extern "C" void *func_002B5C20(void *, int, int);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, void *);
extern "C" void *memset(void *, int, unsigned);
extern int D_0044FD58;
extern int D_00747A34;
extern int D_0044B528;
extern int D_00754C10;
extern int RoomHeap;
extern "C" void __8cObjBase(void *);

#define SQC2_VF0(off, base) __asm__ volatile("sqc2 $vf0,%0(%1)" : : "i"(off), "r"(base) : "memory")

// FUNCTION: GAME 0x302790
extern "C" void *func_00302790(void *self)
{
    func_002B5C20(self, 0, 0);
    *(int *)((char *)self + 0x104) = 0;
    *(void **)((char *)self + 0xF0) = &D_0044FD58;
    char *a = (char *)self + 0x1A0;
    *(int *)((char *)self + 0x108) = 0;
    *(int *)((char *)self + 0x10C) = 0;
    *(int *)((char *)self + 0x110) = 0;
    *(int *)((char *)self + 0x114) = 0;
    *(int *)((char *)self + 0x11C) = 0;
    *(int *)((char *)self + 0x120) = 0;
    *(int *)((char *)self + 0x124) = 0;
    *(int *)((char *)self + 0x128) = 0;
    *(int *)((char *)self + 0x12C) = 0;
    *(int *)((char *)self + 0x130) = 0;
    *(int *)((char *)self + 0x134) = 0;
    *(int *)((char *)self + 0x138) = 0;
    *(int *)((char *)self + 0x13C) = 0;
    *(int *)((char *)self + 0x140) = 0;
    *(int *)((char *)self + 0x144) = 0;
    *(int *)((char *)self + 0x148) = 0;
    *(int *)((char *)self + 0x14C) = 0;
    *(int *)((char *)self + 0x150) = 0;
    *(int *)((char *)self + 0x154) = 0;
    *(int *)((char *)self + 0x158) = 0;
    *(int *)((char *)self + 0x15C) = 0;
    *(int *)((char *)self + 0x160) = 0;
    *(int *)((char *)self + 0x164) = 0;
    *(int *)((char *)self + 0x168) = 0;
    *(int *)((char *)self + 0x16C) = 0;
    *(int *)((char *)self + 0x170) = 0;
    *(int *)((char *)self + 0x174) = 0;
    *(int *)((char *)self + 0x178) = 0;
    *(int *)((char *)self + 0x17C) = 0;
    *(int *)((char *)self + 0x180) = 0;
    *(short *)((char *)self + 0x184) = 0;
    *(short *)((char *)self + 0x186) = 0;
    *(short *)((char *)self + 0x188) = 0;
    *(short *)((char *)self + 0x18A) = 0;
    *(short *)((char *)self + 0x18E) = 0;
    *(char *)((char *)self + 0x190) = 0;
    *(float *)((char *)self + 0x1A0) = 1.0f;
    *(float *)(a + 0x4) = 1.0f;
    *(float *)(a + 0x8) = 1.0f;
    *(float *)(a + 0xC) = 1.0f;
    SQC2_VF0(0x1B0, self);
    SQC2_VF0(0x1C0, self);
    *(float *)((char *)self + 0x1D0) = 1.0f;
    char *v = (char *)self + 0x1D0;
    *(volatile float *)(v + 0xC) = 1.0f;
    *(volatile float *)(v + 0x4) = 1.0f;
    *(volatile float *)(v + 0x8) = 1.0f;
    *(signed char *)(a + 0x4C) = -1;
    *(unsigned char *)(a + 0x4F) = 0xFF;
    *(float *)(a + 0x40) = 1.0f;
    *(int *)(a + 0x44) = 0;
    *(int *)(a + 0x48) = 0;
    *(char *)(a + 0x4D) = 0;
    *(char *)(a + 0x4E) = 0;
    *(int *)(a + 0x50) = 0;
    SQC2_VF0(0x200, self);
    *(volatile int *)(a + 0x78) = 0;
    *(volatile short *)(a + 0x70) = 0;
    *(volatile short *)(a + 0x72) = 0;
    *(volatile char *)(a + 0x74) = 0;
    *(float *)((char *)self + 0x22C) = 1.0f;
    *(int *)((char *)self + 0x170) = 0;
    *(int *)((char *)self + 0x174) = 0;
    *(int *)((char *)self + 0x178) = 0;
    *(char *)((char *)self + 0x230) = 0;
    return self;
}

extern "C" void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x306838
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int type, int id, void *obj, const float *pos, float scale, int flag)
{
    unsigned char buf[0x80];
    *(float *)(buf + 0x0) = 1.0f;
    *(float *)(buf + 0x4) = 1.0f;
    *(float *)(buf + 0x8) = 1.0f;
    *(float *)(buf + 0xC) = 1.0f;
    SQC2_VF0(0x10, buf);
    char *a = (char *)buf + 0x20;
    SQC2_VF0(0x20, buf);
    char *v = (char *)buf + 0x30;
    *(float *)(buf + 0x30) = 1.0f;
    *(volatile float *)(v + 0xC) = 1.0f;
    *(volatile float *)(v + 0x4) = 1.0f;
    *(volatile float *)(v + 0x8) = 1.0f;
    *(volatile float *)(buf + 0x40) = 1.0f;
    *(signed char *)(buf + 0x4C) = -1;
    *(unsigned char *)(buf + 0x4F) = 0xFF;
    *(int *)(buf + 0x44) = 0;
    *(int *)(buf + 0x48) = 0;
    *(char *)(buf + 0x4D) = 0;
    *(char *)(buf + 0x4E) = 0;
    *(int *)(buf + 0x50) = 0;
    SQC2_VF0(0x60, buf);
    *(volatile short *)(buf + 0x70) = 0;
    *(volatile short *)(buf + 0x72) = 0;
    *(volatile char *)(buf + 0x74) = 0;
    *(int *)(buf + 0x78) = 0;
    if ((void *)a != (void *)pos) {
        *(float *)(buf + 0x20) = pos[0];
        *(float *)(buf + 0x24) = pos[1];
        *(float *)(buf + 0x28) = pos[2];
    }
    *(float *)(buf + 0x40) = scale;
    SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(type, id, obj, buf, flag, 0xFFFFFFFFu);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x317D50 - 43 words; frame 0x20 vs 0x30 and flag-branch form differ; variants tried: single ptr, split ptr, barrier before/after memset, single exit, early flag return
extern "C" void *func_00317D50(void)
{
    if (D_00747A34 & 0x10000) {
        return 0;
    }
    char *p = (char *)_MemoryAlloc__FUiUiR5cHeap(0x30E0, 0x10, &D_00754C10);
    if (p != 0) {
        {
            char *s = p;
            memset(p, 0, 0x30E0);
            __8cObjBase(s);
            *(void **)(s + 0x214) = &D_0044B528;
            char *base = s + 0x13A0;
            int i = 0x2B;
            do {
                SQC2_VF0(0x00, base);
                SQC2_VF0(0x10, base);
                SQC2_VF0(0x30, base);
                SQC2_VF0(0x40, base);
                SQC2_VF0(0x50, base);
                SQC2_VF0(0x80, base);
                i--;
                base += 0xA0;
            } while (i != -1);
            SQC2_VF0(0x2F80, p);
            SQC2_VF0(0x2FB0, p);
            SQC2_VF0(0x2FD0, p);
            SQC2_VF0(0x2FE0, p);
            char *q = p + 0x3000;
            int n = 3;
            do {
                char *r = q + 0x20;
                int k = 1;
                int m = n - 1;
                do {
                    SQC2_VF0(0x0, q);
                    k--;
                    q += 0x10;
                } while (k != -1);
                q = r;
                n = m;
            } while (n != -1);
            SQC2_VF0(0x30C0, p);
            SQC2_VF0(0x30D0, p);
            *(char *)(p + 0x4D0) = 0;
            *(char *)(p + 0x1390) = 0;
            *(char *)(p + 0x2FA0) = 0;
            *(char *)(p + 0x4E0) = 0;
            *(char *)(p + 0x2FF0) = 0;
            *(int *)(p + 0x30A4) = 0;
        }
    }
    return p;
}

// DRAFT: GAME 0x3181A8 - 43 words; frame 0x20 vs 0x30 and bnez/beqz flag-branch form differ; variants tried: early flag return, copy before/after memset, memset return value (61), same as 0x317D50
extern "C" void *func_003181A8(void)
{
    if (D_00747A34 & 0x100000) {
        return 0;
    }
    char *p = (char *)_MemoryAlloc__FUiUiR5cHeap(0x30E0, 0x10, &RoomHeap);
    if (p != 0) {
        {
            char *s = p;
            memset(p, 0, 0x30E0);
            __8cObjBase(s);
            *(void **)(s + 0x214) = &D_0044B528;
            char *base = s + 0x13A0;
            int i = 0x2B;
            do {
                SQC2_VF0(0x00, base);
                SQC2_VF0(0x10, base);
                SQC2_VF0(0x30, base);
                SQC2_VF0(0x40, base);
                SQC2_VF0(0x50, base);
                SQC2_VF0(0x80, base);
                i--;
                base += 0xA0;
            } while (i != -1);
            SQC2_VF0(0x2F80, p);
            SQC2_VF0(0x2FB0, p);
            SQC2_VF0(0x2FD0, p);
            SQC2_VF0(0x2FE0, p);
            char *q = p + 0x3000;
            int n = 3;
            do {
                char *r = q + 0x20;
                int k = 1;
                int m = n - 1;
                do {
                    SQC2_VF0(0x0, q);
                    k--;
                    q += 0x10;
                } while (k != -1);
                q = r;
                n = m;
            } while (n != -1);
            SQC2_VF0(0x30C0, p);
            SQC2_VF0(0x30D0, p);
            *(char *)(p + 0x4D0) = 0;
            *(char *)(p + 0x1390) = 0;
            *(char *)(p + 0x2FA0) = 0;
            *(char *)(p + 0x4E0) = 0;
            *(char *)(p + 0x2FF0) = 0;
            *(int *)(p + 0x30A4) = 0;
        }
    }
    return p;
}
#endif
