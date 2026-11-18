// FUNCTION: GAME 0x2A9C98
// DIVNOP: 1
extern "C" float func_002A9C98(float *p)
{
    float r = 0.0f;
    float d = p[0];
    if (d != r)
        r = p[1] / d;
    return r;
}

extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void func_002AA2D0(void *, int, void *);

// FUNCTION: GAME 0x2AA3D8
extern "C" void func_002AA3D8(void *self, int n)
{
    char *w = (char *)getIDWork__7cIDBasei(self, n);
    if (w)
        func_002AA2D0(self, *(int *)(w + 0x1C), w);
}

struct VcObj { char _p[0x18]; short m_18; short _q; void (*m_1C)(void *); };
struct VcHold { int m_0; int _4[5]; VcObj *m_18; };

struct OffTab { int _0; int m_4; int _8[3]; int m_14; };

// FUNCTION: GAME 0x2A9860
extern "C" int func_002A9860(OffTab *self, int off)
{
    int base;
    if (off) {
        base = self->m_4;
        int v = *(int *)(off + base + 4);
        if (!v)
            return 0;
        return v - base;
    }
    if (!self->m_14)
        return 0;
    return self->m_14 - self->m_4;
}

// DRAFT: GAME 0x2ABD30 - 11 words differ: original computes slti+andi before the branch; ours folds it
#ifdef NONMATCHING
extern "C" void func_002ABD30(int, char *o)
{
    char *c = *(char **)(o + 0x1C);
    short n = *(short *)(c + 0x214);
    *(short *)(o + 0xA6) = 0;
    if (c[0x5F] == 0) {
        if ((unsigned char)(n < 2))
            *(int *)(o + 0x2C) |= 0x800;
        else
            *(int *)(o + 0x2C) &= ~0x800;
    }
}
#endif

// DRAFT: GAME 0x2ABD78 - 11 words differ: original computes slti+andi before the branch; ours folds it
#ifdef NONMATCHING
extern "C" void func_002ABD78(int, char *o)
{
    char *c = *(char **)(o + 0x1C);
    short n = *(short *)(c + 0x278);
    *(short *)(o + 0xA8) = 0;
    if (c[0x64] == 0) {
        if ((unsigned char)(n < 2))
            *(int *)(o + 0x2C) |= 0x400;
        else
            *(int *)(o + 0x2C) &= ~0x400;
    }
}
#endif

struct LsNode { char _p[8]; LsNode *m_8; char _q[0x20]; unsigned char m_2C; };
struct LsHold { char _p[0x10]; LsNode *m_10; };
extern "C" void func_002B2400(LsNode *);

// FUNCTION: GAME 0x2AEDF0
extern "C" void func_002AEDF0(LsHold *self, int t)
{
    for (LsNode *n = self->m_10; n; n = n->m_8) {
        if (n->m_2C == (unsigned char)t)
            func_002B2400(n);
    }
}

struct OffEnt { int m_0; int m_4; };

// FUNCTION: GAME 0x2ACD78
extern "C" char *func_002ACD78(OffEnt *tab, int idx, unsigned n)
{
    char *p;
    if (idx == 0x21 || !n || !(p = *(char **)((int)tab + (idx << 3))) || *(unsigned *)p < n)
        return 0;
    int v = *(int *)(p + n * 4);
    return v ? (char *)(v + (int)p) : 0;
}

extern "C" int isPageEndCode__11cMessCommonUs(unsigned short);

// FUNCTION: GAME 0x2AF068
extern "C" int func_002AF068(unsigned short c)
{
    if (!(c >> 15))
        return 0;
    if (isPageEndCode__11cMessCommonUs(c))
        return 1;
    return (c & 0xFF00) == 0xA000;
}

extern char Sys[];

