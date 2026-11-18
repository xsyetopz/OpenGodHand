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

extern int func_0039EAA8(void *, int);

// FUNCTION: GAME 0x3A1068
void func_003A1068(void *s)
{
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 8);
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 7);
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 0x14);
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 0x16);
    func_0039EAA8(s, 1);
    func_0039EAA8(s, 0x16);
    __asm__ volatile("");
}

struct Rd {
    char _pad[0x154];
    int m_154;
    int m_158;
    int m_15C;
};

// FUNCTION: GAME 0x3A0FD8
void func_003A0FD8(struct Rd *s)
{
    func_0039EAA8(s, 3);
    if (func_0039EAA8(s, 1)) {
        func_0039EAA8(s, 8);
        func_0039EAA8(s, 8);
        s->m_154 = func_0039EAA8(s, 8);
    }
    s->m_158 = func_0039EAA8(s, 0xE);
    func_0039EAA8(s, 1);
    s->m_15C = func_0039EAA8(s, 0xE);
}

// FUNCTION: GAME 0x39EC20
void func_0039EC20(struct Bs *s, unsigned int v)
{
    func_0039ECB8(s);
    v |= 0x40000000;
    *(volatile unsigned int *)0x10002000 = v;
    v &= 0xF0000000;
    s->m_82C = v;
    if (v == 0x20000000 || v == 0x30000000 || v == 0x40000000)
        s->m_828 = 0;
    else
        s->m_828 = 1;
    s->m_848 = func_0039E928(s);
    s->m_84C = 0x20;
}

struct Pq {
    int m_0;
    int m_4;
    int m_8;
    char _pad[0xC0 - 0xC];
    int m_C0;
    char _pad1[0x128 - 0xC4];
    int m_128;
    char _pad2[0x130 - 0x12C];
    int m_130;
    char _pad3[0x184 - 0x134];
    int m_184;
    char _pad4[0x1CC - 0x188];
    int m_1CC;
    char _pad5[0x1DC - 0x1D0];
    int m_1DC;
    char _pad6[0x1EC - 0x1E0];
    int m_1EC;
};
struct Pd {
    char _pad[0x8];
    int m_8;
    char _pad1[0x40 - 0xC];
    struct Pq *m_40;
};
extern char D_0045E5D8[];
extern void func_0039C390(struct Pq *, const char *);
extern void func_0039B130(struct Pq *, int, int);
extern void func_0039B3F0(struct Pq *, int, int, int);

// FUNCTION: GAME 0x39B810
int func_0039B810(struct Pd *d)
{
    struct Pq *s = d->m_40;
    int r = 0;
    if (s->m_4 && s->m_8) {
        int n = s->m_128;
        if (s->m_130) {
            func_0039C390(s, D_0045E5D8);
        } else if (s->m_184 == 3) {
            func_0039B130(s, s->m_1CC, n - 1);
        } else {
            func_0039B3F0(s, s->m_1DC, s->m_1EC, n - 1);
        }
        r = 1;
        s->m_130 = 0;
        d->m_8 = s->m_128 - s->m_C0;
        s->m_4 = 0;
    }
    return r;
}
