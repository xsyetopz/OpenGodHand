// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8 (errno-capturing syscall wrappers).
extern int D_0077DB88;
extern "C" long func_003B0450(int, int);
extern "C" long func_003B0390(int, int, int);
extern "C" long func_003B02E8(int, int, int);
extern "C" int func_003B0398(int);
extern "C" long func_003B0268(int, int, int);

// FUNCTION: GAME 0x3ADFA8
extern "C" long func_003ADFA8(int *self, int a1, int a2)
{
    D_0077DB88 = 0;
    long r = func_003B0450(a1, a2);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE008
extern "C" long func_003AE008(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B0390(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE068
extern "C" long func_003AE068(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B02E8(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE0C8
extern "C" int func_003AE0C8(int *self, int a1)
{
    D_0077DB88 = 0;
    unsigned r = func_003B0398(a1);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE128
extern "C" long func_003AE128(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B0268(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// Round 26.

extern "C" int func_003AD0F8(int);

// FUNCTION: GAME 0x3A9260
extern "C" int func_003A9260(char *a, char *b)
{
    while (*a) {
        if (func_003AD0F8(*a) != func_003AD0F8(*b))
            break;
        a++;
        b++;
    }
    return func_003AD0F8((unsigned char)*a) - func_003AD0F8((unsigned char)*b);
}

struct Ent {
    int m_0;
    unsigned m_4;
    int m_8;
};

extern "C" int func_00394328(int, unsigned);

// FUNCTION: GAME 0x394348
extern "C" int func_00394348(Ent *e, int n, unsigned key)
{
    unsigned i = n - 1;
    if (n) {
        do {
            unsigned w = e->m_4;
            if ((w >> 8) == key) {
                if (!func_00394328(e->m_0, w & 0xff))
                    return 0;
            }
            e++;
        } while (--i != (unsigned)-1);
    }
    return 1;
}

struct Cfg {
    int m_0;
    int m_4;
};

struct Rec {
    char _pad[10];
    unsigned char m_a;
    unsigned char m_b;
};

struct Tab {
    char _pad[12];
    Rec *m_c;
    int m_10;
};

extern Cfg D_003F5520;
extern int D_0040A420;
extern Tab *D_003F852C;

#ifdef NONMATCHING
// DRAFT: GAME 0x394D58
// diff: original has one shared `return 7` block mid-loop and v1 reuse (124 bytes); ours 132 with bgez/b layout
extern "C" int func_00394D58(int *out)
{
    D_003F5520.m_4 = 0x31415926;
    D_003F5520.m_0 = 0;
    if (out)
        *out = D_0040A420;
    Tab *t = D_003F852C;
    int n = t->m_10;
    if (n) {
        Rec *r = t->m_c;
        do {
            int v = r->m_a;
            if (v < 0)
                return 7;
            if (v < 2)
                r->m_b = 0;
            else if (v < 5)
                r->m_b = 1;
            else
                return 7;
            r++;
        } while (--n);
    }
    return 0;
}
#endif
