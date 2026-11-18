#include "game/cEmManage.h"
#include "game/ESLibFn.h"

// Scroll layer setters and player-state callbacks (0x2DB000-0x2DCD00).
struct ScrObjQ {
    char _p0[0x240];
    float m_240, m_244, m_248, m_24c;
    unsigned m_250;
    char _p1[0x2FD - 0x254];
    unsigned char m_2fd;
    char _p2[0x310 - 0x2FE];
    float m_310, m_314, m_318, m_31c;
};
struct ScrVecQ {
    int m_0;
    ScrObjQ **m_4;
    ScrObjQ **m_8;
};
extern ScrVecQ *volatile scrArray;

// DRAFT: GAME 0x2DB318
// diff: 2 words, original fills the bnel slot with the scrArray reload and branches past it; ours emits bne plus nop
#ifdef NONMATCHING
void setAlphaScrollLayer(unsigned id, float a)
{
    ScrVecQ *s = scrArray;
    ScrObjQ **p = s->m_4;
    if (p == s->m_8)
        return;
    do {
        if (id == (*p)->m_2fd) {
            (*p)->m_24c = a;
            (*p)->m_31c = a;
        }
        p++;
    } while (p != scrArray->m_8);
}
#endif

// DRAFT: GAME 0x2DB370
// diff: 2 words, original fills the bnel slot with the scrArray reload and branches past it; ours emits bne plus nop
#ifdef NONMATCHING
void setColorScrollLayer(unsigned id, float r, float g, float b)
{
    ScrVecQ *s = scrArray;
    ScrObjQ **p = s->m_4;
    if (p == s->m_8)
        return;
    do {
        if (id == (*p)->m_2fd) {
            (*p)->m_240 = r;
            (*p)->m_244 = g;
            (*p)->m_248 = b;
            (*p)->m_310 = r;
            (*p)->m_314 = g;
            (*p)->m_318 = b;
        }
        p++;
    } while (p != scrArray->m_8);
}
#endif

// DRAFT: GAME 0x2DB2B0
// diff: 2 words, original fills the bnel slot with the scrArray reload and branches past it; ours emits bne plus nop
#ifdef NONMATCHING
void displayScrollLayer(unsigned id, bool on)
{
    ScrVecQ *s = scrArray;
    ScrObjQ **p = s->m_4;
    if (p == s->m_8)
        return;
    do {
        if (id == (*p)->m_2fd) {
            if (on)
                (*p)->m_250 &= 0xFFFFFFFD;
            else
                (*p)->m_250 |= 2;
        }
        p++;
    } while (p != scrArray->m_8);
}
#endif

struct PlrQ {
    char _p[0x54A];
    short m_54a;
};
PlrQ *Getplayer();
extern "C" int func_0010B698(PlrQ *);
#define PQ(s, o, T) (*(T *)((char *)(s) + (o)))

#define PSTATE_B(NAME, ID)                                                                        \
    extern "C" void NAME()                                                                        \
    {                                                                                             \
        PlrQ *q = Getplayer();                                                                    \
        if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 ||                     \
            g_EmManage.CkPlCatched())                                                             \
            return;                                                                               \
        PQ(q, 0x2F4, char) = 0;                                                                   \
        PQ(q, 0x2F5, char) = ID;                                                                  \
        PQ(q, 0x2F6, char) = 0;                                                                   \
        PQ(q, 0x2F7, char) = 0;                                                                   \
    }

// FUNCTION: GAME 0x2DCA58
PSTATE_B(func_002DCA58, 0x31)
// FUNCTION: GAME 0x2DCCD0
PSTATE_B(func_002DCCD0, 0x32)

// FUNCTION: GAME 0x2DC898
extern "C" void func_002DC898(int arg)
{
    PlrQ *q = Getplayer();
    if (q->m_54a <= 0 || func_0010B698(q) || g_EmManage.m_slotWait > 0 || g_EmManage.CkPlCatched())
        return;
    PQ(q, 0x694, int) = arg;
    PQ(q, 0x2F5, char) = 0x44;
    PQ(q, 0x2F4, char) = 0;
    PQ(q, 0x2F6, char) = 0;
    PQ(q, 0x2F7, char) = 0;
}

float capVu0MagnitudeSqXZ(const float *, const float *);
float Turn_dest(const float *, float, const float *, float);

// DRAFT: GAME 0x2DB7E0
// diff: 24 words, original keeps the Turn_dest result in f1 and fabs-selects into f2 with a mov.s in the bc1f slot; ours copies zero into f1
#ifdef NONMATCHING
extern "C" int func_002DB7E0(const float *arg)
{
    PlrQ *q = Getplayer();
    float m = capVu0MagnitudeSqXZ(PQ(q, 0xF0, const float *), arg);
    if (2.0f < m)
        return 0;
    if (m < 0.5f)
        return 1;
    float t = Turn_dest(PQ(q, 0xF0, const float *), PQ(q, 0x104, float), arg, 3.1415927f);
    float a;
    if (t < 0.0f)
        a = -t;
    else
        a = t;
    return a < 0.2617994f;
}
#endif

