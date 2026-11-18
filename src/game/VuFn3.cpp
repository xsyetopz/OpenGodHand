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

void MtxMultiply(cMatrix &, const cMatrix &, const cMatrix &);
struct ObjP { char p0[0x80]; cMatrix m80; float v[4]; };
// FUNCTION: GAME 0x1503B8
extern "C" void func_001503B8(ObjP *self, cMatrix *out)
{
    cMatrix m;
    IDENT(m.m);
    float x = self->v[0];
    float y = self->v[1];
    float z = self->v[2];
    m.m[12] = x;
    m.m[13] = y;
    m.m[14] = z;
    MtxMultiply(*out, self->m80, m);
}

extern "C" void *func_0028EB00(void *);
extern "C" char D_00448E20[], D_00448DB0[], D_00448CA0[], D_00448A00[];
struct ObjQ {
    char p0[0x214]; void *vt214; char p1[0x4AC - 0x218]; void *vt4AC; char p2[0x1540 - 0x4B0];
    Qv s1540; char p3[0x1561 - 0x1550]; unsigned char b1561; char p4[0x1570 - 0x1562];
    Qv s1570, s1580, s1590, s15A0; char p5[0x15E0 - 0x15B0]; Qv s15E0, s15F0;
};
// FUNCTION: GAME 0x289728
extern "C" ObjQ *func_00289728(ObjQ *self)
{
    func_0028EB00(self);
    self->vt214 = D_00448E20;
    unsigned char *c = (unsigned char *)self + 0x1530;
    SVZ(self->s1540);
    c[0x31] = 0xFF;
    SVZ(self->s1570); SVZ(self->s1580); SVZ(self->s1590);
    SVZ(self->s15E0);
    self->vt4AC = D_00448DB0;
    return self;
}

// FUNCTION: GAME 0x284A28
extern "C" ObjQ *func_00284A28(ObjQ *self)
{
    func_0028EB00(self);
    self->vt214 = D_00448CA0;
    unsigned char *c = (unsigned char *)self + 0x1530;
    SVZ(self->s1540);
    c[0x31] = 0xFF;
    SVZ(self->s1570); SVZ(self->s1580); SVZ(self->s1590); SVZ(self->s15A0);
    SVZ(self->s15F0);
    self->vt4AC = D_00448A00;
    return self;
}

extern "C" void func_001FCDB8(void *);
extern "C" char D_0042C4D8[], D_0042C4B8[];
struct ObjR { int w0; Qv s10, s20; char p0[0x3C - 0x30]; int w3C; char p1[0x49 - 0x40]; unsigned char b49; char p2[0x50 - 0x4A]; void *vt50; };
// FUNCTION: GAME 0x1FCE20
extern "C" ObjR *func_001FCE20(ObjR *self)
{
    self->vt50 = D_0042C4D8;
    self->w0 = 0;
    SVZ(self->s10); SVZ(self->s20);
    self->w3C = 0;
    self->vt50 = D_0042C4B8;
    self->b49 = 1;
    func_001FCDB8(self);
    return self;
}
