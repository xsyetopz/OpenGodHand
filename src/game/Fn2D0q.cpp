#include "game/cEmManage.h"

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
