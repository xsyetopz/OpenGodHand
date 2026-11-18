extern "C" void func_002BB2D8();

// FUNCTION: GAME 0x2BB298
extern "C" void func_002BB298(char *self, float *v)
{
    float *d = (float *)(self + 0x60);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
    func_002BB2D8();
}

extern char Dvd[];
extern "C" int func_002019F8(char *);
extern "C" void func_0031A808(char *);

// FUNCTION: GAME 0x2BE200
extern "C" void func_002BE200(char *self)
{
    if (!func_002019F8(Dvd)) func_0031A808(self);
}

extern "C" char func_002BE6A0(char *);

// FUNCTION: GAME 0x2BE630
extern "C" int func_002BE630(char *self, int a)
{
    *(int *)self = a;
    char r = func_002BE6A0(self);
    *(char *)(self + 4) = r;
    if (!(r & 0xFF)) *(int *)self = 0;
    return *(unsigned char *)(self + 4);
}

extern "C" void func_002BF3D0(char *);
extern "C" void func_002BF420(char *);

// FUNCTION: GAME 0x2BF388
extern "C" void func_002BF388(char *self)
{
    switch (*(signed char *)(self + 1)) {
    case 0: func_002BF3D0(self); break;
    case 1: func_002BF420(self); break;
    }
}

// Alias: the asm calls the mangled C++ symbol; the 5th arg (t0, byte at +0x15) is live in the original call but absent from the mangled signature.
extern "C" void func_002B64C0_mtx(char *, char *, char *, char *, int) __asm__("MtxInitCoord__FR7cMatrixRC4cVecN2");

// FUNCTION: GAME 0x2B64C0
extern "C" void func_002B64C0(char *self)
{
    if (*(unsigned char *)(self + 0x16)) return;
    func_002B64C0_mtx(self + 0x50, self + 0x40, self + 0x30, self + 0x20, *(unsigned char *)(self + 0x15));
    *(char *)(self + 0x16) = 1;
}

