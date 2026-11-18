// COMPILER: ee-gcc2.9-991111
extern int D_003FBEB8;
extern int D_003FBEBC;
extern char D_00784048[];
extern void *memset();
extern int func_003B07A8();
extern int func_003AF9D0();
extern int D_0077E514;
extern int D_003FAE50;
extern int D_003FAEDC;
extern char D_007816E8[];

// FUNCTION: GAME 0x3B7988
void func_003B7988(void)
{
    D_003FBEB8 = 0;
    D_003FBEBC = 0;
    memset(D_00784048, 0, 0x200);
}

struct Ring {
    int pad0[5];
    char *base;
    int cnt;
    int pad1;
    int pad2;
    int idx;
};

// DRAFT: GAME 0x3B2B90
// diff: reg alloc (divisor v0 vs v1, hi in v1 vs v0) and sw delay-slot placement in the tail
#ifdef NONMATCHING
char *func_003B2B90(struct Ring *r)
{
    int i = r->idx % r->cnt;
    char *p;
    r->idx = i + 1;
    p = r->base + (i << 6);
    return p;
}
#endif

// FUNCTION: GAME 0x3B67E8
int func_003B67E8(char *d, char *s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}

// FUNCTION: GAME 0x3B2450
void func_003B2450(void)
{
    func_003B07A8(5);
    func_003AF9D0(5, D_0077E514);
    D_003FAE50 = 0;
}

// FUNCTION: GAME 0x3B41E8
int func_003B41E8(void)
{
    D_003FAEDC = 0;
    memset(D_007816E8, 0, 4);
    return 0;
}

extern int D_003FAEF8;
extern char D_00781BA8[];

// FUNCTION: GAME 0x3B5C10
int func_003B5C10(void)
{
    D_003FAEF8 = -1;
    memset(D_00781BA8, 0, 4);
    return 0;
}

// FUNCTION: GAME 0x3B6688
int func_003B6688(int *d, int *s, unsigned n)
{
    unsigned i;
    n >>= 2;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}

// FUNCTION: GAME 0x3B6870
int func_003B6870(int *d, int *s, unsigned n)
{
    unsigned i;
    n >>= 2;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}

// FUNCTION: GAME 0x3B7AE8
int func_003B7AE8(int *d, int *s, unsigned n)
{
    unsigned i;
    n >>= 2;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}

struct Node {
    struct Node *next;
    struct Node *prev;
};
extern struct Node *D_003FBEA8;

// FUNCTION: GAME 0x3B6E40
struct Node *func_003B6E40(struct Node *n)
{
    struct Node *nx = n->next;
    if (n->prev)
        n->prev->next = nx;
    else
        D_003FBEA8 = nx;
    if (nx)
        nx->prev = n->prev;
    n->prev = 0;
    return nx;
}

// DRAFT: GAME 0x3B0D48
// diff: final sb not scheduled into jr delay slot (+1 nop, 60 vs 56 bytes)
#ifdef NONMATCHING
int func_003B0D48(int c)
{
    while (*(volatile int *)0x1000F130 & 0x8000)
        ;
    *(volatile signed char *)0x1000F180 = c;
    return c;
}
#endif
