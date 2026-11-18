// Unnamed units in 0x2B0000-0x2C0000 (block copy, state reset).
struct BlkQ { int b[0x2F]; };
extern BlkQ D_005E7910;
extern "C" void func_002B21F0(char *, int);

// FUNCTION: GAME 0x2B2080
extern "C" void func_002B2080(BlkQ *d)
{
    *d = D_005E7910;
}

// DRAFT: GAME 0x2B42F0
// diff: 30 words, flag word is 64-bit (lw/dsrl) in the original; ours sign-extends the masked store (dsll32/dsra32) and lays the arms out differently
#ifdef NONMATCHING
extern "C" void func_002B42F0(char *self)
{
    long fl = *(int *)(self + 0x14);
    unsigned long bit = ((unsigned long)fl >> 6) & 1;
    int nf = fl & -9;
    *(int *)(self + 0x14) = nf;
    if (!bit) {
        unsigned short *p = *(unsigned short **)(self + 0x8C);
        unsigned hi = *p & 0xFF00;
        if (hi == 0x8000) {
            self[0xF] = 0;
            self[0xC] = 7;
        } else if (hi == 0x9000) {
            func_002B21F0(self, p[1]);
            self[0xF] = 0;
            self[0xC] = 0;
        } else {
            self[0xF] = 0;
            self[0xC] = 0;
        }
    } else {
        self[0xF] = 0;
        self[0xC] = 7;
    }
    self[0xD] = 0;
    self[0xE] = 0;
}
#endif

// FUNCTION: GAME 0x2BA250
extern "C" int func_002BA250(char *self)
{
    for (unsigned i = 0; i < *(unsigned *)(self + 4); i++) {
        char *e = *(char **)self + *(int *)(self + 8) * i;
        unsigned fl = *(unsigned *)e;
        if (fl & 0x603) {
            if (fl & 0x400) {
                if (e) {
                    char *vt = *(char **)(e + 8);
                    ((void (*)(char *, int))(*(void **)(vt + 0xC)))(e + *(short *)(vt + 8), 3);
                }
                *(unsigned *)e = 0;
            } else if (fl & 0x200) {
                *(unsigned *)e = fl | 0x400;
            }
        }
    }
    return 1;
}

float capVu0LengthSq(const float *);
extern "C" float sqrtf_(float) __asm__("sqrtf");
static inline float Sq(float a)
{
    float r;
    __asm__("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(r) : "f"(a));
    if (r != r) r = sqrtf_(a);
    return r;
}
extern "C" void func_002BBDB8(char *, float, float, char *, float, float);
extern "C" void func_002BCF28(char *, float, float, char *, float, float);

// FUNCTION: GAME 0x2BCCC0
extern "C" void func_002BCCC0(char *a, char *b, float x, float y, const float *v)
{
    func_002BBDB8(a, x, y, b, 0.0f, Sq(capVu0LengthSq(v)));
}

// FUNCTION: GAME 0x2BD340
extern "C" void func_002BD340(char *a, char *b, float x, float y, const float *v)
{
    func_002BCF28(a, x, y, b, 0.0f, Sq(capVu0LengthSq(v)));
}

// FUNCTION: GAME 0x2BA998
extern "C" void func_002BA998(char *self)
{
    float m = 0.0f;
    for (unsigned i = 0; i < 8; i++) {
        float l = Sq(capVu0LengthSq((float *)(self + 0x110 + i * 16)));
        if (m < l) m = l;
    }
    *(float *)(self + 0xE4) = m;
}
