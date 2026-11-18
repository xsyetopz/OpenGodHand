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
