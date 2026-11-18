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
