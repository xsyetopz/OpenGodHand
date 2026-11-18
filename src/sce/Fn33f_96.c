// COMPILER: ee-gcc2.96
struct S { char c; char _p[55]; };
extern struct S D_003DED70[];

// FUNCTION: GAME 0x336530
struct S *func_00336530(void)
{
    struct S *r = 0;
    int i;
    for (i = 0; i < 0x28; i++) {
        if (D_003DED70[i].c == 0) {
            r = &D_003DED70[i];
            break;
        }
    }
    return r;
}

struct O {
    char _a[0x54];
    char m54;
};
extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0738;

// FUNCTION: GAME 0x337B30
void func_00337B30(struct O *o, int v)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    if (o->m54 != v) {
        if (D_003E0738 != 0 || v != 1) {
            o->m54 = v;
        }
    }
}

// FUNCTION: GAME 0x3387C8
void func_003387C8(int *o, int i, int v)
{
    int t;
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    t = v < -15 ? -15 : v;
    t = t > 15 ? 15 : t;
    o[i + 0x10] = t;
}

// FUNCTION: GAME 0x33D4D8
void func_0033D4D8(short *d, short *s, int n)
{
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
}

struct CB { void (*f)(int); int a; };
extern struct CB D_00758860[];
extern void (*D_003E9D20)(void);
extern void (*D_003E9D50)(void);
extern int D_003E9944;
extern void func_0033BDD8(void);
extern void func_0033FB20(int);
extern void func_00333E88(int);
extern int strlen(const char *);
extern void func_0033C548(char *, int, short *, short *, short *);
extern short D_003E9D54, D_003E9D56, D_003E9D58;
extern void *memset(void *, int, unsigned);
extern int D_003D8410[];
extern int D_003D8448;
extern int D_003D90D0;
extern int D_003D90E8;
extern void (*D_003DA4C4)(int, int);
extern int D_003DA4C8, D_003DA4CC;
struct P { char _a[4]; int m4; int m8; char _b[0xDC]; int mE8; };
struct Q { char _a[0xC0]; int mC0; };

// FUNCTION: GAME 0x33BBD8
void func_0033BBD8(int i)
{
    if (D_00758860[i].f) {
        D_00758860[i].f(D_00758860[i].a);
    }
}

// FUNCTION: GAME 0x33C2C0
void func_0033C2C0(struct Q *q)
{
    if (q->mC0) {
        D_003E9D20();
    }
}

// FUNCTION: GAME 0x33BE80
void func_0033BE80(void)
{
    volatile int *p = &D_003E9944;
    if (*p == 0) {
        func_0033BDD8();
    }
    (*p)++;
}

// FUNCTION: GAME 0x33D040
void func_0033D040(char *s)
{
    func_0033C548(s, strlen(s), &D_003E9D54, &D_003E9D56, &D_003E9D58);
}

// FUNCTION: GAME 0x33D230
void func_0033D230(struct P *p)
{
    if (p->mE8) {
        D_003E9D50();
    }
    func_0033FB20(p->m8);
    p->m4 = 0;
}

// FUNCTION: GAME 0x330FB8
void func_00330FB8(void)
{
    int x = *(volatile int *)&D_003D8448;
    memset(D_003D8410, 0, 0x38);
}

// FUNCTION: GAME 0x3327D8
int *func_003327D8(void)
{
    int x = *(volatile int *)&D_003D90D0;
    func_00333E88(0);
    return &D_003D90E8;
}

// FUNCTION: GAME 0x335C30
void func_00335C30(void)
{
    if (D_003DA4C4) {
        D_003DA4C4(D_003DA4C8, D_003DA4CC);
    }
}

extern void func_003389F8(int, int, int);
extern void func_00338A10(void);
extern void func_00338E38(int, int, int);
extern void func_00339108(int, int, int);
extern void func_003391F8(int, int, int);
extern void func_00339AE8(int, int, int);
extern void func_00339CB8(int, int, int);
extern void func_0033A468(int, int, int);
extern void func_0033A8D0(int, int, int);
extern void func_0033AA48(int, int, int);

// FUNCTION: GAME 0x338DE8
void func_00338DE8(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_00338E38(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x3390B8
void func_003390B8(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_00339108(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x3391A8
void func_003391A8(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_003391F8(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x339A98
void func_00339A98(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_00339AE8(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x339C68
void func_00339C68(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_00339CB8(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x33A418
void func_0033A418(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_0033A468(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x33A880
void func_0033A880(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_0033A8D0(a, b, c);
    func_00338A10();
}

// FUNCTION: GAME 0x33A9F8
void func_0033A9F8(int a, int b, int c)
{
    func_003389F8(a, b, c);
    func_0033AA48(a, b, c);
    func_00338A10();
}
