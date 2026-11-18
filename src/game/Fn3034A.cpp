// Deferred reset of an object after its countdown at 0x18A expires.
class cMatrix;
void MtxCopy(cMatrix &, const cMatrix &);
void func_00147C40(char *, float *);
void func_00147C88(void *, char *, int);
extern "C" {
void sceVu0ApplyMatrix(float *, const float *, const float *);
void func_002B62F8(float *, void *);
char *func_002B61B0(void *);
void func_002B6230(void *, float *);
void func_002B5F28(void *, const float *);
void func_002B5D58(void *, int);
}
struct O {
    char p0[0x104]; int w104; char *w108; char p10C[0xE]; /* 0x11A */ short pad; float f11C, f120, f124;
    char p128[0x62]; short h18A;
};

// FUNCTION: GAME 0x3034A8
extern "C" void func_003034A8(O *o)
{
    if (o->w104) {
        if (o->h18A >= 0) {
            o->h18A = o->h18A - 2;
            if (o->h18A <= 0) {
                struct F { float p[4]; float m[16]; float v[4]; float u[4]; } f;
                f.p[0] = o->f11C; f.p[1] = o->f120; f.p[2] = o->f124; f.p[3] = 1.0f;
                o->h18A = 0;
                MtxCopy(*(cMatrix *)f.m, *(cMatrix *)(o->w108 + 0x80));
                __asm__ volatile("sqc2 $vf0,0x50(%0)" : : "r"(&f) : "memory");
                func_00147C40((char *)f.m, f.v);
                sceVu0ApplyMatrix(f.p, f.m, f.p);
                o->f11C = f.p[0]; o->f120 = f.p[1]; o->f124 = f.p[2];
                func_002B62F8(f.v, o);
                __asm__ volatile("sqc2 $vf0,0x60(%0)" : : "r"(&f) : "memory");
                func_00147C88(f.u, func_002B61B0(o), 0);
                func_002B6230(o, f.v);
                func_002B5F28(o, f.u);
                func_002B5D58(o, 0);
                o->w104 = 0;
            }
        }
    }
}
