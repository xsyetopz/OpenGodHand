// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8.
extern "C" void *malloc(unsigned);

struct Stream {
    char _pad[12];
    short m_c;
    char _pad2[0x58 - 0xE];
};

struct FList {
    FList *m_next;
    int m_n;
    Stream *m_files;
};

struct Atx {
    Atx *m_next;
    int m_n;
    void (*m_fn[32])(void);
};

struct Env {
    char _pad[0x148];
    Atx *m_148;
    Atx m_14c;
};

struct Reent {
    char _pad[0x1D8];
    FList m_1d8;
};

extern Env *D_003FA62C;

// FUNCTION: GAME 0x3A6830
extern "C" int func_003A6830(Reent *self, int (*fn)(Stream *))
{
    int r = 0;
    FList *l = &self->m_1d8;
    for (; l; l = l->m_next) {
        int n;
        Stream *s;
        n = l->m_n;
        n--;
        for (s = l->m_files; n >= 0; n--, s++) {
            if (s->m_c)
                r |= fn(s);
        }
    }
    return r;
}

// FUNCTION: GAME 0x3A7B88
extern "C" int atexit(void (*f)(void))
{
    Atx *a = D_003FA62C->m_148;
    if (!a) {
        a = &D_003FA62C->m_14c;
        D_003FA62C->m_148 = a;
    }
    if (a->m_n >= 32) {
        a = (Atx *)malloc(136);
        if (!a)
            return -1;
        ((int *)a)[1] = 0;
        ((Atx **)a)[0] = D_003FA62C->m_148;
        D_003FA62C->m_148 = a;
    }
    int n = a->m_n;
    a->m_fn[n] = f;
    a->m_n = n + 1;
    return 0;
}

