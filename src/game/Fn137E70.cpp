// Free units from 0x137E70, 0x156550, 0x15AF30 and 0x17F320 (slice F179).

typedef int Row __attribute__((mode(TI)));

extern const char D_0041EDF0[];
extern float V0001[];

extern "C" void sceVu0UnitMatrix(float *);
extern "C" void sceVu0RotMatrix(float *, float *, float *);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" float sceVu0InnerProduct(float *, float *);
float capVu0Acos(float x);
extern float D_003C3C40[];
extern "C" float capVu0Atan2__Fff(float, float);
extern "C" void sceVu0RotMatrixY(float *, float *, float);
extern "C" void func_0030A650(float *, float *, float);
extern "C" void func_0030A3B0(float *, float *);
extern "C" void func_0030A700(float, float *, float *);
extern "C" void sceVu0MulMatrix(float *, float *, float *);
extern "C" void sceVu0SubVector(float *, float *, float *);

#ifdef NONMATCHING
// DRAFT: GAME 0x137E70 - 50 words; Tried: v/m pointer locals, inline buf offsets (50), separate v/m arrays (51); frame 0xA0 with extra saved s3 vs 0x90.
extern "C" float func_00137E70(char *obj, float *a1, float *a2)
{
    float buf[20] __attribute__((aligned(16)));
    float *s2 = *(float **)(obj + 0x30);
    __asm__("sqc2 $vf0,0x0(%0)" : : "r"(buf) : "memory");
    buf[0] = V0001[0];
    buf[1] = V0001[1];
    buf[2] = 1.0f;
    sceVu0UnitMatrix(buf + 4);
    sceVu0RotMatrix(buf + 4, buf + 4, a2);
    sceVu0ApplyMatrix(buf, buf + 4, buf);
    float d = capVu0Acos(sceVu0InnerProduct(a1, buf));
    float f1 = *(float *)((char *)s2 + 0x60);
    if (f1 < d) {
        return 0.0f;
    }
    return (f1 - d) / f1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x156550 - 19 words; Tried: per-op asm, reused temps, local copies, register pins; original copies dst/src to $t0/$v1 and ours does not.
extern "C" void func_00156550(Row *dst, const Row *src)
{
    register Row *d __asm__("$8") = dst;
    register const Row *p __asm__("$3") = src;
    const Row *tab = (const Row *)D_0041EDF0;
    Row s = *p;
    __asm__("psllw %0,%0,14" : "+r"(s));
    Row t = tab[0];
    Row u = tab[1];
    __asm__("pand %0,%0,%1" : "+r"(t) : "r"(s));
    __asm__("paddw %0,%0,%1" : "+r"(t) : "r"(u));
    Row v = tab[2];
    __asm__("pand %0,%0,%1" : "+r"(v) : "r"(s));
    __asm__("por %0,%0,%1" : "+r"(v) : "r"(t));
    __asm__("psllw %0,%0,2" : "+r"(s));
    t = tab[3];
    __asm__("pand %0,%0,%1" : "+r"(t) : "r"(s));
    __asm__("por %0,%1,%2" : "=r"(s) : "r"(v), "r"(t));
    *d = s;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x17F320 - 63 words; Tried: draft 1 (82), pB/pC after func_001B6FB8 (63), pA reload for C[0] (63, no change), B[1],B[2] stored first (69), separate -0.5f local (63, tie).
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" void func_001BBF68(char *);
extern "C" int func_0017F320(char *obj)
{
    float A[4] __attribute__((aligned(16)));
    float B[4] __attribute__((aligned(16)));
    float C[4] __attribute__((aligned(16)));
    func_001B6FB8(obj);
    float *pB = B;
    float *pC = C;
    float one = 1.0f;
    A[0] = 2.13f;
    A[1] = 3.78f;
    A[2] = 0.2f;
    A[3] = one;
    B[0] = A[0];
    B[1] = A[1];
    B[2] = A[2];
    B[3] = one;
    float half = -0.5f;
    C[0] = A[0] * half;
    C[1] = 0.0f;
    C[2] = 0.0f;
    C[3] = one;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, obj, 2);
    *(void **)(obj + 0x600) = t;
    if (t != 0) {
        float D[4] __attribute__((aligned(16)));
        D[0] = 0.0f;
        D[1] = 0.0f;
        D[2] = 0.0f;
        D[3] = one;
        func_001FD9D8(t, obj + 0x80, pC, D, pB);
    }
    *(short *)(obj + 0x548) = 1;
    *(short *)(obj + 0x54A) = 1;
    float *dst = (float *)(obj + 0x610);
    if (dst != A) {
        dst[0] = A[0];
        dst[1] = A[1];
        dst[2] = A[2];
    }
    setObjCollision__7cOmDoor(obj);
    *(char *)(obj + 0x624) = 1;
    *(char **)(obj + 0x628) = obj + 0x650;
    func_001BBF68(obj);
    *(int *)(obj + 0x5B8) |= 2;
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x15AF30 - 18 words; Tried: draft 1 (43, v[1] hoisted above sqrt), sqrt asm __volatile__ with memory clobber (18), V scoped in own block (18, no change); original recomputes V address per call, ours keeps it in $s0.
extern "C" void func_0015AF30(float s, float *out, float *v, float *m)
{
    float M1[16] __attribute__((aligned(16)));
    float M2[16] __attribute__((aligned(16)));
    float ang;
    if (v[0] == 0.0f && v[2] == 0.0f) {
        ang = capVu0Atan2__Fff(v[1], 0.0f);
        func_0030A650(M1, D_003C3C40, -ang);
    } else {
        ang = capVu0Atan2__Fff(v[2], v[0]);
        sceVu0RotMatrixY(M1, D_003C3C40, ang);
        float r2 = v[0] * v[0] + v[2] * v[2];
        float r;
        __asm__ __volatile__("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(r) : "f"(r2) : "memory");
        ang = capVu0Atan2__Fff(v[1], r);
        func_0030A650(M1, M1, -ang);
    }
    func_0030A3B0(M2, M1);
    func_0030A700(s, M1, M1);
    sceVu0MulMatrix(out, M2, M1);
    {
        float V[4] __attribute__((aligned(16)));
        sceVu0ApplyMatrix(V, out, m);
        sceVu0SubVector(out + 12, m, V);
    }
    out[15] = 1.0f;
}
#endif
