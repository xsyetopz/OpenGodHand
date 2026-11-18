extern "C" void func_002BB1F0(int);

// FUNCTION: GAME 0x2B8AA8
extern "C" void func_002B8AA8(int *self)
{
    self[0xD8 / 4] = 0;
    if (((self[0] & 0x203) ^ 3) == 0)
        func_002BB1F0(self[0x34 / 4]);
}

struct KF { unsigned short a, t; };

// FUNCTION: GAME 0x2BDEE8
extern "C" KF *func_002BDEE8(char *, float f, KF *p, int n)
{
    for (int i = n - 1; i >= 0; i--) {
        if ((float)p[i].t <= f)
            return &p[i];
    }
    return 0;
}


extern "C" int func_002BF700();
extern "C" void func_002BF170(char *);
extern unsigned D_00747A84[];

// FUNCTION: GAME 0x2BF268
extern "C" int openLoad__9cSaveLoad(unsigned char *self)
{
    if (!func_002BF700())
        return 0;
    func_002BF170((char *)self);
    D_00747A84[1] |= 0x40000000;
    self[0] = 2;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    return 1;
}

extern unsigned char D_00747A51;
extern "C" void func_002BEBC8();

// diff: 2 words, original shifts a>>8 into $v0 where ours uses $a1
// DRAFT: GAME 0x2BED60
#ifdef NONMATCHING
extern "C" int func_002BED60(unsigned *self, unsigned short a, long b)
{
    int r;
    unsigned char c = D_00747A51;
    unsigned hi = a >> 8;
    if (c == hi) {
        unsigned s0 = *self;
        func_002BEBC8();
        r = func_002BED08(self, b);
        *self = s0;
    } else
        r = 0;
    return r;
}
#endif

extern "C" unsigned char *func_002BEAA8(char *, unsigned short);

// diff: 7 words, operand order of the base+offset adds and load scheduling
// DRAFT: GAME 0x2BEB00
#ifdef NONMATCHING
extern "C" char *func_002BEB00(char **self, unsigned short id, unsigned char k)
{
    unsigned char *e = func_002BEAA8((char *)self, id);
    char *r = 0;
    if (e && k < e[2]) {
        int off = (e[3] + k) * 0x30;
        char *b = *self;
        r = (char *)((int)b + *(int *)(b + 8)) + off;
    }
    return r;
}
#endif

// FUNCTION: GAME 0x2B4F98
extern "C" char *func_002B4F98(char *self, int key)
{
    if (key == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        if (*(int *)(self + 4 + i * 4) == key)
            return *(char **)self + i * 0xAC;
    }
    return 0;
}

// FUNCTION: GAME 0x2BED08
extern "C" int func_002BED08(unsigned *self, long key)
{
    if (key == 0)
        return 0;
    unsigned char *b = *(unsigned char **)self;
    long *q = (long *)(b + 0x610);
    for (unsigned i = 0; i < 0x100; i++, q += 2) {
        unsigned off = i * 16;
        if (*q == key)
            return b[off + 0x618] == 1;
    }
    return 0;
}

// FUNCTION: GAME 0x2BECB0
extern "C" void func_002BECB0(unsigned *self, long key)
{
    if (key) {
        long *q = (long *)(*(char **)self + 0x610);
        long *w = q;
        for (unsigned i = 0; i < 0x100; i++, w += 2, q += 2) {
            unsigned off = i * 16;
            if (*q == 0) {
                *w = key;
                (*(char **)self)[off + 0x618] = 1;
                return;
            }
        }
    }
}

// FUNCTION: GAME 0x2BDF80
extern "C" void setSeq__7cPadVibiUif(char *self, int idx, unsigned flags, float rate)
{
    char *base = *(char **)self;
    char *p = base + 4;
    unsigned n = *(unsigned short *)base;
    char *e = p + idx * 4;
    *(char **)(self + 4) = e;
    char *s1 = p + n * 4;
    s1 += *(unsigned short *)(e + 2) * 4;
    *(char **)(self + 8) = s1;
    *(char **)(self + 0xC) = s1 + *(unsigned char *)e * 4;
    *(int *)(self + 0x14) = idx;
    *(unsigned *)(self + 0x18) = flags;
    *(float *)(self + 0x1C) = rate;
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = 0;
}

// FUNCTION: GAME 0x2B2D28
extern "C" int func_002B2D28(char *self)
{
    unsigned short t;
    if (!(*(unsigned *)(self + 0x14) & 0x8000)) {
        unsigned short x = *(unsigned short *)(*(char **)(self + 0x8C) + 2);
        *(unsigned *)(self + 0x14) |= 0x8000;
        *(unsigned short *)(self + 0x3A) = x;
    }
    t = *(unsigned short *)(self + 0x3A);
    if (t != 0) {
        *(unsigned short *)(self + 0x3A) = t - 1;
        return 1;
    }
    *(unsigned *)(self + 0x14) &= 0xFFFF7FFF;
    return 0;
}

extern char D_005E7E30[];
extern "C" void func_002B5AE8(char *);

// FUNCTION: GAME 0x2B48F0
extern "C" char *func_002B48F0(char *self)
{
    *(char **)self = D_005E7E30;
    char *p = self + 0x1C;
    int n = 0x3F;
    do {
        func_002B5AE8(p);
        n--;
        p += 8;
    } while (n != -1);
    return self;
}

extern "C" void func_002B46F0(char *, int, int, int);

// diff: 9 words, original materializes the -3 mask and zero store in different registers/order
// DRAFT: GAME 0x2B3460
#ifdef NONMATCHING
extern "C" void func_002B3460(char *self)
{
    int a3 = 0;
    int a1 = *(int *)(self + 0x20);
    if (*(unsigned char *)(self + 0x70) == 0)
        a3 = *(int *)(self + 0x18);
    func_002B46F0(self, a1, 0, a3);
    unsigned i = 0;
    unsigned short *p = (unsigned short *)(self + 0x24);
    for (; i < 2; i++, p++)
        p[0] = p[1];
    int fl = *(int *)(self + 0x14) & -3;
    int z = 0;
    *(unsigned short *)(self + 0x28) = z;
    *(int *)(self + 0x14) = fl;
}
#endif
