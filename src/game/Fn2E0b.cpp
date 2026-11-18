// Unnamed units in 0x2E0000-0x2EFFFF: ground-probe ChkLine callers, Hermite blend, spline sampling.
#include "game/Fn2E0.h"

#ifdef NONMATCHING
// DRAFT: GAME 0x2E7E10
// diff: 12 words; float load/store order of the t vector (z loaded first, w stored before z in original) and 2nd-branch copy load order.
struct cMatrix { float m[16]; };
extern char World_light_work[];
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" float Adjust_theta__Ff(float);
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(cMatrix &, const cVec &, unsigned char);
extern "C" void setLocalTranslation__5cNodeRC4cVec(void *, const cVec &);
extern "C" char *Get_LightData2__11cWorldLightUsUi(void *, unsigned short, unsigned);
extern "C" void Del_LightData__11cWorldLightUsUi(void *, unsigned short, unsigned);
extern "C" void Set_LightData__11cWorldLightP14LIGHT_DATA_TBL(void *, void *);
extern "C" void func_002E7E10(char *self)
{
    cVec v, u, t, r;
    func_002FBED0(self);
    if (*(unsigned char *)(self + 0x2CA)) {
        CP(&v, self + 0x2F0);
        char *l = Get_LightData2__11cWorldLightUsUi(World_light_work, *(unsigned short *)(self + 0x2B2), *(unsigned *)(self + 0x2B4));
        if (l) {
            cMatrix *m = (cMatrix *)(self + 0x310);
            *(float *)(self + 0x304) = Adjust_theta__Ff(*(float *)(self + 0x304) + (float)*(unsigned char *)(self + 0x2CC) * 0.017453292f);
            MtxInitRotVec__FR7cMatrixRC4cVecUc(*m, *(cVec *)(self + 0x300), 0);
            sceVu0ApplyMatrix((float *)&v, m->m, (float *)&v);
            cVec *rp = &r;
            char *o = *(char **)(self + 0x350);
            float *tp = (float *)&t; tp[0] = *(float *)(o + 0xB0); tp[1] = *(float *)(o + 0xB4); tp[2] = *(float *)(o + 0xB8); tp[3] = 1.0f;
            CP(&r, tp);
            __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,%2\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)&r) : "m"(*(Qv *)&r), "m"(*(Qv *)&v));
            CP(&u, rp);
            cVec *d = (cVec *)(l + 0x10);
            if (d != &u) { d->x = u.x; d->y = u.y; d->z = u.z; }
            setLocalTranslation__5cNodeRC4cVec(self, v);
        }
    } else if (*(unsigned char *)(self + 0x2CD)) {
        func_002B6160(&v, self);
        cVec *d = (cVec *)(self + 0x370);
        if (d != &v) { d->x = v.x; d->y = v.y; d->z = v.z; }
        Del_LightData__11cWorldLightUsUi(World_light_work, *(unsigned short *)(self + 0x2B2), *(unsigned *)(self + 0x2B4));
        Set_LightData__11cWorldLightP14LIGHT_DATA_TBL(World_light_work, self + 0x360);
    }
}
#endif
