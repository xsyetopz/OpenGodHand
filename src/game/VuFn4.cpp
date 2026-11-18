// VU0 macro-mode units, fourth batch (COP2 sequences in asm blocks, C control flow).
struct Qv { float f[4]; };
struct Sv {
    float v[4] __attribute__((aligned(16)));
    Sv() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)v)); }
    Sv &operator=(const float *o)
    {
        if (v != o) { v[0] = o[0]; v[1] = o[1]; v[2] = o[2]; }
        return *this;
    }
};
struct Sv16 { float v[4] __attribute__((aligned(16))); };
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

struct VtJ { char p[0x30]; short off; short pad; void (*fn)(float *, void *); };
struct ObjM { char p0[0x70]; float *mtx; char p1[0x100 - 0x74]; VtJ *vt; char p2[0x120 - 0x104]; Sv v120; };
// FUNCTION: GAME 0x2BABD0
extern "C" void func_002BABD0(ObjM *self)
{
    Sv16 b;
    Sv16 a;
    Sv16 t;
    self->vt->fn(a.v, (char *)self + self->vt->off);
    float *tp = t.v;
    float *mt = self->mtx;
    b.v[0] = 0.0f;
    b.v[1] = a.v[1] * 0.5f;
    b.v[2] = 0.0f;
    b.v[3] = 1.0f;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(b.v));
    sceVu0ApplyMatrix(tp, mt, tp);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)a.v) : "r"(tp));
    self->v120 = a.v;
}

extern "C" int func_001573C8(float *, float *, float *, float *, float *);
// FUNCTION: GAME 0x1F8488
extern "C" int func_001F8488(float *o, float *p)
{
    Sv m0, m1, m2, m3;
    float y = o[1];
    float py = p[1];
    float top = y + o[2];
    if (!(py < y)) {
        if (!(top < py)) {
            m0.v[0] = o[4]; m0.v[1] = 0.0f; m0.v[2] = o[5];
            m1.v[0] = o[6]; m1.v[1] = 0.0f; m1.v[2] = o[7];
            m2.v[0] = o[8]; m2.v[1] = 0.0f; m2.v[2] = o[9];
            m3.v[0] = o[10]; m3.v[1] = 0.0f; m3.v[2] = o[11];
            return func_001573C8(p, m0.v, m1.v, m2.v, m3.v) != 0;
        }
    }
    return 0;
}

extern "C" void *func_001B6E90(void *);
extern "C" char D_0042AA98[];
struct Qa { float f[4] __attribute__((aligned(16))); };
struct ObjS { char p0[0x214]; void *vt; char p1[0x610 - 0x218]; Qa s610, s620; char p2[0x640 - 0x630]; Qa s640; char p3[0x6A0 - 0x650]; Qa s6A0; Qa arr[14]; };
#define QZ(f) __asm__ volatile("sqc2 $vf0,%0" : "=m"(f))
// FUNCTION: GAME 0x1C9140
extern "C" ObjS *func_001C9140(ObjS *self)
{
    func_001B6E90(self);
    self->vt = D_0042AA98;
    QZ(self->s610); QZ(self->s620); QZ(self->s640); QZ(self->s6A0);
    Qa *p = self->arr;
    int i = 6;
    do {
        QZ(p[0]); QZ(p[1]);
        p += 2;
    } while (--i != -1);
    return self;
}

extern "C" char D_00429B88[], D_004298B0[];
struct ObjT { char p0[0x214]; void *vt; char p1[0x4AC - 0x218]; void *vt4AC; char p2[0x610 - 0x4B0]; Qa s610; char p3[0x640 - 0x620]; Qa s640, s650; char p4[0x662 - 0x660]; short h662; char p5[0x668 - 0x664]; long d668; char p6[0x676 - 0x670]; char b676, b677; char p7[0x680 - 0x678]; int w680; };
// FUNCTION: GAME 0x1C0068
extern "C" ObjT *func_001C0068(ObjT *self)
{
    func_001B6E90(self);
    self->vt = D_00429B88;
    QZ(self->s610); QZ(self->s640); QZ(self->s650);
    self->b677 = 0;
    self->vt4AC = D_004298B0;
    self->h662 = 0;
    self->b676 = 0;
    self->d668 = 0;
    self->w680 = 0;
    return self;
}

extern "C" void func_001FCDE8(void *);
extern "C" char D_0042C4D8[], D_0042C498[];
struct ObjU { int w0; char pz[0xC]; Qa s10, s20; char p0[0x3C - 0x30]; int w3C; char p1[0x49 - 0x40]; unsigned char b49; char p2[0x50 - 0x4A]; void *vt50; char p3[0x60 - 0x54]; int w60; };
// FUNCTION: GAME 0x1FD3B8
extern "C" ObjU *func_001FD3B8(ObjU *self)
{
    self->vt50 = D_0042C4D8;
    self->w0 = 0;
    QZ(self->s10); QZ(self->s20);
    self->w3C = 0;
    self->w60 = 0;
    self->vt50 = D_0042C498;
    self->b49 = 2;
    func_001FCDE8(self);
    return self;
}

extern "C" void *__8cGameObj(void *);
extern "C" char D_0044A660[], D_0044A630[];
struct ObjV { char p0[0x2AE]; short h2AE; char p1[0x4AC - 0x2B0]; void *vt4AC; char p2[0x5C0 - 0x4B0]; Qa a5C0[2]; char p3[0x610 - 0x5E0]; int w610; char p4[0x62E - 0x614]; short h62E; char p5[0x644 - 0x630]; int w644; char p6[0x650 - 0x648]; Qa s650; };
// FUNCTION: GAME 0x28EB00
extern "C" ObjV *func_0028EB00(ObjV *self)
{
    __8cGameObj(self);
    *(void **)((char *)self + 0x214) = D_0044A660;
    Qa *p = self->a5C0;
    int i = 1;
    do {
        QZ(p[0]);
        p++;
    } while (--i != -1);
    self->w610 = 0;
    QZ(self->s650);
    self->vt4AC = D_0044A630;
    self->h2AE = 0x258;
    self->w610 = 0;
    self->h62E = 0;
    self->w644 = 0;
    return self;
}
