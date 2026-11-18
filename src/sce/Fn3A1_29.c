// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x3A0000-0x3B0000.

struct Cl {
    char _pad[0x24];
    int m_24;
};
extern struct Cl D_0077C900;
extern char D_0045E998[];
extern int D_003FA300;
extern int D_003FA304;
extern void sceSifInitRpc(int);
extern int sceSifBindRpc(struct Cl *, unsigned int, int);
extern int scePrintf(const char *, ...);
extern void FlushCache(int);
extern int func_0039EAA8(void *, int);
extern void func_003A0DE8(void *);
extern void func_0039C390(void *, const char *);
extern char D_0045E858[];
extern char D_0045E880[];

struct Rv {
    char _pad[0x14C];
    int m_14C;
    char _pad1[0x184 - 0x150];
    int m_184;
    int m_188;
    char _pad2[0x194 - 0x18C];
    int m_194;
    char _pad3[0x19C - 0x198];
    int m_19C[3];
    int m_1A8[3];
};

// FUNCTION: GAME 0x3A1100
void func_003A1100(struct Rv *s)
{
    int n, i;
    if (s->m_14C) {
        if (s->m_194 == 0)
            goto one;
        n = s->m_188 ? 3 : 2;
    } else if (s->m_184 != 3) {
one:
        n = 1;
    } else {
        n = s->m_194 ? s->m_184 : 2;
    }
    for (i = 0; i < n; i++) {
        s->m_19C[i] = func_0039EAA8(s, 0x10);
        func_0039EAA8(s, 1);
        s->m_1A8[i] = func_0039EAA8(s, 0x10);
        func_0039EAA8(s, 1);
    }
}

struct Rw {
    char _pad[0x828];
    int m_828;
    int m_82C;
    char _pad1[0x850 - 0x830];
    int m_850;
    int m_854;
};

// FUNCTION: GAME 0x3A0908
void func_003A0908(struct Rw *s)
{
    if ((s->m_850 = func_0039EAA8(s, 1)) != 0) {
        func_003A0DE8(s);
        *(volatile unsigned int *)0x10002000 = 0x50000000;
        s->m_82C = 0x50000000;
        s->m_828 = 1;
        func_003A0DE8(s);
    }
    if ((s->m_854 = func_0039EAA8(s, 1)) != 0) {
        func_003A0DE8(s);
        *(volatile unsigned int *)0x10002000 = 0x58000000;
        s->m_82C = 0x50000000;
        s->m_828 = 1;
        func_003A0DE8(s);
    }
    if (func_0039EAA8(s, 1))
        func_0039C390(s, D_0045E858);
    if (func_0039EAA8(s, 1))
        func_0039C390(s, D_0045E880);
}

// FUNCTION: GAME 0x3A11F8
int func_003A11F8(void)
{
    int i;
    sceSifInitRpc(0);
    do {
        if (sceSifBindRpc(&D_0077C900, 0x80000701, 0) < 0) {
            scePrintf(D_0045E998);
            return -1;
        }
        i = 10000;
        do {
            i--;
            __asm__ volatile("nop");
        } while (i != -1);
    } while (D_0077C900.m_24 == 0);
    D_003FA300 = 0;
    D_003FA304 = 0;
    FlushCache(0);
    return 0;
}

extern int func_003A3768(float *);
extern float func_003A3C80(float, float);
extern float func_003A4728(float, float, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A18F0
// diff: 4 words, addiu sp scheduled after the lui/ori pair (9 variants tried)
float cosf(float x)
{
    union { float value; int word; } u;
    float y[2];
    int n, ix;
    u.value = x;
    ix = u.word;
    ix &= 0x7FFFFFFF;
    if (ix <= 0x3F490FD8)
        return func_003A3C80(x, 0.0f);
    if (ix > 0x7F7FFFFF)
        return x - x;
    n = func_003A3768(y);
    switch (n & 3) {
    case 0:
        return func_003A3C80(y[0], y[1]);
    case 1:
        return -func_003A4728(y[0], y[1], 1);
    case 2:
        return -func_003A3C80(y[0], y[1]);
    default:
        return func_003A4728(y[0], y[1], 1);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3A19F8
// diff: 4 words, addiu sp scheduled after the lui/ori pair (same as cosf)
float sinf(float x)
{
    float y[2];
    int n, ix;
    union { float value; int word; } u;
    u.value = x;
    ix = u.word;
    ix &= 0x7FFFFFFF;
    if (ix <= 0x3F490FD8)
        return func_003A4728(x, 0.0f, 0);
    if (ix > 0x7F7FFFFF)
        return x - x;
    n = func_003A3768(y);
    switch (n & 3) {
    case 0:
        return func_003A4728(y[0], y[1], 1);
    case 1:
        return func_003A3C80(y[0], y[1]);
    case 2:
        return -func_003A4728(y[0], y[1], 1);
    default:
        return -func_003A3C80(y[0], y[1]);
    }
}
#endif
