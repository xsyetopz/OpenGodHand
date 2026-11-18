// COMPILER: ee-gcc2.96
struct Q {
    char _p[8];
    unsigned long m8;
    char _q[0x18];
    int m28;
};

// FUNCTION: GAME 0x334E80
int func_00334E80(char c)
{
    return c == '\\' ? '/' : c;
}

// FUNCTION: GAME 0x334B38
int func_00334B38(struct Q *q)
{
    unsigned long a = q->m8;
    unsigned long b = (long)q->m28 << 11;
    if (a < b) {
        b = a;
    }
    return (long)b >> 32;
}

// FUNCTION: GAME 0x334B58
int func_00334B58(struct Q *q)
{
    unsigned long a = q->m8;
    unsigned long b = (long)q->m28 << 11;
    if (a < b) {
        b = a;
    }
    return (int)(b & 0xFFFFFFFF);
}

extern int D_003DA390;

// FUNCTION: GAME 0x335218
void func_00335218(int a)
{
    if (a == 0) {
        D_003DA390 = 0x8001;
    } else if (a == 1) {
        D_003DA390 = a;
    } else {
        D_003DA390 = 0x8001;
    }
}

// FUNCTION: GAME 0x33C270
void func_0033C270(int *p, int v)
{
    p[0x31] = v;
    p[0x32] = v / 0x600;
}

extern char D_003D9150[];
extern char D_003D9FE0[];
extern int D_003E0710, D_003E0708;

// FUNCTION: GAME 0x333438
int func_00333438(char c)
{
    int r = c;
    if ((unsigned)(c - 0x61) < 0x1A) {
        r = (char)(c - 0x20);
    }
    return c == '\\' ? '/' : r;
}

// FUNCTION: GAME 0x337BC8
void func_00337BC8(char *p)
{
    if (D_003E0710 != 1 || D_003E0708 > 0) {
        p[0x56] = p[1];
    }
}

extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
extern void func_00340AE8(char *);
extern void func_00332670(int, void *, int, int, int);
extern void func_00335CD8(void);
extern int func_00335610(int, int);
extern void func_00335CE0(void);
extern int func_00325620(void);
extern void func_00335D40(void *);
extern char D_00454C78[];

// FUNCTION: GAME 0x338A48
void func_00338A48(char *a, char *b)
{
    char buf[0x40];
    strcpy(buf, a);
    strcat(buf, b);
    func_00340AE8(buf);
}

// FUNCTION: GAME 0x33B520
void func_0033B520(char *p)
{
    int v[4];
    v[0] = *(int *)(p + 0x10);
    func_00332670(1, v, 1, 0, 0);
    *p = 0;
}

// FUNCTION: GAME 0x3355C8
int func_003355C8(int a, int b)
{
    int r;
    func_00335CD8();
    r = func_00335610(a, b);
    func_00335CE0();
    return r;
}

// FUNCTION: GAME 0x33F850
int func_0033F850(int a)
{
    if (a == -1) {
        a = func_00325620() == 1 ? 2 : 1;
    }
    return a;
}

// FUNCTION: GAME 0x335878
void func_00335878(char *p)
{
    if (p == 0) {
        func_00335D40(D_00454C78);
        return;
    }
    if (p[1] == 0) {
        *(int *)(p + 0x1C) = 0;
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x24) = 0;
    }
}

// FUNCTION: GAME 0x339458
void func_00339458(char *a, char *b)
{
    char buf[0x40];
    strcpy(buf, a);
    strcat(buf, b);
    func_00340AE8(buf);
}

// FUNCTION: GAME 0x33A048
void func_0033A048(char *a, char *b)
{
    char buf[0x40];
    strcpy(buf, a);
    strcat(buf, b);
    func_00340AE8(buf);
}

extern void func_003389F8(void);
extern int func_00338BD8(int, int);
extern void func_00338A10(void);
extern int func_0033A618(int, int);

// FUNCTION: GAME 0x338B90
int func_00338B90(int a, int b)
{
    int r;
    func_003389F8();
    r = func_00338BD8(a, b);
    func_00338A10();
    return r;
}

// FUNCTION: GAME 0x33A5D0
int func_0033A5D0(int a, int b)
{
    int r;
    func_003389F8();
    r = func_0033A618(a, b);
    func_00338A10();
    return r;
}

extern void *memset(void *, int, unsigned);
extern int D_003E3AC8;
extern char D_003E3AD0[];
extern int D_003E3FB0;
extern char D_003E3FB8[];

// FUNCTION: GAME 0x338AC0
void func_00338AC0(void)
{
    if (D_003E3AC8 == 0) {
        memset(D_003E3AD0, 0, 0x480);
    }
    D_003E3AC8++;
}

// FUNCTION: GAME 0x338B40
void func_00338B40(void)
{
    if (--D_003E3AC8 == 0) {
        memset(D_003E3AD0, 0, 0x480);
    }
}

// FUNCTION: GAME 0x3394D0
void func_003394D0(void)
{
    if (D_003E3FB0 == 0) {
        memset(D_003E3FB8, 0, 0x4000);
    }
    D_003E3FB0++;
}

// FUNCTION: GAME 0x339550
void func_00339550(void)
{
    if (--D_003E3FB0 == 0) {
        memset(D_003E3FB8, 0, 0x4000);
    }
}

extern int D_00758400[3];
extern int D_00758500;

// FUNCTION: GAME 0x33AF70
int func_0033AF70(int a, int b)
{
    D_00758400[0] = a;
    D_00758400[1] = b;
    func_00332670(0x29, D_00758400, 2, (int)&D_00758500, 1);
    return D_00758500;
}

extern void func_0033FA30(int);

// FUNCTION: GAME 0x33C918
void func_0033C918(short *p)
{
    if (p != 0) {
        int t = *(int *)(p + 4);
        *(int *)(p + 4) = 0;
        func_0033FA30(t);
        memset(p, 0, 0x104);
        *p = 0;
    }
}

extern char D_003D1E70[];
extern void func_00330180(char *);

// FUNCTION: GAME 0x330268
void func_00330268(void)
{
    int p = (int)D_003D1E70;
    int e = p + 0x6590;
    do {
        func_00330180((char *)p);
        p += 0x1964;
    } while (p < e);
}

extern void func_0033E678(void *);
extern void func_0033E690(void);

// FUNCTION: GAME 0x33C038
void func_0033C038(void *p)
{
    if (p != 0) {
        func_0033E678(p);
        memset(p, 0, 0x30);
        func_0033E690();
    }
}

extern int D_003E7FE8;
extern char D_003E7FF0[];

// FUNCTION: GAME 0x33A140
void func_0033A140(void)
{
    if (--D_003E7FE8 == 0) {
        memset(D_003E7FF0, 0, 0xC00);
    }
}

// FUNCTION: GAME 0x33AED0
int func_0033AED0(int a, int b, int c)
{
    D_00758400[0] = a;
    D_00758400[1] = b;
    D_00758400[2] = c;
    func_00332670(0x22, D_00758400, 3, (int)&D_00758500, 1);
    return D_00758500;
}
