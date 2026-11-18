// COMPILER: ee-gcc2.9-991111
// SCE library units built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

int strcmp(const char *, const char *);
extern int D_00460DA8;
extern char D_004512B0[];
void func_0031EEC8(void *, char *);
void func_0038EB28(int, int);
int **func_003892C0(int **);

// FUNCTION: GAME 0x3202A8
int func_003202A8(const char *a, const char *b, int c)
{
    if (strcmp(a, b))
        c = 0;
    return c;
}

// FUNCTION: GAME 0x3218F8
int *func_003218F8(void)
{
    if (!D_00460DA8)
        func_0031EEC8(&D_00460DA8, D_004512B0);
    return &D_00460DA8;
}

// FUNCTION: GAME 0x389400
int **func_00389400(int **o)
{
    func_0038EB28(0, **o);
    return o;
}

// FUNCTION: GAME 0x389438
int **endl__FR7ostream(int **o)
{
    func_0038EB28(10, **o);
    return func_003892C0(o);
}

extern int D_00451270[], D_00451288[];
float func_0031D108();
void func_0031DFA8();
void func_0031E758();
void *func_0031E048();
void func_0031DE78();
struct A { long long v; };
struct B { int w[8]; };

// FUNCTION: GAME 0x31E870
void func_0031E870(struct A a, struct A b)
{
    struct B x, y;
    func_0031DFA8(&a, &x);
    func_0031DFA8(&b, &y);
    func_0031E758(&x, &y);
}

// FUNCTION: GAME 0x31E288
void func_0031E288(struct A a, struct A b)
{
    struct B x, y, z;
    func_0031DFA8(&a, &x);
    func_0031DFA8(&b, &y);
    func_0031DE78(func_0031E048(&x, &y, &z));
}

// FUNCTION: GAME 0x321848
int *func_00321848(int **p)
{
    *p = D_00451270;
    return (int *)p;
}

// FUNCTION: GAME 0x3218E0
int *func_003218E0(int **p)
{
    *p = D_00451288;
    return (int *)p;
}

// FUNCTION: GAME 0x31E2E0
void func_0031E2E0(struct A a, struct A b)
{
    struct B x, y, z;
    func_0031DFA8(&a, &x);
    func_0031DFA8(&b, &y);
    y.w[1] ^= 1;
    func_0031DE78(func_0031E048(&x, &y, &z));
}
