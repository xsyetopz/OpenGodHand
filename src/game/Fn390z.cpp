// Game-code name lookup in 0x393FD8 (ee-gcc2.95.3-136, C++).

struct Fn390E {
    const char *m_0;
    int m_4;
    unsigned short m_8;
    unsigned char m_A;
    unsigned char m_B;
};
struct Fn390N {
    char _p0[0xC];
    Fn390E *m_C;
    int m_10;
    char _p14[0x1C];
    Fn390N *m_30;
};
extern Fn390N *D_003F852C;
extern "C" int strcmp(const char *, const char *);
// FUNCTION: GAME 0x393FD8
extern "C" int func_00393FD8(const char *name, unsigned short id)
{
    for (Fn390N *n = D_003F852C; n; n = n->m_30) {
        int cnt = n->m_10;
        Fn390E *e = n->m_C;
        for (; cnt; cnt--, e++) {
            if (e->m_B && e->m_8 == id && strcmp(e->m_0, name) == 0)
                return e->m_4;
        }
    }
    return 0;
}
