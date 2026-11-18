// COMPILER: ee-gcc2.9-991111
// SCE runtime leaf helpers in 0x3B0268-0x3BA900.

extern void func_003B6990(unsigned int, int);
extern int D_0077E6C0[];

// FUNCTION: GAME 0x3B6A00
void func_003B6A00(int a)
{
    func_003B6990(0xB0001000, a);
}

// FUNCTION: GAME 0x3B6A10
void func_003B6A10(int a)
{
    func_003B6990(0xB0001010, a);
}

// FUNCTION: GAME 0x3B6A20
void func_003B6A20(int a)
{
    func_003B6990(0xB0001020, a);
}

// FUNCTION: GAME 0x3B0450
int func_003B0450(void *a, char *b)
{
    *(long *)(b + 0x48) = 0;
    *(int *)(b + 4) = 0x2000;
    return 0;
}

// FUNCTION: GAME 0x3B2058
int func_003B2058(int i)
{
    return D_0077E6C0[i];
}

// FUNCTION: GAME 0x3B2028
void func_003B2028(int *a, int *b)
{
    ((int *)b[7])[a[4]] = a[5];
}

// FUNCTION: GAME 0x3B2B70
void func_003B2B70(unsigned int *a)
{
    a[6] = 0;
    a[4] &= 0xFFFFFFFE;
}

// FUNCTION: GAME 0x3B2048
void func_003B2048(int *a, int *b)
{
    b[2] = a[4];
}

extern int D_003FAEE4;
extern void SignalSema(int);
extern void func_003B7C18(void);

// FUNCTION: GAME 0x3B3EF8
void func_003B3EF8(void)
{
    SignalSema(D_003FAEE4);
}

// FUNCTION: GAME 0x3B0388
int func_003B0388(void)
{
    return -1;
}

// FUNCTION: GAME 0x3B0390
int func_003B0390(void)
{
    return -1;
}

// FUNCTION: GAME 0x3B0448
int func_003B0448(void)
{
    return 1;
}

// FUNCTION: GAME 0x3B6818
void func_003B6818(void)
{
    func_003B7C18();
}

struct Ent12 {
    int w0, w1, w2;
};
extern struct Ent12 *D_0077E524;
extern struct Ent12 *D_0077E52C;

// FUNCTION: GAME 0x3B2500
void func_003B2500(int i)
{
    if (i < 0)
        D_0077E524[i & 0x7FFFFFFF].w0 = 0;
    else
        D_0077E52C[i].w0 = 0;
}
