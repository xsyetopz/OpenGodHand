#include "vu0.h"
// FUNCTION: GAME 0x1F7ED8
void capVu0AddVectorXYZ(float *d, const float *a, const float *b) { vu0_AddVectorXYZ(d, a, b); }
// FUNCTION: GAME 0x1F7E28
float capVu0LengthSq(const float *v) { return vu0_LengthSq(v); }
// FUNCTION: GAME 0x1F7DF8
float capVu0Length(const float *v) { return vu0_Length(v); }
// FUNCTION: GAME 0x1F7E48
float capVu0LengthAB(const float *a, const float *b) { return vu0_LengthAB(a, b); }
// FUNCTION: GAME 0x1F7E80
float capVu0MagnitudeXZ(const float *a, const float *b) { return vu0_MagnitudeXZ(a, b); }
// FUNCTION: GAME 0x1F7EB0
float capVu0MagnitudeSqXZ(const float *a, const float *b) { return vu0_MagnitudeSqXZ(a, b); }
// FUNCTION: GAME 0x1F8350
void capVu0ApplyMatrixXYZ(float *d, const float (*m)[4], const float *v) { vu0_ApplyMatrixXYZ(d, m, v); }

// Sin/Cos: the sign branch and the VU0 polynomial form one asm run (the original jumps into the
// middle of it); the assembler fills the branch delay slots, D_003BF140 is the coefficient table.
// FUNCTION: GAME 0x1F7EF0
float capVu0Sin(float x)
{
    __asm__ volatile(
        "\tmtc1 $zero,$f0\n"
        "\tnop\n"
        "\tc.lt.s %0,$f0\n"
        "\tlui $at,0x3FC9\n"
        "\tori $at,$at,0x0FDB\n"
        "\tmtc1 $at,$f0\n"
        "\tbc1f 1f\n"
        "\tadd.s %0,$f0,%0\n"
        "\taddiu $a3,$zero,1\n"
        "\tj 2f\n"
        "1:\n"
        "\tsub.s %0,$f0,%0\n"
        "\tdaddu $a3,$zero,$zero\n"
        "2:\n"
        "\tmfc1 $t0,%0\n"
        "\tqmtc2.ni $t0,$vf6\n"
        "\tlui $t0,%%hi(D_003BF140)\n"
        "\taddiu $t0,$t0,%%lo(D_003BF140)\n"
        "\tlqc2 $vf5,0($t0)\n"
        "\tvmr32.w $vf6,$vf6\n"
        "\tvaddx.x $vf4,$vf0,$vf6x\n"
        "\tvmul.x $vf6,$vf6,$vf6\n"
        "\tvmulx.yzw $vf4,$vf4,$vf0x\n"
        "\tvmulw.xyzw $vf8,$vf5,$vf6w\n"
        "\tvsub.xyzw $vf5,$vf0,$vf0\n"
        "\tvmulx.xyzw $vf8,$vf8,$vf6x\n"
        "\tvmulx.xyz $vf8,$vf8,$vf6x\n"
        "\tvaddw.x $vf4,$vf4,$vf8w\n"
        "\tvmulx.xy $vf8,$vf8,$vf6x\n"
        "\tvaddz.x $vf4,$vf4,$vf8z\n"
        "\tvmulx.x $vf8,$vf8,$vf6x\n"
        "\tvaddy.x $vf4,$vf4,$vf8y\n"
        "\tvaddx.x $vf4,$vf4,$vf8x\n"
        "\tvaddx.xy $vf4,$vf5,$vf4x\n"
        "\tvmul.x $vf7,$vf4,$vf4\n"
        "\tvsubx.w $vf7,$vf0,$vf7x\n"
        "\tvsqrt $Q,$vf7w\n"
        "\tvwaitq\n"
        "\tvaddq.x $vf7,$vf0,$Q\n"
        "\tbnez $a3,3f\n"
        "\tvaddx.x $vf4,$vf5,$vf7x\n"
        "\tb 4f\n"
        "3:\n"
        "\tvsubx.x $vf4,$vf5,$vf7x\n"
        "4:\n"
        "\tqmfc2.ni $t1,$vf4\n"
        "\tmtc1 $t1,%0\n"
        : "+f"(x) : : "$f0", "$7", "$8", "$9", "memory");
    return x;
}

