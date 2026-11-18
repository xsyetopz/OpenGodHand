// Mid-size functions in the ProDG game-code island 0x370000-0x387430 (continued from Fn38h.cpp).

struct Fn38V { char _p0[0x20]; int m_20; char _p24[0xC]; void *m_30; };
struct Fn38U { char _p0[0x38]; unsigned m_38; };
extern "C" void func_0032A8C0(void *, int);

// FUNCTION: GAME 0x383EB0
extern "C" void func_00383EB0(char *o, Fn38U *p)
{
    Fn38V *s = (Fn38V *)(o + 0x3A4);
    if (p->m_38 & 0x8000) {
        int v = s->m_20;
        if (v < -14)
            s->m_20 = 15;
        else
            s->m_20 = v - 1;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
    if (p->m_38 & 0x2000) {
        int v = s->m_20;
        if (v < 15)
            s->m_20 = v + 1;
        else
            s->m_20 = -15;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
}

// FUNCTION: GAME 0x385410
extern "C" void func_00385410(char *o, Fn38U *p)
{
    Fn38V *s = (Fn38V *)(o + 0x484);
    if (p->m_38 & 0x8000) {
        int v = s->m_20;
        if (v < -14)
            s->m_20 = 15;
        else
            s->m_20 = v - 1;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
    if (p->m_38 & 0x2000) {
        int v = s->m_20;
        if (v < 15)
            s->m_20 = v + 1;
        else
            s->m_20 = -15;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
}

// FUNCTION: GAME 0x3813C8
extern "C" void func_003813C8(unsigned char *o, Fn38U *p)
{
    Fn38V *s = (Fn38V *)(o + o[5] * 0x48 + 0x58);
    if (p->m_38 & 0x8000) {
        int v = s->m_20;
        if (v < -14)
            s->m_20 = 15;
        else
            s->m_20 = v - 1;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
    if (p->m_38 & 0x2000) {
        int v = s->m_20;
        if (v < 15)
            s->m_20 = v + 1;
        else
            s->m_20 = -15;
        if (s->m_30)
            func_0032A8C0(s->m_30, s->m_20);
    }
}

struct Fn38T { char _p0[0x30]; void *m_30; };
extern "C" void func_0032A6D0(void *, int, int);

// FUNCTION: GAME 0x3812B0
extern "C" void func_003812B0(unsigned char *o, Fn38U *p, unsigned char c)
{
    unsigned char *b = o + (o[5] * 0x48 + 0x48);
    Fn38T *t = (Fn38T *)(b + 0x10);
    short *h;
    int idx;
    if (c) {
        h = (short *)(b + 0xA);
        idx = 1;
    } else {
        h = (short *)(b + 8);
        idx = 0;
    }
    if (p->m_38 & 0x8000) {
        if (*h == -0x80)
            *h = 15;
        else if (*h >= -14)
            *h = *h - 1;
        else
            *h = -0x80;
        if (t->m_30)
            func_0032A6D0(t->m_30, idx, *h);
    }
    if (p->m_38 & 0x2000) {
        if (*h == -0x80)
            *h = -15;
        else if (*h < 15)
            *h = *h + 1;
        else
            *h = -0x80;
        if (t->m_30)
            func_0032A6D0(t->m_30, idx, *h);
    }
}

// FUNCTION: GAME 0x385308
extern "C" void func_00385308(unsigned char *o, Fn38U *p, unsigned char c)
{
    Fn38T *t = (Fn38T *)(o + 0x484);
    short *h;
    int idx;
    if (c) {
        h = (short *)(o + 0x47A);
        idx = 1;
    } else {
        h = (short *)(o + 0x478);
        idx = 0;
    }
    if (p->m_38 & 0x8000) {
        if (*h == -0x80)
            *h = 15;
        else if (*h >= -14)
            *h = *h - 1;
        else
            *h = -0x80;
        if (t->m_30)
            func_0032A6D0(t->m_30, idx, *h);
    }
    if (p->m_38 & 0x2000) {
        if (*h == -0x80)
            *h = -15;
        else if (*h < 15)
            *h = *h + 1;
        else
            *h = -0x80;
        if (t->m_30)
            func_0032A6D0(t->m_30, idx, *h);
    }
}

#ifdef NONMATCHING
extern "C" void func_003823E0(void *, void *, int);

// DRAFT: GAME 0x3822D0
// diff: 8 words; join computes offset in v1 and adds later (original reloads lbu per branch, addu at join)
extern "C" void func_003822D0(unsigned char *o, Fn38U *p, unsigned char c)
{
    unsigned char *t = o + 0x318;
    int k;
    if (c)
        k = t[2] * 2 + 0x22;
    else
        k = t[2] * 2 + 0x18;
    short *h = (short *)(t + k);
    if (p->m_38 & 0x8000) {
        if (*h == -0x80)
            *h = 15;
        else if (*h >= -14)
            *h = *h - 1;
        else
            *h = -0x80;
        func_003823E0(o, t, c);
    }
    if (p->m_38 & 0x2000) {
        if (*h == -0x80)
            *h = -15;
        else if (*h < 15)
            *h = *h + 1;
        else
            *h = -0x80;
        func_003823E0(o, t, c);
    }
}
#endif

#ifdef NONMATCHING
extern "C" void func_00383C70(void *, void *, int);

// DRAFT: GAME 0x383B60
// diff: 8 words; join computes offset in v1 and adds later (original reloads lbu per branch, addu at join)
extern "C" void func_00383B60(unsigned char *o, Fn38U *p, unsigned char c)
{
    unsigned char *t = o + 0x370;
    int k;
    if (c)
        k = t[4] * 2 + 0x26;
    else
        k = t[4] * 2 + 0x1C;
    short *h = (short *)(t + k);
    if (p->m_38 & 0x8000) {
        if (*h == -0x80)
            *h = 15;
        else if (*h >= -14)
            *h = *h - 1;
        else
            *h = -0x80;
        func_00383C70(o, t, c);
    }
    if (p->m_38 & 0x2000) {
        if (*h == -0x80)
            *h = -15;
        else if (*h < 15)
            *h = *h + 1;
        else
            *h = -0x80;
        func_00383C70(o, t, c);
    }
}
#endif