// DRAFT: GAME 0x2A4ED8 - 18 words differ: original rebuilds the Sys base address (lui/addiu) and keeps it in a2
#ifdef NONMATCHING
extern "C" void func_002A4ED8(char *self)
{
    char *b = self + 0x28000;
    *(int *)(b + 0x2054) = (int)self + ((*(unsigned *)(Sys + 0x210) & 1) * 0x15000 + 0x50);
    *(int *)(b + 0x2058) = (int)self + ((*(unsigned *)(Sys + 0x210) & 1) * 0x15000 + 0x50) + 0x15000;
}
#endif

// DRAFT: GAME 0x2A58D8 - 12 words differ (switch, || , ?:, struct forms tried; best is the || form): original branches s==4 and s==6 to separate stores and keeps -1 as lui/ori
#ifdef NONMATCHING
extern "C" void func_002A58D8(char *self, unsigned v)
{
    if (v == 0xFFFFFFFF) {
        char *b = self + 0x28000;
        int s = *(int *)(b + 0x2060);
        if (s == 4 || s == 6)
            *(int *)(b + 0x2064) = 2;
        else
            *(int *)(b + 0x2064) = 1;
    } else
        *(unsigned *)(self + 0x28000 + 0x2064) = v;
}
#endif

// FUNCTION: GAME 0x2A73F0
extern "C" int func_002A73F0(char *self)
{
    int *q = (int *)(self + 0x520);
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    *(short *)(self + 0x570) = -1;
    *(float *)(self + 0x5A8) = 1.0f;
    *(int *)(self + 0x5A0) = 0;
    *(short *)(self + 0x548) = 0;
    *(short *)(self + 0x54A) = 0;
    *(int *)(self + 0x54C) = 0;
    *(int *)(self + 0x254) |= 0x8000000;
    *(float *)(self + 0x3A8) = 1.0f;
    *(int *)(self + 0x574) = 2;
    return 1;
}

extern "C" void func_002A94F0(int *);

// FUNCTION: GAME 0x2A9498
extern "C" void func_002A9498(int *self, int a, int b, int c)
{
    if (!a || !b) {
        self[0] = 0;
        self[1] = 0;
    } else {
        self[0] = a;
        self[1] = b;
        func_002A94F0(self);
    }
    self[2] = c;
}

struct FlNode { char _p[0x20]; FlNode *m_20; };

// FUNCTION: GAME 0x2AA598
extern "C" void func_002AA598(int self, FlNode *n, int on)
{
    char *c = *(char **)((char *)n + 0x20);
    if (c) {
        int t = on ^ 1;
        if (t)
            *(unsigned *)(c + 0x2C) |= 0x20000000;
        else
            *(unsigned *)(c + 0x2C) &= 0xDFFFFFFF;
        func_002AA598(self, n->m_20, on);
    }
}

extern "C" void func_002A4ED8(char *);
extern "C" void Moji_size_set__FUcUc(unsigned char, unsigned char);
extern "C" void printf__FiiiiPCce(int, int, int, int, const char *, ...);
extern char D_0044ACF0[];

// FUNCTION: GAME 0x2A4DF8
extern "C" void func_002A4DF8(char *self)
{
    func_002A4ED8(self);
    Moji_size_set__FUcUc(0, 0);
    printf__FiiiiPCce(0x28, 0x12C, 0, 6, D_0044ACF0, *(int *)(self + 0x28000 + 0x208C));
}

struct DlLink { DlLink *m_0; DlLink *m_4; };
struct DlHead { int _0; int m_4; int _8[2]; DlLink *m_10; DlLink *m_14; };

// FUNCTION: GAME 0x2A9800
extern "C" void func_002A9800(DlHead *h, int off)
{
    if (off) {
        DlLink *n = (DlLink *)(off + h->m_4);
        if (n->m_0)
            n->m_0->m_4 = n->m_4;
        else
            h->m_14 = n->m_4;
        if (n->m_4) {
            n->m_4->m_0 = n->m_0;
            n->m_0 = 0;
        } else
            n->m_0 = 0;
        DlLink *o = h->m_10;
        n->m_4 = o;
        if (o)
            o->m_0 = n;
        h->m_10 = n;
    }
}