// FUNCTION: GAME 0x1F7FB8
float capVu0Cos(float x)
{
    __asm__ volatile(
        "\tmtc1 $zero,$f0\n"
        "\tnop\n"
        "\tc.lt.s %0,$f0\n"
        "\tlui $at,0x3FC9\n"
        "\tori $at,$at,0x0FDB\n"
        "\tmtc1 $at,$f0\n"
        "\tbc1f 1f\n"
        "\tadd.s %0,$f0,%0\n"
        "\taddiu $a3,$zero,1\n"
        "\tj 2f\n"
        "1:\n"
        "\tsub.s %0,$f0,%0\n"
        "\tdaddu $a3,$zero,$zero\n"
        "2:\n"
        "\tmfc1 $t0,%0\n"
        "\tqmtc2.ni $t0,$vf6\n"
        "\tlui $t0,%%hi(D_003BF140)\n"
        "\taddiu $t0,$t0,%%lo(D_003BF140)\n"
        "\tlqc2 $vf5,0($t0)\n"
        "\tvmr32.w $vf6,$vf6\n"
        "\tvaddx.x $vf4,$vf0,$vf6x\n"
        "\tvmul.x $vf6,$vf6,$vf6\n"
        "\tvmulx.yzw $vf4,$vf4,$vf0x\n"
        "\tvmulw.xyzw $vf8,$vf5,$vf6w\n"
        "\tvsub.xyzw $vf5,$vf0,$vf0\n"
        "\tvmulx.xyzw $vf8,$vf8,$vf6x\n"
        "\tvmulx.xyz $vf8,$vf8,$vf6x\n"
        "\tvaddw.x $vf4,$vf4,$vf8w\n"
        "\tvmulx.xy $vf8,$vf8,$vf6x\n"
        "\tvaddz.x $vf4,$vf4,$vf8z\n"
        "\tvmulx.x $vf8,$vf8,$vf6x\n"
        "\tvaddy.x $vf4,$vf4,$vf8y\n"
        "\tvaddx.x $vf4,$vf4,$vf8x\n"
        "\tvaddx.xy $vf4,$vf5,$vf4x\n"
        "\tvmul.x $vf7,$vf4,$vf4\n"
        "\tvsubx.w $vf7,$vf0,$vf7x\n"
        "\tvsqrt $Q,$vf7w\n"
        "\tvwaitq\n"
        "\tvaddq.x $vf7,$vf0,$Q\n"
        "\tbnez $a3,3f\n"
        "\tvaddx.x $vf4,$vf5,$vf7x\n"
        "\tb 4f\n"
        "3:\n"
        "\tvsubx.x $vf4,$vf5,$vf7x\n"
        "4:\n"
        "\tvaddy.x $vf4,$vf5,$vf4y\n"
        "\tqmfc2.ni $t1,$vf4\n"
        "\tmtc1 $t1,%0\n"
        : "+f"(x) : : "$f0", "$7", "$8", "$9", "memory");
    return x;
}

// Acos: the two nops before sqrt.s are hazard padding inside the hand-written asm template.
float capVu0Atan2(float, float);
// FUNCTION: GAME 0x1F8140
float capVu0Acos(float x)
{
    float s = 1.0f - x * x;
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(s));
    return capVu0Atan2(s, x);
}

