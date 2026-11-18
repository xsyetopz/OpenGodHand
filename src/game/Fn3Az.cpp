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
        for (n = l->m_n, n--, s = l->m_files; n >= 0; n--, s++) {
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
