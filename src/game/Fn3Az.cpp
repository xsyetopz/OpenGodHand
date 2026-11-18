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
    unsigned total = size * n;
    Iov iov;
    Uio uio;
    iov.m_base = buf;
    iov.m_len = total;
    uio.m_iov = &iov;
    uio.m_cnt = 1;
    uio.m_resid = total;
    if (func_003AE1D0(fp, &uio))
        return (total - uio.m_resid) / size;
    return n;
}