extern unsigned char D_003FA998[];
extern "C" char *func_003A95A8(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A9620
// diff: itoa loop; original keeps v in a0 with movz (neg via srl in t2); ours copies v to a3 and uses movn (160 vs 156 bytes, 36 words); signed/unsigned param and if-forms tried
extern "C" char *func_003A9620(unsigned v, char *buf, int base)
{
    unsigned neg = v >> 31;
    int i = 0;
    if (neg) {
        if (base == 10)
            v = -v;
    }
    do {
        buf[i++] = D_003FA998[v % base];
        v = v / base;
    } while (v);
    if (neg)
        buf[i++] = '-';
    buf[i] = 0;
    return func_003A95A8(buf);
}
#endif

struct Bigint {
    unsigned m_0;
    int m_4;
    int m_8;
    int m_c;
    int m_10;
};

struct Mp {
    char _pad[0x4C];
    Bigint **m_4c;
};

extern "C" void *func_003AF7B8(void *, int, int);

// FUNCTION: GAME 0x3AE818
extern "C" Bigint *func_003AE818(Mp *self, int k)
{
    if (!self->m_4c) {
        self->m_4c = (Bigint **)func_003AF7B8(self, 4, 16);
        if (!self->m_4c)
            return 0;
    }
    Bigint *b = self->m_4c[k];
    if (b) {
        self->m_4c[k] = (Bigint *)b->m_0;
    } else {
        int x = 1 << k;
        b = (Bigint *)func_003AF7B8(self, 1, (x << 2) + 20);
        if (!b)
            return 0;
        b->m_4 = k;
        b->m_8 = x;
    }
    b->m_10 = 0;
    b->m_c = 0;
    return b;
}

// FUNCTION: GAME 0x3A9498
extern "C" char *func_003A9498(char *s, const char *delim, char **save)
{
    if (!s) {
        s = *save;
        if (!s)
            return 0;
    }
    char c;
    char d;
    const char *p;
skip:
    c = *s++;
    p = delim;
    while ((d = *p++)) {
        if (c == d)
            goto skip;
    }
    if (!c) {
        *save = 0;
        return 0;
    }
    char *tok = s - 1;
    for (;;) {
        c = *s++;
        p = delim;
        do {
            d = *p++;
            if (d == c) {
                if (c == 0)
                    s = 0;
                else
                    s[-1] = 0;
                *save = s;
                return tok;
            }
        } while (d);
    }
}

struct Iov {
    char *m_base;
    unsigned m_len;
};

struct Uio {
    Iov *m_iov;
    int m_cnt;
    unsigned m_resid;
};

extern "C" int func_003AE1D0(void *, Uio *);

// FUNCTION: GAME 0x3A68C8
extern "C" unsigned func_003A68C8(char *buf, unsigned size, unsigned n, void *fp)
{
    unsigned total = n * size;
    Uio uio;
    Iov iov;
    iov.m_base = buf;
    iov.m_len = total;
    uio.m_iov = &iov;
    uio.m_cnt = 1;
    uio.m_resid = total;
    if (!func_003AE1D0(fp, &uio))
        return n;
    return (total - uio.m_resid) / size;
}

// DRAFT: GAME 0x3AEBC0
// diff: final bit test; original uses xori+andi and 1 fewer word (192 vs 196 bytes)
#ifdef NONMATCHING
extern "C" int func_003AEBC0(unsigned *x)
{
    unsigned y = *x;
    int k;
    if (y & 7) {
        if (y & 1)
            return 0;
        if (y & 2) {
            y >>= 1;
            *x = y;
            return 1;
        }
        y >>= 2;
        *x = y;
        return 2;
    }
    k = 0;
    if (!(y & 0xFFFF)) {
        k = 16;
        y >>= 16;
    }
    if (!(y & 0xFF)) {
        k += 8;
        y >>= 8;
    }
    if (!(y & 0xF)) {
        k += 4;
        y >>= 4;
    }
    if (!(y & 3)) {
        k += 2;
        y >>= 2;
    }
    if ((~y) & 1) {
        y >>= 1;
        k++;
        if (!y)
            return 32;
    }
    *x = y;
    return k;
}
#endif

extern "C" int func_003AD0F8(int);

// FUNCTION: GAME 0x3A92E0
extern "C" int func_003A92E0(char *a, char *b, unsigned n)
{
    if (!n)
        return 0;
    while (--n != (unsigned)-1) {
        if (func_003AD0F8(*a) != func_003AD0F8(*b))
            break;
        if (!n || !*a || !*b)
            break;
        a++;
        b++;
    }
    return func_003AD0F8((unsigned char)*a) - func_003AD0F8((unsigned char)*b);
}

struct Rt2 {
    char _pad[0x38];
    int m_38;
};

struct Fp {
    char _pad[0xc];
    short m_c;
    char _pad2[0x1c - 0xe];
    int m_1c;
    char _pad3[0x2c - 0x20];
    int (*m_2c)(int);
    char _pad4[0x54 - 0x30];
    Rt2 *m_54;
};

extern "C" int func_003A6020(Fp *);
extern "C" void func_003A61F0(Rt2 *);

// FUNCTION: GAME 0x3A5F68
extern "C" int func_003A5F68(Fp *fp)
{
    int r;
    if (!fp)
        return 0;
    if (!fp->m_54)
        fp->m_54 = (Rt2 *)D_003FA62C;
    if (!fp->m_54->m_38)
        func_003A61F0(fp->m_54);
    if (!fp->m_c)
        return 0;
    r = 0;
    if (fp->m_c & 8)
        r = func_003A6020(fp);
    if (fp->m_2c) {
        if (fp->m_2c(fp->m_1c) < 0)
            r = -1;
    }
    fp->m_c = 0;
    return r;
}

struct Fq {
    char *m_0;
    char _pad[0xc - 4];
    unsigned short m_c;
    short m_e;
    char *m_10;
    int m_14;
    char _pad2[0x28 - 0x18];
    int (*m_28)(void);
    char _pad3[0x4c - 0x2c];
    int m_4c;
    char _pad4[0x54 - 0x50];
    void *m_54;
};

struct St {
    int _0;
    unsigned m_mode;
    char _pad[0x70 - 8];
};

extern "C" int func_003ADFA8(void *, int, St *);
extern "C" int func_003A6E60(void);

// FUNCTION: GAME 0x3A6950
extern "C" void func_003A6950(Fq *fp)
{
    St st;
    if (fp->m_c & 2) {
        fp->m_0 = (char *)fp + 0x43;
        fp->m_10 = (char *)fp + 0x43;
        fp->m_14 = 1;
        return;
    }
    if (fp->m_e < 0 || func_003ADFA8(fp->m_54, fp->m_e, &st) < 0) {
        fp->m_c |= 0x800;
    } else if ((st.m_mode & 0xf000) == 0x8000 && fp->m_28 == func_003A6E60) {
        fp->m_4c = 0x400;
        fp->m_c |= 0x400;
    } else {
        fp->m_c |= 0x800;
    }
    fp->m_c |= 2;
    fp->m_0 = (char *)fp + 0x43;
    fp->m_14 = 1;
    fp->m_10 = (char *)fp + 0x43;
}

// FUNCTION: GAME 0x3AF310
extern "C" long long func_003AF310(long long a, long long b)
{
    int e = ((int)(a >> 32) & 0x7ff00000) + (int)0xfcc00000;
    unsigned long long r = b;
    if (e > 0) {
        r = (r & 0xffffffffULL) | ((unsigned long long)e << 32);
        r &= 0xffffffff00000000ULL;
    } else {
        e = (-e) >> 20;
        if (e < 20) {
            r = (r & 0xffffffffULL) | ((unsigned long long)(0x80000 >> e) << 32);
            r &= 0xffffffff00000000ULL;
        } else {
            e -= 20;
            r &= 0xffffffffULL;
            r = (r & 0xffffffff00000000ULL) | (unsigned)(e <= 30 ? 1 << (31 - e) : 1);
        }
    }
    return r;
}
