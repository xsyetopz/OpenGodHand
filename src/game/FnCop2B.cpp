// Second half of FnCop2 (split to keep files under 300 lines).
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
extern "C" void *func_002FBCC8(void *);
extern const char D_00428928[], D_00428C20[], D_004292F0[], D_00429DD8[];
extern const char D_004282F0[], D_0044E238[], D_0044F308[], D_0044F598[], D_0044E538[];
extern char D_005686D0[];
enum eEffDataType { };
enum eEffId { };
class cObj;
extern void SetEffectPos(eEffDataType, eEffId, cObj *, const cVec &, float, int);

// FUNCTION: GAME 0x1C7D98
extern "C" char *func_001C7D98(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00429DD8;
    __asm__ volatile("sqc2 $vf0,0x610(%0)\n\tsqc2 $vf0,0x630(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(int *)(p + 0x5B0) |= 8;
    return p;
}

// FUNCTION: GAME 0x2FFAD0
extern "C" char *func_002FFAD0(char *p)
{
    if (p) {
        void *t = (void *)func_002FBCC8(p);
        *(const void **)(p + 0xF0) = D_0044E238;
        __asm__ volatile("" : : "r"(t));
        __asm__ volatile("sqc2 $vf0,0x2B0(%0)" : : "r"(p) : "memory");
    }
    return p;
}

// FUNCTION: GAME 0x2FFF10
extern "C" char *func_002FFF10(char *p)
{
    if (p) {
        void *t = (void *)func_002FBCC8(p);
        *(const void **)(p + 0xF0) = D_0044F308;
        __asm__ volatile("" : : "r"(t));
        __asm__ volatile("sqc2 $vf0,0x2D0(%0)" : : "r"(p) : "memory");
    }
    return p;
}

// FUNCTION: GAME 0x2FFFE0
extern "C" char *func_002FFFE0(char *p)
{
    if (p) {
        void *t = (void *)func_002FBCC8(p);
        *(const void **)(p + 0xF0) = D_0044F598;
        __asm__ volatile("" : : "r"(t));
        __asm__ volatile("sqc2 $vf0,0x2B0(%0)" : : "r"(p) : "memory");
    }
    return p;
}

// FUNCTION: GAME 0x2FFB38
extern "C" char *func_002FFB38(char *p)
{
    if (p) {
        void *t = (void *)func_002FBCC8(p);
        *(const void **)(p + 0xF0) = D_0044E538;
        __asm__ volatile("" : : "r"(t));
        __asm__ volatile("sqc2 $vf0,0x2C0(%0)" : : "r"(p) : "memory");
        *(int *)(p + 0x2B0) = 0;
    }
    return p;
}

// FUNCTION: GAME 0x1B0CE8
extern "C" char *func_001B0CE8(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_004282F0;
    __asm__ volatile("sqc2 $vf0,0x610(%0)\n\tsqc2 $vf0,0x620(%0)\n\tsqc2 $vf0,0x640(%0)\n\tsqc2 $vf0,0x650(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    return p;
}

// FUNCTION: GAME 0x1FC758
extern "C" void func_001FC758(void *a, int b)
{
    if (b == 0xFFFF && a) {
        char *s = D_005686D0;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(char (*)[16])(s + 0x190)));
        char *q = s + 0x28A;
        for (int i = 0x7F; i != -1; i--) {
            q[4] = 0;
            q += 0x10;
        }
        *(int *)(s + 0xB8C) = 0;
    }
}

extern const char D_0044EF08[];
extern "C" void *func_0028EB00(void *);
extern "C" void *func_002FBCC8(void *);
extern const char D_00447B88[], D_00447BA0[], D_00447CB0[], D_00447D48[], D_00447E50[], D_00447E68[], D_004480E0[], D_004481A8[], D_004484B0[], D_00448598[], D_004486A0[], D_00448788[];
extern "C" void *func_001B6E90(void *);
extern "C" void func_0016F640(void *, int);
extern const char D_0044A408[], D_00448F30[], D_00427400[];
extern char D_003BD8D0[], D_004A6D80[];

