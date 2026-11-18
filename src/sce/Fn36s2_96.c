// COMPILER: ee-gcc2.96
extern int func_0036D688(int *);

typedef struct Slot { int state; int pad[0x18F]; } Slot;
extern struct { char pad[0x40]; int n; Slot *base; } D_0076A590;
extern int func_0036D8E8();

// FUNCTION: GAME 0x36D238
void func_0036D238(void)
{
    Slot *s;
    int i;
    int n = D_0076A590.n;
    s = D_0076A590.base;
    for (i = 0; i < n; i++, s++)
        s->state = 1;
}

// FUNCTION: GAME 0x36D410
Slot *func_0036D410(void)
{
    Slot *s = D_0076A590.base;
    int i;
    for (i = 0; i < D_0076A590.n; i++, s++)
        if (s->state == 1)
            return s;
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36D630
// diff: loop register allocation differs (9 words): original keeps n in a2 and uses bnez on the count
void func_0036D630(int idx, int v)
{
    Slot *s;
    int *q;
    int i;
    int n = D_0076A590.n;
    s = D_0076A590.base;
    q = (int *)s + idx + 6;
    for (i = 0; i < n; i++, q += 0x190) {
        if ((s++)->state == 2)
            *q = v;
    }
}
#endif

extern void func_0036D938();
extern int D_003F2048[];

// FUNCTION: GAME 0x36D7F8
void func_0036D7F8(int *p, int a, int b)
{
    int *q;
    if (func_0036D688(p)) {
        func_0036D8E8(0, 0xFF030203);
        return;
    }
    q = p + 1;
    q[0] = a;
    q[1] = b;
}

// FUNCTION: GAME 0x36DB80
void func_0036DB80(char *p, int *out)
{
    char *q = p + 0x160;
    if (func_0036D688(p)) {
        func_0036D8E8(0, 0xFF03020D);
        return;
    }
    *out = *(int *)(q + 0x2D4);
}

// FUNCTION: GAME 0x36D8E8
int func_0036D8E8(int *o, int r)
{
    if (o == 0)
        func_0036D938(D_003F2048);
    else
        func_0036D938(o + 1);
    return r;
}
