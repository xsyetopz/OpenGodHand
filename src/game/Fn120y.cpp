// Free units in 0x120000-0x130000.

extern "C" unsigned *SearchData__FPUiPCcUi(unsigned *, const char *, unsigned);
extern "C" void func_0012ECF0(void *);
extern unsigned *D_00747A4C;
extern char D_0041D418[], D_0041D420[];
struct F { unsigned *p; unsigned a[8]; char _p0[0x30-0x24]; float f30, f34, f38; char _p1[0x40-0x3C]; float f40, f44, f48; char _p2[0x50-0x4C]; float f50, f54, f58; char _p3[0x60-0x5C]; unsigned u60, u64, u68; };
// FUNCTION: GAME 0x12E670
extern "C" void func_0012E670(F *self) {
    if (self->p) return;
    unsigned *r = SearchData__FPUiPCcUi(D_00747A4C, D_0041D418, 0);
    if (!r) return;
    unsigned *s = SearchData__FPUiPCcUi(r, D_0041D420, 0);
    self->p = s;
    if (!s) return;
    self->p[0] = (unsigned)self->p + self->p[0]; self->p[1] = (unsigned)self->p + self->p[1]; self->p[2] = (unsigned)self->p + self->p[2]; self->p[3] = (unsigned)self->p + self->p[3]; self->p[4] = (unsigned)self->p + self->p[4]; self->p[5] = (unsigned)self->p + self->p[5]; self->p[6] = (unsigned)self->p + self->p[6]; self->p[7] = (unsigned)self->p + self->p[7]; 
    unsigned *d = self->p;
    self->a[0] = d[0]; self->a[1] = d[1]; self->a[2] = d[2]; self->a[3] = d[3];
    self->a[4] = d[4]; self->a[5] = d[5]; self->a[6] = d[6]; self->a[7] = d[7];
    self->u60 = *(unsigned short *)((char *)d + 0x60);
    self->u64 = *(unsigned short *)((char *)d + 0x62);
    self->u68 = *(unsigned short *)((char *)d + 0x64);
    self->f50 = *(float *)((char *)d + 0x48);
    self->f54 = *(float *)((char *)d + 0x4C);
    self->f58 = *(float *)((char *)d + 0x50);
    self->f30 = *(float *)((char *)d + 0x30);
    self->f34 = *(float *)((char *)d + 0x34);
    self->f38 = *(float *)((char *)d + 0x38);
    self->f40 = *(float *)((char *)d + 0x3C);
    self->f44 = *(float *)((char *)d + 0x40);
    self->f48 = *(float *)((char *)d + 0x44);
    func_0012ECF0(self);
}

extern "C" {
void *func_0030F550(int);
void *func_0012CF70(void *, int, int, int, int, float, float, int);
}
// FUNCTION: GAME 0x12E990
extern "C" void *func_0012E990(char *self, int a1, int a2, int a3, int a4, float f1, float f2, int a5)
{
    void *r;
    if (a1) {
        if (*(char **)(self + 0x190)) {
            char *n = *(char **)(self + 0x190);
            while (*(char **)n) n = *(char **)n;
            r = func_0012CF70(func_0030F550(0x100), a1, a2, a3, a4, f1, f2, a5);
            *(void **)n = r;
            if (r) {
                *(int *)(self + 0x194) += 1;
                return *(void **)n;
            }
        } else {
            r = func_0012CF70(func_0030F550(0x100), a1, a2, a3, a4, f1, f2, a5);
            *(void **)(self + 0x190) = r;
            if (r) {
                *(int *)(self + 0x194) += 1;
                return r;
            }
        }
    }
    return 0;
}

extern "C" {
void *func_0030F550(int);
void *func_0012D970(void *, int, int, int, int, int, int, int, int, int, int, int);
}
// FUNCTION: GAME 0x12EAD8
extern "C" void *func_0012EAD8(char *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    void *r;
    if (a1) {
        if (*(char **)(self + 0x190)) {
            char *n = *(char **)(self + 0x190);
            while (*(char **)n) n = *(char **)n;
            r = func_0012D970(func_0030F550(0x190), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
            *(void **)n = r;
            if (r) {
                *(int *)(self + 0x194) += 1;
                return *(void **)n;
            }
        } else {
            r = func_0012D970(func_0030F550(0x190), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
            *(void **)(self + 0x190) = r;
            if (r) {
                *(int *)(self + 0x194) += 1;
                return r;
            }
        }
    }
    return 0;
}

struct cVec { cVec(){} cVec(float a, float b, float c, float d = 1.0f) : x(a), y(b), z(c), w(d) {}
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w; };
struct Reg { char _p[8]; unsigned flags; };
extern Reg D_00747A2C;
extern char CamManager[];
extern char *pCamWork;
extern "C" char *Getplayer__Fv();
extern "C" int isCk_CamClass__11cCamManagerUi(void *, unsigned);
extern "C" void func_001325A0(void *, cVec *);
// FUNCTION: GAME 0x12E840
extern "C" void func_0012E840(char *self) {
    for (char *n = *(char **)(self + 0x190); n; n = *(char **)n) {
        char *vt = *(char **)(n + 0x5C);
        ((void (*)(char *))*(void **)(vt + 0x1C))(n + *(short *)(vt + 0x18));
    }
    if (D_00747A2C.flags & 0x8000000) {
        char *pl = Getplayer__Fv();
        cVec v(0.0f, 0.0f, 0.0f);
        if (isCk_CamClass__11cCamManagerUi(CamManager, 0x10)) {
            if (pCamWork) v = *(cVec *)(pCamWork + 0x200);
        } else if (pl) {
            v = **(cVec **)(pl + 0xF0);
        }
        func_001325A0(self, &v);
        for (char *n = *(char **)(self + 0x190); n; n = *(char **)n) {
            char *vt = *(char **)(n + 0x5C);
            ((void (*)(char *, int, int))*(void **)(vt + 0x14))(n + *(short *)(vt + 0x10), 0, 0);
        }
    }
}
