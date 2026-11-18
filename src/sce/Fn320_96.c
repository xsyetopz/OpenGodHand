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
    func_00324880(a, b);
    r = func_00323660(a, b);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x323918
int func_00323918(int a, int b)
{
    int r;
    func_00324880(a, b);
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

extern int func_003252E0();
extern int D_003CF9E8, D_003D04B0, D_003C80C8;
extern int D_003C80FC[], D_003C814C[];
extern char D_003CF9F0[], D_003D04D0[];
extern void *memset();
extern int func_00324D88();
extern int func_00327B58();
extern int func_00327C30();
extern int func_0033F130();
extern int adxf_ReadNw32();
extern char D_004517C8[];

// FUNCTION: GAME 0x325EF8
int func_00325EF8()
{
    *(volatile int *)D_003C80FC = 1;
    return func_003252E0();
}

// FUNCTION: GAME 0x326520
void func_00326520()
{
    --*(volatile int *)&D_003CF9E8;
    if (*(volatile int *)&D_003CF9E8 == 0)
        memset(D_003CF9F0, 0, 0xAC0);
}

// FUNCTION: GAME 0x3279B8
int func_003279B8()
{
    if (++D_003D04B0 == 1)
        memset(D_003D04D0, 0, 0xF00);
    return 1;
}

// FUNCTION: GAME 0x327A00
void func_00327A00()
{
    if (--D_003D04B0 == 0)
        memset(D_003D04D0, 0, 0xF00);
}

// FUNCTION: GAME 0x324E70
int func_00324E70()
{
    return func_00324D88(*(volatile int *)D_003C814C, D_003C80C8);
}

// FUNCTION: GAME 0x327D48
int func_00327D48(int a, int b)
{
    int r;
    if (b < 0x100)
        r = func_00327B58(0, 0, 0, a);
    else
        r = func_00327C30(0, 0, 0, a);
    return r;
}

// FUNCTION: GAME 0x323ED8
int adxf_ReadNw(int a, int b, int c)
{
    if (c & 0x3F) {
        func_0033F130(D_004517C8);
        return -3;
    }
    return adxf_ReadNw32(a, b, c);
}

extern int func_0033C728();
extern int func_00329070();
extern int func_00329088();
extern int func_003282D0();
extern int func_00329028();
extern int func_00329040();
extern int func_00328368();
extern int func_00327FA8();
extern int func_0033F590();
extern int func_0033CF98();
extern int func_0033CFA0();

// FUNCTION: GAME 0x327D00
int func_00327D00(int a, int b)
{
    int r;
    func_00329070(a, b);
    r = func_00327D48(a, b);
    func_00329088();
    return r;
}

// FUNCTION: GAME 0x327FD8
int func_00327FD8(char *o)
{
    func_003282D0(o);
    func_00329028();
    if (o[0x49] == 1)
        o[0x46] = 1;
    o[0x45] = 0;
    return func_00329040();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3264C8 (4 words off, loop flag register v1 vs v0)
void func_003264C8()
{
    if (D_003CF9E8 == 0) {
        func_0033C728();
        memset(D_003CF9F0, 0, 0xAC0);
    }
    D_003CF9E8++;
}

// DRAFT: GAME 0x326160 (4 words off, o[3] load vs index shift order)
unsigned func_00326160(int *o, int i)
{
    int *obj = (int *)((int *)((int *)o[3])[i + 2])[2];
    return (unsigned)((int (*)())((int *)*obj)[9])(obj, 1) >> 1;
}

// DRAFT: GAME 0x327890 (9 words off, branch-likely vs delay-slot shape)
int func_00327890(unsigned char *o)
{
    if (func_0033CF98(*(int *)(o + 4)) > 0 && (unsigned)(o[1] - 2) < 2)
        return func_0033CFA0(*(int *)(o + 4));
    return 0;
}

// DRAFT: GAME 0x328048 (4 words off, loop flag in v1 instead of v0)
int func_00328048(char *o)
{
    func_00328368(o);
    func_00327FA8(o);
    while (o[0x49])
        func_0033F590();
}

// DRAFT: GAME 0x324400 (11 words off, call result copied to v1 in original)
void func_00324400(int *o)
{
    int n;
    int d;
    n = adxf_GetFsizeByte(o);
    d = n;
    o[3] = (d + 0x7FF) / 0x800;
}

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

// DRAFT: GAME 0x3224D0 (9 words off, global list head via addiu instead of lui/lw)
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
