struct Qv2 { float f[4]; };
extern "C" void func_0030ABA0(Qv2 *, Qv2 *, float);
extern "C" void sceVu0AddVector(Qv2 *, Qv2 *, Qv2 *);

// FUNCTION: GAME 0x2D4EF8
extern "C" void getPoint__7cSplineR4cVecf(char *self, Qv2 *out, float t)
{
    Qv2 tmp;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(tmp));
    Qv2 *p = (Qv2 *)(self + 0x30);
    if (out != p) {
        out->f[0] = p->f[0];
        out->f[1] = p->f[1];
        out->f[2] = p->f[2];
    }
    func_0030ABA0(&tmp, out, t);
    sceVu0AddVector(out, &tmp, (Qv2 *)(self + 0x20));
    func_0030ABA0(&tmp, out, t);
    sceVu0AddVector(out, &tmp, (Qv2 *)(self + 0x10));
    func_0030ABA0(&tmp, out, t);
    sceVu0AddVector(out, &tmp, (Qv2 *)self);
    out->f[3] = 1.0f;
}
