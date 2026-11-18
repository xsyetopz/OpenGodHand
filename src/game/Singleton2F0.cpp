// Singleton accessors in 0x2F0000-0x30A2AF.

extern "C" {

struct S2G_Single { int m_0; int m_4; int m_8; int m_C; };
void func_0031EEA8(S2G_Single *a, char *b, char *c);
extern S2G_Single D_00786478;
extern S2G_Single D_00786488;
extern S2G_Single D_00786498;
extern S2G_Single D_007864A8;
extern S2G_Single D_007864B8;
extern S2G_Single D_007864D8;
extern S2G_Single D_007864E8;
extern S2G_Single D_007864F8;
extern S2G_Single D_00786518;
extern S2G_Single D_00786528;
extern S2G_Single D_00786538;
extern S2G_Single D_00786548;
extern S2G_Single D_00786568;
extern S2G_Single D_00786588;
extern S2G_Single D_007865E8;
extern char D_0044EB48[];
extern char D_0044EC00[];
extern char D_0044ECF8[];
extern char D_0044EEC8[];
extern char D_0044EF98[];
extern char D_0044F108[];
extern char D_0044F258[];
extern char D_0044F300[];
extern char D_0044F430[];
extern char D_0044F4E0[];
extern char D_0044F590[];
extern char D_0044F628[];
extern char D_0044F770[];
extern char D_0044F910[];
extern char D_0044FE88[];
extern char D_007863C8[];
extern char D_007863F8[];
void func_002EFA60(void);
void func_00300148(void);

// FUNCTION: GAME 0x002F0060
S2G_Single *func_002F0060(void) {
    if (!D_00786478.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786478, D_0044EB48, D_007863C8);
    }
    return &D_00786478;
}

// FUNCTION: GAME 0x002F1170
S2G_Single *func_002F1170(void) {
    if (!D_00786488.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786488, D_0044EC00, D_007863C8);
    }
    return &D_00786488;
}

// FUNCTION: GAME 0x002F1AC0
S2G_Single *func_002F1AC0(void) {
    if (!D_00786498.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786498, D_0044ECF8, D_007863C8);
    }
    return &D_00786498;
}

// FUNCTION: GAME 0x002F2848
S2G_Single *func_002F2848(void) {
    if (!D_007864A8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007864A8, D_0044EEC8, D_007863C8);
    }
    return &D_007864A8;
}

// FUNCTION: GAME 0x002F2FA0
S2G_Single *func_002F2FA0(void) {
    if (!D_007864B8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007864B8, D_0044EF98, D_007863C8);
    }
    return &D_007864B8;
}

// FUNCTION: GAME 0x002F4238
S2G_Single *func_002F4238(void) {
    if (!D_007864D8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007864D8, D_0044F108, D_007863C8);
    }
    return &D_007864D8;
}

// FUNCTION: GAME 0x002F4B88
S2G_Single *func_002F4B88(void) {
    if (!D_007864E8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007864E8, D_0044F258, D_007863C8);
    }
    return &D_007864E8;
}

// FUNCTION: GAME 0x002F4D48
S2G_Single *func_002F4D48(void) {
    if (!D_007864F8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007864F8, D_0044F300, D_007863C8);
    }
    return &D_007864F8;
}

// FUNCTION: GAME 0x002F5508
S2G_Single *func_002F5508(void) {
    if (!D_00786518.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786518, D_0044F430, D_007863C8);
    }
    return &D_00786518;
}

// FUNCTION: GAME 0x002F6178
S2G_Single *func_002F6178(void) {
    if (!D_00786528.m_0) {
        func_002EFA60();
        func_0031EEA8(&D_00786528, D_0044F4E0, D_007863F8);
    }
    return &D_00786528;
}

// FUNCTION: GAME 0x002F6AF0
S2G_Single *func_002F6AF0(void) {
    if (!D_00786538.m_0) {
        func_002EFA60();
        func_0031EEA8(&D_00786538, D_0044F590, D_007863F8);
    }
    return &D_00786538;
}

// FUNCTION: GAME 0x002F6C80
S2G_Single *func_002F6C80(void) {
    if (!D_00786548.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786548, D_0044F628, D_007863C8);
    }
    return &D_00786548;
}

// FUNCTION: GAME 0x002F7C88
S2G_Single *func_002F7C88(void) {
    if (!D_00786568.m_0) {
        func_002EFA60();
        func_0031EEA8(&D_00786568, D_0044F770, D_007863F8);
    }
    return &D_00786568;
}

// FUNCTION: GAME 0x002FA018
S2G_Single *func_002FA018(void) {
    if (!D_00786588.m_0) {
        func_00300148();
        func_0031EEA8(&D_00786588, D_0044F910, D_007863C8);
    }
    return &D_00786588;
}

// FUNCTION: GAME 0x00305308
S2G_Single *func_00305308(void) {
    if (!D_007865E8.m_0) {
        func_00300148();
        func_0031EEA8(&D_007865E8, D_0044FE88, D_007863C8);
    }
    return &D_007865E8;
}

}
