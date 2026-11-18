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

extern Env *_impure_ptr;

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
    Atx *a = _impure_ptr->m_148;
    if (!a) {
        a = &_impure_ptr->m_14c;
        _impure_ptr->m_148 = a;
    }
    if (a->m_n >= 32) {
        a = (Atx *)malloc(136);
        if (!a)
            return -1;
        ((int *)a)[1] = 0;
        ((Atx **)a)[0] = _impure_ptr->m_148;
        _impure_ptr->m_148 = a;
    }
    int n = a->m_n;
    a->m_fn[n] = f;
    a->m_n = n + 1;
    return 0;
}

extern unsigned char D_003FA998[];
extern "C" char *func_003A95A8(char *);

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
extern "C" unsigned fwrite(char *buf, unsigned size, unsigned n, void *fp)
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