// Atan2: hand-written scalar plus VU0 asm with explicit hazard nops and delay slots (.set noreorder).
// FUNCTION: GAME 0x1F8180
float capVu0Atan2(float y, float x)
{
    register float r __asm__("$f0");
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t.set noat\n\t"
        "abs.s $f2,$f13\n\tlui $at,0x3727\n\tori $at,$at,0xC5AC\n\tmtc1 $at,$f1\n\tnop\n\t"
        "c.lt.s $f2,$f1\n\tnop\n\tbc1f 2f\n\tabs.s $f0,$f12\n\t"
        "c.lt.s $f0,$f1\n\tnop\n\tbc1f 1f\n\tnop\n\tmtc1 $zero,$f0\n\tjr $ra\n\tnop\n"
        "1:\n\tmtc1 $zero,$f1\n\tlui $at,0xBFC9\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\t"
        "c.lt.s $f12,$f1\n\tnop\n\tbc1t 9f\n\tnop\n\tlui $at,0x3FC9\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\tjr $ra\n\tnop\n"
        "2:\n\tc.lt.s $f0,$f1\n\tnop\n\tbc1f 3f\n\tlui $v0,%%hi(D_0042C350)\n\t"
        "mtc1 $zero,$f0\n\tnop\n\tc.lt.s $f13,$f0\n\tnop\n\tbc1f 9f\n\tnop\n\t"
        "c.lt.s $f12,$f0\n\tlui $at,0xC049\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\tbc1t 9f\n\tnop\n\t"
        "lui $at,0x4049\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\tjr $ra\n\tnop\n"
        "3:\n\taddiu $v0,$v0,%%lo(D_0042C350)\n\tmfc1 $t0,$f2\n\tmfc1 $t1,$f0\n\t"
        "lqc2 $vf4,0($v0)\n\tlqc2 $vf5,0x10($v0)\n\tlqc2 $vf6,0x20($v0)\n\t"
        "qmtc2.ni $t0,$vf7\n\tqmtc2.ni $t1,$vf8\n\tvadd.x $vf9,$vf7,$vf8\n\tvsub.x $vf8,$vf8,$vf7\n\t"
        "vdiv $Q,$vf8x,$vf9x\n\tvwaitq\n\tvaddq.x $vf7,$vf0,$Q\n\tvmul.x $vf8,$vf7,$vf7\n\t"
        "vmulax.x $ACC,$vf7,$vf4x\n\tvmul.x $vf7,$vf7,$vf8\n\tvmadday.x $ACC,$vf7,$vf4y\n\tvmul.x $vf7,$vf7,$vf8\n\t"
        "vmaddaz.x $ACC,$vf7,$vf4z\n\tvmul.x $vf7,$vf7,$vf8\n\tvmaddaw.x $ACC,$vf7,$vf4w\n\tvmul.x $vf7,$vf7,$vf8\n\t"
        "vmaddax.x $ACC,$vf7,$vf5x\n\tvmul.x $vf7,$vf7,$vf8\n\tvmadday.x $ACC,$vf7,$vf5y\n\tvmul.x $vf7,$vf7,$vf8\n\t"
        "vmaddaz.x $ACC,$vf7,$vf5z\n\tvmul.x $vf7,$vf7,$vf8\n\tvmaddaw.x $ACC,$vf7,$vf5w\n\tvmaddw.x $vf7,$vf6,$vf0w\n\t"
        "qmfc2.ni $t0,$vf7\n\tmtc1 $t0,$f1\n\tmtc1 $zero,$f0\n\tnop\n\t"
        "c.lt.s $f13,$f0\n\tnop\n\tbc1f 5f\n\tnop\n\tc.lt.s $f12,$f0\n\tnop\n\tbc1f 4f\n\tnop\n\t"
        "lui $at,0x4049\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\tb 6f\n\tsub.s $f1,$f1,$f0\n"
        "4:\n\tlui $at,0x4049\n\tori $at,$at,0x0FDB\n\tmtc1 $at,$f0\n\tb 6f\n\tsub.s $f1,$f0,$f1\n"
        "5:\n\tc.lt.s $f12,$f0\n\tnop\n\tbc1tl 6f\n\tneg.s $f1,$f1\n"
        "6:\n\tmov.s $f0,$f1\n9:\n\t.set pop"
        : "=f"(r) : "f"(y), "f"(x) : "$f1", "$f2", "$8", "$9", "$2", "memory");
    return r;
}

// FUNCTION: GAME 0x133948
extern "C" void func_00133948(void *, float *lo, float *hi) { vu0_MinMax(lo, hi); }
