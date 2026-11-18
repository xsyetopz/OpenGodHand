// Free units in 0x13A000-0x140000 (player camera update).

struct Q4 { float v[4] __attribute__((aligned(16))); };
class cVec { public:
    cVec() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q4 *)this)); }
    cVec(float a, float b, float c, float d = 1.0f) : x(a), y(b), z(c), w(d) {}
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w; };
struct cMat { float m[16]; };
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(cMat *, const cVec *, unsigned char);
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);
extern "C" void Adjust_theta_vec__FPf(float *);
extern char *pCamWork;
struct Tgt { char _p0[0xF0]; cVec *pos; char _p1[0x100 - 0xF4]; cVec rot; };
class cPlCam {
public:
    char _p0[0x200]; cVec v200, v210; float f220[4]; char _p1[0x250 - 0x230]; float f250;
    char _p2[0x3D0 - 0x254]; cVec v3D0; char _p3[0x3F0 - 0x3E0]; Tgt *m3F0; char _p4[0x400 - 0x3F4]; float m400[4]; cVec v410;
    float f420; char _p5[0x51C - 0x424]; int m51C;
};
// FUNCTION: GAME 0x13B9B8
extern "C" void setCamUpdate__9cPlCameraUi(cPlCam *self, unsigned a) {
    if (pCamWork) {
        *(int *)((char *)self + 0x51C) = 0;
        float f;
        if (a) {
            self->v210 = *(cVec *)(pCamWork + 0x210);
            self->v200 = *(cVec *)(pCamWork + 0x200);
            f = *(float *)(pCamWork + 0x250);
        } else {
            cMat m;
            cVec t0;
            MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, &self->m3F0->rot, 0);
            m.m[12] = self->m3F0->pos->x;
            m.m[13] = self->m3F0->pos->y;
            m.m[14] = self->m3F0->pos->z;
            sceVu0ApplyMatrix(&t0.x, m.m, self->m400);
            self->v200 = t0;
            cVec u, w;
            cVec x(self->m3F0->rot.x + self->v410.x, self->m3F0->rot.y + self->v410.y, self->m3F0->rot.z);
            Adjust_theta_vec__FPf(&x.x);
            MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, &x, 0);
            m.m[12] = t0.x; m.m[13] = t0.y; m.m[14] = t0.z;
            w.x = 0.0f; w.y = 0.0f; w.z = -self->f420;
            sceVu0ApplyMatrix(&u.x, m.m, &w.x);
            self->v210 = u;
            self->v3D0 = cVec(0.0f, 1.0f, 0.0f);
            f = 31.0f;
        }
        self->f250 = f;
    }
}
