// Free units from 0x134CB0, 0x135EC8 and 0x136458 (slice F175).
// 0x137E70 is claimed by src/game/Fn137E70.cpp (slice F179) and is not defined here.

extern "C" {
void sceVu0OuterProduct(float *d, const float *a, const float *b);
float sceVu0InnerProduct(const float *a, const float *b);
void sceVu0Normalize(float *d, const float *s);
void sceVu0SubVector(float *d, const float *a, const float *b);
void sceVu0ScaleVector(float *d, const float *s, float k);
}
extern "C" int func_00135EC8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern "C" int func_00136030(void *arg0, void *arg1);

// FUNCTION: GAME 0x136458
extern "C" int func_00136458(void *arg0, void *arg1, void *arg2, void *arg3)
{
    float buf[20] __attribute__((aligned(16)));
    float f0;

    __asm__ volatile("sqc2 $vf0, 0x0(%0)\n\tsqc2 $vf0, 0x10(%0)" : : "r"(buf) : "memory");
    char *q10 = (char *)arg2 + 0x10;
    float *p8 = buf + 8;
    __asm__ volatile("sqc2 $vf0, 0x30(%0)" : : "r"(buf) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyz $vf4, $vf4, $vf5\n\tsqc2 $vf4, 0x30(%2)" : : "r"(q10), "r"(arg2), "r"(buf) : "memory");
    float *p12 = buf + 12;
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0x20(%1)" : : "r"(p12), "r"(buf) : "memory");
    char *q20 = (char *)arg2 + 0x20;
    __asm__ volatile("sqc2 $vf0, 0x40(%0)" : : "r"(buf) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyz $vf4, $vf4, $vf5\n\tsqc2 $vf4, 0x40(%2)" : : "r"(q20), "r"(arg2), "r"(buf) : "memory");
    float *p16 = buf + 16;
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0x30(%1)" : : "r"(p16), "r"(buf) : "memory");
    sceVu0OuterProduct(buf, p8, p12);
    __asm__ volatile("sqc2 $vf0, 0x30(%0)" : : "r"(buf) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyz $vf4, $vf4, $vf5\n\tsqc2 $vf4, 0x30(%2)" : : "r"(arg1), "r"(arg0), "r"(buf) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0x20(%1)" : : "r"(p12), "r"(buf) : "memory");
    f0 = sceVu0InnerProduct(buf, p8);
    if (0.0f <= f0) return 0;
    if (!func_00135EC8(arg0, arg1, buf, arg2, buf + 4)) return 0;
    if (!func_00136030(arg2, buf + 4)) return 0;
    if (arg3 != 0 && (float *)arg3 != buf + 4) {
        ((float *)arg3)[0] = buf[4];
        ((float *)arg3)[1] = buf[5];
        ((float *)arg3)[2] = buf[6];
    }
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x135EC8 - 66 differing words (356 vs 360 bytes); frame 0xB0 matches; prologue save order and early s0 hoist (addiu s0,sp,0x10) differ. Variants: separate arrays, named pointers across calls (frame 0xF0), s0 set early.
extern "C" int func_00135EC8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    float buf[20] __attribute__((aligned(16)));
    float *dir = buf + 4;
    union { float f; unsigned int u; } cv;
    float f20;
    float f0;

    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(dir) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyz $vf4, $vf4, $vf5\n\tsqc2 $vf4, 0(%2)" : : "r"(arg1), "r"(arg0), "r"(dir) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)" : : "r"(dir), "r"(buf) : "memory");
    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(dir) : "memory");
    sceVu0Normalize(dir, (const float *)arg2);
    f20 = sceVu0InnerProduct(dir, (const float *)arg3);
    f20 = f20 - sceVu0InnerProduct(dir, (const float *)arg0);
    f0 = sceVu0InnerProduct(dir, buf);
    if (f0 == 0.0f) {
        return 0;
    }
    f20 = f20 / f0;
    if (!(0.0f <= f20)) {
        return 0;
    }
    if (!(f20 <= 1.0f)) {
        return 0;
    }
    if (arg4 == 0) {
        return 1;
    }
    cv.f = f20;
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)\n\tlqc2 $vf4, 0(%1)\n\tqmtc2.ni %2, $vf5\n\tvmulx.xyz $vf4, $vf4, $vf5x\n\tsqc2 $vf4, 0(%1)" : : "r"(buf), "r"(buf + 16), "r"(cv.u) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)" : : "r"(buf + 16), "r"(buf + 12) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)" : : "r"(arg0), "r"(buf + 16) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvadd.xyz $vf4, $vf4, $vf5\n\tsqc2 $vf4, 0(%0)" : : "r"(buf + 16), "r"(buf + 12) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)" : : "r"(buf + 16), "r"(buf + 8) : "memory");
    if ((float *)arg4 != buf + 8) {
        ((float *)arg4)[0] = buf[8];
        ((float *)arg4)[2] = buf[10];
        ((float *)arg4)[1] = buf[9];
    }
    return 1;
}

#endif

// FUNCTION: GAME 0x134CB0
extern "C" int func_00134CB0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    float tmp0[4] __attribute__((aligned(16)));
    float tmp1[4] __attribute__((aligned(16)));
    float res[4] __attribute__((aligned(16)));
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0(%1)" : : "r"((char *)arg2 + 0x60), "r"(tmp0) : "memory");
    __asm__ volatile("lqc2 $vf4, 0(%0)\n\tsqc2 $vf4, 0x10($sp)" : : "r"((char *)arg4 + 0x60) : "memory");
    float *t1 = tmp1;
    float dx = t1[0] - tmp0[0];
    float dz = t1[2] - tmp0[2];
    float sum = *(float *)((char *)arg2 + 0x70) + *(float *)((char *)arg4 + 0x70);
    if (sum * sum < dx * dx + dz * dz) {
        return 0;
    }
    // The two nops ahead of sqrt.s are hazard padding of the original inline template.
    float sq = dx * dx + dz * dz;
    float dist;
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(dist) : "f"(sq));
    float f21 = sum - dist;
    int v = *(int *)((char *)arg1 + 0x8);
    if (v == 0) {
        return 1;
    }
    int w = *(int *)((char *)arg3 + 0x8);
    float f20;
    if (v == w) {
        f20 = *(float *)((char *)arg3 + 0xC);
    } else {
        f20 = 0.0f;
        if (w < v) {
            f20 = 1.0f;
        }
    }
    sceVu0SubVector(res, tmp0, tmp1);
    sceVu0Normalize(res, res);
    sceVu0ScaleVector(res, res, f21);
    float k = 1.0f - f20;
    register float *p __asm__("$4") = *(float **)((char *)*(void **)arg1 + 0xF0);
    float x = res[0];
    p[0] = p[0] + (x - x * k);
    p = *(float **)((char *)*(void **)arg1 + 0xF0);
    float z = res[2];
    p[2] = p[2] + (z - z * k);
    return 1;
}
