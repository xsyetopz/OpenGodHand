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
