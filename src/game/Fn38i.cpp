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

extern "C" void func_003823E0(void *, void *, int);

// FUNCTION: GAME 0x3822D0
extern "C" void func_003822D0(unsigned char *o, Fn38U *p, unsigned char c)
{
    unsigned char *t = o + 0x318;
    short *h;
    if (c)
        h = (short *)(t + (t[2] * 2 + 0x22));
    else
        h = (short *)(t + (t[2] * 2 + 0x18));
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

extern "C" void func_00383C70(void *, void *, int);

// FUNCTION: GAME 0x383B60
extern "C" void func_00383B60(unsigned char *o, Fn38U *p, unsigned char c)
{
    unsigned char *t = o + 0x370;
    short *h;
    if (c)
        h = (short *)(t + (t[4] * 2 + 0x26));
    else
        h = (short *)(t + (t[4] * 2 + 0x1C));
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

extern "C" void *memset(void *, int, unsigned);
struct Fn38E70 { short a, id; char p[0x6C]; };
struct Fn38EA0 { short a, id; char p[0x9C]; };
struct Fn38E40 { short a, id; char p[0x3C]; };
struct Fn38EE0 { short a, id; char p[0xDC]; };
extern char D_0076E510[];
extern char D_0076E590[];
extern char D_0076E910[];
extern char D_0076EA50[];
extern char D_0076F050[];
extern char D_00770850[];

// FUNCTION: GAME 0x377D80
extern "C" void func_00377D80(void)
{
    int i;
    memset(D_0076E510, 0, 0x80);
    memset(D_0076E590, 0, 0x380);
    memset(D_0076E910, 0, 0x140);
    for (i = 7; i >= 0; i--)
        ((Fn38E70 *)D_0076E590)[i].id = i;
    for (i = 1; i >= 0; i--)
        ((Fn38EA0 *)D_0076E910)[i].id = i;
}

// FUNCTION: GAME 0x377E28
extern "C" void func_00377E28(void)
{
    int i;
    memset(D_0076EA50, 0, 0x600);
    memset(D_0076F050, 0, 0x1800);
    memset(D_00770850, 0, 0x2A00);
    for (i = 0x5F; i >= 0; i--)
        ((Fn38E40 *)D_0076F050)[i].id = i;
    for (i = 0x2F; i >= 0; i--)
        ((Fn38EE0 *)D_00770850)[i].id = i;
}
