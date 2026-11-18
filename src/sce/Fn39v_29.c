// COMPILER: ee-gcc2.9-991111
// SCE small leaf helpers in 0x3951F8-0x3A4AF0.

extern char D_0045E630[];
extern void scePrintf(const char *, ...);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A19D8
// diff: 6 words; ours adds a daddu a0->v1 after mfc1 (5 variants tried)
float func_003A19D8(float x)
{
    union { float f; unsigned int i; } u;
    u.f = x;
    u.i &= 0x7FFFFFFF;
    return u.f;
}
#endif

struct Ctx {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
};

// FUNCTION: GAME 0x39ADA8
void func_0039ADA8(struct Ctx *c, int a, int b)
{
    c->m_4 = b;
    c->m_0 = a;
    c->m_8 = a;
    c->m_C = a;
}

struct Hd {
    char _pad[0x40];
    char *m_40;
};

// FUNCTION: GAME 0x39AA38
void func_0039AA38(struct Hd *h)
{
    *(int *)(h->m_40 + 0x878) = 1;
}

// FUNCTION: GAME 0x39C218
void func_0039C218(int a)
{
    scePrintf(D_0045E630, a);
}

// FUNCTION: GAME 0x3970C8
void func_003970C8(char *p, int n)
{
    while (n--)
        *p++ = 0;
}

extern void func_0039C390(void *, const char *);
extern char D_0045E8B0[];
extern char D_0045E8E0[];
extern char D_0045E8F8[];
extern char D_0045E930[];
extern void func_0039E7C0(void);

// FUNCTION: GAME 0x3A09F0
void func_003A09F0(void *a)
{
    func_0039C390(a, D_0045E8B0);
}

// FUNCTION: GAME 0x3A0A00
void func_003A0A00(void *a)
{
    func_0039C390(a, D_0045E8E0);
}

// FUNCTION: GAME 0x3A0BF8
void func_003A0BF8(void *a)
{
    func_0039C390(a, D_0045E8F8);
}

// FUNCTION: GAME 0x3A0C08
void func_003A0C08(void *a)
{
    func_0039C390(a, D_0045E930);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3A0DE8
// diff: 8 words, register numbering only (v0/v1/a0/a1 order; 4 variants tried)
void func_003A0DE8(void)
{
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000)
        func_0039E7C0();
}
#endif
