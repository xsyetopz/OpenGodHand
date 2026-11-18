// COMPILER: ee-gcc2.96
// FLAGS: -O2
// SCE helpers in 0x320000-0x328098 compiled with 2.96 (frame with ra at 8, lui/lw globals).
extern int func_0033CF70();
extern int func_0033AF70();
extern int func_00327E18();
extern int func_0033F590();
extern int func_00323AA0();
extern int D_003EB838, D_003EB834, D_003C529C;

// FUNCTION: GAME 0x322F18
void func_00322F18()
{
    func_00323AA0(D_003EB838);
    D_003EB838 = 0;
    D_003EB834 = 0;
    D_003C529C = 0;
}

// FUNCTION: GAME 0x327830
int func_00327830(int *p)
{
    if (!p)
        return 0;
    return func_0033CF70(p[1]);
}

extern int func_00324880();
extern int func_00324898();
extern int func_00323660();
extern int func_00323960();
extern int adxf_Seek();
extern int adxf_ReadNw();
extern int adxf_GetFsizeByte();
extern int func_00322B88();
extern int func_00322BD8();
extern int func_00322C18();
extern char D_003C532F[];

// FUNCTION: GAME 0x323618
int func_00323618(int a, int b)
{
    int r;
    func_00324880(a);
    r = func_00323660(a, b);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x323918
int func_00323918(int a, int b)
{
    int r;
    func_00324880(a);
    r = func_00323960(a, b);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x324258
int func_00324258(int a, int b, int c)
{
    int r;
    func_00324880(a);
    r = adxf_Seek(a, b, c);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x323E80
int func_00323E80(int a, int b, int c)
{
    int r;
    func_00324880(a);
    r = adxf_ReadNw(a, b, c);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x322A38
int func_00322A38(int a, int b, int c, int d)
{
    return func_00322B88(a, b, c, d, (int)D_003C532F & ~0x3F, 0x800);
}

// FUNCTION: GAME 0x322AD0
int func_00322AD0(int a, int b, int c, int d)
{
    return func_00322BD8(a, b, c, d, (int)D_003C532F & ~0x3F, 0x800);
}

// FUNCTION: GAME 0x322B60
int func_00322B60(int a, int b, int c, int d)
{
    return func_00322C18(a, b, c, d, (int)D_003C532F & ~0x3F, 0x800);
}

// FUNCTION: GAME 0x324400
void func_00324400(int *o)
{
    o[3] = (adxf_GetFsizeByte(o) + 0x7FF) / 0x800;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x327F70 (2 words off, v0 vs v1 for the loop flag)
void func_00327F70(char *o)
{
    func_00327E18(o);
    do {
        func_0033F590();
    } while (o[0x45]);
}

// DRAFT: GAME 0x3261A8 (7 words off, address arithmetic scheduled differently)
unsigned func_003261A8(int *o, int i)
{
    int *t = (int *)o[3];
    int *q = (int *)t[i + 2];
    return (unsigned)func_0033AF70(q[1], 1) >> 1;
}

typedef struct SceNode { int a, b, c, d, e; struct SceNode *next; } SceNode;
extern SceNode *D_00755C18;

// DRAFT: GAME 0x3224D0 (11 words off, global list head via addiu instead of lui/lw)
void func_003224D0(int v, SceNode *n)
{
    SceNode *h = D_00755C18;
    n->d = v;
    n->next = h;
    D_00755C18 = n;
    n->c = v;
    n->b = 0;
    n->a = 0;
    n->e = 0;
}
#endif
