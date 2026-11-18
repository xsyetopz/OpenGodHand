// Free units in 0x13A000-0x140000 (camera follow step).

struct Q4 { float v[4] __attribute__((aligned(16))); };
class cVec { public:
    cVec() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q4 *)this)); }
    cVec(float a, float b, float c, float d = 1.0f) : x(a), y(b), z(c), w(d) {}
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w; };
struct cMat { float m[16]; };
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(cMat *, const cVec *, unsigned char);
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);
extern "C" void *Getplayer__Fv();
struct Tgt { char _p0[0xF0]; cVec *pos; };
class cCam {
public:
    char _p0[0x200]; cVec v200, v210; char _p1[0x3D0 - 0x220]; cVec v3D0; char _p2[0x470 - 0x3E0]; Tgt *m470;
    char _p3[0x480 - 0x474]; float m480[4]; char _p4[0x4F0 - 0x490]; int m4F0; char _p5[0x500 - 0x4F4]; cVec v500;
    char _p6[0x528 - 0x510]; int m528, m52C;
};
// FUNCTION: GAME 0x13B450
extern "C" void func_0013B450(cCam *self) {
    if (Getplayer__Fv()) {
        self->v500 = *self->m470->pos;
        cMat m;
        cVec t;
        MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, (cVec *)((char *)self->m470 + 0x100), 0);
        m.m[12] = self->m470->pos->x;
        m.m[13] = self->m470->pos->y;
        m.m[14] = self->m470->pos->z;
        sceVu0ApplyMatrix(&t.x, m.m, self->m480);
        float dx = t.x - self->v210.x, dy = t.y - self->v210.y, dz = t.z - self->v210.z;
        self->v210.x += dx * 0.25f;
        self->v210.y += dy * 0.25f;
        self->v210.z += dz * 0.25f;
        MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, (cVec *)((char *)self->m470 + 0x100), 0);
        self->v200.x = m.m[8] + self->v210.x;
        self->v200.y = m.m[9] + self->v210.y;
        self->v200.z = m.m[10] + self->v210.z;
        self->v3D0 = cVec(0.0f, 1.0f, 0.0f);
        if (self->m52C) self->m52C--;
        else { self->m528 &= ~1; self->m4F0 = 1; }
    }
}
