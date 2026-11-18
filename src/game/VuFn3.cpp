// VU0 macro-mode units, third batch (COP2 sequences in asm blocks, C control flow).
struct Qv { float f[4]; };
struct cMatrix { float m[16] __attribute__((aligned(16))); };
struct cVec { float v[4] __attribute__((aligned(16))); };
#define IDENT(p) __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\t" \
                                  "sqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(p) : "memory")
extern "C" void sceVu0RotMatrixY(float *, float *, float);
extern "C" void func_0030A650(float *, float *, float);

// FUNCTION: GAME 0x147988
void MtxInitRotY(cMatrix &m, float a)
{
    IDENT(m.m);
    sceVu0RotMatrixY(m.m, m.m, a);
}

// FUNCTION: GAME 0x1479C8
void MtxInitRotZ(cMatrix &m, float a)
{
    IDENT(m.m);
    func_0030A650(m.m, m.m, a);
}

// FUNCTION: GAME 0x147A08
void MtxInitScaleVec(cMatrix &m, const cVec &s)
{
    IDENT(m.m);
    m.m[0] = s.v[0];
    m.m[5] = s.v[1];
    m.m[10] = s.v[2];
}

extern "C" void *func_002FBCC8(void *);
extern "C" char D_0044E640[];
struct ObjN { char p0[0xF0]; void *vt; char p1[0x2F0 - 0xF4]; Qv s2F0, s300; char p2[0x370 - 0x310]; Qv s370, s380, s390; };
#define SVZ(f) __asm__ volatile("sqc2 $vf0,%0" : "=m"(f))
// FUNCTION: GAME 0x2FFB80
extern "C" ObjN *func_002FFB80(ObjN *self)
{
    if (self) {
        func_002FBCC8(self);
        self->vt = D_0044E640;
        SVZ(self->s2F0); SVZ(self->s300); SVZ(self->s370); SVZ(self->s380); SVZ(self->s390);
    }
    return self;
}