struct ObjQ { char _p[0x2FE]; unsigned short m_2fe; };
struct ObjVecQ { int m_0; ObjQ **m_4; ObjQ **m_8; };
extern ObjVecQ *volatile objbaseArray;
extern "C" int func_001B8030(ObjQ *);

// DRAFT: GAME 0x2DDDF8
// diff: 37 words, range test (v>=0x300 ? v<0x500 : 0) compiles to movn form, not slti/xori/andi; same idiom as unmatched 0x1B8030
#ifdef NONMATCHING
int getItemNumInRoom()
{
    int n = 0;
    ObjVecQ *s = objbaseArray;
    ObjQ **p = s->m_4;
    if (p == s->m_8)
        return 0;
    do {
        ObjQ *o = *p;
        int v = o->m_2fe;
        int in = v >= 0x300 ? v < 0x500 : 0;
        if ((unsigned char)in) {
            if (!func_001B8030(o))
                n++;
        }
        p++;
    } while (p != objbaseArray->m_8);
    return n;
}
#endif

struct QvQ { float f[4]; };
struct VecQ { float x, y, z, w; };
extern int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(const VecQ &, const VecQ &, VecQ *, VecQ *, unsigned, unsigned, void *, unsigned, unsigned *, void *, unsigned, unsigned, bool);

static inline void cpvQ(VecQ *d, const VecQ *s, float y)
{
    if (d != s) {
        float x = s->x;
        float z = s->z;
        d->x = x;
        d->z = z;
        d->y = y;
    }
}

// FUNCTION: GAME 0x2DDD18
extern "C" float func_002DDD18(VecQ *pos)
{
    VecQ a, b, c;
    VecQ *pa = &a;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(QvQ *)pa));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(QvQ *)&b));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(QvQ *)&c));
    float y = pos->y;
    cpvQ(pa, pos, y);
    if (&b != pos) {
        b.x = pos->x;
        b.y = pos->y;
        b.z = pos->z;
    }
    a.y += 0.5f;
    b.y -= 20.0f;
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(a, b, &c, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1)
        y = c.y;
    return y;
}

struct SlotQ { char _p[0xC]; unsigned short m_c; char _p2[0x58 - 0xE]; };
struct SlotSetQ { SlotQ *m_0; char _p[8]; unsigned short m_c; };

// FUNCTION: GAME 0x2D5B30
extern "C" int func_002D5B30(SlotSetQ *self, int idx)
{
    if (idx < 0) {
        for (idx = 2; idx < self->m_c; idx++) {
            if (self->m_0[idx].m_c == 0)
                return idx;
        }
        return -1;
    }
    if (idx < self->m_c)
        return self->m_0[idx].m_c == 0 ? idx : -1;
    return -1;
}

struct EntQ { unsigned short m_0; unsigned short _p; int m_4, m_8, m_c, m_10, m_14; };
extern EntQ D_003C3138[];
extern EntQ D_003C3120;

// DRAFT: GAME 0x2D0B88
// diff: 31 words, original keeps the last match via beql plus daddu in the slot; ours emits xor/movz
#ifdef NONMATCHING
extern "C" EntQ *func_002D0B88(unsigned id)
{
    unsigned short key = id;
    EntQ *r = 0;
    EntQ *p = D_003C3138;
    do {
        if (p->m_0 == key)
            r = p;
        p++;
    } while (p < D_003C3138 + 44);
    if (!r) {
        unsigned hi = key >> 8;
        int v = (unsigned char)(hi - 1) > 7 ? 2 : hi + 1;
        r = &D_003C3120;
        r->m_0 = key;
        r->m_4 = v;
        r->m_8 = v;
        r->m_c = v;
        r->m_10 = v;
        r->m_14 = v;
    }
    return r;
}
#endif

extern unsigned D_00747A84;

// FUNCTION: GAME 0x2D8E18
extern "C" void func_002D8E18(char *self, int a1, short a2)
{
    if (!(*(unsigned *)(self + 0x16284) & 0x10)) {
        short v = (D_00747A84 & 0x20000000) ? 0 : a2;
        *(char *)(self + 0x16168) = a1;
        *(short *)(self + 0x16280) = 0;
        *(short *)(self + 0x16282) = v;
        if (v <= 0)
            *(float *)(self + 0x1616C) = 1.0f;
        else
            *(int *)(self + 0x1616C) = 0;
        *(unsigned *)(self + 0x16284) = (*(unsigned *)(self + 0x16284) | 0x10) & ~0x20u;
    }
}

extern "C" int func_002D3210(char *);

// FUNCTION: GAME 0x2D2EE8
extern "C" int func_002D2EE8(char *self, int key)
{
    if (key == 0)
        return 1;
    char *first = *(char **)self;
    if (first == 0)
        return 1;
    if (*(int *)(first + 0x80) == key)
        return 0;
    char *p = self + 0x40;
    for (int i = 0; i < 16; i++, p += 0xC0) {
        if (func_002D3210(p) && *(int *)(p + 0x80) == key)
            return 0;
    }
    return 1;
}
