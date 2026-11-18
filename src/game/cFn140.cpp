// Small units of 0x140000-0x14FFFF.
class cMatrix {};

extern "C" {
void func_00141AC8(int a, int b);
void func_00149550(int a, int b);
void func_0030A548(void *dst, const void *src);
void sceVu0MulMatrix(void *dst, const void *a, const void *b);

// FUNCTION: GAME 0x1415E0
void func_001415E0() {}

// FUNCTION: GAME 0x141620
void func_00141620() {}

// FUNCTION: GAME 0x146F90
void func_00146F90() {}

// FUNCTION: GAME 0x141AF8
void func_00141AF8() { func_00141AC8(1, 0xFFFF); }

// FUNCTION: GAME 0x149580
void func_00149580() { func_00149550(1, 0xFFFF); }

// FUNCTION: GAME 0x146F70
void func_00146F70(unsigned char *p)
{
    if (p[0x90])
        p[0x78] = 0;
    else
        p[0x78] = 1;
    p[0x90] = 0;
}

// FUNCTION: GAME 0x147C40
void func_00147C40(char *a, float *b)
{
    *(float *)(a + 0x30) = b[0];
    *(float *)(a + 0x34) = b[1];
    *(float *)(a + 0x38) = b[2];
}

// FUNCTION: GAME 0x14FF60
void func_0014FF60(char *a, int *b)
{
    long v = ((long)*b << 32) | 0x20000000;
    *(long *)(a + 0x18) = 0;
    *(long *)(a + 0x10) = v;
}
}

// FUNCTION: GAME 0x147528
void MtxCopy(cMatrix &dst, const cMatrix &src) { func_0030A548(&dst, &src); }

// FUNCTION: GAME 0x147548
void MtxMultiply(cMatrix &dst, const cMatrix &a, const cMatrix &b) { sceVu0MulMatrix(&dst, &a, &b); }


extern "C" {
void func_00150710(float x, float y, float z);
void func_0013C5C8(void *self);
void func_00155AE8(int a, int b, int c);
void func_00149378(void *a);
void func_00149400(void *a, void *b);
void func_001494F8(void *a, void *b);
void func_001495A0(void *self);
void _$_4cObj(void *self);
extern char D_00466448[];
extern int D_007476B0;
extern long D_003BD718[];
extern const char D_0041EBE8[];
extern const char D_0041EAF0[];

// FUNCTION: GAME 0x147C60
void func_00147C60(void *, float *b) { func_00150710(b[12], b[13], b[14]); }

// FUNCTION: GAME 0x146EF0
void func_00146EF0(char *p)
{
    func_0013C5C8(p);
    p[0x90] = 0;
}

struct cFn140S147 {
    char pad[0xAC];
    unsigned short h;
    short q;
    void *p;
    int q2;
    char c;
};
// FUNCTION: GAME 0x147188
void func_00147188(cFn140S147 *s)
{
    if (s->p) {
        s->c = 0;
        s->p = 0;
        s->h = 0xFFFF;
    }
}

// FUNCTION: GAME 0x1492C8
void func_001492C8() { func_00149378(D_00466448); }

// FUNCTION: GAME 0x1492E8
void func_001492E8(void *a) { func_00149400(D_00466448, a); }

// FUNCTION: GAME 0x149350
void func_00149350(void *a) { func_001494F8(D_00466448, a); }

// FUNCTION: GAME 0x148F00
void func_00148F00(int a, int b) { func_00155AE8(a, b, D_007476B0 & 1); }

// FUNCTION: GAME 0x148F28
void func_00148F28(char *a, int i)
{
    *(long *)(a + 0x50) = D_003BD718[i];
    *(long *)(a + 0x100) = D_003BD718[i];
}

// FUNCTION: GAME 0x14EA28
void _$_8cObjBase(char *p)
{
    *(const void **)(p + 0x214) = D_0041EBE8;
    _$_4cObj(p);
}

// FUNCTION: GAME 0x14E598
void *__4cObj(char *p)
{
    func_001495A0(p);
    *(const void **)(p + 0x214) = D_0041EAF0;
    return p;
}
}

struct cFn140Node {
    char pad[0x144];
    cFn140Node *next;
};

extern "C" {
extern int D_00747A34;
void *func_00149488(void *a);
void func_00150100(cFn140Node *n);
void func_00150638();
void func_0031EEA8(void *obj, const void *a, const void *b);
extern int D_007856D8, __ti4cObj, __ti8cObjBase;
extern const char D_0041EAD8[], D_00460D30[], D_0041EB60[], D_0041EC58[];
void func_002A9790(void *a);

// FUNCTION: GAME 0x149310
void *func_00149310()
{
    if (D_00747A34 & 0x40000)
        return 0;
    return func_00149488(D_00466448);
}

// FUNCTION: GAME 0x149550
void func_00149550(int a, int b)
{
    if (b == 0xFFFF) {
        if (a)
            func_002A9790(D_00466448);
    }
}

// FUNCTION: GAME 0x149BE8
cFn140Node *func_00149BE8(cFn140Node *a, int n)
{
    cFn140Node *p = a->next;
    for (int m = n - 1; m != -1; m--) {
        p = p->next;
        if (!p)
            return 0;
    }
    return p;
}

// FUNCTION: GAME 0x149E60
void func_00149E60(cFn140Node *a)
{
    cFn140Node *p = a->next;
    while (p) {
        cFn140Node *n = p->next;
        func_00150100(p);
        p = n;
    }
    a->next = 0;
}

// FUNCTION: GAME 0x1491D0
void func_001491D0(char *a, float *b)
{
    char *e = a + (*(unsigned char *)&D_007476B0 & 1) * 0xD0;
    *(float *)(e + 0x1B0) = b[0];
    *(float *)(e + 0x1B4) = b[1];
    *(float *)(e + 0x1C0) = b[4];
    *(float *)(e + 0x1C4) = b[5];
    *(float *)(e + 0x1D0) = b[8];
    *(float *)(e + 0x1D4) = b[9];
}

// FUNCTION: GAME 0x14E538
void *func_0014E538()
{
    if (D_007856D8 == 0) {
        func_00150638();
        func_0031EEA8(&D_007856D8, D_0041EAD8, D_00460D30);
    }
    return &D_007856D8;
}

// FUNCTION: GAME 0x14E8D8
void *__tf4cObj()
{
    if (__ti4cObj == 0) {
        func_0014E538();
        func_0031EEA8(&__ti4cObj, D_0041EB60, &D_007856D8);
    }
    return &__ti4cObj;
}

// FUNCTION: GAME 0x14FD20
void *__tf8cObjBase()
{
    if (__ti8cObjBase == 0) {
        __tf4cObj();
        func_0031EEA8(&__ti8cObjBase, D_0041EC58, &__ti4cObj);
    }
    return &__ti8cObjBase;
}
}
