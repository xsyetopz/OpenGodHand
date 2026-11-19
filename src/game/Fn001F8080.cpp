// Slice S05: free game units 0x1F8080, 0x1FD338, 0x274E98.

extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(void *m, const void *v, unsigned char f);
extern "C" void sceVu0ApplyMatrix(void *d, void *m, void *s);

typedef struct {
    float x, y, z, w;
} Qv1F;

class cVec;
class cDamageGive {
public:
    void SetDmgGiveHitVecDir(const cVec &v);
};

// FUNCTION: GAME 0x1FD338
void cDamageGive::SetDmgGiveHitVecDir(const cVec &v) {
    float mat[16];
    Qv1F vec;
    float *out;

    __asm__ volatile("sqc2 $vf0,%0" : "=m"(vec));
    vec.x = 0.0f;
    vec.z = 1.0f;
    vec.y = 0.0f;
    MtxInitRotVec__FR7cMatrixRC4cVecUc(mat, (const void *)&v, 0);
    sceVu0ApplyMatrix(&vec, mat, &vec);
    out = (float *)((char *)this + 0x10);
    if (out != (float *)&vec) {
        float x = vec.x;
        float y = vec.y;
        out[0] = x;
        out[1] = y;
        __asm__ volatile("" : : : "memory");
        out[2] = vec.z;
    }
}

extern "C" unsigned short D_00747A50;
extern "C" char g_SceAt;
extern "C" int func_002C2638(void *at, int a1, void *a2, void *a3);

// FUNCTION: GAME 0x274E98
extern "C" int func_00274E98(void *self) {
    Qv1F vec;
    float f;
    unsigned char *s = (unsigned char *)self;
    int v;

    __asm__ volatile("sqc2 $vf0,%0" : "=m"(vec));
    if (D_00747A50 != 0x700) {
        return 0;
    }
    v = *(int *)(s + 0x564);
    if (v < 0x224) {
        if (!(v < 0x220)) {
            return 0;
        }
    }
    if (!func_002C2638(&g_SceAt, *(int *)(s + 0xF0), &vec, &f)) {
        return 0;
    }
    float *dst = (float *)(s + 0x580);
    if (dst != (float *)&vec) {
        float x = vec.x;
        float y = vec.y;
        dst[0] = x;
        dst[1] = y;
        __asm__ volatile("" : : : "memory");
        dst[2] = vec.z;
    }
    *(unsigned char *)(s + 0x2F5) = 0x88;
    *(float *)(s + 0x598) = f;
    __asm__ volatile("" : : : "memory");
    int ret = 1;
    __asm__ volatile("" : "+r"(ret));
    *(unsigned char *)(s + 0x2F7) = 0;
    __asm__ volatile("" : : : "memory");
    *(unsigned char *)(s + 0x2F4) = 0;
    __asm__ volatile("" : : : "memory");
    *(unsigned char *)(s + 0x2F6) = 0;
    return ret;
}

extern "C" unsigned int D_003BF140[];

// Whole body in one asm block: sign fold of x against pi/2, VU0 polynomial, sqc2 to out.
// FUNCTION: GAME 0x1F8080
extern "C" void func_001F8080(float x) {
    register float fx __asm__("$f12") = x;
    register void *out __asm__("$4");
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        ".set noat\n\t"
        "mtc1 $0, $f0\n\t"
        "nop\n\t"
        "c.lt.s $f12, $f0\n\t"
        "lui $1, 0x3FC9\n\t"
        "ori $1, $1, 0x0FDB\n\t"
        "mtc1 $1, $f0\n\t"
        "bc1f 1f\n\t"
        "nop\n\t"
        "add.s $f12, $f0, $f12\n\t"
        "addiu $7, $0, 1\n\t"
        "j 2f\n\t"
        "nop\n\t"
        "1:\n\t"
        "sub.s $f12, $f0, $f12\n\t"
        "daddu $7, $0, $0\n\t"
        "2:\n\t"
        "mfc1 $8, $f12\n\t"
        "qmtc2.ni $8, $vf6\n\t"
        "lui $8, %%hi(D_003BF140)\n\t"
        "addiu $8, $8, %%lo(D_003BF140)\n\t"
        "lqc2 $vf5, 0($8)\n\t"
        "vmr32.w $vf6, $vf6\n\t"
        "vaddx.x $vf4, $vf0, $vf6x\n\t"
        "vmul.x $vf6, $vf6, $vf6\n\t"
        "vmulx.yzw $vf4, $vf4, $vf0x\n\t"
        "vmulw.xyzw $vf8, $vf5, $vf6w\n\t"
        "vsub.xyzw $vf5, $vf0, $vf0\n\t"
        "vmulx.xyzw $vf8, $vf8, $vf6x\n\t"
        "vmulx.xyz $vf8, $vf8, $vf6x\n\t"
        "vaddw.x $vf4, $vf4, $vf8w\n\t"
        "vmulx.xy $vf8, $vf8, $vf6x\n\t"
        "vaddz.x $vf4, $vf4, $vf8z\n\t"
        "vmulx.x $vf8, $vf8, $vf6x\n\t"
        "vaddy.x $vf4, $vf4, $vf8y\n\t"
        "vaddx.x $vf4, $vf4, $vf8x\n\t"
        "vaddx.xy $vf4, $vf5, $vf4x\n\t"
        "vmul.x $vf7, $vf4, $vf4\n\t"
        "vsubx.w $vf7, $vf0, $vf7x\n\t"
        ".word 0x4B8703BD\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf7, $vf0, $Q\n\t"
        "bnez $7, 3f\n\t"
        "nop\n\t"
        "vaddx.x $vf4, $vf5, $vf7x\n\t"
        "b 4f\n\t"
        "nop\n\t"
        "3:\n\t"
        "vsubx.x $vf4, $vf5, $vf7x\n\t"
        "4:\n\t"
        "sqc2 $vf4, 0($4)\n\t"
        ".set pop\n\t"
        : "+f"(fx)
        : "r"(out)
        : "memory", "$1", "$7", "$8", "$f0");
}
