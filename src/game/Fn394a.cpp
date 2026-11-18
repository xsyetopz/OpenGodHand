// Game-code table lookups in 0x393FD8-0x394F20 (ee-gcc2.95.3-136, C++).

struct Fn394E {
    const char *m_0;
    int _p4;
    unsigned short m_8;
    unsigned char m_A;
    unsigned char m_B;
};
struct Fn394N {
    char _p0[0xC];
    Fn394E *m_C;
    int m_10;
    char _p14[0x1C];
    Fn394N *m_30;
};
extern Fn394N *D_003F852C;
extern "C" int strcmp(const char *, const char *);
extern "C" int func_003943D0(Fn394E *);

// FUNCTION: GAME 0x3945C0
extern "C" int func_003945C0(Fn394E *k)
{
    for (Fn394N *n = D_003F852C; n; n = n->m_30) {
        int cnt = n->m_10;
        Fn394E *e = n->m_C;
        for (; cnt; cnt--, e++) {
            if (e->m_B && e->m_8 == k->m_8 && strcmp(e->m_0, k->m_0) == 0)
                return 1;
        }
    }
    return func_003943D0(k);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3944E8
// diff: 12 words; original returns 1 for A==2 or A==4 and, for any other A, clears m_B and jumps to the func_003943D0 tail with likely branches (3 variants tried).
extern "C" int func_003944E8(Fn394E *k)
{
    for (Fn394N *n = D_003F852C; n; n = n->m_30) {
        int cnt = n->m_10;
        Fn394E *e = n->m_C;
        for (; cnt; cnt--, e++) {
            if (e->m_B && e->m_8 == k->m_8 && strcmp(e->m_0, k->m_0) == 0) {
                if (e->m_A == 2)
                    return 1;
                if (e->m_A != 4) {
                    e->m_B = 0;
                    return func_003943D0(k);
                }
                return 1;
            }
        }
    }
    return func_003943D0(k);
}
#endif

struct Fn394S {
    int m_0;
    int m_4;
    int m_8;
};
struct Fn394T {
    unsigned m_0;
    unsigned m_4;
    Fn394S e[0x400];
};
extern Fn394T D_003F5520;

#ifdef NONMATCHING
// DRAFT: GAME 0x394C18
// diff: many words; original keeps pointer-walk loop, mine uses indexed loop (2 variants tried).
extern "C" int func_00394C18(int a, int b)
{
    unsigned i;
    if (D_003F5520.m_0) {
        for (i = 0; i < D_003F5520.m_0; i++) {
            if (D_003F5520.e[i].m_4 == 0) {
                D_003F5520.e[i].m_0 = a;
                D_003F5520.e[i].m_4 = b;
                D_003F5520.e[i].m_8 = a ^ b ^ 0x31415926;
                return i;
            }
        }
    }
    if (D_003F5520.m_0 == 0x400)
        return -1;
    i = D_003F5520.m_0;
    D_003F5520.m_0 = i + 1;
    D_003F5520.e[i].m_0 = a;
    D_003F5520.e[i].m_4 = b;
    D_003F5520.e[i].m_8 = a ^ b ^ 0x31415926;
    D_003F5520.m_4 = D_003F5520.m_0 ^ 0x31415926;
    return i;
}
#endif
