// Unnamed units in 0x2B0000-0x2C0000 (block copy, state reset).
struct BlkQ { int b[0x2F]; };
extern BlkQ D_005E7910;
extern "C" void func_002B21F0(char *, int);
extern "C" int func_002AF218(unsigned short *);

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

extern char *Message;
extern char Snd;
extern "C" void func_002CB7E8(char *, int);
extern "C" int func_002AEF90(char *);
extern "C" void func_002AEF98(char *);
extern "C" void func_002B4428(char *, int, int);
extern "C" void func_002B45E8(char *);

// FUNCTION: GAME 0x2B2348
extern "C" void func_002B2348(char *self)
{
    if (*(unsigned *)(self + 0x14) & 0x1000) {
        if (*(int *)(self + 0x1C)) func_002CB7E8(&Snd, *(int *)(self + 0x20));
        *(int *)(self + 0x1C) = 0;
        *(int *)(self + 0x20) = -1;
        if (!func_002AEF90(Message)) func_002B4428(self, 0, 0);
        else func_002AEF98(Message);
        func_002B45E8(self);
        *(char *)(self + 0xC) = 7;
        *(int *)(self + 0x14) &= -0x1001;
        *(char *)(self + 0xD) = 0;
        *(char *)(self + 0xE) = 0;
        *(char *)(self + 0xF) = 0;
    }
}

extern "C" char *GetMsgAddr(char *, unsigned short) __asm__("getMessageAddr__C8cMessageUs");
extern "C" char *GetRubyAddr(char *, unsigned short) __asm__("getRubyAddr__C8cMessageUs");

// FUNCTION: GAME 0x2B21F0
extern "C" void func_002B21F0(char *self, int no)
{
    unsigned short n = no;
    char *m = GetMsgAddr(Message, n);
    char *r = GetRubyAddr(Message, n);
    *(unsigned *)(self + 0x14) |= 2;
    *(unsigned short *)(self + 0x94) = 0;
    *(unsigned short *)(self + 0x88) = 0xFFFF;
    *(char *)(self + 0x70) = 0;
    *(char *)(self + 0xA4) = 0;
    *(int *)(self + 0x34) = 0;
    unsigned i = 0;
    unsigned short *p = (unsigned short *)(self + 0x24);
    do { *p++ = 0xFFFF; i++; } while (i < 3);
    *(float *)(self + 0x6C) = 1.0f;
    *(unsigned short *)(self + 0x64) = n;
    *(char **)(self + 0x8C) = m;
    *(char **)(self + 0x7C) = m;
    *(char **)(self + 0x74) = m;
    *(char *)(self + 0x30) = -1;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x90) = 0;
    *(int *)(self + 0x84) = 0;
    *(char **)(self + 0x78) = r;
    *(unsigned short *)(self + 0x38) = 0;
    *(char **)(self + 0x80) = r;
    *(char *)(self + 0x3C) = 0;
}

extern "C" unsigned getCodeSize__11cMessCommonUs(unsigned short);
extern "C" int isPageEndCode__11cMessCommonUs(unsigned short);
extern "C" unsigned short *func_002B0700(char *, unsigned short *, float *, float *, float *);
extern "C" void func_002B0480(char *, float *);

// FUNCTION: GAME 0x2B0610
extern "C" void func_002B0610(char *self, unsigned short *s, float *w, float *h)
{
    float t[8];
    *w = 0.0f;
    *h = 0.0f;
    func_002B0480(self, t);
    for (;;) {
        s = func_002B0700(self, s, t, &t[4], &t[5]);
        if (*w < t[4]) *w = t[4];
        *h += t[5];
        if (isPageEndCode__11cMessCommonUs(*s)) break;
        *h += *(float *)(self + 0x30) * *(float *)(self + 0x48);
        s += getCodeSize__11cMessCommonUs(*s);
    }
}

extern "C" void func_002B43B0(char *);

// FUNCTION: GAME 0x2B3A38
extern "C" int func_002B3A38(char *self)
{
    int r = func_002AF218(*(unsigned short **)(self + 0x8C));
    unsigned short *p = *(unsigned short **)(self + 0x8C);
    int a = *(int *)(self + 0x90);
    unsigned n = getCodeSize__11cMessCommonUs(*p);
    a += r;
    int f = *(int *)(self + 0x14);
    int c = *(unsigned char *)(self + 0x30);
    *(int *)(self + 0x68) = a;
    *(int *)(self + 0x84) = a;
    *(unsigned short **)(self + 0x7C) = *(unsigned short **)(self + 0x8C) + n;
    f &= -3;
    f &= -5;
    *(char *)(self + 0x30) = c + 1;
    *(int *)(self + 0x14) = f;
    func_002B43B0(self);
    func_002B45E8(self);
    return 0;
}

extern "C" int func_002AF218(unsigned short *);

// FUNCTION: GAME 0x2B45F8
extern "C" int func_002B45F8(char *self, unsigned short *s, unsigned short code)
{
    for (; !func_002AF218(s); s += getCodeSize__11cMessCommonUs(*s)) {
        unsigned c = *s;
        if (c >> 15) {
            unsigned m = c & 0xFF00;
            if (m == code) return 1;
            if (m == 0x8000) return 0;
        }
    }
    return 0;
}

extern "C" float func_002B0BE0(char *, unsigned short *, float *);
extern "C" void func_002B04C0(char *, unsigned short *, float *);
extern "C" int func_002AF068(unsigned short);

// FUNCTION: GAME 0x2B0830
extern "C" unsigned short *func_002B0830(char *self, unsigned short *s, float *p, float *out)
{
    float m = 0.0f;
    *out = 0.0f;
    while (!(*s >> 15) || (func_002B04C0(self, s, p), !func_002AF068(*s))) {
        float w = func_002B0BE0(self, s, p);
        if (m < w) {
            m = w;
            *out = *p * *(float *)(self + 0x40) * *(float *)(self + 0x48);
        }
        s += getCodeSize__11cMessCommonUs(*s);
    }
    return s;
}

extern "C" int func_002B6510(char *);
extern "C" int func_002B5E58(char *);
extern "C" char *func_002B5E90(char *, int);

// FUNCTION: GAME 0x2B6370
extern "C" void func_002B6370(char *self)
{
    if (func_002B6510(self)) {
        int n = func_002B5E58(self);
        for (int i = 0; i < n;) {
            char *c = func_002B5E90(self, i);
            i++;
            func_002B6370(c);
        }
        *(unsigned *)(self + 0x90) &= ~1u;
    }
}

extern char D_0044BAF8[];
extern "C" void func_002BAC88(char *);
extern "C" void func_002BB040(char *);

// FUNCTION: GAME 0x2B8990
extern "C" char *func_002B8990(char *self)
{
    *(int *)self = 3;
    char *a = self + 0x14;
    char *p = a;
    *(char **)(self + 8) = D_0044BAF8;
    *(char *)(self + 0xD) = 0;
    int n = 3;
    do {
        func_002BAC88(p);
        n--;
        p += 8;
    } while (n != -1);
    func_002BB040(a);
    func_002BB040(self + 0x14);
    *(unsigned *)self |= 3;
    return self;
}
