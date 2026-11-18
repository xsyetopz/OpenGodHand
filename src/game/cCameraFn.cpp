#include "game/cIDBase.h"

class cCamera {
public:
    void move();
    void reset();
};
class cParts;
class cCamManager {
public:
    unsigned isCk_CamClass(unsigned m);
    char _pad0[0x1028];
    unsigned m_flags;
};
class cPartsCamera {
public:
    void SetParts(cParts *a, cParts *b, cParts *c);
    char _pad0[0x360];
    cParts *m_a;
    cParts *m_b;
    cParts *m_c;
};
extern "C" void func_00138BE8(void *);
extern char CamManager[];
extern cCamera *pCamWork;

// FUNCTION: GAME 0x138F88
unsigned cCamManager::isCk_CamClass(unsigned m)
{
    return m & m_flags;
}

// FUNCTION: GAME 0x139B68
void cPartsCamera::SetParts(cParts *a, cParts *b, cParts *c)
{
    m_a = a;
    m_b = b;
    m_c = c;
}

// FUNCTION: GAME 0x13C508
extern "C" void func_0013C508(cIDBase *p) { p->trans(); }

// FUNCTION: GAME 0x13F070
extern "C" void func_0013F070(cIDBase *p) { p->trans(); }

struct VEnt { short delta; short pad; void (*fn)(void *); };
struct W { char _pad[0x35C]; VEnt *m_v; };

// FUNCTION: GAME 0x138210
extern "C" void func_00138210(W *w)
{
    VEnt *v = &w->m_v[1];
    v->fn((char *)w + v->delta);
}

// FUNCTION: GAME 0x139010
extern "C" void func_00139010(int a, unsigned b)
{
    if (b == 0xFFFF && a)
        func_00138BE8(CamManager);
}

// FUNCTION: GAME 0x13F208
extern "C" void func_0013F208(char *p)
{
    if (*(int *)(p + 0x9C) != 0xFFFF)
        ((cIDBase *)p)->trans();
}

extern "C" void func_0030F5A0(void *);
extern char D_0041DCC8[];

// FUNCTION: GAME 0x13C198
extern "C" void func_0013C198(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13C528
extern "C" void func_0013C528(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x138F98
extern "C" void func_00138F98(char *p)
{
    if (*(unsigned *)(p + 0x1028) & 4)
        pCamWork->move();
}

#ifdef NONMATCHING
// 0x13C168 near-miss: original loads lbu and tests ((c ^ 1) & 1) == 0 before trans(); compiled folds to lb/bne with 1 in v1 (48 vs 44 bytes)
// DRAFT: GAME 0x13C168
extern "C" void func_0013C168(char *p)
{
    if (*(bool *)(p + 0x94) == true)
        ((cIDBase *)p)->trans();
}

#endif

extern "C" void func_00139180(int);
extern int D_00747A78;
extern "C" void resetAnim(void *) __asm__("resetAnim__7cIDBase");
extern "C" void func_002AABA0(void *);
extern "C" void func_0031EEC8(void *, const char *);
extern int D_00460D28;
extern const char D_0041DD00[];

// FUNCTION: GAME 0x13C798
extern "C" void func_0013C798(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13CFB0
extern "C" void func_0013CFB0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13D150
extern "C" void func_0013D150(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13D338
extern "C" void func_0013D338(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13F090
extern "C" void func_0013F090(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x139060
extern "C" void func_00139060(int a)
{
    if (!(D_00747A78 & 0x800000))
        func_00139180(a);
}

// FUNCTION: GAME 0x139090
extern "C" void func_00139090(cCamera *c)
{
    c->reset();
    *(int *)((char *)c + 0x1C0) = 0;
}

// FUNCTION: GAME 0x13D0B8
extern "C" void func_0013D0B8(char *p)
{
    resetAnim(p);
    resetAnim(p + 0x140);
    resetAnim(p + 0x190);
    resetAnim(p + 0xA0);
    resetAnim(p + 0xF0);
}

// FUNCTION: GAME 0x13D100
extern "C" void func_0013D100(char *p)
{
    func_002AABA0(p);
    func_002AABA0(p + 0x140);
    func_002AABA0(p + 0x190);
    func_002AABA0(p + 0xA0);
    func_002AABA0(p + 0xF0);
}

// FUNCTION: GAME 0x13C758
extern "C" void *func_0013C758()
{
    if (D_00460D28 == 0)
        func_0031EEC8(&D_00460D28, D_0041DD00);
    return &D_00460D28;
}

// FUNCTION: GAME 0x13E300
extern "C" void func_0013E300(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13E750
extern "C" void func_0013E750(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13EC50
extern "C" void func_0013EC50(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13F270
extern "C" void func_0013F270(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x140B58
extern "C" void func_00140B58(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1434D0
extern "C" void func_001434D0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x143AF0
extern "C" void func_00143AF0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x144AD0
extern "C" void func_00144AD0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146748
extern "C" void func_00146748(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146E70
extern "C" void func_00146E70(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146F98
extern "C" void func_00146F98(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1474A0
extern "C" void func_001474A0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0041D5A8[];

// FUNCTION: GAME 0x12D178
extern "C" void func_0012D178(char *p, int f)
{
    *(char **)(p + 0x5C) = D_0041D5A8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x12DC88
extern "C" void func_0012DC88(char *p, int f)
{
    *(char **)(p + 0x5C) = D_0041D5A8;
    if (f & 1)
        func_0030F5A0(p);
}
extern char D_0041ECA0[];

extern char D_0041D540[];

// FUNCTION: GAME 0x12E640
extern "C" void func_0012E640(char *p, int f)
{
    *(char **)(p + 0x198) = D_0041D540;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0041D8F8[];

// FUNCTION: GAME 0x139878
extern "C" void func_00139878(char *p, int f)
{
    *(char **)(p + 0x35C) = D_0041D8F8;
    if (f & 1)
        func_0030F5A0(p);
}


// FUNCTION: GAME 0x150048
extern "C" void func_00150048(char *p, int f)
{
    *(char **)(p + 0x214) = D_0041ECA0;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0042C4D8[];

// FUNCTION: GAME 0x1FCE80
extern "C" void func_001FCE80(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1FD418
extern "C" void func_001FD418(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1FE500
extern "C" void func_001FE500(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0044B310[];

// FUNCTION: GAME 0x2B6568
extern "C" void func_002B6568(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044B310;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x2FBDD8
extern "C" void func_002FBDD8(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044B310;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0044BAB0[];

// FUNCTION: GAME 0x2B8B20
extern "C" void func_002B8B20(char *p, int f)
{
    *(char **)(p + 0x18) = D_0044BAB0;
    if (f & 1)
        func_0030F5A0(p);
}


extern char D_0044D1C8[];
extern char D_00451038[];
extern char D_003BAFE0[];

// FUNCTION: GAME 0x139C58
extern "C" void _$_9cPlCamera(char *p, int f)
{
    *(char **)(p + 0x35C) = D_0041D8F8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x2D5CA8
extern "C" void func_002D5CA8(char *p, int f)
{
    *(char **)(p + 0x30) = D_0044D1C8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x31EE10
extern "C" void func_0031EE10(char *p, int f)
{
    *(char **)(p + 0x4) = D_00451038;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x372C80
extern "C" void func_00372C80(char *p, int f)
{
    *(char **)(p + 0x80) = D_003BAFE0;
    if (f & 1)
        func_0030F5A0(p);
}
