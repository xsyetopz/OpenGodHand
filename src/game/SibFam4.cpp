// Sibling families of 0x133900, 0x101e98, 0x133810, 0x138210, 0x1267f8 and 0x300148.

struct VEnt { short delta; short pad; void (*fn)(void *); };

extern "C" {
void func_0032DB70(int *);
void func_0032DDF8(int *);
void func_00380EB0(int *);
void func_00381D60(int *);
void func_0031EEC8(void *, const char *);
void func_0031EEA8(void *, const char *, void *);
extern char D_0041D5D0[];
extern char D_0041D830[];
extern char D_0041D8D8[];
extern char D_0042C300[];
extern char D_0042C308[];
extern char D_0042C348[];
extern char D_0042C4F8[];
extern char D_0042C508[];
extern char D_0042C518[];
extern char D_0044BE98[];
extern char D_0044BEB8[];
extern char D_0044D210[];
extern char D_0044D220[];
extern char D_0044E9F8[];
extern char D_0044EA08[];
extern char D_0044FDB8[];
extern char D_0044FDC8[];
extern char D_00450098[];
extern int D_00460D40[];
extern int D_00460D48[];
extern int D_00460D58[];
extern int D_00460D60[];
extern int D_00460D80[];
extern int D_00460D98[];
extern int D_00786188[];
extern int D_00786198[];
extern int D_007861A8[];
extern int D_007861B8[];
extern int D_00786388[];
extern int D_007863A8[];
extern int D_007863C8[];
extern int D_007863F8[];
extern int D_00786458[];
extern int D_007865A8[];
extern int D_007865B8[];
extern int __ti15cCollisionSolid[];
extern int __ti21cCollisionScrollSolid[];
extern int __ti7cCamera[];
int *func_002B6528();
int *func_00300148();
void func_002BF820(int, int);
void func_002C0A28(int, int);
void func_002C5338(int, int);
void func_002C9C38(int, int);
void func_002CC3B8(int, int);
void func_002CD9A0(int, int);
void func_00307140(int, int);

// FUNCTION: GAME 0x1337A0
int *__tf21cCollisionScrollSolid()
{
    if (!__ti21cCollisionScrollSolid[0])
        func_0031EEC8(__ti21cCollisionScrollSolid, D_0041D5D0);
    return __ti21cCollisionScrollSolid;
}

// FUNCTION: GAME 0x134270
int *__tf15cCollisionSolid()
{
    if (!__ti15cCollisionSolid[0])
        func_0031EEC8(__ti15cCollisionSolid, D_0041D830);
    return __ti15cCollisionSolid;
}

// FUNCTION: GAME 0x138B78
int *__tf7cCamera()
{
    if (!__ti7cCamera[0])
        func_0031EEC8(__ti7cCamera, D_0041D8D8);
    return __ti7cCamera;
}

// FUNCTION: GAME 0x1F7C88
int *func_001F7C88()
{
    if (!D_00460D40[0])
        func_0031EEC8(D_00460D40, D_0042C348);
    return D_00460D40;
}

// FUNCTION: GAME 0x1FE4C0
int *func_001FE4C0()
{
    if (!D_00460D48[0])
        func_0031EEC8(D_00460D48, D_0042C4F8);
    return D_00460D48;
}

// FUNCTION: GAME 0x3071A0
int *func_003071A0()
{
    if (!D_00460D98[0])
        func_0031EEC8(D_00460D98, D_00450098);
    return D_00460D98;
}

// FUNCTION: GAME 0x2BF858
void func_002BF858()
{
    func_002BF820(1, 0xFFFF);
}

// FUNCTION: GAME 0x2C0A78
void func_002C0A78()
{
    func_002C0A28(1, 0xFFFF);
}

// FUNCTION: GAME 0x2C5388
void func_002C5388()
{
    func_002C5338(1, 0xFFFF);
}

// FUNCTION: GAME 0x2C9C68
void func_002C9C68()
{
    func_002C9C38(1, 0xFFFF);
}

// FUNCTION: GAME 0x2CC4E0
void func_002CC4E0()
{
    func_002CC3B8(1, 0xFFFF);
}

// FUNCTION: GAME 0x2CD9E8
void func_002CD9E8()
{
    func_002CD9A0(1, 0xFFFF);
}

// FUNCTION: GAME 0x3071E8
void func_003071E8()
{
    func_00307140(1, 0xFFFF);
}

// FUNCTION: GAME 0x1FE530
int *func_001FE530()
{
    if (!D_007861A8[0]) {
        if (!D_00460D48[0])
            func_0031EEC8(D_00460D48, D_0042C4F8);
        func_0031EEA8(D_007861A8, D_0042C508, D_00460D48);
    }
    return D_007861A8;
}

// FUNCTION: GAME 0x1FE5E0
int *func_001FE5E0()
{
    if (!D_007861B8[0]) {
        if (!D_00460D48[0])
            func_0031EEC8(D_00460D48, D_0042C4F8);
        func_0031EEA8(D_007861B8, D_0042C518, D_00460D48);
    }
    return D_007861B8;
}

// FUNCTION: GAME 0x2BAD80
int *func_002BAD80()
{
    if (!D_00786388[0]) {
        if (!D_00460D60[0])
            func_0031EEC8(D_00460D60, D_0044BE98);
        func_0031EEA8(D_00786388, D_0044BEB8, D_00460D60);
    }
    return D_00786388;
}

// FUNCTION: GAME 0x2D5CD8
int *func_002D5CD8()
{
    if (!D_007863A8[0]) {
        if (!D_00460D80[0])
            func_0031EEC8(D_00460D80, D_0044D210);
        func_0031EEA8(D_007863A8, D_0044D220, D_00460D80);
    }
    return D_007863A8;
}

// FUNCTION: GAME 0x1F7BD8
int *func_001F7BD8()
{
    if (!D_00786198[0]) {
        if (!D_00786188[0]) {
            func_001F7C88();
            func_0031EEA8(D_00786188, D_0042C300, D_00460D40);
        }
        func_0031EEA8(D_00786198, D_0042C308, D_00786188);
    }
    return D_00786198;
}

// FUNCTION: GAME 0x2EFAB8
int *func_002EFAB8()
{
    if (!D_00786458[0]) {
        if (!D_007863F8[0]) {
            func_00300148();
            func_0031EEA8(D_007863F8, D_0044E9F8, D_007863C8);
        }
        func_0031EEA8(D_00786458, D_0044EA08, D_007863F8);
    }
    return D_00786458;
}

// FUNCTION: GAME 0x304ED0
int *func_00304ED0()
{
    if (!D_007865B8[0]) {
        if (!D_007865A8[0]) {
            func_002B6528();
            func_0031EEA8(D_007865A8, D_0044FDB8, D_00460D58);
        }
        func_0031EEA8(D_007865B8, D_0044FDC8, D_007865A8);
    }
    return D_007865B8;
}

// FUNCTION: GAME 0x1434A8
void initData__10cCockPlBar(char *w)
{
    VEnt *v = &(*(VEnt **)(w + 0x80))[3];
    v->fn(w + v->delta);
}

// DRAFT: GAME 0x195980
// diff: 5 words, ptr/delta/fn registers allocated v0/v1/a1 instead of v1/a1/v0
#ifdef NONMATCHING
void func_00195980(char *w)
{
    VEnt *v = &(*(VEnt **)(w + 0x214))[13];
    int d = v->delta;
    void (*f)(void *) = v->fn;
    f(w + d);
}
#endif

// FUNCTION: GAME 0x374548
void func_00374548(int **p)
{
    if (*p)
        func_0032DB70(*p);
}

// FUNCTION: GAME 0x374958
void func_00374958(int **p)
{
    if (*p)
        func_0032DDF8(*p);
}

// FUNCTION: GAME 0x380E88
void func_00380E88(int *a, int *b)
{
    if (b[12])
        func_00380EB0(a);
}

// FUNCTION: GAME 0x381D38
void func_00381D38(int *a, int *b)
{
    if (b[8])
        func_00381D60(a);
}
}
