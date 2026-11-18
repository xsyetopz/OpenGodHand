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
