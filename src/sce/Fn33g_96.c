// COMPILER: ee-gcc2.96
extern void func_003389F8();
extern void func_00338A10(void);
extern int func_003395F8(int, int, int);
extern int func_0033A1E8(int, int, int);
extern void func_003398F8(int, int, int, int);
extern void func_0033A730(int, int, int, int);
extern void func_00338FD8(int, int, int, int);
extern int func_00333438(char);
extern int func_00334E80(char);
extern void func_0033BD18(void), func_0033BD30(void), func_0033BD48(void), func_0033BD60(void);
extern void func_0033BD78(void), func_0033BD90(void), func_0033BDA8(void), func_0033BDC0(void);

// FUNCTION: GAME 0x333470
int func_00333470(char a, char b)
{
    return (func_00333438(a) ^ func_00333438(b)) ? -1 : 0;
}

// FUNCTION: GAME 0x334E98
int func_00334E98(char a, char b)
{
    return (func_00334E80(a) ^ func_00334E80(b)) ? -1 : 0;
}

// FUNCTION: GAME 0x33F7B8
int func_0033F7B8(void)
{
    func_0033BD18();
    func_0033BD30();
    func_0033BD48();
    func_0033BD60();
    func_0033BD78();
    func_0033BD90();
    func_0033BDA8();
    func_0033BDC0();
    return 0;
}

// FUNCTION: GAME 0x338F78
void func_00338F78(int a, int b, int c, int d)
{
    func_003389F8(a, b, c, d);
    func_00338FD8(a, b, c, d);
    func_00338A10();
}

// FUNCTION: GAME 0x339898
void func_00339898(int a, int b, int c, int d)
{
    func_003389F8(a, b, c, d);
    func_003398F8(a, b, c, d);
    func_00338A10();
}

// FUNCTION: GAME 0x3395A0
int func_003395A0(int a, int b, int c)
{
    int r;
    func_003389F8(a, b, c);
    r = func_003395F8(a, b, c);
    func_00338A10();
    return r;
}

// FUNCTION: GAME 0x33A190
int func_0033A190(int a, int b, int c)
{
    int r;
    func_003389F8(a, b, c);
    r = func_0033A1E8(a, b, c);
    func_00338A10();
    return r;
}

// FUNCTION: GAME 0x33A6D0
void func_0033A6D0(int a, int b, int c, int d)
{
    func_003389F8(a, b, c, d);
    func_0033A730(a, b, c, d);
    func_00338A10();
}

struct CB { int f; int a; };
extern struct CB D_00758860[];
extern void func_0033B658(int, int, int);
extern void func_0033B670(void);
struct Q { int m0; char _4[0x10]; int m14; char _18[4]; int m1C; int m20; };
struct R {
    char _0[8]; int m8; char _c[0x3C]; int m48; char _4c[0x10]; int m5C;
    char _60[4]; int m64; int m68;
};
extern void func_0033FA70(int, int, int, int, int);
extern void func_0033FAA0(int, int, int, int, int);
extern void func_0033FAD0(int, int, int, int, int);
extern void func_0033FB00(int);

// FUNCTION: GAME 0x33BB80
void func_0033BB80(int i, int f, int a)
{
    func_0033B658(i, f, a);
    D_00758860[i].f = f;
    D_00758860[i].a = a;
    func_0033B670();
}

// FUNCTION: GAME 0x33D2D0
void func_0033D2D0(struct R *p, int x)
{
    struct Q *q = (struct Q *)((char *)p + 0x48);
    int s = p->m8;
    func_0033FA70(s, q->m0, x, q->m14 + q->m20 * 2, 0);
    func_0033FB00(s);
}

// FUNCTION: GAME 0x33D320
void func_0033D320(struct R *p, int x)
{
    struct Q *q = (struct Q *)((char *)p + 0x48);
    int s = p->m8;
    int a3 = q->m14 + q->m20 * 2;
    func_0033FAA0(s, q->m0, x * 2, a3, a3 + q->m1C * 2);
    func_0033FB00(s);
}

// FUNCTION: GAME 0x33D378
void func_0033D378(struct R *p, int x)
{
    struct Q *q = (struct Q *)((char *)p + 0x48);
    int s = p->m8;
    int a3 = q->m14 + q->m20 * 2;
    func_0033FAD0(s, q->m0, x, a3, a3 + q->m1C * 2);
    func_0033FB00(s);
}
