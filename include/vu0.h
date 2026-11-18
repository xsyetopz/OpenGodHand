#ifndef VU0_H
#define VU0_H

// VU0 macro-mode helpers. Each one is a single asm block: the original code keeps the whole
// vector run contiguous, and ee-gcc does not move other instructions into it.
// Operands: d = destination, a/b = sources, all 16-byte vectors (xyzw floats).


// d.xyz = a.xyz + b.xyz (w of d is untouched)
inline void vu0_AddVectorXYZ(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

// x*x + y*y + z*z
inline float vu0_LengthSq(const float *v)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tvmul.xyz $vf4,$vf4,$vf4\n\tvaddy.x $vf4,$vf4,$vf4y\n\tvaddz.x $vf4,$vf4,$vf4z\n\tqmfc2.ni %0,$vf4" : "=r"(r) : "r"(v) : "memory");
    return r;
}

// sqrt(x*x + y*y + z*z)
inline float vu0_Length(const float *v)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tvmul.xyz $vf4,$vf4,$vf4\n\tvaddy.x $vf4,$vf4,$vf4y\n\tvaddz.x $vf4,$vf4,$vf4z\n\tvsqrt $Q,$vf4x\n\tvwaitq\n\tvaddq.x $vf4,$vf0,$Q\n\tqmfc2.ni %0,$vf4" : "=r"(r) : "r"(v) : "memory");
    return r;
}

// |a - b| over xyz
inline float vu0_LengthAB(const float *a, const float *b)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tvmul.xyz $vf4,$vf4,$vf4\n\tvaddy.x $vf4,$vf4,$vf4y\n\tvaddz.x $vf4,$vf4,$vf4z\n\tvsqrt $Q,$vf4x\n\tvwaitq\n\tvaddq.x $vf4,$vf0,$Q\n\tqmfc2.ni %0,$vf4" : "=r"(r) : "r"(a), "r"(b) : "memory");
    return r;
}

// |a - b| over x and z
inline float vu0_MagnitudeXZ(const float *a, const float *b)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xz $vf4,$vf4,$vf5\n\tvmul.xz $vf4,$vf4,$vf4\n\tvaddz.x $vf4,$vf4,$vf4z\n\tvsqrt $Q,$vf4x\n\tvwaitq\n\tvaddq.x $vf4,$vf0,$Q\n\tqmfc2.ni %0,$vf4" : "=r"(r) : "r"(a), "r"(b) : "memory");
    return r;
}

// (a.x-b.x)^2 + (a.z-b.z)^2
inline float vu0_MagnitudeSqXZ(const float *a, const float *b)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xz $vf4,$vf4,$vf5\n\tvmul.xz $vf4,$vf4,$vf4\n\tvaddz.x $vf4,$vf4,$vf4z\n\tqmfc2.ni %0,$vf4" : "=r"(r) : "r"(a), "r"(b) : "memory");
    return r;
}

// d = m * v for a 3-row matrix m (rows at +0x00/+0x10/+0x20), xyz result
inline void vu0_ApplyMatrixXYZ(float *d, const float (*m)[4], const float *v)
{
    __asm__ volatile("lqc2 $vf4,0(%2)\n\tlqc2 $vf5,0(%1)\n\tlqc2 $vf6,0x10(%1)\n\tlqc2 $vf7,0x20(%1)\n\tvmulax.xyzw $ACC,$vf5,$vf4x\n\tvmadday.xyzw $ACC,$vf6,$vf4y\n\tvmaddz.xyzw $vf8,$vf7,$vf4z\n\tsqc2 $vf8,0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}

// d = a * b over xyzw
inline void vu0_MulVector(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvmul.xyzw $vf6,$vf4,$vf5\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

// d = (int)(a * 16) per lane (float to fixed point, 4 fraction bits)
inline void vu0_FtoI4(float *d, const float *a)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tvftoi4.xyzw $vf5,$vf4\n\tsqc2 $vf5,0(%0)" : : "r"(d), "r"(a) : "memory");
}

// d.xyz = a.xyz * s (w of d is taken from a)
inline void vu0_ScaleXYZ(float *d, const float *a, float s)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tmfc1 $t0,%2\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}

// lo = min(lo, hi), hi = max(lo, hi) per lane
inline void vu0_MinMax(float *lo, float *hi)
{
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvmini.xyzw $vf6,$vf4,$vf5\n\tvmax.xyzw $vf7,$vf4,$vf5\n\tsqc2 $vf6,0(%0)\n\tsqc2 $vf7,0(%1)" : : "r"(lo), "r"(hi) : "memory");
}

#endif