// FUNCTION: GAME 0x2772A8
extern "C" char *func_002772A8(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_00447BA0;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_00447B88;
    return p;
}

// FUNCTION: GAME 0x278068
extern "C" char *func_00278068(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_00447D48;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)\n\tsqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x15A0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_00447CB0;
    return p;
}

// FUNCTION: GAME 0x279CE8
extern "C" char *func_00279CE8(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_00447E68;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)\n\tsqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x15A0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_00447E50;
    return p;
}

// FUNCTION: GAME 0x27B768
extern "C" char *func_0027B768(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_004481A8;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)\n\tsqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x15A0(%0)\n\tsqc2 $vf0,0x15C0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_004480E0;
    return p;
}

// FUNCTION: GAME 0x27EE68
extern "C" char *func_0027EE68(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_00448598;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)\n\tsqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x15A0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_004484B0;
    return p;
}

// FUNCTION: GAME 0x281638
extern "C" char *func_00281638(char *p)
{
    void *t = func_0028EB00(p);
    *(const void **)(p + 0x214) = D_00448788;
    __asm__ volatile("sqc2 $vf0,0x1530(%0)\n\tsqc2 $vf0,0x1540(%0)\n\tsqc2 $vf0,0x1550(%0)\n\tsqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x15A0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    *(const void **)(p + 0x4AC) = D_004486A0;
    return p;
}

// FUNCTION: GAME 0x2FFDC8
extern "C" char *func_002FFDC8(char *p)
{
    if (p) {
        void *t = func_002FBCC8(p);
        *(const void **)(p + 0xF0) = D_0044EF08;
        __asm__ volatile("" : : "r"(t));
        __asm__ volatile("sqc2 $vf0,0x2C0(%0)\n\tsqc2 $vf0,0x2E0(%0)" : : "r"(p) : "memory");
    }
    return p;
}

// FUNCTION: GAME 0x1574F0
extern "C" void func_001574F0(void *a, int b)
{
    if (b == 0xFFFF && a) {
        __asm__ volatile("lqc2 $vf4,0x0(%1)\n\tlqc2 $vf5,0x10(%1)\n\tlqc2 $vf6,0x20(%1)\n\tlqc2 $vf7,0x30(%1)\n\t"
                         "sqc2 $vf4,0x0(%0)\n\tsqc2 $vf5,0x10(%0)\n\tsqc2 $vf6,0x20(%0)\n\tsqc2 $vf7,0x30(%0)"
                         : : "r"(D_004A6D80), "r"(D_003BD8D0) : "memory");
    }
}

// FUNCTION: GAME 0x28B0F0
extern "C" char *func_0028B0F0(char *p)
{
    void *t = func_0028EB00(p);
    unsigned char *q = (unsigned char *)p + 0x1510;
    *(const void **)(p + 0x214) = D_0044A408;
    __asm__ volatile("sqc2 $vf0,0x1520(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    q[0x31] = 0xFF;
    __asm__ volatile("sqc2 $vf0,0x1590(%0)\n\tsqc2 $vf0,0x1610(%0)" : : "r"(p) : "memory");
    *(const void **)(p + 0x4AC) = D_00448F30;
    return p;
}

// FUNCTION: GAME 0x1A5FD8
extern "C" char *func_001A5FD8(char *p)
{
    void *t = func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00427400;
    __asm__ volatile("sqc2 $vf0,0x610(%0)\n\tsqc2 $vf0,0x620(%0)" : : "r"(p) : "memory");
    char *q = p + 0x630;
    __asm__ volatile("sqc2 $vf0,0x630(%0)\n\tsqc2 $vf0,0x640(%0)\n\tsqc2 $vf0,0x650(%0)\n\tsqc2 $vf0,0x660(%0)\n\tsqc2 $vf0,0x670(%0)" : : "r"(p) : "memory");
    __asm__ volatile("" : : "r"(t));
    func_0016F640(q, 0);
    return p;
}
