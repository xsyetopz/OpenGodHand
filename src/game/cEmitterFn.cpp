extern "C" void *func_002FBCC8(void *);
extern "C" void *func_002F7110(void *);
extern "C" void *func_002F7CD8(void *);
extern "C" void func_0030F5A0(void *);
extern char D_0044F630[];
extern char D_0044F880[];
extern char D_0044B310[];

struct EmWork {
    char _pad0[0xF0];
    void *m_vt;
};

struct EmFlag {
    char _pad0[0x10C];
    int m_a;
    int m_b;
    unsigned int m_flags;
};

// FUNCTION: GAME 0x300020
extern "C" void *func_00300020(EmWork *p)
{
    EmWork *r = p;
    if (r) {
        func_002FBCC8(r);
        r->m_vt = D_0044F630;
    }
    return r;
}

// FUNCTION: GAME 0x3000B0
extern "C" void *func_003000B0(EmWork *p)
{
    EmWork *r = p;
    if (r) {
        func_002FBCC8(r);
        r->m_vt = D_0044F880;
    }
    return r;
}

// FUNCTION: GAME 0x3028E8
extern "C" void func_003028E8(EmWork *p, int a)
{
    p->m_vt = D_0044B310;
    if (a & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x302918
extern "C" void func_00302918(EmFlag *p)
{
    p->m_flags |= 0x40000000;
}

// FUNCTION: GAME 0x3039E8
extern "C" void func_003039E8(EmFlag *p, int a, int b)
{
    if (p->m_a == a && p->m_b == b)
        func_00302918(p);
}

struct EmSrc {
    char _pad0[0xC0];
    unsigned short m_c0;
    unsigned short m_c2;
};

struct EmObj {
    char _pad0[0x100];
    EmSrc *m_src;
    char _pad104[0x186 - 0x104];
    unsigned short m_186;
    unsigned short m_188;
    char _pad18A[0x1ED - 0x18A];
    unsigned char m_1ED;
    char _pad1EE[0x210 - 0x1EE];
    unsigned short m_210;
    char _pad212[0x224 - 0x212];
    unsigned short m_224;
};

// FUNCTION: GAME 0x302988
extern "C" void func_00302988(EmObj *p, EmSrc *s)
{
    p->m_src = s;
    p->m_186 = s->m_c0 + p->m_1ED;
    unsigned short v = s->m_c2;
    p->m_188 = v;
    if ((short)v > 0)
        p->m_188 = v + p->m_1ED;
}

// FUNCTION: GAME 0x303A20
extern "C" int func_00303A20(EmObj *p)
{
    p->m_224 = p->m_210;
    return 1;
}

extern "C" void *func_00302790(void *);
extern char D_0044FCF8[];
extern char D_0044FC98[];

// FUNCTION: GAME 0x304D48
extern "C" void *func_00304D48(void *p)
{
    void *r = p;
    if (r)
        r = func_00302790(r);
    return r;
}

// FUNCTION: GAME 0x3051D8
extern "C" void func_003051D8(EmWork *p, int a)
{
    p->m_vt = D_0044FC98;
    func_003028E8(p, a);
}

struct EmPos {
    char _pad0[0x100];
    EmPos *m_src;
    char _pad104[0x240 - 0x104];
    float m_240;
    float m_244;
    float m_248;
    float m_24C;
    float m_250;
    unsigned char m_254;
    char _pad255[0x27C - 0x255];
    unsigned char m_27C;
};

// FUNCTION: GAME 0x304BB8
extern "C" int func_00304BB8(EmPos *p)
{
    EmPos *s = p->m_src;
    p->m_240 = s->m_248;
    p->m_244 = s->m_24C;
    p->m_248 = *(float *)((char *)s + 0x250);
    p->m_24C = 1.0f - *(float *)((char *)s + 0x254);
    p->m_254 = s->m_27C;
    return 1;
}

// FUNCTION: GAME 0x304D70
extern "C" void *func_00304D70(EmWork *p)
{
    EmWork *r = p;
    if (r) {
        func_00302790(r);
        r->m_vt = D_0044FCF8;
    }
    return r;
}

// FUNCTION: GAME 0x304DB0
extern "C" void *func_00304DB0(EmWork *p)
{
    EmWork *r = p;
    if (r) {
        func_00302790(r);
        r->m_vt = D_0044FC98;
    }
    return r;
}
