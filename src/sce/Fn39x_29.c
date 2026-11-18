// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x39A000-0x3A4AF0 (continuation of Fn39v_29.c).

struct Dv {
    char _pad[0x40];
    char *m_40;
};
extern void func_0039A140(struct Dv *);

// FUNCTION: GAME 0x39A9A8
void func_0039A9A8(struct Dv *d, unsigned int a, int b)
{
    char *p = d->m_40;
    *(int *)(p + 0xC4) = 1;
    *(unsigned int *)(p + 0xEC) = (a & 0xFFFFFFF) | 0x20000000;
    *(int *)(p + 0xF8) = b;
    *(int *)(p + 0xF4) = 0;
    *(int *)(p + 0xF0) = 0;
    func_0039A140(d);
    __asm__ volatile("");
}

// FUNCTION: GAME 0x39A9F0
void func_0039A9F0(struct Dv *d, unsigned int a, int b)
{
    char *p = d->m_40;
    *(int *)(p + 0xF8) = b;
    *(unsigned int *)(p + 0xEC) = (a & 0xFFFFFFF) | 0x20000000;
    *(int *)(p + 0xC4) = 0;
    *(int *)(p + 0xF4) = 0;
    *(int *)(p + 0xF0) = 0;
    func_0039A140(d);
    __asm__ volatile("");
}

extern void func_0039A720(struct Dv *);
extern void func_0039A5B0(struct Dv *);

#ifdef NONMATCHING
// DRAFT: GAME 0x39AC10
// diff: 7 words, register numbering only (a3/v1 vs a1/v1/a0; 8 variants tried)
void func_0039AC10(struct Dv *d)
{
    struct Q { char _p[0x184]; int m_184; } *q = (struct Q *)d->m_40;
    if (q->m_184 != 3) {
        func_0039A720(d);
        __asm__ volatile("");
    } else {
        func_0039A5B0(d);
        __asm__ volatile("");
    }
}
#endif

struct Bs {
    char _pad[0x828];
    int m_828;
    int m_82C;
    char _pad2[0x848 - 0x830];
    unsigned int m_848;
    int m_84C;
};
extern void func_0039ECB8(struct Bs *);
extern long func_0039E928(struct Bs *);

// FUNCTION: GAME 0x39EB90
unsigned int func_0039EB90(struct Bs *s, int n)
{
    if (s->m_828 || s->m_84C < n) {
        func_0039ECB8(s);
        *(volatile unsigned int *)0x10002000 = 0x40000000;
        s->m_828 = 0;
        s->m_82C = 0x40000000;
        s->m_848 = func_0039E928(s);
        s->m_84C = 0x20;
    }
    return s->m_848 >> -n;
}

extern void func_003A0DE8(void);
extern void func_003A0E20(int, int);

// FUNCTION: GAME 0x3A0F88
void func_003A0F88(int d)
{
    int r;
    func_003A0DE8();
    r = -(*(volatile unsigned int *)0x10002020 & 7) & 7;
    if (r)
        func_003A0E20(d, r);
}
