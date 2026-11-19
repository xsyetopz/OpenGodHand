// Table fill at D_00585040 and reset of D_005850B0, gated on arg1 == 0xFFFF and a non-null arg0.

struct TblEnt {
    float a;
    int b;
    float c;
    float d;
};

struct TblHead {
    int u0;
    int u4;
    int u8;
    float uC;
};

extern "C" TblEnt D_00585040[7];
extern "C" TblHead D_005850B0;

static inline float f32(unsigned int u)
{
    union { unsigned int u; float f; } x;
    x.u = u;
    return x.f;
}

// FUNCTION: GAME 0x276618
extern "C" void func_00276618(void *p, int n)
{
    if (n != 0xFFFF || p == 0) {
        return;
    }
    TblEnt *e = D_00585040;
    TblHead *h = &D_005850B0;
    e->a = f32(0xBF941893);
    e->c = f32(0xC1A80000);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xBDF7CED9);
    e->c = f32(0xC06F5C29);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xC0865E35);
    e->c = f32(0xC12B3F7D);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xC09AB021);
    e->c = f32(0xC1287AE1);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xBF716873);
    e->c = f32(0xC216FCEE);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xC0BF5C29);
    e->c = f32(0xC2006042);
    e->b = 0;
    e->d = 1.0f;
    e++;
    e->a = f32(0xC09EF9DB);
    e->c = f32(0xC1FF126F);
    e->b = 0;
    e->d = 1.0f;
    h->u0 = 0;
    h->u4 = 0;
    h->u8 = 0;
    h->uC = 1.0f;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x288660
// 46 differing words. Argument lives in $s2 here but $s0 in the original, and case-1 dispatch uses beq where the original uses beql. Variants with a local self copy and reversed r==0 branch sense were 47 and pending.
#define FLD(T, p, off) (*(T *)((char *)(p) + (off)))
extern char Snd[];
extern "C" int irand__Fv(void);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void SetTgtTurn__8cGameObjRC4cVecf(void *, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void calcNullPart__6cModel(void *);
extern "C" void Add_nullspeed__FP8cObjBase(void *);

extern "C" void func_00288660(void *arg0)
{
    switch (FLD(unsigned char, arg0, 0x2F6)) {
    case 0: {
        int r = irand__Fv() & 1;
        char *t = FLD(char *, arg0, 0x304);
        int a;
        int b;
        if (r) {
            a = FLD(int, t, 0x50);
            b = FLD(int, t, 0x54);
        } else {
            a = FLD(int, t, 0x58);
            b = FLD(int, t, 0x5C);
        }
        int s2 = a + (int)t;
        int s1 = b + (int)t;
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5C, arg0, 0, 0, 0, 0);
        func_002A8578(arg0, s2, s1, 5, 0, 0, 0.0f);
        FLD(int, arg0, 0x5F0) = 0xA;
        FLD(unsigned char, arg0, 0x2F6) = (unsigned char)(FLD(unsigned char, arg0, 0x2F6) + 1);
    }
    /* fallthrough */
    case 1: {
        int n = FLD(int, arg0, 0x5F0);
        if (n != 0) {
            FLD(int, arg0, 0x5F0) = n - 1;
            char *m = FLD(char *, FLD(char *, arg0, 0x670), 0x34);
            if (m != 0) {
                SetTgtTurn__8cGameObjRC4cVecf(arg0, FLD(int, m, 0xF0), FLD(float, arg0, 0x5A8) * f32(0x3EC90FDB));
            }
        }
        if (moveMotion__FP8cObjBase(arg0) != 0) {
            if (FLD(int, arg0, 0x15B0) & 0x80) {
                FLD(unsigned char, arg0, 0x2F5) = 7;
                FLD(unsigned char, arg0, 0x2F6) = 0x10;
                FLD(unsigned char, arg0, 0x2F7) = 0;
                FLD(unsigned char, arg0, 0x2F4) = 0;
                return;
            }
            FLD(unsigned char, arg0, 0x2F4) = 0;
            FLD(unsigned char, arg0, 0x2F5) = 4;
            FLD(unsigned char, arg0, 0x2F6) = 0;
            FLD(unsigned char, arg0, 0x2F7) = 0;
        }
        calcNullPart__6cModel(arg0);
        Add_nullspeed__FP8cObjBase(arg0);
        return;
    }
    }
}
#endif
