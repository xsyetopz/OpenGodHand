// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8 (errno-capturing syscall wrappers).
extern int D_0077DB88;
extern "C" long func_003B0450(int, int);
extern "C" long func_003B0390(int, int, int);
extern "C" long func_003B02E8(int, int, int);
extern "C" int func_003B0398(int);
extern "C" long func_003B0268(int, int, int);

extern "C" void func_003A6188(void *, short, short, void *);
extern "C" void func_003A6290(void *);

struct Rt {
    char _pad[0x38];
    int m_38;
    void (*m_3c)(void *);
    char _pad2[0x1D8 - 0x40];
    int m_1d8;
    int m_1dc;
    void *m_1e0;
    char m_1e4[3][0x58];
};

// FUNCTION: GAME 0x3A61F0
extern "C" void func_003A61F0(Rt *self)
{
    self->m_3c = func_003A6290;
    self->m_38 = 1;
    func_003A6188(self->m_1e4[0], 4, 0, self);
    func_003A6188(self->m_1e4[1], 9, 1, self);
    func_003A6188(self->m_1e4[2], 10, 2, self);
    self->m_1e0 = self->m_1e4[0];
    self->m_1dc = 3;
    self->m_1d8 = 0;
}

struct Ent2 {
    int m_0;
    unsigned m_4;
    int m_8;
};

extern "C" int func_00394088(int, unsigned, int);

// FUNCTION: GAME 0x394290
extern "C" int func_00394290(Ent2 *e, int n, unsigned key, int base)
{
    unsigned i = n - 1;
    if (n) {
        do {
            unsigned w = e->m_4;
            if ((w >> 8) == key) {
                if (!func_00394088(e->m_0, w & 0xff, base + e->m_8))
                    return 0;
            }
            e++;
        } while (--i != (unsigned)-1);
    }
    return 1;
}

// FUNCTION: GAME 0x3A9538
extern "C" int func_003A9538(char *s, int n)
{
    if (n > 0) {
        n--;
        char *p = s + n;
        if (*p >= '5') {
            do {
                *p = '0';
                n--;
                p--;
            } while (n > 0 && *p == '9');
            if (s[n] == '9')
                return 0;
            s[n]++;
        }
    }
    return 1;
}

struct Big {
    char _pad[0x10];
    int m_10;
    unsigned m_14[1];
};
