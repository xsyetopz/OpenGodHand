// Table lookup/update companion of the 0x3944E8 / 0x3945C0 family (see Fn394a.cpp).
struct Fn394E {
    const char *m_0;
    int m_4;
    unsigned short m_8;
    unsigned char m_A;
    unsigned char m_B;
};
struct Fn394N {
    char _p0[4];
    void *m_4;
    int m_8;
    Fn394E *m_C;
    int m_10;
    char _p14[0x1C];
    Fn394N *m_30;
};
extern Fn394N *D_003F852C;
extern "C" int strcmp(const char *, const char *);
extern "C" int func_00394290(void *, int, int, int);

// FUNCTION: GAME 0x3943D0
extern "C" int func_003943D0(Fn394E *k)
{
    k->m_B = 1;
    unsigned short id = k->m_8;
    int base = k->m_4;
    const char *name = k->m_0;
    for (Fn394N *n = D_003F852C; n; n = n->m_30) {
        int cnt = n->m_10;
        Fn394E *e = n->m_C;
        for (; cnt; cnt--, e++) {
            if (e->m_8 == id && strcmp(e->m_0, name) == 0 && (e->m_A == 1 || e->m_A == 3)) {
                if (!func_00394290(n->m_4, n->m_8, e - n->m_C, base))
                    return 0;
                break;
            }
        }
    }
    return 1;
}
