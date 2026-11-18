// COMPILER: ee-gcc2.96
// Error-hook helpers near 0x3B9D30 compile with ee-gcc 2.96 (dead sd/ld ra around a tail jump).

extern void func_003BA088();
extern void func_003BA058();
extern void func_0033F130(int);
extern void func_0033B658(void);
extern void func_0033B670(void);
extern void (*D_003FC7AC)(int, int);
extern int D_003FC7B0;
extern int D_003FC50C;
extern int D_003FC7A8;
extern char D_003FC7B8[];
extern char D_00460900[];
extern char D_00460928[];

extern void *memset(void *, int, unsigned);
extern void func_003B9DE0(const char *);

// FUNCTION: GAME 0x3B9D30
void func_003B9D30(void)
{
    func_003BA088();
}

// FUNCTION: GAME 0x3B9D48
void func_003B9D48(int a, int b)
{
    func_0033F130(b);
}

// FUNCTION: GAME 0x3B9D60
void func_003B9D60(void)
{
}

// FUNCTION: GAME 0x3B9D68
void func_003B9D68(void)
{
    D_003FC50C++;
}

// FUNCTION: GAME 0x3B9D80
void func_003B9D80(void)
{
    D_003FC50C--;
}

// FUNCTION: GAME 0x3B9D98
void func_003B9D98(void (*a)(int, int), int b)
{
    D_003FC7AC = a;
    D_003FC7B0 = b;
}

// FUNCTION: GAME 0x3B9DB0
void func_003B9DB0(void)
{
    func_0033B658();
}

// FUNCTION: GAME 0x3B9DC8
void func_003B9DC8(void)
{
    func_0033B670();
}

// FUNCTION: GAME 0x3B9DE0
void func_003B9DE0(const char *a)
{
    if (D_003FC7AC)
        D_003FC7AC(D_003FC7B0, (int)a);
}

// 0x3B9E10 near-miss: only register allocation differs (orig counter in a0 and base in v1; ours v0)
// DRAFT: GAME 0x3B9E10
void func_003B9E10(void)
{
    int *c = &D_003FC7A8;
    if (*c == 0)
        memset(D_003FC7B8, 0, 0x3C);
    *c = *c + 1;
}

// FUNCTION: GAME 0x3B9FB8
void func_003B9FB8(int *p)
{
    p[1] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}

// FUNCTION: GAME 0x3B9FD0
void func_003B9FD0(void *a)
{
    func_003BA058(a);
    memset(a, 0, 0x3C);
}

// FUNCTION: GAME 0x3BA058
void func_003BA058(int *p)
{
    if (!p) {
        func_003B9DE0(D_00460900);
        return;
    }
    p[1] = 0;
}

// FUNCTION: GAME 0x3BA088
void func_003BA088(int *p)
{
    if (!p) {
        func_003B9DE0(D_00460928);
        return;
    }
    p[9] = 1;
}
