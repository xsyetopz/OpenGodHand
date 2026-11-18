#include "game/cVec.h"

// Free units whose only COP2 instructions are lqc2/sqc2 (quad copies and vf0 stores).
struct V16 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern V16 ZeroVec;
extern V16 D_0061B660;
extern V16 Spline[4];
extern "C" void *func_001B6E90(void *);
extern "C" void func_002A9DF8(void *);
extern "C" void func_00271518(void *, void *);
extern const char D_00428160[];
extern const char D_00428588[];
extern const char D_0041D808[];
enum eEffDataType { };
enum eEffId { };
class cObj;
extern void SetEffectPos(eEffDataType, eEffId, cObj *, const cVec &, float, int);

// FUNCTION: GAME 0x2BA488
extern "C" V16 *func_002BA488(V16 *d)
{
    V16 *r = d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(r), "r"(&ZeroVec) : "memory");
    return r;
}

// FUNCTION: GAME 0x2F1AA0
extern "C" void func_002F1AA0(void *a, int b)
{
    if (b == 0xFFFF && a)
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(D_0061B660));
}

// FUNCTION: GAME 0x1FC7C8
extern "C" int *func_001FC7C8(int *p)
{
    __asm__ volatile("sqc2 $vf0,0(%0)\n\tsqc2 $vf0,0x10(%0)" : : "r"(p) : "memory");
    *(short *)(p + 11) = -1;
    p[10] = 0;
    ((char *)p)[0x2E] = 0;
    p[8] = 0;
    p[9] = 0;
    return p;
}

// FUNCTION: GAME 0x1B0290
extern "C" char *func_001B0290(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00428160;
    __asm__ volatile("" : : "r"(t));
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(p) : "memory");
    return p;
}

// FUNCTION: GAME 0x1B24E8
extern "C" char *func_001B24E8(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00428588;
    __asm__ volatile("" : : "r"(t));
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(p) : "memory");
    return p;
}

class cIDBase {
public:
    cIDBase();
    char _p[0x40];
};

// FUNCTION: GAME 0x2A9DC0
cIDBase::cIDBase()
{
    __asm__ volatile("sqc2 $vf0,0x20(%0)\n\tsqc2 $vf0,0x30(%0)" : : "r"(this) : "memory");
    func_002A9DF8(this);
}

// FUNCTION: GAME 0x2717D0
extern "C" void func_002717D0(void *a)
{
    V16 v;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
    func_00271518(a, &v);
    SetEffectPos((eEffDataType)0, (eEffId)11, 0, *(cVec *)&v, 1.0f, -1);
}

class cCollisionSolid {
public:
    cCollisionSolid();
    int m_0, m_4, m_8;
    char _pad[0x30 - 0xC];
    const void *m_30;
};

// FUNCTION: GAME 0x133988
cCollisionSolid::cCollisionSolid()
{
    m_8 = 0;
    m_30 = D_0041D808;
    __asm__ volatile("sqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x20(%0)" : : "r"(this) : "memory");
    int f = m_8;
    m_4 = 0;
    f |= 1;
    m_0 = 0;
    m_8 = f;
}

// FUNCTION: GAME 0x2D4FC0
extern "C" void func_002D4FC0(void *a, int b)
{
    if (b == 0xFFFF && a) {
        V16 *s = Spline;
        for (int i = 3; i != -1; i--) {
            __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(s) : "memory");
            s++;
        }
    }
}

extern "C" void *func_002FBCC8(void *);
extern const char D_00428928[], D_00428C20[], D_004292F0[], D_00429DD8[];
extern const char D_004282F0[], D_0044E238[], D_0044F308[], D_0044F598[], D_0044E538[];

// FUNCTION: GAME 0x1B6710
extern "C" char *func_001B6710(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00428928;
    __asm__ volatile("sqc2 $vf0,0x600(%0)\n\tsqc2 $vf0,0x610(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(int *)(p + 0x620) = 0;
    *(int *)(p + 0x624) = 0;
    return p;
}

// FUNCTION: GAME 0x1B87A8
extern "C" char *func_001B87A8(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00428C20;
    __asm__ volatile("sqc2 $vf0,0x600(%0)\n\tsqc2 $vf0,0x610(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    p[0x630] = 0;
    *(int *)(p + 0x620) = 0;
    return p;
}

// FUNCTION: GAME 0x1BBEB8
extern "C" char *func_001BBEB8(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_004292F0;
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(int *)(p + 0x620) = 0;
    *(int *)(p + 0x634) = 0;
    *(short *)(p + 0x630) = 0;
    *(int *)(p + 0x644) = 0;
    return p;
}
