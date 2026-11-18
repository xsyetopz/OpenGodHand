#ifndef CVECOP_H
#define CVECOP_H

// Inlined cVec operations as the game compiled them, one asm block per operation.
// Every vector is 16 bytes (xyzw floats); operands are memory so the compiler keeps the
// surrounding scalar code in its original order. Sequences use $vf4/$vf5 and $8 ($t0).
//
//   cvecop_Zero(d)       sqc2 $vf0,d                      (vf0 = 0,0,0,1)
//   cvecop_Copy(d,s)     lqc2 $vf4,s ; sqc2 $vf4,d
//   cvecop_CopyR(d,s)    cvecop_Copy with the source address forced into a register
//   cvecop_Sub(d,a,b)    lqc2 $vf4,a ; lqc2 $vf5,b ; vsub.xyz $vf4,$vf4,$vf5 ; sqc2 $vf4,d
//   cvecop_SubR(d,a,b)   cvecop_Sub with both source addresses forced into registers
//   cvecop_Add(d,a,b)    same with vadd.xyz
//   cvecop_Scale(d,f)    lqc2 $vf4,d ; mfc1 $8,f ; qmtc2.ni $8,$vf5 ; vmulx.xyz $vf4,$vf4,$vf5x ; sqc2 $vf4,d

struct CvQ {
    float v[4];
};

static inline void cvecop_Zero(float *d)
{
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(CvQ *)d));
}

static inline void cvecop_Copy(float *d, const float *s)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "m"(*(const CvQ *)s));
}

// Source held in a register: the address stays in a register across the block (0(reg)).
static inline void cvecop_CopyR(float *d, const float *s)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "r"(s));
}

static inline void cvecop_Sub(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,%2\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "m"(*(const CvQ *)a), "m"(*(const CvQ *)b));
}

// Both sources held in registers (0(reg)): the addresses stay live across calls.
static inline void cvecop_SubR(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "r"(a), "r"(b));
}

static inline void cvecop_Add(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,%2\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "m"(*(const CvQ *)a), "m"(*(const CvQ *)b));
}

static inline void cvecop_Scale(float *d, float f)
{
    __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $8,%1\n\tqmtc2.ni $8,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(CvQ *)d) : "f"(f) : "$8");
}

#endif