// FUNCTION: GAME 0x2BAAA8
extern "C" void func_002BAAA8(char *self, float *v)
{
    float *d = (float *)(self + 0x110);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

extern "C" void func_002BF4C8(char *);
extern "C" void func_002BF518(char *);

// FUNCTION: GAME 0x2BF478
extern "C" void func_002BF478(char *self)
{
    switch (*(signed char *)(self + 1)) {
    case 1: func_002BF4C8(self); break;
    case 2: func_002BF518(self); break;
    }
}

extern "C" void func_002BF708(char *);
extern "C" void func_002BF790(char *);
extern "C" void func_002C0A08(char *);
extern char *g_SaveManager;

// FUNCTION: GAME 0x2BF3D0
extern "C" void func_002BF3D0(char *self)
{
    func_002BF708(self);
    func_002BF790(self);
    func_002C0A08(g_SaveManager);
    char c = *self;
    *(char *)(self + 1) = 1;
    *self = c;
    *(char *)(self + 2) = 0;
    *(char *)(self + 3) = 0;
}

extern "C" void func_002C09E8(char *);

// FUNCTION: GAME 0x2BF4C8
extern "C" void func_002BF4C8(char *self)
{
    func_002BF708(self);
    func_002BF790(self);
    func_002C09E8(g_SaveManager);
    char c = *self;
    *(char *)(self + 1) = 2;
    *self = c;
    *(char *)(self + 2) = 0;
    *(char *)(self + 3) = 0;
}

extern "C" void func_002B6400(char *);

// FUNCTION: GAME 0x2B61D8
extern "C" void setLocalScale__5cNodeRC4cVec(char *self, float *v)
{
    func_002B6400(self);
    float *d = (float *)(self + 0x20);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
}

// FUNCTION: GAME 0x2B6230
extern "C" void func_002B6230(char *self, float *v)
{
    func_002B6400(self);
    float *d = (float *)(self + 0x30);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
}

// FUNCTION: GAME 0x2B6288
extern "C" void setLocalTranslation__5cNodeRC4cVec(char *self, float *v)
{
    func_002B6400(self);
    float *d = (float *)(self + 0x40);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
}

extern int D_00747A2C[];
extern "C" void setCheckPoint__12cSaveManagerbPC4cVecT2(char *, int, int, int);

// FUNCTION: GAME 0x2BF8F8
extern "C" void func_002BF8F8(char *self)
{
    if (!(D_00747A2C[2] & 0x800) && !(D_00747A2C[-2] & 0x8000000))
        setCheckPoint__12cSaveManagerbPC4cVecT2(self, 0, 0, 0);
}

extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x2BF878
extern "C" void func_002BF878(char *self)
{
    memset(self, 0, 0x14A0);
    memset(self + 0x14A0, 0, 0x9C30);
    memset(self + 0xB0D0, 0, 0x20);
}

extern "C" int func_002AF218(int);
extern "C" int getCodeSize__11cMessCommonUs(unsigned short);

// FUNCTION: GAME 0x2B4768
extern "C" void func_002B4768(void *, int *a, int *b)
{
    int *s1 = a;
    int *s0 = b;
    *s1 += func_002AF218(*s0);
    *s0 += getCodeSize__11cMessCommonUs(*(unsigned short *)*s0) * 2;
}

extern "C" void func_002B5D58(char *, int);
extern "C" void func_002B5EC0(char *);

// FUNCTION: GAME 0x2B5CF0
extern "C" void func_002B5CF0(char *self, int a)
{
    while (*(char **)(self + 8)) func_002B5D58(*(char **)(self + 8), a);
    *(int *)(self + 8) = 0;
    func_002B5EC0(self);
}

extern "C" int func_002B4690(char *, int);
extern "C" void func_002B22E0(char *, int);

// FUNCTION: GAME 0x2B2A88
extern "C" void func_002B2A88(char *self)
{
    int r = func_002B4690(self, *(int *)(self + 0x8C) + 2);
    func_002B22E0(self, r);
    char *o = *(char **)(self + 0x18);
    *(char *)(self + 0x3C) = 0;
    if (o && *(unsigned short *)(o + 0x2FE) == 0x102) *(char *)(self + 0xA4) = 1;
}

extern "C" void func_002BA250(char *);
extern "C" void func_002B8AA8(char *);
extern "C" void func_002B8F48(char *);

// FUNCTION: GAME 0x2B9D58
extern "C" void func_002B9D58(char *self)
{
    func_002BA250(self);
    for (char *p = *(char **)(self + 0x10); p; p = *(char **)(p + 4)) func_002B8AA8(p);
    func_002B8F48(self);
}

// FUNCTION: GAME 0x2BA5E8
extern "C" void func_002BA5E8(char *self, float f)
{
    *(float *)(self + 0x114) = f;
    float g = *(float *)(self + 0x110);
    if (g < f + f) *(float *)(self + 0x114) = g * 0.5f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

// FUNCTION: GAME 0x2BA650
extern "C" void func_002BA650(char *self, float f)
{
    *(float *)(self + 0x110) = f;
    float g = *(float *)(self + 0x114);
    if (f < g + g) *(float *)(self + 0x114) = f * 0.5f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

// DRAFT: GAME 0x2BA7B8
// diff: 4 words, vtable fn pointer loaded into v0 instead of v1 (two forms tried)
#ifdef NONMATCHING
extern "C" void func_002BA7B8(char *self)
{
    char *vt = *(char **)(self + 0x100);
    int o1 = *(short *)(vt + 0x20);
    float (*f1)(char *) = (float (*)(char *))*(void **)(vt + 0x24);
    float a = f1(self + o1);
    vt = *(char **)(self + 0x100);
    int o2 = *(short *)(vt + 0x10);
    float (*f2)(char *) = (float (*)(char *))*(void **)(vt + 0x14);
    float b = f2(self + o2);
    *(float *)(self + 0xE4) = a + b;
}
#endif

extern "C" void func_002BE550(char *);
extern char RelSys[];

// FUNCTION: GAME 0x2BE8E8
extern "C" void func_002BE8E8(int a, int b)
{
    if (b == 0xFFFF && a) {
        char *p = RelSys;
        int n = 2;
        do {
            func_002BE550(p);
            n--;
            p += 8;
        } while (n != -1);
    }
}

extern "C" unsigned func_002BEDD8(char *);

// FUNCTION: GAME 0x2BEF08
extern "C" char *func_002BEF08(char *self, unsigned i)
{
    if (i < func_002BEDD8(self)) return *(char **)self + (i * 0x18 + 0xC);
    return 0;
}

extern "C" void EmClothInit__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(int, char *, char *, char *);
extern "C" void func_002DF938(char *, char *);

// FUNCTION: GAME 0x2B8508
extern "C" void SetPendulum__10cObjSimple6eObjIdP4cObj(char *self, int id, char *o)
{
    char *c = self + 0x2F20;
    *(int *)(self + 0x1394) = id;
    *(char *)(self + 0x1390) = 1;
    EmClothInit__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(id, self, self + 0x13A0, c);
    if (o) func_002DF938(o, c);
}
